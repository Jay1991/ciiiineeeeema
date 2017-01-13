program zfpdelphi;

uses
  Forms,
  MainUnit in 'MainUnit.pas' {ZFPForm},
  ZFPCOMLib_TLB in 'ZFPCOMLib_TLB.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TZFPForm, ZFPForm);
  Application.Run;
end.
