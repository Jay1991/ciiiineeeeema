<!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>Create Screen</h1>
    </div>
  </section>
<!--INNER BANNER END--> 
<span  ng-init="name='';rowNumber=''"></span>
 <!-- Content Header (Page header) -->
       <!--  <section class="content-header">
          <h1>
            Screen 
            <small>Create</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#/"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX"> <a href="#/screens">screens </a></li>
          </ol>
        </section> -->

        <!-- Main content -->
        <section class="content">
          <div class="row">
            <div class="col-md-3">
              &nbsp;
              <div class="box box-primary">
                <div class="box box-body" style="padding:0px">
                  <a href="#/screens" class="btn btn-primary btn-block margin-bottom"><i class="ionicons ion-ios-arrow-back"></i> &nbsp;Back to Home Page</a>
                
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
                      <input class='form-control'  ng-change='addRowsEventListener(screen,rowNumber,screen.name)' ng-model="rowNumber" placeholder="Edit rows number">  
                      <ul class="nav nav-pills nav-stacked">
                        <li class="activeX"><a href="#/screens"><br> <center> {{ screen.name }} </center> </a></li>
                        <li ng-repeat="row in rows | filter:{'screen_id': screen.id }:true"> 
                        #{{ row.number }} 
                        <!-- <span class="label label-primary pull-right">12</span> -->
                        <div>  
                              <label> code </label>
                              <input type='text'  class='form-control' ng-model="code"  ng-blur="updateRowEventListener(row,code)" ng-init ="code=row.code"> 
                              <label> Seat # </label>
                              <input type='text'  class='form-control' ng-model="seatNumber" ng-blur='addSeatEventListen(row,seatNumber)' ng-init ="seatNumber=(seats | filter:{'row_id': row.id }:true).length">
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
                  <h3 class="box-title"><span style="color:#888"> Create New Screen </span></h3>
                </div>
                <div class="box-body">
                  
					<div class='form-group'>
					                          <!-- <label> Name *</label> -->
					                          <input class='form-control' ng-model="name" placeholder="Name *">
					                          <!-- ng-blur="addScreenTempEventListener(name)" -->
					 </div>

					 <!-- rowNumber = (rows | filter:{'screen_id': screen.id }:true).length -->
					<div class='form-group'>
					                          <!-- <label> Total Rows # *</label> -->
					                          <input class='form-control'  ng-change='addRowsEventListener(screen,rowNumber,name)' ng-model="rowNumber" placeholder="Total Rows # *">            
					</div>

					<div class="list-group" ng-if="screen !==''">
						<a href="" class="list-group-item" ng-repeat="row in rows | filter:{'screen_id': screen.id }:true">
						    <!-- <h4 class="list-group-item-heading"> Rows </h4> -->
						    <span class='pull-right'>  
						        <label> code </label>
						        <input type='text' style='width:100px' class=' ' ng-model="code"  ng-blur="updateRowEventListener(row,code)" ng-init ="code=row.code"> 
						        <label> Seat # </label>
						        <input type='text' style='width:100px' class=' ' ng-model="seatNumber" ng-blur='addSeatEventListen(row,seatNumber)' ng-init ="seatNumber=(seats | filter:{'row_id': row.id }:true).length">
						    </span>
						    <p class="list-group-item-text"> #{{ row.number }}
						    
						    </p>
						</a>
					</div>

          
                </div><!-- /.box-body -->
                <div class="box-footer">
                  <div class="pull-right">
                    <!-- <button class="btn btn-default"><i class="fa fa-pencil"></i> Draft</button> -->
                    <button type="submit" class="btn btn-primary" ng-click="addScreenEventListener(screen,name)"> <i class="glyphicon glyphicon-save"></i> Save</button>
                  </div>
                  <a class="btn btn-default" href="#/screens"><i class="fa fa-times"></i> Close</a>
                </div><!-- /.box-footer -->
              </div><!-- /. box -->
            </div><!-- /.col -->
          </div><!-- /.row -->
        </section><!-- /.content -->



<div class="alert alert-danger" ng-show="online">
    Internet not connected .... 
</div>

















    



  














