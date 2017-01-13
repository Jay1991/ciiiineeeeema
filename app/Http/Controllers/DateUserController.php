<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\DateUser;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
class DateUserController extends Controller
{
    //
    private $authtime;
    private $price;
     public function __construct()
    {
        // $this->middleware('auth');
        $this->authtime   =  new AuthTimeController;
        $this->price      =  new PriceController;
    }


    public function index()
    {
      return $this->load();
    }

    public function store($date_id,$movie_id)
    {
    $price;
    if($this->price->isAlreadyExist(0) == 1)
    {
    $price  = $this->price->show(0);
    }
    else
    {
    $price  = $this->price->store(0);
    }

    $authdate                                      = new DateUser;
    $authdate->date_id                             = $date_id;
    $authdate->status                              = false;
    $authdate->movie_id                            = $movie_id;
    $authdate->price_id                            = $price->id;
    $authdate->save();

    }

     public function show($date_id,$movie_id)
    {
      $temp                                           = DateUser::where('date_id', $date_id)
                                                      ->where('movie_id', $movie_id)
                                                      ->with('user')
                                                      ->with('date')
                                                      ->with('price')
                                                      ->first();
      return $temp;
    }

     public function destroy($id)
    {

    $this->authtime->delete($this->seen($id)->date->id);
    $authdate                                         = DateUser::where('id', $id)->delete();
    return $this->api();

    }

     public function seen($id)
    {
     $authtime                                        = DateUser::where('id', $id)->first();
     return $authtime; 
    }



     public function isAlreadyExist($date_id,$movie_id)
    {
      $dateLength = DateUser::where('date_id',$date_id)->where('movie_id',$movie_id)->count();
      if($dateLength  == 0) return 0;return 1;
    }

    public function apilg(Request $request)
    {
    $authdate                                       = DateUser::where('movie_id', $request->Input('movie_id'))
                                                    ->orderBy('created_at','desc')
                                                    ->with('user')
                                                    ->with('date')
                                                    ->with('price')
                                                    ->with('movie')
                                                    ->get();
    return response()->json($authdate,201);

    }


    

    public function api()
    {
    	$authdate                                     = DateUser::orderBy('created_at','desc')
                                                    ->with('user')
                                                    ->with('date')
                                                    ->with('price')
                                                    ->with('movie')
                                                    ->get();
    	return response()->json($authdate,201);

    }

     public function temp($movie_id)
    {
    $temps               =  DateUser::where('user_id', Auth::user()->id)->where('movie_id', 0)->get();
     collect($temps)->each(function ($temp, $key) use($movie_id) 
    {
     $temp->movie_id   = $movie_id;
     $temp->save();
    });

    }

     public function listen()
    {
      $temp            = DateUser::where('user_id', Auth::user()->id)->where('movie_id', 0)->get();
      return response()->json($temp, 200);
    }

     public function price(Request $request, $id)
    {
    $price;
    if($this->price->isAlreadyExist($request->Input('price')) == 1)
    {
    $price  = $this->price->show($request->Input('price'));
    }
    else
    {
    $price  = $this->price->store($request->Input('price'));
    }

    $temp                                                    = DateUser::find($id);
    $temp->price_id                                          = $price->id;
    $temp->save();
      
    return $this->api();

    }

     public function load()
    {
    $type                                                     = new ItemTypeController;
    $temp                                                     = DateUser::whereHas('date', function($query){
                                                                        $query->where(DB::raw('DATE(date)'),'>=', date("Y-m-d"))
                                                                        ;
                                                               })
                                                              ->whereHas('movie', function($query){
                                                                $query->where('status', true)
                                                                      ->where('item_type_id',$type->show('movie')->id)
                                                                ;

                                                              })
                                                              ->with('date')
                                                              ->with('price')
                                                              ->with('movie')
                                                              ->get();
    return response()->json($temp,201);                         
    }
}
