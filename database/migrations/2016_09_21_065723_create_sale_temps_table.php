<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateSaleTempsTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        //
         Schema::create('sale_temps', function (Blueprint $table) 
        {
            $table->increments('id');
            $table->integer('user_id')->default(0);
            $table->integer('item_id')->default(0);
            $table->integer('quantity')->default(0);
            $table->double('total_selling')->default(0);
            $table->double('total_buying')->default(0);
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
        Schema::drop('sale_temps');
        
    }
}
