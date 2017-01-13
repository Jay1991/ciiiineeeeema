  <!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>Settings</h1>
    </div>
  </section>

  <!--INNER BANNER END--> 
 <span ng-init="url='';logo='';src=host + '/images/' + setting.logo"></span> 
 <!-- Content Header (Page header) -->
        <!-- <section class="content-header">
          <h1 style="font-family:ubuntu condensed;color:#888">
            Config
            <small>13 new messages</small>
          </h1>
          <ol class="breadcrumb">
            <li><a href="#/"><i class="fa fa-dashboard"></i> Home</a></li>
            <li class="activeX">config</li>
          </ol>
        </section> -->

        <!-- Main content -->
        <section class="content">
          <div class="row">
            <div class="col-md-3">
              &nbsp;
              <div class="" style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;font: 400 13px/13px 'Roboto', sans-serif;color:#888"">
                <div class="" style="padding:2px;padding:0px" >
                  <a href="#/" class="btn btn-primary btn-block margin-bottom" style="background:#1b8af3">Back to Home Page
                  </a>
                  <br><br><br><br><br><br>
                  
                  <div class="sidebar-jobs" style="float:none">
                     <!--  <ul>
                        <li> 
                          <a href=""></a> 
                          <span>
                            <i class="fa fa-circle"></i>
                            App Name <span class="pull-right" contenteditable="true" ng-model="app_name" ng-init="app_name = setting.app_name" my-enter="updateSettingEventListener(app_name,setting.email,setting.phone,setting.location,setting.currency_symbol,'','',setting.vat_percentage)"> {{ setting.app_name }} </span> 
                          </span> 
                        </li>
                        <li> 
                          <a href=""></a> 
                          <span>
                            <i class="fa fa-phone"></i>
                            Phone <span class="pull-right" contenteditable="true" ng-model="phone" ng-init="phone = setting.phone" my-enter="updateSettingEventListener(setting.app_name,setting.email,phone,setting.location,setting.currency_symbol,'','',setting.vat_percentage)"> {{ setting.phone }} </span> 
                          </span> 
                        </li>
                        <li> 
                          <a href=""></a> 
                          <span>
                            <i class="fa fa-money"></i>
                            Currency Symbol 
                            <span class="pull-right" contenteditable="true" ng-model="currency_symbol" ng-init="currency_symbol = setting.currency_symbol" my-enter="updateSettingEventListener(setting.app_name,setting.email,phone,setting.location,setting.currency_symbol,'','',setting.vat_percentage)"> 
                            {{ setting.currency_symbol }} 
                            </span> 
                          </span> 
                        </li>
                        <li> 
                          <a href=""></a> 
                          <span>
                            <i class="fa fa-envelope-o"></i>
                            Email 
                            <span class="pull-right"> 
                            {{ setting.email }} 
                            </span> 
                          </span> 
                        </li>
                        <li> 
                          <a href=""></a> 
                          <span>
                            <i class="fa fa-inbox"></i>
                            local tax % 
                            <span class="pull-right"> 
                            {{ setting.vat_percentage }} 
                            </span> 
                          </span> 
                        </li>
                        <li> 
                          <a href=""></a> 
                          <span>
                            <i class="fa fa-map-marker"></i>
                            location
                            <span class="pull-right"> 
                            {{ setting.location }} 
                            </span> 
                          </span> 
                        </li>
                        <li>
                          <a href=""></a> 
                          <span>
                            <i class="fa fa-inbox"></i>
                            TIN * 
                            <span class="pull-right"> 
                            {{ setting.tin }} 
                            </span> 
                          </span> 

                        </li>
                        <li>
                          <a href=""></a> 
                          <span>
                            <i class="fa fa-inbox"></i>
                            VRN 
                            <span class="pull-right"> 
                            {{ setting.vrn }} 
                            </span> 
                          </span> 

                        </li>
                        <li>
                          <a href=""></a> 
                          <span>
                            <i class="fa fa-inbox"></i>
                            UIN *
                            <span class="pull-right"> 
                            {{ setting.uin }} 
                            </span> 
                          </span> 

                        </li>
                        <li>
                          <a href=""></a> 
                          <span>
                            <i class="fa fa-inbox"></i>
                            Postal Address
                            <span class="pull-right"> 
                            {{ setting.postal_address }} 
                            </span> 
                          </span> 

                        </li>
                      </ul> -->
                  </div>
                </div>
              </div>
            </div>
            <div class="col-md-9">
              &nbsp;
              <div class="box box-primary" style="border-top:2px solid;border-top-color:#1b8af3;box-shadow: 0 3px 6px 0 rgba(0,0,0,0.15);border-radius:3px;padding:3px;font: 400 13px/13px 'Roboto', sans-serif;color:#888"">
                <div class="box-header with-border">
                  <h3 class="box-title" style="font: 400 13px/13px 'Roboto', sans-serif;color:#888">Config</h3>
                </div><!-- /.box-header -->
                <div class="box-body">
                  <div class="form-group">
                    <label>App Name *</label>
                    <input 
                      class="passwordX" 
                      type="text" 
                      placeholder="Concern Person Name" 
                      ng-model="app_name" 
                      ng-init="app_name = setting.app_name"
                      style="border-width:0px;border-bottom-width:1px;height:34px"
                      >
                  </div>
                  <div class="form-group">
                    <label>Email *</label>
                    <input 
                      class="passwordX" 
                      type="text"  
                      ng-model="email" 
                      ng-init="email = setting.email"
                      style="border-width:0px;border-bottom-width:1px;height:34px"
                    >
                  </div>
                  <div class="form-group">
                    <label>Phone *</label>
                    <input 
                      class="passwordX" 
                      type="text" 
                      ng-model="phone" 
                      ng-init="phone = setting.phone"
                      style="border-width:0px;border-bottom-width:1px;height:34px"
                      >
                  </div>
                  <div class="form-group">
                    <label>Postal Address *</label>
                    <input 
                      class="passwordX" 
                      type="text" 
                      ng-model="postal_address" 
                      ng-init="postal_address = setting.postal_address"
                      style="border-width:0px;border-bottom-width:1px;height:34px"
                      >
                  </div>
                  <div class="form-group">
                    <label>TIN *</label>
                    <input 
                      class="passwordX" 
                      type="text" 
                      ng-model="tin" 
                      ng-init="tin = setting.tin"
                      style="border-width:0px;border-bottom-width:1px;height:34px"
                      >
                  </div>
                  <div class="form-group">
                    <label>VRN *</label>
                    <input 
                      class="passwordX" 
                      type="text" 
                      ng-model="vrn" 
                      ng-init="vrn = setting.vrn"
                      style="border-width:0px;border-bottom-width:1px;height:34px"
                      >
                  </div>
                  <div class="form-group">
                    <label>UIN *</label>
                    <input 
                      class="passwordX" 
                      type="text" 
                      ng-model="uin" 
                      ng-init="uin = setting.uin"
                      style="border-width:0px;border-bottom-width:1px;height:34px"
                      >
                  </div>
                  <div class="form-group">
                    <label>ZNo*</label>
                    <input 
                      class="passwordX" 
                      type="text" 
                      ng-model="zno" 
                      ng-init="zno = setting.zno"
                      style="border-width:0px;border-bottom-width:1px;height:34px"
                      >
                  </div>
                  <div class="form-group">
                    <label>Currency Symbol *</label>
                    <input 
                     class="passwordX" 
                     type="text" 
                     ng-model="currency_symbol" 
                     ng-init="currency_symbol = setting.currency_symbol"
                     style="border-width:0px;border-bottom-width:1px;height:34px"
                     >
                  </div>
                   <div class="form-group">
                    <label>local tax percentage *</label>
                    <input 
                     class="passwordX" 
                     type="text" 
                     ng-model="vat_percentage" 
                     ng-init="vat_percentage = setting.vat_percentage"
                     style="border-width:0px;border-bottom-width:1px;height:34px"
                     >
                  </div>
                  <div class="form-group">
                    <label>Location *</label>
                    <input 
                     class="passwordX" 
                     type="text" 
                     placeholder="”e.g. Mikochen, Coca cola road”" 
                     ng-model='location' 
                     ng-init="location= setting.location"
                     style="border-width:0px;border-bottom-width:1px;height:34px"
                     >
                  </div>
                  <div class="form-group">
                      <label>Logo Url</label>
                    <input 
                      type="passwordX" 
                      placeholder=""  
                      ng-model="url" 
                      class='form-control' 
                      style="border-width:0px;border-bottom-width:1px;height:34px"
                      >
                  </div>
                  <div class="col-md-6 col-sm-6">
                      <label>Browse Logo File</label>
                      <input  type="file"   fileread="logo" ng-click="src = ''">
                      <img src="{{ src }}{{logo}}" width="100" height="50" alt="">
                  </div>

                </div><!-- /.box-body -->
                <div class="box-footer">
                  <div class="pull-right">
                    <!-- <button class="btn btn-default"><i class="fa fa-pencil"></i> Draft</button> -->
                    <button type="button" class="btn btn-primary" ng-click="updateSettingEventListener(app_name,email,phone,location,currency_symbol,logo,url,vat_percentage,postal_address,tin,vrn,uin,zno)" > Save</button>
                  </div>
                  <!-- <button class="btn btn-default"><i class="fa fa-times"></i> Discard</button> -->
                </div><!-- /.box-footer -->
              </div><!-- /. box -->
            </div><!-- /.col -->
          </div><!-- /.row -->
        </section><!-- /.content -->

