<!DOCTYPE html>
<html ng-app="app">
  <head>
    <meta charset="UTF-8">
    <title>{{ App\Setting::find(1)->app_name }} | Dashboard</title>
    <meta content='width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no' name='viewport'>
    
    <!--CUSTOM CSS-->
    <link href="{{ asset('/lib/temp-jobinn-v-1.2.0/css/custom.css') }}" rel="stylesheet" type="text/css">
    <!--BOOTSTRAP CSS-->
    <link href="{{ asset('/lib/temp-jobinn-v-1.2.0/css/bootstrap.css') }}" rel="stylesheet" type="text/css">
    <!--COLOR CSS-->
    <link href="{{ asset('/lib/temp-jobinn-v-1.2.0/css/color.css') }}" rel="stylesheet" type="text/css">
    <!--RESPONSIVE CSS-->
    <link href="{{ asset('/lib/temp-jobinn-v-1.2.0/css/responsive.css') }}" rel="stylesheet" type="text/css">
    <!--OWL CAROUSEL CSS-->
    <link href="{{ asset('/lib/temp-jobinn-v-1.2.0/css/owl.carousel.css') }}" rel="stylesheet" type="text/css">
    <!--FONTAWESOME CSS-->
    <link href="{{ asset('/lib/temp-jobinn-v-1.2.0/css/font-awesome.min.css') }}" rel="stylesheet" type="text/css">
    <!--SCROLL FOR SIDEBAR NAVIGATION-->
    <link href="{{ asset('/lib/temp-jobinn-v-1.2.0/css/jquery.mCustomScrollbar.css') }}" rel="stylesheet" type="text/css">
    <!--FAVICON ICON-->
    <link rel="icon" href="{{ asset('/lib/temp-jobinn-v-1.2.0/images/favicon.ico') }}" type="image/x-icon">
    <!--GOOGLE FONTS-->
    <link href='https://fonts.googleapis.com/css?family=Roboto:400,300,300italic,500,700,900' rel='stylesheet' type='text/css'>

    <!-- Bootstrap 3.3.4 -->
    <link href="{{ asset('lib/admin-LTE.2.1.1/bootstrap/css/bootstrap.min.css')}}" rel="stylesheet" type="text/css" />
    <!-- Font Awesome Icons -->
    <link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css" rel="stylesheet" type="text/css" />
    <!-- Ionicons -->
    <link href="https://code.ionicframework.com/ionicons/2.0.1/css/ionicons.min.css" rel="stylesheet" type="text/css" />
    <!-- jvectormap -->
    <link href="plugins/jvectormap/jquery-jvectormap-1.2.2.css" rel="stylesheet" type="text/css" />
    <!-- Theme style -->
    <link href="{{ asset('lib/admin-LTE.2.1.1/dist/css/AdminLTE.min.css')}}" rel="stylesheet" type="text/css" />
    <!-- AdminLTE Skins. Choose a skin from the css/skins
         folder instead of downloading all of them to reduce the load. -->
    <link href="{{ asset('lib/admin-LTE.2.1.1/dist/css/skins/_all-skins.min.css')}}" rel="stylesheet" type="text/css" />

    <!-- daterange picker -->
    <link href="{{ asset('lib/admin-LTE.2.1.1/plugins/daterangepicker/daterangepicker-bs3.css')}}" rel="stylesheet" type="text/css" />
    <link rel="stylesheet" href="{{ asset('lib/datepicker/css/datepicker.css') }}">

    <!-- Bootstrap time Picker -->
    <link href="{{ asset('lib/admin-LTE.2.1.1/plugins/timepicker/bootstrap-timepicker.min.css')}}" rel="stylesheet"/>

    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
        <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
        <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
    <!-- Angular -->
    <script src="{{ asset('lib/angular/angular.min.js') }}" type="text/javascript"></script>
    <script src="{{ asset('js/cashier.js') }}" type="text/javascript"></script>
    <script src="{{ asset('lib/angular-route/angular-route.min.js') }}" type="text/javascript"></script>

    <!-- notify -->
    <link href="{{ asset('lib/notify-master/css/prettify.css') }}" rel="stylesheet" type="text/css" id="toggleCSS" />
    <link href="{{ asset('lib/notify-master/css/notify.css') }}" rel="stylesheet" type="text/css" id="toggleCSS" />

    <!-- Angular Material style sheet -->
    <link rel="stylesheet" href="http://ajax.googleapis.com/ajax/libs/angular_material/1.1.0/angular-material.min.css">

    <!-- Angular Material requires Angular.js Libraries -->
  <script src="http://ajax.googleapis.com/ajax/libs/angularjs/1.5.5/angular.min.js"></script>
  <script src="http://ajax.googleapis.com/ajax/libs/angularjs/1.5.5/angular-animate.min.js"></script>
  <script src="http://ajax.googleapis.com/ajax/libs/angularjs/1.5.5/angular-aria.min.js"></script>
  <script src="http://ajax.googleapis.com/ajax/libs/angularjs/1.5.5/angular-messages.min.js"></script>

  <!-- Angular Material Library -->
  <script src="http://ajax.googleapis.com/ajax/libs/angular_material/1.1.0/angular-material.min.js"></script>


  <!-- SELECT PICKER -->
  <link href="{{ asset('/lib/bootstrap-select-1.10.0/dist/css/bootstrap-select.min.css') }}" rel="stylesheet" type="text/css" />


  <!-- loadingbar -->
  <link href="{{ asset('lib/angular-loading-bar/build/loading-bar.min.css') }}" rel='stylesheet' />



   
   <!-- <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.2/jquery.min.js"></script> -->


    <!-- <script type="text/javascript">
      $(document).ready(function(){
 alert(686);
        // $('[data-toggle="popover"]').popover(); 
          
        // $('.selectpicker').selectpicker({
        //   style: 'btn-default',
        // });

        // $('.datepicker').datepicker({
        //       format: 'mm/dd/yyyy',
        //       startDate: '-3d'
        // });


        //Date range picker
        $('#reservation').daterangepicker();





        // $('.timepicker').timepicker({
        //     timeFormat: 'h:mm p',
        //     interval: 60,
        //     minTime: '10',
        //     maxTime: '6:00pm',
        //     defaultTime: '11',
        //     startTime: '10:00',
        //     dynamic: false,
        //     dropdown: true,
        //     scrollbar: true
        // });




        // Timepicker
        // $(".timepicker").timepicker({
        //   showInputs: false,
        // });

        // $(".my-colorpicker2").colorpicker();

        //Datemask dd/mm/yyyy
        // $("#datemask").inputmask("dd/mm/yyyy", {"placeholder": "dd/mm/yyyy"});
        // //Datemask2 mm/dd/yyyy
        // $("#datemask2").inputmask("mm/dd/yyyy", {"placeholder": "mm/dd/yyyy"});
        // //Money Euro
        // $("[data-mask]").inputmask();


        // alert(90);



        // $("#example1").dataTable();
        // $('#example2').dataTable({
        //   "bPaginate": true,
        //   "bLengthChange": false,
        //   "bFilter": false,
        //   "bSort": true,
        //   "bInfo": true,
        //   "bAutoWidth": false
        // });
        // $('#reservation').attr('readonly',true);
        // $('input[name="daterangepicker_start"]').attr('readonly',true);
        // $('input[name="daterangepicker_end"]').attr('readonly',true);
        // $('.applyBtn').click(function(){
        //   $('input[name="from_date"]').val($('input[name="daterangepicker_end"]').val());
        //   $('input[name="to_date"]').val($('input[name="daterangepicker_start"]').val());
        // });



       
      


      });
    </script>
 -->
  </head>
  <body class="sidebar-mini wysihtml5-supported skin-black" style="color:#888">
  <!-- font-family:ubuntu condensed; -->
    <input type="hidden" id="positionBtn"   onclick="api_position('')">
    <div class="wrapper">

      <header class="main-header">

        <!-- Logo -->
        <a href="#/" class="logo">
          <!-- mini logo for sidebar mini 50x50 pixels -->
          <span class="logo-mini"><img src="{{ asset('/') }}images/{{ App\Setting::find(1)->logo }}" style="width:40px;height:40px"></span>
          <!-- logo for regular state and mobile devices -->
          <span class="logo-lg"><img src="{{ asset('/') }}images/{{ App\Setting::find(1)->logo }}" style="width:40px;height:40px"></span>
        </a>

        <!-- Header Navbar: style can be found in header.less -->
        <nav class="navbar navbar-static-top" role="navigation">
          <!-- Sidebar toggle button-->
          <!-- <a href="#/" class="sidebar-toggle" data-toggle="offcanvas" role="button"> -->
            <span class="sr-only">Toggle navigation</span>
          </a>
          <!-- Navbar Right Menu -->
          <div class="navbar-custom-menu">
            <ul class="nav navbar-nav">
              
              <!-- Notifications: style can be found in dropdown.less -->
              <!-- <li class="dropdown notifications-menu">
                <a href="#/" class="dropdown-toggle" data-toggle="dropdown">
                  <i class="fa fa-bell-o"></i>
                  <span class="label label-warning"> @{{ receipts.length }} </span>
                </a>
                <ul class="dropdown-menu">
                  <li class="header">Receipt list not printed.</li>
                  <li>
                   
                    <ul class="menu">
                      <li ng-repeat="receipt in receipts | filter:{'user_id':'' + auth.id + ''}:true | filter:{'status':'0'}">
                        <a href="#/">
                          <i class="fa fa-align-justify"></i>
                          @{{ receipt.number }}
                          <button class="btn btn-primary btn-xs pull-right" ng-click="printReceiptEventListener(receipt)"> Print</button>
                        </a>
                      </li>
                    </ul>
                  </li>
                  
                </ul>
              </li> -->
              <li class="dropdown notifications-menu">
                  <input type="text" class="form-control" style="height:52px" ng-model="search">
              </li>

              <li class="dropdown notifications-menu">
                <a href="#/tables" class="dropdown-toggle" data-toggle="dropdown">
                  <i class="fa fa-bell-o"></i>
                  <!-- <span class="label label-warning"> Bills </span> -->
                  <!-- Tables -->
                </a>
                
              </li>
              <!-- Tasks: style can be found in dropdown.less -->
           
              <!-- User Account: style can be found in dropdown.less -->
              <li class="dropdown user user-menu">
                <a href="" class="dropdown-toggle" data-toggle="dropdown">
                  <img src="{{ asset('/') }}/images/users/{{ Auth::user()->avatar }}" class="user-image" alt="" style="width:25px;height:25px"/>
                  <span class="hidden-xs">{{ Auth::user()->name }}</span>
                </a>
                <ul class="dropdown-menu">
                  <!-- User image -->
                  <li class="user-header">
                    <img src="{{ asset('/') }}/images/users/{{ Auth::user()->avatar }}" class="img-circle" alt="User Image" />
                    <p>
                      {{ Auth::user()->name }}
                      <small>Sales Agent since {{ Carbon\Carbon::parse(Auth::user()->created_at)->format('M d, Y') }}</small>
                    </p>
                  </li>
                  <!-- Menu Body -->
                  <li class="user-body">
                    <!-- <div class="col-xs-4 text-center">
                      <a href="#">Followers</a>
                    </div>
                    <div class="col-xs-4 text-center">
                      <a href="#">Sales</a>
                    </div>
                    <div class="col-xs-4 text-center">
                      <a href="#">Friends</a>
                    </div> -->
                  </li>
                  <!-- Menu Footer-->
                  <li class="user-footer">
                    <!-- <div class="pull-left">
                      <a href="#/" class="btn btn-default btn-flat">Profile</a>
                    </div> -->
                    <div class="pull-right">
                      <a href="{{ url('/') }}/auth" class="btn btn-default btn-flat">Sign out</a>
                    </div>
                  </li>
                </ul>
              </li>
              <!-- Control Sidebar Toggle Button -->
              <!-- <li>
                <a href="#" data-toggle="control-sidebar"><i class="fa fa-gears"></i></a>
              </li> -->
            </ul>
          </div>

        </nav>
      </header>
      <!-- Left side column. contains the logo and sidebar -->
      <aside class="main-sidebar" style="display:none">
        <!-- sidebar: style can be found in sidebar.less -->
        <section class="sidebar">
          <!-- Sidebar user panel -->
          <div class="user-panel">
            <div class="pull-left image">
              <img src="dist/img/user2-160x160.jpg" class="img-circle" alt="User Image" />
            </div>
            <div class="pull-left info">
              <p>Alexander Pierce</p>

              <a href="#"><i class="fa fa-circle text-success"></i> Online</a>
            </div>
          </div>
          <!-- search form -->
          <form action="#" method="get" class="sidebar-form">
            <div class="input-group">
              <input type="text" name="q" class="form-control" placeholder="Search..." ng-model="search"/>
              <span class="input-group-btn">
                <button type='submit' name='search' id='search-btn' class="btn btn-flat"><i class="fa fa-search"></i></button>
              </span>
            </div>
          </form>
          <!-- /.search form -->
          <!-- sidebar menu: : style can be found in sidebar.less -->
          <ul class="sidebar-menu">
            <li class="header">MAIN NAVIGATION</li>
            <li class="active treeview">
              <a href="#">
                <i class="fa fa-dashboard"></i> <span>Dashboard</span> <i class="fa fa-angle-left pull-right"></i>
              </a>
              <ul class="treeview-menu">
                <li><a href="index.html"><i class="fa fa-circle-o"></i> Dashboard v1</a></li>
                <li class="active"><a href="index2.html"><i class="fa fa-circle-o"></i> Dashboard v2</a></li>
              </ul>
            </li>
            <li class="treeview">
              <a href="#">
                <i class="fa fa-files-o"></i>
                <span>Layout Options</span>
                <span class="label label-primary pull-right">4</span>
              </a>
              <ul class="treeview-menu">
                <li><a href="pages/layout/top-nav.html"><i class="fa fa-circle-o"></i> Top Navigation</a></li>
                <li><a href="pages/layout/boxed.html"><i class="fa fa-circle-o"></i> Boxed</a></li>
                <li><a href="pages/layout/fixed.html"><i class="fa fa-circle-o"></i> Fixed</a></li>
                <li><a href="pages/layout/collapsed-sidebar.html"><i class="fa fa-circle-o"></i> Collapsed Sidebar</a></li>
              </ul>
            </li>
            <li>
              <a href="pages/widgets.html">
                <i class="fa fa-th"></i> <span>Widgets</span> <small class="label pull-right bg-green">new</small>
              </a>
            </li>
            <li class="treeview">
              <a href="#">
                <i class="fa fa-pie-chart"></i>
                <span>Charts</span>
                <i class="fa fa-angle-left pull-right"></i>
              </a>
              <ul class="treeview-menu">
                <li><a href="pages/charts/chartjs.html"><i class="fa fa-circle-o"></i> ChartJS</a></li>
                <li><a href="pages/charts/morris.html"><i class="fa fa-circle-o"></i> Morris</a></li>
                <li><a href="pages/charts/flot.html"><i class="fa fa-circle-o"></i> Flot</a></li>
                <li><a href="pages/charts/inline.html"><i class="fa fa-circle-o"></i> Inline charts</a></li>
              </ul>
            </li>
            <li class="treeview">
              <a href="#">
                <i class="fa fa-laptop"></i>
                <span>UI Elements</span>
                <i class="fa fa-angle-left pull-right"></i>
              </a>
              <ul class="treeview-menu">
                <li><a href="pages/UI/general.html"><i class="fa fa-circle-o"></i> General</a></li>
                <li><a href="pages/UI/icons.html"><i class="fa fa-circle-o"></i> Icons</a></li>
                <li><a href="pages/UI/buttons.html"><i class="fa fa-circle-o"></i> Buttons</a></li>
                <li><a href="pages/UI/sliders.html"><i class="fa fa-circle-o"></i> Sliders</a></li>
                <li><a href="pages/UI/timeline.html"><i class="fa fa-circle-o"></i> Timeline</a></li>
                <li><a href="pages/UI/modals.html"><i class="fa fa-circle-o"></i> Modals</a></li>
              </ul>
            </li>
            <li class="treeview">
              <a href="#">
                <i class="fa fa-edit"></i> <span>Forms</span>
                <i class="fa fa-angle-left pull-right"></i>
              </a>
              <ul class="treeview-menu">
                <li><a href="pages/forms/general.html"><i class="fa fa-circle-o"></i> General Elements</a></li>
                <li><a href="pages/forms/advanced.html"><i class="fa fa-circle-o"></i> Advanced Elements</a></li>
                <li><a href="pages/forms/editors.html"><i class="fa fa-circle-o"></i> Editors</a></li>
              </ul>
            </li>
            <li class="treeview">
              <a href="#">
                <i class="fa fa-table"></i> <span>Tables</span>
                <i class="fa fa-angle-left pull-right"></i>
              </a>
              <ul class="treeview-menu">
                <li><a href="pages/tables/simple.html"><i class="fa fa-circle-o"></i> Simple tables</a></li>
                <li><a href="pages/tables/data.html"><i class="fa fa-circle-o"></i> Data tables</a></li>
              </ul>
            </li>
            <li>
              <a href="pages/calendar.html">
                <i class="fa fa-calendar"></i> <span>Calendar</span>
                <small class="label pull-right bg-red">3</small>
              </a>
            </li>
            <li>
              <a href="#movies">
                <i class="fa fa-envelope"></i> <span>Movies</span>
                <small class="label pull-right bg-yellow"> @{{ movies.length }} </small>
              </a>
            </li>
            <li>
              <a href="#consessions">
                <i class="fa fa-envelope"></i> <span>Consessions</span>
                <small class="label pull-right bg-yellow"> @{{ consessions.length }} </small>
              </a>
            </li>
            <li>
              <a href="pages/mailbox/mailbox.html">
                <i class="fa fa-envelope"></i> <span>Mailbox</span>
                <small class="label pull-right bg-yellow">12</small>
              </a>
            </li>
            <li class="treeview">
              <a href="#">
                <i class="fa fa-folder"></i> <span>Examples</span>
                <i class="fa fa-angle-left pull-right"></i>
              </a>
              <ul class="treeview-menu">
                <li><a href="pages/examples/invoice.html"><i class="fa fa-circle-o"></i> Invoice</a></li>
                <li><a href="pages/examples/login.html"><i class="fa fa-circle-o"></i> Login</a></li>
                <li><a href="pages/examples/register.html"><i class="fa fa-circle-o"></i> Register</a></li>
                <li><a href="pages/examples/lockscreen.html"><i class="fa fa-circle-o"></i> Lockscreen</a></li>
                <li><a href="pages/examples/404.html"><i class="fa fa-circle-o"></i> 404 Error</a></li>
                <li><a href="pages/examples/500.html"><i class="fa fa-circle-o"></i> 500 Error</a></li>
                <li><a href="pages/examples/blank.html"><i class="fa fa-circle-o"></i> Blank Page</a></li>
              </ul>
            </li>
            <li class="treeview">
              <a href="#">
                <i class="fa fa-share"></i> <span>Multilevel</span>
                <i class="fa fa-angle-left pull-right"></i>
              </a>
              <ul class="treeview-menu">
                <li><a href="#"><i class="fa fa-circle-o"></i> Level One</a></li>
                <li>
                  <a href="#"><i class="fa fa-circle-o"></i> Level One <i class="fa fa-angle-left pull-right"></i></a>
                  <ul class="treeview-menu">
                    <li><a href="#"><i class="fa fa-circle-o"></i> Level Two</a></li>
                    <li>
                      <a href="#"><i class="fa fa-circle-o"></i> Level Two <i class="fa fa-angle-left pull-right"></i></a>
                      <ul class="treeview-menu">
                        <li><a href="#"><i class="fa fa-circle-o"></i> Level Three</a></li>
                        <li><a href="#"><i class="fa fa-circle-o"></i> Level Three</a></li>
                      </ul>
                    </li>
                  </ul>
                </li>
                <li><a href="#"><i class="fa fa-circle-o"></i> Level One</a></li>
              </ul>
            </li>
            <li><a href="documentation/index.html"><i class="fa fa-book"></i> <span>Documentation</span></a></li>
            <li class="header">LABELS</li>
            <li><a href="#"><i class="fa fa-circle-o text-red"></i> <span>Important</span></a></li>
            <li><a href="#"><i class="fa fa-circle-o text-yellow"></i> <span>Warning</span></a></li>
            <li><a href="#"><i class="fa fa-circle-o text-aqua"></i> <span>Information</span></a></li>
          </ul>
        </section>
        <!-- /.sidebar -->
      </aside>

      <!-- Content Wrapper. Contains page content -->
      <div class="content-wrapper" style='margin-left:0px !important'>
          <div autoscroll='true' ng-view></div>
      </div><!-- /.content-wrapper -->

      <footer class="main-footer">
        <div class="pull-right hidden-xs">
          <b>Version</b> 1.0
        </div>
        {{ App\Setting::find(1)->app_name }} &copy; 2016, All Rights Reserved, Design &amp; Developed By: <a href="https://getcoregroup.com/" target="_blank">Getcore group</a>
      </footer>

      <!-- Control Sidebar -->
      <aside class="control-sidebar control-sidebar-dark">
        <!-- Create the tabs -->
        <ul class="nav nav-tabs nav-justified control-sidebar-tabs">
          <li><a href="#control-sidebar-home-tab" data-toggle="tab"><i class="fa fa-home"></i></a></li>
          <li><a href="#control-sidebar-settings-tab" data-toggle="tab"><i class="fa fa-gears"></i></a></li>
        </ul>
        <!-- Tab panes -->
        <div class="tab-content">
          <!-- Home tab content -->
          <div class="tab-pane" id="control-sidebar-home-tab">
            <h3 class="control-sidebar-heading">Recent Activity</h3>
            <ul class='control-sidebar-menu'>
              <li>
                <a href='javascript::;'>
                  <i class="menu-icon fa fa-birthday-cake bg-red"></i>
                  <div class="menu-info">
                    <h4 class="control-sidebar-subheading">Langdon's Birthday</h4>
                    <p>Will be 23 on April 24th</p>
                  </div>
                </a>
              </li>
              <li>
                <a href='javascript::;'>
                  <i class="menu-icon fa fa-user bg-yellow"></i>
                  <div class="menu-info">
                    <h4 class="control-sidebar-subheading">Frodo Updated His Profile</h4>
                    <p>New phone +1(800)555-1234</p>
                  </div>
                </a>
              </li>
              <li>
                <a href='javascript::;'>
                  <i class="menu-icon fa fa-envelope-o bg-light-blue"></i>
                  <div class="menu-info">
                    <h4 class="control-sidebar-subheading">Nora Joined Mailing List</h4>
                    <p>nora@example.com</p>
                  </div>
                </a>
              </li>
              <li>
                <a href='javascript::;'>
                  <i class="menu-icon fa fa-file-code-o bg-green"></i>
                  <div class="menu-info">
                    <h4 class="control-sidebar-subheading">Cron Job 254 Executed</h4>
                    <p>Execution time 5 seconds</p>
                  </div>
                </a>
              </li>
            </ul><!-- /.control-sidebar-menu -->

            <h3 class="control-sidebar-heading">Tasks Progress</h3>
            <ul class='control-sidebar-menu'>
              <li>
                <a href='javascript::;'>
                  <h4 class="control-sidebar-subheading">
                    Custom Template Design
                    <span class="label label-danger pull-right">70%</span>
                  </h4>
                  <div class="progress progress-xxs">
                    <div class="progress-bar progress-bar-danger" style="width: 70%"></div>
                  </div>
                </a>
              </li>
              <li>
                <a href='javascript::;'>
                  <h4 class="control-sidebar-subheading">
                    Update Resume
                    <span class="label label-success pull-right">95%</span>
                  </h4>
                  <div class="progress progress-xxs">
                    <div class="progress-bar progress-bar-success" style="width: 95%"></div>
                  </div>
                </a>
              </li>
              <li>
                <a href='javascript::;'>
                  <h4 class="control-sidebar-subheading">
                    Laravel Integration
                    <span class="label label-waring pull-right">50%</span>
                  </h4>
                  <div class="progress progress-xxs">
                    <div class="progress-bar progress-bar-warning" style="width: 50%"></div>
                  </div>
                </a>
              </li>
              <li>
                <a href='javascript::;'>
                  <h4 class="control-sidebar-subheading">
                    Back End Framework
                    <span class="label label-primary pull-right">68%</span>
                  </h4>
                  <div class="progress progress-xxs">
                    <div class="progress-bar progress-bar-primary" style="width: 68%"></div>
                  </div>
                </a>
              </li>
            </ul><!-- /.control-sidebar-menu -->

          </div><!-- /.tab-pane -->

          <!-- Settings tab content -->
          <div class="tab-pane" id="control-sidebar-settings-tab">
            <form method="post">
              <h3 class="control-sidebar-heading">General Settings</h3>
              <div class="form-group">
                <label class="control-sidebar-subheading">
                  Report panel usage
                  <input type="checkbox" class="pull-right" checked />
                </label>
                <p>
                  Some information about this general settings option
                </p>
              </div><!-- /.form-group -->

              <div class="form-group">
                <label class="control-sidebar-subheading">
                  Allow mail redirect
                  <input type="checkbox" class="pull-right" checked />
                </label>
                <p>
                  Other sets of options are available
                </p>
              </div><!-- /.form-group -->

              <div class="form-group">
                <label class="control-sidebar-subheading">
                  Expose author name in posts
                  <input type="checkbox" class="pull-right" checked />
                </label>
                <p>
                  Allow the user to show his name in blog posts
                </p>
              </div><!-- /.form-group -->

              <h3 class="control-sidebar-heading">Chat Settings</h3>

              <div class="form-group">
                <label class="control-sidebar-subheading">
                  Show me as online
                  <input type="checkbox" class="pull-right" checked />
                </label>
              </div><!-- /.form-group -->

              <div class="form-group">
                <label class="control-sidebar-subheading">
                  Turn off notifications
                  <input type="checkbox" class="pull-right" />
                </label>
              </div><!-- /.form-group -->

              <div class="form-group">
                <label class="control-sidebar-subheading">
                  Delete chat history
                  <a href="javascript::;" class="text-red pull-right"><i class="fa fa-trash-o"></i></a>
                </label>
              </div><!-- /.form-group -->
            </form>
          </div><!-- /.tab-pane -->
        </div>
      </aside><!-- /.control-sidebar -->
      <!-- Add the sidebar's background. This div must be placed
           immediately after the control sidebar -->
      <div class='control-sidebar-bg'></div>

    </div><!-- ./wrapper -->

    <!-- jQuery 2.1.4 -->
    <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/jQuery/jQuery-2.1.4.min.js')}}"></script>


    <!-- Bootstrap 3.3.2 JS -->
    <script src="{{ asset('lib/admin-LTE.2.1.1/bootstrap/js/bootstrap.min.js')}}" type="text/javascript"></script>
    <!-- FastClick -->
    <script src='plugins/fastclick/fastclick.min.js'></script>
    <!-- AdminLTE App -->
    <script src="{{ asset('lib/admin-LTE.2.1.1/dist/js/app.min.js')}}" type="text/javascript"></script>
    <!-- Sparkline -->
    <script src="plugins/sparkline/jquery.sparkline.min.js" type="text/javascript"></script>
    <!-- jvectormap -->
    <script src="plugins/jvectormap/jquery-jvectormap-1.2.2.min.js" type="text/javascript"></script>
    <script src="plugins/jvectormap/jquery-jvectormap-world-mill-en.js" type="text/javascript"></script>
    <!-- SlimScroll 1.3.0 -->
    <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/slimScroll/jquery.slimscroll.min.js')}}" type="text/javascript"></script>
    <!-- ChartJS 1.0.1 -->
    <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/chartjs/Chart.min.js')}}" type="text/javascript"></script>

    <!-- AdminLTE dashboard demo (This is only for demo purposes) -->
    <script src="{{ asset('lib/admin-LTE.2.1.1/dist/js/pages/dashboard2.js')}}" type="text/javascript"></script>

    <!-- AdminLTE for demo purposes -->
    <script src="{{ asset('lib/admin-LTE.2.1.1/dist/js/demo.js')}}" type="text/javascript"></script>

    <!-- bootstrap time picker -->
    <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/timepicker/bootstrap-timepicker.min.js')}}" type="text/javascript"></script>

    <!-- date-range-picker -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/moment.js/2.10.2/moment.min.js" type="text/javascript"></script>
    <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/daterangepicker/daterangepicker.js')}}" type="text/javascript"></script>
    <script src="{{asset('lib/datepicker/js/bootstrap-datepicker.js')}}" /></script>


    <!-- notify-master -->
    <script src="{{ asset('lib/notify-master/js/notify.js') }}"></script>
    <script src="{{ asset('lib/notify-master/js/prettify.js') }}"></script>

    <!-- bootstrap-select-1.10.0 -->
    <script src="{{ asset('lib/bootstrap-select-1.10.0/dist/js/bootstrap-select.min.js') }}"></script>

    <script src="{{ asset('lib/bootstrap-select-1.10.0/dist/js/i18n/defaults-*.min.js') }}"></script>

    <!-- loadingbar -->
    <script src="{{ asset('lib/angular-loading-bar/build/loading-bar.min.js') }}"></script>


    <script type="text/javascript">
          var host  = "{{ url('/') }}"; 
          var assetpath  = "{{ asset('/') }}";
          var message                                                   = '';
          function api_position(){
            $.notify(message, {align:"right", verticalAlign:"top"});
          }
          !function ($) {
            $(function(){
              window.prettyPrint && prettyPrint()   
            })
          }(window.jQuery)
    </script>


  

  </body>
</html>