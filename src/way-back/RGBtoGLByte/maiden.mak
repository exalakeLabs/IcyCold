# Microsoft Developer Studio Generated NMAKE File, Based on maiden.dsp
!IF "$(CFG)" == ""
CFG=maiden - Win32 Debug
!MESSAGE No configuration specified. Defaulting to maiden - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "maiden - Win32 Release" && "$(CFG)" != "maiden - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "maiden.mak" CFG="maiden - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "maiden - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "maiden - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "maiden - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\maiden.exe"

!ELSE 

ALL : "$(OUTDIR)\maiden.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\maiden.obj"
	-@erase "$(INTDIR)\sgi.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\maiden.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D\
 "_MBCS" /Fp"$(INTDIR)\maiden.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\maiden.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=opengl32.lib glu32.lib glut32.lib kernel32.lib user32.lib\
 gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib\
 oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console\
 /incremental:no /pdb:"$(OUTDIR)\maiden.pdb" /machine:I386\
 /out:"$(OUTDIR)\maiden.exe" 
LINK32_OBJS= \
	"$(INTDIR)\maiden.obj" \
	"$(INTDIR)\sgi.obj"

"$(OUTDIR)\maiden.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "maiden - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\maiden.exe"

!ELSE 

ALL : "$(OUTDIR)\maiden.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\maiden.obj"
	-@erase "$(INTDIR)\sgi.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\maiden.exe"
	-@erase "$(OUTDIR)\maiden.ilk"
	-@erase "$(OUTDIR)\maiden.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE"\
 /D "_MBCS" /Fp"$(INTDIR)\maiden.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\maiden.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=opengl32.lib glu32.lib glut32.lib kernel32.lib user32.lib\
 gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib\
 oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console\
 /incremental:yes /pdb:"$(OUTDIR)\maiden.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\maiden.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\maiden.obj" \
	"$(INTDIR)\sgi.obj"

"$(OUTDIR)\maiden.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "maiden - Win32 Release" || "$(CFG)" == "maiden - Win32 Debug"
SOURCE=.\maiden.cpp

!IF  "$(CFG)" == "maiden - Win32 Release"

DEP_CPP_MAIDE=\
	".\sgi.h"\
	{$(INCLUDE)}"gl\glut.h"\
	

"$(INTDIR)\maiden.obj" : $(SOURCE) $(DEP_CPP_MAIDE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "maiden - Win32 Debug"

DEP_CPP_MAIDE=\
	".\sgi.h"\
	{$(INCLUDE)}"GL\gl.h"\
	{$(INCLUDE)}"GL\glu.h"\
	{$(INCLUDE)}"gl\glut.h"\
	

"$(INTDIR)\maiden.obj" : $(SOURCE) $(DEP_CPP_MAIDE) "$(INTDIR)"


!ENDIF 

SOURCE=.\sgi.cpp

"$(INTDIR)\sgi.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

