<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class AddVrnTinUinAddressSettingTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        //
         Schema::table('settings', function ($table) 
        {
            $table->string('tin')->nullable()->after('id');
            $table->string('vrn')->nullable()->after('id');
            $table->string('uin')->nullable()->after('id');
            $table->string('postal_address')->nullable()->after('id');

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
        Schema::table('settings', function ($table) 
        {
            $table->dropColumn('tin');
            $table->dropColumn('vrn');
            $table->dropColumn('uin');
            $table->dropColumn('postal_address');
            
        }); 
    }
}
