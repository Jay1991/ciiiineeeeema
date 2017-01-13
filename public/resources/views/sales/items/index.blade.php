<section class="content">
  <div class="row">
    <div class="box box-primary">
      <br>
      <div class="box-body no-padding">

        <div class='col-md-9' style='padding:0px'>
            <a class="btn btn-app" ng-repeat="item in items | filter:search" ng-click="addSaleTempEventListener(item)" style="border-top:0px;background-image: url({{ host }}images/items/{{ item.avatar }});background-repeat: no-repeat; background-size: 100% auto;min-width:200px;height:250px;background-color:#fff">
                            <span class="badge bg-green" ng-show="badgeEventListener((temps | filter:{'item_id': item.id }:true).length)" ng-cloak> 
                              <span style="color:white;font-size:13px;"> {{ (temps | filter:{'item_id': item.id }:true)[0].quantity  }} </span> 
                            </span>
                            <br>
            </a>

        </div>

        <div class='col-md-3'>
                     <div class='box box-primary' style='padding-top: 2px'>
                       <input type='text' class='form-control' placeholder="Search" ng-model='search' style="height:43px">
                     
                      <!-- DIRECT CHAT DANGER -->
                      <div class="box box-default box-solid direct-chat direct-chat-info">
                        <div class="box-header">
                          <h3 class="box-title"> </h3>
                          <a ng-click="clearSaleTemp()"> <i class="glyphicon glyphicon-remove-sign"></i>  </a>
                          <div class="box-tools pull-right">                     
                            <span data-toggle="tooltip" title="number of items sold" class='badge bg-aqua'>{{ cart() }}</span>
                          </div>
                        </div><!-- /.box-header -->
                        <div class="box-body">
                          <!-- <ul class="list-group">
                              <li class="list-group-item" ng-repeat='temp in temps | filter:itemSearch'>
                                <i class="fa fa-times pull-right" ng-click='deleteTemp(temp)'></i>
                                <span class="pull-right" style='font-size:15px'> {{ temp.quantity }}  </span> <small> {{ temp.item.name }} </small> 
                              </li>
                          </ul> -->

                          <div class="col-md-12 col-sm-12">
                            <br>
                            <aside>
                              <div class="sidebar">
                                <div class="sidebar-jobs">
                                  <ul>
                                    <li ng-repeat="temp in temps | filter:{'user_id': auth.id }:true">
                                        <span>  
                                            <i class="fa fa-circle"></i>
                                            {{ temp.item.name }} <!-- {{ temp.item.code }} {{ temp.item.barcode }} {{ temp.item.selling_price | number:2 }} -->
                                            <span class="pull-right"> {{ temp.quantity }} <i class="fa fa-times pull-right" ng-click='deleteTemp(temp)'></i> </span>  
                                        </span> 
                                    </li>
                                  </ul>
                                </div>
                              </div>
                            </aside>

                            <aside>
                              <div class="sidebar">
                                <div class="sidebar-jobs">
                                  <ul>
                                    <li>
                                        <span>  
                                            <i class="fa fa-circle"></i>
                                            Sub Total 
                                            <span class="pull-right">
                                            {{ settings[0].currency_symbol }}   {{ subTotal().toLocaleString() }}  </span>  
                                        </span> 
                                    </li>
                                    <!-- <li>
                                        <span>  
                                            <i class="fa fa-circle"></i>
                                            VAT
                                            <span class="pull-right"> 
                                               <label class="checkbox-inline"><input type="checkbox" value="" ng-model="vat" ng-click="vatEvent(vat)"> % </label>
                                            </span>  
                                        </span> 
                                    </li> -->
                                    <li>
                                      <div>
                                      <i class="fa fa-circle" style="color:#1b8af3"></i>
                                      <span style="font:400 13px/13px 'Roboto'">Discount</span>
                                      </div>
                                      
                                     
                                     

                                    </li>
                                    <li>
                                        <span>  
                                            <i class="fa fa-circle"></i>
                                            Paid
                                            <span class="pull-right">  
                                            {{ settings[0].currency_symbol }} {{ toLocale(output) }}  </span>  
                                        </span> 
                                    </li>
                                    <li>
                                        <span>  
                                            <i class="fa fa-circle"></i>
                                            Total
                                            <span class="pull-right">  
                                            {{ settings[0].currency_symbol }} {{ toLocale((sub + vatAmount) - discountAmount )   }}  </span>  
                                        </span> 
                                    </li>
                                    <li>
                                        <span>  
                                            <i class="fa fa-circle"></i>
                                            Changes
                                            <span class="pull-right">  
                                            {{ settings[0].currency_symbol }} {{ toLocale(((sub + vatAmount) - discountAmount) - output)   }}  </span>  
                                        </span> 
                                    </li>

                                  </ul>
                                </div>
                              </div>
                            </aside>
                      

                          </div>

              
                        </div><!-- /.box-body -->
                        
                      </div><!-- /.direct-chat -->

                    







                       <!-- DIRECT CHAT DANGER -->
                      <div class="box box-default box-solid direct-chat direct-chat-info" style='padding-right:10px'>

                        <div class="box-body" >
                          <div ng-include="'resources/views/partials/app/calculator.blade.php'"></div>
                        </div><!-- /.box-body -->
                        
                      </div><!-- /.direct-chat -->

                      <ul class="list-group">
                          <li class="list-group-item" ><a class='btn btn-primary btn-block' ng-click="computeSaleEventListener(vatAmount,discountAmount,subTotal(),output)" > Compute </a></li>
                      </ul>







                     </div>
                    
        </div>

      </div>
    </div>

  </div>
</section>

