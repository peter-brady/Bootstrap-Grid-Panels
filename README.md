# Drupal Bootstrap Grid Panels

Enables Bootstrap 3 column classes to be addedto regions and panes in Panels.

Supports:
 - col-xs-*, col-sm-*, col-md-*, col-lg-*
 - col-xs-offset-*, col-md-offset-*, col-md-offset-*, col-lg-offset-*
 - col-xs-push-*, col-md-push-*, col-md-push-*, col-lg-push-*
 - col-xs-pull-*, col-md-pull-*, col-md-pull-*, col-lg-pull-*
 - hidden-xs, hidden-sm, hidden-md, hidden-lg
 
Also supports sections (regions) as Bootstrap containers or just full width sections.

Default Bootstrap container:
----------------------------
```
<section>                       <-- Full width section (add custom classes below)
  <div class="container">       <-- Default section container (add custom classes below)
    <div class="row">           <-- Row to hold columns IE. Panels panes (add custom classes below)
      <?php print $panes ?>     <-- Panels panes with responsive column settings
    </div>
  </div>    
</section>
```

Full width section:
-------------------
```
<section>                   <-- Full-width section (add custom classes below)
  <?php print $panes ?>     <-- Components as Fieldable Panels Panes
</section>
```

## Installation

- Ensure you have cTools, Page Manager and Panels contrib modules enabled
- Clone this repository into your modules directory
- Enable the **Bootstrap Grid Panels** module

## Usage

TODO: Write usage instructions


## License

TODO: Write license
