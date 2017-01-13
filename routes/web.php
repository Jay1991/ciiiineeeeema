<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| This file is where you may define all of the routes that are handled
| by your application. Just tell Laravel the URIs it should respond
| to using a Closure or controller method. Build something great!
|
*/

use App\Sale;
use App\SeatTemp;
use App\Setting;
// use DB;


Auth::routes();

Route::group(['middleware' => 'auth'], function()
{

	Route::get('/','AppController@index');
	Route::get('home','HomeController@index');

	Route::resource('movies', 'MovieController');
	Route::post('movies/add','MovieController@add');
	Route::post('movies/seller','MovieController@seller');
	Route::post('api/movies','MovieController@api');
	Route::post('movies/{id}/update-avatar','MovieController@updateAvatar');

	Route::resource('dates', 'DateController');
	Route::post('api/dates','DateController@api');
	Route::post('dates/ask','DateController@ask');

	Route::resource('date-user', 'DateUserController');
	Route::post('api/date-user','DateUserController@api');
	Route::post('api/date-user/lg','DateUserController@apilg');
	Route::post('date-user/{id}/price','DateUserController@price');
	Route::post('date-user/listen','DateUserController@listen');


	Route::resource('users', 'UserController');
	Route::post('users/auth','UserController@auth');
	Route::post('users/{id}/update-avatar','UserController@updateAvatar');
	Route::post('api/users','UserController@api');


	Route::resource('times', 'TimeController');
	Route::post('api/times','TimeController@api');

	Route::resource('seats', 'SeatController');
	Route::post('api/seats','SeatController@api');



	Route::resource('screens', 'ScreenController');
	Route::post('screens/new','ScreenController@newer');
	Route::post('api/screens','ScreenController@api');

	Route::resource('screen-time', 'ScreenTimeController');
	Route::post('api/screen-time','ScreenTimeController@api');
	Route::post('api/screen-time/lg','ScreenTimeController@apilg');

	Route::resource('dashboard', 'DashboardController');
	Route::post('api/dashboard','DashboardController@api');

	Route::resource('consessions', 'ConsessionController');
	Route::post('api/consessions','ConsessionController@api');
	Route::post('consessions/{id}/update-avatar','ConsessionController@updateAvatar');
	Route::post('consessions/{id}','ConsessionController@_put');

	Route::resource('roles', 'RoleController');
	Route::post('api/roles','RoleController@api');

	Route::resource('sale-temps', 'SaleTempController');
	Route::post('sale-temps/compute', 'SaleTempController@compute');
	Route::post('sale-temps/tables/{table_id}/item/add', 'SaleTempController@addItemTable');
	Route::post('api/sale-temps','SaleTempController@api');

	Route::resource('sales', 'SaleController');
	Route::post('api/sales','SaleController@api');


	Route::get('auth','AuthController@index');

	Route::resource('settings', 'SettingController');
	Route::post('api/settings','SettingController@api');
	Route::post('settings/{id}','SettingController@_put');


	Route::resource('receipts', 'ReceiptController');
	Route::post('receipts/{number}/print','ReceiptController@printer');
	Route::post('receipts/auth/re/print','ReceiptController@rePrint');
	Route::post('api/receipts','ReceiptController@api');

	Route::resource('auth-times', 'AuthTimeController');
	Route::post('api/auth-times','AuthTimeController@api');
	Route::post('api/auth-times/lg','AuthTimeController@apilg');
	Route::post('auth-times/reports/time','AuthTimeController@report');


	Route::resource('rows', 'RowController');
	Route::post('api/rows','RowController@api');

	Route::resource('reports', 'ReportController');
	Route::post('reports/date-range','ReportController@dateRange');
	Route::post('api/reports','ReportController@api');

	Route::resource('parental-guidances', 'ParentalGuidanceController');
	Route::post('api/parental-guidances','ParentalGuidanceController@api');

	Route::resource('directors', 'DirectorController');
	Route::post('api/directors','DirectorController@api');

	Route::resource('seat-temps', 'SeatTempController');
    Route::get('seat-temps/{flag}/{time_id}', 'SeatTempController@selected');
	Route::post('seat-temps/remove','SeatTempController@remove');
	Route::post('seat-temps/compute','SeatTempController@compute');
	Route::post('seat-temps/temp/booked','SeatTempController@booked');
	Route::post('seat-temps/{id}/un-book','SeatTempController@unBook');
	Route::post('seat-temps/{id}/confirm-book','SeatTempController@confirmBook');
	Route::post('api/seat-temps','SeatTempController@api');
	Route::post('api/seat-temps/lg','SeatTempController@apilg');


	Route::resource('prices', 'PriceController');
	Route::post('api/prices','PriceController@api');


	Route::resource('sale-seats', 'SaleSeatController');
	Route::post('api/sale-seats','SaleSeatController@api');

	Route::resource('items', 'ItemController');
	Route::post('api/items','ItemController@api');
	Route::post('items/{id}/update-avatar','ItemController@updateAvatar');

	Route::resource('item-types', 'ItemTypeController');
	Route::post('api/item-types','ItemTypeController@api');

	Route::resource('tables', 'TableController');
	Route::post('api/tables','TableController@api');

	Route::resource('inventories', 'InventoryController');
	Route::post('api/inventories','InventoryController@api');

	Route::resource('printers', 'PrinterController');
	Route::post('api/printers','PrinterController@api');






});

