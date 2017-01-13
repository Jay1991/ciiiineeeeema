<!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>
         {{ flagNote }} -
         <small style="color:#fff">{{ timer }}</small>
      </h1>
    </div>
<!--      {{ reports }}-->
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
        <!-- {{ reports }} -->

        <!-- Main content -->
        <div class="col-md-12">
                &nbsp;
                <ol class="breadcrumb pull-left">
                  <li><a href="#/reports">Consession Report</a></li>
                  <li><a href="#/reportMovieToday">Movie Reports</a></li>
                  <li><a href="#/reportComplementaryToday">Complementary Tickets</a></li>


<!--
                    <li style="cursor:pointer" ng-click="flagNoteEventListener('Consession Report')"><a href="">Consession Report</a></li>
                    <li style="cursor:pointer" ng-click="flagNoteEventListener('Movie Report',0)"><a href=""> Movie Reports </a></li>
-->
<!--                     <li style="cursor:pointer"><a href="{{ url('/testing') }}"> Movie Reports </a></li> -->
<!--
                    <li style="cursor:pointer" ng-click="flagNoteEventListener('Movie Report',1)"><a href=""># Complementary Tickets </a> <span class="label label-primary"> {{ (reports| filter:{'is_complementary': 1 }).length }}</span></li>
                    
-->
                </ol>
                <ol class="breadcrumb pull-right">
                    
                    
                    <li><a ng-href="{{host}}/excel/{{ timer.split(' ').join('') }}" > <i class="fa fa-file-excel-o fa-2x" aria-hidden="true"></i></a></li>
                   

                    <li style="cursor:pointer" ng-click="timeEventListener('To Day')"><a href="#/"> To Day</a></li>
                    <li style="cursor:pointer" ng-click="timeEventListener('Yesterday')"><a href="#/"> Yesterday</a></li>
                    <li style="cursor:pointer" ng-click="timeEventListener('Last 7 Days')"><a href="#/"> Last 7 Days</a></li>
                    <li style="cursor:pointer" ng-click="timeEventListener('Last 30 Days')"><a href="#/"> Last 30 Days</a></li>
                    <li style="cursor:pointer" ng-click="timeEventListener('This Month')"><a href="#/"> This Month</a></li>
                    <li style="cursor:pointer" ng-click="timeEventListener('Last Month')"> <a href="#/"> Last Month</a> </li>
<!--
                    <li style="cursor:pointer" ng-click="timeEventListener('Custom Range')">
                    <input class="form-control pull-right active" id="reservation" type="text" style="width:150px" placeholder="Custom Range "></li>
-->

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
                            <li ><a href=""><i class="fa fa-inbox"></i> Total buying <span class="label label-primary pull-right">{{ setting.currency_symbol }} {{ totalBuyingEventListener(reports).toLocaleString() }}</span></a></li>
                            <li ><a href=""><i class="fa fa-inbox"></i>  Total Selling Figure <span class="label label-primary pull-right">{{ setting.currency_symbol }}
                                {{ totalSellingEventListener(reports) | number:2 }} </span></a></li>
                            <li ><a href=""><i class="fa fa-inbox"></i>  VAT amount <span class="label label-primary pull-right">{{ setting.currency_symbol }}
                                {{ totalVATEventListener(reports) | number:2 }}  </span></a>
                            </li>
                            <li ><a href=""><i class="fa fa-inbox"></i>  discount amount <span class="label label-primary pull-right">{{ setting.currency_symbol }}
                                {{ totalDiscountEventHandle(reports) | number:2 }}  </span></a>
<!--
                            </li>
                            <li ><a href=""><i class="fa fa-inbox"></i>  net <span class="label label-primary pull-right">{{ setting.currency_symbol }}
                              {{ (totalSellingEventListener(reports) - totalDiscountEventHandle(reports)) | number:2 }}
                                 {{ netEventListener(totalSellingEventListener(reports),totalVATEventListener(reports)).toLocaleString() }}   </span></a></li>
-->

                            <li ><a href=""><i class="fa fa-inbox"></i>  Profit <span class="label label-primary pull-right">{{ setting.currency_symbol }}
<!--                                {{ profitEventListener((totalSellingEventListener(reports) - totalDiscountEventHandle(reports)), totalBuyingEventListener(reports)) | number:2 }}  -->
                                {{ profitEventListener(reports) | number:2 }}
                                </span></a></li>

                          </ul>
                        </div><!-- /.box-body -->
                    </div>

