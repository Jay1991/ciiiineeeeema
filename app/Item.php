<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Item extends Model
{
    //
    public function type()
    {
        return $this->belongsTo('App\ItemType', 'item_type_id');
    }

    public function director()
    {
        return $this->belongsTo('App\Director', 'director_id');
    }
    public function guidance()
    {
        return $this->belongsTo('App\ParentalGuidance', 'parental_guidance_id');
    }

    public function date()
    {
        return $this->hasMany('App\DateUser','movie_id');
    }
}
