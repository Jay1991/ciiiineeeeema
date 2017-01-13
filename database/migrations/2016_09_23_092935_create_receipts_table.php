<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateReceiptsTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        //
         Schema::create('receipts', function (Blueprint $table) 
        {
            $table->increments('id');
            $table->string('number')->nullable();
            $table->boolean('status')->default(false);
            $table->double('VAT')->default(0);
            $table->double('discount')->default(0);
            $table->double('sub_total')->default(0);
            $table->double('total')->default(0);
            $table->double('paid')->default(0);
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
        Schema::drop('receipts');
        
    }
}
