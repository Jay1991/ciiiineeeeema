<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;

use App\Price;
class PriceController extends Controller
{
    //

     public function index()
    {
    return  $this->store(102);
    }

    public function store($fig)
    {
    $price                                                      = new Price;
    $price->figure                                              = $fig;
    $price->save();

    return $price;
    }

    public function show($fig)
    {
    $price                                                      = Price::where('figure',$fig)->first();
    return $price;
    }

     public function api()
    {
    $prices                                                     = Price::all();
    return response()->json($prices, 201);
    }

    public function isAlreadyExist($fig)
    {
    $priceLength = Price::where('figure',(float)$fig)->count();
    if($priceLength  == 0) return 0;return 1;
    }
}