Route::get('/settings', function(){

	$settings = Setting::all();

	return response()->json($settings, 201);


});

Route::get('/testing', function(){


// $date = date('Y-m-d', strtotime(str_replace('-', '/', date("Y-m-d"))));
// $sales = Sale::where(\DB::raw('DATE(created_at)'),'=', $date)->with('item')
// 				->with('user')->get();

// $temp=SeatTemp::with('seat')->with('time')->with('price')->with('row')->get();
// $temp=SeatTemp::all();
	$temp = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

$settings = Setting::all();


// dd($temp);

// return view('datareport')->with('reports', $temp)->with('setting', $settings);
// return view('reports.report')->with('reports', $temp)->with('setting', $settings);
return view('sales.movies.moviereport')->with('reports', $temp)->with('setting', $settings);


});

Route::get('/today_movie_report', function(){

	$todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
    $year = Carbon::now()->year;
	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();
	// dd($lastmonth);

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();

	$temps = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			// today
			 ->whereDate('seat_temps.updated_at', $todayDate)
			// yesterday
			// ->whereDate('seat_temps.updated_at', $yesterday)
			// last seven days
			// ->where('seat_temps.updated_at', '>=', $lastSevenDays)
			// last thirty days
			// ->where('seat_temps.updated_at', '>=', $lastThirtyDays)
			// this month
			->whereMonth('seat_temps.updated_at', '=', $month)
            ->whereYear('seat_temps.updated_at', '=', $year)
			// last month
			// ->whereMonth('seat_temps.updated_at', '=', $lastmonth)



			// last month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->subMonth())
			// this month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->startOfMonth())

			->where('seat_temps.flag', '=', 1)
			->where('seat_temps.is_complementary', '=', 0)
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

			$settings = Setting::all()->toArray();

			foreach ($temps as $temp) {
			 $temp->movie_sales = [
				 'setting' => $settings,
			 ];
		 }

	 return response()->json($temps, 200);



});




Route::get('/yesterday_movie_report', function(){

	$todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();
	// dd($lastmonth);

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();

	$temps = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			// today
			// ->whereDate('seat_temps.updated_at', $todayDate)
			// yesterday
			->whereDate('seat_temps.updated_at', $yesterday)
			// last seven days
			// ->where('seat_temps.updated_at', '>=', $lastSevenDays)
			// last thirty days
			// ->where('seat_temps.updated_at', '>=', $lastThirtyDays)
			// this month
			// ->whereMonth('seat_temps.updated_at', '=', $month)
			// last month
			// ->whereMonth('seat_temps.updated_at', '=', $lastmonth)



			// last month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->subMonth())
			// this month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->startOfMonth())

			->where('seat_temps.flag', '=', 1)
			->where('seat_temps.is_complementary', '=', 0)
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

			$settings = Setting::all()->toArray();

			foreach ($temps as $temp) {
			 $temp->movie_sales = [
				 'setting' => $settings,
			 ];
		 }

	 return response()->json($temps, 200);

});


Route::get('/sevendays_movie_report', function(){

	$todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();
	// dd($lastmonth);

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();

	$temps = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			// today
			// ->whereDate('seat_temps.updated_at', $todayDate)
			// yesterday
			// ->whereDate('seat_temps.updated_at', $yesterday)
			// last seven days
			->where('seat_temps.updated_at', '>=', $lastSevenDays)
			// last thirty days
			// ->where('seat_temps.updated_at', '>=', $lastThirtyDays)
			// this month
			// ->whereMonth('seat_temps.updated_at', '=', $month)
			// last month
			// ->whereMonth('seat_temps.updated_at', '=', $lastmonth)



			// last month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->subMonth())
			// this month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->startOfMonth())

			->where('seat_temps.flag', '=', 1)
			->where('seat_temps.is_complementary', '=', 0)
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

			$settings = Setting::all()->toArray();

			foreach ($temps as $temp) {
			 $temp->movie_sales = [
				 'setting' => $settings,
			 ];
		 }

	 return response()->json($temps, 200);

});

