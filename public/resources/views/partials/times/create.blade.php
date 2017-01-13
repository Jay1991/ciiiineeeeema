<div class="modal" id="createTime" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel"  ng-init="time=''">
     <div class="modal-dialog" style="width:80%">
            <div class="modal-content">
                     <div class="modal-header">
                           <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                          <h4 class="modal-title text-center" id="myModalLabel"> Add Time</h4>
                     </div>
                     <div class="modal-body">
                     

                      <!-- time Picker -->
                      <div class="bootstrap-timepicker">
                          <div class="form-group">
                            <label>Time</label>
                            <div class="input-group">
                              <input type="text" class="form-control timepicker" ng-model="time">
                              <div class="input-group-addon">
                                <i class="fa fa-clock-o"></i>
                              </div>
                            </div><!-- /.input group -->
                          </div><!-- /.form group -->
                      </div>

                      <center>
                        <a class="btn btn-primary btn-md" ng-click="addTime(date,time)" data-dismiss="modal"> Save </a>
                      </center>

                
                     </div>

                     <div class="modal-footer">
                     </div>
            </div>
    </div>
</div>
