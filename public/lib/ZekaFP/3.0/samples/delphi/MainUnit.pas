unit MainUnit;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, OleServer, ZFPCOMLib_TLB;

type
  TZFPForm = class(TForm)
    Label1: TLabel;
    ComPorts: TComboBox;
    FindBtn: TButton;
    version: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    cOperator: TEdit;
    cPassword: TEdit;
    OpenFiscalReceipt: TButton;
    Bevel1: TBevel;
    Label4: TLabel;
    cArticle: TEdit;
    Label5: TLabel;
    cTaxGroup: TComboBox;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    cPrice: TEdit;
    cQuantity: TEdit;
    cDiscount: TEdit;
    cSell: TButton;
    Bevel2: TBevel;
    cCalc: TButton;
    cSum: TEdit;
    Label9: TLabel;
    cPayType: TComboBox;
    cPayment: TButton;
    Bevel3: TBevel;
    cCurentReceipt: TButton;
    Label10: TLabel;
    cPurchases: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    Label13: TLabel;
    cVATc: TLabel;
    cVATb: TLabel;
    cVATa: TLabel;
    cNoVoid: TCheckBox;
    cPayStarted: TCheckBox;
    cPrintVAT: TCheckBox;
    cPayFinished: TCheckBox;
    cDetailed: TCheckBox;
    Bevel4: TBevel;
    closeFiscal: TButton;
    Label14: TLabel;
    cBaud: TComboBox;
    procedure FindBtnClick(Sender: TObject);
    procedure OpenFiscalReceiptClick(Sender: TObject);
    procedure cSellClick(Sender: TObject);
    procedure cCalcClick(Sender: TObject);
    procedure cPaymentClick(Sender: TObject);
    procedure cCurentReceiptClick(Sender: TObject);
    procedure closeFiscalClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  ZFPForm: TZFPForm;
  zfp: TZekaFP;

implementation

{$R *.dfm}

procedure TZFPForm.FindBtnClick(Sender: TObject);
var
    com: LongWord;
begin
    com := zfp.FindFirstFPCOM();
	if (0 <> com) then begin
		ComPorts.ItemIndex := (com and $FFFF) - 1;
        if (19200 = com shr 16) then
            cBaud.ItemIndex := 1
        else
            cBaud.ItemIndex := 0;
		zfp.Setup(ComPorts.ItemIndex + 1, com shr 16, 3, 1000);
		version.Caption := zfp.GetVersion();
	end;
end;

procedure TZFPForm.OpenFiscalReceiptClick(Sender: TObject);
var
    oper: Byte;
    baud: LongWord;
begin
    if (0 < cBaud.ItemIndex) then
        baud := 19200
    else
        baud := 9600;
    zfp.Setup(ComPorts.ItemIndex + 1, baud, 3, 1000);
    oper := Byte(StrToInt(cOperator.Text));
    zfp.OpenFiscalBon(oper, cPassword.Text, 0, 1);
    if (0 <> zfp.errorCode) then begin
        MessageDlg(zfp.GetErrorString(zfp.errorCode, 0), mtError, [mbOk], 0);
    end;
end;

procedure TZFPForm.cSellClick(Sender: TObject);
var
    price, quantity, discount: Single;
    baud: LongWord;
begin
    if (0 < cBaud.ItemIndex) then
        baud := 19200
    else
        baud := 9600;
    zfp.Setup(ComPorts.ItemIndex + 1, baud, 3, 1000);
    price := StrToFloat(cPrice.Text);
    quantity := StrToFloat(cQuantity.Text);
    discount := StrToFloat(cDiscount.Text);
    zfp.SellFree(cArticle.Text, Byte(cTaxGroup.ItemIndex), price, quantity, discount);
    if (0 <> zfp.errorCode) then begin
        MessageDlg(zfp.GetErrorString(zfp.errorCode, 0), mtError, [mbOk], 0);
    end;
end;

procedure TZFPForm.cCalcClick(Sender: TObject);
var
    sum: Double;
    baud: LongWord;
begin
    if (0 < cBaud.ItemIndex) then
        baud := 19200
    else
        baud := 9600;
    zfp.Setup(ComPorts.ItemIndex + 1, baud, 3, 1000);
    sum := zfp.CalcIntermediateSum(1, 1, 0, 0);
    if (0 <> zfp.errorCode) then begin
        MessageDlg(zfp.GetErrorString(zfp.errorCode, 0), mtError, [mbOk], 0);
    end
    else begin
        cSum.Text := Format('%.2f', [sum]);
    end;
end;

procedure TZFPForm.cPaymentClick(Sender: TObject);
var
    sum: Single;
    baud: LongWord;
begin
    if (0 < cBaud.ItemIndex) then
        baud := 19200
    else
        baud := 9600;
    zfp.Setup(ComPorts.ItemIndex + 1, baud, 3, 1000);
    sum := StrToFloat(cSum.Text);
    zfp.Payment(sum, cPayType.ItemIndex, 0);
    if (0 <> zfp.errorCode) then begin
        MessageDlg(zfp.GetErrorString(zfp.errorCode, 0), mtError, [mbOk], 0);
    end;
end;

procedure TZFPForm.cCurentReceiptClick(Sender: TObject);
var
    bi: Variant;
    baud: LongWord;
begin
    if (0 < cBaud.ItemIndex) then
        baud := 19200
    else
        baud := 9600;
    zfp.Setup(ComPorts.ItemIndex + 1, baud, 3, 1000);
    bi := zfp.GetCurrentBonInfo();
    if (0 <> zfp.errorCode) then begin
        MessageDlg(zfp.GetErrorString(zfp.errorCode, 0), mtError, [mbOk], 0);
    end
    else begin
        cPurchases.Caption := bi.purchases;

        cVATa.Caption := bi.taxgrp1;
        cVATb.Caption := bi.taxgrp2;
        cVATc.Caption := bi.taxgrp3;

        cNoVoid.Checked := bi.novoid;
        cPayStarted.Checked := bi.paystarted;
        cPrintVAT.Checked := bi.dds;
        cPayFinished.Checked := bi.paid;
        cDetailed.Checked := bi.detailed;
    end;
end;

procedure TZFPForm.closeFiscalClick(Sender: TObject);
var
    baud: LongWord;
begin
    if (0 < cBaud.ItemIndex) then
        baud := 19200
    else
        baud := 9600;
    zfp.Setup(ComPorts.ItemIndex + 1, baud, 3, 1000);
    zfp.CloseFiscalBon();
    if (0 <> zfp.errorCode) then begin
        MessageDlg(zfp.GetErrorString(zfp.errorCode, 0), mtError, [mbOk], 0);
    end;
end;

procedure TZFPForm.FormCreate(Sender: TObject);
begin
    zfp := TZekaFP.Create(Self);
end;

end.
