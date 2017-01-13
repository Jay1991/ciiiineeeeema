<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use App\Http\Requests;
use App\Inventory;
class InventoryController extends Controller
{
    //
    public function index()
    {
    return $this->store(67,67);
    }
    public function store($quantity,$item_id,$remarks)
    {
    // process inventory
    if(!empty($quantity))
	{
		$inventories                             = new Inventory;
		$inventories->item_id                    = $item_id;
		$inventories->user_id                    = Auth::user()->id;
		$inventories->in_out_qty                 = $quantity;
		$inventories->remarks                    = $remarks;
		$inventories->save();
	}

    }

    public function update()
    {
	    

    }
}
