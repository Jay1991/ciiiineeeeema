<!doctype html>
<html ng-app='app'>
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>{{ App\Setting::find(1)->app_name }}</title>
<!-- JOBINN-V-1.2.0 CSS This-->

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
<!--TEXT EDITOR CSS-->
<!-- <link href="{{ asset('/lib/temp-jobinn-v-1.2.0/css/editor.css') }}" type="text/css" rel="stylesheet"/> -->
<!--END TEXT EDITOR CSS-->

<!-- END JOBINN-V-1.2.0 CSS -->


<!-- Bootstrap 3.3.4 -->
<link href="{{ asset('lib/admin-LTE.2.1.1/bootstrap/css/bootstrap.min.css')}}" rel="stylesheet" type="text/css" />
<!-- Font Awesome Icons -->
<link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css" rel="stylesheet" type="text/css" />
<!-- Ionicons -->
<!-- <link href="https://code.ionicframework.com/ionicons/2.0.1/css/ionicons.min.css" rel="stylesheet" type="text/css" /> -->
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




<!-- SELECT PICKER -->
<link href="{{ asset('lib/bootstrap-select-1.10.0/dist/css/bootstrap-select.min.css') }}" rel="stylesheet" type="text/css" />
<!-- END SELECT PICKER -->

<!-- ANGULAR LOADIND BAR CSS -->
    
<!-- END ANGULAR LOADIND BAR CSS-->

<!-- NOTIFY CSS -->
<link href="{{ asset('lib/notify-master/css/prettify.css') }}" rel="stylesheet" type="text/css" id="toggleCSS" />
<link href="{{ asset('lib/notify-master/css/notify.css') }}" rel="stylesheet" type="text/css" id="toggleCSS" />
<!-- END NOTIFY CSS -->

<!-- DATE PICKER CSS -->
<link href="{{ asset('lib/admin-LTE.2.1.1/plugins/daterangepicker/daterangepicker-bs3.css')}}" rel="stylesheet" type="text/css" />
<link rel="stylesheet" href="{{ asset('lib/datepicker/css/datepicker.css') }}">
<!-- END DATE PICKER CSS -->


    <!-- FOR DATATABLE -->
<link href="https://cdn.datatables.net/1.10.13/css/jquery.dataTables.min.css" rel="stylesheet">
<link href="https://cdn.datatables.net/autofill/2.1.3/css/autoFill.dataTables.min.css" rel="stylesheet">


<!-- PUSHER JS -->
<script src="https://js.pusher.com/3.2/pusher.min.js"></script>
<!-- END PUSHER JS -->

<script>

    // Enable pusher logging - don't include this in production


</script>




</head>

<body class="theme-style-1">
@if(!Auth::check())
<script type="text/javascript">

window.location = "{{ url('/login') }}";
//here double curly bracket

</script>
@endif
<form id="form" method="get" action="{{ url('/') . '/auth' }}">
</form>
<input type="hidden" id="positionBtn"   onclick="api_position('')">
<input type="hidden"  id="logout" onclick="document.getElementById('form').submit();">

