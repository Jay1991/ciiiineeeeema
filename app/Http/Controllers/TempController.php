<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;

class TempController extends Controller
{
    //
     public function index()
    {
        return $this->api();
    }
     public function api()
    {
        $temps                                        = ConsessionSaleTemp::all();
        return response()->json($temps, 201);
    }
}
