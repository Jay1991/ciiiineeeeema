
<section class="content">
  <div class="row">
        <div class='col-md-3'  ng-repeat="table in tables | filter:search">
          <div class="box box-primary">
            <div class="box box-body">
              <div class="sidebar-jobs">
                  <ul>
                    <li> <a href="#">{{ table.name }}</a> 
                    <span>
                        <a class="btn btn-app pull-right" style="max-width:100px" data-toggle="modal" data-target="#itemList" ng-click="tableEventHandle(table)">
                          <br> 
                          <!-- <i class="fa fa-plus-square"></i> -->
                          +
                        </a>
                        <a class="btn btn-app pull-left" style="max-width:auto;color:#888;padding:10px;">
                          <br>
                          <span style="font-family:ubuntu condensedX">{{ tableSubTotal(table,temps,auth) | number:2 }}</span>
                        </a>
                    </span> 

                    </li>
                    <li ng-repeat="temp in temps | filter:{'table_id':border-bottom-width table.id }:true">  
	                    <span>  
                            <i class="fa fa-circle"></i>
                            {{ temp.item.name }}
                            <span class="pull-right"> {{ temp.quantity }} <i class="fa fa-times pull-right" ng-click='deleteTemp(temp)'></i> 
                            </span>  
                        </span> 
                    </li>
                    <li>
                    <!-- font-size:20px -->
                    <!-- <div class="well text-center" style="color:#fff;background:#1b8af3;font-family:ubuntu"> {{ tableSubTotal(table,temps,auth) | number:2 }}  -->
                    </div>
                    </li>
                  </ul>
              </div>
            </div>
          </div>
        </div>
  </div>
</section>

<div ng-include="'resources/views/partials/items/index.blade.php'"></div>

