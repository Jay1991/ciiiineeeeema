<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class AddCinemaAttributesSalesTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        //
         Schema::table('sales', function ($table) 
        {
            $table->integer('time_id')->default(0)->after('id');
            $table->integer('seat_id')->default(0)->after('id');
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
         Schema::table('sales', function ($table) 
        {
            $table->dropColumn('time_id');
            $table->dropColumn('seat_id');
        }); 
    }
}
