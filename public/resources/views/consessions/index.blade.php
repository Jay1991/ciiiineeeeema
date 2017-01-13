<!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>Consessions</h1>
    </div>
  </section>
  <!--INNER BANNER END--> 

<!-- Content Header (Page header) -->
        <section class="content-header">
         <!--  <h1 style="color:#888">
            consession 
            <small>List</small>
          </h1> -->
          <!-- <ol class="breadcrumb">
            <li><a href="#/"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX"> consession</li>
          </ol> -->
        </section>
        <!-- Main content -->
        <section class="content">
          <div class="row">
            <div class="col-md-3">
              &nbsp;
              <div style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;font: 400 13px/13px 'Roboto', sans-serif;color:#888;padding-left:0px">
                <div>
                  <a href="#/consessions/create" class="btn btn-primary btn-block margin-bottom" style="background:#1b8af3">
                  create new consession
                  </a>

                  <aside style="float:none" ng-if="consession != ''">
                    <div class="sidebar" style="float:none">
                      <div class="related-people" style="float:none">
                        <ul>
                          <li ng-if="consession !=''"> 
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

                          <!-- <li ng-repeat="consession in consessions">
                            <div class="frame" style="background:#fff">
                              <a href="">
                                <img 
                                  src="{{ host }}/images/items/{{ consession.avatar }}" 
                                  alt=""
                                  class="img-thumbnail" 
                                  style="width:60px;height:60px;border-width:0px"
                                >
                              </a>
                            </div>
                            <div class="text-box"> 
                              <strong class="name">
                                <a href="">{{ consession.name }}</a>
                              </strong> 
                              <span>
                                <i class="fa fa-inbox"></i>
                                Cost price  -
                                <span >{{ consession.buying_price | number:2 }}</span>
                              </span> 
                              <span>
                                <i class="fa fa-money"></i>
                                selling price - {{ consession.selling_price | number:2 }}
                              </span> 
                            </div>
                          </li> -->
                        </ul>
                      </div>
                    </div>
                  </aside>

                 
                </div>
              </div>

              
            </div><!-- /.col -->
            <div class="col-md-9">
              &nbsp;
              <div class="box box-primary" style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;font: 400 13px/13px 'Roboto', sans-serif;color:#888">
                <div class="box-header with-border">
                  <h3 class="box-title" style="font-family:ubuntuX">consession 
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
                       {{ (consessions | filter:search).length }}/{{ consessions.length }}
                      <div class="btn-group">
                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-left"></i></button>
                        <button class="btn btn-default btn-sm"><i class="fa fa-chevron-right"></i></button>
                      </div><!-- /.btn-group -->
                    </div><!-- /.pull-right -->
                  </div>
                  <div class="">
                  <!-- table-responsive mailbox-messages -->
                    <table 
                        class="table table-bordered table-hover" 
                        style="color:#888;font:400 15px/15px 'Roboto', sans-serif"
                        >
                      <thead>
                          <!-- <th></th> -->
                          <!-- <th></th> -->
                          <th>Name</th>
                          <th>Buying Price <!-- in  {{ setting.currency_symbol }} --></th>
                          <th>Selling Price <!-- in {{ setting.currency_symbol }} --> </th>
                          <th><span class="pull-right">Action </span></th>
                      </thead>
                      <tbody>
                        <tr ng-repeat='consession in consessions | filter:search' ng-click="consessionEventListener(consession)">
                          <!-- <td style="width:10px"><input type="checkbox" /></td> -->
                          <!-- <td class="mailbox-star" style="width:5px">
                            <a href="">
                              <i class="fa fa-star-o text-yellow"></i>
                            </a>
                          </td> -->
                         <!--  <td style="width:60px"> <img src="{{ host }}/images/items/{{ consession.avatar }}"   class="img-thumbnail" style="width:40px;height:40px;" alt="&nbsp;"></td> -->
                          <td class="mailbox-name" contenteditable='true' ng-model="name"  ng-init="name = consession.name " my-enter="update(name,consession.buying_price,consession.selling_price,'','')">{{ consession.name }} </td>
                          <td contenteditable='true' ng-model="buying_price" ng-init="buying_price = consession.buying_price" my-enter="update(consession.name,buying_price,consession.selling_price,'','')"> {{ consession.buying_price  }} 
                          </td>
                          <td contenteditable='true' ng-model="selling_price" ng-init="selling_price = consession.selling_price" my-enter="update(consession.name,consession.buying_price,selling_price,'','')"> {{ consession.selling_price }}
                          </td>
                          <td>
                              <div class="btn-group pull-right">
                                <!-- <a href="#/consessions/edit" class="btn btn-default btn-sm" ng-click="consessionEventListener(consession)"><i class="glyphicon glyphicon-pencil"></i></a> -->
                                <button class="btn btn-default btn-sm" data-toggle="modal" data-target="#deleteConsession" ng-click="deleteConsessionEventListener(consession)">X</button>
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
                      <!-- {{ (consessions | filter:search).length }}/{{ consessions.length }} -->
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

<div ng-include="'resources/views/partials/consessions/delete.blade.php'"></div>
<input  type="file"   fileread="src" style="position:absolute;left:-2000px" id="avatarX" custom-on-change='customeOnChangeFileEventListener' ng-init="src = ''">



 




