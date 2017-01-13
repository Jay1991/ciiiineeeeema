<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateSalesTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        //
         Schema::create('sales', function (Blueprint $table) 
        {
            $table->bigIncrements('id');
            $table->integer('receipt_id')->default(0);
            $table->integer('total_selling')->default(0);
            $table->integer('total_buying')->default(0);
            $table->integer('quantity')->default(0);
            $table->integer('item_id')->default(0);
            $table->integer('user_id')->default(0);
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
        Schema::drop('sales');

    }
}
