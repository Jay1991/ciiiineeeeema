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
          
                   
                    <a href="#/" class="btn btn-app" style="width:200px;height:250px;">
                         <center style="padding-top:40%"><i class="fa fa-chevron-left"></i></center>       
                    </a>

                    <a href="#/movies/dates" class="btn btn-app" ng-repeat="movie in movies | filter:search" ng-click="movieEventListener(movie)" 
                       ng-style="{'background-image':'url({{ host }}images/items/{{ movie.avatar }})'}"
                       style="border-top:0px; background-repeat: no-repeat; background-size: 100% auto;min-width:200px;height:250px;background-color:#fff">

                                    
                    </a>

                
            </div>
            
          </div><!-- /.row -->
        </section><!-- /.content -->













    



  





