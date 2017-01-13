
#define SAMPLES
#define API
#define SOURCECODE

#define BULGARIAN
#define INTERNATIONAL

#dim VersionInfo[4];
#define MyAppVersionNo ParseVersion(AddBackslash(SourcePath) + "..\bin\zfpcom.dll", VersionInfo[0], VersionInfo[1], VersionInfo[2], VersionInfo[3])
#define AppVersion Str(VersionInfo[0]) + "." + Str(VersionInfo[1])+ "." + Str(VersionInfo[2])
#define SetupVersion Str(VersionInfo[0]) + Str(VersionInfo[1]) + Str(VersionInfo[2])

[Setup]
AppId=zfplib{#SetupVersion}
Compression=lzma
OutputBaseFilename=zfplib{#SetupVersion}sdk
VersionInfoVersion={#GetFileVersion("..\bin\zfpcom.dll")}
VersionInfoTextVersion={#AppVersion}
VersionInfoCompany=Tremol Ltd.
VersionInfoDescription=ZFPlib - Zeka Fiscal Printer support library (open source)
AppCopyright=Copyright © Tremol Ltd.
AppName=ZFPlib - Zeka Fiscal Printer support library
AppVerName=ZFPlib - Zeka Fiscal Printer support library v{#AppVersion}
DefaultDirName={pf}\ZekaFP\3.0
AllowNoIcons=true
DefaultGroupName=Zeka FP library
ShowLanguageDialog=yes
AppPublisher=Tremol Ltd.
AppPublisherURL=http://www.tremol.bg/
AppSupportURL=http://www.tremol.bg/
AppUpdatesURL=http://www.tremol.bg/
UninstallFilesDir={app}\uninstall
UninstallDisplayIcon={app}\bin\zfpcash.exe
LicenseFile=..\license.rtf

[Languages]
#ifdef BULGARIAN
Name: bg; MessagesFile: Bulgarian-5.1.0.isl
#endif
Name: en; MessagesFile: compiler:Default.isl

[Messages]
#ifdef BULGARIAN
bg.BeveledLabel=Zeka Фискален Принтер
#endif
en.BeveledLabel=Zeka Fiscal Printer

[CustomMessages]
; my messages
en.zCompiled=Compiled version + samples
en.zFullInstall=Full install
en.zChooseComponens=Choose components
en.zMainPart=Main components
en.zSamples=Sample programs
en.zAPI=API documentation
en.zSourceCode=Source code (C++, license: Mozilla Public License 1.1)
en.zSampleIcon=Create a &desktop icons for the Sample application

#ifdef BULGARIAN
; my messages
bg.zCompiled=Компилирана версия + примери
bg.zFullInstall=Пълна инсталация
bg.zChooseComponens=Избор на компоненти
bg.zMainPart=Основна част
bg.zSamples=Примерни програми
bg.zAPI=Документация на програмния интерфейс
bg.zSourceCode=Source code (C++, лиценз: Mozilla Public License 1.1)
bg.zSampleIcon=Икони на &десктопа за примерното приложение (за различни езици и версии)
#endif

[Types]
Name: binary; Description: {cm:zCompiled}
Name: full; Description: {cm:zFullInstall}
Name: custom; Description: {cm:zChooseComponens}; Flags: iscustom

[Components]
Name: binary; Description: {cm:zMainPart}; Types: full custom binary; Flags: fixed

#ifdef SAMPLES
Name: samples; Description: {cm:zSamples}; Types: full custom binary; Flags: fixed
#endif

#ifdef API
Name: api; Description: {cm:zAPI}; Types: full custom
#endif

#ifdef SOURCECODE
Name: sourcecode; Description: {cm:zSourceCode}; Types: full custom
#endif

[Files]
; binary
Source: ..\bin\zfpcom.dll; DestDir: {app}\bin; Components: binary; Flags: regserver replacesameversion
Source: ..\bin\zfpcom.tlb; DestDir: {app}\bin; Components: binary; Flags: regtypelib replacesameversion
Source: ..\bin\zfpcash.exe; DestDir: {app}\bin; Components: binary; Flags: replacesameversion
Source: ..\bin\zfpcash.chm; DestDir: {app}\bin; Components: binary;
Source: ..\lib\zfplib.lib; DestDir: {app}\lib; Components: binary
Source: ..\license.rtf; DestDir: {app}; Components: binary
Source: ..\license.html; DestDir: {app}; Components: binary
Source: ..\redist\zfplib*.*; DestDir: {app}\redist; Components: binary

; source
#ifdef SOURCECODE
Source: ..\include\*.*; DestDir: {app}\include; Components: sourcecode
Source: ..\zfplib\*.*; DestDir: {app}\zfplib; Components: sourcecode; Flags: recursesubdirs
Source: ..\zfpcom\*.h; DestDir: {app}\zfpcom; Components: sourcecode
Source: ..\zfpcom\*.cpp; DestDir: {app}\zfpcom; Components: sourcecode
Source: ..\zfpcom\*.def; DestDir: {app}\zfpcom; Components: sourcecode
Source: ..\zfpcom\*.idl; DestDir: {app}\zfpcom; Components: sourcecode
Source: ..\zfpcom\*.mk; DestDir: {app}\zfpcom; Components: sourcecode
Source: ..\zfpcom\*.rc; DestDir: {app}\zfpcom; Components: sourcecode
Source: ..\zfpcom\*.rgs; DestDir: {app}\zfpcom; Components: sourcecode
Source: ..\zfpcom\*.dsp; DestDir: {app}\zfpcom; Components: sourcecode

Source: ..\zfpcash\*.h; DestDir: {app}\zfpcash; Components: sourcecode
Source: ..\zfpcash\*.cpp; DestDir: {app}\zfpcash; Components: sourcecode
Source: ..\zfpcash\*.rc; DestDir: {app}\zfpcash; Components: sourcecode
Source: ..\zfpcash\*.dsp; DestDir: {app}\zfpcash; Components: sourcecode
Source: ..\zfpcash\res\*.*; DestDir: {app}\zfpcash\res; Components: sourcecode
Source: ..\zfpcash\help\*.*; DestDir: {app}\zfpcash\help; Components: sourcecode
Source: ..\zfpcash\description.txt; DestDir: {app}\zfpcash; Components: sourcecode

Source: ..\vstudio\*.dsp; DestDir: {app}\vstudio; Components: sourcecode
Source: ..\vstudio\*.dsw; DestDir: {app}\vstudio; Components: sourcecode
Source: ..\setup\*.*; DestDir: {app}\setup; Components: sourcecode
#endif

; samples
#ifdef SAMPLES
Source: ..\samples\*.html; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.js; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.css; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.jpg; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.gif; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs

Source: ..\samples\*.cpp; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
;Source: ..\samples\*.rc; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
;Source: ..\samples\*.h; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.dsp; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\cpp\sellfree\release\sellfree.exe; DestDir: {app}\samples\cpp\sellfree\release\; Components: samples; Flags: replacesameversion

Source: ..\samples\*.frm; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.frx; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.vbp; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.vbw; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\vb\vbsample1.exe; DestDir: {app}\samples\vb; Components: samples; Flags: replacesameversion

Source: ..\samples\*.cs; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.resx; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.ico; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.csproj; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.sln; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\cs\zfpcs\bin\*.*; DestDir: {app}\samples\cs\zfpcs\bin; Components: samples; Flags: replacesameversion

Source: ..\samples\*.aspx; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.asax; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.config; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.webinfo; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\asp.net\bin\*.dll; DestDir: {app}\samples\asp.net\bin; Components: samples; Flags: replacesameversion

Source: ..\samples\*.dfm; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.pas; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.dcr; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.dof; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.dpr; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
Source: ..\samples\*.res; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs
;Source: ..\samples\delphi\zfpdelphi.exe; DestDir: {app}\samples\delphi; Components: samples; Flags: replacesameversion

Source: ..\samples\*.xls; DestDir: {app}\samples; Components: samples; Flags: recursesubdirs

#endif

; api
#ifdef API
Source: ..\docs\api\*.*; DestDir: {app}\docs\api; Components: api; Flags: recursesubdirs
Source: ..\docs\COM api\*.*; DestDir: {app}\docs\COM api; Components: api; Flags: recursesubdirs
#endif

[Tasks]
#ifdef SAMPLES
Name: desktopicon_samplehtml; Description: {cm:zSampleIcon}; GroupDescription: Icons:; Components: samples
#endif

[Icons]
Name: {group}\ZFPlib license; Filename: {app}\license.html; WorkingDir: {app}; Components: binary; Comment: Mozilla Public License version 1.1
#ifdef BULGARIAN
Name: {group}\ZFPcash помощна програма; Filename: {app}\bin\zfpcash.exe; WorkingDir: {app}\bin; Components: binary; Comment: cashfile и fprint съвместима програма за Zeka FP
#endif

#ifdef SAMPLES
#ifdef BULGARIAN
Name: {group}\Samples\bg\ZFPlib пример (Български); Filename: {pf}\Internet Explorer\iexplore.exe; Parameters: "{app}\samples\html\bg\index.html"; WorkingDir: {app}\samples\html\bg; Components: samples; Comment: Примерно приложение използващо ZFPlib за работа със Zeka Фискален Принтер
Name: {userdesktop}\ZFPlib пример (Български); Filename: {pf}\Internet Explorer\iexplore.exe; Parameters: "{app}\samples\html\bg\index.html"; WorkingDir: {app}\samples\html\bg; Components: samples; Comment: Примерно приложение използващо ZFPlib за работа със Zeka Фискален Принтер
#endif

Name: {group}\Samples\en\ZFPlib example (BG in English); Filename: {pf}\Internet Explorer\iexplore.exe; Parameters: "{app}\samples\html\en\index.html"; WorkingDir: {app}\samples\html\en; Components: samples; Comment: Sample application for ZFPlib
Name: {userdesktop}\ZFPlib example (BG in English); Filename: {pf}\Internet Explorer\iexplore.exe; Parameters: "{app}\samples\html\en\index.html"; WorkingDir: {app}\samples\html\en; Components: samples; Tasks: desktopicon_samplehtml; Comment: Sample application for ZFPlib

Name: {group}\Samples\Excel sample; Filename: {app}\samples\excel\zfplib_sample1.xls; WorkingDir: {app}\samples\excel; Components: samples; Comment: Sample Excel application for ZFPlib

#ifdef INTERNATIONAL
Name: {group}\Samples\en\ZFPlib example (International); Filename: {pf}\Internet Explorer\iexplore.exe; Parameters: "{app}\samples\html\international\index.html"; WorkingDir: {app}\samples\html\international; Components: samples; Comment: Sample application for ZFPlib (International)
Name: {userdesktop}\ZFPlib example (International); Filename: {pf}\Internet Explorer\iexplore.exe; Parameters: "{app}\samples\html\international\index.html"; WorkingDir: {app}\samples\html\international; Components: samples; Tasks: desktopicon_samplehtml; Comment: Sample application for ZFPlib (International)
#endif

Name: {group}\Samples\Go to samples directory; Filename: {app}\samples; WorkingDir: {app}\samples; Components: samples; Comment: Samples in several programming languages
#endif

#ifdef API

Name: {group}\en\ZFPlib C++ API (English); Filename: {app}\docs\api\en\index_en.html; WorkingDir: {app}\docs\api\en; Components: api; Comment: Description of the ZFPlib API (C++)
Name: {group}\en\ZFPlib COM API (English); Filename: {app}\docs\COM api\en\index_en.html; WorkingDir: {app}\docs\COM api\en; Components: api; Comment: Description of the ZFPlib API (COM)

#ifdef BULGARIAN
Name: {group}\bg\ZFPlib C++ API (Български); Filename: {app}\docs\api\bg\index_bg.html; WorkingDir: {app}\docs\api\bg; Components: api; Comment: Описание на програмния интерфейс за работа със ZFPlib (C++)
Name: {group}\bg\ZFPlib COM API (Български); Filename: {app}\docs\COM api\bg\index_bg.html; WorkingDir: {app}\docs\COM api\bg; Components: api; Comment: Описание на програмния интерфейс за работа със ZFPlib (COM)
#endif

#endif

