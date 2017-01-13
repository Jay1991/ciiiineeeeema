<?php
use Mike42\Escpos\PrintConnectors\WindowsPrintConnector;
use Mike42\Escpos\PrintConnectors\FilePrintConnector;
use Mike42\Escpos\Printer;
use Mike42\Escpos\PrintConnectors\NetworkPrintConnector;
use Mike42\Escpos\EscposImage;
// use itemClass;
// use Carbon;
class Printers {

    public static function printer($setting, $items,$vatAmount,$discountAmount,$total,$number, $subTotal)
    {
    	$connector             = '';
		$printer               = '';
    	  try
        {

        /* Open the printer; this will change depending on how it is connected */
//        $connector             = new FilePrintConnector("/dev/usb/lp0");
        $connector             = new WindowsPrintConnector("smb://DESKTOP-QMGQ05S/EPSON TM-T20II Receipt");

        // $connector             = new WindowsPrintConnector("smb://POS5-PC/EPSON TM-T20II Receipt5");
		$printer               = new Printer($connector);




		// /* Information for the receipt */
		// $items = array(
		//     new itemClass("Example item #1", "4.00"),
		//     new itemClass("Another thing", "3.50"),
		//     new itemClass("Something else", "1.00"),
		//     new itemClass("A final item", "4.45"),
		// );

		$subtotal = new itemClass('| SUBTOT.A', str_replace(',' , ' ', number_format($subTotal,1)) . ' |' );
		$net = new itemClass('| NET A', str_replace(',' , ' ', number_format($total,1))   . ' |');
		$FEDHA = new itemClass('FEDHA', str_replace(',' , ' ', number_format($subTotal,1)) );
		$vat = new itemClass('| VAT A', str_replace(',' , ' ', number_format($vatAmount,1))  . ' |');
		$KODI = new itemClass('KODI ILIYOTOZWA A-18.00%', str_replace(',' , ' ', number_format($subTotal,1)) );
		$VATA = new itemClass('VAT A-18.00%', str_replace(',' , ' ', number_format($vatAmount,1))  );
		$JUMLAVAT = new itemClass('JUMLA VAT', str_replace(',' , ' ', number_format($vatAmount,1)) , true);
        $SN = strtoupper(str_random(6));
		$SERIALNUMBER = new itemClass('SERIAL NUMBER', $SN);
		$NUMBERYAEJILIYOWEZESHWA = new itemClass('NAMBA YA EJ ILIYOWEZESHWA', sprintf('%.1f', '1515'));
		$TAREHEYAEJKUWEZESHA = new itemClass('TAREHE YA EJ KUWEZESHWA', sprintf('%.1f', '21-03-2016'));
        
		$tax = new itemClass('A local tax', str_replace(',' , ' ', number_format($vatAmount,1)) );
		$discount = new itemClass('Discount Amount', sprintf('%.1f', $discountAmount));
		// $total = new itemClass('Total', $total, true);
		$JUMLA = new itemClass('JUMLA', $setting->currency_symbol . ' ' . str_replace(',' , ' ', number_format($subTotal,1)) , true);
		/* Date is kept the same for testing */
		// $date = date('l jS \of F Y h:i:s A');
		$date = Carbon::now();
		$TAREHE = new itemClass('TAREHE  ' . date('d-m-Y'), date('H:i'));
		/* Start the printer */
		 if ($setting->logo                       != '')
		{
		// $logo = EscposImage::load(base_path() . '/public/images/' . 
		// 	$setting->logo, false);
		// $printer = new Printer($connector);

		/* Print top logo */
		// $printer -> setJustification(Printer::JUSTIFY_CENTER);
		// $printer -> graphics($logo);

 	    } 

		/* Name of shop */
		$printer -> setJustification(Printer::JUSTIFY_CENTER);
		$printer -> text('*** MWANZO WA RISITI HALALI ***' . "\n");
		$printer -> feed(2);
		$printer -> text($setting->app_name . "\n");
		$printer -> text($setting->postal_address . "\n");
		$printer -> text('DAR ES SALAAM' . "\n");
		$printer -> text('TANZANIA' . "\n");
		$printer -> selectPrintMode(Printer::MODE_DOUBLE_WIDTH);
		$tin = new itemClass('TIN', $setting->tin,true);
		$printer -> text($tin);
		$printer -> selectPrintMode();
		$vrn = new itemClass('VRN', $setting->vrn);
		$printer -> text($vrn);
		$uin = new itemClass('UIN', $setting->uin);
		$printer -> text($uin);
		$printer -> feed(1);
		$printer -> selectPrintMode();
		$printer -> text("TEMEKE\n");
		$printer -> feed();

		$rNumber = new itemClass('NAMBA YA RISITI',$number);
		$printer ->text($rNumber);
		$zno = new itemClass('ZNo',$setting->zno);
		$printer ->text($zno);
		$fp = new itemClass('FP:01', 01);
		$printer ->text($fp);
		$printer -> text('------------------------------------------------' . "\n");


		// $printer -> text("NAMBA YA RISITI" . $number . "\n");
		// $printer -> feed();

		/* Title of receipt */
		// $printer -> setEmphasis(true);
		// $printer -> text("SALES INVOICE\n");
		// $printer -> setEmphasis(false);

		/* Items */
		$printer -> setJustification(Printer::JUSTIFY_LEFT);
		// $printer -> setEmphasis(true);
		// $printer -> text(new itemClass('', '$'));
		// $printer -> setEmphasis(false);
		$LENGTH = 0;
		foreach ($items as $item) {
		    $printer -> text($item);
		    $LENGTH +=  1;
		}

		$NAMBAYABIDHAA = new itemClass('NAMBA YA BIDHAA', $LENGTH);

		// $printer -> setEmphasis(true);
		$printer -> text('------------------------------------------------' . "\n");
		$printer -> text($subtotal);
		$printer -> text($net);
		$printer -> text($vat);
		// $printer -> setEmphasis(false);
		$printer -> feed();
		$printer -> text('------------------------------------------------' . "\n");

		$printer -> selectPrintMode(Printer::MODE_DOUBLE_WIDTH);
		$printer -> text($JUMLA);
		$printer -> selectPrintMode();

		$printer -> text('------------------------------------------------' . "\n");
        $printer -> text($KODI);
        $printer -> text($VATA);
		$printer -> text('------------------------------------------------' . "\n");
        $printer -> selectPrintMode(Printer::MODE_DOUBLE_WIDTH);
		$printer -> text($JUMLAVAT);
		$printer -> selectPrintMode();
		$printer -> text('------------------------------------------------' . "\n");
		$printer -> text($FEDHA);
		$printer -> text($NAMBAYABIDHAA);
		$printer -> text($TAREHE);
		$printer -> text($SERIALNUMBER);
		$printer -> text($NUMBERYAEJILIYOWEZESHWA);
		$printer -> text($TAREHEYAEJKUWEZESHA);

		$printer -> feed(1);

		$printer -> setJustification(Printer::JUSTIFY_CENTER);
		$printer -> text('*** MWISHO WA RISITI HALALI ***' . "\n");




		/* Tax and total */
		// $printer -> text($tax);
		// $printer -> text($discount);
		// $printer -> selectPrintMode(Printer::MODE_DOUBLE_WIDTH);
		// $printer -> text($total);
		// $printer -> selectPrintMode();



		/* Footer */
		/*$printer -> feed(2);
		$printer -> setJustification(Printer::JUSTIFY_CENTER);
		$printer -> text("Thank you for shopping at ExampleMart\n");
		$printer -> text("For trading hours, please visit example.com\n");
		$printer -> feed(2);
		$printer -> text($date . "\n");*/

		$printer -> cut();
		$printer -> pulse();

		$printer -> close();

		

     	}
     	 catch(\Illuminate\Database\QueryException $e)
	    {
	       // return  $e;
	    }
     	

     	/* Cut the receipt and open the cash drawer */
		
     

    }

    public function numberFormat($TEXT)
    {
    return str_replace(',' , '&nbsp;', number_format($TEXT,1));
    }

    

}