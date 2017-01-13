<section class="content">
<!--   | {{ discountAmount }}  | {{ output }} | {{ temps }}-->
<!--    {{ temps[0].quantity }} | {{ temps[0].item.name }} | {{ temps[0].item.selling_price }}-->
  <div class="row">
    <div class="box box-primary" style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;font: 400 13px/13px 'Roboto', sans-serif;color:#888">
      <br>
      <div class="box-body no-padding">
        <div class='col-md-9' style='padding:0px'>
            <a class="btn btn-app" ng-repeat="consession in consessions  | filter:search" ng-click="addSaleTempEventListener(consession)"
               ng-style="{'background-image':'url({{ host }}images/items/{{ consession.avatar }})'}"
               style="border-top:0px; background-repeat: no-repeat; background-size: 100% auto; min-width:200px; height:250px; background-color:#fff">
                            <span class="badge bg-green" ng-show="badgeEventListener(90)" ng-cloak> 
                              <span style="color:white;font-size:13px;"> {{ (temps | filter:{'item_id': consession.id }:true)[0].quantity  }} </span> 
                            </span>
                            <br>
            </a>

        </div>

        <div class='col-md-3'>
                     <div class='box box-primary' style="border-top:2px solid;border-top-color:#1b8af3;padding:3px;font: 400 13px/13px 'Roboto', sans-serif;color:#888;padding:0px">
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
<!--                            {{ temps }}-->
                          <div class="col-md-12 col-sm-12" style='padding:0px'>
                            <br>
                            <aside>
                              <div class="sidebar">
                                <div class="sidebar-jobs">
                                  <ul>
                                    <li ng-repeat="temp in temps | filter:{'user_id': auth.id }:true" >
                                        <span>  
                                            <i class="fa fa-circle"></i>
                                            {{ temp.item.name }}
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
                                      <div class="col-md-12"  style="padding:0px">
                                           <label class="pull-left">Discount</label><br><br>

                                            <span class="pull-left">% </span>
                                            <input 
                                            type="text" 
                                            class="passwordX text-center"
                                            ng-model="discountPercentage"
                                            ng-init="discountPercentage = 0"
                                            ng-change="discountPercentageEventListen(discountPercentage,vat)"
                                            style="border-width:0px;border-bottom-width:1px;height:34px;width:20%"
                                            >
                                            <!-- Amount -->
                                            <input 
                                            type="text"
                                            class="passwordX"
                                            ng-model="discountAmount"
                                            ng-init="discountAmount = 0"
                                            ng-change="discountAmountEventListen(discountAmount)"
                                            style="border-width:0px;border-bottom-width:1px;height:34px;width:72%;background:#fff"
                                            >

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
                                            {{ settings[0].currency_symbol }} {{ toLocale(output - ((sub + vatAmount) - discountAmount))   }}  </span>  
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
                          <li class="list-group-item" ><a class='btn btn-primary btn-block' ng-click="computeSaleEventListener(vatAmount,discountAmount,subTotal(),output, temps)" > Compute </a></li>
                      </ul>
                         
   







                     </div>
                    
        </div>

      </div>
    </div>

  </div>
</section>

