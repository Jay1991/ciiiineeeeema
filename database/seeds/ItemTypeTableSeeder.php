<?php

use Illuminate\Database\Seeder;

class ItemTypeTableSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        //
        DB::table('item_types')->insert(
         	[
	            [
	                'name'                  =>'Consessions',
	            ],
	            [
	                'name'                  =>'Movie'
	            ]
            ]
        );
    }
}
