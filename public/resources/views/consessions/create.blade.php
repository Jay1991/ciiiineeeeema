 <!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>Create Consession</h1>
    </div>
  </section>
  <!--INNER BANNER END--> 
       <span ng-init="name='';buying_price='';selling_price='';url='';avatar=''"></span> 
       <!-- Content Header (Page header) -->
       <!--  <section class="content-header">
          <h1>
            Consession
            <small>Create</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX">Mailbox</li>
          </ol>
        </section> -->
        <!-- Main content -->
        <section class="content">
          <div class="row">
            <div class="col-md-3">
              &nbsp;  
              <div  style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;font: 400 13px/13px 'Roboto', sans-serif;color:#888">
                <div  style="padding:0px;">
                          <a  href="#/consessions" 
                              class="btn btn-primary btn-block margin-bottom" 
                              style="background:#1b8af3"
                              >
                              <i class="ionicons ion-ios-arrow-back"></i> 
                              &nbsp; Back to Home Page
                          </a>
                          <div class="sidebar-jobs" style="float:none">
                                <ul>
                                  <li> <a href=""></a> 
                                       <span>
                                          <!-- Name --> 
                                          <span class="" contenteditable='true' ng-model="name"  ng-init="name = consession.name " my-enter="updateConsessionEventListener(name,consession.buying_price,consession.selling_price,'','')"> 
                                            <i class="fa fa-inbox"></i>
                                            {{ consession.name }} 
                                          </span>
                                       </span> 
                                  </li>

                                  <li> <a href=""></a> 
                                       <span>
                                          <i class="fa fa-money"></i>
                                          B.P <span class="pull-right" contenteditable='true' ng-model="buying_price" ng-init="buying_price = consession.buying_price" my-enter="updateConsessionEventListener(consession.name,buying_price,consession.selling_price,'','')"> {{ consession.buying_price | number:2  }} </span>
                                       </span> 
                                  </li>

                                  <li> <a href=""></a> 
                                       <span>
                                          <i class="fa fa-money"></i>
                                          S.P <span class="pull-right" contenteditable='true' ng-model="selling_price" ng-init="selling_price = consession.selling_price" my-enter="updateConsessionEventListener(consession.name,consession.buying_price,selling_price,'','')"> {{ consession.selling_price | number:2 }} </span>
                                       </span> 
                                  </li>

                                  <li> 
                                      <div >
                                        <div class="" style="border-top:0px;background-image: url({{ src }}{{ avatarX }});background-repeat: no-repeat; background-size: 100% auto;min-width:200px;height:300px;background-color:#fff">
                                          <center style="padding-top:30%">
                                            <button class="btn btn-default btn-lg" ng-click="avatarUploidEventListener()">
                                              <i class="fa fa-camera"></i>
                                            </button>
                                          </center>

                                        </div><!-- /.box-body -->
                                      </div><!-- /.box -->
                                  </li>

                                  


                                </ul>
                          </div>
                </div>
              </div>
            </div><!-- /.col -->
            <div class="col-md-9">
              &nbsp;
              <div class="box box-primary" style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;font: 400 13px/13px 'Roboto', sans-serif;color:#888">
                <!-- <div class="box-header with-border">
                  <h3 class="box-title">Create New Consession</h3>
                </div> -->
                <div class="box-body">

                     <input type="hidden" name="_token" value="{{ csrf_token() }}" ng-init="name='';buying_price='';selling_price='';url='';avatar=''">
                     <div class='form-group'>
                        <span> Name *</span>
                        <input 
                          class='passwordX'  
                          ng-model="name" 
                          placeholder="" 
                          style="border-width:0px;border-bottom-width:1px;height:34px"
                          >
                     </div>
                     <div class='form-group'>
                        <span> Buying Price *</span>
                        <input 
                          class="passwordX" 
                          type="text"  
                          placeholder=""  
                          ng-model='buying_price' 
                          style="border-width:0px;border-bottom-width:1px;height:34px"
                          >
                     </div>

                     <div class='form-group'>
                        <span> Selling Price *</span>
                        <input 
                          class="passwordX" 
                          type="text"  
                          placeholder=""  
                          ng-model='selling_price' 
                          style="border-width:0px;border-bottom-width:1px;height:34px"
                          >
                     </div>

                     

                     <div class="form-group">
                        <!-- <label for="exampleInputFile">Uploid Cover</label> -->
                        <input id="exampleInputFile" type="file"   fileread="avatar">
                        <img src="{{avatar}}" width="100" height="50" alt="">
                     </div>

                    
                    <div class='form-group'>
                        <span> Online Image Url </span>
                         <input 
                          type="text" 
                          class='passwordX' 
                          ng-model="url" 
                          placeholder="" 
                          style="border-width:0px;border-bottom-width:1px;height:34px"
                          >
                     </div>

                </div><!-- /.box-body -->
                <div class="box-footer">
                  <div class="pull-right">
                    <!-- <button class="btn btn-default"><i class="fa fa-pencil"></i> Draft</button> -->
                    <button 
                          type="button" 
                          class="btn btn-primary" 
                          style="background:#1b8af3"
                          ng-click="addConsessionEventListener(

                                                              name,
                                                              buying_price,
                                                              selling_price,
                                                              url,
                                                              avatar

                                                              )"
                          >
                          
                          Save
                    </button>
                  </div>
                  <a class="btn btn-default" href="#/consessions"><i class="fa fa-times"></i> Close </a>
                </div><!-- /.box-footer -->
              </div><!-- /. box -->
            </div><!-- /.col -->
          </div><!-- /.row -->
        </section><!-- /.content -->




