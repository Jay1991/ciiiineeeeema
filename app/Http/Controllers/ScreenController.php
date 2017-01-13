<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \Storage, \DB;
use App\Screen;
class ScreenController extends Controller
{
    //
     public function index()
    {
        return $this->change(3,'sadsa',78);
    }

     public function store(Request $request)
    {

        try
        {
        $rules                                                                      = array(
        'name'                                                                      => 'required|unique:screens,name,' . $request->Input('screen_id') .'',
        );
        $errorMessage                                                               = array(

        );

 
        $validator                                                                  = Validator::make($request->all(), $rules,$errorMessage);
        if ($validator->fails()) 
        {
            return $validator->messages()->toJson();
        }

        // if($this->isAleadyExist($request->Input('name')) == 1)
        // {
        //     return $this->show($request->Input('name'));
        // }


        $screen                       = Screen::find($request->Input('screen_id'));
        $screen->name                 = $request->Input('name');
        $screen->user_id              = Auth::user()->id;
        $screen->status               = true;
        $screen->save();

        return $this->api();

        }
        catch(\Illuminate\Database\QueryException $e)
        {
            return Redirect::to('auth/login');
        }





    }

     public function update(Request $request,$id)
    {

        try
        {
        $rules                                                                      = array(
        'name'                                                                      => 'required|unique:screens,name,' . $id .'',
        );
        $errorMessage                                                               = array(

        );

 
        $validator                                                                  = Validator::make($request->all(), $rules,$errorMessage);
        if ($validator->fails()) 
        {
            return $validator->messages()->toJson();
        }

    

        $screen                       = Screen::find($id);
        $screen->name                 = $request->Input('name');
        $screen->save();

        return $this->api();

        }
        catch(\Illuminate\Database\QueryException $e)
        {
        return response()->json($e, 200);
        }





    }



     public function show($name)
    {
        $screen   = Screen::where('name', $name)->where('user_id',Auth::user()->id)->where('status',false)->first();
        return response()->json($screen, 201);
    }

     public function destroy($id)
    {
    $screen                          = Screen::where('id', $id)->delete();
    return $this->api();
    }


     public function api()
    {
    	$screens                                    = Screen::orderBy('created_at','desc')->get();
    	return response()->json($screens, 201);
    }

     public function isAleadyExist($name)
    {
        $screenLength = Screen::where('name',$name)->count();
        if($screenLength == 0) return 0; return 1;
    }



     public function newer()
    {
         try
        {
        // $rules                                                                      = array(
        // 'name'                                                                      => 'required',
        // );
        // $errorMessage                                                               = array(

        // );

 
        // $validator                                                                  = Validator::make($request->all(), $rules,$errorMessage);
        // if ($validator->fails()) 
        // {
        //     return $validator->messages()->toJson();
        // }

        if($this->isAleadyExister() == 1){ return $this->shower();}


        $screen                       = new Screen;
        $screen->name                 = '';
        $screen->user_id              = Auth::user()->id;
        $screen->status               = false;
        $screen->save();

        return response()->json($screen,201);

        }
        catch(\Illuminate\Database\QueryException $e)
        {
            return Redirect::to('auth/login');
        }

    }
       public function isAleadyExister()
    {
        $screenLength = Screen::where('user_id',Auth::user()->id)->where('status', false)->count();
        if($screenLength == 0) return 0; return 1;
    }

     public function shower()
    {
        $screen   = Screen::where('user_id',Auth::user()->id)->where('status', false)->first();
        return response()->json($screen, 201);
    }

     public function change($creen_id, $name,$rows)
    {
        $screen                      = Screen::find($creen_id);
        $screen->name                = $name;
        $screen->rows                = $rows;
        $screen->save();
    }


}
