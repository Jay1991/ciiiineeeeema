<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \Storage, \DB;

use App\Seat;
class SeatController extends Controller
{
    //

    private $row;

     public function __construct()
    {
        $this->row = new RowController;  
    }


     public function index()
    {
        return $this->row->show(97)->code;
    }


     public function store(Request $request)
    {
        try
        {
        // $rules                        = array(
       
        // );
        // $errorMessage                 = array(

        // );

 
        // $validator                    = Validator::make($request->all(), $rules,$errorMessage);
        // if ($validator->fails()) 
        // {
        //     return $validator->messages()->toJson();
        // }

        $screen = Seat::where('row_id', $request->Input('row_id'))->delete();

         for($i=0; $i < (int)$request->Input('number'); $i++)
        {
        	$row                         = new Seat;
        	$row->number                 = $i + 1;
        	$row->row_id                 = $request->Input('row_id');
        	$row->code                   = $this->row->show($request->Input('row_id'))->code . '.' . $i + 1;
        	$row->save();
        }

        return $this->api();


        }
        catch(\Illuminate\Database\QueryException $e)
        {
            return response()->json($e,200);
        }

    }


     public function api()
    {
        $seats                      = Seat::orderBy('number','asc')->with('row')->get();
        return  response()->json($seats,201);
    }
}
