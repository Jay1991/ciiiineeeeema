/*jslint white:true */
/*global angular */
(function () {
    
//    "use strict";

    var app = angular.module('app', ['ngRoute','chieffancypants.loadingBar','datatables', 'datatables.buttons', 'datatables.tabletools']);
    
//    .controller('WithButtonsCtrl', WithButtonsCtrl);
//    
//    function WithButtonsCtrl(DTOptionsBuilder) {
////        alert("exe here");
//    var vm = this;
//    vm.dtOptions = DTOptionsBuilder
////        .withDOM('Bfrtip')
//        // Active Buttons extension
//       .withTableTools('vendor/datatables-tabletools/swf/copy_csv_xls_pdf.swf')
//          .withTableToolsButtons([
//                'copy',
//                'print', {
//                'sExtends': 'collection',
//                'sButtonText': 'Save',
//                'aButtons': ['csv', 'xls', 'pdf']
//            }
//        ]);
// 
//}

app.run(function($window, $rootScope,$location,$http,$interval,userService,roleService,authDateService,authTimeService,screenTimeService,screenService,parentalGuidanceService,directorService,movieService,priceService,consessionService,seatService,rowService) {
    
    
  // $rootScope.online                                           = navigator.onLine;
  // $window.addEventListener("offline", function () {
  //   $rootScope.$apply(function() {
  //     $rootScope.online                                      = false;
  //   });
  // }, false);
  // $window.addEventListener("online", function () {
  //   $rootScope.$apply(function() {
  //     $rootScope.online                                       = true;
  //   });
  // }, false);
  $rootScope.reports                                          = [];
  $rootScope.movies                                           = [];
  $rootScope.movie                                            = '';
  $rootScope.director                                         = '';
  $rootScope.receipt                                          = '';
  $rootScope.consession                                       = '';
  $rootScope.consessions                                      = [];
  $rootScope.users                                            = [];
  $rootScope.user                                             = '';
  $rootScope.roles                                            = [];
  $rootScope.search                                           = '';
  $rootScope.times                                            = '';
  $rootScope.dates                                            = '';
  $rootScope.screen                                           = '';
  $rootScope.authdate                                         = '';
  $rootScope.authtime                                         = '';
  $rootScope.datepickerlength                                 = 0;
  $rootScope.yesterday = [];
  $rootScope.myWelcome = [];

  $rootScope.host = host.replace("/index.php", "");
  $http.post(host + '/users/auth').success(function(data, status, headers, config)
  {
  $rootScope.auth                                             = data[0];
  });
  $http.post(host + '/api/settings').success(function(data, status, headers, config)
  {
  $rootScope.setting                                          = data[0];
  });



  // $interval(function () {
  //       if ( isSessionExpire() == 0){$("#logout").click();}
  // }, 1000);

  // $interval(function () {
  //       if ( isSessionExpire() == 0){$window.location.assign("http://www.w3schools.com");}
  // }, 1000);


  // userService.api();
  roleService.api();

  parentalGuidanceService.api();
  directorService.api();

  rowService.api();
  seatService.api();


  authDateService.api();
  authTimeService.api();
  screenTimeService.api();
  screenService.api();

  priceService.api();
  seatService.booked();

  movieService.api();

  // consessionService.api();





});




 app.config(function($routeProvider)
{
  $routeProvider
  .when("/", {
      templateUrl              : "resources/views/reports/report.blade.php",
      controller               : "ReportCtrl"
  })
  .when("/items", {
      templateUrl              : "resources/views/items/index.blade.php",
      controller               : "ItemCtrl"
  })
  .when("/items/create", {
      templateUrl              : "resources/views/items/create.blade.php",
      controller               : "ItemCtrl"
  })
  .when("/receipts", {
      templateUrl              : "resources/views/receipts/index.blade.php",
      controller               : "ReceiptCtrl"
  })
  .when("/seats/booked", {
      templateUrl              : "resources/views/seats/booked.blade.php",
      controller               : "SeatCtrl"
  })
  .when("/directors", {
      templateUrl              : "resources/views/directors/index.blade.php",
      controller               : "DirectorCtrl"
  })
  .when("/directors/create", {
      templateUrl              : "resources/views/directors/create.blade.php",
      controller               : "DirectorCtrl"
  })
  .when("/directors/edit", {
      templateUrl              : "resources/views/directors/edit.blade.php",
      controller               : "DirectorCtrl"
  })
  .when("/screens", {
      templateUrl              : "resources/views/screens/index.blade.php",
      controller               : "ScreenCtrl"
  })
  .when("/screens/create", {
      templateUrl              : "resources/views/screens/create.blade.php",
      controller               : "ScreenCtrl"
  })
  .when("/movies", {
      templateUrl              : "resources/views/movies/index.blade.php",
      controller               : "MovieCtrl"
  })
  .when("/movies/create", {
      templateUrl              : "resources/views/movies/create.blade.php",
      controller               : "MovieCtrl"
  })
  .when("/movies/edit", {
      templateUrl              : "resources/views/movies/edit.blade.php",
      controller               : "MovieCtrl"
  })
  .when("/consessions", {
      templateUrl              : "resources/views/consessions/index.blade.php",
      controller               : "ConsessionCtrl"
  })
  .when("/consessions/create", {
      templateUrl              : "resources/views/consessions/create.blade.php",
      controller               : "ConsessionCtrl"
  })
  .when("/consessions/edit", {
      templateUrl              : "resources/views/consessions/edit.blade.php",
      controller               : "ConsessionCtrl"
  })
  .when("/users", {
      templateUrl              : "resources/views/users/index.blade.php",
      controller               : "UserCtrl"
  })
  .when("/users/create", {
      templateUrl              : "resources/views/users/create.blade.php",
      controller               : "UserCtrl"
  })
  .when("/settings", {
      templateUrl              : "resources/views/settings/edit.blade.php",
      controller               : "SettingCtrl"
  })
  .when("/en/settings", {
      templateUrl              : "resources/views/settings/en/edit.blade.php",
      controller               : "SettingCtrl"
  })
  .when("/reports", {
      templateUrl              : "resources/views/reports/report.blade.php",
      controller               : "ReportCtrl"
  }).when("/reportJ", {
    templateUrl : "resources/views/reports/reportj.blade.php",
    controller : "ReportJController"
  })
  .when("/reportMovieYest", {
    templateUrl : "resources/views/reports/reportyesterday.blade.php",
    controller : "ReportJController"
  })
  .when("/reportMovieSeven", {
    templateUrl : "resources/views/reports/reportseven.blade.php",
    controller : "ReportJController"
  })
  .when("/reportMovieThirty", {
    templateUrl : "resources/views/reports/reportthirty.blade.php",
    controller : "ReportJController"
  })
  .when("/reportMovieLastMonth", {
    templateUrl : "resources/views/reports/reportlastmonth.blade.php",
    controller : "ReportJController"
  })
  .when("/reportMovieToday", {
    templateUrl : "resources/views/reports/reporttoday.blade.php",
    controller : "ReportJController"
  })
   .when("/reportComplementaryToday", {
    templateUrl : "resources/views/reports/reportcomplementarytoday.blade.php",
    controller : "ReportJController"
  })
    .when("/reportComplementaryYest", {
    templateUrl : "resources/views/reports/reportcomplementaryyesterday.blade.php",
    controller : "ReportJController"
  }) .when("/reportComplementarySeven", {
    templateUrl : "resources/views/reports/reportcomplementaryseven.blade.php",
    controller : "ReportJController"
  }) .when("/reportComplementaryThirty", {
    templateUrl : "resources/views/reports/reportcomplementarythirty.blade.php",
    controller : "ReportJController"
  }) .when("/reportComplementaryThismonth", {
    templateUrl : "resources/views/reports/reportcomplementarythismonth.blade.php",
    controller : "ReportJController"
  })
  .when("/reportComplementaryLastmonth", {
    templateUrl : "resources/views/reports/reportcomplementarylastmonth.blade.php",
    controller : "ReportJController"
  })
  .otherwise({
      template : "<h1>None</h1><p>Nothing has been selected,</p>"
  });
});

 function leftPad(number, targetLength)
{
var output                                            = number + '';
while (output.length < targetLength) {
output                                                = '0' + output;
}
return output;
}


app.directive("fileread", [
  function() {
    return {
      scope: {
        fileread: "="
      },
      link: function(scope, element, attributes) {
        element.bind("change", function(changeEvent) {

          var reader         = new FileReader();
          reader.onload      = function(loadEvent) {
            scope.$apply(function() {
              scope.fileread = loadEvent.target.result;
            });
          }
          reader.readAsDataURL(changeEvent.target.files[0]);

        });
      }
    }
  }
]);


app.directive('myEnter', function () {
      return function (scope, element, attrs) {
          element.bind("keydown keypress", function (event) {
              if(event.which === 13) {
                  scope.$apply(function (){
                      scope.$eval(attrs.myEnter);
                  });

                  event.preventDefault();
              }
          });
      };
});


 app.directive('customOnChange', function()
{
  return {
    restrict: 'A',
    link: function (scope, element, attrs) {
      var onChangeHandler = scope.$eval(attrs.customOnChange);
      element.bind('change', onChangeHandler);
    }
  };
});


app.directive('contenteditable', function() {
    return {
      restrict: 'A', // only activate on element attribute
      require: '?ngModel', // get a hold of NgModelController
      link: function(scope, element, attrs, ngModel) {
        if(!ngModel) return; // do nothing if no ng-model

        // Specify how UI should be updated
        ngModel.$render = function() {
          element.html(ngModel.$viewValue || '');
        };

        // Listen for change events to enable binding
        element.on('blur keyup change mouseover focus', function() {
          scope.$apply(read);
        });
        read(); // initialize

        // Write data to the model
        function read() {
          var html = element.html();
          // When we clear the content editable the browser leaves a <br> behind
          // If strip-br attribute is provided then we strip this out
          if( attrs.stripBr && html == '' ) {
            html = '';
          }
          ngModel.$setViewValue(html);
        }
      }
    };
  });


app.directive('focusMe', ['$timeout', '$parse', function ($timeout, $parse) {
    return {
        //scope: true,   // optionally create a child scope
        link: function (scope, element, attrs) {
            var model = $parse(attrs.focusMe);
            scope.$watch(model, function (value) {
                console.log('value=', value);
                if (value === true) {
                    $timeout(function () {
                        element[0].focus();
                    });
                }
            });
            // to address @blesh's comment, set attribute value to 'false'
            // on blur event:
            element.bind('blur', function () {
                console.log('blur');
                scope.$apply(model.assign(scope, false));
            });
        }
    };
}]);


app.factory('itemService', function($http, $rootScope,$location,$filter)
{
return {
api: function()
{
$http.post(host + '/api/items').success(function(data, status, headers, config)
{
$rootScope.items                                            = data;
});

},
updateAvatar: function(item,src)
{
var fd                                                         = new FormData();
if(src                                                         != ''){ var imgBlob  = dataURItoBlob(src); fd.append('avatar', imgBlob); }else{return;}

$http.post(host + '/items/' + item.id + '/update-avatar', fd, {transformRequest: angular.identity, headers: {'Content-Type': undefined}}).success(function(data, status, headers, config)
{
if(status                                                      == 200){errorMessage(data);$("#positionBtn").click();return;}
message                                                        = 'image is successfull uploaded';
$("#positionBtn").click();
$rootScope.items                                               = data;

});


},
add:function(name,buying_price,selling_price,url,avatar,code,barcode,isbn,size,item_type_id,quantity)
{

var fd                                                   = new FormData();
if(avatar                                                != '')
{
var imgBlob                                              = dataURItoBlob(avatar);
fd.append('avatar',          imgBlob);

}


fd.append('name',            name);
fd.append('url',             url);
fd.append('code',            code);
fd.append('barcode',         barcode);
fd.append('isbn',            isbn);
fd.append('size',            size);
fd.append('item_type_id',    item_type_id);
fd.append('buying_price',    buying_price);
fd.append('selling_price',   selling_price);
fd.append('quantity',        quantity);

$http.post(host + '/items',fd, {transformRequest: angular.identity, headers: {'Content-Type': undefined}}).success(function(data, status, headers, config)
{
if (status                                             == 200)
{
  errorMessage(data);
  $("#positionBtn").click();
  return;
}

message                                                = 'Your sucessfull add new Product';
$rootScope.consessions                                 = data;
$location.path('/items');
$("#positionBtn").click();


});

}
}
});

app.factory('itemTypeService', function($http, $rootScope)
{
return {
api: function()
{
$http.post(host + '/api/item-types').success(function(data, status, headers, config)
{
$rootScope.itemTypes                                        = data;
});

},
add:function(dateAuth,time)
{
 $http.post(host + '/times',{'date_id':dateAuth.id, 'time':time}).success(function(data, status, headers, config)
{
$rootScope.authtimes                                        = data;
});
}
}
});

app.controller("ReportJController", [ '$scope', '$rootScope', '$http','reportService', function($scope, $rootScope, $http, reportService, DTOptionsBuilder){

  $http.get(host + '/thismonth_movie_report')
   .then(function(response) {
       $rootScope.myWelcome = response.data;
   });

   $http.get(host + '/yesterday_movie_report')
    .then(function(response) {
        $rootScope.yesterday = response.data;
    });

   $http.get(host + '/settings')
    .then(function(response) {
        $rootScope.appSettings = response.data;
    });
    
    $scope.getTotalBuying = function(data){
        
        var total = 0;
         angular.forEach(data, function (item) {
             if (item.seatNo) {
//                 total += item.seatNo;
                  total += item.seatNo * item.figure;

             }
         });
         return total;
        
    }
    
    $scope.getTotalDiscount = function(data){
        
        var total = 0;
        angular.forEach(data, function (item) {
             if (item.seatNo) {
                  total += item.seatNo * item.discount_amount;

             }
         });
         return total;
        
    }
    
      $scope.getTotalProfit = function(data){
        
        var total = 0;
        angular.forEach(data, function (item) {
             if (item.seatNo) {
                 
                  total += item.seatNo * item.final_amount;

             }
         });
         return total;
        
    }

    $scope.getTotalTks = function(myWelcome){

      var total = 0;
         angular.forEach(myWelcome, function (item) {
             if (item.seatNo) {
                 total += item.seatNo;

             }
         });
         return total;

}

$scope.getAmtIncl = function(myWelcome){

  var total = 0;
     angular.forEach(myWelcome, function (item) {
         if (item.seatNo) {
            //  total += item.seatNo;
             total += item.seatNo * item.figure;

         }
     });
     return total;

}

$scope.getTax = function(myWelcome){

  var total = 0;
     angular.forEach(myWelcome, function (item) {
         if (item.seatNo) {
            //  total += item.seatNo;
            total += (item.figure * item.seatNo)*((item.movie_sales.setting[0].vat_percentage)/100);

         }
     });
     return total;

}

$scope.getTotalNet = function(myWelcome){

  var total = 0;
     angular.forEach(myWelcome, function (item) {
         if (item.seatNo) {
            //  total += item.seatNo;
            total += (item.figure * item.seatNo) - (item.figure * item.seatNo)*((item.movie_sales.setting[0].vat_percentage)/100);

         }
     });
     return total;

}

$scope.getTotalDisCom = function(myWelcome){

  var total = 0;
     angular.forEach(myWelcome, function (item) {
         if (item.seatNo) {
            //  total += item.seatNo;
            total += item.distributor_commission * item.seatNo;

         }
     });
     return total;

}


 $http.get(host + '/yesterday_movie_report')
  .then(function(response) {
      $rootScope.yesterday = response.data;
  });


  $scope.getTotalTksYes = function(yesterday){

    var total = 0;
       angular.forEach(yesterday, function (item) {
           if (item.seatNo) {
               total += item.seatNo;
              //  total += item.seatNo * item.figure;

           }
       });
       return total;

}

$scope.getAmtInclYes = function(yesterday){

var total = 0;
   angular.forEach(yesterday, function (item) {
       if (item.seatNo) {
          //  total += item.seatNo;
           total += item.seatNo * item.figure;

       }
   });
   return total;

}

$scope.getTaxYes = function(yesterday){

var total = 0;
   angular.forEach(yesterday, function (item) {
       if (item.seatNo) {
          //  total += item.seatNo;
          total += (item.figure * item.seatNo)*((item.movie_sales.setting[0].vat_percentage)/100);

       }
   });
   return total;

}

$scope.getTotalNetYes = function(yesterday){

var total = 0;
   angular.forEach(yesterday, function (item) {
       if (item.seatNo) {
          //  total += item.seatNo;
          total += (item.figure * item.seatNo) - (item.figure * item.seatNo)*((item.movie_sales.setting[0].vat_percentage)/100);

       }
   });
   return total;

}

$scope.getTotalDisComYes = function(yesterday){

var total = 0;
   angular.forEach(yesterday, function (item) {
       if (item.seatNo) {
          //  total += item.seatNo;
          total += item.distributor_commission * item.seatNo;

       }
   });
   return total;

}


 $http.get(host + '/sevendays_movie_report')
  .then(function(response) {
      $rootScope.Seven = response.data;
  });


  $scope.getTotalTksYes = function(Seven){

    var total = 0;
       angular.forEach(Seven, function (item) {
           if (item.seatNo) {
               total += item.seatNo;
              //  total += item.seatNo * item.figure;

           }
       });
       return total;

}

$scope.getAmtInclYes = function(Seven){

var total = 0;
   angular.forEach(Seven, function (item) {
       if (item.seatNo) {
          //  total += item.seatNo;
           total += item.seatNo * item.figure;

       }
   });
   return total;

}

$scope.getTaxYes = function(Seven){

var total = 0;
   angular.forEach(Seven, function (item) {
       if (item.seatNo) {
          //  total += item.seatNo;
          total += (item.figure * item.seatNo)*((item.movie_sales.setting[0].vat_percentage)/100);

       }
   });
   return total;

}

$scope.getTotalNetYes = function(Seven){

var total = 0;
   angular.forEach(Seven, function (item) {
       if (item.seatNo) {
          //  total += item.seatNo;
          total += (item.figure * item.seatNo) - (item.figure * item.seatNo)*((item.movie_sales.setting[0].vat_percentage)/100);

       }
   });
   return total;

}

$scope.getTotalDisComYes = function(Seven){

var total = 0;
   angular.forEach(Seven, function (item) {
       if (item.seatNo) {
          //  total += item.seatNo;
          total += item.distributor_commission * item.seatNo;

       }
   });
   return total;

}

$http.get(host + '/thirtydays_movie_report')
 .then(function(response) {
     $rootScope.Thirty = response.data;
 });


 $scope.getTotalTksYes = function(Thirty){

   var total = 0;
      angular.forEach(Thirty, function (item) {
          if (item.seatNo) {
              total += item.seatNo;
             //  total += item.seatNo * item.figure;

          }
      });
      return total;

}

$scope.getAmtInclYes = function(Thirty){

var total = 0;
  angular.forEach(Thirty, function (item) {
      if (item.seatNo) {
         //  total += item.seatNo;
          total += item.seatNo * item.figure;

      }
  });
  return total;

}

$scope.getTaxYes = function(Thirty){

var total = 0;
  angular.forEach(Thirty, function (item) {
      if (item.seatNo) {
         //  total += item.seatNo;
         total += (item.figure * item.seatNo)*((item.movie_sales.setting[0].vat_percentage)/100);

      }
  });
  return total;

}

$scope.getTotalNetYes = function(Thirty){

var total = 0;
  angular.forEach(Thirty, function (item) {
      if (item.seatNo) {
         //  total += item.seatNo;
         total += (item.figure * item.seatNo) - (item.figure * item.seatNo)*((item.movie_sales.setting[0].vat_percentage)/100);

      }
  });
  return total;

}

$scope.getTotalDisComYes = function(Thirty){

var total = 0;
  angular.forEach(Thirty, function (item) {
      if (item.seatNo) {
         //  total += item.seatNo;
         total += item.distributor_commission * item.seatNo;

      }
  });
  return total;

}




$http.get(host + '/lastmonth_movie_report')
 .then(function(response) {
     $rootScope.lastMonth = response.data;
 });


 $scope.getTotalTksYes = function(lastMonth){

   var total = 0;
      angular.forEach(lastMonth, function (item) {
          if (item.seatNo) {
              total += item.seatNo;
             //  total += item.seatNo * item.figure;

          }
      });
      return total;

}

$scope.getAmtInclYes = function(lastMonth){

var total = 0;
  angular.forEach(lastMonth, function (item) {
      if (item.seatNo) {
         //  total += item.seatNo;
          total += item.seatNo * item.figure;

      }
  });
  return total;

}

$scope.getTaxYes = function(lastMonth){

var total = 0;
  angular.forEach(lastMonth, function (item) {
      if (item.seatNo) {
         //  total += item.seatNo;
         total += (item.figure * item.seatNo)*((item.movie_sales.setting[0].vat_percentage)/100);

      }
  });
  return total;

}

$scope.getTotalNetYes = function(lastMonth){

var total = 0;
  angular.forEach(lastMonth, function (item) {
      if (item.seatNo) {
         //  total += item.seatNo;
         total += (item.figure * item.seatNo) - (item.figure * item.seatNo)*((item.movie_sales.setting[0].vat_percentage)/100);

      }
  });
  return total;

}

$scope.getTotalDisComYes = function(lastMonth){

var total = 0;
  angular.forEach(lastMonth, function (item) {
      if (item.seatNo) {
         //  total += item.seatNo;
         total += item.distributor_commission * item.seatNo;

      }
  });
  return total;

}

$http.get(host + '/today_movie_report')
 .then(function(response) {
     $rootScope.Today = response.data;
 });

 $scope.getTotalTksYes = function(Today){

   var total = 0;
      angular.forEach(Today, function (item) {
          if (item.seatNo) {
              total += item.seatNo;
             //  total += item.seatNo * item.figure;

          }
      });
      return total;

}

$scope.getAmtInclYes = function(Today){

var total = 0;
  angular.forEach(Today, function (item) {
      if (item.seatNo) {
         //  total += item.seatNo;
          total += item.seatNo * item.figure;

      }
  });
  return total;

}

$scope.getTaxYes = function(Today){

var total = 0;
  angular.forEach(Today, function (item) {
      if (item.seatNo) {
         //  total += item.seatNo;
         total += (item.figure * item.seatNo)*((item.movie_sales.setting[0].vat_percentage)/100);

      }
  });
  return total;

}

$scope.getTotalNetYes = function(Today){

var total = 0;
  angular.forEach(Today, function (item) {
      if (item.seatNo) {
         //  total += item.seatNo;
         total += (item.figure * item.seatNo) - (item.figure * item.seatNo)*((item.movie_sales.setting[0].vat_percentage)/100);

      }
  });
  return total;

}

$scope.getTotalDisComYes = function(Today){

var total = 0;
  angular.forEach(Today, function (item) {
      if (item.seatNo) {
         //  total += item.seatNo;
         total += item.distributor_commission * item.seatNo;

      }
  });
  return total;

}

$http.get(host + '/today_complementary_report')
 .then(function(response) {
     $rootScope.complementaryToday = response.data;
 });

$http.get(host + '/yesterday_complementary_report')
 .then(function(response) {
     $rootScope.complementaryYesterday = response.data;
 });
    
$http.get(host + '/seven_complementary_report')
 .then(function(response) {
     $rootScope.complementarySeven = response.data;
 });

$http.get(host + '/thirty_complementary_report')
 .then(function(response) {
     $rootScope.complementaryThirty = response.data;
 });

$http.get(host + '/thismonth_complementary_report')
 .then(function(response) {
     $rootScope.complementaryThisMonth = response.data;
 });

$http.get(host + '/lastmonth_complementary_report')
 .then(function(response) {
     $rootScope.complementaryLastMonth = response.data;
 });

//$scope.dtOptions = DTOptionsBuilder 
//        .withDOM('Bfrtip')
//        // Active Buttons extension
//       .withTableTools('vendor/datatables-tabletools/swf/copy_csv_xls_pdf.swf')
//       .withTableToolsButtons([
//                'copy',
//                'print', {
//                'sExtends': 'collection',
//                'sButtonText': 'Save',
//                'aButtons': ['csv', 'xls', 'pdf']
//            }
//        ]);
    






}]);

 app.controller("ItemCtrl", [ '$scope', '$http','$rootScope','itemService','itemTypeService','$interval','$timeout', function($scope, $http,$rootScope,itemService,itemTypeService,$interval,$timeout)
{
  itemService.api();
  itemTypeService.api();
  $scope.addItemEventListener             = function(name,buying_price,selling_price,url,avatar,code,barcode,isbn,size,item_type_id,quantity)
  {
  itemService.add(name,buying_price,selling_price,url,avatar,code,barcode,isbn,size,item_type_id,quantity);
  }

  $scope.itemEventListener                            = function(item)
  {
  $rootScope.item = item;
  $scope.src= '';$scope.avatarX  = $scope.host + '/images/items/' + item.avatar;
  }

  $scope.avatarUploidEventListener                    = function()
  {
  $scope.itemAvatar = $scope.item;$('#avatarX').click();
  }

  $scope.customeOnChangeFileEventListener                   = function()
  {
  $scope.avatarX = '';
  $timeout(function ()
  {
  itemService.updateAvatar($scope.itemAvatar,$scope.src);
  }, 2000);
  }


}]);



 app.service('movieService', function($http, $rootScope,$location)
{

this.api                                                      = function()
{
 $http.post(host + '/api/movies',{}).success(function(data, status, headers, config)
{
$rootScope.movies                                             = data;
});
},
this.add                                                      = function(name,url,avatar,parentalGuidancer,directorer,directorFee,movie)
{
var fd                                                        = new FormData();
if(avatar                                                     != ''){ var imgBlob  = dataURItoBlob(avatar); fd.append('avatar', imgBlob); }

fd.append('name', name);
fd.append('url', url);
fd.append('avatar', avatar);
fd.append('parental_guidance_id', parentalGuidancer);
fd.append('director_id', directorer);
fd.append('director_fee', directorFee);
fd.append('movie_id', movie.id);

 $http.post(host + '/movies', fd, {transformRequest: angular.identity, headers: {'Content-Type': undefined}}).success(function(data, status, headers, config)
{
 if(status                                                     == 200)
{
  errorMessage(data);$("#positionBtn").click();return;
}

$rootScope.movies                                              = data;
message                                                        = 'Your sucessfull add Movie';
$("#positionBtn").click();$location.path('/movies');
});
},
this.new                                                       = function()
{
 $http.post(host + '/movies/add',{}).success(function(data, status, headers, config)
{
$rootScope.movie                                               = data;
});
},
this.delete                                                    = function(movie)
{
 $http.delete(host + '/movies/' + movie.id ,{}).success(function(data, status, headers, config)
{
$rootScope.movies                                              = data;
message                                                        = 'Your sucessfull delete movie';
$("#positionBtn").click();
});
},
this.show                                                      = function(movie)
{
$rootScope.movie                                               = movie;
},
this.update                                                    = function(movie,name,director_fee)
{
$http.put(host + '/movies/' + movie.id,{'name':name,'director_fee':director_fee}).success(function(data, status, headers, config)
{
if(status                                                      == 200)
{
  errorMessage(data);$("#positionBtn").click();return;
}

$rootScope.movies                                              = data;
message                                                        = 'Your sucessfull update Movie';
$("#positionBtn").click();

});

},
this.updateAvatar                                              = function(movie,src)
{
var fd                                                         = new FormData();
if(src                                                         != ''){ var imgBlob  = dataURItoBlob(src); fd.append('avatar', imgBlob); }else{return;}

$http.post(host + '/movies/' + movie.id + '/update-avatar', fd, {transformRequest: angular.identity, headers: {'Content-Type': undefined}}).success(function(data, status, headers, config)
{
if(status                                                      == 200)
{
  errorMessage(data);$("#positionBtn").click();return;
}
message = 'image is successfull uploaded';
$("#positionBtn").click();
$rootScope.movies                                              = data;
$rootScope.avatarX = $rootScope.host + '/images/items/' + $filter('filter')(data, {id: movie.id},true)[0].avatar;
});

}



});



app.service('parentalGuidanceService', function($http, $rootScope)
{
this.api                                                      = function()
{
$http.post(host + '/api/parental-guidances').success(function(data, status, headers, config)
{
    $rootScope.parentalGuidances                              = data;
});
}
});

app.service('directorService', function($http, $rootScope,$location)
{
this.api                                                      = function()
{
$http.post(host + '/api/directors').success(function(data, status, headers, config) {
$rootScope.directors                                          = data;
});
},
this.add                                                      = function(name)
{
$http.post(host + '/directors',{'name':name}).success(function(data, status, headers, config)
{
if(status                                                     == 200)
{
  errorMessage(data);$("#positionBtn").click();return;
}
$rootScope.directors                                          = data;
message                                                       = 'Your sucessfull add distributor';
$("#positionBtn").click();$location.path('/directors');
});
},
this.show                                                     = function($this)
{
$rootScope.director                                           = $this;
},
this.update                                                   = function(director, name)
{
$http.put(host + '/directors/' + director.id, {'name':name}).success(function(data, status, headers, config)
{
if(status                                                     == 200)
{
  errorMessage(data);$("#positionBtn").click();return;
}

  $rootScope.directors                                          = data;
  message                                                       = 'Your sucessfull edit distributor';
  $("#positionBtn").click();$location.path('/directors');
});
},
this.delete                                                     = function($this)
{
$http.delete(host + '/directors/' + $this.id ).success(function(data, status, headers, config)
{
$rootScope.directors                                            = data;
message                                                         = 'Your successfull delete distributor';
$("#positionBtn").click();
});
}

});



 app.service('rowService', function($http, $rootScope)
{
  this.api                                                    = function()
  {
    $http.post(host + '/api/rows').success(function(data, status, headers, config) {
      $rootScope.rows                                         = data;
    });
  },
  this.add                                                    = function(screen,rows,name)
  {
  $http.post(host + '/rows',{'screen_id':screen.id, 'number':rows, 'name':name}).success(function(data, status, headers, config)
  {
  $rootScope.rows                                             = data;
  });
  },
  this.update                                                 = function(row,code)
  {
  $http.put(host + '/rows/' + row.id,{'code':code}).success(function(data, status, headers, config)
  {
    $rootScope.seats                                          = data;
  });
  }

});




 app.service('authTimeService', function($http, $rootScope, $location)
{
this.api                                                    = function()
{
$http.post(host + '/api/auth-times').success(function(data, status, headers, config)
{
$rootScope.authtimes                                        = data;

});
},
this.report                                                 = function(time)
{
$http.post(host + '/auth-times/reports/time',{'time':time}).success(function(data, status, headers, config)
{
$rootScope.reportTimes                                      = data;
// alert(data);

});
},
this.delete                                                 = function(timeAuth)
{
 $http.delete(host + '/auth-times/' +  timeAuth.id ).success(function(data, status, headers, config)
{
$rootScope.authtimes                                        = data;
});
}

});

app.service('authDateService', function($http, $rootScope, $location,$filter)
{
this.api                                                      = function()
{
$http.post(host + '/api/date-user').success(function(data, status, headers, config) {
    $rootScope.authdates                                      = data;
});
},
this.delete                                                   = function($this)
{
$http.delete(host + '/date-user/' + $this.id).success(function(data, status, headers, config) {
    $rootScope.authdates                                      = data;
});
},
this.temp                                                     = function()
{
$http.post(host + '/date-user/listen').success(function(data, status, headers, config) {
    $rootScope.movieTemp                                      = data[0];
});
},
this.price                                                    = function(dateAuth,price_id)
{
$http.post(host + '/date-user/' + dateAuth.id + '/price',{'price_id':price_id}).success(function(data, status, headers, config)
{
});
}

});


 app.service('dateService', function
(                                                           $http,
                                                            $rootScope
                                                            )
                                                            {
this.api                                                    = function()
{
$http.post(host + '/api/dates').success(function(data, status, headers, config) {
$rootScope.dates                                            = data;
});
},
this.add                                                    = function(movie,date)
{
$http.post(host + '/dates',{'date':date,'movie_id':movie.id}).success(function
(
                                                            data,
                                                            status,
                                                            headers,
                                                            config
                                                            )
                                                            {
$rootScope.authdates                                      = data;
});
}
});


 app.service('saleService', function($http, $rootScope, $location)
{
this.api                                                     = function()
{
$http.post(host + '/api/sales').success(function(data, status, headers, config)
{
$rootScope.sales                                             = data;
});
}
,
this.vatAmount                                               = function(vatPercentage, vatFigure)
{
return (parseFloat(vatPercentage)/100) *  (parseFloat(vatFigure));
},
//this.profit = function(totalSelling, totalCost)
//{
////  return 100 * ((parseFloat(totalSelling)/parseFloat(totalCost)) - 1);
//},
//    
this.profit = function(data){
//    sale.item.selling_price - (sale.item.buying_price + sale.vat_amount + sale.discount_amount))*sale.totalQuantity
//    return (totalSelling - totalCost);
//  return 100 * ((parseFloat(totalSelling)/parseFloat(totalCost)) - 1);
    
var listener     = 0;
 angular.forEach(data, function(value,key)
{
  listener +=  (value.item.selling_price - (value.item.buying_price + value.vat_amount + value.discount_amount))*value.totalQuantity;
});
return listener; 
    
}, 
this.totalBuying                                             = function(data)
{
 var listener     = 0;
 angular.forEach(data, function(value,key)
{
listener += parseFloat(value.total_buying);
});
return listener;

},
    this.totalSellings = function(data)
{

 var listener     = 0;
 angular.forEach(data, function(value,key)
{
//listener += parseFloat(value.total_buying);
listener += (value.item.selling_price)*(value.totalQuantity);
//     value.total_buying
});
return listener;

}, 
this.totalSelling                                            = function(data)
{
 var listener     = 0;
 angular.forEach(data, function(value,key)
{
listener += parseFloat(value.total_selling);
//     totalSells = (value.totalQuantity)*(value.total_selling);
//     console.log(totalSells);
});
return listener;

},
this.vatFigure                                               = function(data)
{
 var listener     = 0;
 angular.forEach(data, function(value,key)
{
if(value.item.vat_inclusive                                  == 1)
{
listener += parseFloat(value.total_selling);
}
});
return listener;
}


});


 app.service('roleService', function($http, $rootScope)
{
this.api                                                      = function()
{
  $http.post(host + '/api/roles').success(function(data, status, headers, config) {
        $rootScope.roles                                      = data;
  });
}
});



 app.service('screenService', function($http, $rootScope, $location)
{
 this.add                                                     = function(screen,name)
{
 $http.post(host + '/screens',{'screen_id':screen.id,'name':name}).success(function(data, status, headers, config)
{
 if (status                                                   == 200)
{
errorMessage(data);
$("#positionBtn").click();
return;
}

$rootScope.screens                                            = data;
message                                                       = 'Your successfull add new screen';
$("#positionBtn").click();
$location.path("/screens");

});
},
 this.api                                                     = function()
{
$http.post(host + '/api/screens').success(function(data, status, headers, config)
{
$rootScope.screens                                            = data;
});
},
this.new                                                      = function(timeScreen)
{
 $http.post(host + '/screens/new').success(function(data, status, headers, config)
{
$rootScope.screen                                             = data;

});
},
this.delete                                                   = function(screen)
{
 $http.delete(host + '/screens/' + screen.id).success(function(data, status, headers, config)
{
$rootScope.screens                                            = data;

});
},
this.update                                                   = function(screen,name)
{
 $http.put(host + '/screens/' + screen.id,{'name':name}).success(function(data, status, headers, config)
{
if (status                                                    == 200)
{
  errorMessage(data);
  $("#positionBtn").click();
  return;
}

message                                                       = 'Your sucessfull edit screen';
$rootScope.screens                                            = data;
$("#positionBtn").click();


});
}



});

 app.service('screenTimeService', function($http, $rootScope)
{
this.api                                                      = function()
{
  $http.post(host + '/api/screen-time').success(function(data, status, headers, config) {
      $rootScope.timeScreens                                  = data;
  });
},
this.add                                                      = function(screen_id, timeAuth)
{
$http.post(host + '/screen-time',{'time_id':timeAuth.id, 'screen_id':screen_id}).success(function(data, status, headers, config)
{
$rootScope.timeScreens                                        = data;
});
},
this.delete                                                   = function(timeScreen)
{
 $http.delete(host + '/screen-time/' + timeScreen.id ).success(function(data, status, headers, config)
{
    $rootScope.timeScreens                                    = data;
});
}
});


 app.service('consessionService', function($http, $rootScope,$location)
{

this.api                                                      = function()
{
$http.post(host + '/api/consessions').success(function(data, status, headers, config)
{
$rootScope.consessions                                        = data;
});
},
this.update                                                   = function(consession,name,buying_price,selling_price,url,avatar)
{
var fd                                                        = new FormData();
if(avatar                                                     != '')
{
var imgBlob                                                   = dataURItoBlob(avatar);
fd.append('avatar',          imgBlob);

}


fd.append('name',                                             name);
fd.append('url',                                              url);
fd.append('buying_price',                                     buying_price);
fd.append('selling_price',                                    selling_price);
$http.post(host + '/consessions/' + consession.id,fd, {transformRequest: angular.identity, headers: {'Content-Type': undefined}}).success(function(data, status, headers, config)
{
if (status                                                    == 200){errorMessage(data);$("#positionBtn").click();return;
}

message                                                       = 'Your sucessfull edit consession';
$rootScope.consessions                                        = data;
// $location.path('/consessions');
$("#positionBtn").click();

});
},
  this.delete                                                = function(consession)
  {
   $http.delete(host + '/consessions/' + consession.id).success(function(data, status, headers, config)
  {
   if (status                                                == 200)
  {
    errorMessage(data);
    $("#positionBtn").click();
    return;
  }

  message                                                   = 'Your sucessfull delete consession';
  $rootScope.consessions                                    = data;
  $("#positionBtn").click();

  });
  },
  this.add                                                  = function(name,buying_price,selling_price,url,avatar)
  {

  var fd                                                   = new FormData();
  if(avatar                                                != '')
  {
  var imgBlob                                              = dataURItoBlob(avatar);
  fd.append('avatar',          imgBlob);

  }


  fd.append('name',            name);
  fd.append('url',             url);
  fd.append('buying_price',    buying_price);
  fd.append('selling_price',   selling_price);

    $http.post(host + '/consessions',fd, {transformRequest: angular.identity, headers: {'Content-Type': undefined}}).success(function(data, status, headers, config)
  {
    if (status                                             == 200)
    {
      errorMessage(data);
      $("#positionBtn").click();
      return;
    }

    message                                                = 'Your sucessfull add new consession';
    $rootScope.consessions                                 = data;
    $location.path('/consessions');
    $("#positionBtn").click();


  });

  },
   this.show                                               = function(consession)
  {
    $rootScope.consession                                  = consession;
  },
  this.updateAvatar                                              = function(consession,src)
  {
  var fd                                                         = new FormData();
  if(src                                                         != ''){ var imgBlob  = dataURItoBlob(src); fd.append('avatar', imgBlob); }else{return;}

  $http.post(host + '/consessions/' + consession.id + '/update-avatar', fd, {transformRequest: angular.identity, headers: {'Content-Type': undefined}}).success(function(data, status, headers, config)
  {
  if(status                                                      == 200)
  {
    errorMessage(data);$("#positionBtn").click();return;
  }
  $rootScope.consessions                                         = data;
  message                                                        = "Your successfull uploid image";
  $("#positionBtn").click();
  $rootScope.avatarX = $rootScope.host + '/images/items/' + $filter('filter')(data, {id: consession.id},true)[0].avatar;
  });

  }






});

app.factory('timeService', function($http, $rootScope)
{
return {
api: function()
{
$http.post(host + '/api/times').success(function(data, status, headers, config)
{
$rootScope.times                                            = data;
});

},
add:function(dateAuth,time)
{
 $http.post(host + '/times',{'date_id':dateAuth.id, 'time':time}).success(function(data, status, headers, config)
{
$rootScope.authtimes                                        = data;
});
}
}
});

 app.controller("ScreenCtrl", [ '$scope', '$http','$filter','$location','screenService','$rootScope','rowService','seatService','$rootScope', function($scope, $http, $filter,$location,screenService,$rootScope,rowService,seatService,$rootScope)
{

  // rowService.api();
  // screenService.api();
  // seatService.api();

   $scope.addScreenEventListener      = function(screen,name)
  {
    screenService.add(screen,name);
  }

   $scope.createScreenEventListener   = function()
  {
    screenService.new();
  }

   $scope.addScreenTempEventListener  = function(name)
  {
    screenService.add(name);
  }

   $scope.screenEventListener         = function(screen)
  {
    $rootScope.screen                 = screen;
  }

   $scope.deleteScreenEventListener   = function(screen)
  {
    screenService.delete(screen);
  }

   $scope.updateScreenEventListener   = function(screen,name)
  {
    screenService.update(screen,name);

  }



   $scope.addRowsEventListener        = function(screen,rows,name)
  {
    if (isNaN(rows) == true){ message = 'Rows should be in Number Format'; $("#positionBtn").click(); }

    // if($scope.screen  == ''){ message = 'The name field is required'; $("#positionBtn").click(); return; }

    rowService.add(screen,rows,name);


  }

   $scope.updateRowEventListener      =  function(row,code)
  {
    rowService.update(row,code);
  }

   $scope.addSeatEventListen          = function(row,seatNumber)
  {
    if(row.code == ''){ message = 'The code field is required.'; $("#positionBtn").click(); return;}
    seatService.add(row,seatNumber);
  }



}]);
//
 app.service('seatService', function($http, $rootScope)
{
this.api                                                    = function()
{
$http.post(host + '/api/seats').success(function(data, status, headers, config) {
$rootScope.seats                                            = data;
});
},
this.add                                                    = function(row,number)
{
$http.post(host + '/seats',{'row_id':row.id,'number':number}).success(function(data, status, headers, config)
{
$rootScope.seats                                            = data;
});
},
this.booked                                                 = function()
{
$http.post(host + '/seat-temps/temp/booked',{}).success(function(data, status, headers, config)
{
$rootScope.bookedSeats                                      = data;
});
},
this.unBook                                                 = function(temp)
{
$http.post(host + '/seat-temps/' + temp.id + '/un-book',{}).success(function(data, status, headers, config)
{
$rootScope.bookedSeats                                      = data;
});
},
this.confirmBook                                            = function(temp)
{
$http.post(host + '/seat-temps/' + temp.id + '/confirm-book',{}).success(function(data, status, headers, config)
{
$rootScope.bookedSeats                                      = data;
});
}



});


 app.controller("SeatCtrl", [ '$scope', '$http','$filter','$location','seatService', function($scope, $http, $filter,$location,seatService)
{
  // seatService.booked();
  $scope.unBookEventListener                                 = function(temp)
  {
  seatService.unBook(temp);
  }

  $scope.isComplementaryY                                    = function(status)
  {
  if(parseInt(status) == 1) return true;
  }
  $scope.isComplementaryN                                    = function(status)
  {
  if(parseInt(status) == 0) return true;
  }

  $scope.confirmBookEventListener                            = function(temp)
  {
  seatService.confirmBook(temp);
  }


}]);




 app.controller("DashboardCtrl", [ '$scope', '$http','$filter','$location', function($scope, $http, $filter,$location)
{



}]);

app.service('reportService', function(
                                                             $http,
                                                             $rootScope,
                                                             authTimeService
                                                             )
                                                             {

this.api                                                      = function(flagNote,timer)
{
if(flagNote == 'Consession Report')
{
$http.post(host + '/api/reports',{'flagNote':flagNote, 'timer':timer}).success(function(data, status, headers, config) {
$rootScope.reports                                            = data;
});
}

if(flagNote == 'Movie Report')
{
$http.post(host + '/api/reports',{'flagNote':flagNote, 'timer':timer}).success(function(data, status, headers, config) {
$rootScope.reports                                            = data;
authTimeService.report();
});
}

},
this.dateRange                                                = function(flagNote,startDate,endDate)
{

 $http.post(host + '/reports/date-range',{'flagNote':flagNote, 'starDate':startDate, 'endDate':endDate}).success(function(data, status, headers, config)
{
$rootScope.reports                                            = data;
});

}

});

 app.controller("ReportCtrl", [ '$scope', '$http','$filter','$location','saleService','reportService','$window','$timeout','$interval','$rootScope', function($scope, $http, $filter,$location,saleService,reportService,$window,$timeout, $interval,$rootScope)
{
//Date range picker
$('#reservation').daterangepicker();

$('.applyBtn').click(function(){
    $scope.timer                                              = $('input[name="daterangepicker_start"]').val() + ' - ' + $('input[name="daterangepicker_end"]').val();
    // $window.scrollTo(0, 0);
    reportService.dateRange($scope.flagNote,$('input[name="daterangepicker_start"]').val(),$('input[name="daterangepicker_end"]').val());
});

$scope.flagNote = 'Consession Report'; $scope.timer  = 'To Day';
reportService.api($scope.flagNote,$scope.timer);



// $interval(function ()
// {
// reportService.api($scope.flagNote, $scope.timer);
// }, 20000);

$scope.noOfTicket                                           = function(reports,movie_id,date_id,time_id)
{

var listener                                                = 0;
angular.forEach(reports, function(value,key)
{
if(value.movie_id == movie_id && value.date_id == date_id && value.time_id == time_id ){
listener += 1;
}
});

return listener;

}


$scope.flagNoteEventListener                                = function(flagNote,isComplementary)
{
$scope.flagNote                                             = flagNote;
$scope.isComplementary                                      = isComplementary;
// $window.scrollTo(0, 0);
//    alert($scope.timer);
reportService.api($scope.flagNote, $scope.timer);
    


$timeout(function ()
{
TRDELETE('#tb_movie');
}, 2000);


}



saleService.api();

// reportService.lib(1);

 $scope.timeEventListener                                   = function(timer)
{
  // $window.scrollTo(0, 0);
  $scope.timer                                              = timer;
  reportService.api($scope.flagNote, timer);

}

 $scope.vatAmountEventListener                              = function(sale)
{
if(sale.item.vat_inclusive                                  == 0)return 0;
return (parseFloat(saleService.vatAmount(18,sale.total_selling)));
// + parseFloat(sale.total_selling)
// .toLocaleString()
}

$scope.netEventListener                                    = function(figure,vat)
{
return (parseFloat(figure) + parseFloat(vat));
}

//$scope.profitEventListener                                 = function(totalSelling,totalCost)
//{
//return saleService.profit(totalSelling,totalCost);
//}

$scope.profitEventListener = function(data)
{
return saleService.profit(data);
}

 $scope.totalBuyingEventListener                            = function(data)
{
  return saleService.totalBuying(data);
}

 $scope.totalSellingEventListener                           = function(data)
{
  return saleService.totalSellings(data);
}

$scope.totalSeatSellingEventListener                        = function(data)
{
var listener                                                = 0;
angular.forEach(data, function(value,key)
{
listener += parseFloat(value.price.figure);

});

return listener;

}

$scope.totalDiscountEventHandle                             = function(data)
{
var listener                                                = 0;
angular.forEach(data, function(value,key)
{
listener += parseFloat(value.discount_amount);

});

return listener;
}

$scope.netSeatSellingEventListener                          = function(data)
{
var listener                                                = 0;
angular.forEach(data, function(value,key)
{
if (parseInt(value.is_complementary) == 1)
{
listener += 0;
}
else
{
listener += parseFloat(value.price.figure);
}

});

return listener;

}

$scope.isComplementaryY                                      = function(status)
{
if(parseInt(status) == 1) return true;
}
$scope.isComplementaryN                                      = function(status)
{
if(parseInt(status) == 0) return true;
}

$scope.totalSeatVATEventListener                            = function(data)
{
var listener                                                = 0;
angular.forEach(data, function(value,key)
{

listener += parseFloat(value.vat_amount);

});

return listener;

}

$scope.totalSeatWHTEventListener                            = function(data)
{
var listener                                                = 0;
angular.forEach(data, function(value,key)
{

listener += parseFloat(value.with_draw_tax);

});

return listener;

}


$scope.netSeatSellingEventListener                          = function(data)
{
var listener                                                = 0;
angular.forEach(data, function(value,key)
{

listener += parseFloat(value.net);

});

return listener;

}


$scope.directorCommisionSeatSellingEventListener            = function(data)
{
var listener                                                = 0;
angular.forEach(data, function(value,key)
{

listener += parseFloat(value.distributor_commission);

});

return listener;

}

$scope.finalAmountSeatSellingEventListener                  = function(data)
{
var listener                                                = 0;
angular.forEach(data, function(value,key)
{

listener += parseFloat(value.final_amount);

});

return listener;

}

$scope.totalVATEventListener                               = function(data)
{
  // return (parseFloat(saleService.vatAmount(18,saleService.vatFigure(data))));

var listener = 0;
angular.forEach(data, function(value,key)
{

//listener += parseFloat(value.vat_amount);
    listener += (value.vat_amount)*(value.totalQuantity);

});

return listener;

}


}]);

  app.controller("DirectorCtrl", [ '$scope', '$http','$filter','$location','directorService', function($scope, $http, $filter,$location,directorService)
{

  // directorService.api();

  $scope.addDirectorEventListener                           = function(name)
  {
    directorService.add(name);
  }

  $scope.directorEventListener                              = function(director)
  {
    directorService.show(director);
  }

  $scope.updateDirectorEventListener                        = function(director,name)
  {
    directorService.update(director,name);

  }

   $scope.deleteDirectorEventListener                        = function(director)
  {
    directorService.delete(director);
  }

}]);


app.factory('priceService', function($http, $rootScope)
{
return {
api: function()
{
$http.post(host + '/api/prices').success(function(data, status, headers, config)
{
$rootScope.prices                                           = data;
});

},
add: function(dateAuth,price)
{
$http.post(host + '/date-user/' + dateAuth.id + '/price',{'price':price}).success(function(data, status, headers, config)
{
if(status == 200){errorMessage(data);$("#positionBtn").click();return;}

$rootScope.authdates                                        = data;
message                                                     = 'Your sucessfull assign price to ' + dateAuth.date.date ;
$("#positionBtn").click();

});

}

}
});


app.controller("MovieCtrl", [
                                  '$scope',
                                  '$http',
                                  '$filter',
                                  'movieService',
                                  '$location',
                                  'dateService',
                                  'timeService',
                                  'screenService',
                                  'screenTimeService',
                                  'authTimeService',
                                  '$log',
                                  'authDateService',
                                  'parentalGuidanceService',
                                  'directorService',
                                  'priceService',
                                  '$timeout',
                                  function
                                  (

                                  $scope,
                                  $http,
                                  $filter,
                                  movieService,
                                  $location,
                                  dateService,
                                  timeService,
                                  screenService,
                                  screenTimeService,
                                  authTimeService,
                                  $log,
                                  authDateService,
                                  parentalGuidanceService,
                                  directorService,
                                  priceService,
                                  $timeout

                                  )
                                  {



  // $('#x').change({
  //             format: 'mm/dd/yyyy',
  //             startDate: '-3d'
  // });

  // movieService.api();

  // $('[data-toggle="popover"]').popover();

  //Date range picker
  // $('#reservation').daterangepicker();

$scope.datepicker          = function()
{
$scope.datepickerlength    = 1
$('.datepicker').datepicker({
        format: 'mm/dd/yyyy',
        startDate: '-3d'
});
}



  //Timepicker
  // $(".timepicker").timepicker({
  //         showInputs: false
  // });



  ///


  //

  // authDateService.api();
  // authTimeService.api();
  // screenTimeService.api();
  // screenService.api();
  // parentalGuidanceService.api();
  // directorService.api();
  // movieService.api();
  // priceService.api();

  // timeService.api();

$scope.refreshEventListener                                = function()
{
movieService.api();
}

$scope.deleteAuthDateEventListener                        = function(dateAuth)
{
$scope.authtime                                            = '';
authDateService.delete(dateAuth);
}

$scope.movieEventListener                                  = function(movie)
{
movieService.show(movie);
$scope.src='';$scope.avatarX  = $scope.host + '/images/items/' + movie.avatar;
}

$scope.deleteTimeEventListener                            = function(authTime)
{

authTimeService.delete(authTime);

}

$scope.deleteMovieEventListener                            = function(movie)
{
movieService.delete(movie);
}

$scope.addScreenEventListener                             = function(screen_id,authTime)
{
if(screen_id == '')return;
screenTimeService.add(screen_id,authTime);
}

$scope.deleteScreenEventListener                          = function(timeScreen)
{
screenTimeService.delete(timeScreen);
}

$scope.timeEventListener                                  = function(timeAuth)
{
$scope.authtime                                            = timeAuth;
$scope.screener                                            = '';
}

$scope.addDateEventListener                                  = function
(                                                            movie,
                                                     date
                                                     )
                                                     {
dateService.add(movie,$('#date').val());
authTimeService.api();
// dateService.show(date);
}


$scope.addTimeEventListener                                = function(dateAuth,time)
{
timeService.add(dateAuth,time);

}

$scope.priceEventHandle                                    = function(dateAuth,price)
{
if(parseFloat(price) == parseFloat(dateAuth.price.figure)){return;}
if (isNaN(parseFloat(price)) == true){ message = 'Price should be numeric'; $("#positionBtn").click();return;}
priceService.add(dateAuth,parseFloat(price));
}


$scope.dateEventListener                                  = function(date)
{
$scope.authdate                                            =  date;
$scope.authtime                                            = '';
}

$scope.addMovieEventListener                              = function(name,url,avatar,parentalGuidancer,directorer,directorFee, movie)
{
movieService.add(name,url,avatar,parentalGuidancer,directorer,directorFee,movie);
}

$scope.createMovieEventListener                           = function()
{
movieService.new();
authDateService.api();
$location.path('/movies/create')
}

$scope.datePriceEventListener                         = function(dateAuth,price_id)
{
authDateService.price(dateAuth,price_id);
}

$scope.updateMovieEventListener                           = function(movie,name,director_fee)
{
movieService.update(movie,name,parseFloat(director_fee));
}

$scope.avatarUploidEventListener                          = function()
{
$scope.movieAvatar = $scope.movie;$('#avatarX').click();
}

$scope.customeOnChangeFileEventListener                   = function()
{
$scope.avatarX = '';
$timeout(function ()
{
movieService.updateAvatar($scope.movieAvatar,$scope.src);
}, 2000);
}







}]);

 app.controller("ConsessionCtrl", [ '$scope', '$http','$filter','consessionService','$location','$rootScope','$timeout','$interval', function($scope, $http, $filter,consessionService,$location,$rootScope,$timeout,$interval)
{
   if($scope.consessions.length == 0){consessionService.api();}

   $scope.addConsessionEventListener                                 = function(name,buying_price,selling_price,url,avatar)
  {
    consessionService.add(name,buying_price,selling_price,url,avatar);
  }

   $scope.consessionEventListener                            = function(consession)
  {
    consessionService.show(consession);
    $scope.src= '';$scope.avatarX  = $scope.host + '/images/items/' + consession.avatar;
  }

   $scope.avatarUploidEventListener                          = function()
  {
    $scope.consessionAvatar = $scope.consession;$('#avatarX').click();
  }

   $scope.customeOnChangeFileEventListener                   = function()
  {
  $scope.avatarX = '';
  $timeout(function ()
  {
  consessionService.updateAvatar($scope.consessionAvatar,$scope.src);
  }, 2000);

  }


  $scope.update                                              = function
  (
                                                               name,
                                                               buying_price,
                                                               selling_price,
                                                               url,
                                                               avatar
                                                             )
                                                             {
  consessionService.update(
                                                             $rootScope.consession,
                                                             name,
                                                             removeSlash(buying_price),
                                                             removeSlash(selling_price),
                                                             url,
                                                             avatar
                          );
  }

   $scope.deleteConsessionEventListener                      = function(consession)
  {
    consessionService.delete(consession);
  }




}]);

app.service('settingService', function($http, $rootScope, $location)
{
this.api                                                    = function()
{
$http.post(host + '/api/settings',{'ignoreLoadingBar': false}).success(function(data, status, headers, config)
{
$rootScope.settings                                     = data;
$rootScope.app_name = data[0].app_name; $rootScope.email = data[0].email;$rootScope.phone = data[0].phone;$rootScope.location = data[0].location;
});
},
this.update                                                 = function(app_name,email,phone,location,currency_symbol,logo,url,vat_percentage,postal_address,tin,vrn,uin,zno)
{
var fd                                                    = new FormData();
if(logo                                                   != '')
{
var imgBlob                                               = dataURItoBlob(logo);
fd.append('logo',          imgBlob);
}


fd.append('app_name',            app_name);
fd.append('email',               email);
fd.append('phone',               phone);
fd.append('location',            location);
fd.append('currency_symbol',     currency_symbol);
fd.append('url',                 url);
fd.append('vat_percentage',      vat_percentage);
fd.append('postal_address',      postal_address);
fd.append('tin',                 tin);
fd.append('vrn',                 vrn);
fd.append('uin',                 uin);
fd.append('zno',                 zno);

$http.post(host + '/settings/1',fd, {transformRequest: angular.identity, headers: {'Content-Type': undefined}}).success(function(data, status, headers, config)
{
if (status == 200){errorMessage(data);$("#positionBtn").click();return;}

message                                                = 'Your sucessfull edit settings';
$rootScope.setting = data[0];$("#positionBtn").click();



});
}

});

 app.controller("SettingCtrl", [ '$scope', '$http','$filter','$location','settingService', function($scope, $http, $filter,$location,settingService)
{
if($scope.setting.length == 0){settingService.api();}


$scope.updateSettingEventListener                            = function(app_name,email,phone,location,currency_symbol,logo,url,vat_percentage,postal_address,tin,vrn,uin,zno)
{
settingService.update(app_name,email,phone,location,currency_symbol,logo,url,vat_percentage,postal_address,tin,vrn,uin,zno);
}

}]);

  app.service('userService', function($http, $rootScope,$location,$filter,roleService)
{
this.api                                                     = function()
{
$http.post(host + '/api/users').success(function(data, status, headers, config)
{
$rootScope.users                                             = data;
});
},
this.add                                                     = function(name,role_id,email,password,password_confirmation,avatar,url)
{
var fd                                                       = new FormData();
 if(avatar                                                   != '')
{
var imgBlob                                                  = dataURItoBlob(avatar);
fd.append('avatar',                  imgBlob);
}

fd.append('name',                    name);
fd.append('url',                     url);
fd.append('role_id',                 role_id);
fd.append('email',                   email);
fd.append('password',                password);
fd.append('password_confirmation',   password_confirmation);

 $http.post(host + '/users',fd, {transformRequest: angular.identity, headers: {'Content-Type': undefined}}).success(function(data, status, headers, config)
{
if (status == 200){errorMessage(data);$("#positionBtn").click();return;}

message                                                      = 'Your sucessfull add new user';
$rootScope.users = data;$location.path('/users');
$("#positionBtn").click();


});

},
this.update                                                  = function(user,name,email,roleIndex)
{
$http.put(host + '/users/' + user.id, {'name':name,'email':email,'role_id':roleIndex}).success(function(data, status, headers, config)
{
if (status == 200){errorMessage(data);$("#positionBtn").click();return;}
message                                                      = 'Your sucessfull update user';
$rootScope.users = data;$("#positionBtn").click();

});
},
this.delete                                                  = function(user)
{
$http.delete(host + '/users/' + user.id, {}).success(function(data, status, headers, config)
{
if (status == 200){errorMessage(data);$("#positionBtn").click();return;}
message                                                      = 'Your sucessfull delete user';
$rootScope.users = data;$("#positionBtn").click();

});
},
this.updateAvatar                                            = function(user,src)
{
var fd                                                       = new FormData();
if(src                                                       != ''){ var imgBlob  = dataURItoBlob(src); fd.append('avatar', imgBlob); }else{return;}

$http.post(host + '/users/' + user.id + '/update-avatar', fd, {transformRequest: angular.identity, headers: {'Content-Type': undefined}}).success(function(data, status, headers, config)
{
if(status                                                    == 200)
{
  errorMessage(data);$("#positionBtn").click();return;
}
message = 'image is successfull uploaded';
$("#positionBtn").click();
$rootScope.users                                             = data;
$rootScope.avatarX = $rootScope.host + '/images/users/' + $filter('filter')(data, {id: user.id},true)[0].avatar;
});

}



});


 app.controller("UserCtrl", [ '$scope', '$http','$filter','$location','userService','roleService','$rootScope','$timeout', function($scope, $http, $filter,$location,userService,roleService,$rootScope,$timeout)
{
  if($scope.users.length == 0){userService.api();}

  $scope.addUserEventListener                              = function(name,role_id,email,password,password_confirmation,avatar,url)
  {
  userService.add(name,role_id,email,password,password_confirmation,avatar,url);
  }

  $('.selectpicker').selectpicker({
  style: 'btn-default',
  });



  $scope.updateUserEventListener                           = function(user,name,email,roleIndex)
  {
  if(roleIndex == '')return;
  userService.update(user,name,email,roleIndex);
  }

  $scope.userEventListener                                 = function(user)
  {
  $rootScope.user                                          = user;
  $scope.src='',$scope.avatarX  = $scope.host + '/images/users/' + user.avatar;
  }

  $scope.deleteUserEventHandle                             = function(user)
  {
  userService.delete(user);
  }

  $scope.avatarUploidEventListener                         = function()
  {
  $scope.userAvatar = $scope.user;
  $('#avatarX').click();
  }

  $scope.customeOnChangeFileEventListener                   = function()
  {
  $scope.avatarX = '';
  $timeout(function ()
  {
  userService.updateAvatar($scope.userAvatar,$scope.src);
  }, 2000);

  }





}]);
 app.service('receiptService', function($http, $rootScope,$location,$filter)
{
this.api                                                     = function()
{
$http.post(host + '/api/receipts').success(function(data, status, headers, config)
{
$rootScope.receipts                                          = data;
});
},
this.print                                                    = function(receipt)
{
$http.post(host + '/receipts/' + receipt.number + '/print').success(function(data, status, headers, config)
{
$rootScope.receipts                                           = data;
});
}


});

 app.service('seatTempService', function($http, $rootScope)
{
this.api                                                      = function()
{
$http.post(host + '/api/seat-temps').success(function(data, status, headers, config)
{
$rootScope.temps                                             = data;
});
}


});



 app.controller("ReceiptCtrl", [ '$scope', '$http','receiptService','seatTempService','$rootScope','saleService', function($scope, $http,receiptService,seatTempService,$rootScope,saleService)
{
receiptService.api();
seatTempService.api();
saleService.api();
$scope.receiptEventHandle                                    = function(receipt)
{
$rootScope.receipt                                           = receipt;
}

$scope.rePrintEventListener                                  = function(receipt)
{
receiptService.print(receipt);
}



}]);




 function dataURItoBlob(dataURI)
{

var binary                                        = atob(dataURI.split(',')[1]);
var mimeString                                    = dataURI.split(',')[0].split(':')[1].split(';')[0];
var array                                         = [];
for (var i = 0; i < binary.length; i++) {
  array.push(binary.charCodeAt(i));
}
return new Blob([new Uint8Array(array)], {
  type: mimeString
});

}

app.directive('selectPicker', ['$parse', function ($parse) {
        return {
            restrict: 'A',
            require: '?ngModel',
            priority: 10,
            compile: function (tElement, tAttrs, transclude) {
                tElement.selectpicker($parse(tAttrs.selectpicker)());
                tElement.selectpicker('refresh');
                return function (scope, element, attrs, ngModel) {
                    if (!ngModel) return;

                    scope.$watch(attrs.ngModel, function (newVal, oldVal) {
                    scope.$evalAsync(function () {
                        if (!attrs.ngOptions || /track by/.test(attrs.ngOptions)) element.val(newVal);
                        element.selectpicker('refresh');
                    });
                    });

                    ngModel.$render = function () {
                    scope.$evalAsync(function () {
                        element.selectpicker('refresh');
                    });
                    }
                };
            }

        };
}]);

app.directive('selectWatcher', function ($timeout) {
    return {
        link: function (scope, element, attr) {
            var last = attr.last;
            if (last === "true") {
                $timeout(function () {
                    // $(element).parent().selectpicker('val', 'any');
                    $(element).parent().selectpicker('refresh');
                });
            }
        }
    };
});


function removeSlash(listener)
{
if(listener                                                      !=''){return parseFloat(listener.toString().replace(/,/g,'').replace('<br>','')) ;}
return 0;

}

function TRDELETE(table)
{


// function removeDuplicateRows($table){
//     function getVisibleRowText($row){
//         return $row.find('td:visible').text().toLowerCase();
//     }

//     $table.find('tr').each(function(index, row){
//         var $row = $(row);

//         $row.nextAll('tr').each(function(index, next){
//             var $next = $(next);
//             console.log(getVisibleRowText($row), getVisibleRowText($next))
//             if(getVisibleRowText($next) == getVisibleRowText($row))
//                 $next.remove();
//         })
//     });
// }

// removeDuplicateRows($('table'));

// $(table).find('tr').each(function(){
//   var i       = 0;
//   var $date   = $(this).find('td').html();
//   var $movie  = $(this).find('td').eq(2).html();
//   var time   = $(this).find('td').eq(3).html();
//   $(table).find('tr').each(function(){
//      if ($(this).find('td').eq(0).html() == $date && $(this).find('td').eq(2).html() == $movie && $(this).find('td').eq(3).html() == $time){
//      i+=1;


//      }
//   });

//   if(i != 0)
//   {
//     $(this).remove(i);
//   }
// });

}


function errorMessage(data)
{
message                                           = '';
angular.forEach(data, function(value,key)
{
message                                            = message + value + '<br>';
});
}

})();
