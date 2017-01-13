<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\Role;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use App\ItemType;
use App\Item;
class DashboardController extends Controller
{
    //
     public function index()
    {
       $role                                                                      = Role::where('name', 'like', '%' . 'admin' . '%')->first();
        if(Auth::check() && Auth::user()->role_id == $role->id)
       {
        return view('app');
       }

       $role                                                                      = Role::where('name', 'like', '%' . 'consess' . '%')->first();
        if(Auth::check() && Auth::user()->role_id == $role->id)
       {
        return view('sales.consessions.index');
       }


       $role                                                                      = Role::where('name', 'like', '%' . 'movie' . '%')->first();
        if(Auth::check() && Auth::user()->role_id == $role->id)
       {
        return view('sale.movie.index');
       }
    }
}
