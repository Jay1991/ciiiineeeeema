<!doctype html>
<html ng-app="app">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>{{ App\Setting::find(1)->app_name }}</title>
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
<link rel="icon" href="images/favicon.ico" type="image/x-icon">
<!--GOOGLE FONTS-->
<link href='https://fonts.googleapis.com/css?family=Roboto:400,300,300italic,500,700,900' rel='stylesheet' type='text/css'>
<!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->

<!-- Bootstrap 3.3.4 -->
<link href="{{ asset('lib/admin-LTE.2.1.1/bootstrap/css/bootstrap.min.css')}}" rel="stylesheet" type="text/css" />
<!-- Font Awesome Icons -->
<link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css" rel="stylesheet" type="text/css" />
<!-- Ionicons -->
<link href="https://code.ionicframework.com/ionicons/2.0.1/css/ionicons.min.css" rel="stylesheet" type="text/css" />
<!-- jvectormap -->
<!-- <link href="plugins/jvectormap/jquery-jvectormap-1.2.2.css" rel="stylesheet" type="text/css" /> -->
<!-- Theme style -->
<link href="{{ asset('lib/admin-LTE.2.1.1/dist/css/AdminLTE.min.css')}}" rel="stylesheet" type="text/css" />
<!-- AdminLTE Skins. Choose a skin from the css/skins
         folder instead of downloading all of them to reduce the load. -->
<link href="{{ asset('lib/admin-LTE.2.1.1/dist/css/skins/_all-skins.min.css')}}" rel="stylesheet" type="text/css" />

<!-- daterange picker -->
<!-- <link href="{{ asset('lib/admin-LTE.2.1.1/plugins/daterangepicker/daterangepicker-bs3.css')}}" rel="stylesheet" type="text/css" /> -->
<!-- <link rel="stylesheet" href="{{ asset('lib/datepicker/css/datepicker.css') }}"> -->

<!-- Bootstrap time Picker -->
<!-- <link href="{{ asset('lib/admin-LTE.2.1.1/plugins/timepicker/bootstrap-timepicker.min.css')}}" rel="stylesheet"/> -->

    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
        <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
        <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
    

<!-- Angular -->
<script src="{{ asset('lib/angular/angular.min.js') }}" type="text/javascript"></script>
<script src="{{ asset('js/ticket.js') }}" type="text/javascript"></script>
<script src="{{ asset('lib/angular-route/angular-route.min.js') }}" type="text/javascript"></script>
 
    
<script src="https://cdnjs.cloudflare.com/ajax/libs/moment.js/2.17.1/moment.js" type="text/javascript"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/angular-moment/1.0.1/angular-moment.min.js" type="text/javascript"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/ngStorage/0.3.6/ngStorage.min.js"></script>


<!-- notify -->
<link href="{{ asset('lib/notify-master/css/prettify.css') }}" rel="stylesheet" type="text/css" id="toggleCSS" />
<link href="{{ asset('lib/notify-master/css/notify.css') }}" rel="stylesheet" type="text/css" id="toggleCSS" />

<!-- Angular Material style sheet -->
<!-- <link rel="stylesheet" href="http://ajax.googleapis.com/ajax/libs/angular_material/1.1.0/angular-material.min.css"> -->

<!-- Angular Material requires Angular.js Libraries -->
<script src="http://ajax.googleapis.com/ajax/libs/angularjs/1.5.5/angular.min.js"></script>
<script src="http://ajax.googleapis.com/ajax/libs/angularjs/1.5.5/angular-animate.min.js"></script>
<script src="http://ajax.googleapis.com/ajax/libs/angularjs/1.5.5/angular-aria.min.js"></script>
<script src="http://ajax.googleapis.com/ajax/libs/angularjs/1.5.5/angular-messages.min.js"></script>

<!-- Angular Material Library -->
<!-- <script src="http://ajax.googleapis.com/ajax/libs/angular_material/1.1.0/angular-material.min.js"></script> -->


<!-- SELECT PICKER -->
<!-- <link href="{{ asset('/lib/bootstrap-select-1.10.0/dist/css/bootstrap-select.min.css') }}" rel="stylesheet" type="text/css" /> -->

<!-- loadingbar -->
<link href="{{ asset('lib/angular-loading-bar/build/loading-bar.min.css') }}" rel='stylesheet' />


</head>

<body class="theme-style-1">
@if(!Auth::check())
  <script type="text/javascript">
    window.location = "{{ url('/login') }}";//here double curly bracket
  </script>
