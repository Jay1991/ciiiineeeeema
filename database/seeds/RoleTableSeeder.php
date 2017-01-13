<?php

use Illuminate\Database\Seeder;

class RoleTableSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        //
        DB::table('roles')->insert(
         	[
	            [
	                'name'                          =>'Admin',
	                'display_name'                  =>'Adminstrator',
	            ],
                [
                    'name'                          =>'Cashier',
                    'display_name'                  =>'Cashier',
                ],
                [
                    'name'                          =>'Consession',
                    'display_name'                  =>'Consession',
                ],
                [
                    'name'                          =>'Movie',
                    'display_name'                  =>'Movie',
                ],
                [
                    'name'                          =>'Sales Agent',
                    'display_name'                  =>'Sales Agent',
                ]

	            
            ]
        );
    }
}
