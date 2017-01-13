<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Seat extends Model
{
    //

      public function row()
    {
        return $this->belongsTo('App\Row','row_id');
    }
}