@endif
<form id="form" method="get" action="{{ url('/') . '/auth' }}">
</form>
<input type="hidden" id="positionBtn"   onclick="api_position('')">
<input type="hidden"  id="logout" onclick="document.getElementById('form').submit();">

<!--WRAPPER START-->
<div id="wrapper">
  <!--HEADER START-->
  <header id="header" >
    <!--BURGER NAVIGATION SECTION START-->
    <div class="cp-burger-nav">
      <!--BURGER NAV BUTTON-->
      <div id="cp_side-menu-btnX" class="cp_side-menu"><a href="#/" class=""><img src="images/menu-icon.png" alt="img"></a></div>
      <!--BURGER NAV BUTTON-->

      <!--SIDEBAR MENU START-->
      <div id="cp_side-menu"> <a href="#/" id="cp-close-btn" class="crose"><i class="fa fa-close"></i></a>
        <div class="cp-top-bar">
          <h4>For any Queries: +800 123 4567</h4>
          <div class="login-section"> <a href="login.html" class="btn-login">Log in</a> <a href="signup.html" class="btn-login">Signup</a> </div>
        </div>
        <strong class="logo-2"><a href="index.html"><img src="images/sidebar-logo.png" alt="img"></a></strong>
        <div class="content mCustomScrollbar">
          <div id="content-1" class="content">
            <div class="cp_side-navigation">
              <nav>
                <ul class="navbar-nav">
                  <li><a href="contact.html">Contact</a> </li>
                </ul>
              </nav>
            </div>
          </div>
        </div>
        <div class="cp-sidebar-social">
          <ul>
            <li><a href="#/"><i class="fa fa-google-plus"></i></a></li>
            <li><a href="#/"><i class="fa fa-twitter"></i></a></li>
            <li><a href="#/"><i class="fa fa-linkedin"></i></a></li>
            <li><a href="#/"><i class="fa fa-facebook-f"></i></a></li>
          </ul>
        </div>
        <strong class="copy">JobInn &copy; 2016, All Rights Reserved</strong> </div>
      <!--SIDEBAR MENU END-->

    </div>
    <!--BURGER NAVIGATION SECTION END-->
    <div class="container">
      <!--NAVIGATION START-->
      <div class="navigation-col">
        <nav class="navbar navbar-inverse">
          <div class="navbar-header">
            <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" afria-expanded="false" aria-controls="navbar"> <span class="sr-only">Toggle navigation</span> <span class="icon-bar"></span> <span class="icon-bar"></span> <span class="icon-bar"></span> </button>
            <strong class="logo"><a href="index.html"><!-- <img src="{{ asset('/') }}images/{{ App\Setting::find(1)->logo }}" alt="logo" style="width:173px;height:59px"> --></a></strong> </div>
          <div id="navbar" class="collapse navbar-collapse">
            <ul class="nav navbar-nav" id="nav">
              <li><a href=""></a></li>
            </ul>
          </div>
        </nav>
      </div>
      <!--NAVIGATION END-->
    </div>

    <!--USER OPTION COLUMN START-->
    <div class="user-option-col">
      <div class="thumb">
        <div class="dropdown">
          <button class="btn btn-default dropdown-toggle" type="button" id="dropdownMenu1" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true" style="background:#fff"> <img src="{{ asset('/')}}images/users/{{ Auth::user()->avatar}}" alt="" style="width:44px;height:44px;background:#fff" class="img-circle"></button>
          <ul class="dropdown-menu" aria-labelledby="dropdownMenu1">
          <!--   <li><a href="#/">Manage Account</a></li>
            <li><a href="#/">Change Password</a></li>
            <li><a href="#/">Edit Profile</a></li> -->
            <li><a href="{{ url('/') }}/auth">Log off</a></li>
          </ul>
        </div>
      </div>
      <div class="dropdown-box">
        <div class="dropdown">
          <button class="btn btn-default dropdown-toggle" type="button" id="dropdownMenu2" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true"> <img src="{{ asset('/')}}images/option-icon.png" alt="img" > </button>
          <ul class="dropdown-menu" aria-labelledby="dropdownMenu2">
            <li> <a href="#/" class="login-round"><i class="fa fa-sign-in"></i></a> <a href="{{ url('/') }}/auth" class="btn-login">Log off</a> </li>
            <!-- <li> <a href="#/" class="login-round"><i class="fa fa-user-plus"></i></a> <a href="#/" class="btn-login">Log in with Jobinn</a> </li> -->
          </ul>
        </div>
      </div>
    </div>
    <!--USER OPTION COLUMN END-->

  </header>
  <!--HEADER END-->

  <!--BANNER START-->
  <div class="banner-outer">
     <div autoscroll='true'  ng-view> </div>
  </div>
  <!--BANNER END-->

  <!--MAIN START-->
  <div id="main">

  </div>
  <!--MAIN END-->

  <!--FOOTER START-->
  <footer id="footer">
    <div class="container">
      <div class="bottom-row"> <strong class="copyrights">JobInn &copy; 2016, All Rights Reserved, Design &amp; Developed By: <a href="http://crunchpress.com/" target="_blank">CrunchPress</a></strong>
        <div class="footer-social">
          <ul>
            <li><a href="#/"><i class="fa fa-google-plus"></i></a></li>
            <li><a href="#/"><i class="fa fa-twitter"></i></a></li>
            <li><a href="#/"><i class="fa fa-linkedin"></i></a></li>
            <li><a href="#/"><i class="fa fa-facebook-f"></i></a></li>
          </ul>
        </div>
      </div>
    </div>
  </footer>
  <!--FOOTER END-->
