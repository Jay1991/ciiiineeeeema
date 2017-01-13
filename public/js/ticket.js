
(function () {

    var app = angular.module('app', ['ngRoute', 'angularMoment']);
// ,'chieffancypants.loadingBar'

app.run(function($window, $rootScope,$http,$location,movieService,authTimeService,authDateService,screenTimeService,seatService,rowService,seatTempService) {
  $rootScope.online                                           = navigator.onLine;
  $window.addEventListener("offline", function () {
    $rootScope.$apply(function() {
      $rootScope.online                                       = false;
    });
  }, false);
  $window.addEventListener("online", function () {
    $rootScope.$apply(function() {
      $rootScope.online                                       = true;
    });
  }, false);

  $rootScope.output  = 0;
  $rootScope.search  = [];
  $rootScope.host  = assetpath;


  $http.post(host + '/users/auth').success(function(data, status, headers, config)
  {
    $rootScope.auth                                           = data[0];
  });

  $http.post(host + '/api/settings').success(function(data, status, headers, config)
  {
    $rootScope.setting                                        = data[0];
  });




  movieService.seller();
  authTimeService.api();
  authDateService.api();
  screenTimeService.api();
  seatService.api();
  rowService.api();
  seatTempService.api();




});

 app.config(function($routeProvider)
{
  $routeProvider
  .when("/", {
      templateUrl                                : "resources/views/sales/movies/flag.blade.php",
      controller                                 : "SaleCtrl"
  })
  .when("/movies",                         {
      templateUrl                                : "resources/views/sales/movies/index.blade.php",
      controller                                 : "SaleCtrl"
  })
  .when("/movies/dates",                         {
      templateUrl                                : "resources/views/sales/movies/date.blade.php",
      controller                                 : "SaleCtrl"
  })
  .when("/movies/dates/times",                   {
      templateUrl                                : "resources/views/sales/movies/time.blade.php",
      controller                                 : "SaleCtrl"
  })
  .when("/movies/dates/times/screens", {
      templateUrl                                : "resources/views/sales/movies/screen.blade.php",
      controller                                 : "SaleCtrl"
  })
  .when("/movies/dates/times/screens/seats", {
      templateUrl                                : "resources/views/sales/movies/seat.blade.php",
      controller                                 : "SaleCtrl"
  })
  .otherwise({
      template                                   : "<h1>None</h1><p>Nothing has been selected,</p>"
  });
});

 app.service('movieService', function($http, $rootScope)
{

this.seller                                                   = function()
{
 $http.post(host + '/movies/seller').success(function(data, status, headers, config)
{
$rootScope.movies                                             = data;
});
},
this.show                                                     = function(movie)
{
$rootScope.movie                                              = movie;
}

});

 app.service('authTimeService', function($http, $rootScope)
{
this.api                                                      = function(movie)
{
$http.post(host + '/api/auth-times').success(function(data, status, headers, config)
{
$rootScope.authtimes                                          = data;
});
},
this.apilg                                                    = function(dateAuth)
{
$http.post(host + '/api/auth-times/lg',{'date_id':dateAuth.id}).success(function(data, status, headers, config)
{
$rootScope.authtimes                                          = data;
});
},
this.show                                                     = function(timeAuth)
{
$rootScope.authtime                                           = timeAuth;
}

});

 app.service('authDateService', function($http, $rootScope)
{
this.api                                                      = function()
{
$http.post(host + '/api/date-user').success(function(data, status, headers, config)
{
$rootScope.authdates                                          = data;
});
},
this.apilg                                                    = function(movie)
{
$http.post(host + '/api/date-user/lg',{'movie_id':movie.id}).success(function(data, status, headers, config)
{
$rootScope.authdates                                          = data;
});
},
this.show                                                     = function(dateAuth)
{
$rootScope.authdate                                           = dateAuth;
}

});

 app.service('seatService', function($http, $rootScope)
{
this.api                                                     = function()
{
$http.post(host + '/api/seats').success(function(data, status, headers, config)
{
$rootScope.seats                                             = data;
});
}
});



 app.service('screenTimeService', function($http, $rootScope)
{
this.api                                                      = function()
{
$http.post(host + '/api/screen-time').success(function(data, status, headers, config)
{
$rootScope.timeScreens                                        = data;
});
},
this.apilg                                                    = function(timeAuth)
{
$http.post(host + '/api/screen-time/lg',{'time_id':timeAuth.id}).success(function(data, status, headers, config)
{
$rootScope.timeScreens                                        = data;
});
},
this.show                                                     = function(timeScreen)
{
$rootScope.timeScreen                                         = timeScreen;
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
},
this.apilg                                                   = function(timeAuth)
{
$http.post(host + '/api/seat-temps/lg',{'time_id':timeAuth.id}).success(function(data, status, headers, config)
{
$rootScope.temps                                             = data;
});
},
this.add                                                     = function(dateAuth,timeAuth,seat,flagNote)
{
$http.post(host + '/seat-temps',{'date_id':dateAuth.date.id,'movie_id':dateAuth.movie.id,'price_id':dateAuth.price.id,'timer_id':timeAuth.time.id,'time_id':timeAuth.id,'row_id':seat.row.id,'seat_id':seat.id,'flag':flagNote}).success(function(data, status, headers, config)
{
$rootScope.temps                                             = data;
});
},
this.remove                                                  = function(timeAuth,seat,flagNote)
{
$http.post(host + '/seat-temps/remove',{'time_id':timeAuth.id,'seat_id':seat.id,'flag':flagNote}).success(function(data, status, headers, config)
{
$rootScope.temps                                             = data;
});
}


});



 app.service('rowService', function($http, $rootScope)
{
this.api                                                      = function()
{
$http.post(host + '/api/rows').success(function(data, status, headers, config)
{
$rootScope.rows                                               = data;
});
}

});




 app.service('saleService', function($http, $rootScope, $location)
{
this.api                                                    = function()
{
$http.post(host + '/api/users').success(function(data, status, headers, config) {
$rootScope.users                                            = data;
});
},
this.add                                                    = function(vatAmount,discountAmount,sub,output)
{
$http.post(host + '/sales',{'vatAmount':vatAmount,'discountAmount':discountAmount,'subTotal':sub,'output':output}).success(function(data, status, headers, config)
{
if(status  == 200){ errorMessage(data); $("#positionBtn").click();return;}
message = 'Your sucessfull make sales';
$rootScope.temps = data;
$("#positionBtn").click();
$rootScope.vat = false;
$rootScope.vatAmount = 0;
$rootScope.discountPercentage = 0;
$rootScope.discountAmount = 0;$rootScope.output = 0;$rootScope.s
});

},
this.compute = function(subTotal,output,authtime,authdate,flagNote,isComplementary, movieName, quantity, price, date, time)
{

var isComplementery = false;
if(isComplementary == true){
    isComplementery = true;
}
    
var zfp = new ActiveXObject("Zfpcom.ZekaFP");
var val = zfp.FindFirstFPCOMEx();
if (val) {    
////    print with efd
  var companyName = $rootScope.setting.app_name;
  var hq = $rootScope.setting.location;
  var tin = $rootScope.setting.tin;
  var companyAddress = $rootScope.setting.postal_address;
  var vrn = $rootScope.setting.vrn;          
  var screenName = $rootScope.timeScreen.screen.name; 
  var formattedTime = moment(time, ["HH:mm:ss"]).format("hh:mm:ss A");
  var formattedDate = $filter('date')(date, 'fullDate');

$http.get(host + '/seat-temps/' + flagNote + '/' + authtime.id)
.then(function(response){
$rootScope.selectedSeats = response.data;  
 
});
    
angular.forEach($rootScope.selectedSeats, function(value,key)
{
    var seatNumber = 'Seat No:' + value.row.code + '' + value.seat.number;
    openReceipt(companyName, hq, tin, companyAddress, vrn);
    printReceipt(movieName, 1, price, formattedDate, formattedTime, screenName, seatNumber);


}); 
    
} 

//    print with epson
    
$http.post(host + '/seat-temps/compute',{'subTotal':subTotal,'output':output, 'time_id':authtime,'flag':flagNote,'isComplementary':parseFloat(isComplementary)}).success(function(data, status, headers, config)
{
if(status  == 200){ errorMessage(data);
$("#positionBtn").click();
return;
}
$rootScope.output = 0;

message = 'ok is done';
$rootScope.temps = data;
$("#positionBtn").click();

});
}

});
    
function openReceipt(companyName, hq, tin, companyAddress, vrn){
        //    
var zfp = new ActiveXObject("Zfpcom.ZekaFP");
////    Find COM port
var val = zfp.FindFirstFPCOMEx();
var comport = (val >> 24) & 0xFF
var baud = val & 0x00FFFFFF

//// com port, baud, retries, retryWait)
  var res = zfp.Setup(comport, baud, 3, 1000);

//
////    get operator name, pswd
    res = zfp.GetOperatorUserPass(1);
////    res.name, res.passwd
    var password = res.passwd;

 
 res = zfp.OpenReceipt(1, password, 0, 1, companyName, hq, tin, companyAddress, hq,vrn,0,0);
//     res = zfp.OpenReceipt(1, password, 0, 1, -, hq, tin, companyAddress, hq,vrn,0,0);

//    res = zfp.OpenReceipt(1, password, 0, 1, '-', '-', '-', '-', '-','-',0,0);

        
        
    }
    
    function printReceipt(movieName, price, quantity, date, time, screenName, seatNumber){
        
var sum = quantity*price;
    

var zfp = new ActiveXObject("Zfpcom.ZekaFP");

////    Find COM port
var val = zfp.FindFirstFPCOMEx();
var comport = (val >> 24) & 0xFF
var baud = val & 0x00FFFFFF

//// com port, baud, retries, retryWait)
var res = zfp.Setup(comport, baud, 3, 1000);

//    //      artical name, vat class, price, quantity, discount
// res = zfp.SellFreeEx(movieName, 1,price , quantity, 0);
res = zfp.SellFreeEx(movieName, 1, price, quantity, 0, 1);    
    
printTextLeft(date);
printTextLeft(screenName);
printTextLeft(time);
printTextLeft(seatNumber);

subTotal();

payment(sum);

closeReceipt();

}
    
function subTotal(){
    
var zfp = new ActiveXObject("Zfpcom.ZekaFP");
    
var val = zfp.FindFirstFPCOMEx();
var comport = (val >> 24) & 0xFF
var baud = val & 0x00FFFFFF

var res = zfp.Setup(comport, baud, 3, 1000);
//    res = zfp.CalcIntermediateSum(1, 1, 1, 0.0);
//    0 is discount
res = zfp.CalcIntermediateSum2(1, 1, 1,0 ,1);   


}
    
function closeReceipt(){

var zfp = new ActiveXObject("Zfpcom.ZekaFP");

var val = zfp.FindFirstFPCOMEx();
var comport = (val >> 24) & 0xFF
var baud = val & 0x00FFFFFF

var res = zfp.Setup(comport, baud, 3, 1000);
res = zfp.CloseFiscalBon();

}

function payment(sum){

var zfp = new ActiveXObject("Zfpcom.ZekaFP");


var val = zfp.FindFirstFPCOMEx();
var comport = (val >> 24) & 0xFF
var baud = val & 0x00FFFFFF

var res = zfp.Setup(comport, baud, 3, 1000);

//res = zfp.PaymentEU(parseFloat(sum.value), parseInt(line.value, 10), norest.checked ? 1 : 0, parseInt(changeType.value, 10));
res = zfp.PaymentEU(sum, 0, 1 , 0);

    
}
    
    function printTextLeft(text){
        
    var zfp = new ActiveXObject("Zfpcom.ZekaFP");

    var val = zfp.FindFirstFPCOMEx();
    var comport = (val >> 24) & 0xFF
    var baud = val & 0x00FFFFFF

    var res = zfp.Setup(comport, baud, 3, 1000);        

    zfp.SetLineWidth(40);
    res = zfp.PrintText(text, 0);     

        
    }
    
    function printDuplicate(){
        
    var zfp = new ActiveXObject("Zfpcom.ZekaFP");

    var val = zfp.FindFirstFPCOMEx();
    var comport = (val >> 24) & 0xFF
    var baud = val & 0x00FFFFFF

    var res = zfp.Setup(comport, baud, 3, 1000);        

    res = zfp.PrintDuplicate();  

//          alert((zfp.GetErrorString(zfp.errorCode, 0)));
    
        
}
    
    


app.service('receiptService', function($http, $rootScope,$location,$filter)
{
this.rePrint = function()
{

var zfp = new ActiveXObject("Zfpcom.ZekaFP");
var val = zfp.FindFirstFPCOMEx();
if (val) {
    
  printDuplicate();  
}
    
$http.post(host + '/receipts/auth/re/print').success(function(data, status, headers, config)
{
// $rootScope.receipts                                           = data;
});
}


});




 app.controller("SaleCtrl", [ '$scope', '$http','$filter','$location','movieService','$rootScope','authTimeService','authDateService','screenTimeService','seatService','rowService','seatTempService','$rootScope','saleService','$interval','receiptService', function($scope, $http, $filter,$location,movieService,$rootScope,authTimeService,authDateService,screenTimeService,seatService,rowService,seatTempService,$rootScope,saleService,$interval,receiptService)
{

  // movieService.seller();
  // authTimeService.api();
  // authDateService.api();
  // screenTimeService.api();
  // seatService.api();
  // rowService.api();
  // seatTempService.api();

  $interval(function ()
  {
  seatTempService.api();
  }, 20000);

  $scope.rePrintEventHandle        = function()
  {
  receiptService.rePrint();
  }
  $scope.movieEventListener                                 = function(movie)
  {
  movieService.show(movie);
  // authDateService.apilg(movie);
  }

  $scope.dateEventListener                                  = function(dateAuth)
  {
  authDateService.show(dateAuth);
  // authTimeService.apilg(dateAuth);
  }

  $scope.timeEventListener                                  = function(timeAuth)
  {
  authTimeService.show(timeAuth);
  // screenTimeService.apilg(timeAuth);
  }

  $scope.screenEventListener                                = function(timeScreen)
  {
  screenTimeService.show(timeScreen);
  // seatTempService.apilg($scope.authtime);
  }

  $scope.addSaleTemp                                        = function(dateAuth,timeAuth,seat,flagNote)
  {
  seatTempService.add(dateAuth,timeAuth,seat,flagNote);
  }

  $scope.redEventHandle = function(temp,length,seat_id,time_id)
  {
  if (parseInt(length) !=0 && parseInt(temp.seat_id) == seat_id && parseInt(temp.time_id) == parseInt(time_id) && (parseInt(temp.user_id) != parseInt($scope.auth.id) || parseInt(temp.status) == 1))  return true;
  }

  $scope.yellowEventHandle = function(temp,length,seat_id,time_id)
  {
  if (parseInt(length) !=0  && parseInt(temp.seat_id) == parseInt(seat_id)  && parseInt(temp.time_id) == parseInt(time_id) && parseInt(temp.user_id) == parseInt($scope.auth.id) && parseInt(temp.status) == 0)  return true;
  }

  $scope.greenEventHandle                                    = function(length)
  {
  if (parseInt(length) == 0)return true;
  }

   $scope.flagNoteEventListener                             = function(flag)
  {
  $rootScope.flagNote                                       = flag;
  }

  $scope.removeSaleTemp                                     = function(timeAuth,seat,flagNote)
  {
  seatTempService.remove(timeAuth,seat,flagNote);
  }

  $scope.printEventListener = function(subTotal,output,authtime,authdate,flagNote)
  {
  saleService.print(subTotal,output,authtime,authdate,flagNote);
  }

  $scope.saleEventListener = function(subTotal,output,authtime,authdate,flagNote,isComplementary, movieName, quantity, price, date, time)
  {
      
      if(quantity > 0){
        saleService.compute(subTotal,output,authtime,authdate,flagNote,isComplementary, movieName, quantity, price, date, time);
          
      } 
  
  }

  $scope.totalEventListener                                  = function(auth,authtime,authdate)
  {
  var listener                                              = 0;
  angular.forEach($scope.temps, function(value,key)
  {

  if(parseInt(value.time_id) == parseInt(authtime.id) && parseInt(value.user_id) == parseInt(auth.id) && parseInt(value.status) == 0)
  {
  listener                                                   += parseFloat(authdate.price.figure);
  }

  });

  return listener;


  }


  $scope.output                                        = "0";
  $scope.OK                                            = function()
  {

  }


  $scope.paid                                         = 0;
  $scope.output                                      = "0";

  $scope.newNumber                                   = true;

  $scope.pendingOperation                            = null;

  $scope.operationToken                              = "";

  $scope.runningTotal                                = null;

  $scope.pendingValue                                = null;

  $scope.lastOperation                               = null;

  var ADD                                            = "adding";
  var SUBTRACT                                       = "subtracting";
  var ADD_TOKEN                                      = "+";
  var SUBTRACT_TOKEN                                 = "-";

  $scope.updateOutput                                = function(btn) {
            if($scope.output                                == "0" || $scope.newNumber) {
              $scope.output                                 = btn;
              $scope.newNumber                              = false;
            } else {
                $scope.output                               += String(btn);
            }
            $scope.pendingValue                             = toNumber($scope.output);
            $scope.paid                              = $scope.output;
  };

  $scope.add = function() {
            if($scope.pendingValue) {
              if($scope.runningTotal && $scope.pendingOperation == ADD ) {
                $scope.runningTotal                         += $scope.pendingValue;
              } else if($scope.runningTotal && $scope.pendingOperation == SUBTRACT ) {
                $scope.runningTotal                         -= $scope.pendingValue;
              }
              else {
                $scope.runningTotal                         = $scope.pendingValue;
              }
            }
            setOperationToken(ADD);
            setOutput(String($scope.runningTotal));
            $scope.pendingOperation                         = ADD;
            $scope.newNumber                                = true;
            $scope.pendingValue                             = null;
  };

  $scope.subtract = function() {
            if($scope.pendingValue) {
              if($scope.runningTotal && ($scope.pendingOperation == SUBTRACT) ) {
                $scope.runningTotal                         -= $scope.pendingValue;
              } else if($scope.runningTotal && $scope.pendingOperation == ADD ) {
                $scope.runningTotal                         += $scope.pendingValue;
              } else {
                $scope.runningTotal                         = $scope.pendingValue;
              }
            }
            setOperationToken(SUBTRACT);
            setOutput(String($scope.runningTotal));
            $scope.pendingOperation                         = SUBTRACT;
            $scope.newNumber                                = true;
            $scope.pendingValue                             = null;
  };

  $scope.calculate = function() {
            if(!$scope.newNumber) {
              $scope.pendingValue                           = toNumber($scope.output);
              $scope.lastValue                              = $scope.pendingValue;
            }
            if($scope.pendingOperation                      == ADD) {
              $scope.runningTotal                           += $scope.pendingValue;
              $scope.lastOperation                          = ADD;
            } else if($scope.pendingOperation               == SUBTRACT) {
              $scope.runningTotal                           -= $scope.pendingValue;
              $scope.lastOperation                          = SUBTRACT;
            } else {
              if($scope.lastOperation) {
                if($scope.lastOperation                     == ADD) {
                  if($scope.runningTotal) {
                    $scope.runningTotal                     += $scope.lastValue;
                  } else {
                    $scope.runningTotal                     = 0;
                  }
                } else if($scope.lastOperation              == SUBTRACT) {
                  if($scope.runningTotal) {
                    $scope.runningTotal                     -= $scope.lastValue;
                  } else {
                    $scope.runningTotal                     = 0;
                  }
                }
              } else {
                $scope.runningTotal                         = 0;
              }
            }
            setOutput($scope.runningTotal);
            setOperationToken();
            $scope.pendingOperation                         = null;
            $scope.pendingValue                             = null;
            $scope.paid                              = $scope.output;
  };


  $scope.clear = function() {
            $scope.runningTotal                             = null;
            $scope.pendingValue                             = null;
            $scope.pendingOperation                         = null;
            setOutput("0");
            $scope.output                                   = 0;
            $scope.paid                              = $scope.output;
  };

  setOutput                                          = function(outputString) {
            $scope.output                                   = outputString;
            $scope.newNumber                                = true;
            $scope.paid                              = $scope.output;
  };

  setOperationToken                                  = function(operation) {
            if(operation                                    == ADD) {
              $scope.operationToken                         = ADD_TOKEN;
            } else if (operation                            == SUBTRACT) {
              $scope.operationToken                         = SUBTRACT_TOKEN;
            } else {
              $scope.operationToken                         = "";
            }
  };

  toNumber                                           = function(numberString) {
            var result                                      = 0;
            if(numberString) {
              result                                        = numberString*1;
            }
            return result;
  };





}]);



app.directive("fileread", [
  function() {
    return {
      scope: {
        fileread: "="
      },
      link: function(scope, element, attributes) {
        element.bind("change", function(changeEvent) {

          var reader = new FileReader();
          reader.onload = function(loadEvent) {
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

 function errorMessage(data)
{
message                                                   = '';
 angular.forEach(data, function(value,key)
{
 message                                                  = message + value + '<br>';
});
}

})();
