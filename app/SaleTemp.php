<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class SaleTemp extends Model
{
    //
    public function user()
    {
        return $this->belongsTo('App\User');
    }

    public function item()
    {
        return $this->belongsTo('App\Item');
    }

    public function table()
    {
    return $this->belongsTo('App\Table');
    }
}
