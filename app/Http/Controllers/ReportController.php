<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use \Auth, \Redirect, \Validator, \Input, \Session, \Response, \Hash, \DB;
use App\Sale;
use App\SeatTemp;
use App\Setting;
use Carbon;
use Excel;
class ReportController extends Controller
{
    public function excel(){
        
    Excel::create('Movie Report', function($excel){
    $excel->sheet('This month', function($sheet){
                
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

	$reports = DB::table('seat_temps')
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
			->whereMonth('seat_temps.updated_at', '=', $month)
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

			$settings = Setting::all()->pluck('vat_percentage');
            $vat =  $settings[0];
//            $reports = Sale::all();

                
            foreach($reports as $report){
                    $data[] = array(
                        
                        $report->date,
                        $report->distributor,
                        $report->name,
                        $report->starting_at,
                        $report->seatNo,
                        $report->figure,
                        $report->seatNo*$report->figure,
                        ($report->seatNo*$report->figure)*($vat/100),
                        $report->with_draw_tax,
                        $report->discount_amount,
                        ($report->seatNo*$report->figure)-($report->seatNo*$report->figure)*($vat/100),
                        $report->distributor_percentage,
                        (($report->seatNo*$report->figure)-($report->seatNo*$report->figure)*($vat/100))*($report->distributor_percentage)/100,
                        $report->seatNo*($report->final_amount),
                        
                        
                        

                    );
                }
                $sheet->fromArray($data, null, 'A1', false, false);
                $headings = array('Show Date', 'Distributor', 'Movie Name', 'Show Time', 'No Of Tkts','Price/Tkt', 'Amt(Incl Tax)', 'Tax', 'WHT', 'Discount', 'Net Amt', 'Dist%', 'Dist Comm', 'F/A');                
													
                $sheet->prependRow(1, $headings);
                
                
                 $totalTks = 0;

                    foreach($reports as $report){
                      $totalTks = $totalTks + $report->seatNo;

                    }
                
                    $Amt = 0;

                    foreach($reports as $report){

                    $amt = $report->seatNo*$report->figure;

                      $Amt = $Amt + $amt;

                    }                

                    $vatPer = $vat/100;

                    $sumTax = 0;
                    foreach($reports as $report){

                     $salePerSeat = $report->seatNo*$report->figure;
                     $salePerSeatTax= $salePerSeat*$vatPer;
                     $sumTax += $salePerSeatTax;


                    }
                
                    $sumNet = 0;

                    foreach($reports as $report){

                    $amt = $report->seatNo*$report->figure;

                    $sumNet += (1 - $vatPer)*$amt;


                    }
                
                    $totalDisCom = 0;

                    foreach($reports as $report){


                      $disCom = floor((($report->seatNo*$report->figure)*(1-$vatPer))*($report->distributor_percentage)/100);


                      $totalDisCom += $disCom;


                    }
                
                $sheet->appendRow(array(
                    'Total', '', '', '', $totalTks, '', $Amt, $sumTax, '', '', $sumNet,'', $totalDisCom, ''
                ));
                
            });
            
        })->export('xls');
    }
    //
     public function index()
    {
     return 4;
    }
    public function store(Request $request)
    {

    if((int)$request->Input('flag')               == 1)
    {
    $date                                         = $this->dateFormat(date('Y-m-d'));
    return $this->toDay($date);
    }

    }

     public function toDay()
    {
         
    $date                                         = date('Y-m-d', strtotime(str_replace('-', '/', date("Y-m-d"))));
    // $sales                                        = Sale::where(DB::raw('DATE(created_at)'),'=', $date)->with('item')->with('user')->get();
    $todayDate = Carbon::now()->toDateString();

    $todayParsed = Carbon::parse($todayDate)->subDay();
    $yesterday = $todayParsed->toDateString();

//    $sales  = Sale::whereDate('created_at', $todayDate)->with('item')->with('user')->get();
         
    $sales= Sale::whereDate('created_at', $todayDate)  
                    ->with('item')
                    ->with('user')			
                    ->selectRaw('*, sum(quantity) as totalQuantity')
                    ->groupBy('item_id')
                    ->get(); 

    return response()->json($sales, 201);

    }

