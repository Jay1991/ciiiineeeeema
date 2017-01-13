<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class AuthTime extends Model
{
    //
     public function date()
    {
        return $this->belongsTo('App\DateUser','date_id');
    }

     public function time()
    {
        return $this->belongsTo('App\Time','time_id');
    }

    public function temp()
    {
    return $this->hasMany('App\SeatTemp');
    }
}
