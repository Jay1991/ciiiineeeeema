<!-- Angular Material style sheet -->
<link rel="stylesheet" href="http://ajax.googleapis.com/ajax/libs/angular_material/1.1.0/angular-material.min.css">

<div ng-init="x = datepicker()">
</div>
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/bootstrap/js/bootstrap.min.js')}}" type="text/javascript"></script> -->

<!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>Movies</h1>
    </div>
  </section>
<!--INNER BANNER END--> 
<!-- Content Header (Page header) -->
        <!-- <section class="content-header">
          <h1 style="font-family:ubuntu condensedX">
            Movies 
            <small>List</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX">movie</li>
          </ol>
        </section> -->
        <!-- Main content -->
        <section class="content" style="padding:0px">
          <div class="row" style="padding:0px">
            <div class="col-md-3">
              &nbsp;
              <div class="" style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;font: 400 13px/13px 'Roboto', sans-serif;color:#888">
                <div class="" style="padding:1px">

                  <a 
                    href="" 
                    class="btn btn-primary btn-block margin-bottom" 
                    ng-click="createMovieEventListener()"
                    style="background:#1b8af3"
                    >
                    Create Movie
                  </a>
                <!-- ng-if="movie.status !==  0 " -->
                  <div class="box box-solid" >
                      <div class="box-body no-padding">
                        <ul class="nav nav-pills nav-stacked" ng-if="movie != ''">
                          <!-- <li class="activeX"><a href="#movies"><center> <a>{{ movie.name }} </a></center> <span class="label label-primary pull-right"></span></a>
                          </li> -->
                          <li>
                            <div class="" ng-if="movie !== ''">
                              <div class="" style="border-top:0px;background-image: url({{ src }}{{ avatarX }});background-repeat: no-repeat; background-size: 100% auto;height:300px;background-color:#fff">

                                <center style="padding-top:30%">
                                  <button class="btn btn-default btn-lg" ng-click="avatarUploidEventListener()">
                                    <i class="fa fa-camera"></i>
                                  </button>
                                </center>

                              </div><!-- /.box-body -->
                            </div><!-- /.box -->

                          </li>
                         <!--  <li > Parental guidance  <select class="form-control" data-width="100%" data-live-search='true' ng-model="parental_guidance_id">  <option ng-repeat="parentalGuidance in parentalGuidances" value="{{ parentalGuidance.id }}"> {{ parentalGuidance.name }}</option></select></li>
                          <li > Director  <select class="form-control" data-width="100%" data-live-search='true' ng-model="director_id">  <option ng-repeat="director in directors" value="{{ director.id }}"> {{ director.name }}</option></select></li> -->
                          
                        </ul>
                      </div><!-- /.box-body -->
                  </div><!-- /. box -->
                  <div class="box box-solid">
                      <div class="box-body no-padding" >
                        <ul class="nav nav-pills nav-stacked">
                          <li>

                          <div class="form-group">
                                        <table style="width:100%">
                                          <tr style="width:100%">
                                            <td style="width:100%">
                                              <input 
                                                type="text" 
                                                class="datepicker passwordX"
                                                ng-model="date"
                                                ng-init = "date = ''"
                                                id="date"
                                                style="height:34px;float:none;border-bottom-width:0px;border-right-width:0px"
                                                >
                                            </td>
                                            <td valign="top">
                                              <button 
                                                class="btn btn-primary"
                                                ng-click="addDateEventListener(movie,date)"
                                                >
                                                Add Date {{ date }}
                                              </button>
                                            </td>
                                          </tr>
                                        </table>
                            </div>

                            <div ng-repeat="authdate in authdates | filter:{'movie_id': movie.id }:true"> 
                                      <span style="color:#1b8af3">
                                          {{ authdate.date.date }} - price: <span  contenteditable="true" ng-model="price" ng-init="price=authdate.price.figure" my-enter="priceEventHandle(authdate,price)" ng-blur="priceEventHandle(authdate,price)">{{ authdate.price.figure }} </span>
                                          <span class="pull-right" style="cursor:pointer" ng-click="deleteAuthDateEventListener(authdate)"> <i class="fa fa-times"></i> </span>
                                          <input 
                                            type="text" 
                                            class="passwordX" 
                                            ng-model="timer" 
                                            placeholder="03:43 PM" 
                                            my-enter="addTimeEventListener(authdate,timer)"
                                            style="border-width:0px;border-bottom-width:1px;height:34px"


                                            >

                                       </span>
                                        <br>

                                        <div ng-repeat="authtime in authtimes | filter:{'date_id': authdate.id }:true">

                                          <span style="color:#f44336">
                                              {{ authtime.time.starting_at }}
                                              <span class="pull-right" style="cursor:pointer" ng-click="deleteTimeEventListener(authtime)"> <i class="fa fa-times"></i> 
                                              </span> 
                                              <select 
                                                  class="passwordX" 
                                                  ng-model="screener" 
                                                  ng-change="addScreenEventListener(screener,authtime)"
                                                  style="background:#fff"

                                                >
                                                <option ng-repeat="screen in screens"  value="{{ screen.id }}"> {{ screen.name }} 
                                                </option>
                                              </select>
                                          </span>
                                          <br>
                                          <span ng-repeat="timeScreen in timeScreens | filter:{'time_id': authtime.id }:true">

                                            <div style="color:#8bc34a">
                                              {{ timeScreen.screen.name  }}
                                              <span class="pull-right" style="cursor:pointer" ng-click="deleteScreenEventListener(timeScreen)"> <i class="fa fa-times"></i> </span> 
                                            </div>
                                          </span>
                                        </div>

                             </div> 
                          </li>
                        </ul>
                      </div><!-- /.box-body -->
                  </div><!-- /. box -->
                  <div class="box box-solid" ng-if="movie !==''">
                      <div class="box-body no-padding" >
                        <ul class="nav nav-pills nav-stacked">
                          <li class="activeX">
                            <a href="#">
                              <i class="fa fa-clock-o"></i> 
                              Timer 
                              <span class="label label-primary pull-right"> {{ authtimes | filter:{''}.length  }} </span>
                            </a>
                          </li>
                        </ul>
                      </div><!-- /.box-body -->
                  </div><!-- /. box -->

                </div>
              </div>

              
            </div>
            <div class="col-md-9">
              &nbsp;
              <div class="box box-primary" style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;font: 400 13px/13px 'Roboto', sans-serif;color:#888">
                <div class="box-header with-border">
                  <h3 class="box-title" style="font-family:ubuntu condensedX;">movie 
                    <!-- <small> List</small> -->
                  </h3>
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
                    <button class="btn btn-default btn-sm checkbox-toggle"><i class="fa fa-square-o"></i></button>
                    <div class="btn-group">
                      <button class="btn btn-default btn-sm"><i class="fa fa-trash-o"></i></button>
                     
                    </div><!-- /.btn-group -->
                    <button class="btn btn-default btn-sm"><i class="fa fa-refresh"></i></button>
                    <div class="pull-right">
                       {{ (movies | filter:{'status':'1'} | filter:search).length }}/{{ (movies | filter:{'status':'1'}).length }}
                      <div class="btn-group">
                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-left"></i></button>
                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-right"></i></button>
                      </div><!-- /.btn-group -->
                    </div><!-- /.pull-right -->
                  </div>
                  <div class="table-responsive mailbox-messages">
                    <table class="table table-bordered table-hover" style="font: 400 15px/15px 'Roboto', sans-serif;color:#888">
                      <thead>
                          <!-- <th></th> -->
                          <th>Name</th>
                          <th>Parental Guidance</th>
                          <th>Distributor Name</th>
                          <th>Distributor Percentage</th>
                          <th>Timing</th>
                          <th><span class="pull-right">Action</span></th>
                      </thead>
                      <tbody>
                        <tr ng-repeat="movie in movies | filter:{'status':'1'} | filter:search" ng-click="movieEventListener(movie)">
                          <!-- <td> <img src="{{ host }}/images/items/{{ movie.avatar }}"   class="img-thumbnail" style="width:40px;height:40px;" alt="&nbsp;"></td> -->
                          <td contenteditable='true' ng-model="name"  ng-init="name = movie.name " my-enter="updateMovieEventListener(movie,name,movie.director_fee)"> {{ movie.name }} </td>
                          <td contenteditable='true' ng-model="parental_guidance_id"  ng-init="parental_guidance_id = movie.guidance.id " my-enter="updateMovieEventListener(movie,movie.name,parental_guidance_id)"> {{ movie.guidance.name }} </td>
                          <td> {{ movie.director.name }} </td>
                          <td contenteditable='true' ng-model="director_fee"  ng-init="director_fee = director_fee" my-enter="updateMovieEventListener(movie,movie.name,director_fee)"> {{ movie.director_fee }} </td>
                          <td> 
                              <span ng-repeat="authdate in authdates | filter:{'movie_id': movie.id }:true"> <span style="color:#1b8af3">
                                 {{ authdate.date.date }} </span>
                              
                                  <span ng-repeat="authtime in authtimes | filter:{'date_id': authdate.id }:true">

                                    <span style="color:#f44336">{{ authtime.time.starting_at }} </span>

                                    <span ng-repeat="timeScreen in timeScreens | filter:{'time_id': authtime.id }:true">

                                      <span style="color:#8bc34a">{{ timeScreen.screen.name  }}</span>
                                    </span>
                                  </span>
                                
                              </span> 
                          </td>
                          <td>