Route::get('/thirtydays_movie_report', function(){

	$todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();
	// dd($lastmonth);

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();

	$temps = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			// today
			// ->whereDate('seat_temps.updated_at', $todayDate)
			// yesterday
			// ->whereDate('seat_temps.updated_at', $yesterday)
			// last seven days
			// ->where('seat_temps.updated_at', '>=', $lastSevenDays)
			// last thirty days
			->where('seat_temps.updated_at', '>=', $lastThirtyDays)
			// this month
			// ->whereMonth('seat_temps.updated_at', '=', $month)
			// last month
			// ->whereMonth('seat_temps.updated_at', '=', $lastmonth)



			// last month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->subMonth())
			// this month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->startOfMonth())

			->where('seat_temps.flag', '=', 1)
			->where('seat_temps.is_complementary', '=', 0)
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

			$settings = Setting::all()->toArray();

			foreach ($temps as $temp) {
			 $temp->movie_sales = [
				 'setting' => $settings,
			 ];
		 }

	 return response()->json($temps, 200);

});



Route::get('/lastmonth_movie_report', function(){

	$todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
    $year = Carbon::now()->year;

	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();
	// dd($lastmonth);

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();

	$temps = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			// today
			// ->whereDate('seat_temps.updated_at', $todayDate)
			// yesterday
			// ->whereDate('seat_temps.updated_at', $yesterday)
			// last seven days
			// ->where('seat_temps.updated_at', '>=', $lastSevenDays)
			// last thirty days
			// ->where('seat_temps.updated_at', '>=', $lastThirtyDays)
			// this month
//            ->whereMonth('seat_temps.updated_at', '=', $month)
			// last month
			->whereMonth('seat_temps.updated_at', '=', $lastmonth)
//            ->whereYear('seat_temps.updated_at', '=', $year)

			// last month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->subMonth())
			// this month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->startOfMonth())

			->where('seat_temps.flag', '=', 1)
			->where('seat_temps.is_complementary', '=', 0)
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

			$settings = Setting::all()->toArray();

			foreach ($temps as $temp) {
			 $temp->movie_sales = [
				 'setting' => $settings,
			 ];
		 }

	 return response()->json($temps, 200);

});

Route::get('/thismonth_movie_report', function(){

	$todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
    $year = Carbon::now()->year;
    
	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();
	// dd($lastmonth);

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();

	$temps = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			// today
			// ->whereDate('seat_temps.updated_at', $todayDate)
			// yesterday
			// ->whereDate('seat_temps.updated_at', $yesterday)
			// last seven days
			// ->where('seat_temps.updated_at', '>=', $lastSevenDays)
			// last thirty days
//			->where('seat_temps.updated_at', '>=', $lastThirtyDays)
			// this month
			->whereMonth('seat_temps.updated_at', '=', $month)
			// last month
			// ->whereMonth('seat_temps.updated_at', '=', $lastmonth)
//            ->whereYear('seat_temps.updated_at', '=', $year)




			// last month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->subMonth())
			// this month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->startOfMonth())

			->where('seat_temps.flag', '=', 1)
			->where('seat_temps.is_complementary', '=', 0)
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

			$settings = Setting::all()->toArray();

			foreach ($temps as $temp) {
			 $temp->movie_sales = [
				 'setting' => $settings,
			 ];
		 }

	 return response()->json($temps, 200);

});

Route::get('/today_complementary_report', function(){

	$todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();
	// dd($lastmonth);

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();

	$temps = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			// today
            ->whereDate('seat_temps.updated_at', $todayDate)
			// yesterday
			// ->whereDate('seat_temps.updated_at', $yesterday)
			// last seven days
			// ->where('seat_temps.updated_at', '>=', $lastSevenDays)
			// last thirty days
			// ->where('seat_temps.updated_at', '>=', $lastThirtyDays)
			// this month
//			->whereMonth('seat_temps.updated_at', '=', $month)
			// last month
			// ->whereMonth('seat_temps.updated_at', '=', $lastmonth)



			// last month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->subMonth())
			// this month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->startOfMonth())

			->where('seat_temps.flag', '=', 1)
			->where('seat_temps.is_complementary', '=',1)
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

			$settings = Setting::all()->toArray();

			foreach ($temps as $temp) {
			 $temp->movie_sales = [
				 'setting' => $settings,
			 ];
		 }

	 return response()->json($temps, 200);



});

