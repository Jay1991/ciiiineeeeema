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
          <div class="row">
            <div class="col-md-12">
                    <a href="#/movies/dates" class="btn btn-app"  style="width:200px;height:250px">
                         <center style="padding-top:10%"><i class="fa fa-chevron-left"></i></center>       
                    </a>
                

                    <a href="#/movies/dates/times/screens" class="btn btn-app" ng-repeat="authtime in authtimes | filter:{'date_id': authdate.id }:true" ng-click="timeEventListener(authtime)" style="width:200px;height:250px">

                    <span style="font-family:ubuntu"> {{ authtime.time.starting_at }} </span>
                                    
                    </a>


            </div>
          </div><!-- /.row -->
        </section><!-- /.content -->
