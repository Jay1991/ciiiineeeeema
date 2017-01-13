<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class AddCodeBarcodeIsbnSizeItems extends Migration
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
            $table->string('code')->nullable()->after('id');
            $table->string('barcode')->nullable()->after('id');
            $table->string('isbn')->nullable()->after('id');
            $table->string('size')->nullable()->after('id');
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
            $table->dropColumn('code');
            $table->dropColumn('barcode');
            $table->dropColumn('isbn');
            $table->dropColumn('size');
            
        }); 
    }
}