<!--
                    <div class="box box-solid"  ng-if="flagNote === 'Movie Report'">
                      <div class="box-header with-border">
                          <h3 class="box-title"></h3>
                          <div class="box-tools">
                            <button class="btn btn-box-tool" data-widget="collapse"><i class="fa fa-minus"></i></button>
                          </div>
                      </div>
                      <div class="box-body no-padding">
                        <ul class="nav nav-pills nav-stacked">
                          <li class="activeX"><a href="#/reports"><i class="fa fa-align-justify"></i> Report Summary </a></li>
                          <li ><a href=""><i class="fa fa-inbox"></i>  Total Selling Figure <span class="label label-primary pull-right" >{{ setting.currency_symbol }}
                              {{ totalSeatSellingEventListener(reports).toLocaleString() }} </span></a></li>
                          <li ><a href=""><i class="fa fa-inbox"></i>  VAT amount <span class="label label-primary pull-right" >{{ setting.currency_symbol }}
                              {{ totalSeatVATEventListener(reports).toLocaleString() }}  </span></a></li>
                          <li ><a href=""><i class="fa fa-inbox"></i>  With draw tax <span class="label label-primary pull-right" >{{ setting.currency_symbol }}
                              {{ totalSeatWHTEventListener(reports).toLocaleString() }}  </span></a></li>
                          <li ><a href=""><i class="fa fa-inbox"></i>  net <span class="label label-primary pull-right" >{{ setting.currency_symbol }}
                              {{ netSeatSellingEventListener(reports).toLocaleString() }}  </span></a></li>
                          <li ><a href=""><i class="fa fa-inbox"></i>  D/comm <span class="label label-primary pull-right" >{{ setting.currency_symbol }}
                              {{ directorCommisionSeatSellingEventListener(reports).toLocaleString() }}  </span></a></li>
                          <li ><a href=""><i class="fa fa-inbox"></i>  F/A <span class="label label-primary pull-right" >{{ setting.currency_symbol }}
                              {{ finalAmountSeatSellingEventListener(reports).toLocaleString() }}  </span></a></li>

                        </ul>
                      </div>
                    </div>
-->
                </div>
              </div>






            </div><!-- /.col -->
            <div class="col-md-9">
              &nbsp;
              <div class="box box-primary">
<!--                <div class="box-header with-border">-->
<!--                  <h3 class="box-title" style="font: 400 13px/13px 'Roboto', sans-serif;color:#888"> {{ flagNote }}  <small> {{ timer }} </small> </h3>-->
<!--                  <div class="box-tools pull-right">-->
<!--
                    <div class="has-feedback">
                      <input type="text" class="form-control input-sm" placeholder="Search" ng-model="search" />
                      <span class="glyphicon glyphicon-search form-control-feedback"></span>
                    </div>
-->
<!--                  </div> /.box-tools -->
<!--                </div> /.box-header -->
                <div class="box-body no-padding">
                  <div class="mailbox-controls">
                    <!-- Check all button -->
                    <!-- <button class="btn btn-default btn-sm checkbox-toggle"><i class="fa fa-square-o"></i></button> -->
                    <div class="btn-group">
                      <!-- <button class="btn btn-default btn-sm"><i class="fa fa-trash-o"></i></button> -->
                      <!-- <button class="btn btn-default btn-sm"><i class="fa fa-reply"></i></button> -->
                      <!-- <button class="btn btn-default btn-sm"><i class="fa fa-share"></i></button> -->
                    </div><!-- /.btn-group -->
<!--                    <button class="btn btn-default btn-sm"><i class="fa fa-refresh"></i></button>-->
<!--                    <div class="pull-right">-->
<!--                      {{ (reports | filter:search).length }}/{{ reports.length }}-->
<!--                      <div class="btn-group">-->
<!--                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-left"></i></button>-->
<!--                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-right"></i></button>-->
<!--                      </div> /.btn-group -->
<!--                    </div> /.pull-right -->
                  </div>
                  <div class="table-responsive mailbox-messages">
                    <table  datatable="ng" 
                           class="row-border hover table table-bordered table-striped" 
                           ng-if="flagNote !== 'Movie Report'" 
                           style="font: 400 14px/22px 'Roboto', sans-serif;color:#888">
                      <thead>
                        <tr>
                          <!-- <th></th> -->
                          <!-- <th>Date</th> -->
                          <th>Name</th>
                          <th># Sold</th>
                          <th>Buying Price</th>
                          <th>Selling Price</th>
                          <th>Total Selling</th>
                          <th>VAT Amount</th>
                          <th>discount Amount</th>
