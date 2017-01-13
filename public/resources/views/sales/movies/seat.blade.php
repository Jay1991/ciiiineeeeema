<style>
 .numberCircle {
    display: block;
    height: 20px;
    width: 20px;
    line-height: 60px;

    -moz-border-radius: 30px;
    border-radius: 30px;

    background-color: black;
    color: white;
    text-align: center;
    font-size: 2em;

}
.numberCircle .height_fix {
    margin-top: 100%;
}
.numberCircle .content {
    position: absolute;
    left: 0;
    top: 50%;
    height: 100%;
    width: 100%;
    text-align: center;
    margin-top: -16px; /* Note, this must be half the font size */
}
  
    .other{
/*        padding-left: 60px;*/
        padding-left: 60px;
        padding-right: 60px;
/*        margin-left: 60px;*/
/*        margin-right: 60px;*/
/*        border-left: 60px;*/
/*        background-color: darkgoldenrod;*/
    }
      .last {
/*        background-color: aqua;*/
          margin-left: none;
        margin-right: none;
          padding-left: 0px;
          padding-right: 0px;
    }


</style>

<!-- Content Header (Page header) -->
        <!-- <section class="content-header">
          <h1>

            <small></small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX">Mailbox</li>
          </ol>
        </section> -->

       <!--  <div class="alert alert-danger" ng-show="online">
            Internet not connected ....
        </div> -->
        <!-- Main content -->


        <section class="content">
      <!--            auth,authtime,authdate),output,authtime,authdate-->
<!--            {{ selectedSeats }}-->
        <div class="row">
          <div class="col-md-12">

                <a href="#/movies/dates/times/screens" class="btn btn-app">
                  <i class="fa fa-chevron-left"></i>
                </a>

                <button class="btn bg-green btn-app pull-right" style="" ng-click="saleEventListener(totalEventListener(auth,authtime,authdate),output,authtime,authdate,flagNote,0,authdate.movie.name, ((totalEventListener(auth,authtime,authdate))/authdate.price.figure), authdate.price.figure, authdate.date.date, authtime.time.starting_at)"  ng-if="flagNote === 2">BOOK</button>
                
                <button class="btn bg-green btn-app pull-right" style="" ng-click="saleEventListener(totalEventListener(auth,authtime,authdate),output,authtime,authdate,flagNote,0, authdate.movie.name, ((totalEventListener(auth,authtime,authdate))/authdate.price.figure), authdate.price.figure, authdate.date.date, authtime.time.starting_at)" ng-if="flagNote !== 2" >SALE</button>
              
                <button class="btn bg-blue btn-app pull-right"  ng-click="saleEventListener(totalEventListener(auth,authtime,authdate),output,authtime,authdate,flagNote,1,authdate.movie.name, ((totalEventListener(auth,authtime,authdate))/authdate.price.figure), authdate.price.figure, authdate.date.date, authtime.time.starting_at)" ng-if="flagNote !== 2">COMPLEMENTARY</button>

                <button class="btn bg-default btn-app pull-right" style="" ng-click="rePrintEventHandle()">RE-PRINT</button>

                <label class="badge bg-red pull-right" style="font-size: 40px;padding: 10px 20px;font-family:ubuntu">
                {{ totalEventListener(auth,authtime,authdate).toLocaleString() }}
                </label>

          </div>
          </div>
<!--         <div class="container">-->

          <div class="row">
<!--            <div class="col-md-12">-->

              <div class="box box-default">
                  <div class="box-header">
                      <div class="navbar navbar-default col-md-4 col-md-offset-4 text-center">{{ timeScreen.screen.name }}</div>
                  </div>
                  <div class="col-md-offset-1">
                  <div class="box-body">
                        
<!--                      <div class="col-md-10">-->                      

                    <div ng-repeat="row in rows | filter:{'screen_id': timeScreen.screen.id }:true" class="center-block other" ng-class="{'last': $last}">                        


                      <span ng-repeat="seat in seats | filter:{'row_id': row.id }">
<!--
                          {{ yellowEventHandle((temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true)[0],(temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true).length,seat.id,authtime.id) }}
                          
-->
                        <!-- <a href="" class="btn btn-app" style="background:#dd4b39;font-family:ubuntu condensed"  ng-if="(temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true | filter:{'is_already_saled': 1 }).length !== 0">
                            {{ seat.row.code }} {{ seat.number }}
                        </a> -->
                        <!-- <a href="" class="btn btn-app" style="background:#f39c12;font-weight:bold"   ng-show="Hider((temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true)[0],(temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true).length)">
                            {{ seat.row.code }} {{ seat.number }}

                        </a> -->
                        <!-- <a href="" class="btn btn-app" style="background:#00a65a;color:#fff;font-family:ubuntu condensed"  ng-if="(temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true).length === 0" ng-click="addSaleTemp(authdate,authtime, seat,flagNote)">
                            {{ seat.row.code }} {{ seat.number }}

                        </a> -->
                        <!-- <a href="" class="btn btn-app" style="background:yellow;font-family:ubuntu condensed"  ng-if="(temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true | filter:{'user_id': auth.id } | filter:{'status': 0 }).length != 0" ng-click="removeSaleTemp(authtime, seat,flagNote)">
                            {{ seat.row.code }} {{ seat.number }}

                        </a> -->
                        <!-- green -->  
                         
                                                 
                        <button href="" class="btn btn-app" style="background:#00a65a;color:#fff;font-family:ubuntu;min-width: 50px !important;height: 50px !important;"  
                                ng-click="addSaleTemp(authdate,authtime, seat,flagNote);" 
                                ng-show="greenEventHandle((temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true).length)"
                               >
                            {{ seat.row.code }} {{ seat.number }}

                        </button>

                        <!-- red -->
                         <button href="" class="btn btn-app" style="background:#dd4b39;color:#fff;font-family:ubuntu condensed;min-width: 50px !important;height: 50px !important;"   
                                 ng-show="redEventHandle((temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true)[0],(temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true).length,seat.id,authtime.id)" >
                            {{ seat.row.code }} {{ seat.number }}

                        </button>
                        <!-- yellow -->
                        <button href="" class="btn btn-app" id="seat" style="background:yellow;font-family:ubuntu condensed;min-width: 50px !important;height: 50px !important;"   
                                ng-show="yellowEventHandle((temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true)[0],(temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true).length,seat.id,authtime.id)" 
                                ng-click="removeSaleTemp(authtime, seat,flagNote)">
                            {{ seat.row.code }} {{ seat.number }}

                        </button>
                        



                      </span>


                    </div>
                      
