<?php

use Illuminate\Database\Seeder;

class DatabaseSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        $this->call(UserTableSeeder::class);
        $this->call(ItemTypeTableSeeder::class);
        $this->call(RoleTableSeeder::class);
        $this->call(ParentalGuidanceSeederTable::class);
        $this->call(SettingTableSeeder::class);
    }
}
