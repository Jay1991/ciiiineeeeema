<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;

use App\Director;
class DirectorController extends Controller
{
    //
     public function index()
    {

    return $this->api();

    }

     public function store(Request $request)
    {

    try
    {
    $rules                                                        = array
    (
        'name'                                                        => 'required|unique:directors',
    );
    $errorMessage                                                 = array(

    );


    $validator                                                    = Validator::make($request->all(), $rules,$errorMessage);
    if ($validator->fails()) 
    {
       
        return $validator->messages()->toJson();

    }

    $director                                                     = new Director;
    $director->name                                               = $request->Input('name');
    $director->save();

    return $this->api();                                                            


    }
    catch(\Illuminate\Database\QueryException $e)
    {
        return Redirect::to('auth/login');
    }


    }

     public function update(Request $request, $id)
    {

    try
    {
    $rules                                                        = array
    (
    'name'                                                        => 'required|unique:directors,name,' . $id .'',
    );
    $errorMessage                                                 = array(

    );


    $validator                                                    = Validator::make($request->all(), $rules,$errorMessage);
    if ($validator->fails()) 
    {
       
        return $validator->messages()->toJson();

    }

    $director                                                     = Director::find($id);
    $director->name                                               = $request->Input('name');
    $director->save();

    return $this->api();                                                            


    }
    catch(\Illuminate\Database\QueryException $e)
    {
        return Redirect::to('auth/login');
    }


    }


     public function destroy($id)
    {
    $director                                   = Director::where('id', $id)->delete();
    return $this->api();
    }


     public function api()
    {

    $directors                                  = Director::orderBy('created_at', 'desc')->get();
    return response()->json($directors, 201);


    }
}
