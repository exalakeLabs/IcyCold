/************************************
  REVISION LOG ENTRY
  Revision By: Mihai Filimon
  Revised on 9/16/98 2:20:27 PM
  Comments: MultiColumnComboBox.cpp : implementation file
 ************************************/

#include "stdafx.h"
#include "MultiColumnComboBox.h"
#include "XPropertiesWnd.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiColumnComboBox

CBrush CMultiColumnComboBox::m_brBkGnd(defaultRGBBkGnd);
CFont CMultiColumnComboBox::m_font;

static const LOGFONT logFontPages =
{
/*LONG lfHeight*/8,
/*LONG lfWidth*/0,
/*LONG lfEscapement*/0,
/*LONG lfOrientation*/0,
/*LONG lfWeight*/FW_NORMAL,
/*BYTE lfItalic*/FALSE,
/*BYTE lfUnderline*/FALSE,
/*BYTE lfStrikeOut*/FALSE,
/*BYTE lfCharSet*/ANSI_CHARSET,
/*BYTE lfOutPrecision*/0,
/*BYTE lfClipPrecision*/0,
/*BYTE lfQuality*/DEFAULT_QUALITY,
/*BYTE lfPitchAndFamily*/DEFAULT_PITCH,
/*CHAR lfFaceName[LF_FACESIZE]*/_T("MS Sans Serif")
};

// Function name	: CMultiColumnComboBox::CMultiColumnComboBox
// Description	    : default constuctor
// Return type		: 
CMultiColumnComboBox::CMultiColumnComboBox(int nColumnKey)
{
	RegClassMultiColumnComboBox();
	m_pListCtrl = NULL;
	m_pEdit = NULL;
	m_bCaptured = FALSE;
	m_nColumnKey = nColumnKey;
	SetRateWidth(0.0);
	SetMultipleHeight();
	m_bFirstShow = TRUE; 
	m_nCurrentItem = -1;
}

// Function name	: CMultiColumnComboBox::~CMultiColumnComboBox
// Description	    : virtual destructor
// Return type		: 
CMultiColumnComboBox::~CMultiColumnComboBox()
{
}

BEGIN_MESSAGE_MAP(CMultiColumnComboBox, CWnd)
	//{{AFX_MSG_MAP(CMultiColumnComboBox)
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiColumnComboBox message handlers
UINT CMultiColumnComboBox::m_nSelChange = NULL;

// Function name	: CMultiColumnComboBox::RegClassMultiColumnComboBox
// Description	    : Register this window class
// Return type		: BOOL 
BOOL CMultiColumnComboBox::RegClassMultiColumnComboBox()
{
	WNDCLASS wndClass;
		wndClass.style = CS_DBLCLKS;
		wndClass.lpfnWndProc = ::DefWindowProc;
		wndClass.cbClsExtra = NULL;
		wndClass.cbWndExtra = NULL;
		wndClass.hInstance = AfxGetInstanceHandle();
		wndClass.hIcon = NULL;
		wndClass.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		wndClass.hbrBackground = (HBRUSH)m_brBkGnd;
		wndClass.lpszMenuName = NULL;
		wndClass.lpszClassName = wndClassName;
	BOOL bResult = AfxRegisterClass(&wndClass);
	if (bResult)
	{
		if (!m_nSelChange)
			m_nSelChange = RegisterWindowMessage(defaultSelChange);
		if (!m_font.GetSafeHandle())
		{
			//At the first call set the new font
			m_font.CreateFontIndirect(&logFontPages);
		}
	}
	return bResult;
}

CMultiColumnComboBox* CMultiColumnComboBox::m_pActiveMCBox = NULL;
CMultiColumnComboBox::CWindowProcs CMultiColumnComboBox::m_wndProcs;
// Function name	: CMultiColumnComboBox::ListCtrlWindowProc
// Description	    : ListControl window procedure
// Return type		: LRESULT CALLBACK 
// Argument         : HWND hWnd
// Argument         : UINT nMsg
// Argument         : WPARAM wParam
// Argument         : LPARAM lParam
LRESULT CALLBACK CMultiColumnComboBox::ListCtrlWindowProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	CMultiColumnComboBox* pOwner  = NULL;
	if (pOwner = CMultiColumnComboBox::m_pActiveMCBox)
		pOwner->ForwardMessage(nMsg, wParam, lParam);
	LRESULT lResult = CallWindowProc( CMultiColumnComboBox::m_wndProcs.GetOldListCtrlProcedure(hWnd), hWnd, nMsg, wParam, lParam );
	return lResult;
}

