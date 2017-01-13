<?php

use Illuminate\Database\Seeder;

class ParentalGuidanceSeederTable extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        //
        DB::table('parental_guidances')->insert(
         	[
	            [
	                'name'                          =>'G',
	            ],
                [
                    'name'                          =>'PG',
                ],
                [
                    'name'                          =>'PG-13',
                ],
                [
                    'name'                          =>'PG-18+',
                ]

	            
            ]
        );
    }
}