Route::get('/yesterday_complementary_report', function(){

	$todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();
	// dd($lastmonth);

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();

	$temps = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			// today
//            ->whereDate('seat_temps.updated_at', $todayDate)
			// yesterday
			 ->whereDate('seat_temps.updated_at', $yesterday)
			// last seven days
			// ->where('seat_temps.updated_at', '>=', $lastSevenDays)
			// last thirty days
			// ->where('seat_temps.updated_at', '>=', $lastThirtyDays)
			// this month
//			->whereMonth('seat_temps.updated_at', '=', $month)
			// last month
			// ->whereMonth('seat_temps.updated_at', '=', $lastmonth)



			// last month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->subMonth())
			// this month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->startOfMonth())

			->where('seat_temps.flag', '=', 1)
			->where('seat_temps.is_complementary', '=',1)
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

			$settings = Setting::all()->toArray();

			foreach ($temps as $temp) {
			 $temp->movie_sales = [
				 'setting' => $settings,
			 ];
		 }

	 return response()->json($temps, 200);



});

Route::get('/seven_complementary_report', function(){

	$todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();
	// dd($lastmonth);

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();

	$temps = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			// today
//            ->whereDate('seat_temps.updated_at', $todayDate)
			// yesterday
			// ->whereDate('seat_temps.updated_at', $yesterday)
			// last seven days
			 ->where('seat_temps.updated_at', '>=', $lastSevenDays)
			// last thirty days
			// ->where('seat_temps.updated_at', '>=', $lastThirtyDays)
			// this month
//			->whereMonth('seat_temps.updated_at', '=', $month)
			// last month
			// ->whereMonth('seat_temps.updated_at', '=', $lastmonth)



			// last month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->subMonth())
			// this month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->startOfMonth())

			->where('seat_temps.flag', '=', 1)
			->where('seat_temps.is_complementary', '=',1)
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

			$settings = Setting::all()->toArray();

			foreach ($temps as $temp) {
			 $temp->movie_sales = [
				 'setting' => $settings,
			 ];
		 }

	 return response()->json($temps, 200);



});

Route::get('/thirty_complementary_report', function(){

	$todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();
	// dd($lastmonth);

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();

	$temps = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			// today
//            ->whereDate('seat_temps.updated_at', $todayDate)
			// yesterday
			// ->whereDate('seat_temps.updated_at', $yesterday)
			// last seven days
			// ->where('seat_temps.updated_at', '>=', $lastSevenDays)
			// last thirty days
			 ->where('seat_temps.updated_at', '>=', $lastThirtyDays)
			// this month
//			->whereMonth('seat_temps.updated_at', '=', $month)
			// last month
			// ->whereMonth('seat_temps.updated_at', '=', $lastmonth)



			// last month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->subMonth())
			// this month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->startOfMonth())

			->where('seat_temps.flag', '=', 1)
			->where('seat_temps.is_complementary', '=',1)
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

			$settings = Setting::all()->toArray();

			foreach ($temps as $temp) {
			 $temp->movie_sales = [
				 'setting' => $settings,
			 ];
		 }

	 return response()->json($temps, 200);



});


Route::get('/thismonth_complementary_report', function(){

	$todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();
	// dd($lastmonth);

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();

	$temps = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			// today
//            ->whereDate('seat_temps.updated_at', $todayDate)
			// yesterday
			// ->whereDate('seat_temps.updated_at', $yesterday)
			// last seven days
			// ->where('seat_temps.updated_at', '>=', $lastSevenDays)
			// last thirty days
			// ->where('seat_temps.updated_at', '>=', $lastThirtyDays)
			// this month
			->whereMonth('seat_temps.updated_at', '=', $month)
			// last month
			// ->whereMonth('seat_temps.updated_at', '=', $lastmonth)



			// last month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->subMonth())
			// this month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->startOfMonth())

			->where('seat_temps.flag', '=', 1)
			->where('seat_temps.is_complementary', '=',1)
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

			$settings = Setting::all()->toArray();

			foreach ($temps as $temp) {
			 $temp->movie_sales = [
				 'setting' => $settings,
			 ];
		 }

	 return response()->json($temps, 200);

});

