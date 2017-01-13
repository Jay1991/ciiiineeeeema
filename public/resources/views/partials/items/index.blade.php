<!-- Modal -->
<div id="itemList" class="modal fade" role="dialog">
  <div class="modal-dialog" style="width:98%">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal">&times;</button>
        <!-- <h4 class="modal-title">Modal Header</h4> -->
        <a class="btn btn-app pull-right" style="height:43px">  
          <i class="fa fa-times"></i>
        </a>
        <input type="text" class="form-control pull-right" ng-model="search" style="width:200px;height:43px" placeholder="">

      </div>
      <div class="modal-body">
        <section class="content">
          <div class="row">
            <div class="box box-danger">
              <br>
              <div class="box-body no-padding">

                <div class='col-md-12' style='padding:0px'>
                    <a class="btn btn-app" ng-repeat="item in items | limitTo:40 | filter:search" ng-click="addTableSaleTempEventListener(item)" style="border-top:0px;background-image: url({{ host }}images/items/{{ item.avatar }});background-repeat: no-repeat; background-size: 100% auto;min-width:200px;height:250px;background-color:#fff">
                                    <span class="badge bg-green" ng-show="badgeEventListener((temps | filter:{'item_id':border-bottom-width item.id }:true | filter:{'table_id':border-bottom-width table.id }:true).length)" ng-cloak> 
                                      <span style="color:white;font-size:13px;"> {{ (temps | filter:{'item_id':border-bottom-width item.id }:true | filter:{'table_id':border-bottom-width table.id }:true )[0].quantity  }} </span> 
                                    </span>
                                    <br>
                    </a>

                </div>

              </div>
            </div>

          </div>
        </section>

      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      </div>
    </div>

  </div>
</div>