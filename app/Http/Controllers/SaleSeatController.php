<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;

use App\SaleSeat;
use itemClass;
class SaleSeatController extends Controller
{
    //
    private $temp;

    public function __construct()
	{
		$this->temp = new SeatTempController;
	}

     public function index()
    {
     return $this->store();
    }

     public function store()
    {

    $collection = collect([]);

    collect($this->temp->temp(2,4))->each(function ($temp, $key) use ($collection)
    {
    // $collection->push(new itemClass($temp->seat->row->code . '-' . $temp->seat->number, $temp->time->date->price->figure));
    // $temp->is_already_saled                             =  false;
    // $temp->save();


    $sale                                               = new SaleSeat;
    $sale->seat_id                                      =  $temp->seat_id;
    $sale->time_id                                      =  $temp->time_id;
    $sale->user_id                                      =  $temp->user_id;
    $sale->price_id                                     =  $temp->time->price->figure;
    $sale->status                                       =  $request->Input('flag');

    $sale->save();
                                           

    });

    // $this->printer->printer($this->setting->show(1),$collection->all(),67,89,78,67);

    }

     public function api()
    {
      $sales                               = SaleSeat::all();
      return response()->json($sales, 201);
    }
}
