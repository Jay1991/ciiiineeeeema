<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\ItemType;
class ItemTypeController extends Controller
{
    //
    public function index()
    {
    return $this->api();
    }

     public function show($item)
    {
    $type                              = ItemType::where('name', 'like', '%' . $item . '%')->first();
    return $type;
    }

    public function api()
    {
    $types                             = ItemType::all();
    return response()->json($types,201);
    }
}