// Function name	: CMultiColumnComboBox::ParentWindowProc
// Description	    : Parent window procedure.
// Return type		: LRESULT CALLBACK 
// Argument         : HWND hWnd
// Argument         : UINT nMsg
// Argument         : WPARAM wParam
// Argument         : LPARAM lParam
LRESULT CALLBACK CMultiColumnComboBox::ParentWindowProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	if (CMultiColumnComboBox* pOwner = CMultiColumnComboBox::m_pActiveMCBox)
	{
		switch (nMsg)
		{
			case WM_COMMAND:
			case WM_CAPTURECHANGED:
			case WM_SYSCOMMAND:
			case WM_LBUTTONDOWN:
			case WM_NCLBUTTONDOWN:
			{
				BOOL bDropped = pOwner->IsDropedDown();
				pOwner->DropDown(FALSE);
				if (nMsg == WM_COMMAND)
					if (LOWORD(wParam) == IDOK)
					{
						pOwner->SelectCurrentItem();
						return FALSE;
					}
					else
						if (LOWORD(wParam) == IDCANCEL)
							if (bDropped)
								return FALSE;
				break;
			}
		}
	};
	WNDPROC wndProc = CMultiColumnComboBox::m_wndProcs.GetOldParentProcedure(hWnd);
	ASSERT (wndProc);
	return CallWindowProc( wndProc, hWnd, nMsg, wParam, lParam );
}

// Function name	: CMultiColumnComboBox::EditWindowProc
// Description	    : Edit window procedure
// Return type		: LRESULT CALLBACK 
// Argument         : HWND hWnd
// Argument         : UINT nMsg
// Argument         : WPARAM wParam
// Argument         : LPARAM lParam
LRESULT CALLBACK CMultiColumnComboBox::EditWindowProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	CMultiColumnComboBox* pOwner = CMultiColumnComboBox::m_pActiveMCBox;
	switch (nMsg)
	{
		case WM_SETFOCUS:
			{
				CMultiColumnComboBox::m_pActiveMCBox = (CMultiColumnComboBox*)CWnd::FromHandle(::GetParent(hWnd));
				break;
			}
		case WM_KILLFOCUS:
			{
				if (pOwner)
				{
					pOwner->DropDown(FALSE);
					CMultiColumnComboBox::m_pActiveMCBox = NULL;
				}
				break;
			}
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
			{
				if (pOwner)
					switch ((int) wParam)
					{
						case VK_RETURN :
						case VK_ESCAPE :
						case VK_UP:
						case VK_DOWN:
						case VK_PRIOR:
						case VK_NEXT:
							{
								//dispatch enter,... keys to multi column...
								pOwner->SendMessage(nMsg, wParam, lParam);
								break;
							}
						case defaultDropDownKey:
							{
								pOwner->DropDown(!pOwner->IsDropedDown());
								pOwner->CaptureListCtrl();
								break;
							}
					}
				break;
			}
	}
	return CallWindowProc( CMultiColumnComboBox::m_wndProcs.GetOldEditProcedure(hWnd), hWnd, nMsg, wParam, lParam );
}

