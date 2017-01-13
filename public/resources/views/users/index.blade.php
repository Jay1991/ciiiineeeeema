<!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>Users</h1>
    </div>
  </section>
<!--INNER BANNER END-->
<!-- Content Header (Page header) -->
        <!-- <section class="content-header">
          <h1 style="font: 400 13px/13px 'Roboto', sans-serif;color:#888">
            Users
            <small>List</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#/"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX">user</li>
          </ol>
        </section> -->

        <!-- Main content -->
        <section class="content" ng-clock>
          <div class="row">
            <div class="col-md-3">
              &nbsp;
              <div class="" style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;font: 400 13px/13px 'Roboto', sans-serif;color:#888">
                <div class="" style="padding:1px;">
                    <a 
                      href="#/users/create" 
                      class="btn btn-primary btn-block margin-bottom"
                      style="background:#1b8af3" 
                      >
                    create user
                    </a>

                    <div class="" style="border-top:0px;background-image: url({{ src }}{{ avatarX }});background-repeat: no-repeat; background-size: 100% auto;height:200px;background-color:#fff">
                                <center style="padding-top:30%">
                                  <button class="btn btn-default btn-lg" ng-click="avatarUploidEventListener()">
                                    <i class="fa fa-camera"></i>
                                  </button>
                                </center>

                              </div>
<!-- style="font: 400 16px/16px 'Roboto', sans-serif;color:#fff" -->
                    <!-- <div class="sidebar-jobs">
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
                              
                            </div>
                        </li>

                        


                      </ul>
                    </div> -->
                </div>
              </div>
            </div>
            <div class="col-md-9">
              &nbsp;
              <div class="box box-primary" style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;font: 400 13px/13px 'Roboto', sans-serif;color:#888">
                <div class="box-header with-border">
                  <h3 class="box-title" style="font-family:ubuntuX;color:#888"> 
                  user
                  </h3>
                  <div class="box-tools pull-right">
                    <div class="has-feedback">
                      <input type="text" class="form-control input-sm" placeholder="Search" ng-model="search"/>
                      <span class="glyphicon glyphicon-search form-control-feedback"></span>
                    </div>
                  </div>
                </div>
                <div class="box-body no-padding">
                  <div class="mailbox-controls">
                    <div class="btn-group">
                    </div><!-- /.btn-group -->
                    <button class="btn btn-default btn-sm"><i class="ionicons ion-refresh"></i></button>
                    <div class="pull-right">
                      {{ (users | filter:search).length }}/{{ users.length }}
                      <div class="btn-group">
                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-left"></i></button>
                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-right"></i></button>
                      </div><!-- /.btn-group -->
                    </div><!-- /.pull-right -->
                  </div>
                  <div class="">
                  <!-- table-responsive mailbox-messages -->
                    <table class="table table-bordered table-hover" style="font: 400 15px/22px 'Roboto', sans-serif;color:#888">
                      <thead >
                          <!-- <th></th> -->
                          <!-- <th></th> -->
                          <th>Name</th>
                          <th>Email</th>
                          <th>Privilege</th>
                          <th><span class="pull-right">Action</span></th>
                      </thead>
                      <tbody>
                        <tr ng-repeat='user in users | filter:search' ng-click="userEventListener(user)">
                          <!-- <td class="mailbox-star"><a href="#"><i class="fa text-yellow fa-star-o"></i></a></td> -->
                          <!-- <td><img class="img-thumbnail" src="{{ host }}/images/users/{{ user.avatar }}" style="width:40px;height:40px" alt="&nbsp;">
                          </td> -->
                          <td contenteditable="true" ng-model="name" ng-init="name=user.name" my-enter="updateUserEventListener(user,name,user.email,user.role_id)"> {{ user.name }} 
                          </td>
                          <td contenteditable="true" ng-model="email" ng-init="email=user.email" my-enter="updateUserEventListener(user,user.name, email,user.role_id)"> {{ user.email }} </td>
                          <td> {{ user.role.name }} </td>
                          
                          <td>
                            <button class="btn btn-default btn-sm pull-right" data-toggle="modal" data-target="#deleteUser" ng-click="deleteUserEventHandle(user)">X</button>
                          </td>
                        </tr>
                      </tbody>
                    </table><!-- /.table -->
                  </div><!-- /.mail-box-messages -->
                </div><!-- /.box-body -->
                <div class="box-footer no-padding">
                  <div class="mailbox-controls">
                    <!-- Check all button -->
                    <!-- <button class="btn btn-primary btn-sm checkbox-toggle"><i class="fa fa-square-o"></i></button>                     -->
                    <div class="btn-group">
                      <!-- <button class="btn btn-primary btn-sm"><i class="fa fa-trash-o"></i></button> -->
                      <!-- <button class="btn btn-primary btn-sm"><i class="fa fa-reply"></i></button> -->
                      <!-- <button class="btn btn-primary btn-sm"><i class="fa fa-share"></i></button> -->
                    </div><!-- /.btn-group -->
                    <!-- <button class="btn btn-primary btn-sm"><i class="fa fa-refresh"></i></button> -->
                    <div class="pull-right">
                      <!-- {{ (users | filter:search).length }}/{{ users.length }} -->
                      <div class="btn-group">
                        <!-- <button class="btn btn-primary btn-sm"><i class="fa fa-chevron-left"></i></button> -->
                        <!-- <button class="btn btn-primary btn-sm"><i class="fa fa-chevron-right"></i></button> -->
                      </div><!-- /.btn-group -->
                    </div><!-- /.pull-right -->
                  </div>
                </div>
              </div><!-- /. box -->
            </div><!-- /.col -->
          </div><!-- /.row -->
        </section><!-- /.content -->

<div ng-include="'resources/views/partials/users/delete.blade.php'"></div>
<input  type="file"   fileread="src" style="position:absolute;left:-2000px" id="avatarX" custom-on-change='customeOnChangeFileEventListener' ng-init="src = ''">