    public function toDayX()
    {
    $date                                         = date('Y-m-d', strtotime(str_replace('-', '/', date("Y-m-d"))));
    $sales                                        = SeatTemp::where(DB::raw('DATE(created_at)'),'=', $date)
                                                  ->where('flag', 1)
                                                  ->with('user')
                                                  ->with('time')
                                                  ->with('seat')
                                                  ->with('date')
                                                  ->with('movie')
                                                  ->with('timer')
                                                  ->with('row')
                                                  ->with('price')
                                                  ->get();
    return response()->json($sales, 201);

    }


     public function yesterday()
    {

    // $date                                         = date_create(date("Y-m-d"));
    // date_sub($date,date_interval_create_from_date_string("1 days"));
    // $date                                         =  date_format($date,"Y-m-d");
    //
    // $sales                                        = Sale::where(DB::raw('DATE(created_at)'),'=', $date)->with('item')->get();

    $todayDate = Carbon::now()->toDateString();

    $todayParsed = Carbon::parse($todayDate)->subDay();
    $yesterday = $todayParsed->toDateString();

//    $sales  = Sale::whereDate('created_at', $yesterday)->with('item')->with('user')->get();
         
           
    $sales= Sale::whereDate('created_at', $yesterday)  
                    ->with('item')
                    ->with('user')			
                    ->selectRaw('*, sum(quantity) as totalQuantity')
                    ->groupBy('item_id')
                    ->get();
         
    return response()->json($sales, 201);

    }

    public function yesterdayX()
    {

    $date                                         = date_create(date("Y-m-d"));
    date_sub($date,date_interval_create_from_date_string("1 days"));
    $date                                         =  date_format($date,"Y-m-d");

    $sales                                        = SeatTemp::where(DB::raw('DATE(created_at)'),'=', $date)
                                                  ->where('flag', 1)
                                                  ->with('user')
                                                  ->with('time')
                                                  ->with('seat')
                                                  ->with('date')
                                                  ->with('movie')
                                                  ->with('timer')
                                                  ->with('row')
                                                  ->with('price')
                                                  ->get();
    return response()->json($sales, 201);

    }



     public function last7days()
    {

    // $startDate                                    = date_create(date("Y-m-d"));
    // date_sub($startDate,date_interval_create_from_date_string("7 days"));
    // $startDate                                    = date_format($startDate,"Y-m-d");
    // $endDate                                      = date_create(date("Y-m-d"));
    // date_sub($endDate,date_interval_create_from_date_string("1 days"));
    // $endDate                                      = date_format($endDate,"Y-m-d");
    // $sales                                        = Sale::whereBetween(DB::raw('DATE(updated_at)'), [$startDate,$endDate])->with('item')->get();

    $todayDate = Carbon::now()->toDateString();

    $toSevenDays = Carbon::parse($todayDate)->subDays(7);

    $lastSevenDays = $toSevenDays->toDateString();

    $sales= Sale::where('created_at','>=', $lastSevenDays)  
                    ->with('item')
                    ->with('user')			
                    ->selectRaw('*, sum(quantity) as totalQuantity')
                    ->groupBy('item_id')
                    ->get();   

    return response()->json($sales, 201);
    }

     public function last7daysX()
    {

    $startDate                                    = date_create(date("Y-m-d"));
    date_sub($startDate,date_interval_create_from_date_string("7 days"));
    $startDate                                    = date_format($startDate,"Y-m-d");
    $endDate                                      = date_create(date("Y-m-d"));
    date_sub($endDate,date_interval_create_from_date_string("1 days"));
    $endDate                                      = date_format($endDate,"Y-m-d");
    $sales                                        = SeatTemp::whereBetween(DB::raw('DATE(updated_at)'), [$startDate,$endDate])
                                                  ->where('flag', 1)
                                                  ->with('user')
                                                  ->with('time')
                                                  ->with('seat')
                                                  ->with('date')
                                                  ->with('movie')
                                                  ->with('timer')
                                                  ->with('row')
                                                  ->with('price')
                                                  ->get();
    return response()->json($sales, 201);
    }


