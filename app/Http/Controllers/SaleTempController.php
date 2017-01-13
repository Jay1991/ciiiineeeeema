<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\SaleTemp;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use App\Item;
class SaleTempController extends Controller
{
    //
    private $setting;

     public function __construct()
    { 
        $this->setting = new SettingController;                          
    }

     public function index()
    {
        if($this->counter() == 1){ echo 5; }
    // return $this->Length();
    }

    public function addItemTable(Request $request, $table_id)
    {
    try
    {
    $item                                        = Item::where('id', $request->Input('item_id'))->first();
    
    $temp                                        = new SaleTemp;
    $temp->user_id                               = Auth::user()->id;
    $temp->item_id                               = $request->Input('item_id');
    $temp->quantity                              = 1;
    $temp->total_selling                         = $item->selling_price;
    $temp->total_buying                          = $item->buying_price;
    $temp->table_id                              = $table_id;
    $temp->vat_amount                            = $this->vatAmount((float)$item->selling_price);

    $temp->save();

    return $this->api();

    }
    catch(\Illuminate\Database\QueryException $e)
    {
    return response()->json($e,200);
    }

    }

     public function store(Request $request)
    {
    try
    {
    if($request->has('table_id'))
    {
    $item                                        = Item::where('id', $request->Input('item_id'))->first();
    
    $temp                                        = new SaleTemp;
    $temp->user_id                               = Auth::user()->id;
    $temp->item_id                               = $request->Input('item_id');
    $temp->quantity                              = 1;
    $temp->total_selling                         = $item->selling_price;
    $temp->total_buying                          = $item->buying_price;
    $temp->vat_amount                            = $this->vatAmount((float)$item->selling_price);
    $temp->table_id                              = $request->Input('table_id');
    $temp->save();

    return $this->api();
      
    }
    $item                                        = Item::where('id', $request->Input('item_id'))->first();
    
    $temp                                        = new SaleTemp;
    $temp->user_id                               = Auth::user()->id;
    $temp->item_id                               = $request->Input('item_id');
    $temp->quantity                              = 1;
    $temp->total_selling                         = $item->selling_price;
    $temp->total_buying                          = $item->buying_price;
    $temp->vat_amount                            = $this->vatAmount((float)$item->selling_price);

    $temp->save();

    return $this->api();

    }
    catch(\Illuminate\Database\QueryException $e)
    {
    return response()->json($e,200);
    }

    }


     public function update(Request $request, $id)
    {
        if ($request->has('table_id'))
        {
        $item                                        = Item::where('id', $id)->first();

        $temp                                        = SaleTemp::where('item_id', $id)->where('table_id', $request->Input('table_id'))->first();

        $quantity                                    = ((float)$temp->quantity) + 1;

        $temp->quantity                              = $quantity;
        $temp->total_selling                         = (float)$quantity * (float)$item->selling_price;
        $temp->total_buying                          = (float)$quantity * (float)$item->buying_price;
        $temp->vat_amount                            = $this->vatAmount((float)$quantity * (float)$item->selling_price);
        $temp->save();

        return $this->api();

        }

        $item                                        = Item::where('id', $id)->first();

        $temp                                        = SaleTemp::where('item_id', $id)->first();

        $quantity                                    = ((float)$temp->quantity) + 1;

        $temp->quantity                              = $quantity;
        $temp->total_selling                         = (float)$quantity * (float)$item->selling_price;
        $temp->total_buying                          = (float)$quantity * (float)$item->buying_price;
        $temp->vat_amount                            = $this->vatAmount((float)$quantity * (float)$item->selling_price);
        $temp->save();

        return $this->api();


    }

     public function destroy($id)
    {
        //
        $temp                                        = SaleTemp::find($id);
         if($temp->quantity                          == 1)
        {
        SaleTemp::find($id)->delete();
        }
        $temp->quantity                              = ((int)$temp->quantity) - 1;
        $temp->save();

        return $this->api();

    }


     public function delete()
    {
        SaleTemp::where('user_id', Auth::user()->id)->delete();
    }


     public function api()
    {
    $temps                                        = SaleTemp::where('user_id', Auth::user()->id)->orderBy('created_at','desc')
                                                  ->with('item')
                                                  ->with('user')
//                                                  ->with('table')
                                                  ->get();
    return response()->json($temps, 201);
    }

    public function vatAmount($subTotal)
    {
      return  (($this->setting->show(1)->vat_percentage)/100) *  (float)$subTotal;
    }

    public function totalLocalTax()
    {
    $sum   = SaleTemp::where('user_id', Auth::user()->id)->sum('vat_amount');
    return $sum;
    }

    public function totalDiscount()
    {
    $sum   = SaleTemp::where('user_id', Auth::user()->id)->sum('discount_amount');
    return $sum;
    }

    public function subTotal()
    {
    $sum   = SaleTemp::where('user_id', Auth::user()->id)->sum('total_selling');
    return $sum;
    }

    public function table()
    {
    return $this->belongsTo('App\Table');
    }

    public function counter()
    {
    return SaleTemp::count();
    }

    public function truncate()
    {
    SaleTemp::truncate(); 
    }


    

    
}
