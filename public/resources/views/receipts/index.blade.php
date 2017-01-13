<!-- Content Header (Page header) -->
        <section class="content-header">
          <h1>
            Receipts 
            <small>List</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX">receipt</li>
          </ol>
        </section>

        <!-- Main content -->
        <section class="content">
          <div class="row">
            <div class="col-md-3">
              <div class="box box-solid">
               <div class="box-body no-padding">
                  <ul class="nav nav-pills nav-stacked">
                    <li ><a href="#/consessions"> no. <span class="pull-right">{{ receipts.length }}</span></a></li>
                
                  </ul>
               </div><!-- /.box-body -->
              </div>

              <div class="box box-solid" ng-if="receipt !==''">
               <div class="box-header with-border">
                  <h3 class="box-title" style="">Summary</h3>
                  <div class="box-tools">
                    <button class="btn btn-box-tool" data-widget="collapse"><i class="fa fa-minus"></i></button>
                  </div>
               </div>
               <div class="box-body no-padding">
                  <ul class="nav nav-pills nav-stacked">
                    <li class="activeX"><a href="#/consessions"><i class="fa fa-inbox"></i> # <span class="pull-right">{{ receipt.number }}</span></a></li>
                    <li><a href="#/consessions"><i class="fa fa-money"></i> Vat Amount <span class="label label-primary pull-right">{{ receipt.VAT }}</span></a></li>
                    <li><a href="#/consessions"><i class="fa fa-money"></i> Discount <span class="label label-primary pull-right">{{ receipt.discount }}</span></a></li>
                    <li><a href="#/consessions"><i class="fa fa-money"></i> Sub Total <span class="label label-primary pull-right">{{ receipt.sub_total }}</span></a></li>
                    <li><a href="#/consessions"><i class="fa fa-money"></i> Total <span class="label label-primary pull-right">{{ receipt.total }}</span></a></li>
                    
                    
                  </ul>
               </div><!-- /.box-body -->
              </div>

              <div class="box box-solid" ng-if="receipt !==''">
               <div class="box-body no-padding">
                  <ul class="nav nav-pills nav-stacked">
                    <li ng-repeat="temp in temps | filter:{'receipt_id':border-bottom-width receipt.id }"><a href="#/consessions"> {{ temp.row.code }} {{ temp.seat.number }} <span class="label label-primary pull-right">{{ temp.price.figure }}</span></a></li>
                  </ul>
               </div><!-- /.box-body -->
              </div>

               <div class="box box-solid" ng-if="receipt !==''">
               <div class="box-body no-padding">
                  <ul class="nav nav-pills nav-stacked">
                    <li ng-repeat="sale in sales | filter:{'receipt_id':border-bottom-width receipt.id }"><a href="#/consessions">  {{ sale.item.name }} *  {{ sale.quantity }}<span class="label label-primary pull-right">{{ sale.total_selling }}</span></a></li>
                  </ul>
               </div><!-- /.box-body -->
              </div>

              <a href="" class="btn btn-primary btn-block margin-bottom" style="" ng-click="rePrintEventListener(receipt)" ng-if="receipt !==''"><i class="fa fa-print"></i><!-- Re -<i>print</i> --></a>

            </div><!-- /.col -->
            <div class="col-md-9">
              <div class="box box-primary">
                <div class="box-header with-border">
                  <h3 class="box-title">Receipt <small> List </small></h3>
                  <div class="box-tools pull-right">
                    <div class="has-feedback">
                      <input type="text" class="form-control input-sm" placeholder="Search" ng-model="search" />
                      <span class="glyphicon glyphicon-search form-control-feedback"></span>
                    </div>
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
                    <!-- <button class="btn btn-default btn-sm"><i class="fa fa-refresh"></i></button> -->
                    <div class="pull-right">
                       <!-- {{ (directors | filter:search).length }}/{{ directors.length }} -->
                      <div class="btn-group">
                        <!-- <button class="btn btn-default btn-sm"><i class="fa fa-chevron-left"></i></button> -->
                        <!-- <button class="btn btn-default btn-sm"><i class="fa fa-chevron-right"></i></button> -->
                      </div><!-- /.btn-group -->
                    </div><!-- /.pull-right -->
                  </div>
                  <div class="table-responsive mailbox-messages">
                    <table class="table table-bordered table-striped">
                      <tbody>
                        <tr ng-repeat="receipt in receipts | filter:search" ng-click="receiptEventHandle(receipt)">
                          <td class="mailbox-star" style="width:25px" contenteditable="true"><a href="#"><i class="fa text-yellow fa-star-o"></i></a></td>
                          <td contenteditable="true">{{ receipt.number }}</td>
                        </tr>
                      </tbody>
                    </table><!-- /.table -->
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
                      <!-- {{ (directors | filter:search).length }}/{{ directors.length }} -->
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

<div ng-include="'resources/views/partials/directors/delete.blade.php'"></div>