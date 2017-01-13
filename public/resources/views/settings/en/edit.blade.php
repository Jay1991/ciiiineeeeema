<section class="content-header" style='padding-left:0px'>
          <h1 style="font-family:ubuntu condensedX;color:#888;">
             Config 
          </h1>
          <ol class="breadcrumb">
            <li><a href="#/"><i class="glyphicon glyphicon-home"></i>Home</a></li>
            <li class="active">config</li>
          </ol>
</section>
<br>
<div class='box box-danger' style='padding:0px'>
<div class='box-header' style='padding:2px'></div>
<div class="box-body" style='padding:0px;padding-left:2px'>
<div class='row col-sm-12' ng-controller='SettingCtrl' style='padding:0px'>
    <div class='col-md-3'>
	    <div class="panel-group">
		  <div class="panel panel-primary">
		    <div class="panel-heading"><b><!-- {{ trans('setting.companyInfo') }} -->Company Info</b></div>
		    <div class="panel-body">
		    	<div class="form-group">
                        <label for="logo"><!-- {{ trans('setting.logo') }} --> logo</label>
                        <input type="file" name='company_logo', id="avatar", value='null' custom-on-change='uploadFile' id="avatar">
                        <img src="/images/settings/{{ $tutapos_settings->company_logo_path }}" alt="" name='default_img' id="default_img" class='img-thumbnail' style="width:100px;height:auto" />
						<img src="/images/items/@{{ avatar }}" alt="" id='img' name='img' style="width:100px;height:auto" class='img-thumbnail' />
						
                </div>
                <div class="form-group">
                        <label for="logo"><!-- {{ trans('setting.name') }} --> Name</label>
                        <!-- {!! Form::text('company_name', old('company_name'), array('class'=>'form-control')) !!}  -->
                        <input type="text" class="form-control" ng-model="app_name">
                </div>
                <div class="form-group">
                        <label for="logo"><!-- {{ trans('setting.website') }} --> Website Url</label>
                        <!-- {!! Form::text('website', old('website'), array('class'=>'form-control')) !!}  -->
                        <input type="text" class="form-control" ng-model="website">

                </div>
		    </div>
		  </div>
	    </div>
    </div>
    <div class='col-md-3' >
	    <div class="row panel-group">
		  <div class="panel panel-primary">
		    <div class="panel-heading">  <b><!-- {{ trans('setting.tax_config')}} --> Tax config</b>  </div>
		    <div class="panel-body">
		        <!-- <div class="form-group">
		          <label>Price Include Tax 
		            <span>  </span>
		          </label>
		        </div> -->
		    	<div class="form-group">
                      <label> 
                       Price Include Tax <!-- {{ trans('setting.tax' )}} --> 
                      </label>
                       <span class="pull-right"><input type='checkbox' name='price_includes_tax' checked="true"></span>

                </div>
                <div class="form-group">
                      <!-- {{ trans('setting.vat') }} --> <label>Local Tax (VAT) </label>
	                  <div class="input-group">
	                      <span class="input-group-addon"> % </span>
	                      <!-- {!! Form::text('vat_percentage',null, array('class'=>'form-control', 'placeholder'=>'percent', 'style'=>'')) !!} -->
                         <input type="text" class="form-control" ng-model="vat_percentage" placeholder="">
	                      
	                  </div>
	                  <!-- <br />
	                  <div class="input-group">
	                      <span class="input-group-addon"> $  </span>
	                      {!! Form::text('vat_amount',null, array('class'=>'form-control', 'placeholder'=>'amount','style'=>'')) !!}
                          <input type="text" class="form-control" ng-model="vat_amount" placeholder="">
	                      
	                  </div> -->

	                  <hr />

                      <!-- {{ trans('setting.discount') }}
	                  <div class="input-group">
	                      <span class="input-group-addon"> % </span>
	                      {!! Form::text('discount_limit_percentage',null, array('class'=>'form-control', 'placeholder'=>'percent', 'style'=>'')) !!}
	                  </div>
                      <br />
	                  <div class="input-group">
	                      <span class="input-group-addon"> $  </span>
	                      {!! Form::text('discount_limit_amount',null, array('class'=>'form-control', 'placeholder'=>'amount','style'=>'')) !!}
	                  </div> -->
				</div>

				<div class="form-group">
                        {{ trans('setting.currency_symbol') }}
                        {!! Form::text('currency_symbol', old('currency_symbol'), array('class'=>'form-control')) !!} 
                </div>


		    </div>
		  </div>
	    </div>
    </div>
    <div class='col-md-3'>
	    <div class="panel-group">
		  <div class="panel panel-primary">
		    <div class="panel-heading"><b><!-- {{ trans('setting.sales-config') }} --> Sales Config</b></div>
		    <div class="panel-body">
		       
                <!-- <div class="form-group">
	                <div class="checkbox">
	                      <label> 
	                            @if ($tutapos_settings->edit_item_price == 1)
	                            <input type='checkbox' name='edit_item_price' checked='true'>
	                            @else
                                <input type='checkbox' name='edit_item_price'>
	                            @endif
	                            {{ trans('setting.edit_item_price') }}
	                      </label>
	                </div> 
                </div> -->
                <div class="form-group">
                      <label> 
                       Sales Agent Edit Price <!-- {{ trans('setting.tax' )}} --> 
                      </label>
                       <span class="pull-right"><input type='checkbox' ng-model='edit_item_price'></span>

                </div>

                <div class="form-group">
                    <label>Receipt Size</label><!-- {{ trans('setting.receipt_size') }} -->
	                <!-- {!! Form::select(
														'receipt_text_size', array(
															'Small'      => 'Small', 
															'Medium'     => 'Medium', 
															'Large'      => 'Large',
															'ExtraLarge' => 'Extra Large'
														), 
														Input::old('receipt_text_size'), array('class' => 'form-control')) 
	                !!} -->
	                <select class="form-control" ng-model="receipt_size_id"></select>
                </div>

                <div class="form-group">
                      <label> Payment Type</label>
                      <select class="form-control" ng-model="payment_type_id">
                      </select>

                </div>

                
                <!-- <div class="form-group">
                    {{ trans('setting.payment_type') }}
	                {!! Form::select(
										'default_payment_type', array(
											'Cash'          => 'Cash', 
											'Check'         => 'Check', 
											'GiftCard'      => 'Gift Card',
											'DebitCard'     => 'Debit Card',
											'CreditCard'    => 'Credit Card',
											'StoreAccount'  => 'Store Account'
										), 
										Input::old('default_payment_type'), array('class' => 'form-control')) 
				    !!}
                </div> -->

                <!-- <div class="form-group">
	                <div class="checkbox">
	                      <label> 
	                      @if ($tutapos_settings->automatically_email_receipt == 1)
	                      <input type='checkbox' name='automatically_email_receipt' checked='true'>
	                      @else
	                      <input type='checkbox' name='automatically_email_receipt'>
	                      @endif
	                      {{ trans('setting.email_receipt') }}
	                      </label>
	                </div> 
                </div> -->

               
		    </div>
		  </div>
	    </div>
    </div>
    <div class='col-md-3' >
	    <div class="row panel-group">
		  <div class="panel panel-primary">
		    <div class="panel-heading"><b><!-- {{ trans('setting.app-config') }} --> Other Config</b></div>
		    <div class="panel-body">
		       <!-- {{ trans('setting.language') }}
		       {!! Form::select(
														'languange', array(
															'en' => 'English', 
															'id' => 'Indonesia', 
															'sw' => 'Swahili'
														), 
														Input::old('languange'), array('class' => 'form-control')) 
			   !!} -->

			   <div class="form-group">
			    <label>Language</label>
			    <select class="form-control" ng-model="languange_id"></select>

			   </div>

			   

                <!-- <div class="form-group">
                    {{ trans('setting.date_format') }}
	                {!! Form::select(
														'date_format', array(
															'M/d/YYYY'     => 'M/d/YYYY', 
															'yyyy-MM-dd'   => 'yyyy-MM-dd', 
															'dd-MMM-yy'    => 'dd-MMM-yy'
														), 
														Input::old('date_format'), array('class' => 'form-control')) 
					!!}

                </div> -->
                <div class="form-group">
			        <label>Date Format</label>
			        <select class="form-control" ng-model="date_format_id"></select>

			   </div>

                <!-- <div class="form-group">
                    {{ trans('setting.time_format') }}
	                {!! Form::select(
														'time_format', array(
															'h:mm tt'   => 'h:mm tt', 
															'hh:mm tt'  => 'hh:mm tt', 
															'H:mm'      => 'H:mm',
															'HH:mm'     => 'HH:mm'
														), 
														Input::old('time_format'), array('class' => 'form-control')) 
			        !!}

                </div> -->

                <div class="form-group">
			        <label>Time Format</label>
			        <select class="form-control" ng-model="time_format_id"></select>

			    </div>

                <!-- <div class="form-group">
                    {{ trans('setting.spreadsheet_format') }}
	                {!! Form::select(
														'spreadsheet_format', array(
															'XLSX' => 'XLSX', 
															'CSV' => 'CSV', 
														), 
														Input::old('spreadsheet_format'), array('class' => 'form-control')) 
					!!}

                </div> -->

                <div class="form-group">
			        <label>Spreadsheet Format</label>
			        <select class="form-control" ng-model="spreadsheet_format_id"></select>

			    </div>

		    </div>
		  </div>
	    </div>
    </div>
</div>
<div style='text-align:center'>
    <input class="btn btn-primary" value="Submit" type="{{ trans('item.submit')}}" style='font-weight:80%'>
    <br>
    <br>
</div>
</div>
</div>
