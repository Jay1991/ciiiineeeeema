<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateSettingsTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        //
         Schema::create('settings', function (Blueprint $table) 
        {
            $table->increments('id');
            $table->string('app_name')->nullable();
            $table->string('languange', 5)->default('en');
            $table->string('logo')->nullable();
            $table->string('email')->nullable();
            $table->string('phone')->nullable();
            $table->string('currency_symbol')->nullable();
            $table->text('location')->nullable();
            $table->double('vat_percentage')->default(0);
            $table->double('discount_percentage')->default(0);
            $table->double('discount_amount')->default(0);
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
        Schema::drop('settings');
        
    }
}
