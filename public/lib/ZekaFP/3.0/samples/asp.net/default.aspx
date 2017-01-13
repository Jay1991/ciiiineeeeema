<%@ Page language="c#" Codebehind="default.aspx.cs" AutoEventWireup="false" Inherits="zfpaspx.WebForm1" culture="en-US"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>Zeka Fiscal Printer ASP.NET sample</title>
		<meta name="vs_snapToGrid" content="True">
		<meta name="vs_showGrid" content="True">
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<asp:Label id="Label1" style="Z-INDEX: 101; LEFT: 32px; POSITION: absolute; TOP: 16px" runat="server"
				Width="83px" Height="17px">COM port:</asp:Label>
			<asp:CheckBox id="cDetailed" style="Z-INDEX: 143; LEFT: 368px; POSITION: absolute; TOP: 392px"
				runat="server" Height="16px" Text="Detailed receipt"></asp:CheckBox>
			<asp:CheckBox id="cPayFinished" style="Z-INDEX: 142; LEFT: 200px; POSITION: absolute; TOP: 416px"
				runat="server" Height="16px" Text="Payment finished"></asp:CheckBox>
			<asp:CheckBox id="cPrintVAT" style="Z-INDEX: 141; LEFT: 200px; POSITION: absolute; TOP: 392px"
				runat="server" Height="16px" Text="Print VAT in receipt"></asp:CheckBox>
			<asp:CheckBox id="cPayStarted" style="Z-INDEX: 140; LEFT: 32px; POSITION: absolute; TOP: 416px"
				runat="server" Height="16px" Text="Payment started"></asp:CheckBox>
			<asp:Label id="Label15" style="Z-INDEX: 138; LEFT: 368px; POSITION: absolute; TOP: 352px" runat="server"
				Width="88px" Height="24px">VAT class C:</asp:Label>
			<asp:Label id="Label13" style="Z-INDEX: 137; LEFT: 200px; POSITION: absolute; TOP: 352px" runat="server"
				Width="88px" Height="24px">VAT class B:</asp:Label>
			<asp:Label id="cVATc" style="Z-INDEX: 136; LEFT: 456px; POSITION: absolute; TOP: 352px" runat="server"
				Width="64px" Height="24px">0</asp:Label>
			<asp:Label id="Label14" style="Z-INDEX: 133; LEFT: 32px; POSITION: absolute; TOP: 352px" runat="server"
				Width="88px" Height="24px">VAT class A:</asp:Label>
			<asp:Label id="cVATb" style="Z-INDEX: 135; LEFT: 288px; POSITION: absolute; TOP: 352px" runat="server"
				Width="64px" Height="24px">0</asp:Label>
			<asp:DropDownList id="ComPorts" style="Z-INDEX: 102; LEFT: 104px; POSITION: absolute; TOP: 16px" runat="server"
				Width="64px" Height="16px">
				<asp:ListItem Value="1" Selected="True">COM1</asp:ListItem>
				<asp:ListItem Value="2">COM2</asp:ListItem>
				<asp:ListItem Value="3">COM3</asp:ListItem>
				<asp:ListItem Value="4">COM4</asp:ListItem>
			</asp:DropDownList>
			<asp:Button id="FindCom" style="Z-INDEX: 103; LEFT: 320px; POSITION: absolute; TOP: 16px" runat="server"
				Width="49px" Height="24px" Text="Find"></asp:Button>
			<asp:Label id="version" style="Z-INDEX: 104; LEFT: 376px; POSITION: absolute; TOP: 16px" runat="server"
				Width="208px" Height="32px"></asp:Label>
			<asp:Label id="Label2" style="Z-INDEX: 105; LEFT: 32px; POSITION: absolute; TOP: 56px" runat="server"
				Width="56px" Height="16px">Operator:</asp:Label>
			<asp:TextBox id="cOperator" style="Z-INDEX: 106; LEFT: 104px; POSITION: absolute; TOP: 56px"
				runat="server" Width="72px" Height="24px" MaxLength="1">1</asp:TextBox>
			<asp:Label id="Label3" style="Z-INDEX: 107; LEFT: 200px; POSITION: absolute; TOP: 56px" runat="server"
				Width="64px" Height="24px">Password:</asp:Label>
			<asp:TextBox id="cPassword" style="Z-INDEX: 108; LEFT: 272px; POSITION: absolute; TOP: 56px"
				runat="server" Width="80px" MaxLength="4">0000</asp:TextBox>
			<asp:Button id="OpenFiscalBon" style="Z-INDEX: 109; LEFT: 360px; POSITION: absolute; TOP: 56px"
				runat="server" Width="200px" Height="24px" Text="Open Fiscal Receipt"></asp:Button>
			<HR style="Z-INDEX: 110; LEFT: 32px; WIDTH: 83.88%; POSITION: absolute; TOP: 96px; HEIGHT: 1px"
				width="83.88%" SIZE="1">
			<asp:Label id="Label4" style="Z-INDEX: 111; LEFT: 32px; POSITION: absolute; TOP: 120px" runat="server"
				Width="80px" Height="24px">Article name:</asp:Label>
			<asp:TextBox id="cName" style="Z-INDEX: 112; LEFT: 120px; POSITION: absolute; TOP: 120px" runat="server"
				Width="192px" Height="26px" MaxLength="36">Test article</asp:TextBox>
			<asp:Label id="Label5" style="Z-INDEX: 113; LEFT: 328px; POSITION: absolute; TOP: 120px" runat="server"
				Width="72px" Height="16px">Tax group:</asp:Label>
			<asp:DropDownList id="cTaxGroup" style="Z-INDEX: 114; LEFT: 408px; POSITION: absolute; TOP: 120px"
				runat="server" Width="41px" Height="24px">
				<asp:ListItem Value="À" Selected="True">À</asp:ListItem>
				<asp:ListItem Value="Á">Á</asp:ListItem>
				<asp:ListItem Value="Â">Â</asp:ListItem>
			</asp:DropDownList>
			<asp:Label id="Label6" style="Z-INDEX: 115; LEFT: 464px; POSITION: absolute; TOP: 120px" runat="server"
				Width="32px" Height="24px">Price:</asp:Label>
			<asp:TextBox id="cPrice" style="Z-INDEX: 116; LEFT: 504px; POSITION: absolute; TOP: 120px" runat="server"
				Width="56px">1.23</asp:TextBox>
			<asp:Label id="Label7" style="Z-INDEX: 117; LEFT: 32px; POSITION: absolute; TOP: 160px" runat="server"
				Width="56px" Height="8px">Quantity:</asp:Label>
			<asp:TextBox id="cQuantity" style="Z-INDEX: 118; LEFT: 96px; POSITION: absolute; TOP: 160px"
				runat="server" Width="89px">4.321</asp:TextBox>
			<asp:Label id="Label8" style="Z-INDEX: 119; LEFT: 200px; POSITION: absolute; TOP: 160px" runat="server"
				Width="120px" Height="16px">Addition / Discount:</asp:Label>
			<asp:TextBox id="cDiscount" style="Z-INDEX: 120; LEFT: 328px; POSITION: absolute; TOP: 160px"
				runat="server" Width="73px">0</asp:TextBox>
			<asp:Button id="Sell" style="Z-INDEX: 121; LEFT: 416px; POSITION: absolute; TOP: 160px" runat="server"
				Width="144px" Text="Sell"></asp:Button>
			<asp:Label id="error" style="Z-INDEX: 122; LEFT: 32px; POSITION: absolute; TOP: 472px" runat="server"
				Width="352px" Height="24px" ForeColor="Red"></asp:Label>
			<HR style="Z-INDEX: 123; LEFT: 32px; WIDTH: 83.88%; POSITION: absolute; TOP: 208px; HEIGHT: 1px"
				width="83.88%" SIZE="1">
			<asp:Button id="CalcSum" style="Z-INDEX: 124; LEFT: 32px; POSITION: absolute; TOP: 232px" runat="server"
				Width="152px" Text="Calc intermediate sum"></asp:Button>
			<asp:TextBox id="cSum" style="Z-INDEX: 125; LEFT: 192px; POSITION: absolute; TOP: 232px" runat="server"
				Width="152px"></asp:TextBox>
			<asp:Label id="Label9" style="Z-INDEX: 126; LEFT: 360px; POSITION: absolute; TOP: 232px" runat="server"
				Width="56px" Height="16px">Pay type:</asp:Label>
			<asp:DropDownList id="cPayType" style="Z-INDEX: 127; LEFT: 424px; POSITION: absolute; TOP: 232px"
				runat="server" Width="40px" Height="24px">
				<asp:ListItem Value="0" Selected="True">0</asp:ListItem>
				<asp:ListItem Value="1">1</asp:ListItem>
				<asp:ListItem Value="2">2</asp:ListItem>
				<asp:ListItem Value="3">3</asp:ListItem>
				<asp:ListItem Value="4">4</asp:ListItem>
			</asp:DropDownList>
			<asp:Button id="Pay" style="Z-INDEX: 128; LEFT: 472px; POSITION: absolute; TOP: 232px" runat="server"
				Width="88px" Text="Pay it"></asp:Button>
			<HR style="Z-INDEX: 129; LEFT: 32px; WIDTH: 83.88%; POSITION: absolute; TOP: 280px; HEIGHT: 1px"
				width="83.88%" SIZE="1">
			<asp:Button id="bonInfo" style="Z-INDEX: 130; LEFT: 32px; POSITION: absolute; TOP: 304px" runat="server"
				Width="160px" Text="Get current receipt info"></asp:Button>
			<asp:Label id="Label10" style="Z-INDEX: 131; LEFT: 224px; POSITION: absolute; TOP: 304px" runat="server"
				Width="104px" Height="24px">Purchases count:</asp:Label>
			<asp:Label id="cPurchases" style="Z-INDEX: 132; LEFT: 336px; POSITION: absolute; TOP: 304px"
				runat="server" Width="72px" Height="24px">0</asp:Label>
			<asp:Label id="cVATa" style="Z-INDEX: 134; LEFT: 120px; POSITION: absolute; TOP: 352px" runat="server"
				Width="64px" Height="24px">0</asp:Label>
			<asp:CheckBox id="cNoVoid" style="Z-INDEX: 139; LEFT: 32px; POSITION: absolute; TOP: 392px" runat="server"
				Height="16px" Text="Void forbiden"></asp:CheckBox>
			<HR style="Z-INDEX: 144; LEFT: 32px; WIDTH: 83.88%; POSITION: absolute; TOP: 456px; HEIGHT: 1px"
				width="83.88%" SIZE="1">
			<asp:Button id="closeFiscal" style="Z-INDEX: 145; LEFT: 408px; POSITION: absolute; TOP: 472px"
				runat="server" Width="153px" Text="Close Fiscal Receipt"></asp:Button>
			<asp:Label id="Label11" style="Z-INDEX: 146; LEFT: 176px; POSITION: absolute; TOP: 16px" runat="server"
				Height="16px" Width="40px">Baud:</asp:Label>
			<asp:DropDownList id="cBaud" style="Z-INDEX: 147; LEFT: 216px; POSITION: absolute; TOP: 16px" runat="server"
				Height="24px" Width="96px">
				<asp:ListItem Value="9600" Selected="True">9600</asp:ListItem>
				<asp:ListItem Value="19200">19200</asp:ListItem>
				<asp:ListItem Value="38400">38400</asp:ListItem>
				<asp:ListItem Value="57600">57600</asp:ListItem>
				<asp:ListItem Value="115200">115200</asp:ListItem>
			</asp:DropDownList>
		</form>
	</body>
</HTML>
