 <!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>Create user</h1>
    </div>
  </section>
  <!--INNER BANNER END--> 
 <input type="hidden" name="_token" value="{{ csrf_token() }}" ng-init="name='';email='';role_id='';password='';password_confirmation='';avatar='';url=''">

        <!-- <section class="content-header">
          <h1>
            User
            <small>Create New</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#/"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX">user</li>
          </ol>
        </section> -->

        <!-- Main content -->
        <section class="content">
          <div class="row">
            <div class="col-md-3">
              &nbsp;
              <div class="box box-primary">
                <div class="box box-body" style="padding:0px">
                    <a href="#/users" class="btn btn-primary btn-block margin-bottom" > <i class="ionicons ion-ios-arrow-back"></i> &nbsp;Back to Home Page </a>

                    <div class="sidebar-jobs">
                      <ul>
                        <li> <a href=""></a> 
                             <span>
                                <span class="pull-left" style="color:#888 !important"> 
                                   <i class="fa fa-inbox"></i>
                                   {{ user.name }} 
                                </span>
                             </span> 
                        </li>

                        <li> <a href=""></a> 
                             <span>
                                <i class="fa fa-envelope-o"></i>
                                Email <span class="pull-right" style="color:#888 !important"> {{ user.email }} </span>
                             </span> 
                        </li>
                        <li> <a href=""></a> 
                             <span>
                                <i class="fa fa-inbox"></i>
                                Privilege <span class="pull-right" style="color:#888 !important"> {{ user.role.name }} </span>
                             </span> 
                        </li>

                        <li> 
                          <div class="" ng-if="user !== ''">
                            <span style="font: 400 13px/13px 'Roboto', sans-serif;color:#888">Privilege</span>
                            <select class="form-control" ng-model="role_id" ng-init="role_id = ''" ng-change="updateUserEventListener(user,user.name, user.email,role_id)"><option ng-repeat="role in roles" value="{{ role.id }}"> {{ role.name }}</option></select>
                          </div>
                        </li>

                        <li> 
                            <div class="box box-default" ng-if="user !== ''">
                              <div class="" style="border-top:0px;background-image: url({{ src }}{{ avatarX }});background-repeat: no-repeat; background-size: 100% auto;height:200px;background-color:#fff">
                                <center style="padding-top:30%">
                                  <button class="btn btn-default btn-lg" ng-click="avatarUploidEventListener()">
                                    <i class="fa fa-camera"></i>
                                  </button>
                                </center>

                              </div><!-- /.box-body -->
                            </div><!-- /.box -->
                        </li>

                        


                      </ul>
                    </div>
                </div>
              </div>
            </div>
            <div class="col-md-9">
              &nbsp;
              <div class="box box-primary">
                <div class="box-header with-border">
                  <h3 class="box-title">Compose New User</h3>
                </div><!-- /.box-header -->
                <div class="box-body">
                  
                 <div class='form-group'>
                    <!-- <label> Name *</label> -->
                    <input class='form-control'  ng-model="name" placeholder="Name *">
                 </div>
                 <div class='form-group'>
                    <div class="input-group">
                          <span class="input-group-addon" style="color:#888">Role *</span>
                          <select class="form-control" ng-model="role_id">
                            <option ng-repeat="role in roles" value="{{ role.id }}" data-width='100%' data-live-search="true"> {{ role.name }} 
                            </option>
                         </select>
                      </div>

                   <!-- <label>Role *</label>
                   <select class="form-control" ng-model="role_id">
                      <option ng-repeat="role in roles" value="{{ role.id }}" data-width='100%' data-live-search="true"> {{ role.name }} 
                      </option>
                   </select> -->
                 </div>

                 <div class='form-group'>
                    <!-- <label> Email *</label> -->
                    <input class='form-control'  ng-model="email" placeholder="Email *">
                 </div>

                 <div class='form-group'>
                    <!-- <label> Password *</label> -->
                    <input type="password" class='form-control'  ng-model="password" placeholder="Password *">
                 </div>

                 <div class='form-group'>
                    <!-- <label> Confirm Password *</label> -->
                    <input type="password" class='form-control'  ng-model="password_confirmation" placeholder="Confirm Password *">
                 </div>


                 <div class="form-group">
                    <label for="exampleInputFile">Uploid Image</label>
                    <input id="exampleInputFile" type="file"   fileread="avatar">
                    <img src="{{avatar}}" width="100" height="50" alt="Image preview...">
                 </div>

                 <div class='form-group'>
                  <!-- <label> Image Url</label> -->
                  <input type="text" class='form-control' ng-model="url" placeholder="Image Url">
                 </div>

                </div><!-- /.box-body -->
                <div class="box-footer">
                  <div class="pull-right">
                    <!-- <button class="btn btn-default"><i class="fa fa-pencil"></i> Draft</button> -->
                    <button type="submit" class="btn btn-primary" ng-click="addUserEventListener(name,role_id,email,password,password_confirmation,avatar,url)"> Save</button>
                  </div>
                  <a href="#/users" class="btn btn-default"><i class="fa fa-times"></i> Close</a>
                </div><!-- /.box-footer -->
              </div><!-- /. box -->
            </div><!-- /.col -->
          </div><!-- /.row -->
        </section><!-- /.content -->


