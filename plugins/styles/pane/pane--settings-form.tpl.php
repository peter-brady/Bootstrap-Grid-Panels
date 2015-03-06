<div class="row">
  <div class="col-sm-12">
    <div class="panel panel-default">
      <div class="panel-heading">
        <h3 class="panel-title"><?php print render($form['use_columns']) ?></h3>
      </div>
      <div class="panel-body">
        <?php print render($form['columns']) ?> 
      </div>
    </div>
  </div>
</div>

<div class="row">
  <div class="col-sm-12">
    <div class="panel panel-default">
      <div class="panel-heading">
        <h3 class="panel-title"><?php print render($form['use_offset']) ?></h3>
      </div>
      <?php print render($form['offset']) ?> 
    </div>
  </div>
</div>

<div class="row">
  <div class="col-sm-12">
    <div class="panel panel-default">
      <div class="panel-heading">
        <h3 class="panel-title"><?php print render($form['use_push']) ?></h3>
      </div>
      <?php print render($form['push']) ?> 
    </div>
  </div>
</div>

<div class="row">
  <div class="col-sm-12">
    <div class="panel panel-default">
      <div class="panel-heading">
        <h3 class="panel-title"><?php print render($form['use_pull']) ?></h3>
      </div>
      <?php print render($form['pull']) ?> 
    </div>
  </div>
</div>

<div class="row">
  <div class="col-sm-12">
    <div class="panel panel-default">
      <div class="panel-heading">
        <h3 class="panel-title"><?php print render($form['use_visibility']) ?></h3>
      </div>
      <?php print render($form['visibility']) ?> 
    </div>
  </div>
</div>

<?php print drupal_render_children($form) ?> 