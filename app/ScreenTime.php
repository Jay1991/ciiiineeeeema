<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class ScreenTime extends Model
{
    //
    protected $table = 'screen_time';

    public function screen()
    {
        return $this->belongsTo('App\Screen','screen_id');
    }

    public function time()
    {
        return $this->belongsTo('App\Time','
        	time_id');
    }
}
