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

class ExportReportController extends Controller
{
    public function moviethismonth(){
               
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
    
    public function movietoday(){
               
    Excel::create('Movie Report', function($excel){
    $excel->sheet('Today', function($sheet){
                
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
    
    public function movieyesterday(){
               
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
    
    public function movielastseven(){
               
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
    
    public function movielastthirty(){
               
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
    
    public function movielastmonth(){
               
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
//			->whereMonth('seat_temps.updated_at', '=', $month)
			// last month
			 ->whereMonth('seat_temps.updated_at', '=', $lastmonth)


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
    
    public function consessiontoday(){
               
    Excel::create('Consession Report', function($excel){
    $excel->sheet('Today', function($sheet){
                
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

	$reports = Sale::whereDate('created_at', $todayDate)  
                    ->with('item')
                    ->with('user')			
                    ->selectRaw('*, sum(quantity) as totalQuantity')
                    ->groupBy('item_id')
                    ->get();

			$settings = Setting::all()->pluck('vat_percentage');
            $vat =  $settings[0];
                
            foreach($reports as $report){
                    $data[] = array(
                        
                        $report->item->name,
                        $report->totalQuantity,
                        $report->item->buying_price,
                        $report->item->selling_price,
                        $report->item->selling_price*$report->totalQuantity,
                        $report->vat_amount*$report->totalQuantity,
                        $report->discount_amount,
                        ($report->item->selling_price - ($report->item->buying_price + $report->vat_amount + $report->discount_amount))*$report->totalQuantity,
                        $report->user->name,

                    );
                }
                $sheet->fromArray($data, null, 'A1', false, false);
                $headings = array('Name', '# Sold', 'Buying Price', 'Selling Price', 'Total Selling Price','VAT Amount', 'discount Amount', 'Profit', 'Sale Agent');                
													
                $sheet->prependRow(1, $headings);                
                
                 $totalBuying = 0;

                    foreach($reports as $report){
                      $totalBuying += ($report->item->buying_price*$report->totalQuantity);

                    }
                
                    $totalSelling = 0;

                    foreach($reports as $report){
                    
                        $totalSelling += $report->item->selling_price*$report->totalQuantity;

                    } 
            
                     $totalVAT = 0;


                    foreach($reports as $report){
                
                        $totalVAT += ($report->vat_amount)*$report->totalQuantity;


                    }
        
                     $totalDiscount = 0;                

                    foreach($reports as $report){

                    $totalDiscount += ($report->discount_amount)*$report->totalQuantity;


                    }
                
                    $totalProfit = 0;

                    foreach($reports as $report){

     $totalProfit += ($report->item->selling_price - ($report->item->buying_price + $report->vat_amount + $report->discount_amount))*$report->totalQuantity;


                    }
                
                $sheet->appendRow(array(
                    'Total', '', $totalBuying, '', $totalSelling, $totalVAT, $totalDiscount, $totalProfit, ''));
                
            });
            
        })->export('xls');
        
    }
    
    public function consessionyesterday(){
               
    Excel::create('Consession Report', function($excel){
        
    $excel->sheet('Yesterday', function($sheet){
                
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

	
	$reports = Sale::whereDate('created_at', $yesterday)  
                    ->with('item')
                    ->with('user')			
                    ->selectRaw('*, sum(quantity) as totalQuantity')
                    ->groupBy('item_id')
                    ->get();

			$settings = Setting::all()->pluck('vat_percentage');
            $vat =  $settings[0];
                
            foreach($reports as $report){
                    $data[] = array(
                        
                       $report->item->name,
                        $report->totalQuantity,
                        $report->item->buying_price,
                        $report->item->selling_price,
                        $report->item->selling_price*$report->totalQuantity,
                        $report->vat_amount*$report->totalQuantity,
                        $report->discount_amount,
                        ($report->item->selling_price - ($report->item->buying_price + $report->vat_amount + $report->discount_amount))*$report->totalQuantity,
                        $report->user->name,


                    );
                }
                $sheet->fromArray($data, null, 'A1', false, false);
                $headings = array('Name', '# Sold', 'Buying Price', 'Selling Price', 'Total Selling Price','VAT Amount', 'discount Amount', 'Profit', 'Sale Agent');                
													
                $sheet->prependRow(1, $headings);
                   $totalBuying = 0;

                    foreach($reports as $report){
                      $totalBuying += ($report->item->buying_price*$report->totalQuantity);

                    }
                
                    $totalSelling = 0;

                    foreach($reports as $report){
                    
                        $totalSelling += $report->item->selling_price*$report->totalQuantity;

                    } 
            
                     $totalVAT = 0;


                    foreach($reports as $report){
                
                        $totalVAT += ($report->vat_amount)*$report->totalQuantity;


                    }
        
                     $totalDiscount = 0;                

                    foreach($reports as $report){

                    $totalDiscount += ($report->discount_amount)*$report->totalQuantity;


                    }
                
                    $totalProfit = 0;

                    foreach($reports as $report){

     $totalProfit += ($report->item->selling_price - ($report->item->buying_price + $report->vat_amount + $report->discount_amount))*$report->totalQuantity;


                    }
                
                $sheet->appendRow(array(
                    'Total', '', $totalBuying, '', $totalSelling, $totalVAT, $totalDiscount, $totalProfit, ''));
                
            });
            
        })->export('xls');
        
    }
    
    public function consessionlastseven(){
               
    Excel::create('Consession Report', function($excel){
    $excel->sheet('Last Seven Days', function($sheet){
                
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
        
    $reports = Sale::where('created_at','>=', $lastSevenDays)  
                    ->with('item')
                    ->with('user')			
                    ->selectRaw('*, sum(quantity) as totalQuantity')
                    ->groupBy('item_id')
                    ->get();

			$settings = Setting::all()->pluck('vat_percentage');
            $vat =  $settings[0];
                
            foreach($reports as $report){
                    $data[] = array(
                        
                        $report->item->name,
                        $report->totalQuantity,
                        $report->item->buying_price,
                        $report->item->selling_price,
                        $report->item->selling_price*$report->totalQuantity,
                        $report->vat_amount*$report->totalQuantity,
                        $report->discount_amount,
                        ($report->item->selling_price - ($report->item->buying_price + $report->vat_amount + $report->discount_amount))*$report->totalQuantity,
                        $report->user->name,

                    );
                }
                $sheet->fromArray($data, null, 'A1', false, false);
                $headings = array('Name', '# Sold', 'Buying Price', 'Selling Price', 'Total Selling Price','VAT Amount', 'discount Amount', 'Profit', 'Sale Agent');                
													
                $sheet->prependRow(1, $headings);
        
           
                 $totalBuying = 0;

                    foreach($reports as $report){
                      $totalBuying = ($report->item->buying_price*$report->totalQuantity);

                    }
                
                    $totalSelling = 0;

                    foreach($reports as $report){
                    
                        $totalSelling += $report->item->selling_price*$report->totalQuantity;

                    } 
            
                     $totalVAT = 0;


                    foreach($reports as $report){
                
                        $totalVAT += ($report->vat_amount)*$report->totalQuantity;


                    }
        
                     $totalDiscount = 0;                

                    foreach($reports as $report){

                    $totalDiscount += ($report->discount_amount)*$report->totalQuantity;


                    }
                
                    $totalProfit = 0;

                    foreach($reports as $report){

     $totalProfit += ($report->item->selling_price - ($report->item->buying_price + $report->vat_amount + $report->discount_amount))*$report->totalQuantity;


                    }
                
                $sheet->appendRow(array(
                    'Total', '', $totalBuying, '', $totalSelling, $totalVAT, $totalDiscount, $totalProfit, ''));
                
            });
            
        })->export('xls');
        
    }
    
    public function consessionlastthirty(){
               
    Excel::create('Consession Report', function($excel){
    $excel->sheet('Last Thirty Days', function($sheet){
                
    $todayDate = Carbon::now()->toDateString();
	$todayParsed = Carbon::parse($todayDate)->subDay();
	$toSevenDays = Carbon::parse($todayDate)->subDays(7);
	$lastThirtyDays = Carbon::parse($todayDate)->subMonth()->toDateString();
	$month = Carbon::now()->month;
	$lastmonth = Carbon::parse($todayDate)->subMonth()->month;


	$lastSevenDays = $toSevenDays->toDateString();

	$yesterday = $todayParsed->toDateString();

	$oneMonthLater = $todayParsed ->subMonth()->toDateTimeString();
        
      $reports = Sale::where('created_at','>=', $lastThirtyDays)  
                    ->with('item')
                    ->with('user')			
                    ->selectRaw('*, sum(quantity) as totalQuantity')
                    ->groupBy('item_id')
                    ->get();

			$settings = Setting::all()->pluck('vat_percentage');
            $vat =  $settings[0];
                
            foreach($reports as $report){
                    $data[] = array(
                        
                       $report->item->name,
                        $report->totalQuantity,
                        $report->item->buying_price,
                        $report->item->selling_price,
                        $report->item->selling_price*$report->totalQuantity,
                        $report->vat_amount*$report->totalQuantity,
                        $report->discount_amount,
                        ($report->item->selling_price - ($report->item->buying_price + $report->vat_amount + $report->discount_amount))*$report->totalQuantity,
                        $report->user->name,
                    );
                }
                $sheet->fromArray($data, null, 'A1', false, false);
                $headings = array('Name', '# Sold', 'Buying Price', 'Selling Price', 'Total Selling Price','VAT Amount', 'discount Amount', 'Profit', 'Sale Agent');                
													
                $sheet->prependRow(1, $headings);
            
        $totalBuying = 0;

                    foreach($reports as $report){
                      $totalBuying += ($report->item->buying_price*$report->totalQuantity);

                    }
                
                    $totalSelling = 0;

                    foreach($reports as $report){
                    
                        $totalSelling += $report->item->selling_price*$report->totalQuantity;

                    } 
            
                     $totalVAT = 0;


                    foreach($reports as $report){
                
                        $totalVAT += ($report->vat_amount)*$report->totalQuantity;


                    }
        
                     $totalDiscount = 0;                

                    foreach($reports as $report){

                    $totalDiscount += ($report->discount_amount)*$report->totalQuantity;


                    }
                
                    $totalProfit = 0;

                    foreach($reports as $report){

     $totalProfit += ($report->item->selling_price - ($report->item->buying_price + $report->vat_amount + $report->discount_amount))*$report->totalQuantity;


                    }
                
                $sheet->appendRow(array(
                    'Total', '', $totalBuying, '', $totalSelling, $totalVAT, $totalDiscount, $totalProfit, ''));
                
                
            });
            
        })->export('xls');
        
    }
    
    public function consessionthismonth(){
               
    Excel::create('Consession Report', function($excel){
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
        
             $reports = Sale::whereMonth('created_at','=', $month) 
                    ->with('item')
                    ->with('user')			
                    ->selectRaw('*, sum(quantity) as totalQuantity')
                    ->groupBy('item_id')
                    ->get();

			$settings = Setting::all()->pluck('vat_percentage');
            $vat =  $settings[0];
                
            foreach($reports as $report){
                    $data[] = array(
                          
                        $report->item->name,
                        $report->totalQuantity,
                        $report->item->buying_price,
                        $report->item->selling_price,
                        $report->item->selling_price*$report->totalQuantity,
                        $report->vat_amount*$report->totalQuantity,
                        $report->discount_amount,
                        ($report->item->selling_price - ($report->item->buying_price + $report->vat_amount + $report->discount_amount))*$report->totalQuantity,
                        $report->user->name,

                    );
                }
                $sheet->fromArray($data, null, 'A1', false, false);
                $headings = array('Name', '# Sold', 'Buying Price', 'Selling Price', 'Total Selling Price','VAT Amount', 'discount Amount', 'Profit', 'Sale Agent');                
													
                $sheet->prependRow(1, $headings);
        
        
                 $totalBuying = 0;

                    foreach($reports as $report){
                      $totalBuying += ($report->item->buying_price*$report->totalQuantity);

                    }
                
                    $totalSelling = 0;

                    foreach($reports as $report){
                    
                        $totalSelling += $report->item->selling_price*$report->totalQuantity;

                    } 
            
                     $totalVAT = 0;


                    foreach($reports as $report){
                
                        $totalVAT += ($report->vat_amount)*$report->totalQuantity;


                    }
        
                     $totalDiscount = 0;                

                    foreach($reports as $report){

                    $totalDiscount += ($report->discount_amount)*$report->totalQuantity;


                    }
                
                    $totalProfit = 0;

                    foreach($reports as $report){

     $totalProfit += ($report->item->selling_price - ($report->item->buying_price + $report->vat_amount + $report->discount_amount))*$report->totalQuantity;


                    }
                
                $sheet->appendRow(array(
                    'Total', '', $totalBuying, '', $totalSelling, $totalVAT, $totalDiscount, $totalProfit, ''));

                
            });
            
        })->export('xls');
        
    }
    
    public function consessionlastmonth(){
               
    Excel::create('Concession Report', function($excel){
    $excel->sheet('Last month', function($sheet){
                
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
        
             $reports = Sale::whereMonth('created_at','=', $lastmonth)  
                    ->with('item')
                    ->with('user')			
                    ->selectRaw('*, sum(quantity) as totalQuantity')
                    ->groupBy('item_id')
                    ->get();

			$settings = Setting::all()->pluck('vat_percentage');
            $vat =  $settings[0];
                
            foreach($reports as $report){
                    $data[] = array(
                        
                        $report->item->name,
                        $report->totalQuantity,
                        $report->item->buying_price,
                        $report->item->selling_price,
                        $report->item->selling_price*$report->totalQuantity,
                        $report->vat_amount*$report->totalQuantity,
                        $report->discount_amount,
                        ($report->item->selling_price - ($report->item->buying_price + $report->vat_amount + $report->discount_amount))*$report->totalQuantity,
                        $report->user->name,

                    );
                }
                $sheet->fromArray($data, null, 'A1', false, false);
                $headings = array('Name', '# Sold', 'Buying Price', 'Selling Price', 'Total Selling Price','VAT Amount', 'discount Amount', 'Profit', 'Sale Agent');                
													
                $sheet->prependRow(1, $headings);
        
         $totalBuying = 0;

                    foreach($reports as $report){
                      $totalBuying += ($report->item->buying_price*$report->totalQuantity);

                    }
                
                    $totalSelling = 0;

                    foreach($reports as $report){
                    
                        $totalSelling += $report->item->selling_price*$report->totalQuantity;

                    } 
            
                     $totalVAT = 0;


                    foreach($reports as $report){
                
                        $totalVAT += ($report->vat_amount)*$report->totalQuantity;


                    }
        
                     $totalDiscount = 0;                

                    foreach($reports as $report){

                    $totalDiscount += ($report->discount_amount)*$report->totalQuantity;


                    }
                
                    $totalProfit = 0;

                    foreach($reports as $report){

     $totalProfit += ($report->item->selling_price - ($report->item->buying_price + $report->vat_amount + $report->discount_amount))*$report->totalQuantity;


                    }
                
                $sheet->appendRow(array(
                    'Total', '', $totalBuying, '', $totalSelling, $totalVAT, $totalDiscount, $totalProfit, ''));


                
            });
            
        })->export('xls');
        
    }
    
    public function complementarytoday(){
        
    Excel::create('Complementary Report', function($excel){
    $excel->sheet('Today', function($sheet){
                
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
			->where('seat_temps.is_complementary', '=', 1)
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
    
    public function complementaryyesterday(){
        
    Excel::create('Complementary Report', function($excel){
    $excel->sheet('Yesterday', function($sheet){
                
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
//			 ->whereDate('seat_temps.updated_at', $todayDate)
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
			->where('seat_temps.is_complementary', '=', 1)
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
    
    public function complementarylastseven(){
        
    Excel::create('Movie Report', function($excel){
    $excel->sheet('Today', function($sheet){
                
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
//			 ->whereDate('seat_temps.updated_at', $todayDate)
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
			->where('seat_temps.is_complementary', '=', 1)
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
    
    public function complementarylastthirty(){
        
          Excel::create('Movie Report', function($excel){
    $excel->sheet('Today', function($sheet){
                
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
//			 ->whereDate('seat_temps.updated_at', $todayDate)
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
			->where('seat_temps.is_complementary', '=', 1)
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
    
    public function complementarythismonth(){
        
    Excel::create('Movie Report', function($excel){
    $excel->sheet('Today', function($sheet){
                
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
//			 ->whereDate('seat_temps.updated_at', $todayDate)
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
			->where('seat_temps.is_complementary', '=', 1)
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
    
    public function complementarylastmonth(){
        
    Excel::create('Complementary Report', function($excel){
    $excel->sheet('Last month', function($sheet){
                
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
//			 ->whereDate('seat_temps.updated_at', $todayDate)
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
			->where('seat_temps.is_complementary', '=', 1)
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
    
    
    
}
