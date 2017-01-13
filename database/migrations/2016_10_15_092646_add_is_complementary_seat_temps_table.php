<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class AddIsComplementarySeatTempsTable extends Migration
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
            $table->boolean('is_complementary')->default(false)->after('id');

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
            $table->dropColumn('is_complementary');
            
        }); 
    }
}
