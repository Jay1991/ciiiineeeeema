<!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>Screens</h1>
    </div>
  </section>
<!--INNER BANNER END--> 
<!-- Content Header (Page header) -->
        <!-- <section class="content-header">
          <h1 style="font-family:ubuntu condensedX">
            Screens 
            <small>List</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#/"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX"> screen</li>
          </ol>
        </section> -->
        <!-- Main content -->
        <section class="content">
          <div class="row">
            <div class="col-md-3">
              &nbsp;
              <div class="box box-primary">
                <div class="box box-body" style="padding:0px">
                  <a href="#/screens/create" class="btn btn-primary btn-block margin-bottom" ng-click="createScreenEventListener()">Create screen</a>
                
                  <div class="box box-solid">
                    <!-- <div class="box-header with-border">
                      <h3 class="box-title"></h3>
                      <div class='box-tools'>
                        <button class='btn btn-box-tool' data-widget='collapse'><i class='fa fa-minus'></i></button>
                      </div>
                    </div> -->
                    <div class="box-body no-padding">
                      <ul class="nav nav-pills nav-stacked">
                        <li><a href=""><i class="fa fa-circle" style="color:#1b8af3"></i> no. <span class="label label-primary pull-right"> {{ (screens | filter:{'status':'1'}).length }}</span></a></li>
                      </ul>
                    </div>
                  </div>

                  <div class="box box-solid" >
                    <!-- <div class="box-header with-border">
                      <h3 class="box-title"></h3>
                      <div class='box-tools'>
                        <button class='btn btn-box-tool' data-widget='collapse'><i class='fa fa-minus'></i></button>
                      </div>
                    </div> -->
                    <div class="box-body no-padding">
                      <input 
                           class='form-control'  ng-change='addRowsEventListener(screen,rowNumber,screen.name)' ng-model="rowNumber" placeholder="Edit rows number">  
                      <ul class="nav nav-pills nav-stacked">
                        <li class="activeX"><a href="#/screens"><br> <center> {{ screen.name }} </center> </a></li>
                        <li ng-repeat="row in rows | filter:{'screen_id': screen.id }:true"> 
                        #{{ row.number }} 
                        <!-- <span class="label label-primary pull-right">12</span> -->
                        <div>  
                              <label> code </label>
                              <input type='text'  class='form-control' ng-model="code"  ng-blur="updateRowEventListener(row,code)" my-enter="updateRowEventListener(row,code)" ng-init ="code=row.code"> 
                              <label> Seat # </label>
                              <input type='text'  class='form-control' ng-model="seatNumber" ng-blur='addSeatEventListen(row,seatNumber)' my-enter='addSeatEventListen(row,seatNumber)' ng-init ="seatNumber=(seats | filter:{'row_id': row.id }:true).length">
                        </div>


                        </li>
                      </ul>
                    </div>
                  </div>
                </div>
              </div>

           
            </div><!-- /.col -->
            <div class="col-md-9">
              &nbsp;
              <div class="box box-primary">
                <div class="box-header with-border">
                  <h3 class="box-title" style="font-family:ubuntuX"> Screen <!-- <small>  List </small> --></h3>
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
                    <button class="btn btn-default btn-sm"><i class="ionicons ion-refresh"></i></button>
                    <div class="pull-right">
                       {{ (screens | filter:{'status':'1'} | filter:search).length }}/{{ (screens | filter:{'status':'1'}).length }}
                      <div class="btn-group">
                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-left"></i></button>
                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-right"></i></button>
                      </div><!-- /.btn-group -->
                    </div><!-- /.pull-right -->
                  </div>
                  <div class="">
                  <!-- table-responsive mailbox-messages -->
                      <table class="table table-bordered table-hover" style="font: 400 14px/22px 'Roboto', sans-serif;color:#888">
                        <thead style="color:#888">
                            <th>Name</th>
                            <th>Rows</th>
                            <th>Action</th>
                        </thead>
                        <tbody>
                          <tr ng-repeat="screen in screens | filter:{'status':'1'} | filter:search" ng-click="screenEventListener(screen)">
                            <td contenteditable='true' ng-model="name"  ng-init="name = screen.name " my-enter="updateScreenEventListener(screen,name)"> {{ screen.name }} </td>
                            <td> 
                              <div ng-repeat="row in rows | filter:{'screen_id': screen.id }:true"> 
                                  #{{ row.number }}
                                  <br>
                                  <span ng-repeat="seat in seats | filter:{'row_id': row.id }:true"> 
                                    <span  class="btn btn-app" style="font-family:ubuntu;color:#888">{{ seat.row.code }} {{ seat.number }} </span>   
                                  </span>
                              </div> 
                            </td>
                            <td>
                              <button class="btn btn-default btn-sm" data-toggle="modal" data-target="#deleteScreen" ng-click="deleteScreenEventListener(screen)">X</button>
                            </td>
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

<div ng-include="'resources/views/partials/screens/delete.blade.php'"></div>
<input  type="file"   fileread="src" style="position:absolute;left:-2000px" id="avatarX" custom-on-change='customeOnChangeFileEventListener' ng-init="src = ''">



 




