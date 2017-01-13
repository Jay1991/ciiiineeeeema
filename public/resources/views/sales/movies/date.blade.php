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
           
      

                    <a href="#/movies" class="btn btn-app" style="width:200px;height:250px">
                         <center style="padding-top:10%"><i class="fa fa-chevron-left" ></i></center>       
                    </a>

                   
                    <a href="#/movies/dates/times" class="btn btn-app" ng-repeat="authdate in authdates | filter:{'movie_id': movie.id }:true" ng-click="dateEventListener(authdate)" style="width:200px;height:250px">

                      <span style="font-family:ubuntu"> {{ authdate.date.date }} </span>
                        
                                    
                    </a>

                 

              </div>
          </div><!-- /.row -->
        </section><!-- /.content -->
