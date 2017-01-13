//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005,2008 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// This is a sample program for zfplib COM library (Zeka FP)
//////////////////////////////////////////////////////////////////////

using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;
using ZFPCOMLib;

namespace zfpaspx
{
	/// <summary>
	/// Summary description for WebForm1.
	/// </summary>
	public class WebForm1 : System.Web.UI.Page
	{
		private ZekaFPClass zfp;

		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Button FindCom;
		protected System.Web.UI.WebControls.DropDownList ComPorts;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.TextBox cOperator;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.TextBox cPassword;
		protected System.Web.UI.WebControls.Button OpenFiscalBon;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.TextBox cName;
		protected System.Web.UI.WebControls.Label Label5;
		protected System.Web.UI.WebControls.DropDownList cTaxGroup;
		protected System.Web.UI.WebControls.Label Label6;
		protected System.Web.UI.WebControls.TextBox cPrice;
		protected System.Web.UI.WebControls.Label Label7;
		protected System.Web.UI.WebControls.TextBox cQuantity;
		protected System.Web.UI.WebControls.Label Label8;
		protected System.Web.UI.WebControls.TextBox cDiscount;
		protected System.Web.UI.WebControls.Button Sell;
		protected System.Web.UI.WebControls.Label error;
		protected System.Web.UI.WebControls.Button CalcSum;
		protected System.Web.UI.WebControls.TextBox cSum;
		protected System.Web.UI.WebControls.Label Label9;
		protected System.Web.UI.WebControls.DropDownList cPayType;
		protected System.Web.UI.WebControls.Button Pay;
		protected System.Web.UI.WebControls.Button bonInfo;
		protected System.Web.UI.WebControls.Label Label10;
		protected System.Web.UI.WebControls.Label cPurchases;
		protected System.Web.UI.WebControls.Label cVATa;
		protected System.Web.UI.WebControls.Label cVATb;
		protected System.Web.UI.WebControls.Label Label14;
		protected System.Web.UI.WebControls.Label cVATc;
		protected System.Web.UI.WebControls.Label Label13;
		protected System.Web.UI.WebControls.Label Label15;
		protected System.Web.UI.WebControls.CheckBox cNoVoid;
		protected System.Web.UI.WebControls.CheckBox cPayStarted;
		protected System.Web.UI.WebControls.CheckBox cPrintVAT;
		protected System.Web.UI.WebControls.CheckBox cPayFinished;
		protected System.Web.UI.WebControls.CheckBox cDetailed;
		protected System.Web.UI.WebControls.Button closeFiscal;
		protected System.Web.UI.WebControls.Label Label11;
		protected System.Web.UI.WebControls.DropDownList cBaud;
		protected System.Web.UI.WebControls.Label version;

        private uint IndexToBaud(int index)
        {
            uint[] b = new uint[] { 9600, 19200, 38400, 57600, 115200 };

            if (index < 0 || index >= b.Length) return 0;

            return b[index];
        }

        private int BaudToIndex(uint baud)
        {
            switch (baud)
            {
                case 9600:
                    return 0;

                case 19200:
                    return 1;

                case 38400:
                    return 2;

                case 57600:
                    return 3;

                case 115200:
                    return 4;
            }
            return 0;
        }

		private void Page_Load(object sender, System.EventArgs e)
		{
			// Put user code to initialize the page here
			zfp = new ZekaFPClass();
		}

