<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use App\Role;
class HomeController extends Controller
{
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    private $role;

    public function __construct()
    {
        $this->role = new RoleController;
        $this->middleware('auth');
    }

    /**
     * Show the application dashboard.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
    return redirect()->action('AppController@index');
    }
}