// Function name	: CMultiColumnComboBox::OnInit
// Description	    : Init the control
// Return type		: BOOL 
BOOL CMultiColumnComboBox::OnInit()
{
	//Do not call twice
	ASSERT (m_pEdit == NULL && m_pListCtrl == NULL);
	ASSERT (m_font.GetSafeHandle());
	SetFont(&m_font);
	ModifyStyle(WS_OVERLAPPED , WS_TABSTOP);
	m_pEdit		= new CEdit();
	m_pListCtrl = new CListCtrl();
	if (m_pEdit->Create(WS_CHILD | WS_VISIBLE | defaultEditStyle, CRect(0,0,0,0), this, IDEDIT ))
	{
		ModifyStyleEx(0, WS_EX_STATICEDGE);
		m_pEdit->SetFont(&m_font);
		if (m_pListCtrl->Create(WS_BORDER | WS_CHILD | defaultListCtrlStyle , CRect(0,0,0,0), GetDesktopWindow(), IDLISTCTRL))
		{
			//Set the reference to this object in user data dword
			::SetWindowLong(m_pListCtrl->m_hWnd, GWL_USERDATA, (long)this);
			::SetWindowLong(m_pListCtrl->m_hWnd, GWL_STYLE, GetWindowLong(m_pListCtrl->m_hWnd, GWL_STYLE) | WS_CLIPSIBLINGS | WS_OVERLAPPED);
			m_pListCtrl->ModifyStyleEx(0, WS_EX_TOOLWINDOW);
			m_pListCtrl->SetWindowPos(&CWnd::wndTopMost,0,0,0,0, SWP_NOSIZE | SWP_NOMOVE);
			ListView_SetExtendedListViewStyle(m_pListCtrl->m_hWnd, LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
			Resize();
			m_wndProcs.AddEdit(GetEdit(), EditWindowProc);
			m_wndProcs.AddListCtrl(GetListCtrl(), ListCtrlWindowProc);
			m_wndProcs.AddParent(GetParent(), ParentWindowProc);
			return TRUE;
		}
	}
	return FALSE;
}

// Function name	: CMultiColumnComboBox::PreSubclassWindow
// Description	    : Call to subclass window
// Return type		: void 
void CMultiColumnComboBox::PreSubclassWindow() 
{
	CWnd::PreSubclassWindow();

	// If this is dynamical created then do not call OnInit
	if (AfxGetThreadState()->m_pWndInit == 0)
		OnInit();
}

// Function name	: CMultiColumnComboBox::OnDestroy
// Description	    : Remove all dependent datas.
// Return type		: void 
void CMultiColumnComboBox::OnDestroy() 
{
	CWnd::OnDestroy();

	m_wndProcs.RemoveEdit(GetEdit());
	m_wndProcs.RemoveListCtrl(GetListCtrl());
	m_wndProcs.RemoveParent(GetParent());
	
	if (CListCtrl* pList = GetListCtrl())
	{
		pList->DeleteAllItems();
		delete pList;
	}

	if (CEdit* pEdit = GetEdit())
		delete pEdit;

	m_pListCtrl = NULL;
	m_pEdit = NULL;

}

// Function name	: CMultiColumnComboBox::GetListCtrl
// Description	    : return the list control for 
// Return type		: CListCtrl* 
CListCtrl* CMultiColumnComboBox::GetListCtrl()
{
	return m_pListCtrl;
}

// Function name	: CMultiColumnComboBox::GetEdit
// Description	    : retirn  pointer to edit control inside of thsi control
// Return type		: CEdit* 
CEdit* CMultiColumnComboBox::GetEdit()
{
	return m_pEdit;
}

// Function name	: CMultiColumnComboBox::DrawButton
// Description	    : Draw down button
// Return type		: void 
// Argument         : CDC * pDC
// Argument         : CRect r
// Argument         : BOOL bDown
void CMultiColumnComboBox::DrawButton(CDC * pDC, CRect r, BOOL bDown)
{
	r.InflateRect(-1,-1);
	pDC->FillRect(r,&CBrush(RGB(192,192,192)));
	pDC->DrawEdge(r, EDGE_RAISED, BF_RECT);
	pDC->DrawIcon(r.TopLeft() + CPoint(1,1),AfxGetApp()->LoadIcon(IDI_ICON_DOWN));
}

// Function name	: CMultiColumnComboBox::OnPaint
// Description	    : On Draw function
// Return type		: void 
void CMultiColumnComboBox::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect r; GetClientRect(r);
	r.left = r.right - (GetSystemMetrics(SM_CXHSCROLL) + 2);
	m_rectBtn = r;
	DrawButton(&dc, m_rectBtn);
}

