<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class AddDirectorParentalItems extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        //
         Schema::table('items', function ($table) 
        {
            $table->integer('director_id')->default(0);
            $table->integer('parental_guidance_id')->default(0);
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
        Schema::table('items', function ($table) 
        {
            $table->dropColumn('parental_guidance_id');
            $table->dropColumn('director_id');
        });

        
    }
}
