<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\Table;
class TableController extends Controller
{
    //
     public function api()
    {
	$tables                                         = Table::orderBy('created_at','desc')->get();
	return response()->json($tables, 201);
    }
}
