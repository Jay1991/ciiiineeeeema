<!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>
         Movie Report -
         <small style="color:#fff">Yesterday</small>
      </h1>
    </div>
  </section>
  <!--INNER BANNER END-->

 <!-- Content Header (Page header) -->
        <!-- <section class="content-header">
           <h1  style="font: 400 13px/13px 'Roboto', sans-serif;color:#888">
            {{ flagNote }}
            <small>{{ timer }}</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href=""><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX">report</li>
          </ol>
        </section> -->

        <!-- Main content -->
        <div class="col-md-12">
                &nbsp;
                <ol class="breadcrumb pull-left">
                  <li><a href="#/reports">Consession Report</a></li>

                  <li><a href="#/reportMovieToday">Movie Reports</a></li>
                  <li><a href="#/reportComplementaryToday">Complementary Tickets</a></li>


<!--
                    <li  ng-click="flagNoteEventListener('Consession Report')"><a href="">Consession Report</a></li>
                    <li  ng-click="flagNoteEventListener('Movie Report',0)"><a href=""> Movie Reports </a></li>
-->
<!--
                    <li  ng-click="flagNoteEventListener('Movie Report',1)"><a href=""># Complementary Tickets </a> <span class="label label-primary"> {{ (reports| filter:{'is_complementary': 1 }).length }}</span></li>
                    
-->
                </ol>
                <ol class="breadcrumb pull-right">
                  <li><a href="{{host}}/excel/movieyesterday"><i class="fa fa-file-excel-o fa-2x" aria-hidden="true"></i></a></li>
                  <li><a href="#/reportMovieToday">To Day</a></li>
                  <li><a href="#/reportMovieYest">Yesterday</a></li>
                  <li><a href="#/reportMovieSeven">Last 7 Days</a></li>
                  <li><a href="#/reportMovieThirty">Last 30 Days</a></li>
                  <li><a href="#/reportJ">This Month</a></li>
                  <li><a href="#/reportMovieLastMonth">Last Month</a></li>
                </ol>
        </div>


        <section class="content">
          <div class="row">
            <div class="col-md-3">
              &nbsp;
              <div class="box box-primary">
                <div class="box-body">
                    <a href="" class="btn btn-primary btn-block margin-bottom">Report</a>

                    <div class="box box-solid" ng-if="flagNote !== 'Movie Report'">
                        <div class="box-header with-border">
                          <h3 class="box-title"></h3>
                          <div class="box-tools">
                            <button class="btn btn-box-tool" data-widget="collapse"><i class="fa fa-minus"></i></button>
                          </div>
                        </div>
                        <div class="box-body no-padding">
                          <ul class="nav nav-pills nav-stacked">
                            <li class="activeX"><a href="#/reports"> Report Summary </a></li>
                            <li ><a href=""><i class="fa fa-inbox"></i> Total buying <span class="label label-primary pull-right">{{ setting.currency_symbol }} 
                                    
                                    {{ getTotalBuying(yesterday) | number:2 }}
<!--                                {{ totalBuyingEventListener(yesterday).toLocaleString() }}</span></a></li>-->
                            <li ><a href=""><i class="fa fa-inbox"></i>  Total Selling Figure <span class="label label-primary pull-right">{{ setting.currency_symbol }}
<!--                                {{ totalSellingEventListener(reports) | number:2 }}-->
                                {{ getAmtIncl(yesterday) | number:0 }}
                                </span></a></li>
                            <li ><a href=""><i class="fa fa-inbox"></i>  VAT amount <span class="label label-primary pull-right">{{ setting.currency_symbol }}
<!--                                {{ totalVATEventListener(reports) | number:2 }}-->
                                {{ getTax(yesterday) | number:0 }} 
                                </span></a>
                            </li>
                            <li ><a href=""><i class="fa fa-inbox"></i>  discount amount <span class="label label-primary pull-right">{{ setting.currency_symbol }}
<!--                                {{ totalDiscountEventHandle(yesterday) | number:2 }}-->
                                    {{ getTotalDiscount(yesterday) | number:2 }}
                                
                                </span></a>
                            </li>
                            <li ><a href=""><i class="fa fa-inbox"></i>  net <span class="label label-primary pull-right">{{ setting.currency_symbol }}
                                {{ getTotalNet(yesterday) | number:0 }}
<!--                              {{ (totalSellingEventListener(reports) - totalDiscountEventHandle(reports)) | number:2 }}-->
                               <!--  {{ netEventListener(totalSellingEventListener(reports),totalVATEventListener(reports)).toLocaleString() }} -->  </span></a></li>

                            <li ><a href=""><i class="fa fa-inbox"></i>  Profit <span class="label label-primary pull-right">{{ setting.currency_symbol }}
                                
                                {{ getTotalProfit(yesterday) | number:2 }}
