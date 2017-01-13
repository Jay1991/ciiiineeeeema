<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\Receipt;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use Printers;
use ticketPrinters;
use App\Sale;
// use itemClass;
class ReceiptController extends Controller
{
    //

    private $printer;
    private $printerX;
    private $setting;
     public function __construct()
    {
        $this->printer  = new Printers; 
        $this->printerX = new ticketPrinters; 
        $this->setting  = new SettingController;                           
    }




     public function index()
    {
    // return $this->printer('580f446484362');
        // return view('app');
    }

   

     public function show($number)
    {
        $receipt                                            = Receipt::where('number', $number)->first();
        return $receipt;
    }

     public function store($number,$vat,$discount,$sub,$output,$total)
    {
        $receipt                                            = new Receipt;
        $receipt->number                                    = $number;
        $receipt->status                                    = false;
        $receipt->VAT                                       = $vat;
        $receipt->discount                                  = $discount;
        $receipt->sub_total                                 = $sub;
        $receipt->total                                     = $total;
        $receipt->paid                                      = $output;
        $receipt->user_id                                   = Auth::user()->id;
        $receipt->save();

        return $receipt;
    }

    public function collection($receipt_id)
    {
    $collection        = collect([]);

     Sale::where('receipt_id', $receipt_id)->get()->each(function ($item, $key) use ($collection) 
    {
        
     $collection->push(new itemClass($item->item->name, $item->total_selling));

    });

     return $collection->all();
    }


     public function update($id)
    {
        $receipt                                            = Receipt::find($id);
        $receipt->status                                    = true;
        $receipt->user_id                                   = Auth::user()->id;
        $receipt->save();

    }

     public function printer($number)
    {
        $seatTemp                                           = new SeatTempController;
        $receipt     = $this->show($number);
        if ($receipt->flag  == 0){return $this->printer->printer($this->setting->show(1), $this->collection($receipt->id),$receipt->VAT,$receipt->discount,$receipt->total,$receipt->number,0);}
        if ($receipt->flag  == 1){return $this->printerX->printer($this->setting->show(1), $seatTemp->itemCollection($receipt->id),$receipt->VAT,$receipt->discount,$seatTemp->netX($receipt->sub_total, $receipt->VAT),$receipt->number,$receipt->sub_total);}
        
        // try
        // {

        
        // }
        // catch(\Illuminate\Database\QueryException $e)
        // {
        // return response()->json($e,200);
        // }

        // $this->update($this->show($number)->id);

        // return $this->api();

      
        
    }

    public function api()
    {
        $receipts                                           = Receipt::orderBy('created_at','desc')->get();
        return response()->json($receipts,201);

    }

    public function flag($number,$flagNote)
    {
    $receipt                                                = Receipt::where('number',$number)->first();
    $receipt->flag                                          = $flagNote;
    $receipt->save();
    }

    public function rePrint()
    {
    // if(lastPrint() !=0){$this->printer($this->lastPrint()->number);}
    $this->printer($this->lastPrint()->number);
    
    }

    public function printerX($number)
    {
    $this->printer($number);
    }

    public function lastPrint()
    {
    if(Receipt::where('flag',1)->count() == 0 ){return 0;}
    $receipt                                                = Receipt::where('flag',1)->orderBy('created_at','desc')->first();
    return $receipt; 
    }
}
