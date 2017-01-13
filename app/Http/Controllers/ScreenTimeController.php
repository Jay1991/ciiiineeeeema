<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use App\Http\Requests;
use App\ScreenTime;

class ScreenTimeController extends Controller
{
    //
     public function index()
    {
        return $this->api();
    }

     public function store(Request $request)
    {
        if ($this->isAlreadyExist($request->Input('screen_id'),$request->Input('time_id')) == 0)
        {
            $this->add($request->Input('screen_id'),$request->Input('time_id'));

        }

        return $this->api();

    }

     public function destroy($id)
    {
        $temp                                         = ScreenTime::where('id', $id)->delete();
        return $this->api();                                        
    }

     public function add($screen_id, $time_id)
    {
        $screen                                        = new ScreenTime;
        $screen->screen_id                             = $screen_id;
        $screen->time_id                               = $time_id;
        $screen->save();
    }

     public function api()
    {
    $screen                                            = ScreenTime::orderBy('created_at', 'desc')->with('screen')->with('time')->get();
    return response()->json($screen,201);
    }

     public function apilg(Request $request)
    {
    $screen                                            = ScreenTime::where('time_id', $request->Input('time_id'))
                                                       ->orderBy('created_at', 'desc')
                                                       ->with('screen')
                                                       ->with('time')
                                                       ->get();
    return response()->json($screen,201);
    }


     public function isAlreadyExist($screen_id,$time_id)
    {
        $screenLength = ScreenTime::where('screen_id',$screen_id)->where('time_id', $time_id)->count();
        if($screenLength  == 0) return 0;return 1;
    }
}