     public function last30Days()
    {

    // $startDate                                    = date_create(date("Y-m-d"));
    // date_sub($startDate,date_interval_create_from_date_string("30 days"));
    // $startDate                                    = date_format($startDate,"Y-m-d");
    // $endDate                                      = date_create(date("Y-m-d"));
    // date_sub($endDate,date_interval_create_from_date_string("1 days"));
    // $endDate                                      = date_format($endDate,"Y-m-d");
    // $sales                                        = Sale::whereBetween(DB::raw('DATE(updated_at)'), [$startDate,$endDate])->with('item')->get();

    $todayDate = Carbon::now()->toDateString();
    $lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
//    $sales= Sale::where('created_at','>=',$lastThirtyDays)->with('item')->with('user')->get();
         
     $sales= Sale::where('created_at','>=',$lastThirtyDays)  
                    ->with('item')
                    ->with('user')			
                    ->selectRaw('*, sum(quantity) as totalQuantity')
                    ->groupBy('item_id')
                    ->get();
         
    return response()->json($sales, 201);


    }

    public function last30DaysX()
    {

    $startDate                                    = date_create(date("Y-m-d"));
    date_sub($startDate,date_interval_create_from_date_string("30 days"));
    $startDate                                    = date_format($startDate,"Y-m-d");
    $endDate                                      = date_create(date("Y-m-d"));
    date_sub($endDate,date_interval_create_from_date_string("1 days"));
    $endDate                                      = date_format($endDate,"Y-m-d");
    $sales                                        = SeatTemp::whereBetween(DB::raw('DATE(updated_at)'), [$startDate,$endDate])
                                                  ->where('flag', 1)
                                                  ->with('user')
                                                  ->with('time')
                                                  ->with('seat')
                                                  ->with('date')
                                                  ->with('movie')
                                                  ->with('timer')
                                                  ->with('row')
                                                  ->with('price')
                                                  ->get();
    return response()->json($sales, 201);


    }


     public function thisMonth()
    {
    // $date = date('m');
    // $sales                                        = Sale::where(DB::raw('EXTRACT(MONTH FROM updated_at)'), $date)->with('item')->get();

    $month = Carbon::now()->month;

//    $sales= Sale::whereMonth('created_at','=', $month)->with('item')->with('user')->get();
         
    $sales= Sale::whereMonth('created_at','=', $month)  
                    ->with('item')
                    ->with('user')			
                    ->selectRaw('*, sum(quantity) as totalQuantity')
                    ->groupBy('item_id')
                    ->get();
         
    return response()->json($sales, 201);

    }

     public function thisMonthX()
    {
    $date = date('m');
    $sales                                        = SeatTemp::where(DB::raw('EXTRACT(MONTH FROM updated_at)'), $date)
                                                  ->where('flag', 1)
                                                  ->with('user')
                                                  ->with('time')
                                                  ->with('seat')
                                                  ->with('date')
                                                  ->with('movie')
                                                  ->with('timer')
                                                  ->with('row')
                                                  ->with('price')
                                                  ->get();
    return response()->json($sales, 201);

    }

     public function lastMonth()
    {

    // $d                                            = strtotime("-1 Months");
    // $date                                         = date("m", $d);
    // $sales                                        = Sale::where(DB::raw('EXTRACT(MONTH FROM updated_at)'), $date)->with('item')->get();

    $todayDate = Carbon::now()->toDateString();
    $lastmonth = Carbon::parse($todayDate)->subMonth()->month;

//    $sales= Sale::whereMonth('created_at','=', $lastmonth)->get();
         
    $sales= Sale::whereMonth('created_at','=', $lastmonth)  
                    ->with('item')
                    ->with('user')			
                    ->selectRaw('*, sum(quantity) as totalQuantity')
                    ->groupBy('item_id')
                    ->get();

    return response()->json($sales, 201);

    }

