<!DOCTYPE html>
<html>
<link href="https://cdn.datatables.net/autofill/2.1.3/css/autoFill.dataTables.min.css" rel="stylesheet">
<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
<link href="https://cdn.datatables.net/1.10.13/css/jquery.dataTables.min.css" rel="stylesheet">



<head>
    <title></title>
</head>
<body>

<a href="{{ url('/testing') }}">Dashboard</a>
<a href="{{ url('/testing') }}">Reports</a>
<a href="http://localhost:8097/cinema-vr-2/public/index.php#/consessions">Consession</a>
<a href="http://localhost:8097/cinema-vr-2/public/index.php#/movies">Movies</a>
<a href="http://localhost:8097/cinema-vr-2/public/index.php#/directors">Distributors</a>
<a href="http://localhost:8097/cinema-vr-2/public/index.php#/seats/booked">Booked seats</a>
<a href="http://localhost:8097/cinema-vr-2/public/index.php#/screens">Screens</a>



<table id="example" class="display" width="100%" cellspacing="0">
        <thead>
            <tr>
                <th>Show Date</th>
                <th>Distributor</th>
                <th>Movie Name</th>
                <th>Show Time</th>
                <th>No Of Tkts</th>
                <th>Price/Tkt</th>
                <th>Amt(Incl Tax)</th>
                <th>Tax</th>
                <th>WHT</th>
                <th>Discount</th>
                <th>Net Amt</th>
                <th>Dist%</th>
                <th>Dist Comm</th>
                <th>F/A</th>



            </tr>
        </thead>
        <tfoot>
            <tr>
                <th>Total</th>
                <th></th>
                <th></th>
                <th></th>
                <th></th>
                <th></th>
                <th></th>
                <th></th>
                <th></th>
                <th></th>
                <th></th>
                <th></th>
                <th></th>
                <th></th>


            </tr>
        </tfoot>
        <tbody>

        @foreach($reports as $report)
            <tr>
                <td>{{ $report->date }}</td>
                <td>{{ $report->distributor }}</td>
                <td>{{ $report->name }}</td>
                <td>{{ $report->starting_at}}</td>
                <td>{{ $report->seatNo }}</td>
                <td>{{ $report->figure }}</td>
                <td>
                <?php
                    $amt = $report->seatNo*$report->figure;
                    echo $amt;
                ?>


                </td>
                 @foreach($setting as $settings)
                <td>
                <?php
                    $amt = $report->seatNo*$report->figure;

                    $tax = $amt*($settings->vat_percentage)/100;
                    echo $tax;
                ?>

                </td>
                @endforeach
                <td>{{ $report->with_draw_tax }}</td>
                <td>
                    @if($report->discount_amount == 0)
                            -
                    @else

                        {{ $report->discount_amount }}
                    @endif
                </td>
                <td>
                <?php

                    $netAmount = $amt - $tax;
                    echo $netAmount;

                ?>
                </td>

                <td>{{ $report->distributor_percentage }}</td>
                <td>
                <?php

                    $distCommission = $netAmount*($report->distributor_percentage)/100;
                    echo floor($distCommission);
                ?>
                </td>
                <td>
                <?php

                    $fa = $report->seatNo*($report->final_amount);
                    echo floor($fa);
                ?>
                </td>



            </tr>
      @endforeach
        </tbody>
    </table>
</body>

<script src="https://code.jquery.com/jquery-3.1.1.min.js"
        integrity="sha256-hVVnYaiADRTO2PzUGmuLJr8BLUSjGIZsDYGmIJLv2b8="
        crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
<script src="https://cdn.datatables.net/1.10.13/js/jquery.dataTables.min.js"></script>
<script src="https://cdn.datatables.net/plug-ins/1.10.13/api/sum().js"></script>

<script src="https://cdn.datatables.net/buttons/1.2.3/js/dataTables.buttons.min.js"></script>
<script src="https://cdn.datatables.net/buttons/1.2.3/js/buttons.flash.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jszip/2.5.0/jszip.min.js"></script>
<script src="https://cdn.rawgit.com/bpampuch/pdfmake/0.1.18/build/pdfmake.min.js"></script>
<script src="https://cdn.rawgit.com/bpampuch/pdfmake/0.1.18/build/vfs_fonts.js"></script>
<script src="https://cdn.datatables.net/buttons/1.2.3/js/buttons.html5.min.js"></script>
<script src="https://cdn.datatables.net/buttons/1.2.3/js/buttons.print.min.js"></script>
<script src="https://cdn.datatables.net/autofill/2.1.3/js/dataTables.autoFill.min.js"></script>


<script type="text/javascript">


$(document).ready(function() {

    $('#example').DataTable({

        dom: 'Bfrtip',
        buttons: [
        'copy', 'csv', 'excel', 'pdf', 'print'],

            "footerCallback": function ( row, data, start, end, display ) {
            var api = this.api(), data;

            // Remove the formatting to get integer data for summation
            var intVal = function ( i ) {
                return typeof i === 'string' ?
                    i.replace(/[\$,]/g, '')*1 :
                    typeof i === 'number' ?
                        i : 0;
            };

            // Total over all pages
            totalTks = api
                .column( 4 )
                .data()
                .reduce( function (a, b) {
                    return intVal(a) + intVal(b);
                }, 0 );

            // Total over this page
            pageTotalTks = api
                .column( 4, { page: 'current'} )
                .data()
                .reduce( function (a, b) {
                    return intVal(a) + intVal(b);
                }, 0 );

            // Update footer
            $( api.column( 4 ).footer() ).html(
                pageTotalTks
            );

             // Total over all pages
            totalAmt = api
                .column( 6 )
                .data()
                .reduce( function (a, b) {
                    return intVal(a) + intVal(b);
                }, 0 );


             // Total over this page
            pageTotalAmt = api
                .column( 6, { page: 'current'} )
                .data()
                .reduce( function (a, b) {
                    return intVal(a) + intVal(b);
                }, 0 );

                 // Update footer
            $( api.column( 6 ).footer() ).html(
                pageTotalAmt
            );

              // Total over all pages
            totalTax = api
                .column( 7 )
                .data()
                .reduce( function (a, b) {
                    return intVal(a) + intVal(b);
                }, 0 );


             // Total over this page
            pageTotalTax = api
                .column( 7, { page: 'current'} )
                .data()
                .reduce( function (a, b) {
                    return intVal(a) + intVal(b);
                }, 0 );

                 // Update footer
            $( api.column( 7 ).footer() ).html(
                pageTotalTax
            );


              // Total over all pages
            totalNet = api
                .column( 10 )
                .data()
                .reduce( function (a, b) {
                    return intVal(a) + intVal(b);
                }, 0 );


             // Total over this page
            pageTotalNet = api
                .column( 10, { page: 'current'} )
                .data()
                .reduce( function (a, b) {
                    return intVal(a) + intVal(b);
                }, 0 );

                 // Update footer
            $( api.column( 10 ).footer() ).html(
                pageTotalNet
            );


              // Total over all pages
            totalDisCom = api
                .column( 12 )
                .data()
                .reduce( function (a, b) {
                    return intVal(a) + intVal(b);
                }, 0 );


             // Total over this page
            pageTotalDisCom = api
                .column( 12, { page: 'current'} )
                .data()
                .reduce( function (a, b) {
                    return intVal(a) + intVal(b);
                }, 0 );

                 // Update footer
            $( api.column( 12 ).footer() ).html(
                pageTotalDisCom
            );

        }


    });


});
</script>



</html>