// Function name	: CMultiColumnComboBox::Resize
// Description	    : Call to remove the edit and list controls
// Return type		: void 
void CMultiColumnComboBox::Resize()
{
	ASSERT (GetListCtrl());
	CRect r;
	GetWindowRect(r);
	SetWindowPos(0, 0, 0, r.Width(), defaultSizeDY, SWP_NOMOVE | SWP_NOZORDER | SWP_NOMOVE);
	// Set the height and width of edit control
	GetClientRect(r);
	r.InflateRect(-1,-2); r.bottom++;
	r.right = r.right - (GetSystemMetrics(SM_CXHSCROLL) + 2);
	GetEdit()->MoveWindow(r.left, r.top, r.Width(), r.Height());
	// Set the height and width of list control
	GetWindowRect(r);
	int dy = r.Height();
	int dx = r.Width();
	r.top = r.bottom;
	r.left++;r.right--;
	r.bottom += m_nMultipleHeight * dy;
	r.right += int(m_dWidthList * r.Width());
	r.OffsetRect(-(r.Width() - dx),0);
	GetListCtrl()->MoveWindow(r.left, r.top, r.Width(), r.Height());
}

// Function name	: CMultiColumnComboBox::DropDown
// Description	    : DropDown
// Return type		: void 
// Argument         : BOOL bDown
void CMultiColumnComboBox::DropDown(BOOL bDown)
{
	if (IsWindowVisible())
	{
		if (IsDropedDown() != bDown)
		{
			Resize();
			GetListCtrl()->ShowWindow(bDown ? SW_SHOW : SW_HIDE);
			GetListCtrl()->SetCapture();
			if (bDown)
			{
				GetEdit()->SetFocus();
				SetCurrentItem(m_nSelectedItem);
				GetListCtrl()->EnsureVisible(m_nSelectedItem, FALSE);
			}
			else
				ReleaseCapture();
		}
	}
}

// Function name	: CMultiColumnComboBox::IsDropedDown
// Description	    : If the list control is dropped downd, return TRUE
// Return type		: BOOL 
BOOL CMultiColumnComboBox::IsDropedDown()
{
	return GetListCtrl()->IsWindowVisible();
}

// Function name	: CMultiColumnComboBox::OnWindowPosChanged
// Description	    : 
// Return type		: void 
// Argument         : WINDOWPOS FAR* lpwndpos
void CMultiColumnComboBox::OnWindowPosChanged(WINDOWPOS FAR* lpwndpos) 
{
	CWnd::OnWindowPosChanged(lpwndpos);
	Resize();
}

// Function name	: CMultiColumnComboBox::OnLButtonDown
// Description	    : 
// Return type		: void 
// Argument         : UINT nFlags
// Argument         : CPoint point
void CMultiColumnComboBox::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if (m_rectBtn.PtInRect(point))
	{
		SetButton();
		DropDown(!IsDropedDown());
	}
	
	CWnd::OnLButtonDown(nFlags, point);
}

// Function name	: CMultiColumnComboBox::OnLButtonUp
// Description	    : 
// Return type		: void 
// Argument         : UINT nFlags
// Argument         : CPoint point
void CMultiColumnComboBox::OnLButtonUp(UINT nFlags, CPoint point) 
{
	ReleaseButton();
	CaptureListCtrl();
	CWnd::OnLButtonUp(nFlags, point);
}

// Function name	: CMultiColumnComboBox::OnMouseMove
// Description	    : 
// Return type		: void 
// Argument         : UINT nFlags
// Argument         : CPoint point
void CMultiColumnComboBox::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (m_bCaptured)
	{
		CPoint p; ::GetCursorPos(&p);
		ScreenToClient(&p);
		if (!m_rectBtn.PtInRect(p))
			ReleaseButton();
	}
	
	CWnd::OnMouseMove(nFlags, point);
}

// Function name	: CMultiColumnComboBox::ReleaseButton
// Description	    : Call to release the capture and image of button. After SetButton()
// Return type		: void 
void CMultiColumnComboBox::ReleaseButton()
{
	if (m_bCaptured)
	{
		ReleaseCapture();
		CDC* pDC = GetDC();
			DrawButton(pDC, m_rectBtn);
		ReleaseDC(pDC);
		m_bCaptured = FALSE;
		GetListCtrl()->SetCapture();
	}
}

// Function name	: CMultiColumnComboBox::SetButton
// Description	    : 
// Return type		: void 
void CMultiColumnComboBox::SetButton()
{
	if (!m_bCaptured)
	{
		SetCapture();
		CDC* pDC = GetDC();
			DrawButton(pDC, m_rectBtn, TRUE);
		ReleaseDC(pDC);
		m_bCaptured = TRUE;
	}
}