<!--WRAPPER START-->
<div id="wrapper">
  <!--HEADER START-->
  <header id="header" class="header-4">
    <!--BURGER NAVIGATION SECTION START-->
    <div class="cp-burger-nav">
      <!--BURGER NAV BUTTON-->
      <div id="cp_side-menu-btn" class="cp_side-menu"><a href="" class=""><img src="{{ asset('/') }}images/menu-icon-2.png" alt="img"></a></div>
      <!--BURGER NAV BUTTON-->

      <!--SIDEBAR MENU START-->
      <div id="cp_side-menu"> <a href="" id="cp-close-btn" class="crose"><i class="fa fa-close"></i></a>
        <div class="cp-top-bar">
          <!-- <h4>For any Queries: +800 123 4567</h4> -->
          <div class="login-section">
            <a href="{{ url('/') }}/auth" class="btn-login">Log off</a>
            <!-- <a href="signup.html" class="btn-login">Signup</a>  -->
          </div>
        </div>
        <strong class="logo-2"><a href="index.html"><img src="images/sidebar-logo.png" alt="img"></a></strong>
        <div class="content mCustomScrollbar">
          <div id="content-1" class="content">
            <div class="cp_side-navigation">
              <nav>
                <ul class="navbar-nav">
                  <li class="active"><a href="#/reports" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-expanded="false">Dashboard<span class="caret"></span></a>
                    <!-- <ul class="dropdown-menu" role="menu">
                      <li><a href="index-1.html">Home 1</a></li>
                      <li><a href="index-2.html">Home 2</a></li>
                      <li><a href="index-3.html">Home 3</a></li>
                      <li><a href="index-4.html">Home 4</a></li>
                    </ul> -->
                  </li>
                  <li><a href="#/reports">Reports</a></li>

                  <li class="dropdown"><a href="#/consessions"  class="dropdown-toggle" data-toggle="dropdown" role="button" aria-expanded="false">consessions<span class="caret"></span></a>
                    <!-- <ul class="dropdown-menu" role="menu">
                      <li><a href="candidates-listings.html">Jobseeker Listing</a></li>
                      <li><a href="candidate-details.html">Jobseeker Details</a></li>
                      <li><a href="job-seekers.html">Jobseeker From</a></li>
                    </ul> -->
                  </li>
                  <li><a href="#/movies">Movies</a></li>
                  <li><a href="#/directors">Distributors</a></li>
                  <li><a href="#/seats/booked">Booked seats </a></li>
                  <li><a href="#/screens">Screens </a></li>
                  <li><a href="#/users">Users </a></li>
                  <li><a href="#/settings">Settings </a></li>


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
            <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar"> <span class="sr-only">Toggle navigation</span> <span class="icon-bar"></span> <span class="icon-bar"></span> <span class="icon-bar"></span> </button>
          </div>
          <div id="navbar" class="collapse navbar-collapse">
            <ul class="nav navbar-nav" id="nav">
              <li><a href="#/reports">Dashboard</a>
                <!-- <ul>
                  <li><a href="index.html">Home 1</a></li>
                  <li><a href="index-2.html">Home 2</a></li>
                  <li><a href="index-3.html">Home 3</a></li>
                  <li><a href="index-4.html">Home 4</a></li>
                </ul> -->
              </li>
              <li><a href="#/reports">Reports</a></li>

              <li><a href="#/consessions">Consessions</a>
                <!-- <ul>
                  <li><a href="candidates-listings.html">Jobseeker Listing</a></li>
                  <li><a href="candidate-details.html">Jobseeker Details</a></li>
                  <li><a href="job-seekers.html">Jobseeker From</a></li>
                </ul> -->
              </li>
              <li><a href="#/movies">Movies</a></li>
              <li><a href="#/directors">Distributors</a>
                <!-- <ul>
                  <li><a href="jobs.html">Latest Jobs</a></li>
                  <li><a href="jobs-detail.html">Jobs Details</a></li>
                  <li><a href="job-seekers.html">Jobs Form</a></li>
                </ul> -->
              </li>
              <li><a href="#/seats/booked">Booked seats</a>
              <li><a href="#/screens">Screens</a>
                <!-- <ul>
                  <li><a href="companies.html">Companies</a></li>
                  <li><a href="company-detail.html">Company Details</a></li>
                </ul> -->
              </li>
              <!-- <li><a href="#/">Features</a>
                <ul>
                  <li><a href="blog-full.html">Blogs<i class="fa fa-caret-right"></i></a>
                    <ul>
                      <li><a href="blog-medium.html">Blog Medium</a></li>
                      <li><a href="blog-post.html">Blog Post</a></li>
                      <li><a href="blog-detail.html">Blog Detail</a></li>
                      <li><a href="#/">Post a Job</a></li>
                    </ul>
                  </li>
                  <li><a href="companies.html">Companies</a></li>
                  <li><a href="#/">Resumes</a></li>
                  <li><a href="price.html">Job Plans &amp; Pricing</a></li>
                  <li><a href="testimonials.html">Testimonials</a></li>
                  <li><a href="privacy-policy.html">Privacy Policy</a></li>
                  <li><a href="our-terms.html">Our Terms</a></li>
                  <li><a href="login.html">Login</a></li>
                  <li><a href="signup.html">Register</a></li>
                  <li><a href="privacy-policy.html">Privacy Policy</a></li>
                </ul>
              </li> -->
              <!-- <li><a href="#/users">Users</a></li> -->
              <!-- <li><a href="#/settings">Settings</a></li> -->
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
          <button class="btn btn-default dropdown-toggle" type="button" id="dropdownMenu1" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true">
            <img
                src="{{ asset('/')}}/images/users/{{ Auth::user()->avatar}}" alt=""
                style="width:44px;height:44px"
                class="img-circle"
                >
          </button>
          <ul class="dropdown-menu">
        <!--     <li><a href="#/">Manage Account</a></li>
            <li><a href="#/">Change Password</a></li>
            <li><a href="#/">Edit Profile</a></li> -->
            <li><a href="{{ url('/') }}/auth">Log off</a></li>
          </ul>
        </div>
      </div>
      <div class="dropdown-box">
        <div class="dropdown">
          <button class="btn btn-default dropdown-toggle" type="button" id="dropdownMenu2" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true"> <img src="{{ asset('/')}}images/option-icon-2.png" alt="img"> </button>
          <!-- <ul class="dropdown-menu">
            <li> <a href="#/" class="login-round"><i class="fa fa-sign-in"></i></a> <a href="#/" class="btn-login">Log in with Jobinn</a> </li>
            <li> <a href="#/" class="login-round"><i class="fa fa-user-plus"></i></a> <a href="#/" class="btn-login">Log in with Jobinn</a> </li>
          </ul> -->
        </div>
      </div>
    </div>
    <!--USER OPTION COLUMN END-->

  </header>
  <!--HEADER END-->



  <!--MAIN START-->
  <div id="main">
     <div autoscroll='true'  ng-view></div>

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
<script src="{{ asset('/lib/temp-jobinn-v-1.2.0/js/owl.carousel.min.js') }}"></script>
<!--BANNER ZOOM OUT IN-->
<script src="{{ asset('/lib/temp-jobinn-v-1.2.0/js/jquery.velocity.min.js') }}"></script>
<script src="{{ asset('/lib/temp-jobinn-v-1.2.0/js/jquery.kenburnsy.js') }}"></script>
<!--SCROLL FOR SIDEBAR NAVIGATION-->
<script src="{{ asset('/lib/temp-jobinn-v-1.2.0/js/jquery.mCustomScrollbar.concat.min.js') }}"></script>
<!--CUSTOM JS-->
<script src="{{ asset('/lib/temp-jobinn-v-1.2.0/js/custom.js') }}"></script>

