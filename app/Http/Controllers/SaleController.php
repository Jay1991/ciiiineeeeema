<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\Sale;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;

use Printers;
use ticketPrinters;

use App\SaleTemp;
use itemClass;
use App\Setting;

class SaleController extends Controller
{
    //

    private $receipt;
    private $printer;
    private $setting;
    private $temp;

     public function __construct()
    {
        $this->receipt = new ReceiptController;
        $this->printer = new Printers; 
        $this->setting = new SettingController;
        $this->temp    = new SaleTempController;
                                     
    }

     public function index()
    {
    $collection = array(
    new itemClass("Example item #1", "4.00"),
    new itemClass("Another thing", "3.50"),
    new itemClass("Something else", "1.00"),
    new itemClass("A final item", "4.45"),
    );

        $printer           = new ticketPrinters;
        return $printer->printer(Setting::find(1),$collection,2,2,3,4,6);
    }

     public function store(Request $request)
    {
          try
         {

         $total = ((float)$request->Input('subTotal') + (float)$request->Input('vatAmount'))- (float)$request->Input('discountAmount');

         $number     = strtoupper(str_random(6));

         $_receipt   = $this->receipt->store($number,$this->vatAmount($request->Input('subTotal')),$request->Input('discountAmount'), $request->Input('subTotal'), $request->Input('output'),$total);

         $collection = collect([]);
         $discountAmount              = $this->discountAmount(SaleTemp::where('user_id', Auth::user()->id)->count(), $request->Input('discountAmount'));               
         

         SaleTemp::where('user_id', Auth::user()->id)->get()->each(function ($item, $key) use ($collection,$_receipt,$discountAmount) 
        {
            
         $collection->push(new itemClass('| ' . $item->item->name, $item->total_selling . ' |'));

         $sale                                        = new Sale;
         $sale->item_id                               = $item->item->id;
         $sale->quantity                              = $item->quantity;
         $sale->total_selling                         = $item->total_selling;
         $sale->total_buying                          = $item->total_buying;
         $sale->user_id                               = $item->user_id;
         $sale->vat_amount                            = $item->vat_amount;
         $sale->receipt_id                            = $_receipt->id;
         $sale->discount_amount                       = $discountAmount;
         $sale->save();

         $item->status                                = true;
         $item->discount_amount                       = $discountAmount;
         $item->save();
        });

        
        $this->printer->printer($this->setting->show(1),$collection->all(),$this->temp->totalLocalTax(),$this->temp->totalDiscount(),$this->netX($this->temp->subTotal(),$this->temp->totalLocalTax()),$number,$this->temp->subTotal());
        $this->receipt->update($_receipt->id);
        $this->temp->delete();
        if($this->temp->counter() == 0){$this->temp->truncate();}
        return $this->temp->api();

        }
         catch(\Illuminate\Database\QueryException $e)
        {
            return $e;
        }


    }

     

     public function api()
    {
        $sales                                        = Sale::with('item')->with('user')->get();
        return response()->json($sales, 201);
    }

     public function collection($receipt_id)
    {
        $collection = collect([]);

         Sale::where('receipt_id', $receipt_id)->get()->each(function ($item, $key) use ($collection) 
        {
            
         $collection->push(new itemClass('| ' . $item->item->name, $item->total_selling . ' |'));

        
        });

         return $collection;
    }

     public function discountAmount($itemNumber, $discountFig)
    {
    return (float)$discountFig/(int)$itemNumber;
    }

    public function vatAmount($subTotal)
    {
    return  (($this->setting->show(1)->vat_percentage)/100) *  (float)$subTotal;
    }

    public function netX($subTotal, $vatAmount)
    {
    return $subTotal - $vatAmount;
    }


}
