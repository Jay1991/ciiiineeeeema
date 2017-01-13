<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Row extends Model
{
    //
     public function screen()
    {
        return $this->belongsTo('App\Screen');
    }
}