<!--TEXT EDITOR JS-->
<!-- <script src="js/editor.js"></script>  -->
<!-- END JOBINN-V-1.2.0 JSS -->


<!-- SELECT PICKER JS -->
<script src="{{ asset('lib/bootstrap-select-1.10.0/dist/js/bootstrap-select.min.js') }}"></script>

<script src="{{ asset('lib/bootstrap-select-1.10.0/dist/js/i18n/defaults-*.min.js') }}"></script>
<!-- END SELECT PICKER JS -->

<!-- ANGULAR -->

<!-- END ANGULAR -->

<!-- ANGULAR-LOADING BAR  -->
    
<!-- END ANGULAR-LOADING BAR  -->

<!-- NOTIFY JS -->
<script src="{{ asset('lib/notify-master/js/notify.js') }}"></script>
<script src="{{ asset('lib/notify-master/js/prettify.js') }}"></script>
<!-- END NOTIFY JS -->


<!-- ANGULAR LOCAL STORAGE JS -->

<!-- ANGULAR LOCAL STORAGE JS -->


<!-- DATE RANGE PICKER JS -->
<!-- <script src="https://cdnjs.cloudflare.com/ajax/libs/moment.js/2.10.2/moment.min.js" type="text/javascript"></script> -->
<script src="{{ asset('lib/moment/min/moment.min.js')}}" type="text/javascript"></script>
<script src="{{ asset('lib/admin-LTE.2.1.1/plugins/daterangepicker/daterangepicker.js')}}" type="text/javascript"></script>
<script src="{{asset('lib/datepicker/js/bootstrap-datepicker.js')}}" /></script>
<!-- END DATE RANGE PICKER JS -->
<!-- <script src="https://code.jquery.com/jquery-3.1.1.min.js"
        integrity="sha256-hVVnYaiADRTO2PzUGmuLJr8BLUSjGIZsDYGmIJLv2b8="
        crossorigin="anonymous"></script> -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
    