<!--                          <th>net</th>-->
                          <th>Profit</th>
                          <th>Sale Agent</th>
                        </tr>
                      </thead>
                      <tfoot>
                          <tr>
                              <th>Total:</th>
                              <th></th>
                              <th>{{ totalBuyingEventListener(reports).toLocaleString() }}</th>
                              <th></th>
                              <th>{{ totalSellingEventListener(reports) | number:2 }}</th>
                              <th>{{ totalVATEventListener(reports) | number:2 }} </th>
                              <th>{{ totalDiscountEventHandle(reports) | number:2 }}</th>
                              <th>{{ profitEventListener(reports) | number:2 }}</th>
                              <th></th>
                              <th></th>
                          </tr>
                      </tfoot>
                      <tbody>
                          
                          

                        <tr ng-repeat="sale in reports | filter:search" >
                          <!-- <td class="mailbox-star"><a href=""><i class="fa fa-star-o text-yellow"></i></a></td> -->
                          <!-- <td> {{ sale.created_at }} </td> -->
                          <td class="mailbox-name"> <a>{{ sale.item.name }}</a> </td>
                          <td> {{ sale.totalQuantity }} </td>
                          <td> {{ sale.item.buying_price | number:2 }} </td>
                          <td> {{ sale.item.selling_price | number:2 }} </td>
                          <td> {{ (sale.item.selling_price)*(sale.totalQuantity) | number:2 }} </td>
                          <td> {{ (sale.vat_amount)*(sale.totalQuantity) | number:2 }} </td>

<!--                          <td> {{ sale.total_selling | number:2 }} </td>-->
                          <td> {{ sale.discount_amount | number:2 }} </td>
<!--                          <td> {{ sale.total_selling - sale.discount_amount | number:2 }} </td>-->
<!--                          <td> {{ profitEventListener((sale.total_selling - sale.discount_amount),sale.total_buying) | number:2 }} </td>-->

                          <td> {{ (sale.item.selling_price - (sale.item.buying_price + sale.vat_amount + sale.discount_amount))*sale.totalQuantity | number:2 }} </td>
                          <td> {{ sale.user.name }}</td>
                        </tr>
                      </tbody>
                    </table>
<!--
                    <table
                       datatable="ng" >
                      <thead>
-->
<!--                        <tr>-->
                          <!-- <th></th> -->
<!--
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
-->
<!--                      </thead>-->
<!--
                      <tbody >
                        <tr ng-repeat="sale in reports | filter:{'is_complementary': isComplementary }| filter:search">
                           <td class="mailbox-star"><a href=""><i class="fa fa-star-o text-yellow"></i></a></td> 
                          <td> {{ sale.date.date }} </td>
                          <td> {{ sale.distributor }} </td>
                          <td> {{ sale.movie.name }} </td>
                          <td> {{ sale.timer.starting_at }} </td>
                          <td> {{ noOfTicket(reports,sale.movie_id, sale.date_id, sale.time_id ) }} </td>
                          <td> {{ sale.price.figure }} </td>
                          <td> {{ sale.price.figure * noOfTicket(reports,sale.movie_id, sale.date_id, sale.time_id ) }} </td>
                          <td> {{ sale.vat_amount * noOfTicket(reports,sale.movie_id, sale.date_id, sale.time_id )  }} </td>
                          <td> {{ sale.with_draw_tax * noOfTicket(reports,sale.movie_id, sale.date_id, sale.time_id ) }} </td>
                          <td> {{ sale.discount_amount * noOfTicket(reports,sale.movie_id, sale.date_id, sale.time_id ) }} </td>
                          <td> {{ sale.net * noOfTicket(reports,sale.movie_id, sale.date_id, sale.time_id ) }} </td>
                          <td> {{ sale.distributor_percentage }} </td>
                          <td> {{ sale.distributor_commission * noOfTicket(reports,sale.movie_id, sale.date_id, sale.time_id )  }} </td>
                          <td> {{ sale.final_amount * noOfTicket(reports,sale.movie_id, sale.date_id, sale.time_id ) }} </td>
                        </tr>
                      </tbody>
-->
<!--                    </table>-->
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
