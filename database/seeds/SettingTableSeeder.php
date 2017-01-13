<?php

use Illuminate\Database\Seeder;

class SettingTableSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        //
         DB::table('settings')->insert
        (
            [
	            [
	                'app_name'                  =>'Cinema',
	                'languange'                 =>'en',
	                'logo'                      =>'',
	                'email'                     =>'adimin@system.com',
	                'phone'                     =>'077',
	                'currency_symbol'           =>'$',
	                'location'                  =>'Dar es salaam',
	                'vat_percentage'            => 18,
	                'discount_percentage'       => 0,
	                'discount_amount'           => 0,
	            ]
            ]
        );
    }
}
