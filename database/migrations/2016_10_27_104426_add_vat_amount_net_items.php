<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class AddVatAmountNetItems extends Migration
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
            $table->double('vat_amount')->default(0)->after('id');
            $table->string('net')->nullable()->after('id');
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
            $table->dropColumn('vat_amount');
            $table->dropColumn('net');
        }); 
    }
}
