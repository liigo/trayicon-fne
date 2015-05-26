# Microsoft Developer Studio Project File - Name="trayicon_static" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=trayicon_static - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "trayicon_static.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "trayicon_static.mak" CFG="trayicon_static - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "trayicon_static - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "trayicon_static - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "trayicon_static - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "trayicon_static___Win32_Release"
# PROP BASE Intermediate_Dir "trayicon_static___Win32_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "trayicon_static___Win32_Release"
# PROP Intermediate_Dir "trayicon_static___Win32_Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "__E_STATIC_LIB" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"C:\Program Files\e\static_lib\TrayIcon_static.lib"
# Begin Special Build Tool
TargetPath=C:\Program Files\e\static_lib\TrayIcon_static.lib
SOURCE="$(InputPath)"
PostBuild_Cmds="C:\Program Files\e\sdk\tools\resym.exe" all infile="$(TargetPath)" outfile="$(TargetPath)"
# End Special Build Tool

!ELSEIF  "$(CFG)" == "trayicon_static - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "trayicon_static___Win32_Debug"
# PROP BASE Intermediate_Dir "trayicon_static___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "trayicon_static___Win32_Debug"
# PROP Intermediate_Dir "trayicon_static___Win32_Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "__E_STATIC_LIB" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"C:\Program Files\e\static_lib\TrayIcon_static.lib"
# Begin Special Build Tool
TargetPath=C:\Program Files\e\static_lib\TrayIcon_static.lib
SOURCE="$(InputPath)"
PostBuild_Cmds="C:\Program Files\e\sdk\tools\resym.exe" all infile="$(TargetPath)" outfile="$(TargetPath)"
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "trayicon_static - Win32 Release"
# Name "trayicon_static - Win32 Debug"
# Begin Group "Resource Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\blank_bl.ico
# End Source File
# Begin Source File

SOURCE=.\Blank_Black.ico
# End Source File
# Begin Source File

SOURCE=.\DefaultIcon.ico
# End Source File
# Begin Source File

SOURCE=.\icon1.ico
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\elib_h\fnshare.h
# End Source File
# Begin Source File

SOURCE=.\elib_h\krnllib.h
# End Source File
# Begin Source File

SOURCE=.\elib_h\lang.h
# End Source File
# Begin Source File

SOURCE=.\elib_h\lib2.h
# End Source File
# Begin Source File

SOURCE=.\elib_h\mem.h
# End Source File
# Begin Source File

SOURCE=.\elib_h\mylog.h
# End Source File
# Begin Source File

SOURCE=.\NewWnd_component.h
# End Source File
# Begin Source File

SOURCE=.\NewWnd_wrap.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TrayIcon.h
# End Source File
# Begin Source File

SOURCE=.\TrayIconPosition.h
# End Source File
# Begin Source File

SOURCE=.\elib_h\untshare.h
# End Source File
# End Group
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ELIB_H\FNSHARE.CPP
# End Source File
# Begin Source File

SOURCE=.\ELIB_H\MEM.CPP
# End Source File
# Begin Source File

SOURCE=.\ELIB_H\MYLOG.CPP
# End Source File
# Begin Source File

SOURCE=.\NewWnd_wrap.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TrayIcon.cpp
# End Source File
# Begin Source File

SOURCE=.\TrayIcon.def
# End Source File
# Begin Source File

SOURCE=.\TrayIcon.rc
# End Source File
# Begin Source File

SOURCE=.\TrayIconPosition.cpp
# End Source File
# Begin Source File

SOURCE=.\ELIB_H\UNTSHARE.CPP
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