<script src="https://cdn.datatables.net/1.10.13/js/jquery.dataTables.min.js"></script>
<script src="https://cdn.datatables.net/plug-ins/1.10.13/api/sum().js"></script>

<script src="https://cdn.datatables.net/buttons/1.2.3/js/dataTables.buttons.min.js"></script>
<script src="https://cdn.datatables.net/buttons/1.2.3/js/buttons.flash.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jszip/2.5.0/jszip.min.js"></script>
<script src="https://cdn.rawgit.com/bpampuch/pdfmake/0.1.18/build/pdfmake.min.js"></script>
<script src="https://cdn.rawgit.com/bpampuch/pdfmake/0.1.18/build/vfs_fonts.js"></script>
<script src="https://cdn.datatables.net/buttons/1.2.3/js/buttons.html5.min.js"></script>
<script src="https://cdn.datatables.net/buttons/1.2.3/js/buttons.print.min.js"></script>
<script src="https://cdn.datatables.net/autofill/2.1.3/js/dataTables.autoFill.min.js"></script>
    
<script src="{{ asset('lib/angular/angular.min.js') }}" type="text/javascript"></script>
<script src="{{ asset('js/angularJS.js') }}" type="text/javascript"></script>
<script src="{{ asset('lib/angular-route/angular-route.min.js') }}" type="text/javascript"></script>
<script src="{{ asset('lib/angular-local-storage/dist/angular-local-storage.min.js') }}"></script>
    
<link href="{{ asset('lib/angular-loading-bar/build/loading-bar.min.css') }}" rel='stylesheet' />
<script src="{{ asset('lib/angular-loading-bar/build/loading-bar.min.js') }}"></script>
    
<script src="{{asset('lib/angular-datatables-0.5.6/angular-datatables-0.5.6/dist/angular-datatables.min.js')}}" /></script>
<script src="{{asset('lib/angular-datatables-0.5.6/angular-datatables-0.5.6/dist/plugins/buttons/angular-datatables.buttons.min.js')}}" /></script>
<script src="{{asset('lib/angular-datatables-0.5.6/angular-datatables-0.5.6/dist/plugins/tabletools/angular-datatables.tabletools.min.js')}}" /></script>

    

<script type="text/javascript">

$(document).ready(function() {

    $('#example').DataTable({

        dom: 'Bfrtip',
        buttons: [
        'copy', 'csv', 'excel', 'pdf', 'print'],


    });


});
</script>

    <script type="text/javascript">
          var host                                             = "{{ url('/') }}";
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

    <script type="text/javascript">

       //Enable iCheck plugin for checkboxes
      //iCheck for checkbox and radio inputs
       //Handle starring for glyphicon and font awesome
        $(".mailbox-star").click(function (e) {
          e.preventDefault();
          //detect type
          var $this = $(this).find("a > i");
          var glyph = $this.hasClass("glyphicon");
          var fa = $this.hasClass("fa");

          //Switch states
          if (glyph) {
            $this.toggleClass("glyphicon-star");
            $this.toggleClass("glyphicon-star-empty");
          }

          if (fa) {
            $this.toggleClass("fa-star");
            $this.toggleClass("fa-star-o");
          }
        });
          // alert(6);





    </script>




</body>
</html>
