<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateItemsTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        //
         Schema::create('items', function (Blueprint $table) 
        {
            $table->increments('id');
            $table->string('name')->nullable();
            $table->integer('item_type_id')->nullable();
            $table->string('avatar')->nullable();
            $table->double('selling_price')->default(0);
            $table->double('buying_price')->default(0);
            $table->boolean('vat_inclusive')->default(true);
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
        Schema::drop('items');
        
    }
}
