object ZFPForm: TZFPForm
  Left = 293
  Top = 344
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Zeka Fiscal Printer - Delphi sample'
  ClientHeight = 430
  ClientWidth = 482
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 12
    Top = 20
    Width = 48
    Height = 13
    Caption = 'COM port:'
  end
  object version: TLabel
    Left = 280
    Top = 20
    Width = 3
    Height = 13
  end
  object Label2: TLabel
    Left = 12
    Top = 56
    Width = 44
    Height = 13
    Caption = 'Operator:'
  end
  object Label3: TLabel
    Left = 192
    Top = 56
    Width = 49
    Height = 13
    Caption = 'Password:'
  end
  object Bevel1: TBevel
    Left = 8
    Top = 88
    Width = 469
    Height = 1
    Style = bsRaised
  end
  object Label4: TLabel
    Left = 12
    Top = 108
    Width = 61
    Height = 13
    Caption = 'Article name:'
  end
  object Label5: TLabel
    Left = 280
    Top = 108
    Width = 51
    Height = 13
    Caption = 'Tax group:'
  end
  object Label6: TLabel
    Left = 376
    Top = 108
    Width = 27
    Height = 13
    Caption = 'Price:'
  end
  object Label7: TLabel
    Left = 12
    Top = 140
    Width = 42
    Height = 13
    Caption = 'Quantity:'
  end
  object Label8: TLabel
    Left = 180
    Top = 140
    Width = 111
    Height = 13
    Caption = 'Addition / Discount (%):'
  end
  object Bevel2: TBevel
    Left = 8
    Top = 176
    Width = 469
    Height = 1
    Style = bsRaised
  end
  object Label9: TLabel
    Left = 280
    Top = 200
    Width = 44
    Height = 13
    Caption = 'Pay type:'
  end
  object Bevel3: TBevel
    Left = 8
    Top = 232
    Width = 469
    Height = 1
    Style = bsRaised
  end
  object Label10: TLabel
    Left = 204
    Top = 256
    Width = 83
    Height = 13
    Caption = 'Purchases count:'
  end
  object cPurchases: TLabel
    Left = 292
    Top = 256
    Width = 105
    Height = 13
    AutoSize = False
  end
  object Label11: TLabel
    Left = 8
    Top = 288
    Width = 61
    Height = 13
    Caption = 'VAT class A:'
  end
  object Label12: TLabel
    Left = 144
    Top = 288
    Width = 61
    Height = 13
    Caption = 'VAT class B:'
  end
  object Label13: TLabel
    Left = 276
    Top = 288
    Width = 61
    Height = 13
    Caption = 'VAT class C:'
  end
  object cVATc: TLabel
    Left = 340
    Top = 288
    Width = 77
    Height = 13
    AutoSize = False
  end
  object cVATb: TLabel
    Left = 208
    Top = 288
    Width = 65
    Height = 13
    AutoSize = False
  end
  object cVATa: TLabel
    Left = 72
    Top = 288
    Width = 69
    Height = 13
    AutoSize = False
  end
  object Bevel4: TBevel
    Left = 8
    Top = 380
    Width = 469
    Height = 1
    Style = bsRaised
  end
  object Label14: TLabel
    Left = 128
    Top = 20
    Width = 28
    Height = 13
    Caption = 'Baud:'
  end
  object ComPorts: TComboBox
    Left = 60
    Top = 16
    Width = 61
    Height = 21
    AutoDropDown = True
    Style = csDropDownList
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 0
    Text = 'COM1'
    Items.Strings = (
      'COM1'
      'COM2'
      'COM3'
      'COM4')
  end
  object FindBtn: TButton
    Left = 232
    Top = 16
    Width = 41
    Height = 21
    Caption = '&Find'
    TabOrder = 1
    OnClick = FindBtnClick
  end
  object cOperator: TEdit
    Left = 68
    Top = 52
    Width = 77
    Height = 21
    MaxLength = 1
    TabOrder = 2
    Text = '1'
  end
  object cPassword: TEdit
    Left = 244
    Top = 52
    Width = 81
    Height = 21
    MaxLength = 4
    TabOrder = 3
    Text = '0000'
  end
  object OpenFiscalReceipt: TButton
    Left = 336
    Top = 52
    Width = 137
    Height = 25
    Caption = 'Open Fiscal Receipt (&1)'
    TabOrder = 4
    OnClick = OpenFiscalReceiptClick
  end
  object cArticle: TEdit
    Left = 80
    Top = 104
    Width = 193
    Height = 21
    MaxLength = 36
    TabOrder = 5
    Text = 'Test article'
  end
  object cTaxGroup: TComboBox
    Left = 332
    Top = 104
    Width = 37
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 6
    Text = #1040
    Items.Strings = (
      #1040
      #1041
      #1042)
  end
  object cPrice: TEdit
    Left = 408
    Top = 104
    Width = 65
    Height = 21
    MaxLength = 12
    TabOrder = 7
    Text = '1.23'
  end
  object cQuantity: TEdit
    Left = 56
    Top = 136
    Width = 77
    Height = 21
    TabOrder = 8
    Text = '4.321'
  end
  object cDiscount: TEdit
    Left = 300
    Top = 136
    Width = 73
    Height = 21
    TabOrder = 9
    Text = '0'
  end
  object cSell: TButton
    Left = 380
    Top = 136
    Width = 93
    Height = 25
    Caption = 'Sell (&2)'
    TabOrder = 10
    OnClick = cSellClick
  end
  object cCalc: TButton
    Left = 8
    Top = 192
    Width = 133
    Height = 25
    Caption = 'Calc intermediate sum (&3)'
    TabOrder = 11
    OnClick = cCalcClick
  end
  object cSum: TEdit
    Left = 148
    Top = 196
    Width = 109
    Height = 21
    TabOrder = 12
  end
  object cPayType: TComboBox
    Left = 328
    Top = 196
    Width = 45
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 13
    Text = '0'
    Items.Strings = (
      '0'
      '1'
      '2'
      '3'
      '4')
  end
  object cPayment: TButton
    Left = 380
    Top = 192
    Width = 91
    Height = 25
    Caption = 'Pay it (&4)'
    TabOrder = 14
    OnClick = cPaymentClick
  end
  object cCurentReceipt: TButton
    Left = 8
    Top = 248
    Width = 165
    Height = 25
    Caption = 'Get current receipt info (&5)'
    TabOrder = 15
    OnClick = cCurentReceiptClick
  end
  object cNoVoid: TCheckBox
    Left = 8
    Top = 320
    Width = 97
    Height = 17
    Caption = 'Void forbiden'
    TabOrder = 16
  end
  object cPayStarted: TCheckBox
    Left = 8
    Top = 348
    Width = 97
    Height = 17
    Caption = 'Payment started'
    TabOrder = 17
  end
  object cPrintVAT: TCheckBox
    Left = 148
    Top = 320
    Width = 125
    Height = 17
    Caption = 'Print VAT in receipt'
    TabOrder = 18
  end
  object cPayFinished: TCheckBox
    Left = 148
    Top = 348
    Width = 125
    Height = 17
    Caption = 'Payment finished'
    TabOrder = 19
  end
  object cDetailed: TCheckBox
    Left = 304
    Top = 320
    Width = 97
    Height = 17
    Caption = 'Detailed receipt'
    TabOrder = 20
  end
  object closeFiscal: TButton
    Left = 340
    Top = 392
    Width = 135
    Height = 25
    Caption = 'Close Fiscal Receipt (&6)'
    TabOrder = 21
    OnClick = closeFiscalClick
  end
  object cBaud: TComboBox
    Left = 156
    Top = 16
    Width = 69
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 22
    Text = '9600'
    Items.Strings = (
      '9600'
      '19200')
  end
end