<!--                      </div>-->

                    <!-- <div style="font-family:ubuntu" ng-repeat="row in rows | filter:{'screen_id': timeScreen.screen.id }:true">

                      <br>
                      <a class="btn btn-app" ng-repeat="seat in seats | filter:{'row_id': row.id }" ng-if="(temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true | filter:{'status': 1 }).length === 0" style="cursor:pointer;font-family:ubuntu condensed;font-weight:bold;font-size:9px" ng-click="addSaleTemp(authtime, seat,flagNote)"> {{ seat.row.code }} {{ seat.number }} </a>
                      <span class="label bg-red" ng-repeat="seat in seats | filter:{'row_id': row.id }" ng-if="(temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true | filter:{'status': 1 } | filter:{'flag': 1 }).length != 0"  style="cursor:pointer;font-family:ubuntu condensed;font-weight:bold;font-size:12px"  ng-click="removeSaleTemp(authtime, seat,flagNote)"> {{ seat.row.code }} {{ seat.number }} </span>
                      <span class="label label-warning" ng-repeat="seat in seats | filter:{'row_id': row.id }" ng-if="(temps | filter:{'seat_id': seat.id }:true | filter:{'time_id': authtime.id }:true | filter:{'status': 1 } | filter:{'flag': 2 }).length != 0"  style="cursor:pointer;font-family:ubuntu condensed;font-weight:bold;font-size:12px"  ng-click="removeSaleTemp(authtime, seat,flagNote)"> {{ seat.row.code }} {{ seat.number }} </span>

                    </div> -->
<!--                    </div>-->

                    

                  
                  </div><!-- /.box-body -->
                      </div>
              </div><!-- /.box -->

<!--            </div>-->
<!--            <div class="col-md-3">-->

              <!-- <div class="box box-default">
                  <div class="box-body">
                    <center>


                      <a ng-click="printEventListener(flagNote)"  class="btn btn-app" style="width:95%;height:150px" ng-if="flagNote === 1">

                        <i class="glyphicon glyphicon-print" style="font-size:72px"></i>

                      </a>

                      <a ng-click="printEventListener(flagNote)"  class="btn btn-app"  style="width:95%;height:100px;font-family:ubuntu">

                        <span style="font-size:30px">
                              {{ totalEventListener(auth,authtime,authdate).toLocaleString() }}/ {{ output.toLocaleString() }}
                              {{ totalEventListener(auth,authtime,authdate).toLocaleString() }}

                             <hr>
                              <span ng-if="output != 0"> {{ (totalEventListener(auth,authtime,authdate) - output).toLocaleString() }} </span>
                        </span>

                      </a>





                    </center>


                  </div>
              </div>


              <div class="box box-primary">
                <div class="box-body ">
                  <div>
                    <span>VAT %</span>
                    <span class="pull-right"> <input type="checkbox" value="" ng-model="vat" ng-click="vatEvent(vat)"> </span>
                  </div>
                  <div>
                  <span>Discount %</span>
                  <span class="pull-right"> <input type="checkbox" value="" ng-model="vat" ng-click="vatEvent(vat)"> </span>
                  </div>
                  <table >
                    <tr>
                      <td style="width:100%">VAT %</td>
                      <td style="width:100%"><input type="checkbox" value="" ng-model="vat" ng-click="vatEvent(vat)"></td>
                    </tr>
                    <tr>
                      <td >Discount</td>
                      <td >
                        <span class="pull-right">%<input type="text" style="width:30px;text-align:center" ng-model="discountPercentage" ng-change="discountPercentageEventListen(discountPercentage,vat)" > </span>
                      <span class="pull-right">
                                            {{ settings[0].currency_symbol }}
                                            <input type="text" style="width:40px;text-align:center" ng-change="discountAmountEventListen(discountAmount)" ng-model="discountAmount">
                                            </span>
                      </td>
                     S
                    </tr>
                  </table>


                </div>
              </div>




              <div class="box box-primary">
                <br>
                <div class="box-body no-padding">
                  <center>
                  <div ng-include="'resources/views/partials/app/calculator.blade.php'"></div>
                  </center>
                </div>
              </div>




            </div> -->


          </div>
<!--        </div>-->
              <!-- /.row -->
        </section><!-- /.content -->
