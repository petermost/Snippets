@echo off
rem Windows-7 is not automatically executing AUTOEXEC.BAT anymore, so add it to
rem HKEY_CURRENT_USER/SOFTWARE/Microsoft/Windows/CurrentVersion/Run

rem To disable restoring the network connections execute:
rem reg add HKLM\SYSTEM\CurrentControlSet\Control\NetworkProvider /v RestoreConnection /t REG_DWORD /d 0

rem set GANT_HOME=C:\Tools\gant-1.9.5
rem set JYTHON_HOME=C:\Programme\Jython2.5.0
rem set NMAP_HOME=C:\Programme\Nmap
rem set COMFYJ_HOME=R:\crtu_meg\bin\Comfyj\bin

rem Disabled MSVC_HOME so cmake finds the mingw compiler first
rem Calling 'vcvarsall.bat' here doesn't set the vars so add the directory so we can call it directly:
rem set MSVC_HOME=C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC

set VIM_HOME=C:\Program Files (x86)\Vim\vim74
set JAVA_BIN_HOME=C:\Program Files (x86)\Java\jdk8\bin
set ANT_BIN_HOME=C:\Tools\apache-ant-1.8.2\bin
set GROOVY_BIN_HOME=C:\Program Files (x86)\Groovy\Groovy-1.8.0\bin
set PYTHON_HOME=C:\Tools\Python27
set JEDIT_HOME=C:\Tools\jEdit
set CRTU_MEG_HOME=R:\crtu_meg\bin
set CMWTOOLS_HOME=C:\JazzMarsSandbox

set MSYS2_HOME=c:\msys64
set MSYS2_BIN_HOME=%MSYS2_HOME%\usr\bin
set MINGW_BIN_HOME=%MSYS2_HOME%\mingw64\bin

rem Windows-7 is still parsing the AUTOEXEC.BAT for environment variables and it appends the settings
rem to the existing variables like PATH. So we don't need to prepend our new path with %PATH%

set PATH=%MINGW_BIN_HOME%;%MSYS2_BIN_HOME%;%VIM_HOME%;%JEDIT_HOME%;%JAVA_BIN_HOME%;%GROOVY_BIN_HOME%;%ANT_BIN_HOME%;%PYTHON_HOME%;C:\Tools

rem Test for R&S specific environment variable:
rem Note: It must point to the 'Rohde-Schwarz' directory!

if not "%RSCommonDocuments%" == "" echo "RSCommonDocuments already exists <%RSCommonDocuments%>!"
set RSCommonDocuments=C:\Users\Public\Documents\Rohde-Schwarz\

rem Disable debug heap:
set _NO_DEBUG_HEAP=1

rem Remove unused/unneeded net drives:

rem net use J: /delete 
rem net use K: /delete 
rem net use N: /delete 
rem net use P: /delete
rem net use Q: /delete 
rem net use S: /delete 
rem net use T: /delete 

rem subst /D r:

rem MCT-Tools Entwicklung:
subst r: C:\ClearCaseViews\mcttools_view

rem Start Launchy:
echo Starting 'Launchy'...
start c:\tools\launchy\launchy

rem Start RBTray for minimize windows to tray:
echo Starting 'RBTray'...
echo Minimize windows by right clicking on the minimize symbol.
start C:\Tools\RBTray-4_3\64bit\RBTray

rem Delete the temp directory:
C:\Tools\DeleteOldFiles\DeleteOldFiles %temp%

rem Check for missing paths:
C:\Entwicklung_Cpp_Tools\CheckPath\bin\CheckPath

