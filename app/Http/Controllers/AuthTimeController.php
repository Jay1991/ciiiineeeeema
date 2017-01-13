<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use App\AuthTime;

class AuthTimeController extends Controller
{
    //

     public function index()
    {
        
    }

     
     public function store($time_id, $date_id)
    {
        $time                  = new AuthTime;
        $time->date_id         = $date_id;
        $time->time_id         = $time_id;
        $time->save();
    }

     public function isAlreadyExist($time_id, $date_id)
    {
        $timeLength  = AuthTime::where('date_id', $date_id)->where('time_id', $time_id)->count();
        if($timeLength == 0) return 0; return 1;

    }

     public function destroy($id)
    {
    $authtime                                        = AuthTime::where('id', $id)->delete();
    return $this->api();
    }

    public function delete($date_id)
    {
    $authtime                                        = AuthTime::where('date_id', $date_id)->delete();
    }


     public function api()
    {
        $time = AuthTime::orderBy('created_at','desc')->with('time')->with('date')->get();
        return response()->json($time,201);
    }

    function apilg(Request $request)
    {
    $time                                            = AuthTime::where('date_id', $request->Input('date_id'))
                                                     ->orderBy('created_at','desc')
                                                     ->with('time')
                                                     ->with('date')
                                                     ->get();
    return response()->json($time,201);
    }

    public function report(Request $request)
    {
    // return $this->toDay();
    }

    



   

}