    public function lastMonthX()
    {

    $d                                            = strtotime("-1 Months");
    $date                                         = date("m", $d);
    $sales                                        = SeatTemp::where(DB::raw('EXTRACT(MONTH FROM updated_at)'), $date)
                                                  ->where('flag', 1)
                                                  ->with('user')
                                                  ->with('time')
                                                  ->with('seat')
                                                  ->with('date')
                                                  ->with('movie')
                                                  ->with('timer')
                                                  ->with('row')
                                                  ->with('price')
                                                  ->get();
    return response()->json($sales, 201);

    }

     public function dateRangePicker($startDate,$endDate)
    {

    $sales                                        = Sale::whereBetween(DB::raw('DATE(updated_at)'), [$startDate,$endDate])->with('item')->get();
    return response()->json($sales, 201);
    }

    public function dateRangePickerX($startDate,$endDate)
    {

    $sales                                        = SeatTemp::whereBetween(DB::raw('DATE(updated_at)'), [$startDate,$endDate])
                                                  ->where('flag', 1)
                                                  ->with('user')
                                                  ->with('time')
                                                  ->with('seat')
                                                  ->with('date')
                                                  ->with('movie')
                                                  ->with('timer')
                                                  ->with('row')
                                                  ->with('price')
                                                  ->get();
    return response()->json($sales, 201);
    }


    public function dateFormat($date)
    {
    return date('Y-m-d', strtotime(str_replace('-', '/', $date)));
    }

     public function api(Request $request)
    {

     if ($request->Input('flagNote') == 'Consession Report' && $request->Input('timer') == 'To Day')
    {
    return $this->toDay();
    }
    else if ($request->Input('flagNote') == 'Movie Report' && $request->Input('timer') == 'To Day')
    {
    return $this->toDayX();
    }
     else if ($request->Input('flagNote') == 'Consession Report' && $request->Input('timer') == 'Yesterday')
    {
    return $this->yesterday();
    }
    else if ($request->Input('flagNote') == 'Movie Report' && $request->Input('timer') == 'Yesterday')
    {
    return $this->yesterdayX();
    }
    else if ($request->Input('flagNote') == 'Consession Report' && $request->Input('timer') == 'Last 7 Days')
    {
    return $this->last7days();
    }
    else if ($request->Input('flagNote') == 'Movie Report' && $request->Input('timer') == 'Last 7 Days')
    {
    return $this->last7daysX();
    }
    else if ($request->Input('flagNote') == 'Consession Report' && $request->Input('timer') == 'Last 30 Days')
    {
    return $this->last30Days();
    }
    else if ($request->Input('flagNote') == 'Movie Report' && $request->Input('timer') == 'Last 30 Days')
    {
    return $this->last30DaysX();
    }

    else if ($request->Input('flagNote') == 'Consession Report' && $request->Input('timer') == 'This Month')
    {
    return $this->thisMonth();
    }
    else if ($request->Input('flagNote') == 'Movie Report' && $request->Input('timer') == 'This Month')
    {
    return $this->thisMonthX();
    }

    else if ($request->Input('flagNote') == 'Consession Report' && $request->Input('timer') == 'Last Month')
    {
    return $this->lastMonth();
    }

    else if ($request->Input('flagNote') == 'Movie Report' && $request->Input('timer') == 'Last Month')
    {
    return $this->lastMonthX();
    }




    }

     public function dateRange(Request $request)
    {

    if ($request->Input('flagNote') == 'Consession Report')
    {
    return $this->dateRangePicker($this->dateFormat($request->Input('startDate')),$this->dateFormat($request->Input('endDate')));
    }
    else if($request->Input('flagNote') == 'Movie Report')
    {
    return $this->dateRangePickerX($this->dateFormat($request->Input('startDate')),$this->dateFormat($request->Input('endDate')));
    }

    }


}
