<!--INNER BANNER START-->
  <section id="inner-banner">
    <div class="container">
      <h1>Distributors</h1>
    </div>
  </section>
<!--INNER BANNER END--> 
&nbsp;

<ul class="nav nav-tabs">
  <li class="active" data-toggle="tab" href="#home" style="cursor:pointer"><a>List</a></li>
  <li><a href="#/directors/create" class="btn btn-primary btn-block margin-bottom">create distributor</a></li>
 
</ul>

<div class="tab-content">
  <div id="home" class="tab-pane fade in active">
    <h3>

      <input type="text" class="form-control" style="width:200px;height:43px" placeholder="search" ng-model="search">
                 
    </h3>
    <p>
      <div class="list-group">
        <a href="" class="list-group-item" ng-repeat='director in directors | filter:search'>
          <p class="list-group-item-text">
            <span contenteditable="true" ng-model="name" ng-init="name=director.name" my-enter="updateDirectorEventListener(director,name)"> {{ director.name }}</span>   
            <button class="btn btn-default btn-sm pull-right" data-toggle="modal" data-target="#deleteDirector" ng-click="deleteDirectorEventListener(director)">X
            </button>
          </p>
        </a>
      </div>

    </p>
  </div>
  <div id="menu1" class="tab-pane fade">
    <h3>Menu 1</h3>
    <p>Some content in menu 1.</p>
  </div>
</div>

<div ng-include="'resources/views/partials/directors/delete.blade.php'"></div>