<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class ItemType extends Model
{
    //
    public function item()
    {
        return $this->hasMany('App\Item', 'item_type_id', 'id');
    }
}
