VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Zeka Fiscal Printer sample"
   ClientHeight    =   6630
   ClientLeft      =   1755
   ClientTop       =   2025
   ClientWidth     =   6600
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   6630
   ScaleWidth      =   6600
   Begin VB.CommandButton CloseInCash 
      Caption         =   "Pay and Close (&7)"
      Height          =   435
      Left            =   120
      TabIndex        =   42
      Top             =   6000
      Width           =   2115
   End
   Begin VB.ComboBox combaud 
      Height          =   315
      ItemData        =   "MainForm.frx":0000
      Left            =   2520
      List            =   "MainForm.frx":000A
      Style           =   2  'Dropdown List
      TabIndex        =   41
      Top             =   180
      Width           =   855
   End
   Begin VB.CommandButton FindCom 
      Caption         =   "Find"
      Height          =   375
      Left            =   3480
      TabIndex        =   38
      Top             =   180
      Width           =   555
   End
   Begin VB.CheckBox paid 
      Caption         =   "Payment finished"
      Height          =   315
      Left            =   2280
      TabIndex        =   34
      Top             =   5220
      Width           =   1695
   End
   Begin VB.CheckBox paystarted 
      Caption         =   "Payment started"
      Height          =   315
      Left            =   180
      TabIndex        =   33
      Top             =   5220
      Width           =   1515
   End
   Begin VB.CheckBox detailed 
      Caption         =   "Detailed reciept"
      Height          =   315
      Left            =   4920
      TabIndex        =   32
      Top             =   4740
      Width           =   1515
   End
   Begin VB.CheckBox dds 
      Caption         =   "Print VAT in reciept"
      Height          =   315
      Left            =   2280
      TabIndex        =   31
      Top             =   4740
      Width           =   1755
   End
   Begin VB.CheckBox novoid 
      Caption         =   "Void forbiden"
      Height          =   315
      Left            =   180
      TabIndex        =   30
      Top             =   4740
      Width           =   1275
   End
   Begin VB.CommandButton GetCurrentBonInfo 
      Caption         =   "Get current receipt info (&5)"
      Height          =   375
      Left            =   180
      TabIndex        =   24
      Top             =   3660
      Width           =   2235
   End
   Begin VB.ComboBox paytype 
      Height          =   315
      ItemData        =   "MainForm.frx":001B
      Left            =   4320
      List            =   "MainForm.frx":002E
      Style           =   2  'Dropdown List
      TabIndex        =   23
      Top             =   2760
      Width           =   1035
   End
   Begin VB.CommandButton payment 
      Caption         =   "Pay it (&4)"
      Height          =   375
      Left            =   5520
      TabIndex        =   21
      Top             =   2760
      Width           =   855
   End
   Begin VB.TextBox sum 
      Height          =   375
      Left            =   2340
      TabIndex        =   20
      Top             =   2760
      Width           =   1215
   End
   Begin VB.CommandButton calcintermed 
      Caption         =   "Calc Intermediate Sum (&3)"
      Height          =   375
      Left            =   180
      TabIndex        =   19
      Top             =   2760
      Width           =   2055
   End
   Begin VB.CommandButton sell 
      Caption         =   "Sell (&2)"
      Height          =   375
      Left            =   5340
      TabIndex        =   18
      Top             =   1920
      Width           =   1035
   End
   Begin VB.TextBox discount 
      Height          =   315
      Left            =   4560
      TabIndex        =   17
      Text            =   "0"
      Top             =   1920
      Width           =   555
   End
   Begin VB.TextBox quantity 
      Height          =   315
      Left            =   2640
      TabIndex        =   15
      Text            =   "4.321"
      Top             =   1920
      Width           =   975
   End
   Begin VB.TextBox price 
      Height          =   315
      Left            =   780
      TabIndex        =   13
      Text            =   "1.23"
      Top             =   1920
      Width           =   915
   End
   Begin VB.ComboBox taxgrp 
      Height          =   315
      ItemData        =   "MainForm.frx":0041
      Left            =   5400
      List            =   "MainForm.frx":004E
      Style           =   2  'Dropdown List
      TabIndex        =   11
      Top             =   1440
      Width           =   975
   End
   Begin VB.TextBox article 
      Height          =   315
      Left            =   1200
      TabIndex        =   9
      Text            =   "Test article"
      Top             =   1440
      Width           =   3015
   End
   Begin VB.CommandButton CloseFiscalBon 
      Caption         =   "Close Fiscal Receipt (&6)"
      Height          =   435
      Left            =   4260
      TabIndex        =   7
      Top             =   6000
      Width           =   2115
   End
   Begin VB.TextBox password 
      Height          =   315
      Left            =   2940
      TabIndex        =   6
      Text            =   "0000"
      Top             =   660
      Width           =   975
   End
   Begin VB.TextBox Operator 
      Height          =   315
      Left            =   960
      TabIndex        =   4
      Text            =   "1"
      Top             =   660
      Width           =   975
   End
   Begin VB.ComboBox comport 
      Height          =   315
      ItemData        =   "MainForm.frx":005B
      Left            =   960
      List            =   "MainForm.frx":007A
      Style           =   2  'Dropdown List
      TabIndex        =   2
      Top             =   180
      Width           =   975
   End
   Begin VB.CommandButton openfiscalbon 
      Caption         =   "Open fiscal receipt (&1)"
      Height          =   435
      Left            =   4140
      TabIndex        =   0
      Top             =   600
      Width           =   2235
   End
   Begin VB.Label Label10 
      Caption         =   "Baud:"
      Height          =   255
      Left            =   2040
      TabIndex        =   40
      Top             =   240
      Width           =   495
   End
   Begin VB.Label version 
      Height          =   255
      Left            =   4080
      TabIndex        =   39
      Top             =   240
      Width           =   2475
   End
   Begin VB.Line Line4 
      X1              =   180
      X2              =   6360
      Y1              =   5820
      Y2              =   5820
   End
   Begin VB.Label taxgr3 
      Height          =   315
      Left            =   5580
      TabIndex        =   37
      Top             =   4200
      Width           =   855
   End
   Begin VB.Label taxgr2 
      Height          =   315
      Left            =   3420
      TabIndex        =   36
      Top             =   4200
      Width           =   975
   End
   Begin VB.Label taxgr1 
      Height          =   315
      Left            =   1200
      TabIndex        =   35
      Top             =   4200
      Width           =   975
   End
   Begin VB.Label purchases 
      Height          =   315
      Left            =   3960
      TabIndex        =   29
      Top             =   3720
      Width           =   975
   End
   Begin VB.Label Label14 
      Caption         =   "Purchases count:"
      Height          =   255
      Left            =   2700
      TabIndex        =   28
      Top             =   3720
      Width           =   1275
   End
   Begin VB.Label Label13 
      Caption         =   "VAT class C:"
      Height          =   255
      Index           =   1
      Left            =   4500
      TabIndex        =   27
      Top             =   4200
      Width           =   975
   End
   Begin VB.Label Label12 
      Caption         =   "VAT class B:"
      Height          =   255
      Index           =   1
      Left            =   2340
      TabIndex        =   26
      Top             =   4200
      Width           =   975
   End
   Begin VB.Label Label11 
      Caption         =   "VAT class A:"
      Height          =   255
      Index           =   0
      Left            =   180
      TabIndex        =   25
      Top             =   4200
      Width           =   975
   End
   Begin VB.Line Line3 
      X1              =   180
      X2              =   6360
      Y1              =   3420
      Y2              =   3420
   End
   Begin VB.Label Label9 
      Caption         =   "Type:"
      Height          =   255
      Left            =   3720
      TabIndex        =   22
      Top             =   2820
      Width           =   495
   End
   Begin VB.Line Line2 
      X1              =   180
      X2              =   6360
      Y1              =   2520
      Y2              =   2520
   End
   Begin VB.Label Label8 
      Caption         =   "Discount:"
      Height          =   195
      Left            =   3780
      TabIndex        =   16
      Top             =   1980
      Width           =   675
   End
   Begin VB.Label Label7 
      Caption         =   "Quantity:"
      Height          =   255
      Left            =   1860
      TabIndex        =   14
      Top             =   1980
      Width           =   675
   End
   Begin VB.Label Label6 
      Caption         =   "Price:"
      Height          =   255
      Left            =   180
      TabIndex        =   12
      Top             =   1980
      Width           =   495
   End
   Begin VB.Label Label5 
      Caption         =   "Tax group:"
      Height          =   255
      Left            =   4440
      TabIndex        =   10
      Top             =   1500
      Width           =   855
   End
   Begin VB.Label Label4 
      Caption         =   "Article name:"
      Height          =   255
      Left            =   180
      TabIndex        =   8
      Top             =   1500
      Width           =   975
   End
   Begin VB.Line Line1 
      X1              =   120
      X2              =   6420
      Y1              =   1260
      Y2              =   1260
   End
   Begin VB.Label Label3 
      Caption         =   "Password:"
      Height          =   255
      Left            =   2100
      TabIndex        =   5
      Top             =   720
      Width           =   795
   End
   Begin VB.Label Label2 
      Caption         =   "Operator:"
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   720
      Width           =   735
   End
   Begin VB.Label Label1 
      Caption         =   "COM port:"
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   240
      Width           =   735
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub calcintermed_Click()
    mp = Screen.MousePointer
    Screen.MousePointer = vbHourglass
    
    Set zfp = CreateObject("Zfpcom.ZekaFP")
    baud = 9600
    If combaud.ListIndex Then
        baud = 19200
    End If
    res = zfp.Setup(comport.ListIndex + 1, baud, 3, 1000)
    res = zfp.CalcIntermediateSum(1, 1, 0, 0)
    If zfp.errorCode Then
        MsgBox "Error durring operation: " + zfp.GetErrorString(zfp.errorCode, 0), 16, "Error"
        sum.Text = ""
    Else
        sum.Text = CStr(res)
    End If
    
    Screen.MousePointer = mp
