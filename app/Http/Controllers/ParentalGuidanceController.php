<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\ParentalGuidance;
class ParentalGuidanceController extends Controller
{
    //

     public function index()
    {
      return $this->api();
    }

     public function api()
    {
    $parentalGuidance                             = ParentalGuidance::all();
    return response()->json($parentalGuidance, 201);
    }
}
