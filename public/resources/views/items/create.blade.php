 <span ng-init="name='';buying_price='';selling_price='';url='';avatar=''"></span> 
 <!-- Content Header (Page header) -->
        <section class="content-header">
          <h1>
            Product
            <small>Create</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX">Mailbox</li>
          </ol>
        </section>

        <!-- Main content -->
        <section class="content">
          <div class="row">
            <div class="col-md-3">
              <a href="#/consessions" class="btn btn-primary btn-block margin-bottom">Back to Home Page</a>
              <div class="sidebar-jobs" ng-if="consession !== ''">
                  <ul>
                    <li> <a href=""></a> 
                         <span>
                            <i class="fa fa-inbox"></i>
                            Name <span class="pull-right" contenteditable='true' ng-model="name"  ng-init="name = consession.name " my-enter="updateConsessionEventListener(name,consession.buying_price,consession.selling_price,'','')"> {{ consession.name }} </span>
                         </span> 
                    </li>

                    <li> <a href=""></a> 
                         <span>
                            <i class="fa fa-money"></i>
                            Buying Price <span class="pull-right" contenteditable='true' ng-model="buying_price" ng-init="buying_price = consession.buying_price" my-enter="updateConsessionEventListener(consession.name,buying_price,consession.selling_price,'','')"> {{ consession.buying_price | number:2  }} </span>
                         </span> 
                    </li>

                    <li> <a href=""></a> 
                         <span>
                            <i class="fa fa-money"></i>
                            Selling Price <span class="pull-right" contenteditable='true' ng-model="selling_price" ng-init="selling_price = consession.selling_price" my-enter="updateConsessionEventListener(consession.name,consession.buying_price,selling_price,'','')"> {{ consession.selling_price | number:2 }} </span>
                         </span> 
                    </li>

                    <li> 
                        <div class="box box-default">
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
            </div><!-- /.col -->
            <div class="col-md-9">
              <div class="box box-primary">
                <div class="box-header with-border">
                  <h3 class="box-title">Create New Product</h3>
                </div><!-- /.box-header -->
                <div class="box-body">
                     <input type="hidden" name="_token" value="{{ csrf_token() }}" ng-init="name='';buying_price='';selling_price='';url='';avatar=''">
                     <div class='form-group'>
                        <!-- <label> Name</label> -->
                        <input class='form-control'  ng-model="name" placeholder="Name *">
                     </div>
                     <div class='form-group'>
                       <div class="input-group">
                          <span class="input-group-addon">Product Type</span>
                          <select class="form-control" ng-model="item_type_id" ng-init="item_type_id = ''">
                            <option ng-repeat="itemType in itemTypes" value="{{ itemType.id }}">
                              {{ itemType.name }}
                            </option>
                          </select>
                       </div>
                     </div>
                     <div class='form-group'>
                        <!-- <label> Name</label> -->
                        <input class='form-control'  ng-model="code" placeholder="Code " ng-init="code = ''">
                     </div>
                     <div class='form-group'>
                        <!-- <label> Name</label> -->
                        <input class='form-control'  ng-model="barcode" placeholder="Barcode " ng-init="barcode = ''">
                     </div>
                     <div class='form-group'>
                        <!-- <label> Name</label> -->
                        <input class='form-control'  ng-model="isbn" placeholder="UPC/EAN/ISBN" ng-init="isbn = ''">
                     </div>
                     <div class='form-group'>
                        <!-- <label> Name</label> -->
                        <input class='form-control'  ng-model="size" placeholder="Size eg 350 ml" ng-init="size = ''">
                     </div>
                     <div class='form-group'>
                       <!-- <label>Buying Price *</label> -->
                       <div class="input-group">
                          <span class="input-group-addon">{{ setting.currency_symbol }}</span>
                          <input class="form-control" type="text"  placeholder="Buying price *"  ng-model='buying_price'>
                         <!--  <span class="input-group-addon"><i class="fa fa-ambulance"></i></span> -->
                       </div>
                     </div>
                     <div class='form-group'>
                       <!-- <label>Selling Price *</label> -->
                       <div class="input-group">
                          <span class="input-group-addon">{{ setting.currency_symbol }}</span>
                          <input class="form-control" type="text"  placeholder="Selling price *"  ng-model='selling_price'>
                          <!-- <span class="input-group-addon"><i class="fa fa-ambulance"></i></span> -->
                       </div>
                     </div>

                     <div class='form-group'>
                        <!-- <label> Name</label> -->
                        <input class='form-control'  ng-model="quantity" placeholder="quantity" ng-init="quantity = ''">
                     </div>



                     <div class="form-group">
                        <!-- <label for="exampleInputFile">Uploid Cover</label> -->
                        <input id="exampleInputFile" type="file"   fileread="avatar">
                        <img src="{{avatar}}" width="100" height="50" alt="Uploid Image...">
                     </div>

                     <div class='form-group'>
                      <!-- <label> Image Url</label> -->
                      <input type="text" class='form-control' ng-model="url" placeholder="Online Image Url">
                     </div>
                </div><!-- /.box-body -->
                <div class="box-footer">
                  <div class="pull-right">
                    <!-- <button class="btn btn-default"><i class="fa fa-pencil"></i> Draft</button> -->
                    <button type="button" class="btn btn-primary" ng-click="addItemEventListener(name,buying_price,selling_price,url,avatar,code,barcode,isbn,size,item_type_id,quantity)"><i class="glyphicon glyphicon-save"></i> Save</button>
                  </div>
                  <a class="btn btn-default" href="#/consessions"><i class="fa fa-times"></i> Close </a>
                </div><!-- /.box-footer -->
              </div><!-- /. box -->
            </div><!-- /.col -->
          </div><!-- /.row -->
        </section><!-- /.content -->




