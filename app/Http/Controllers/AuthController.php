<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;

class AuthController extends Controller
{
    //

     public function index()
    {
        Auth::logout();
        return redirect('login');
    }
}
