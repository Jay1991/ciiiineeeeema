<div  class="modal example-modal" id="dateRange" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel">
            <div class="modal modal-danger">
              <div class="modal-dialog">
                <div class="modal-content">
                  <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                    <h4 class="modal-title">Do you real want to delete {{ consession.name }} consession</h4>
                  </div>
                  <div class="modal-body">
                    <div class="form-group">
                      <label>Date range:</label>
                      <div class="input-group">
                        <div class="input-group-addon">
                          <i class="fa fa-calendar"></i>
                        </div>
                        <input class="form-control pull-right active" id="reservation" type="text">
                      </div><!-- /.input group -->
                    </div>

                  </div>
                  <div class="modal-footer">
                    <button type="button" class="btn btn-outline pull-left" data-dismiss="modal">Close</button>
                    <button type="button" class="btn btn-outline" data-dismiss="modal" ng-click="deleteConsessionEventListener(consession)" >Yes </button>
                    <button type="button" class="btn btn-outline" data-dismiss="modal">No</button>
                  </div>
                </div><!-- /.modal-content -->
              </div><!-- /.modal-dialog -->
            </div><!-- /.modal -->
</div><!-- /.example-modal -->

 <style>
      .example-modal .modal {
        position: relative;
        top: auto;
        bottom: auto;
        right: auto;
        left: auto;
        display: block;
        z-index: 1;
      }
      .example-modal .modal {
        background: transparent!important;
      }
</style>