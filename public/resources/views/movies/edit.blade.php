<span class="col-md-12" ng-init="name=movie.name;url='';avatar='';timer='03:43 PM';directorer=movie.director.id;directorFee=movie.director_fee;parentalGuidancer=''">
</span>

 <!-- Content Header (Page header) -->
        <section class="content-header">
          <h1>
            Movie 
            <small>Edit</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX">Mailbox</li>
          </ol>
        </section>

        <div class="alert alert-danger" ng-show="online">
            Internet not connected .... 
        </div>

        <!-- Main content -->
        <section class="content">
          <div class="row">
            <div class="col-md-3">
              <a href="#/movies" class="btn btn-primary btn-block margin-bottom">Back to Home</a>
              <div class="box box-solid">
                <div class="box-header with-border">
                  <h3 class="box-title">Folders</h3>
                  <div class='box-tools'>
                    <button class='btn btn-box-tool' data-widget='collapse'><i class='fa fa-minus'></i></button>
                  </div>
                </div>
                <div class="box-body no-padding">
                  <ul class="nav nav-pills nav-stacked">
                    <li><a href="mailbox.html"><i class="fa fa-inbox"></i> Inbox <span class="label label-primary pull-right">12</span></a></li>
                    <li><a href="#"><i class="fa fa-envelope-o"></i> Sent</a></li>
                    <li><a href="#"><i class="fa fa-file-text-o"></i> Drafts</a></li>
                    <li><a href="#"><i class="fa fa-filter"></i> Junk <span class="label label-waring pull-right">65</span></a></li>
                    <li><a href="#"><i class="fa fa-trash-o"></i> Trash</a></li>
                  </ul>
                </div><!-- /.box-body -->
              </div><!-- /. box -->
              <div class="box box-solid">
                <div class="box-header with-border">
                  <h3 class="box-title">Labels</h3>
                  <div class='box-tools'>
                    <button class='btn btn-box-tool' data-widget='collapse'><i class='fa fa-minus'></i></button>
                  </div>
                </div><!-- /.box-header -->
                <div class="box-body no-padding">
                  <ul class="nav nav-pills nav-stacked">
                    <li><a href="#"><i class="fa fa-circle-o text-red"></i> Important</a></li>
                    <li><a href="#"><i class="fa fa-circle-o text-yellow"></i> Promotions</a></li>
                    <li><a href="#"><i class="fa fa-circle-o text-light-blue"></i> Social</a></li>
                  </ul>
                </div><!-- /.box-body -->
              </div><!-- /.box -->
            </div><!-- /.col -->
            <div class="col-md-9">
              <div class="box box-primary">
                <div class="box-header with-border">
                  <h3 class="box-title">Edit Movie</h3>
                </div><!-- /.box-header -->
                <div class="box-body">
                  <div class="form-group">
                    <!-- <label>Name *</label> -->
                    <input type="text" placeholder="Enter Movie Name *" ng-model='name' class='form-control' style="height:43px">
                  </div>
                  <div class="form-group">
                    <label>Parental Guidance *</label>
                    <select ng-model="parentalGuidancer" class='form-control' data-live-search='true' >
                      <option ng-repeat="parentalGuidance in parentalGuidances" value="{{ parentalGuidance.id }}"> {{ parentalGuidance.name }}</option>
                    </select>
                  </div>

                  <div class="form-group">
                    <label>Director *</label>
                    <select  class="form-control" ng-model="directorer">
                      <option ng-repeat="director in directors" value="{{ director.id }}"> {{ director.name }}</option>
                    </select>
                  </div>

                  <div class="form-group">
                    <!-- <label>Director Fee *</label> -->
                    <input type="text" class="form-control" ng-model="directorFee" placeholder="Director Fee *">
                  </div>


                  <div class="form-group">
                      <!-- <label>Cover Url</label> -->
                      <input type="text" placeholder="Cover Url"  ng-model="url" class='form-control'>
                  </div>
                  <div class="form-group">
                      <label>Browse Cover File</label>
                      <input  type="file"   fileread="avatar">
                      <img src="{{avatar}}" width="100" height="50" alt="">
                  </div>

                  <div class="form-group">
                    <div class="col-md-4" >
                     <div class="box box-danger">
                                    <div class="box-header">
                                      <h3 class="box-title">Date</h3>
                                      <md-datepicker ng-model="myDate" md-placeholder="Enter date" ng-change="addDateEventListener(movie,myDate)"></md-datepicker>
                                    </div>
                                    <div class="box-body">
                                    
                                      <div class="list-group">
                                        <a href="#/movies/create" class="list-group-item" ng-repeat="authdate in authdates | filter:{'movie_id':border-bottom-width movie.id }:true" ng-click="dateEventListener(authdate)">
                                          <!-- <h4 class="list-group-item-heading">Third List Group Item Heading</h4> -->
                                          <p class="list-group-item-text">
                                            {{ authdate.date.date }}
                                            <i class="fa fa-times pull-right" style="color:#1b8af3" ng-click="deleteAuthDateEventListener(authdate)"></i>
                                          </p>
                                        </a>
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
                                          <a href="#/movies/create" class="list-group-item" ng-repeat="authtime in authtimes | filter:{'date_id':border-bottom-width authdate.date.id }:true" ng-click="timeEventListener(authtime)">
                                            <!-- <h4 class="list-group-item-heading">Third List Group Item Heading</h4> -->
                                            <p class="list-group-item-text">
                                              <i class="fa fa-circle" style="color: #1b8af3"></i>
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
                                          <a href="#/movies/create" class="list-group-item" ng-repeat="timeScreen in timeScreens | filter:{'time_id':border-bottom-width authtime.id }:true">
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



<div ng-include="'resources/views/partials/times/create.blade.php'"></div>









    



  





