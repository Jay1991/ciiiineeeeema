<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use App\SeatTemp;
use itemClass;
use Printers;
use ticketPrinters;
use App\Time;
use App\AuthTime;

class SeatTempController extends Controller
{
    //
    private $receipt;
    private $printer;
    private $setting;

     public function __construct()
    {
        $this->receipt = new ReceiptController;
        $this->printer = new ticketPrinters; 
        $this->setting = new SettingController;                          
    }

     public function index()
    {
      $this->receipt->printerX(1802046836);
    }
    
       public function selected($flag, $id){           
      
        $temps = SeatTemp::where('user_id', Auth::user()->id)
                            ->where('flag', '=', $flag)
                            ->where('status','=', 0)
                            ->where('time_id', '=', $id)
                            ->with('seat')
                            ->with('row')
                            ->with('user')
                            ->with('time')
                            ->get();


	 return response()->json($temps, 201);
        

    }

     public function store(Request $request)
    {
      if(Auth::check() != true) return response()->json('session has being expired',200); 
      
      $temp                          = new SeatTemp;
      $temp->user_id                 = Auth::user()->id;
      $temp->time_id                 = $request->Input('time_id');
      $temp->seat_id                 = $request->Input('seat_id');
      $temp->flag                    = $request->Input('flag');
      $temp->date_id                 = $request->Input('date_id');
      $temp->movie_id                = $request->Input('movie_id');
      $temp->timer_id                = $request->Input('timer_id');
      $temp->row_id                  = $request->Input('row_id');
      $temp->price_id                = $request->Input('price_id');
      $temp->status                  = false;
      $temp->save();

      return $this->api();
    }

     public function update(Request $request,$id)
    {
      // $temp                          = new SeatTemp;
      // $temp->user_id                 = Auth::user()->id;
      // $temp->time_id                 = $request->Input('time_id');
      // $temp->seat_id                 = $request->Input('seat_id');
      // $temp->status                  = true;
      // $temp->save();

      // return $this->api();
    }

     public function compute(Request $request)
    {
    
    if(Auth::check() != true) return response()->json('session has being expired',200); 
    $net = $request->Input('subTotal');
    if($request->Input('isComplementary') == 1)
    {
        $net = 0;
    }
    
    $number     = rand();
    $_receipt   = $this->receipt->store($number,$this->vatAmount($request->Input('subTotal')),0,$request->Input('subTotal'),$request->Input('output'),$net);
    $this->receipt->flag($number,1);
    $isComplementary = $request->Input('isComplementary');

$temp   = SeatTemp::where('user_id', Auth::user()->id)
        ->where('flag', $request->Input('flag'))
        ->where('status', false)
        ->where('time_id', $request->Input('time_id'))
        ->with('seat')
        ->with('user')
        ->with('time')
        ->get();
         
    
    $collection = collect([]);

    collect($temp)->each(function ($temp, $key) use ($collection,$isComplementary,$_receipt)
    {
    $collection->push(new itemClass('| ' . $temp->seat->row->code . '-' . $temp->seat->number, $temp->time->date->price->figure . ' |'));
    $temp->status                                       =  true;
    $temp->receipt_id                                   =  $_receipt->id;
    $temp->is_complementary                             =  $isComplementary;
    $temp->distributor_percentage                       =  $temp->time->date->movie->director_fee;
    $discount_amount                                    =  0;
    $net                                                =  0;
    $distributor_commission                             =  0;
    $final_amount                                       =  0;
    $with_draw_tax                                      =  0;
    $vat_amount                                         =  0;



    if($isComplementary == 1)
    {
    $discount_amount                                    =  $temp->time->date->price->figure;
    }
    else
    {
    $discount_amount                                    =  0;
    $net =  $this->net($temp->time->date->price->figure, $this->vatAmount($temp->time->date->price->figure),$this->withDrawTax($temp->time->date->price->figure));
    $with_draw_tax =  $this->withDrawTax($temp->time->date->price->figure);
    $vat_amount =  $this->vatAmount($temp->time->date->price->figure);
    }

    // if($temp->flag                                      == 2)
    // {
    // $discount_amount                                    = $temp->time->date->price->figure;
    // }

    $temp->vat_amount                                   =  $vat_amount;
    $temp->with_draw_tax                                =  $with_draw_tax;
    $temp->discount_amount                              =  $discount_amount;
    $temp->net                                          =  $net;
    $temp->distributor_commission                       =  $this->distributorCommission($temp->time->date->movie->director_fee, $net);
    $temp->final_amount                                 =  $this->finalAmount($net,$this->distributorCommission($temp->time->date->movie->director_fee, $net));
    $temp->distributor                                  =  $temp->time->date->movie->director->name;
    $temp->save();

    });





    if($request->Input('flag') != 2){
    $this->printer->printer($this->setting->show(1),$collection->all(),$this->vatAmount($request->Input('subTotal')),$this->totalDiscountAmount($_receipt->id),$this->netX($request->Input('subTotal'),$this->vatAmount($request->Input('subTotal'))),$number,$request->Input('subTotal'));
    $this->receipt->update($_receipt->id);
    }


    

    return $this->api();

    }
    
 


