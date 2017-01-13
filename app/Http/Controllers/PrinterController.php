<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use Mike42\Escpos\PrintConnectors\WindowsPrintConnector;
use Mike42\Escpos\PrintConnectors\FilePrintConnector;
use Mike42\Escpos\Printer;
use Mike42\Escpos\PrintConnectors\NetworkPrintConnector;
use Mike42\Escpos\EscposImage;

class PrinterController extends Controller
{
    //
    public function index()
    {

    }

    public function php1()
    {
    	$printer="/dev/usb/lp0";
		$handle = printer_open($printer); //or it could be \\pcname\printername
		//set printing option to raw
		printer_set_option($handle, PRINTER_MODE, 'RAW');
		//write date to printer
		$data = 'sample printer command';
		$ret = printer_write($handle, $data);
		//close the printer handle
		printer_close($handle);

    }

    public function php()
    {
    	//constant
		$rn=chr(13).chr(10);
		$esc=chr(27);
		$cutpaper=$esc."m";
		$bold_on=$esc."E1";
		$bold_off=$esc."E0";
		$reset=pack('n', 0x1B30);


		      //printer setup
		$printer="/dev/usb/lp0";


		//formating data text:
		$string = "--test EAN-13 barcode wide--\n";
		$string .= "\x1d\x77\x04";   # GS w 4
		$string .= "\x1d\x6b\x02";   # GS k 2 
		$string .= "5901234123457\x00";  # [data] 00
		$string .= "-end-\n";

		//cut paper at end
		$string.=$cutpaper;


		//send data to USB printer
		$fp=fopen($printer, 'w');
		fwrite($fp,$string);
		fclose($fp);
    }

    public function printer()
    {
    $connector = new FilePrintConnector("/dev/usb/lp0");
    $printer   = new Printer($connector);

	/* Text */
	$printer -> text("Hello world\n");
	$printer -> cut();
	$printer -> close();
    }
}