// Function name	: CMultiColumnComboBox::ForwardMessage
// Description	    : This function is called by ListCtrlWindowProc
// Return type		: void 
// Argument         : UINT nMsg
// Argument         : WPARAM wParam
// Argument         : LPARAM lParam
void CMultiColumnComboBox::ForwardMessage(UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	CListCtrl* pListCtrl = GetListCtrl();
	switch (nMsg)
	{
		case WM_MOUSEMOVE:
		case WM_NCMOUSEMOVE:
		{
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
			pListCtrl->SetCapture();
		}
		case WM_LBUTTONDOWN:
		{
			CPoint point(LOWORD(lParam), HIWORD(lParam));
			CRect rectWindow; pListCtrl->GetWindowRect(rectWindow);
			CRect rectClient; pListCtrl->GetClientRect(rectClient);
			pListCtrl->ClientToScreen(rectClient);
			CPoint pointScreen(point);
			pListCtrl->ClientToScreen(&pointScreen);
			LPARAM lPoint = MAKELPARAM(pointScreen.x, pointScreen.y);
			BOOL bClient = rectClient.PtInRect(pointScreen);
			if ( bClient )
			{
				int nIndex = pListCtrl->HitTest(CPoint(LOWORD(lParam), HIWORD(lParam)));
				if (nIndex >= 0)
					if (GetCurrentItem() != nIndex)
						SetCurrentItem(nIndex);
			}
			else 
				if (rectWindow.PtInRect(pointScreen))
					if (nMsg == WM_LBUTTONDOWN)
					{
						ReleaseCapture();
						pListCtrl->SendMessage(WM_NCLBUTTONDOWN, pListCtrl->SendMessage(WM_NCHITTEST,0,lPoint), lPoint);
						pListCtrl->SetCapture();
						break;
					};
			if (nMsg == WM_LBUTTONDOWN)
			{
				DropDown(FALSE);
				if ( bClient )
					SelectCurrentItem();
			}
			break;
		}
	}
}

// Function name	: CMultiColumnComboBox::OnSetFocus
// Description	    : When control have focus then edit will take the focus
// Return type		: void 
// Argument         : CWnd* pOldWnd
void CMultiColumnComboBox::OnSetFocus(CWnd* pOldWnd) 
{
	CWnd::OnSetFocus(pOldWnd);
	
	GetEdit()->SetFocus();

}

// Function name	: CMultiColumnComboBox::OnCommand
// Description	    : When something is happen in edit control, notify the list control
// Return type		: BOOL 
// Argument         : WPARAM wParam
// Argument         : LPARAM lParam
BOOL CMultiColumnComboBox::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	if (LOWORD(wParam) == IDEDIT)
		if (HIWORD(wParam) == EN_CHANGE)
		{
			ASSERT( GetEdit() && GetEdit()->GetDlgCtrlID() == IDEDIT);
			CString text,t ;
			GetEdit()->GetWindowText(t);
			Search(t);
		}
	return CWnd::OnCommand(wParam, lParam);
}

// Function name	: CMultiColumnComboBox::Search
// Description	    : Look for the lpszFindItem
// Return type		: void 
// Argument         : LPCTSTR lpszFindItem
void CMultiColumnComboBox::Search(LPCTSTR lpszFindItem)
{
	if (CListCtrl* pListCtrl = GetListCtrl())
	{
		int nItem = 0, n = pListCtrl->GetItemCount(), l = CString(lpszFindItem).GetLength();
		while (nItem < n)
		{
			CString itemL = pListCtrl->GetItemText(nItem, m_nColumnKey).Mid(0,l);
			if (itemL.CompareNoCase(lpszFindItem) == 0)
				break;
			nItem++;
		}
		if (nItem < n)
		{
			SetCurrentItem(nItem);
			pListCtrl->EnsureVisible(nItem, FALSE); 
		}
	}
}

