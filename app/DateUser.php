<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class DateUser extends Model
{
    //
    protected $table = 'date_user';

    public function date()
    {
        return $this->belongsTo('App\Date','date_id');
    }

    public function user()
    {
        return $this->belongsTo('App\User','user_id');
    }

     public function price()
    {
        return $this->belongsTo('App\Price','price_id');
    }

     public function movie()
    {
        return $this->belongsTo('App\Item','movie_id');
    }
}