<!--                                {{ profitEventListener((totalSellingEventListener(yesterday) - totalDiscountEventHandle(yesterday)), totalBuyingEventListener(yesterday)) | number:0 }} -->
                                </span></a></li>

                          </ul>
                        </div><!-- /.box-body -->
                    </div>


                </div>
              </div>






            </div><!-- /.col -->
            <div class="col-md-9">
              &nbsp;
              <div class="box box-primary">
                <div class="box-header with-border">
                  <h3 class="box-title" style="font: 400 13px/13px 'Roboto', sans-serif;color:#888">   <small> </small> </h3>
                  <div class="box-tools pull-right">

                  </div><!-- /.box-tools -->
                </div><!-- /.box-header -->
                <div class="box-body no-padding">
                  <div class="mailbox-controls">
                    <!-- Check all button -->
                    <!-- <button class="btn btn-default btn-sm checkbox-toggle"><i class="fa fa-square-o"></i></button> -->
                    <div class="btn-group">
                      <!-- <button class="btn btn-default btn-sm"><i class="fa fa-trash-o"></i></button> -->
                      <!-- <button class="btn btn-default btn-sm"><i class="fa fa-reply"></i></button> -->
                      <!-- <button class="btn btn-default btn-sm"><i class="fa fa-share"></i></button> -->
                    </div><!-- /.btn-group -->

                  </div>

                  <div class="table-responsive mailbox-messages">
                    <table datatable="ng" 
                           class="row-border hover table table-bordered table-striped" 
                           style="font: 400 14px/22px 'Roboto', sans-serif;color:#888">
                      <thead>
                        <tr>
                          <!-- <th></th> -->
                          <th>Show Date</th>
                          <th>Distributor</th>
                          <th>Movie name</th>
                          <th>Show Time </th>
                          <th>No Of Tkts</th>
                          <th>Price/Tkt(incl Tax) </th>
                          <th>Amt(incl Tax) </th>
                          <th>Tax </th>
                          <th>WHT </th>
                          <th>Discount </th>
                          <th>Net Amt </th>
                          <th>Dst % </th>
                          <th>Dst comm </th>
                          <th>F/A </th>
                        </tr>
                      </thead>
                        <tfoot>
                        <tr>
                          <th>Total</th>
                          <th></th>
                          <th></th>
                          <th></th>
                          <th>{{ getTotalTks(yesterday) | number:0 }}</th>
                          <th></th>
                          <th>{{ getAmtIncl(yesterday) | number:0 }}</th>
                          <th>{{ getTax(yesterday) | number:0 }}</th>
                          <th></th>
                          <th></th>
                          <th>{{ getTotalNet(yesterday) | number:0 }}</th>
                          <th></th>
                          <th>{{ getTotalDisCom(yesterday) | number:0 }}</th>
                          <th></th>
                        </tr>
                      </tfoot>
                      <tbody >
                        <tr ng-repeat="movie in yesterday">
                          <!-- <td class="mailbox-star"><a href=""><i class="fa fa-star-o text-yellow"></i></a></td> -->
                          <td> {{ movie.date }} </td>
                          <td> {{ movie.distributor }} </td>
                          <td> {{ movie.name }} </td>
                          <td> {{ movie.starting_at }} </td>
                          <td> {{ movie.seatNo }} </td>
                          <td> {{ movie.figure }} </td>
                          <td> {{ movie.figure * movie.seatNo | number:0 }} </td>
                          <td> {{ (movie.figure * movie.seatNo)*((movie.movie_sales.setting[0].vat_percentage)/100) | number:0 }} </td>
                          <td> {{ movie.with_draw_tax | number:0 }} </td>
                          <td> {{ movie.discount_amount * movie.seatNo | number:0 }} </td>
                          <td> {{ (movie.figure * movie.seatNo) - (movie.figure * movie.seatNo)*((movie.movie_sales.setting[0].vat_percentage)/100) | number:0 }} </td>
                          <td> {{ movie.distributor_percentage | number:0 }} </td>
                          <td> {{ movie.distributor_commission * movie.seatNo | number:0 }} </td>
                          <td> {{ movie.final_amount * movie.seatNo | number:0 }} </td>
                        </tr>                      
                      </tbody>
                    </table>
                  </div><!-- /.mail-box-messages -->
                </div><!-- /.box-body -->
                <div class="box-footer no-padding">
                  <div class="mailbox-controls">
                    <!-- Check all button -->
                    <!-- <button class="btn btn-default btn-sm checkbox-toggle"><i class="fa fa-square-o"></i></button>                     -->
                    <div class="btn-group">
                      <!-- <button class="btn btn-default btn-sm"><i class="fa fa-trash-o"></i></button> -->
                      <!-- <button class="btn btn-default btn-sm"><i class="fa fa-reply"></i></button> -->
                      <!-- <button class="btn btn-default btn-sm"><i class="fa fa-share"></i></button> -->
                    </div><!-- /.btn-group -->
                    <!-- <button class="btn btn-default btn-sm"><i class="fa fa-refresh"></i></button> -->
                    <div class="pull-right">
                      <!-- 1-50/200 -->
                      <div class="btn-group">
                        <!-- <button class="btn btn-default btn-sm"><i class="fa fa-chevron-left"></i></button> -->
                        <!-- <button class="btn btn-default btn-sm"><i class="fa fa-chevron-right"></i></button> -->
                      </div><!-- /.btn-group -->
                    </div><!-- /.pull-right -->
                  </div>
                </div>
              </div><!-- /. box -->
            </div><!-- /.col -->
          </div><!-- /.row -->
        </section><!-- /.content -->



<!-- <div ng-include="'resources/views/partials/app/date-range.blade.php'"></div> -->
