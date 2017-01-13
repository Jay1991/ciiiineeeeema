<?php
use Mike42\Escpos\PrintConnectors\WindowsPrintConnector;
use Mike42\Escpos\PrintConnectors\FilePrintConnector;
use Mike42\Escpos\Printer;
use Mike42\Escpos\PrintConnectors\NetworkPrintConnector;
use Mike42\Escpos\EscposImage;
use App\SeatTemp;
use App\Receipt;
// use itemClass;
// use Carbon;
class ticketPrinters {

    public static function printer($setting, $items,$vatAmount,$discountAmount,$total,$number,$subTotal)
    {
    	try{
	     $connector             = new WindowsPrintConnector("smb://DESKTOP-QMGQ05S/EPSON TM-T20II Receipt");

//    $connector             = new FilePrintConnector("/dev/usb/lp0");
		$printer               = new Printer($connector);

		$receipt               = Receipt::where('number', $number)->first();

		$printer -> setJustification(Printer::JUSTIFY_CENTER);
		$printer -> text('*** MWANZO WA RISITI HALALI ***' . "\n");
		$printer -> feed(2);
		$printer -> text($setting->app_name . "\n");
		$printer -> text($setting->postal_address . "\n");
		$printer -> text('DAR ES SALAAM' . "\n");
		$printer -> text('TANZANIA' . "\n");
		$printer -> setJustification();

		$printer -> selectPrintMode(Printer::MODE_DOUBLE_WIDTH);
		$tin     = new itemClass('TIN', $setting->tin,true);
		$printer -> text($tin);
		$printer -> selectPrintMode();
		$vrn = new itemClass('VRN', $setting->vrn);
		$printer -> text($vrn);
		$uin = new itemClass('UIN', $setting->uin);
		$printer -> text($uin);
		$printer -> feed(1);
		$printer -> selectPrintMode();
		$printer -> setJustification(Printer::JUSTIFY_CENTER);
		$printer -> text("TEMEKE\n");
		$printer -> setJustification();
		$printer -> feed();

		$rNumber = new itemClass('NAMBA YA RISITI',$number);
		$printer ->text($rNumber);
		$zno = new itemClass('ZNo',$setting->zno);
		$printer ->text($zno);
		$fp = new itemClass('FP:01', 01);
		$printer ->text($fp);
		$printer -> text('------------------------------------------------' . "\n");

		if($receipt->flag       == 1)
		{
        $temp                   = SeatTemp::where('receipt_id', $receipt->id)->first();
		$DATE                  = new itemClass('DATE', date('d-m-Y', strtotime(str_replace('-', '/', $temp->date->date))));
		$printer -> text($DATE);
		$TIME                  = new itemClass('TIME', $temp->timer->starting_at);
        $printer -> text($TIME);


		$MOVIE                 = new itemClass('MOVIE',$temp->movie->name);
		$printer -> text($MOVIE);
		$printer -> selectPrintMode(Printer::MODE_DOUBLE_WIDTH);
		$SCREEN                = new itemClass('SCREEN',$temp->seat->row->screen->name,true);
		$printer -> text($SCREEN);
		$printer -> selectPrintMode();

		$RESTRICTION           = new itemClass('RESTRICTION',$temp->movie->guidance->name);
        $printer -> text($RESTRICTION);


        $LENGTH = 0;
        foreach ($items as $item) {
		    $LENGTH +=  1;
		}

        $TICKETS           = new itemClass('TICKETS',$LENGTH);
        $printer -> text($TICKETS);

        $printer -> selectPrintMode(Printer::MODE_DOUBLE_WIDTH);
        $SEATS             = new itemClass('SEATS','', true);
        $printer -> text($SEATS);
        $printer -> selectPrintMode();

		}

		$printer -> text('------------------------------------------------' . "\n");

		foreach ($items as $item) {
		    // $printer -> setEmphasis(true);
		     $printer -> text($item);
		    // $printer -> setEmphasis(false);

		}

		// $printer -> setEmphasis(true);
		$printer -> text('------------------------------------------------' . "\n");
		$subtotal = new itemClass('| SUBTOT.A', str_replace(',' , ' ', number_format($subTotal,2)) . ' |' );
		$printer -> text($subtotal);
		$net      = new itemClass('| NET A', str_replace(',' , ' ', number_format($total,2))   . ' |');
		$printer -> text($net);
		$vat      = new itemClass('| VAT A', str_replace(',' , ' ', number_format($vatAmount,2))  . ' |');
		$printer -> text($vat);
		// $printer -> setEmphasis(false);
		$printer -> feed();
		$printer -> text('------------------------------------------------' . "\n");



        $printer -> selectPrintMode(Printer::MODE_DOUBLE_WIDTH);
        $JUMLA   = new itemClass('JUMLA', $setting->currency_symbol . ' ' . str_replace(',' , ' ', number_format($subTotal,2)) , true);
		$printer -> text($JUMLA);
		$printer -> selectPrintMode();

		$printer -> text('------------------------------------------------' . "\n");
        $KODI    = new itemClass('KODI ILIYOTOZWA A-18.00%', str_replace(',' , ' ', number_format($subTotal,2)) );
        $printer -> text($KODI);
        $VATA    = new itemClass('VAT A-18.00%', str_replace(',' , ' ', number_format($vatAmount,2))  );
        $printer -> text($VATA);
		$printer -> text('------------------------------------------------' . "\n");
        $printer -> selectPrintMode(Printer::MODE_DOUBLE_WIDTH);
        $JUMLAVAT = new itemClass('JUMLA VAT', str_replace(',' , ' ', number_format($vatAmount,2)) , true);
		$printer -> text($JUMLAVAT);
		$printer -> selectPrintMode();
		$printer -> text('------------------------------------------------' . "\n");
		$FEDHA   = new itemClass('FEDHA', str_replace(',' , ' ', number_format($subTotal,2)) );
		$printer -> text($FEDHA);
		$NAMBAYABIDHAA = new itemClass('NAMBA YA BIDHAA', $LENGTH);
		$printer -> text($NAMBAYABIDHAA);
		$TAREHE  = new itemClass('TAREHE  ' . date('d-m-Y'), date('H:i'));
		$printer -> text($TAREHE);
		$SN      = strtoupper(str_random(6));
		$SERIALNUMBER = new itemClass('SERIAL NUMBER', $SN);
		$printer -> text($SERIALNUMBER);
		$NUMBERYAEJILIYOWEZESHWA = new itemClass('NAMBA YA EJ ILIYOWEZESHWA', sprintf('%.1f', '1515'));
		$printer -> text($NUMBERYAEJILIYOWEZESHWA);
		$TAREHEYAEJKUWEZESHA     = new itemClass('TAREHE YA EJ KUWEZESHWA', sprintf('%.1f', '21-03-2016'));
		$printer -> text($TAREHEYAEJKUWEZESHA);

		$printer -> feed(1);


		if($receipt->flag       == 1)
		{
		$printer ->text('Rights of admission reserved.No Exchange or Refunds or Cancellations of tickets.In the event the show is cancelled the liability is limited to the price of the ticket only.In the case of any disputes or errors or malfunction of the computerised ticketing system the liability is limited to the price of the ticket only.In this regard the Managements decision is abiding and final.E & OE\n' . "\n");
		}

		$printer -> feed(1);

		$printer -> setJustification(Printer::JUSTIFY_CENTER);

		$printer -> text('*** MWISHO WA RISITI HALALI ***' . "\n");









		// $receipt               = Receipt::where('number', $number)->first();
  //       $temp                  = SeatTemp::where('receipt_id', $receipt->id)->first();

  //       $printer -> setJustification(Printer::JUSTIFY_CENTER);
  //       $printer -> text($setting->app_name . "\n");
  //       $printer -> setJustification();

  //       $printer -> feed(2);


		// $TICKETNUMBER          = new itemClass('TICKET NUMBER', $number);
		// $printer -> text($TICKETNUMBER);
		// $DATE                  = new itemClass('DATE', date('d-m-Y', strtotime(str_replace('-', '/', $temp->date->date))));
		// $printer -> text($DATE);
		// $TIME                  = new itemClass('TIME', $temp->timer->starting_at);
  //       $printer -> text($TIME);


		// $MOVIE                 = new itemClass('MOVIE',$temp->movie->name);
		// $printer -> text($MOVIE);
		// $SCREEN                = new itemClass('SCREEN',$temp->seat->row->screen->name);
		// $printer -> text($SCREEN);
		// $RESTRICTION           = new itemClass('RESTRICTION',$temp->movie->guidance->name);
  //       $printer -> text($RESTRICTION);


  //       $LENGTH = 0;
  //       foreach ($items as $item) {
		//     $LENGTH +=  1;
		// }

		// $TICKETS           = new itemClass('TICKETS',$LENGTH);
  //       $printer -> text($TICKETS);

  //       $printer -> selectPrintMode(Printer::MODE_DOUBLE_WIDTH);
  //       $SEATS             = new itemClass('SEATS','', true);
  //       $printer -> text($SEATS);
  //       $printer -> selectPrintMode();

		// $printer -> text('------------------------------------------------' . "\n");

		// foreach ($items as $item) {
		//     $printer -> text($item);
		// }

		// $printer -> text('------------------------------------------------' . "\n");


		// $printer ->text('Rights of admission reserved.No Exchange or Refunds or Cancellations of tickets.In the event the show is cancelled the liability is limited to the price of the ticket only.In the case of any disputes or errors or malfunction of the computerised ticketing system the liability is limited to the price of the ticket only.In this regard the Managements decision is abiding and final.E & OE\n');

  //       $printer -> feed(1);

  //       $printer -> setJustification(Printer::JUSTIFY_CENTER);
		// $printer -> text(date('d-m-Y H:i') . "\n");




        $printer -> cut();
		$printer -> pulse();
		$printer -> close();

	    }
        catch(\Illuminate\Database\QueryException $e)
        {
        // return response()->json($e,200);
        }







    }

}