End Sub

Private Sub CloseFiscalBon_Click()
    mp = Screen.MousePointer
    Screen.MousePointer = vbHourglass
    
    Set zfp = CreateObject("Zfpcom.ZekaFP")
    baud = 9600
    If combaud.ListIndex Then
        baud = 19200
    End If
    res = zfp.Setup(comport.ListIndex + 1, baud, 3, 1000)
    res = zfp.CloseFiscalBon()
    If zfp.errorCode Then
        MsgBox "Error durring operation: " + zfp.GetErrorString(zfp.errorCode, 0), 16, "Error"
    End If

    Screen.MousePointer = mp
End Sub

Private Sub CloseInCash_Click()
    mp = Screen.MousePointer
    Screen.MousePointer = vbHourglass
    
    Set zfp = CreateObject("Zfpcom.ZekaFP")
    baud = 9600
    If combaud.ListIndex Then
        baud = 19200
    End If
    res = zfp.Setup(comport.ListIndex + 1, baud, 3, 1000)
    res = zfp.CloseBonInCash()
    If zfp.errorCode Then
        MsgBox "Error durring operation: " + zfp.GetErrorString(zfp.errorCode, 0), 16, "Error"
    End If

    Screen.MousePointer = mp
End Sub

Private Sub FindCom_Click()
    mp = Screen.MousePointer
    Screen.MousePointer = vbHourglass
    
    Set zfp = CreateObject("Zfpcom.ZekaFP")
    com = zfp.FindFirstFPCOM()
    If (com) Then
        test = CLng(com) And CLng(65535)
        comport.ListIndex = CInt(CLng(com) And CLng(65535)) - 1
        baud = (CLng(com) And CLng(2147418112)) / 65536
        If baud = 19200 Then
            combaud.ListIndex = 1
        Else
            combaud.ListIndex = 0
        End If
        res = zfp.Setup(comport.ListIndex + 1, baud, 3, 1000)
        ver = zfp.GetVersion()
        If Not zfp.errorCode Then
            version.Caption = ver
        End If
    End If

    Screen.MousePointer = mp
