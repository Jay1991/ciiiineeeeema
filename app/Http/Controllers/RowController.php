<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;

use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \Storage, \DB;
use App\Row;
class RowController extends Controller
{
    //
     public function index()
    {
        // return $this->add(1,10); 
    }

     public function show($id)
    {
        return Row::find($id);
    }

     public function update(Request $request, $id)
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

      
        $row                             = Row::find($id);
        $row->code                       = $request->Input('code');
        $row->save();

        $seats                           = new SeatController;

        return $seats->api();


        }
        catch(\Illuminate\Database\QueryException $e)
        {
            return Redirect::to('auth/login');
        }

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

        $screen = Row::where('screen_id', $request->Input('screen_id'))->delete();

         for($i=0; $i < (int)$request->Input('number'); $i++)
        {
        	$row                         = new Row;
        	$row->number                 = $i + 1;
        	$row->screen_id              = $request->Input('screen_id');
        	$row->save();
        }

        $screen                          = new ScreenController;
        $screen->change($request->Input('screen_id'),$request->Input('name'), $request->Input('number'));




        return $this->api();


        }
        catch(\Illuminate\Database\QueryException $e)
        {
            return Redirect::to('auth/login');
        }

    }

     public function api()
    {
       $rows = Row::orderBy('number','asc')->with('screen')->get();
       return response()->json($rows, 201);

    }
}
