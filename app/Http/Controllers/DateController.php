<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\Date;
use App\DateUser;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;

class DateController extends Controller
{
    //
    private $authdate;
    public function __construct()
    {

    $this->middleware('auth');
    $this->authdate                                  =  new DateUserController;

    }

    public function index()
    {
    	return $this->authdate->api();
    }
    public function store(Request $request)
    {
    	
        $date                                        = date('Y-m-d', strtotime(str_replace('-', '/', $request->Input('date'))));
        if ($this->isAlreadyExist($date) != 0)
        {
        	$date_id                                = $this->show($date)->id;
        	 if($this->authdate->isAlreadyExist($date_id, $request->Input('movie_id'))  !=0)
            {
            return $this->authdate->api();
            }

    	    $this->authdate->store($date_id,$request->Input('movie_id'));
            return $this->authdate->api();

        }
        
        $date_id                                   = $this->add($date)->id;
        $this->authdate->store($date_id,$request->Input('movie_id'));
        return $this->authdate->api();

        

    }

     public function show($date)
    {
        return Date::where('date',$date)->first();
    }

     public function ask(Request $request)
    {
        // $date     =  $this->show($this->dateFormat($request->Input('date')));
        $date   = $this->authdate->show($this->show($this->dateFormat($request->Input('date')))->id); 
        return response()->json($date,201);
    }

     public function isAlreadyExist($date)
    {
        $dateLength = Date::where('date',$date)->count();
        if($dateLength  == 0) return 0;return 1;
    }
    public function api()
    {
    	$dates                                       = Date::all();
    	return response()->json($dates, 201);
    }

     public function add($date)
    {
        $_date                                       = new Date;
        $_date->date                                 = $date;
        $_date->save();

        return $_date;
    }

    public function dateFormat($dater)
    {
        $date                                        = date_create($dater); date_add($date,date_interval_create_from_date_string("1 days")); $date   = date_format($date,"Y-m-d");
        return $date;
    }
}