</div>
<!--WRAPPER END-->

<!--jQuery START-->
<!--JQUERY MIN JS-->
<script src="{{ asset('/lib/temp-jobinn-v-1.2.0/js/jquery-1.11.3.min.js') }}"></script>
<!--BOOTSTRAP JS-->
<script src="{{ asset('/lib/temp-jobinn-v-1.2.0/js/bootstrap.min.js') }}"></script>
<!--OWL CAROUSEL JS-->
<!-- <script src="js/owl.carousel.min.js"></script>  -->
<!--BANNER ZOOM OUT IN-->
<!-- <script src="js/jquery.velocity.min.js"></script>  -->
<!-- <script src="js/jquery.kenburnsy.js"></script>  -->
<!--SCROLL FOR SIDEBAR NAVIGATION-->
<!-- <script src="{{ asset('/lib/temp-jobinn-v-1.2.0/js/jquery.mCustomScrollbar.concat.min.js') }}"></script>  -->
<!--CUSTOM JS-->
<script src="{{ asset('/lib/temp-jobinn-v-1.2.0/js/custom.js') }}"></script>

<!-- jQuery 2.1.4 -->
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/jQuery/jQuery-2.1.4.min.js')}}"></script> -->
<!-- Bootstrap 3.3.2 JS -->
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/bootstrap/js/bootstrap.min.js')}}" type="text/javascript"></script> -->
<!-- FastClick -->
<!-- <script src='plugins/fastclick/fastclick.min.js'></script> -->
<!-- AdminLTE App -->
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/dist/js/app.min.js')}}" type="text/javascript"></script> -->
<!-- Sparkline -->
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/sparkline/jquery.sparkline.min.js')}}" type="text/javascript"></script> -->
<!-- jvectormap -->
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/jvectormap/jquery-jvectormap-1.2.2.min.js')}}" type="text/javascript"></script> -->
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/jvectormap/jquery-jvectormap-world-mill-en.js')}}" type="text/javascript"></script> -->
<!-- SlimScroll 1.3.0 -->
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/slimScroll/jquery.slimscroll.min.js')}}" type="text/javascript"></script> -->
<!-- ChartJS 1.0.1 -->
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/chartjs/Chart.min.js')}}" type="text/javascript"></script> -->

<!-- AdminLTE dashboard demo (This is only for demo purposes) -->
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/dist/js/pages/dashboard2.js')}}" type="text/javascript"></script> -->

<!-- AdminLTE for demo purposes -->
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/dist/js/demo.js')}}" type="text/javascript"></script> -->

<!-- bootstrap time picker -->
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/timepicker/bootstrap-timepicker.min.js')}}" type="text/javascript"></script> -->

<!-- date-range-picker -->
<!-- <script src="https://cdnjs.cloudflare.com/ajax/libs/moment.js/2.10.2/moment.min.js" type="text/javascript"></script> -->
<!-- <script src="{{ asset('lib/admin-LTE.2.1.1/plugins/daterangepicker/daterangepicker.js')}}" type="text/javascript"></script> -->
<!-- <script src="{{asset('lib/datepicker/js/bootstrap-datepicker.js')}}" /></script> -->


<!-- notify-master -->
<script src="{{ asset('lib/notify-master/js/notify.js') }}"></script>
<script src="{{ asset('lib/notify-master/js/prettify.js') }}"></script>

<!-- bootstrap-select-1.10.0 -->
<!-- <script src="{{ asset('lib/bootstrap-select-1.10.0/dist/js/bootstrap-select.min.js') }}"></script> -->

<!-- <script src="{{ asset('lib/bootstrap-select-1.10.0/dist/js/i18n/defaults-*.min.js') }}"></script> -->


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