End Sub

Private Sub GetCurrentBonInfo_Click()
    mp = Screen.MousePointer
    Screen.MousePointer = vbHourglass
    
    Set zfp = CreateObject("Zfpcom.ZekaFP")
    baud = 9600
    If combaud.ListIndex Then
        baud = 19200
    End If
    res = zfp.Setup(comport.ListIndex + 1, baud, 3, 1000)
    Set res = zfp.GetCurrentBonInfo()
    If zfp.errorCode Then
        MsgBox "Error durring operation: " + zfp.GetErrorString(zfp.errorCode, 0), 16, "Error"
        sum.Text = ""
    Else
        purchases.Caption = res.purchases
        taxgr1.Caption = CStr(res.taxgrp1)
        taxgr2.Caption = CStr(res.taxgrp2)
        taxgr3.Caption = CStr(res.taxgrp3)
        novoid.Value = res.novoid
        dds.Value = res.dds
        detailed.Value = res.detailed
        paystarted.Value = res.paystarted
        paid.Value = res.paid
    End If

    Screen.MousePointer = mp
End Sub

Private Sub openfiscalbon_Click()
    mp = Screen.MousePointer
    Screen.MousePointer = vbHourglass
    
    Set zfp = CreateObject("Zfpcom.ZekaFP")
    baud = 9600
    If combaud.ListIndex Then
        baud = 19200
    End If
    res = zfp.Setup(comport.ListIndex + 1, baud, 3, 1000)
    res = zfp.OpenReceipt(CInt(Operator.Text), password.Text, 0, 1, "Company Name", "HQ", "1234567890", "Address", "City, Postcode", "9876543210", 0#, 0#)
    If zfp.errorCode Then
        MsgBox "Error durring operation: " + zfp.GetErrorString(zfp.errorCode, 0), 16, "Error"
    End If

    Screen.MousePointer = mp
End Sub

Private Sub payment_Click()
    mp = Screen.MousePointer
    Screen.MousePointer = vbHourglass
    
    Set zfp = CreateObject("Zfpcom.ZekaFP")
    baud = 9600
    If combaud.ListIndex Then
        baud = 19200
    End If
    res = zfp.Setup(comport.ListIndex + 1, baud, 3, 1000)
    
    If sum.Text = "" Then
        MsgBox "Please enter a price to pay", 16, "Error"
        sum.SetFocus
    Else
        res = zfp.payment(CDbl(sum.Text), paytype.ListIndex, 0)
        If zfp.errorCode Then
            MsgBox "Error durring operation: " + zfp.GetErrorString(zfp.errorCode, 0), 16, "Error"
        End If
    End If

    Screen.MousePointer = mp
End Sub

Private Sub sell_Click()
    mp = Screen.MousePointer
    Screen.MousePointer = vbHourglass
    
    Set zfp = CreateObject("Zfpcom.ZekaFP")
    baud = 9600
    If combaud.ListIndex Then
        baud = 19200
    End If
    res = zfp.Setup(comport.ListIndex + 1, baud, 3, 1000)
    res = zfp.SellFree(article.Text, taxgrp.ListIndex, CDbl(price.Text), CDbl(quantity.Text), CDbl(discount.Text))
    If zfp.errorCode Then
        MsgBox "Error durring operation: " + zfp.GetErrorString(zfp.errorCode, 0), 16, "Error"
    End If

    Screen.MousePointer = mp
End Sub

Private Sub Form_Load()
    comport.ListIndex = 0
    taxgrp.ListIndex = 0
    paytype.ListIndex = 0
    combaud.ListIndex = 0
End Sub
