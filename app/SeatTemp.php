<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class SeatTemp extends Model
{
    //
     public function seat()
    {
        return $this->belongsTo('App\Seat','seat_id');
    }

     public function user()
    {
        return $this->belongsTo('App\User','user_id');
    }

     public function time()
    {
        return $this->belongsTo('App\AuthTime','time_id');
    }

     public function timer()
    {
        return $this->belongsTo('App\Time','timer_id');
    }

    public function date()
    {
        return $this->belongsTo('App\Date','date_id');
    }

    public function movie()
    {
        return $this->belongsTo('App\Item','movie_id');
    }

    public function row()
    {
    return $this->belongsTo('App\Row','row_id');
    }

    public function price()
    {
    return $this->belongsTo('App\Price','price_id');
    }

    

}
