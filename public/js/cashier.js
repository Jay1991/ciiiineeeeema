(function(){
var app                                                       = angular.module('app', ["ngRoute",'ngMaterial','chieffancypants.loadingBar']);

app.run(function($window, $rootScope,$location,$http,itemService,tempService,receiptService,tableService) {
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
    $rootScope.auth                                           = data[0];
  });

  $http.post(host + '/api/settings').success(function(data, status, headers, config) {
    $rootScope.settings                                       = data;
  });

  itemService.api();
  tempService.api();
  receiptService.api();
  tableService.api();




});

 app.config(function($routeProvider) 
{
  $routeProvider
  .when("/", {
      templateUrl         : "resources/views/sales/items/index.blade.php",
      controller          : "SaleCtrl"
  })
  .when("/tables", {
      templateUrl         : "resources/views/tables/index.blade.php",
      controller          : "SaleCtrl"
  })
  .otherwise({
      template            : "<h1>None</h1><p>Nothing has been selected,</p>"
  });
});

 app.service('itemService', function($http, $rootScope)
{

this.api                            = function()
{
 $http.post(host + '/api/items').success(function(data, status, headers, config) 
{
$rootScope.items                    = data;
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
          $rootScope.users                                    = data;
    });
  },
  this.add                                                    = function(vatAmount,discountAmount,sub,output)
  {
  $http.post(host + '/sales',{'vatAmount':vatAmount,'discountAmount':discountAmount,'subTotal':sub,'output':output}).success(function(data, status, headers, config) 
  {   
  if(status  == 200){ errorMessage(data); $("#positionBtn").click();return;}
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
  this.checkItemAvailability                                  = function(temps,item,auth)
  {
  var listener = false;
  angular.forEach(temps, function(value,key)
  {
  if(parseInt(value.item_id)   == parseInt(item.id) &&  parseInt(value.quantity) + 1 >  parseInt(item.quantity))
  {
  message                      = "we don't have " + item.name + " in a stock";
  $("#positionBtn").click();
  listener = true;
  }
  });
  return listener;

  },
  this.tableIsAlreadyExist                                         = function(temps,item,auth)
  {
  var listener = false;
  angular.forEach(temps, function(value,key)
  {
  if(parseInt(value.item_id)   == parseInt(item.id) && parseInt(value.user_id) == parseInt(auth.id) && parseInt(value.table_id) == parseInt($rootScope.table.id))
  {
  listener = true;
  }
  });
  return listener;
  },
  this.addSale                                                = function(item)
  {
  $http.post(host + '/sale-temps',{'item_id':item.id }).success(function(data, status, headers, config) {
  $rootScope.temps                                            = data;
  });
  },
  this.tableAddSale                                           = function(item)
  {
  $http.post(host + '/sale-temps',{'item_id':item.id,'table_id':$rootScope.table.id}).success(function(data, status, headers, config) {
  $rootScope.temps                                            = data;
  });
  },
  this.updateSale                                             = function(item)
  {
  $http.put(host + '/sale-temps/' + item.id,{
                                }).success(function(data, status, headers, config) 
  {
  $rootScope.temps                                            = data;
  });

  },
  this.tableUpdateSale                                        = function(item)
  {
  $http.put(host + '/sale-temps/' + item.id,{'table_id':$rootScope.table.id
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


 app.factory('tableService', function($http, $rootScope)
{
return {
api: function()
{
$http.post(host + '/api/tables').success(function(data, status, headers, config) 
{
$rootScope.tables                            = data;
});

},
add:function(dateAuth,time)
{
 $http.post(host + '/times',{'date_id':dateAuth.id, 'time':time}).success(function(data, status, headers, config) 
{
$rootScope.authtimes                         = data;
});
}
}               
});


 app.controller("TableCtrl", [ '$scope', '$http','$filter','$location','$rootScope','tableService', function($scope, $http, $filter,$location,$rootScope,tableService) 
{
tableService.api();
}]);

 app.controller("SaleCtrl", [ '$scope', '$http','$filter','$location','itemService','tempService','saleService','receiptService','$rootScope', function($scope, $http, $filter,$location,itemService,tempService,saleService,receiptService,$rootScope) 
{
  $scope.tableSubTotal                                          = function(table,temps,auth)
  {
  var listener = 0;
  angular.forEach(temps, function(value,key)
  {
  if(parseInt(value.user_id) == parseInt(auth.id) && parseInt(value.table_id) == parseInt(table.id))
  {
  listener  += parseFloat(value.total_selling);
  }
  });
  return listener;

  }


  $scope.addSaleTempEventListener                               = function(item)
  {
  if (tempService.checkItemAvailability($scope.temps,item,$scope.auth) == true){ return; }
  if (tempService.isAlreadyExist($scope.temps,item,$scope.auth)         == false)
  {
  tempService.addSale(item);

  }
  else
  {
  tempService.updateSale(item); 
  }

  }

  $scope.tableEventHandle                                              = function(table)
  {
  $rootScope.table    = table;
  tempService.api();  
  }

  $scope.addTableSaleTempEventListener                                 = function(item)
  {
  if (tempService.checkItemAvailability($scope.temps,item,$scope.auth) == true){ return; }
  if (tempService.tableIsAlreadyExist($scope.temps,item,$scope.auth)        == false)
  {
  tempService.tableAddSale(item);
  }
  else
  {
  tempService.tableUpdateSale(item); 
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

   $scope.computeSaleEventListener                             = function(vatAmount,discountAmount,sub,output)
  {
    if ($scope.temps.length == 0){ message = 'Add items first';$("#positionBtn").click();return;}
    saleService.add(vatAmount,discountAmount,sub,output);
    // $scope.vat = false; $scope.vatAmount = 0;$scope.discountPercentage = 0; $scope.discountAmount = 0;$scope.output = 0;$scope.sub = 0;
    
    
    receiptService.api();
  }

  
   $scope.cart                                                 = function()
  {
     var total                                                 = 0;
     angular.forEach($scope.temps, function(value,key)
    {
      total                                                    = total + parseFloat(value.quantity);
    });

    return total;

  }

   $scope.subTotal                                             = function()
  {
     return tempService.subTotal($scope.temps);
  }

  $scope.toLocale                                              = function($this)
  {
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

})();