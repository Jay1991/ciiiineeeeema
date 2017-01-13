#dim VersionInfo[4];
#define MyAppVersionNo ParseVersion(AddBackslash(SourcePath) + "..\bin\zfpcom.dll", VersionInfo[0], VersionInfo[1], VersionInfo[2], VersionInfo[3])
#define AppVersion Str(VersionInfo[0]) + "." + Str(VersionInfo[1])+ "." + Str(VersionInfo[2])
#define SetupVersion Str(VersionInfo[0]) + Str(VersionInfo[1]) + Str(VersionInfo[2])

[Setup]
OutputBaseFilename=zfplib3redist
OutputDir=..\redist
SolidCompression=true
AppCopyright=Copyright © Tremol Ltd.
AppName=Zeka Fiscal Printer support library
AppVerName=Zeka Fiscal Printer support library v{#AppVersion}
RestartIfNeededByRun=false
AllowCancelDuringInstall=false
CreateAppDir=true
DefaultDirName={pf}\ZekaFP\3.0
UsePreviousGroup=false
AlwaysShowComponentsList=false
ShowLanguageDialog=no
Uninstallable=false
AppPublisher=Tremol Ltd.
AppComments=ZFPlib (Zeka Fiscal Printer support library) Redistributable

VersionInfoCompany=Tremol Ltd.
VersionInfoDescription=ZFPlib - Zeka Fiscal Printer support library Redistributable
VersionInfoVersion={#GetFileVersion("..\bin\zfpcom.dll")}
VersionInfoTextVersion={#AppVersion}

DisableReadyPage=true
DisableReadyMemo=true
;DisableDirPage=true
DisableProgramGroupPage=true
DisableFinishedPage=true
AppendDefaultDirName=false

[Files]
; binary
Source: ..\bin\zfpcom.dll; DestDir: {app}\bin; Flags: regserver replacesameversion
Source: ..\bin\zfpcom.tlb; DestDir: {app}\bin; Flags: regtypelib replacesameversion
Source: ..\bin\zfpcash.exe; DestDir: {app}\bin; Flags: replacesameversion
Source: ..\bin\zfpcash.chm; DestDir: {app}\bin;
