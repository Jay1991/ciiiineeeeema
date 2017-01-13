<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\Role;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;

class RoleController extends Controller
{
    //
     public function index()
    {
        return $this->api();
    }

     public function show($name)
    {
        return Role::where('name', 'like', '%' . $name . '%')->first();

    }
     public function api()
    {
        $roles                                            = Role::all();
        return response()->json($roles, 201);

    }
}
