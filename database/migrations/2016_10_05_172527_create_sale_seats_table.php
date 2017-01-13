<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateSaleSeatsTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        //
         Schema::create('sale_seats', function (Blueprint $table) 
        {
            $table->increments('id');
            $table->integer('seat_id')->default(0);
            $table->integer('user_id')->default(0);
            $table->integer('time_id')->default(0);
            $table->boolean('status')->default(false);
            $table->timestamps();
        }); 
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        //
        Schema::drop('sale_seats');
        
    }
}
