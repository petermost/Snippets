@echo off
rem Windows-7 is not automatically executing AUTOEXEC.BAT anymore, so add it to
rem HKEY_CURRENT_USER/SOFTWARE/Microsoft/Windows/CurrentVersion/Run

rem To disable restoring the network connections execute:
rem reg add HKLM\SYSTEM\CurrentControlSet\Control\NetworkProvider /v RestoreConnection /t REG_DWORD /d 0

rem set GANT_HOME=C:\Tools\gant-1.9.5
rem set JYTHON_HOME=C:\Programme\Jython2.5.0
rem set CYGWIN_HOME=C:\cygwin
rem set NMAP_HOME=C:\Programme\Nmap

set QT_BIN_HOME=C:\Qt\Qt5.5.0\5.5\mingw492_32\bin
set MINGW_BIN_HOME=C:\Qt\Qt5.5.0\Tools\mingw492_32\bin
set CMAKE_BIN_HOME=C:\Tools\cmake-3\bin
set VIM_HOME=C:\Program Files (x86)\Vim\vim74
set JAVA_BIN_HOME=C:\Program Files (x86)\Java\jdk8\bin
set ANT_BIN_HOME=C:\Tools\apache-ant-1.8.2\bin
set GROOVY_BIN_HOME=C:\Program Files (x86)\Groovy\Groovy-1.8.0\bin
set PYTHON_HOME=C:\Tools\Python27
set JEDIT_HOME=C:\Tools\jEdit
rem Calling 'vcvarsall.bat' here doesn't set the vars so add the directory so we can call it directly:
set MSVC_HOME=C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC
set COMFYJ_HOME=R:\crtu_meg\bin\Comfyj\bin
set CRTU_MEG_HOME=R:\crtu_meg\bin
set CMWTOOLS_HOME=C:\JazzMarsSandbox

rem Windows-7 is still parsing the AUTOEXEC.BAT for environment variables and it appends the settings
rem to the existing variables like PATH. So we don't need to prepend our new path with %PATH%

set PATH=C:\Tools;%VIM_HOME%;%JEDIT_HOME%;%MSVC_HOME%;%QT_BIN_HOME%;%MINGW_BIN_HOME%;%CMAKE_BIN_HOME%;%JAVA_BIN_HOME%;%GROOVY_BIN_HOME%;%ANT_BIN_HOME%;%PYTHON_HOME%

rem Test for R&S specific environment variable:
rem Note: It must point to the 'Rohde-Schwarz' directory!

if not "%RSCommonDocuments%" == "" echo "RSCommonDocuments already exists <%RSCommonDocuments%>!"
set RSCommonDocuments=C:\Users\Public\Documents\Rohde-Schwarz\
					  
rem Remove unused/unneeded net drives:

rem J: \\RSINT.NET\DATA\CAP
rem K: \\RSINT.NET\DATA\MU\SATURN\APP-ARIEL
rem M: \\view
rem N: \\RSINT.NET\DATA\MU\SATURN\SECTION
rem P: \\RSINT.NET\DATA\MU\SATURN\USER\most\DATEN
rem Q: \\RSINT.NET\DATA\MU\SATURN\PROJECT\1cm_PVCS
rem S: \\RSINT.NET\DATA\MU\SATURN\GROUP\GR_1CM
rem T: \\RSINT.NET\DATA\MU\SATURN\TRANSFER
rem X: \\RSINT.NET\DATA\MU\SATURN

net use J: /delete 
net use K: /delete 
net use N: /delete 
net use P: /delete
net use Q: /delete 
net use S: /delete 
net use T: /delete 

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

rem Check for non-existing paths:
C:\Entwicklung_Cpp_Tools\CheckPath\bin\CheckPath

rem Delete the temp directory:
C:\Entwicklung_Cpp_Tools\DeleteOldFiles\bin\DeleteOldFiles %temp%

