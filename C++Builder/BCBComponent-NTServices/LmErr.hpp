// Borland C++ Builder
// Copyright (c) 1995, 1998 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'lmErr.pas' rev: 3.00

#ifndef lmErrHPP
#define lmErrHPP
#include <SysInit.hpp>
#include <System.hpp>

//-- user supplied -----------------------------------------------------------

namespace Lmerr
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
#define NERR_Success (Byte)(0)
#define NERR_BASE (Word)(2100)
#define NERR_NetNotStarted (Word)(2102)
#define NERR_UnknownServer (Word)(2103)
#define NERR_ShareMem (Word)(2104)
#define NERR_NoNetworkResource (Word)(2105)
#define NERR_RemoteOnly (Word)(2106)
#define NERR_DevNotRedirected (Word)(2107)
#define NERR_ServerNotStarted (Word)(2114)
#define NERR_ItemNotFound (Word)(2115)
#define NERR_UnknownDevDir (Word)(2116)
#define NERR_RedirectedPath (Word)(2117)
#define NERR_DuplicateShare (Word)(2118)
#define NERR_NoRoom (Word)(2119)
#define NERR_TooManyItems (Word)(2121)
#define NERR_InvalidMaxUsers (Word)(2122)
#define NERR_BufTooSmall (Word)(2123)
#define NERR_RemoteErr (Word)(2127)
#define NERR_LanmanIniError (Word)(2131)
#define NERR_NetworkError (Word)(2136)
#define NERR_WkstaInconsistentState (Word)(2137)
#define NERR_WkstaNotStarted (Word)(2138)
#define NERR_BrowserNotStarted (Word)(2139)
#define NERR_InternalError (Word)(2140)
#define NERR_BadTransactConfig (Word)(2141)
#define NERR_InvalidAPI (Word)(2142)
#define NERR_BadEventName (Word)(2143)
#define NERR_DupNameReboot (Word)(2144)
#define NERR_CfgCompNotFound (Word)(2146)
#define NERR_CfgParamNotFound (Word)(2147)
#define NERR_LineTooLong (Word)(2149)
#define NERR_QNotFound (Word)(2150)
#define NERR_JobNotFound (Word)(2151)
#define NERR_DestNotFound (Word)(2152)
#define NERR_DestExists (Word)(2153)
#define NERR_QExists (Word)(2154)
#define NERR_QNoRoom (Word)(2155)
#define NERR_JobNoRoom (Word)(2156)
#define NERR_DestNoRoom (Word)(2157)
#define NERR_DestIdle (Word)(2158)
#define NERR_DestInvalidOp (Word)(2159)
#define NERR_ProcNoRespond (Word)(2160)
#define NERR_SpoolerNotLoaded (Word)(2161)
#define NERR_DestInvalidState (Word)(2162)
#define NERR_QInvalidState (Word)(2163)
#define NERR_JobInvalidState (Word)(2164)
#define NERR_SpoolNoMemory (Word)(2165)
#define NERR_DriverNotFound (Word)(2166)
#define NERR_DataTypeInvalid (Word)(2167)
#define NERR_ProcNotFound (Word)(2168)
#define NERR_ServiceTableLocked (Word)(2180)
#define NERR_ServiceTableFull (Word)(2181)
#define NERR_ServiceInstalled (Word)(2182)
#define NERR_ServiceEntryLocked (Word)(2183)
#define NERR_ServiceNotInstalled (Word)(2184)
#define NERR_BadServiceName (Word)(2185)
#define NERR_ServiceCtlTimeout (Word)(2186)
#define NERR_ServiceCtlBusy (Word)(2187)
#define NERR_BadServiceProgName (Word)(2188)
#define NERR_ServiceNotCtrl (Word)(2189)
#define NERR_ServiceKillProc (Word)(2190)
#define NERR_ServiceCtlNotValid (Word)(2191)
#define NERR_NotInDispatchTbl (Word)(2192)
#define NERR_BadControlRecv (Word)(2193)
#define NERR_ServiceNotStarting (Word)(2194)
#define NERR_AlreadyLoggedOn (Word)(2200)
#define NERR_NotLoggedOn (Word)(2201)
#define NERR_BadUsername (Word)(2202)
#define NERR_BadPassword (Word)(2203)
#define NERR_UnableToAddName_W (Word)(2204)
#define NERR_UnableToAddName_F (Word)(2205)
#define NERR_UnableToDelName_W (Word)(2206)
#define NERR_UnableToDelName_F (Word)(2207)
#define NERR_LogonsPaused (Word)(2209)
#define NERR_LogonServerConflict (Word)(2210)
#define NERR_LogonNoUserPath (Word)(2211)
#define NERR_LogonScriptError (Word)(2212)
#define NERR_StandaloneLogon (Word)(2214)
#define NERR_LogonServerNotFound (Word)(2215)
#define NERR_LogonDomainExists (Word)(2216)
#define NERR_NonValidatedLogon (Word)(2217)
#define NERR_ACFNotFound (Word)(2219)
#define NERR_GroupNotFound (Word)(2220)
#define NERR_UserNotFound (Word)(2221)
#define NERR_ResourceNotFound (Word)(2222)
#define NERR_GroupExists (Word)(2223)
#define NERR_UserExists (Word)(2224)
#define NERR_ResourceExists (Word)(2225)
#define NERR_NotPrimary (Word)(2226)
#define NERR_ACFNotLoaded (Word)(2227)
#define NERR_ACFNoRoom (Word)(2228)
#define NERR_ACFFileIOFail (Word)(2229)
#define NERR_ACFTooManyLists (Word)(2230)
#define NERR_UserLogon (Word)(2231)
#define NERR_ACFNoParent (Word)(2232)
#define NERR_CanNotGrowSegment (Word)(2233)
#define NERR_SpeGroupOp (Word)(2234)
#define NERR_NotInCache (Word)(2235)
#define NERR_UserInGroup (Word)(2236)
#define NERR_UserNotInGroup (Word)(2237)
#define NERR_AccountUndefined (Word)(2238)
#define NERR_AccountExpired (Word)(2239)
#define NERR_InvalidWorkstation (Word)(2240)
#define NERR_InvalidLogonHours (Word)(2241)
#define NERR_PasswordExpired (Word)(2242)
#define NERR_PasswordCantChange (Word)(2243)
#define NERR_PasswordHistConflict (Word)(2244)
#define NERR_PasswordTooShort (Word)(2245)
#define NERR_PasswordTooRecent (Word)(2246)
#define NERR_InvalidDatabase (Word)(2247)
#define NERR_DatabaseUpToDate (Word)(2248)
#define NERR_SyncRequired (Word)(2249)
#define NERR_UseNotFound (Word)(2250)
#define NERR_BadAsgType (Word)(2251)
#define NERR_DeviceIsShared (Word)(2252)
#define NERR_NoComputerName (Word)(2270)
#define NERR_MsgAlreadyStarted (Word)(2271)
#define NERR_MsgInitFailed (Word)(2272)
#define NERR_NameNotFound (Word)(2273)
#define NERR_AlreadyForwarded (Word)(2274)
#define NERR_AddForwarded (Word)(2275)
#define NERR_AlreadyExists (Word)(2276)
#define NERR_TooManyNames (Word)(2277)
#define NERR_DelComputerName (Word)(2278)
#define NERR_LocalForward (Word)(2279)
#define NERR_GrpMsgProcessor (Word)(2280)
#define NERR_PausedRemote (Word)(2281)
#define NERR_BadReceive (Word)(2282)
#define NERR_NameInUse (Word)(2283)
#define NERR_MsgNotStarted (Word)(2284)
#define NERR_NotLocalName (Word)(2285)
#define NERR_NoForwardName (Word)(2286)
#define NERR_RemoteFull (Word)(2287)
#define NERR_NameNotForwarded (Word)(2288)
#define NERR_TruncatedBroadcast (Word)(2289)
#define NERR_InvalidDevice (Word)(2294)
#define NERR_WriteFault (Word)(2295)
#define NERR_DuplicateName (Word)(2297)
#define NERR_DeleteLater (Word)(2298)
#define NERR_IncompleteDel (Word)(2299)
#define NERR_MultipleNets (Word)(2300)
#define NERR_NetNameNotFound (Word)(2310)
#define NERR_DeviceNotShared (Word)(2311)
#define NERR_ClientNameNotFound (Word)(2312)
#define NERR_FileIdNotFound (Word)(2314)
#define NERR_ExecFailure (Word)(2315)
#define NERR_TmpFile (Word)(2316)
#define NERR_TooMuchData (Word)(2317)
#define NERR_DeviceShareConflict (Word)(2318)
#define NERR_BrowserTableIncomplete (Word)(2319)
#define NERR_NotLocalDomain (Word)(2320)
#define NERR_IsDfsShare (Word)(2321)
#define NERR_DevInvalidOpCode (Word)(2331)
#define NERR_DevNotFound (Word)(2332)
#define NERR_DevNotOpen (Word)(2333)
#define NERR_BadQueueDevString (Word)(2334)
#define NERR_BadQueuePriority (Word)(2335)
#define NERR_NoCommDevs (Word)(2337)
#define NERR_QueueNotFound (Word)(2338)
#define NERR_BadDevString (Word)(2340)
#define NERR_BadDev (Word)(2341)
#define NERR_InUseBySpooler (Word)(2342)
#define NERR_CommDevInUse (Word)(2343)
#define NERR_InvalidComputer (Word)(2351)
#define NERR_MaxLenExceeded (Word)(2354)
#define NERR_BadComponent (Word)(2356)
#define NERR_CantType (Word)(2357)
#define NERR_TooManyEntries (Word)(2362)
#define NERR_ProfileFileTooBig (Word)(2370)
#define NERR_ProfileOffset (Word)(2371)
#define NERR_ProfileCleanup (Word)(2372)
#define NERR_ProfileUnknownCmd (Word)(2373)
#define NERR_ProfileLoadErr (Word)(2374)
#define NERR_ProfileSaveErr (Word)(2375)
#define NERR_LogOverflow (Word)(2377)
#define NERR_LogFileChanged (Word)(2378)
#define NERR_LogFileCorrupt (Word)(2379)
#define NERR_SourceIsDir (Word)(2380)
#define NERR_BadSource (Word)(2381)
#define NERR_BadDest (Word)(2382)
#define NERR_DifferentServers (Word)(2383)
#define NERR_RunSrvPaused (Word)(2385)
#define NERR_ErrCommRunSrv (Word)(2389)
#define NERR_ErrorExecingGhost (Word)(2391)
#define NERR_ShareNotFound (Word)(2392)
#define NERR_InvalidLana (Word)(2400)
#define NERR_OpenFiles (Word)(2401)
#define NERR_ActiveConns (Word)(2402)
#define NERR_BadPasswordCore (Word)(2403)
#define NERR_DevInUse (Word)(2404)
#define NERR_LocalDrive (Word)(2405)
#define NERR_AlertExists (Word)(2430)
#define NERR_TooManyAlerts (Word)(2431)
#define NERR_NoSuchAlert (Word)(2432)
#define NERR_BadRecipient (Word)(2433)
#define NERR_AcctLimitExceeded (Word)(2434)
#define NERR_InvalidLogSeek (Word)(2440)
#define NERR_BadUasConfig (Word)(2450)
#define NERR_InvalidUASOp (Word)(2451)
#define NERR_LastAdmin (Word)(2452)
#define NERR_DCNotFound (Word)(2453)
#define NERR_LogonTrackingError (Word)(2454)
#define NERR_NetlogonNotStarted (Word)(2455)
#define NERR_CanNotGrowUASFile (Word)(2456)
#define NERR_TimeDiffAtDC (Word)(2457)
#define NERR_PasswordMismatch (Word)(2458)
#define NERR_NoSuchServer (Word)(2460)
#define NERR_NoSuchSession (Word)(2461)
#define NERR_NoSuchConnection (Word)(2462)
#define NERR_TooManyServers (Word)(2463)
#define NERR_TooManySessions (Word)(2464)
#define NERR_TooManyConnections (Word)(2465)
#define NERR_TooManyFiles (Word)(2466)
#define NERR_NoAlternateServers (Word)(2467)
#define NERR_TryDownLevel (Word)(2470)
#define NERR_UPSDriverNotStarted (Word)(2480)
#define NERR_UPSInvalidConfig (Word)(2481)
#define NERR_UPSInvalidCommPort (Word)(2482)
#define NERR_UPSSignalAsserted (Word)(2483)
#define NERR_UPSShutdownFailed (Word)(2484)
#define NERR_BadDosRetCode (Word)(2500)
#define NERR_ProgNeedsExtraMem (Word)(2501)
#define NERR_BadDosFunction (Word)(2502)
#define NERR_RemoteBootFailed (Word)(2503)
#define NERR_BadFileCheckSum (Word)(2504)
#define NERR_NoRplBootSystem (Word)(2505)
#define NERR_RplLoadrNetBiosErr (Word)(2506)
#define NERR_RplLoadrDiskErr (Word)(2507)
#define NERR_ImageParamErr (Word)(2508)
#define NERR_TooManyImageParams (Word)(2509)
#define NERR_NonDosFloppyUsed (Word)(2510)
#define NERR_RplBootRestart (Word)(2511)
#define NERR_RplSrvrCallFailed (Word)(2512)
#define NERR_CantConnectRplSrvr (Word)(2513)
#define NERR_CantOpenImageFile (Word)(2514)
#define NERR_CallingRplSrvr (Word)(2515)
#define NERR_StartingRplBoot (Word)(2516)
#define NERR_RplBootServiceTerm (Word)(2517)
#define NERR_RplBootStartFailed (Word)(2518)
#define NERR_RPL_CONNECTED (Word)(2519)
#define NERR_BrowserConfiguredToNotRun (Word)(2550)
#define NERR_RplNoAdaptersStarted (Word)(2610)
#define NERR_RplBadRegistry (Word)(2611)
#define NERR_RplBadDatabase (Word)(2612)
#define NERR_RplRplfilesShare (Word)(2613)
#define NERR_RplNotRplServer (Word)(2614)
#define NERR_RplCannotEnum (Word)(2615)
#define NERR_RplWkstaInfoCorrupted (Word)(2616)
#define NERR_RplWkstaNotFound (Word)(2617)
#define NERR_RplWkstaNameUnavailable (Word)(2618)
#define NERR_RplProfileInfoCorrupted (Word)(2619)
#define NERR_RplProfileNotFound (Word)(2620)
#define NERR_RplProfileNameUnavailable (Word)(2621)
#define NERR_RplProfileNotEmpty (Word)(2622)
#define NERR_RplConfigInfoCorrupted (Word)(2623)
#define NERR_RplConfigNotFound (Word)(2624)
#define NERR_RplAdapterInfoCorrupted (Word)(2625)
#define NERR_RplInternal (Word)(2626)
#define NERR_RplVendorInfoCorrupted (Word)(2627)
#define NERR_RplBootInfoCorrupted (Word)(2628)
#define NERR_RplWkstaNeedsUserAcct (Word)(2629)
#define NERR_RplNeedsRPLUSERAcct (Word)(2630)
#define NERR_RplBootNotFound (Word)(2631)
#define NERR_RplIncompatibleProfile (Word)(2632)
#define NERR_RplAdapterNameUnavailable (Word)(2633)
#define NERR_RplConfigNotEmpty (Word)(2634)
#define NERR_RplBootInUse (Word)(2635)
#define NERR_RplBackupDatabase (Word)(2636)
#define NERR_RplAdapterNotFound (Word)(2637)
#define NERR_RplVendorNotFound (Word)(2638)
#define NERR_RplVendorNameUnavailable (Word)(2639)
#define NERR_RplBootNameUnavailable (Word)(2640)
#define NERR_RplConfigNameUnavailable (Word)(2641)
#define NERR_DfsInternalCorruption (Word)(2660)
#define NERR_DfsVolumeDataCorrupt (Word)(2661)
#define NERR_DfsNoSuchVolume (Word)(2662)
#define NERR_DfsVolumeAlreadyExists (Word)(2663)
#define NERR_DfsAlreadyShared (Word)(2664)
#define NERR_DfsNoSuchShare (Word)(2665)
#define NERR_DfsNotALeafVolume (Word)(2666)
#define NERR_DfsLeafVolume (Word)(2667)
#define NERR_DfsVolumeHasMultipleServers (Word)(2668)
#define NERR_DfsCantCreateJunctionPoint (Word)(2669)
#define NERR_DfsServerNotDfsAware (Word)(2670)
#define NERR_DfsBadRenamePath (Word)(2671)
#define NERR_DfsVolumeIsOffline (Word)(2672)
#define NERR_DfsInternalError (Word)(2690)
#define MAX_NERR (Word)(2999)

}	/* namespace Lmerr */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Lmerr;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// lmErr