<!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>Products</h1>
    </div>
  </section>
<!--INNER BANNER END--> 
<!-- Content Header (Page header) -->
        <!-- <section class="content-header">
          <h1 style="font-family:ubuntu condensedX">
            Products 
            <small>List</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#/"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX"> Product</li>
          </ol>
        </section> -->
        <!-- Main content -->
        <section class="content">
          <div class="row">
            <div class="col-md-3">
              &nbsp;
              <div class="box box-primary">
                <div class="box box-body" style="padding:1px">
                  <a href="#/items/create" class="btn btn-primary btn-block margin-bottom">create product</a>

                  <div class="sidebar-jobs">
                      <ul>
                        <li> <a href=""></a> 
                             <span>
                                <i class="fa fa-circle"></i>
                                Name <span class="pull-right" contenteditable='true' ng-model="name"  ng-init="name = item.name " my-enter="updateConsessionEventListener(name,item.buying_price,item.selling_price,'','')"> {{ item.name }} </span>
                             </span> 
                        </li>

                        <li> <a href=""></a> 
                             <span>
                                <i class="fa fa-circle"></i>
                                Buying Price <span class="pull-right" contenteditable='true' ng-model="buying_price" ng-init="buying_price = item.buying_price" my-enter="updateConsessionEventListener(item.name,buying_price,item.selling_price,'','')"> {{ item.buying_price | number:2  }} </span>
                             </span> 
                        </li>

                        <li> <a href=""></a> 
                             <span>
                                <i class="fa fa-circle"></i>
                                Selling Price <span class="pull-right" contenteditable='true' ng-model="selling_price" ng-init="selling_price = item.selling_price" my-enter="updateConsessionEventListener(item.name,item.buying_price,selling_price,'','')"> {{ item.selling_price | number:2 }} </span>
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
                        <li> <a href=""></a> 
                             <span>
                                <i class="fa fa-circle"></i>
                                Product Type <span class="pull-right" contenteditable='true' ng-model="product_type_id" ng-init="product_type_id = item.type.id" my-enter="updateConsessionEventListener(item.name,item.buying_price,selling_price,'','')"> {{ item.type.name }} </span>
                             </span> 
                        </li>
                        <li> <a href=""></a> 
                             <span>
                                <i class="fa fa-circle"></i>
                                Code <span class="pull-right" contenteditable='true' ng-model="code" ng-init="code = item.code" my-enter="updateConsessionEventListener(item.name,item.buying_price,selling_price,'','')"> {{ item.code }} </span>
                             </span> 
                        </li>
                        <li> <a href=""></a> 
                             <span>
                                <i class="fa fa-circle"></i>
                                UPC/EAN/ISBN <span class="pull-right" contenteditable='true' ng-model="isbn" ng-init="isbn = item.isbn" my-enter="updateConsessionEventListener(item.name,item.buying_price,selling_price,'','')"> {{ item.isbn }} </span>
                             </span> 
                        </li>
                        <li> <a href=""></a> 
                             <span>
                                <i class="fa fa-circle"></i>
                                Barcode <span class="pull-right" contenteditable='true' ng-model="barcode" ng-init="barcode = item.barcode" my-enter="updateConsessionEventListener(item.name,item.buying_price,selling_price,'','')"> {{ item.barcode }} </span>
                             </span> 
                        </li>

                        


                      </ul>
                  </div>
                </div>
              </div>

              
            </div><!-- /.col -->
            <div class="col-md-9">
              &nbsp;
              <div class="box box-primary">
                <div class="box-header with-border">
                  <h3 class="box-title" style="">
                      Product 
                      <!-- <small> List</small> -->
                  </h3>
                  <div class="box-tools pull-right">
                    <div class="has-feedback">
                      <input type="text" class="form-control input-sm" placeholder="Search" ng-model="search"/>
                      <span class="glyphicon glyphicon-search form-control-feedback"></span>
                    </div>
                  </div><!-- /.box-tools -->
                </div><!-- /.box-header -->
                <div class="box-body no-padding">
                  <div class="mailbox-controls">
                    <!-- Check all button -->
                    <!-- <button class="btn btn-default btn-sm checkbox-toggle"><i class="fa fa-square-o"></i></button> -->
                    <div class="btn-group">
                      <!-- <button class="btn btn-default btn-sm"><i class="fa fa-trash-o"></i></button> -->
                     
                    </div><!-- /.btn-group -->
                    <!-- <button class="btn btn-default btn-sm"><i class="fa fa-refresh"></i></button> -->
                    <div class="pull-right">
                       {{ (items | filter:search).length }}/{{ items.length }}
                      <div class="btn-group">
                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-left"></i></button>
                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-right"></i></button>
                      </div><!-- /.btn-group -->
                    </div><!-- /.pull-right -->
                  </div>
                  <div class="table-responsive mailbox-messages" style="width:100%">
                  <br>
                  <!-- table-responsive mailbox-messages -->
                    <table class="table table-bordered table-hover" style="font: 400 13px/13px 'Roboto', sans-serif;color:#888">
                      <thead>
                          <!-- <th></th> -->
                          <!-- <th></th> -->
                          <th>Name</th>
                          <th>Code</th>
                          <th>Product Type</th>
                          <th>Barcode</th>
                          <th>UPC/EAN/ISBN</th>
                          <th>Size</th>
                          <th>Buying Price <!-- in  {{ setting.currency_symbol }} --></th>
                          <th>Selling Price <!-- in {{ setting.currency_symbol }} --> </th>
                          <th>quantity</th>
                          <th><span class="pull-right">Action </span></th>
                      </thead>
                      <tbody>
                        <tr ng-repeat='item in items | filter:search' ng-click="itemEventListener(item)">
                          <!-- <td style="width:60px"> <img src="{{ host }}/images/items/{{ item.avatar }}"   class="img-thumbnail" style="width:40px;height:40px;" alt="&nbsp;"></td> -->
                          <td class="mailbox-name" contenteditable='true' ng-model="name"  ng-init="name = item.name " my-enter="updateConsessionEventListener(name,item.buying_price,item.selling_price,'','')">{{ item.name }} </td>
                          <td contenteditable='true' ng-model="code" ng-init="code = item.code" my-enter="updateConsessionEventListener(item.name,buying_price,item.selling_price,'','')"> {{ item.code }} 
                          </td>
                          <td> {{ item.type.name }} </td>
                          <td contenteditable='true' ng-model="barcode" ng-init="barcode= item.barcode" my-enter="updateConsessionEventListener(item.name,buying_price,item.selling_price,'','')"> {{ item.barcode }} 
                          </td>
                          <td contenteditable='true' ng-model="isbn" ng-init="isbn = item.isbn" my-enter="updateConsessionEventListener(item.name,buying_price,item.selling_price,'','')"> {{ item.isbn }} 
                          </td>
                          <td contenteditable='true' ng-model="size" ng-init="size = item.size" my-enter="updateConsessionEventListener(item.name,buying_price,item.selling_price,'','')"> {{ item.size }} 
                          </td>
                          <td contenteditable='true' ng-model="buying_price" ng-init="buying_price = item.buying_price" my-enter="updateConsessionEventListener(item.name,buying_price,item.selling_price,'','')"> {{ item.buying_price }} 
                          </td>
                          <td contenteditable='true' ng-model="selling_price" ng-init="selling_price = item.selling_price" my-enter="updateConsessionEventListener(item.name,item.buying_price,selling_price,'','')"> {{ item.selling_price }}
                          </td>
                          <td contenteditable='true' ng-model="quantity" ng-init="quantity = item.quantity" my-enter="updateConsessionEventListener(item.name,buying_price,item.selling_price,'','')"> {{ item.quantity }} 
                          </td>
                          <td>
                              <div class="btn-group pull-right">
                                <!-- <a href="#/items/edit" class="btn btn-default btn-sm" ng-click="itemEventListener(item)"><i class="glyphicon glyphicon-pencil"></i></a> -->
                                <button class="btn btn-default btn-sm" data-toggle="modal" data-target="#deleteConsession" ng-click="itemEventListener(item)">X</button>
                              </div><!-- /.btn-group -->

                          </td>
                        </tr>
                      </tbody>
                    </table><!-- /.table -->
                  </div><!-- /.mail-box-messages -->
                </div><!-- /.box-body -->
                <div class="box-footer no-padding">
                  <div class="mailbox-controls">
                    <!-- Check all button -->
                    <!-- <button class="btn btn-default btn-sm checkbox-toggle"><i class="fa fa-square-o"></i></button>                     -->
                    <div class="btn-group">
                      <!-- <button class="btn btn-default btn-sm"><i class="fa fa-trash-o"></i></button> -->
                      
                    </div><!-- /.btn-group -->
                    <!-- <button class="btn btn-default btn-sm"><i class="fa fa-refresh"></i></button> -->
                    <div class="pull-right">
                      <!-- {{ (items | filter:search).length }}/{{ items.length }} -->
                      <div class="btn-group">
                        <!-- <button class="btn btn-default btn-sm"><i class="fa fa-chevron-left"></i></button> -->
                        <!-- <button class="btn btn-default btn-sm"><i class="fa fa-chevron-right"></i></button> -->
                      </div><!-- /.btn-group -->
                    </div><!-- /.pull-right -->
                  </div>
                </div>
              </div><!-- /. box -->
            </div><!-- /.col -->
            
          </div><!-- /.row -->
        </section><!-- /.content -->

<div ng-include="'resources/views/partials/items/delete.blade.php'"></div>
<input  type="file"   fileread="src" style="position:absolute;left:-2000px" id="avatarX" custom-on-change='customeOnChangeFileEventListener' ng-init="src = ''">



 




