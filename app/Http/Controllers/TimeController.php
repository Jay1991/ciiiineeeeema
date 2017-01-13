<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \Storage, \DB;
use App\Http\Requests;
use App\Time;
class TimeController extends Controller
{
    //
    private $timer; 

     public function __construct()
    {
        $this->timer    = new AuthTimeController;
        $this->dater    = new DateUserController;

    }
    public function index()
    {
        return $this->dater->show(1);
    }

    public function show($time)
    {
        return Time::where('starting_at', $time)->first();
    }

    public function store(Request $request)
    {   
        $time  =   $this->timeFormat($request->Input('time'));
        $date_id  = $request->Input('date_id');
         if($this->isAlreadyExist($time) != 0)
        {
           if($this->timer->isAlreadyExist($this->show($time)->id, $date_id) == 0)
           {
             $this->timer->store($this->show($time)->id, $date_id);
             return $this->timer->api();
           }
           return $this->timer->api();
        }

        $this->add($time);
        $this->timer->store($this->show($time)->id, $date_id);
        return $this->timer->api();
    }

    public function api()
    {
	    $times                                         = Time::all();
	    return response()->json($times, 201);
    }

    public function destroy($id)
    {
        $time                                          = Time::where('id', $id)->delete();
        return $this->api();
    }

     public function isAlreadyExist($time)
    {
        $timeLength  = Time::where('starting_at', $time)->count();
        if($timeLength == 0) return 0; return 1;

    }

     public function add($timer)
    {
        $time                                          = new Time;
        $time->starting_at                             = $timer;
        $time->save();
    }

     public function timeFormat($time)
    {
       return date('H:i:s', strtotime(str_replace('-', '/', $time)));
    }
}
