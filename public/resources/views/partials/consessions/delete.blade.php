<div  class="modal example-modal" id="deleteConsession" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel">
            <div class="modal modal-danger">
              <div class="modal-dialog">
                <div class="modal-content">
                  <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                    <h4 class="modal-title">Do you real want to delete {{ consession.name }} consession</h4>
                  </div>
                  <div class="modal-body">
                    <!-- <p>One fine body&hellip;</p> -->
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