		#region Web Form Designer generated code
		override protected void OnInit(EventArgs e)
		{
			//
			// CODEGEN: This call is required by the ASP.NET Web Form Designer.
			//
			InitializeComponent();
			base.OnInit(e);
		}
		
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{    
			this.FindCom.Click += new System.EventHandler(this.FindCom_Click);
			this.OpenFiscalBon.Click += new System.EventHandler(this.OpenFiscalBon_Click);
			this.Sell.Click += new System.EventHandler(this.Sell_Click);
			this.CalcSum.Click += new System.EventHandler(this.CalcSum_Click);
			this.Pay.Click += new System.EventHandler(this.Pay_Click);
			this.bonInfo.Click += new System.EventHandler(this.bonInfo_Click);
			this.closeFiscal.Click += new System.EventHandler(this.closeFiscal_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void FindCom_Click(object sender, System.EventArgs e)
		{
			error.Text = "";
			uint com = zfp.FindFirstFPCOMEx();

			if (com != 0) 
			{
				ComPorts.SelectedIndex = (int)(com >> 24) - 1;
				uint baud = com & 0x00FFFFFF;
                cBaud.SelectedIndex = BaudToIndex(baud);
                zfp.Setup((ushort)(com >> 24), baud, 3, 1000);
				version.Text = zfp.GetVersion();
			}
		}

		private void OpenFiscalBon_Click(object sender, System.EventArgs e)
		{
			error.Text = "";
            zfp.Setup(Convert.ToUInt16(ComPorts.SelectedIndex + 1), IndexToBaud(cBaud.SelectedIndex), 3, 1000);
			byte oper = byte.Parse(cOperator.Text);
			zfp.OpenFiscalBon(oper, cPassword.Text, 0, 1);
			if (0 != zfp.errorCode) 
				error.Text = zfp.GetErrorString(zfp.errorCode, 0);
		}

		private void Sell_Click(object sender, System.EventArgs e)
		{
			error.Text = "";
            zfp.Setup(Convert.ToUInt16(ComPorts.SelectedIndex + 1), IndexToBaud(cBaud.SelectedIndex), 3, 1000);
			zfp.SellFree(cName.Text, Convert.ToByte(cTaxGroup.SelectedIndex), 
				Single.Parse(cPrice.Text), 
				Single.Parse(cQuantity.Text), 
				Single.Parse(cDiscount.Text));
			if (0 != zfp.errorCode) 
				error.Text = zfp.GetErrorString(zfp.errorCode, 0);
		}

		private void CalcSum_Click(object sender, System.EventArgs e)
		{
			error.Text = "";
            zfp.Setup(Convert.ToUInt16(ComPorts.SelectedIndex + 1), IndexToBaud(cBaud.SelectedIndex), 3, 1000);
			double sum = zfp.CalcIntermediateSum(1, 1, 0, 0);
			if (0 != zfp.errorCode)
				error.Text = zfp.GetErrorString(zfp.errorCode, 0);
			else 
				cSum.Text = sum.ToString();
		}

		private void Pay_Click(object sender, System.EventArgs e)
		{
			error.Text = "";
            zfp.Setup(Convert.ToUInt16(ComPorts.SelectedIndex + 1), IndexToBaud(cBaud.SelectedIndex), 3, 1000);
			zfp.Payment(Single.Parse(cSum.Text), Convert.ToByte(cPayType.SelectedIndex), 0);
			if (0 != zfp.errorCode) 
				error.Text = zfp.GetErrorString(zfp.errorCode, 0);
		}

		private void bonInfo_Click(object sender, System.EventArgs e)
		{
			error.Text = "";
            zfp.Setup(Convert.ToUInt16(ComPorts.SelectedIndex + 1), IndexToBaud(cBaud.SelectedIndex), 3, 1000);
			ZFPCOMLib.GetCurrentBonInfoRes info = (ZFPCOMLib.GetCurrentBonInfoRes)zfp.GetCurrentBonInfo();
			if (0 != zfp.errorCode) {
				error.Text = zfp.GetErrorString(zfp.errorCode, 0);
			}
			else {
				cPurchases.Text = info.purchases.ToString();
				cVATa.Text = info.taxgrp1.ToString();
				cVATb.Text = info.taxgrp2.ToString();
				cVATc.Text = info.taxgrp3.ToString();

				cNoVoid.Checked = info.novoid != 0 ? true : false;
				cPrintVAT.Checked = info.dds != 0 ? true : false;
				cDetailed.Checked = info.detailed != 0 ? true : false;
				cPayStarted.Checked = info.paystarted != 0 ? true : false;
				cPayFinished.Checked = info.paid != 0 ? true : false;
			}
		}

		private void closeFiscal_Click(object sender, System.EventArgs e)
		{
			error.Text = "";
            zfp.Setup(Convert.ToUInt16(ComPorts.SelectedIndex + 1), IndexToBaud(cBaud.SelectedIndex), 3, 1000);
			zfp.CloseFiscalBon();
			if (0 != zfp.errorCode) 
				error.Text = zfp.GetErrorString(zfp.errorCode, 0);
		}
	}
}