     public function remove(Request $request)
    {
    if(Auth::check() != true) return response()->json('session has being expired',200); 
    $temp = SeatTemp::where('user_id', Auth::user()->id)
        ->where('time_id', $request->Input('time_id'))
        ->where('seat_id', $request->Input('seat_id'))
        // ->where('flag', $request->Input('flag'))
        ->where('is_already_saled', false)
        ->delete();
    return $this->api();

    }

     public function api()
    {

    $temp=SeatTemp::with('seat')->with('user')->with('time')->with('price')->with('row')->get();
    return response()->json($temp, 201);

    }




     public function apilg(Request $request)
    {

    $temp                                                       = SeatTemp::where('time_id', $request->Input('time_id'))
                                                                ->with('seat')
                                                                ->with('user')
                                                                ->with('time')
                                                                ->with('price')
                                                                ->with('row')
                                                                ->get();
    return response()->json($temp, 201);

    }

     public function vatAmount($subTotal)
    {
      return  (($this->setting->show(1)->vat_percentage)/100) *  (float)$subTotal;
    }

     public function withDrawTax($subTotal)
    {
      return  (10/100) *  (float)$subTotal;
    }

     public function booked()
    {
    $temp                                         = SeatTemp::where('flag', 2)
                                                  ->where('status', true)
                                                  ->with('user')
                                                  ->with('time')
                                                  ->with('seat')
                                                  ->with('date')
                                                  ->with('movie')
                                                  ->with('timer')
                                                  ->with('row')
                                                  ->with('price')
                                                  ->get();
    return response()->json($temp, 201);


    }

     public function unBook(Request $request, $id)
    {
    $temp                                         = SeatTemp::where('id', $id)->delete();
    // $temp->status                                 = false;
    // $temp->save();

    return $this->booked();
    }

    public function confirmBook(Request $request, $id)
    {
    $temp                                         = SeatTemp::find($id);
    $number                                       = rand();
    $_receipt                                     = $this->receipt->store($number,$temp->vat_amount,0,$temp->price->figure,$temp->price->figure,$temp->final_amount);

    $temp->status                                 = true;
    $temp->flag                                   = 1;
    $temp->receipt_id                             = $_receipt->id;
    $temp->save();

    $_receipt->flag                               = 1;
    $_receipt->status                             = true;
    $_receipt->save();


    $this->receipt->printerX($_receipt->number);

    return $this->booked();
    
    }

    public function movieNotRepeated()
    {

    }

     public function isComplementary($log)
    {
    if($log == 1) return 1; return 0;
    }

    public function distributorCommission($commissionPercentage,$net)
    {
    $commission = ($commissionPercentage/100) * $net;
    return $commission;
    }

    public function net($fig,$vatAmount, $withDrawTax)
    {
    return $fig - $vatAmount - $withDrawTax;
    }

    public function finalAmount($net,$commission)
    {
    return $net - $commission;
    }

     public function itemCollection($receipt_id)
    {
    $temp                                         = SeatTemp::where('receipt_id',$receipt_id)->get();
    $collection = collect([]);
    collect($temp)->each(function ($temp, $key) use ($collection, $receipt_id)
    {
    $collection->push(new itemClass('| ' . $temp->seat->row->code . '-' . $temp->seat->number, $temp->time->date->price->figure . ' |'));
    });

    return $collection->all();

    }

    public function itemCollectionX($id)
    {
    $temp                                         = SeatTemp::where('id',$id)->get();
    $collection = collect([]);
    collect($temp)->each(function ($temp, $key) use ($collection, $id)
    {
    $collection->push(new itemClass('| ' . $temp->seat->row->code . '-' . $temp->seat->number, $temp->time->date->price->figure . ' |'));
    });

    return $collection->all();

    }

    public function totalDiscountAmount($receipt_id)
    {
    $sum                                         = SeatTemp::where('receipt_id', $receipt_id)
                                                 ->sum('discount_amount');
    return $sum;
    }

    public function getFirstSalesRowByReceiptId($receipt_id)
    {
    $sales                                       = SeatTemp::where('receipt_id', $receipt_id)->first();
    return $sales;
    }

    public function netX($subTotal, $vatAmount)
    {
    return $subTotal - $vatAmount;
    }

    

    

}
