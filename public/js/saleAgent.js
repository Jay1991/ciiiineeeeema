(function(){
var app                                                       = angular.module('app', ["ngRoute",'chieffancypants.loadingBar','angular-virtual-keyboard']);

 app.run(function($window, $rootScope,$location,$http,consessionService,tempService,receiptService) 
{

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

  $rootScope.search                                           = [];
  $rootScope.cart                                             = 0;
  $rootScope.vatAmount                                        = 0;
  $rootScope.discountAmount                                   = 0;
  $rootScope.discountPercentage                               = 0;
  $rootScope.vat = false;
  $rootScope.sub = 0;

  $rootScope.host                                             = assetpath;



  $http.post(host + '/users/auth').success(function(data, status, headers, config) {
    $rootScope.auth = data[0];
  });

  $http.post(host + '/api/settings').success(function(data, status, headers, config) {
    $rootScope.settings = data;
  });

  consessionService.api();
  tempService.api();
  receiptService.api();




});

 app.config(function($routeProvider,VKI_CONFIG) 
{
  $routeProvider
  .when("/", {
      templateUrl : "resources/views/sales/consessions/index.blade.php",
      controller : "SaleCtrl"
  })
  .otherwise({
      template : "<h1>None</h1><p>Nothing has been selected,</p>"
  });

  VKI_CONFIG.layout['Portugu\u00eas Brasileiro'] = {
        'name': "Portuguese (Brazil)", 'keys': [
        [["'", '"'], ["1", "!", "\u00b9"], ["2", "@", "\u00b2"], ["3", "#", "\u00b3"], ["4", "$", "\u00a3"], ["5", "%", "\u00a2"], ["6", "\u00a8", "\u00ac"], ["7", "&"], ["8", "*"], ["9", "("], ["0", ")"], ["-", "_"], ["=", "+", "\u00a7"], ["Bksp", "Bksp"]],
        [["Tab", "Tab"], ["q", "Q", "/"], ["w", "W", "?"], ["e", "E", "\u20ac"], ["r", "R"], ["t", "T"], ["y", "Y"], ["u", "U"], ["i", "I"], ["o", "O"], ["p", "P"], ["\u00b4", "`"], ["[", "{", "\u00aa"], ["Enter", "Enter"]],
        [["Caps", "Caps"], ["a", "A"], ["s", "S"], ["d", "D"], ["f", "F"], ["g", "G"], ["h", "H"], ["j", "J"], ["k", "K"], ["l", "L"], ["\u00e7", "\u00c7"], ["~", "^"], ["]", "}", "\u00ba"], ["/", "?"]],
        [["Shift", "Shift"], ["\\", "|"], ["z", "Z"], ["x", "X"], ["c", "C", "\u20a2"], ["v", "V"], ["b", "B"], ["n", "N"], ["m", "M"], [",", "<"], [".", ">"], [":", ":"], ["Shift", "Shift"]],
        [[" ", " ", " ", " "], ["AltGr", "AltGr"]]
      ], 'lang': ["pt-BR"] };

  VKI_CONFIG.layout.Numerico = {
        'name': "Numerico", 'keys': [
        [["1", '1'], ["2", "2"], ["3", "3"], ["Bksp", "Bksp"]],
        [["4", "4"], ["5", "5"], ["6", '6'], ["Enter", "Enter"]],
        [["7", "7"], ["8", "8"], ["9", "9"], []],
        [["0", "0"], ["-"], ["+"], [","]]
      ], 'lang': ["pt-BR-num"] };




});

 app.service('consessionService', function($http, $rootScope)
{

this.api                                                      = function()
{
 $http.post(host + '/api/consessions').success(function(data, status, headers, config) 
{
$rootScope.consessions                                        = data;
});
}                        

});

 app.filter("dateRangefilter", function($filter) 
{
return function(items, from, to) {
   return $filter('filter')(items, "name", function(v)
  {
    var date  = moment(v);
    return date >= moment(from) && date <= moment(to);
  });
};
});

app.filter('myFormat', function() 
{
  return function(x) {
      var i, c, txt = "";
      for (i = 0; i < x.length; i++) {
          c = x[i];
          if (i % 2 == 0) {
              c = c.toUpperCase();
          }
          txt += c;
      }
      return txt;
  };
});

 app.service('saleService', function($http, $rootScope)
{
  this.api                                                    = function()
  {
    $http.post(host + '/api/users').success(function(data, status, headers, config) {
          $rootScope.users = data;
    });
  },
  this.add = function(vatAmount,discountAmount,sub,output)
  {
      
     
      
//    work();
   $http.post(host + '/sales',{'vatAmount':vatAmount,'discountAmount':discountAmount,'subTotal':sub,'output':output}).success(function(data, status, headers, config) 
   {   
   if(status  == 200){ errorMessage(data);
     $("#positionBtn").click();
                      return;
                    }
  
   message                                                     = 'Your sucessfull make sales';
   $rootScope.temps                                            = data;
   $("#positionBtn").click();
   $rootScope.vat = false; $rootScope.vatAmount = 0;$rootScope.discountPercentage = 0; $rootScope.discountAmount = 0;$rootScope.output = 0;$rootScope.sub = 0;

   });

  }                        
});

  app.service('receiptService', function($http, $rootScope)
{
 this.api                                                     = function()
{
$http.post(host + '/api/receipts').success(function(data, status, headers, config) 
{
$rootScope.receipts                                           = data;
//    console.log($rootScope.receipts);
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

 app.service('tempService', function($http, $rootScope, $filter)
{
  var temp                                                    = [];
  this.api                                                    = function()
  {
   $http.post(host + '/api/sale-temps').success(function(data, status, headers, config) 
  {
  $rootScope.temps                                            = data;
  });
  },
  this.isAlreadyExist                                         = function(temps,consession,auth)
  {
  var listener = false;
   angular.forEach(temps, function(value,key)
  {

  if(parseInt(value.item_id)   == parseInt(consession.id) && parseInt(value.user_id) == parseInt(auth.id))
  {
  listener = true;
  }
  });
  return listener;


  // var data                                                    = $filter('filter')($this, {item_id: consession.id}, true);
  // var dataLength                                              = ($filter('filter')(data, {user_id: auth.id}));
  // var i                                                       = false;
  //  if(dataLength.length                                       !=0)
  // {
  //   i                                                         = true;
  //   temp                                                      = (dataLength)[0];
  // }

  // return i;
  },
  this.addSale                                                = function(consession)
  {
  $http.post(host + '/sale-temps',{'item_id':consession.id }).success(function(data, status, headers, config) {
  $rootScope.temps                                            = data;
  });
  },
  this.updateSale                                             = function(consession)
  {
  $http.put(host + '/sale-temps/' + consession.id,{
                                }).success(function(data, status, headers, config) 
  {
  $rootScope.temps                                            = data;
  });

  },
  this.subTotal                                               = function($this)
  {
  var total                                                   = 0;
  angular.forEach($this, function(value,key)
  {
  total                                                       = total + (parseFloat(value.item.selling_price) * parseFloat(value.quantity));
  $rootScope.sub                                              = total;
  });
  return total;
  },
  this.toLocale                                               = function($this)
  {
    return $this.toLocaleString();
  },
  this.vatFigure                                              = function($this)
  {
    var fig = 0; angular.forEach($this, function(value,key) { if (value.item.vat_inclusive                           == 1){ fig  += parseFloat(value.quantity * value.item.selling_price); } }); return fig; 
  },
  this.deleteSale                                             = function(temp)
  {
     $http.delete(host + '/sale-temps/' + temp.id).success(function(data, status, headers, config) 
    {
          $rootScope.temps                                    = data;
    });
  }
  ,
  this.vatAmount                                              = function(vatPercentage, vatFigure)
  {
    return (vatPercentage/100) *  (vatFigure);
  },
  this.discountPercentage                                     = function(sub,discountAmount, vatAmount)
  {
    return (discountAmount * 100)/(sub + vatAmount);
  },
  this.discountAmount                                         = function(sub,discountPercentage, vatAmount)
  {
    return (discountPercentage * (sub + vatAmount))/100;
  }                                      




});

 app.controller("SaleCtrl", [ '$scope', '$http','$filter','$location','consessionService','tempService','saleService','receiptService','$rootScope', function($scope, $http, $filter,$location,consessionService,tempService,saleService,receiptService,$rootScope) 
{
  // consessionService.api();
  // tempService.api();
  // receiptService.api();
   $scope.addSaleTempEventListener                               = function(consession)
  {
     if (tempService.isAlreadyExist($scope.temps,consession,$scope.auth)         == false)
    {
      tempService.addSale(consession);

    }
    else
    {
      tempService.updateSale(consession); 
    }

  }

   $rootScope.printReceiptEventListener                        = function(receipt)
  {
    receiptService.print(receipt);
  }

  $scope.badgeEventListener                                    = function (object) 
  {
  var listener                                                 =  true;
  if (parseInt(object)                                                   == 0)
  {
    listener                                                   = false;
  }
  return listener;

  }


   $scope.deleteTemp                                           = function($this)
  {
    tempService.deleteSale($this);
  }

   $scope.computeSaleEventListener                             = function(vatAmount,discountAmount,sub,output, temps)
  {
  
    if ($scope.temps.length == 0){
        message = 'Add items first';
        $("#positionBtn").click();
        return;
    }
       
      var zfp = new ActiveXObject("Zfpcom.ZekaFP");
      var val = zfp.FindFirstFPCOMEx();
       
      if (val){
       
       var companyName = $rootScope.settings[0].app_name;
       var hq = $rootScope.settings[0].location;
       var tin = $rootScope.settings[0].tin;
       var companyAddress = $rootScope.settings[0].postal_address;
       var vrn = $rootScope.settings[0].vrn;          
       
       openReceipt(companyName, hq, tin, companyAddress, vrn);      
       
       angular.forEach(temps, function(value,key) {
           
           printReceipt(value.item.name, value.item.selling_price, value.quantity, discountAmount, output);

           
       });
       
    subTotal();
    
    payment(output,discountAmount);
       
    closeReceipt();
          
    }
       
    saleService.add(vatAmount,discountAmount,sub,output);
       $scope.vat = false; 
       $scope.vatAmount = 0;
       $scope.discountPercentage = 0;
       $scope.discountAmount = 0;
       $scope.output = 0;
       $scope.sub = 0;
       $scope.cart(0);
       $scope.subTotal(0);    
    
       receiptService.api();
  }

  
   $scope.cart = function()  {
     var total = 0;
     angular.forEach($scope.temps, function(value,key)
    {
      total = total + parseFloat(value.quantity);
    });

    return total;

  }

   $scope.subTotal = function() {
     return tempService.subTotal($scope.temps);
  }

  $scope.toLocale = function($this) {
    return parseFloat($this).toLocaleString();
  }

   $scope.vatEvent                                             = function(vat)
  {
    if (vat                                                    == true)
   {
      $scope.vatAmount                                         = tempService.vatAmount(18, tempService.vatFigure($scope.temps));
      return;
   }
   $scope.vatAmount                                            = 0;

  }

  $scope.discountAmountEventListen                             = function($this)
  {
  $scope.discountPercentage  = tempService.discountPercentage($scope.sub, $scope.discountAmount,$scope.vatAmount);
  }

  $scope.discountPercentageEventListen                         = function($this,vat)
  {
    // var fig = 0; if (vat == true) { fig =  tempService.vatFigure($scope.temps); }
    $scope.discountAmount   =    tempService.discountAmount($scope.sub, $scope.discountPercentage,$scope.vatAmount);           
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

 // Open receipt
// res = zfp.OpenReceipt(parseInt(line.value, 10), pass.value, parseInt(type.value),
//  detail.checked ? 1 : 0, company.value, hq.value, tin.value, addr.value, city.value,
//   vrn.value, parseFloat(total.value), parseFloat(vat.value));

// res = zfp.OpenReceipt(1, password, 0,1,Company Name,Company HQ,TIN,Company Address,vrn,0,0);

 res = zfp.OpenReceipt(1, password, 0, 1, companyName, hq, tin, companyAddress, hq,vrn,0,0);
        
        
    }
    
    
    function printReceipt(movieName, price, quantity, discount, sum)
{
//    alert(movieName);
        
//    var sum = quantity*price;
    
//    alert(sum);


//    totalPrice of tickets = subTotal
//    
var zfp = new ActiveXObject("Zfpcom.ZekaFP");
//
////    Find COM port
var val = zfp.FindFirstFPCOMEx();
var comport = (val >> 24) & 0xFF
var baud = val & 0x00FFFFFF
   // alert(baud);
////    find baud by comport
////    zfp.FindBaudByCOM(comport)
//// com port, baud, retries, retryWait)
  var res = zfp.Setup(comport, baud, 3, 1000);
//
////  var res = zfp.Setup(3, 9600, 3, 1000);

//
//  // diagnostic for testing
 // res = zfp.Diagnostic();
//
//////    get operator name, pswd
//    res = zfp.GetOperatorUserPass(1);
//////    res.name, res.passwd
//    var password = res.passwd;
//    // alert(password);
//    //  //    open non-fiscal receipt
// // res = zfp.OpenBonWithEJ(1, password, 1
//
// // Open receipt
//// res = zfp.OpenReceipt(parseInt(line.value, 10), pass.value, parseInt(type.value),
////  detail.checked ? 1 : 0, company.value, hq.value, tin.value, addr.value, city.value,
////   vrn.value, parseFloat(total.value), parseFloat(vat.value));
//
//// res = zfp.OpenReceipt(1, password, 0,1,Company Name,Company HQ,TIN,Company Address,vrn,0,0);
//
// res = zfp.OpenReceipt(1, password, 0, 1, 'Company Name','Company HQ', 115098071,'Company Address',9876543210,0,0,0);



//
//    
//  //    open fiscal receipt
//  //  operator_no,pswd, detail(1,0), vat(0,1)
    // res = zfp.OpenFiscalBon(1, password, 1, 1);
//
//
//// open invoice
////  oprtNo, pswd, type, companyName, hq, tin, vrn, address, city, amt
//// vat
//// res = zfp.OpenInvoice();
//
////    register free sale
////    artical name, vat class, price, quantity, discount
////    res = zfp.SellFreeEx( , , , , , );

//    
//    //      artical name, vat class, price, quantity, discount
   // res = zfp.SellFreeEx(movieName, 1,price , quantity, 0);
//    alert(discount);
     res = zfp.SellFreeEx(movieName, 1, price, quantity, discount, 0);

     // res = zfp.SellFreeEx(line.value, parseInt(taxgrp.value, 10),
     //  parseFloat(price.value), parseFloat(quantity.value), parseFloat(discount.value), percent.checked ? 0 : 1);


//
////    register sale from fp db
////    void(0/1), PLU number, quantity, discount, percent(0/1)
////    res = zfp.SellDBEx(, , , , );
//
////    subTotal amount calculation
////    res = zfp.CalcIntermediateSum(print 1/ 0, display 1/ 0, percents 1/ 0, discount);
////        res = zfp.CalcIntermediateSum(1, 1, 1, 0.0);
    
//    subTotal();
//    
//    payment(sum,discount);
    
//    zfp.zfpType = 1;
//    res = zfp.CalcIntermediateSum2(1, 1, 1, 0,1);
//
//
////    Add discount
////    res = zfp.AddDiscount(, , ,display , discount);
//
////    res = zfp.PaymentEx(subTotal, paymentType(0-4), change(0/1), changeType(0/1/2paymentType(4), 10), paidexact(1/0));
////      res = zfp.PaymentEx(subTotal, paymentType(0-4), change(0/1), changeType(0/1/2paymentType(4), 10), paidexact(1/0));
//    
//
//
//
//// console.log(zfp.GetParameters());
//
//
////  Reprint
////	res = zfp.PrintDuplicate();
//
//  //    close fiscal device
//    res = zfp.CloseFiscalBon();
// close non-fiscal
   // res = zfp.CloseBon();
    
    
//    closeReceipt();

//
//  alert((zfp.GetErrorString(zfp.errorCode, 0)));

}
    
        function subTotal()
{
    
var zfp = new ActiveXObject("Zfpcom.ZekaFP");
    
var val = zfp.FindFirstFPCOMEx();
var comport = (val >> 24) & 0xFF
var baud = val & 0x00FFFFFF

var res = zfp.Setup(comport, baud, 3, 1000);
//    res = zfp.CalcIntermediateSum(1, 1, 1, 0.0);
    
    res = zfp.CalcIntermediateSum2(1, 1, 1,0 ,1);
    
//    alert((zfp.GetErrorString(zfp.errorCode, 0)));


}
    
    function closeReceipt()
{

var zfp = new ActiveXObject("Zfpcom.ZekaFP");

var val = zfp.FindFirstFPCOMEx();
var comport = (val >> 24) & 0xFF
var baud = val & 0x00FFFFFF

var res = zfp.Setup(comport, baud, 3, 1000);
    res = zfp.CloseFiscalBon();

}
    
        function payment(sum, discount)
{

var zfp = new ActiveXObject("Zfpcom.ZekaFP");


var val = zfp.FindFirstFPCOMEx();
var comport = (val >> 24) & 0xFF
var baud = val & 0x00FFFFFF

var res = zfp.Setup(comport, baud, 3, 1000);
    
//res = zfp.PaymentEU(parseFloat(sum.value), parseInt(line.value, 10), norest.checked ? 1 : 0, parseInt(changeType.value, 10));
res = zfp.PaymentEU(sum, 0, 0 , 0);

    
}



})();