Route::get('/lastmonth_complementary_report', function(){

	$todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();
	// dd($lastmonth);

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();

	$temps = \DB::table('seat_temps')
			->join('seats', 'seats.id', '=', 'seat_temps.seat_id')
			->join('items', 'items.id', '=', 'seat_temps.movie_id')
			->join('times', 'times.id', '=', 'seat_temps.timer_id')
			->join('dates', 'dates.id', '=', 'seat_temps.date_id')
			->join('prices', 'prices.id', '=', 'seat_temps.price_id')
			->selectRaw('*, count(seat_temps.id) as seatNo')
			// today
//            ->whereDate('seat_temps.updated_at', $todayDate)
			// yesterday
			// ->whereDate('seat_temps.updated_at', $yesterday)
			// last seven days
			// ->where('seat_temps.updated_at', '>=', $lastSevenDays)
			// last thirty days
			// ->where('seat_temps.updated_at', '>=', $lastThirtyDays)
			// this month
//			->whereMonth('seat_temps.updated_at', '=', $month)
			// last month
			 ->whereMonth('seat_temps.updated_at', '=', $lastmonth)



			// last month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->subMonth())
			// this month
			// ->where('seat_temps.created_at', '>=', Carbon::now()->startOfMonth())

			->where('seat_temps.flag', '=', 1)
			->where('seat_temps.is_complementary', '=',1)
			->groupBy('seat_temps.movie_id', 'seat_temps.date_id', 'seat_temps.timer_id')
			->get();

			$settings = Setting::all()->toArray();

			foreach ($temps as $temp) {
			 $temp->movie_sales = [
				 'setting' => $settings,
			 ];
		 }

	 return response()->json($temps, 200);



});




Route::get('/concession_today_report', function(){

    $todayDate = Carbon::now()->toDateString();

    $sales  = Sale::whereDate('created_at', $todayDate)->get();
    return response()->json($sales, 201);
});

Route::get('/concession_yesterday_report', function(){

    $todayDate = Carbon::now()->toDateString();

	$todayParsed = Carbon::parse($todayDate)->subDay();
    $yesterday = $todayParsed->toDateString();

    $sales  = Sale::whereDate('created_at', $yesterday)->get();
    return response()->json($sales, 201);
});

Route::get('/concession_seven_report', function(){

    $todayDate = Carbon::now()->toDateString();

    $toSevenDays = Carbon::parse($todayDate)->subDays(7);

    $lastSevenDays = $toSevenDays->toDateString();

    $sales= Sale::where('created_at','>=', $lastSevenDays)->get();


    return response()->json($sales, 201);
});

Route::get('/concession_thirty_report', function(){

    $todayDate = Carbon::now()->toDateString();
    $lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
    $sales= Sale::where('created_at','>=',$lastThirtyDays)->get();
    return response()->json($sales, 201);
});

Route::get('/concession_thismonth_report', function(){

    $month = Carbon::now()->month;

    $sales= Sale::whereMonth('created_at','=', $month)->get();
    return response()->json($sales, 201);
});

Route::get('/concession_lastmonth_report', function(){

    $todayDate = Carbon::now()->toDateString();
    $lastmonth = Carbon::parse($todayDate)->subMonth()->month;


    $sales= Sale::whereMonth('created_at','=', $lastmonth)->get();
    return response()->json($sales, 201);
});

Route::get('/excel/movietoday', 'ExportReportController@movietoday');
Route::get('/excel/movieyesterday', 'ExportReportController@movieyesterday');
Route::get('/excel/movielastseven', 'ExportReportController@movielastseven');
Route::get('/excel/movielastthirty', 'ExportReportController@movielastthirty');
Route::get('/excel/moviethismonth', 'ExportReportController@moviethismonth');
Route::get('/excel/movielastmonth', 'ExportReportController@movielastmonth');

Route::get('/excel/complementarytoday', 'ExportReportController@complementarytoday');
Route::get('/excel/complementaryyesterday', 'ExportReportController@complementaryyesterday');
Route::get('/excel/complementarylastseven', 'ExportReportController@complementarylastseven');
Route::get('/excel/complementarylastthirty', 'ExportReportController@complementarylastthirty');
Route::get('/excel/complementarythismonth', 'ExportReportController@complementarythismonth');
Route::get('/excel/complementarylastmonth', 'ExportReportController@complementarylastmonth');

Route::get('/excel/ToDay', 'ExportReportController@consessiontoday');
Route::get('/excel/Yesterday', 'ExportReportController@consessionyesterday');
Route::get('/excel/Last7Days', 'ExportReportController@consessionlastseven');
Route::get('/excel/Last30Days', 'ExportReportController@consessionlastthirty');
Route::get('/excel/ThisMonth', 'ExportReportController@consessionthismonth');
Route::get('/excel/LastMonth', 'ExportReportController@consessionlastmonth');
