<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class DistributorPercentageSeatTempsTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        //
         Schema::table('seat_temps', function ($table) 
        {
            $table->double('distributor_percentage')->default(0)->after('id');

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
         Schema::table('seat_temps', function ($table) 
        {
            $table->dropColumn('distributor_percentage');
            
        }); 
    }
}
