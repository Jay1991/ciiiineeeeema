<!-- Angular Material style sheet -->
<link rel="stylesheet" href="http://ajax.googleapis.com/ajax/libs/angular_material/1.1.0/angular-material.min.css">
<div ng-init="x = datepicker()">
</div>

<!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>Creat Movie</h1>
    </div>
  </section>
<!--INNER BANNER END-->
<div class="col-md-12" ng-init="name='';url='';avatar='';timer='03:43 PM';directorer='';directorFee='';parentalGuidancer=''">
    
</div>
 <!-- Content Header (Page header) -->
       <!--  <section class="content-header">
          <h1>
            Movie
            <small>Create</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#/movies"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX">Movie</li>
          </ol>
        </section> -->
        <!-- Main content -->
        <section class="content">
          <div class="row">
            <div class="col-md-3">
              &nbsp;
              <div class="" class="box box-primary" style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;">
                <div class="" style="padding:0px">

                  <a 
                    href="#/movies" 
                    class="btn btn-primary btn-block margin-bottom"
                    style="background:#1b8af3"
                    >
                    <i class="ionicons ion-ios-arrow-back"></i> 
                    &nbsp; Back to Home Page
                  </a>
                <!-- ng-if="movie.status !==  0 " -->
                  <div >
                    
                    <div class="box box-solid">
                      <div class="box-body no-padding" >
                        <ul class="nav nav-pills nav-stacked">
                          <li>
                          
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

                    <div class="" ng-if="movie !== ''">
                      <div class="" style="border-top:0px;background-image: url({{ src }}{{ avatarX }});background-repeat: no-repeat; background-size: 100% auto;height:300px;background-color:#fff">

                        <center style="padding-top:30%">
                          <button class="btn btn-default btn-lg" ng-click="avatarUploidEventListener()">
                            <i class="fa fa-camera"></i>
                          </button>
                        </center>

                      </div><!-- /.box-body -->
                    </div><!-- /.box -->
                  </div>

                </div>
              </div>

              
            </div>
            <div class="col-md-9">
              &nbsp;
              <div class="box box-primary" style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;">
                <!-- <div class="box-header with-border">
                  <h3 class="box-title">Create New Movie</h3>
                </div> -->
                <div class="box-body">
                  <div class="form-group">
                    <label>Name *</label>
                    <input 
                        type="text" 
                        placeholder="" 
                        ng-model='name' 
                        class='passwordX'
                        style="border-width:0px;border-bottom-width:1px;height:34px"
                        >
                  </div>
                  <div class="form-group">
                    <label>Parental Guidance *</label>
                
                    <select 
                          ng-model="parentalGuidancer" 
                          class="form-control"
                          data-width="100%"
                          data-search-live="true"
                          style="height:43px"

                           >
                          <option 
                          class="small-font"
                          ng-repeat="parentalGuidance in parentalGuidances" 
                          value="{{ parentalGuidance.id }}"
                          
                          > 
                          {{ parentalGuidance.name }}
                          </option>
                    </select>
                  </div>

                  <div class="form-group">
                    <label>Distributor *</label>
                    <select 
                        ng-model="directorer" 
                        class="form-control" 
                        style="height:43px"
                        >
                        <option 
                        ng-repeat="director in directors" 
                        value="{{ director.id }}"
                        > 
                        {{ director.name }}
                        </option>
                    </select>
                  </div>

                  <div class="form-group">
                    <label>Director Commision %</label>
                    <input 
                         type="text" 
                         class="passwordX" 
                         ng-model="directorFee" 
                         placeholder="" 
                         style="border-width:0px;border-bottom-width:1px;height:34px"

                         >
                  </div>


                  <div class="form-group">
                      <label>Cover Url</label>
                      <input 
                        type="text" 
                        placeholder=""  
                        ng-model="url" 
                        class='passwordX' 
                        style="border-width:0px;border-bottom-width:1px;height:34px"

                        >
                  </div>
                  <div class="form-group">
                      <label>Browse Cover File</label>
                      <input  type="file"   fileread="avatar">
                      <img src="{{avatar}}" width="100" height="50" alt="">
                  </div>

                  <div class="form-group">
                    <div class="col-md-4" style="padding:0px">
                     <div class="box box-danger">
                                    <div class="box-header">
                                      <h3 class="box-title">Date</h3>
                                      <!-- <md-content layout-padding>
                                        <div layout-gt-xs="row">
                                          <div flex-gt-xs> -->
                                            <!-- <md-datepicker ng-model="myDate" md-placeholder="Enter date" ng-change="addDateEventListener(movie,myDate)">
                                              
                                            </md-datepicker> -->
                                         <!--  </div>
                                        </div>
                                      </md-content> -->

                                      <!--  <input class="datepicker" ng-model="myDate" ng-change="addDateEventListener(movie,myDate)"> -->
                                      <div class="form-group">
                                        <table style="width:100%">
                                          <tr style="width:100%">
                                            <td style="width:100%">
                                              <input 
                                                type="text" 
                                                class="datepicker form-control"
                                                ng-model="date"
                                                ng-init = "date = ''"
                                                id="date"
                                                >
                                            </td>
                                            <td>
                                              <button 
                                                class="btn btn-primary"
                                                ng-click="addDateEventListener(movie,date)"
                                                >
                                                Add Date
                                              </button>
                                            </td>
                                          </tr>
                                        </table>
                                      </div>

                                    </div>
                                    <div class="box-body">
                                    
                                      <div class="list-group">
                                        <ul class="nav nav-pills nav-stacked">
                                          <li  ng-repeat="authdate in authdates | filter:{'movie_id': movie.id }:true" ng-click="dateEventListener(authdate)"> 
                                              {{ authdate.date.date }}  
                                              <i class="fa fa-times pull-right" style="color:#1b8af3;cursor:pointer" ng-click="deleteAuthDateEventListener(authdate)"></i> 
                                              <div style="color:#1b8af3">price / seat</div>

                                              <input 
                                                type="text" 
                                                class="form-control" 
                                                ng-model="price" 
                                                ng-init="price=authdate.price.figure" ng-blur="priceEventHandle(authdate,price)"
                                                style="border-width:0px;border-bottom-width:1px;height:34px"

                                              >
                                        
                                          </li>
                                         
                                        </ul>
                                      </div>

                                    </div><!-- /.box-body -->
                     </div><!-- /.box -->
                    </div>
                  </div>

                  <div class="form-group">
                    <div class="col-md-4" ng-if="authdate !== ''" >
                      <div class="box box-danger">
                                      <div class="box-header">
                                        <h3 class="box-title">Time Picker</h3>
                                        <input type="text" class="form-control timepicker" ng-model="timer" placeholder="03:43 PM" my-enter="addTimeEventListener(authdate,timer)">

                                      </div>
                                      <div class="box-body">
                                      
                                        <div class="list-group">
                                          <a href="#/movies/create" class="list-group-item" ng-repeat="authtime in authtimes | filter:{'date_id': authdate.id }:true" ng-click="timeEventListener(authtime)">
                                            <!-- <h4 class="list-group-item-heading">Third List Group Item Heading</h4> -->
                                            <p class="list-group-item-text">
                                              <!-- <i class="fa fa-circle" style="color: #1b8af3"></i> -->
                                              {{ authtime.time.starting_at }}
                                              <i class="fa fa-times pull-right" style="color: #1b8af3;cursor:pointer" ng-click="deleteTimeEventListener(authtime)">
                                              </i>
                                            </p>
                                          </a>
                                        </div>

                                      </div><!-- /.box-body -->
                      </div><!-- /.box -->
                    </div>
                  </div>

                  <div class="form-group">
                    <div class="col-md-4" ng-if="authtime !== ''" >
                      <div class="box box-danger">
                                      <div class="box-header">
                                        <h3 class="box-title">Screens</h3>
                                        <select class="form-control" ng-model="screener" ng-change="addScreenEventListener(screener,authtime)">
                                          <option ng-repeat="screen in screens"  value="{{ screen.id }}"> {{ screen.name }} 
                                          </option>
                                        </select>
                                      </div>
                                      <div class="box-body">
                                      
                                        <div class="list-group">
                                          <a href="#/movies/create" class="list-group-item" ng-repeat="timeScreen in timeScreens | filter:{'time_id': authtime.id }:true">
                                            <!-- <h4 class="list-group-item-heading">Third List Group Item Heading</h4> -->
                                            <p class="list-group-item-text">
                                              {{ timeScreen.screen.name }}
                                              <i class="fa fa-times pull-right" style="color: #1b8af3;cursor:pointer" ng-click="deleteScreenEventListener(timeScreen)">
                                              </i>
                                            </p>
                                          </a>
                                        </div>

                                      </div><!-- /.box-body -->
                      </div><!-- /.box -->
                    </div>
                  </div>

                </div><!-- /.box-body -->
                <div class="box-footer">
                  <div class="pull-right">
                    <!-- <button class="btn btn-default"><i class="fa fa-pencil"></i> Draft</button> -->
                    <button type="submit" class="btn btn-primary" ng-click="addMovieEventListener(name,url,avatar,parentalGuidancer,directorer,directorFee,movie)"> <i class="glyphicon glyphicon-save"></i> Save</button>
                  </div>
                  <a class="btn btn-default" href="#/movies"><i class="fa fa-times"></i> Close</a>
                </div><!-- /.box-footer -->
              </div><!-- /. box -->
            </div><!-- /.col -->
          </div><!-- /.row -->
        </section><!-- /.content -->
}


<div class="alert alert-danger" ng-show="online">
    Internet not connected .... 
</div>





<div class="col-md-12"></div>



<div ng-include="'resources/views/partials/times/create.blade.php'"></div>









    



  





