<section id="inner-banner">
    <div class="container">
      <h1>Booked Seats</h1>
    </div>
</section>
<!--INNER BANNER END--> 
 <!-- Content Header (Page header) -->
<!-- <section class="content-header">
  <h1>
    {{ flagNote }} 
    <small>{{ timer }}</small>
  </h1>
  <ol class="breadcrumb">
    <li><a href="#/"><i class="fa fa-dashboard"></i> Home</a></li>
    <li class="activeX">seat</li>
  </ol>
</section> -->

<!-- Main content -->
<section class="content">
  <div class="row">
    <div class="col-md-12">
      &nbsp;
      <!-- iCheck -->
      <div class="box box-primary">
        <div class="box-header">
          <h3 class="box-title"> </h3>
        </div>
        <div class="box-body">
          <!-- Minimal style -->
          <table  class="table table-bordered table-hover" style="font: 400 14px/22px 'Roboto', sans-serif;color:#888">
            <thead>
              <tr>
                <th>Date</th>
                <th># movie name</th>
                <th>Time</th>
                <th>Seat #</th>
                <th>Price(incl Tax) </th>
                <th>local tax amount </th>
                <th>WHT </th>
                <th>discount </th>
                <th>net </th>
                <th>Distributor </th>
                <th>Dst % </th>
                <th>Dst comm </th>
                <th>F/A </th>
                <th><span class='pull-right'>Action</span></th>
              </tr>
            </thead>
            <tbody>
              <tr ng-repeat="sale in bookedSeats" >
                <td> {{ sale.date.date }} </td>
                <td> {{ sale.movie.name }} </td>
                <td> {{ sale.timer.starting_at }} </td>
                <td> {{ sale.row.code }} {{ sale.seat.number }} </td>
                <td> {{ sale.price.figure | number }} </td>
                <td> {{ sale.vat_amount }} </td>
                <td> {{ sale.with_draw_tax }} </td>
                <td> {{ sale.discount_amount }} </td>
                <td> {{ sale.net }} </td>
                <td> {{ sale.distributor }} </td>
                <td> {{ sale.distributor_percentage }} </td>
                <td> {{ sale.distributor_commission | number }} </td>
                <td> {{ sale.final_amount | number:3 }} </td>
                <td>
                  <a class="btn btn-primary btn-xs pull-right" ng-click="unBookEventListener(sale)"> un-booked </a>
                  <a class="btn btn-primary btn-xs pull-right" ng-click="confirmBookEventListener(sale)"> confirm </a>
                  </td>
              </tr>
            </tbody>
          </table>

         
        </div><!-- /.box-body -->
        <div class="box-footer">
         
        </div>
      </div><!-- /.box -->
    </div><!-- /.col (right) -->
  </div><!-- /.row -->

</section><!-- /.content -->


