 <!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>Create Distributor</h1>
    </div>
  </section>
<!--INNER BANNER END--> 
 <span ng-init="name=''"></span> 
 <!-- Content Header (Page header) -->
        <!-- <section class="content-header">
          <h1>
            Distributor
            <small>Create</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX">distributor</li>
          </ol>
        </section> -->

        <!-- Main content -->
        <section class="content">
          <div class="row">
            <div class="col-md-3">
              &nbsp;
              <a href="#/directors" class="btn btn-primary btn-block margin-bottom"><i class="ionicons ion-ios-arrow-back"></i> &nbsp;Back to Home Page</a>

              <div class="sidebar-jobs">
                  <ul>
                    <li> <a href=""># no. <span class="pull-right">{{ directors.length }}</span></a>   </li>
                    <li> <a href=""></a> 
                    <span><i class="fa fa-circle"></i>name  <span class="pull-right" contenteditable="true" ng-model="name" ng-init="name=director.name" my-enter="updateDirectorEventListener(director,name)">{{ director.name }}</span> </span> 
                    </li>
                    <li> <a href=""> <span class="pull-right"></span></a>   </li>
                  
                  </ul>
              </div>
             
            </div><!-- /.col -->
            <div class="col-md-9">
              &nbsp;
              <div class="box box-primary">
                <div class="box-header with-border">
                  <h3 class="box-title">Compose New Distributor</h3>
                </div><!-- /.box-header -->
                <div class="box-body">
                  <div class="form-group">
                    <input class="form-control" placeholder="Enter Name" ng-model="name" ng-init="name=''"/>
                  </div>

                </div><!-- /.box-body -->
                <div class="box-footer">
                  <div class="pull-right">
                    <!-- <button class="btn btn-default"><i class="fa fa-pencil"></i> Draft</button> -->
                    <button type="button" class="btn btn-primary" ng-click="addDirectorEventListener(name)"> Save</button>
                  </div>
                  <a href="#/directors" class="btn btn-default"><i class="fa fa-times"></i> Close</a>
                </div><!-- /.box-footer -->
              </div><!-- /. box -->
            </div><!-- /.col -->
          </div><!-- /.row -->
        </section><!-- /.content -->