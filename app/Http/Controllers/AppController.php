<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use App\Role;
class AppController extends Controller
{
    //
    private $role;

    public function __construct()
    {
        $this->role = new RoleController;
        $this->middleware('auth');
    }

    public function index()
    {

    $role                                     = $this->role->show('admin');
    if(Auth::check() && Auth::user()->role_id == $role->id)
    {
    return view('app');
    }

    $role                                     = Role::where('name', 'like', '%' . 'consess' . '%')
                                            ->first();
    if(Auth::check() && Auth::user()->role_id == $role->id)
    {
    return view('sales.consessions.index');
    }


    $role                                     = Role::where('name', 'like', '%' . 'movie' . '%')
                                              ->first();
    if(Auth::check() && Auth::user()->role_id == $role->id)
    {
    return view('sales.movies.index');
    }

    $role                                     = Role::where('name', 'like', '%' . 'cashier' . '%')
                                              ->first();
    if(Auth::check() && Auth::user()->role_id == $role->id)
    {
    return view('sales.items.index');
    }



    }


    public function isRemoteFileExist($file)
    {
    $listener                                                          = 0;
    $external_link                                                     = $file;
    if (@getimagesize($external_link)) {
    $listener                                                          =1;
    }
    return $listener; 
    }

    public function numberFormat($TEXT)
    {
    return str_replace(',' , '&nbsp;', number_format($TEXT,2));
    }
}