// Function name	: CMultiColumnComboBox::SelectCurrentItem
// Description	    : Select the current item of list. Called if user click the mouse, oor press ENTER
// Return type		: void 
BOOL CMultiColumnComboBox::SelectCurrentItem()
{
	BOOL bResult = FALSE;
	m_nSelectedItem = GetCurrentItem();
	// Store in m_nSelectedItem lastselected item, to retrieve, when drop down occurs
	if (m_nSelectedItem >= 0)
	{
		GetEdit()->SetWindowText(GetListCtrl()->GetItemText(m_nSelectedItem, m_nColumnKey));
		//Notify the parent that one item was changed
		if (m_nSelectedItem >= 0)
			if (CWnd* pParent = GetParent())
			{
				pParent->SendMessage(m_nSelChange, (WPARAM)GetDlgCtrlID(), (LPARAM)m_hWnd);
				bResult = TRUE;
			}
	}
	return bResult;
}

// Function name	: CMultiColumnComboBox::GetCurrentItem
// Description	    : Get current item from list control
// Return type		: int 
int CMultiColumnComboBox::GetCurrentItem()
{
	return m_nCurrentItem;
	//return GetListCtrl()->GetNextItem(-1, LVNI_SELECTED);
}

// Function name	: CMultiColumnComboBox::SetCurrentItem
// Description	    : Set current item from list control to nIndex
// Return type		: void 
// Argument         : int nIndex
void CMultiColumnComboBox::SetCurrentItem(int nIndex)
{
	if (nIndex >= 0)
	{
		GetListCtrl()->SetItemState(nIndex, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		m_nCurrentItem = nIndex;
	}
}

// Function name	: CMultiColumnComboBox::OnCreate
// Description	    : Call OnInit if control is created dynamically
// Return type		: int 
// Argument         : LPCREATESTRUCT lpCreateStruct
int CMultiColumnComboBox::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	OnInit();
	
	return 0;
}

// Function name	: CMultiColumnComboBox::SetRateWidth
// Description	    : This function will changes the width of inside listcontrol
// Return type		: double 
// Argument         : double dWidthList
double CMultiColumnComboBox::SetRateWidth(double dWidthList)
{
	double dResult = m_dWidthList;
	m_dWidthList = fabs(dWidthList);
	return dResult;
}

// Function name	: CMultiColumnComboBox::SetMultipleHeight
// Description	    : 
// Return type		: int 
// Argument         : int nMHeight
int CMultiColumnComboBox::SetMultipleHeight(int nMHeight)
{
	int nResult = m_nMultipleHeight;
	m_nMultipleHeight = abs(nMHeight);
	return nResult;
}

// Function name	: CMultiColumnComboBox::WindowProc
// Description	    : 
// Return type		: LRESULT 
// Argument         : UINT message
// Argument         : WPARAM wParam
// Argument         : LPARAM lParam
LRESULT CMultiColumnComboBox::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (GetEdit())
		switch ( message )
		{
			case WM_SETTEXT:
			case WM_GETTEXT:
			{
				GetEdit()->SendMessage( message, wParam, lParam );
				break;
			}
		}
	
	return CWnd::WindowProc(message, wParam, lParam);
}

// Function name	: CMultiColumnComboBox::OnSize
// Description	    : resize combo if needs
// Return type		: void 
// Argument         : UINT nType
// Argument         : int cx
// Argument         : int cy
void CMultiColumnComboBox::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	Resize();
	
}

// Function name	: CMultiColumnComboBox::CaptureListCtrl
// Description	    : Capture listcontrol to know when the drop will be up
// Return type		: void 
void CMultiColumnComboBox::CaptureListCtrl()
{
	if (IsDropedDown())
		GetListCtrl()->SetCapture();
}

// Function name	: CMultiColumnComboBox::OnKeyDown
// Description	    : Treat here the VK_RETURN key
// Return type		: void 
// Argument         : UINT nChar
// Argument         : UINT nRepCnt
// Argument         : UINT nFlags
void CMultiColumnComboBox::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	switch (nChar)
	{
		case VK_RETURN:
		case VK_SPACE:
		{
			DropDown(FALSE);
			SelectCurrentItem();
		}
		case VK_ESCAPE:
		{
			DropDown(FALSE);
			break;
		}
		case VK_UP:
		case VK_DOWN:
		case VK_PRIOR:
		case VK_NEXT:
		{
			//dispatch enter,... keys to multi column...
			GetListCtrl()->SendMessage(WM_KEYDOWN, nChar, 0);
			break;
		}
	}
	
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