<!--                              {{ director.name }}-->
                              <div class="btn-group pull-right">
                                <!-- <a href="#/movies/edit" class="btn btn-default btn-sm" ng-click="movieEventListener(movie)"><i class="glyphicon glyphicon-pencil"></i></a> -->
                                <button class="btn btn-default btn-sm" data-toggle="modal" data-target="#deleteMovie" ng-click="deleteMovieEventListener(movie)">
                                <i class="fa fa-times"></i>
                                </button>
                              </div><!-- /.btn-group -->

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
                      
                    </div><!-- /.btn-group -->
                    <!-- <button class="btn btn-default btn-sm"><i class="fa fa-refresh"></i></button> -->
                   <!--  <div class="pull-right">
                      {{ (movies | filter:search).length }}/{{ movies.length }}
                      <div class="btn-group">
                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-left"></i></button>
                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-right"></i></button>
                      </div>
                    </div> -->
                  </div>
                </div>
              </div><!-- /. box -->
            </div><!-- /.col -->
          </div><!-- /.row -->
        </section><!-- /.content -->
<!-- <input type="text" class="datepicker" data-date-format="mm/dd/yyyy" ng-model="l" ng-change="x(l)">
 -->






<div ng-include="'resources/views/partials/movies/delete.blade.php'"></div>
<input  type="file"   fileread="src" style="position:absolute;left:-2000px" id="avatarX" custom-on-change='customeOnChangeFileEventListener' ng-init="src = ''">




