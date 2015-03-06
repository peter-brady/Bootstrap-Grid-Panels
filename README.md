# Drupal Bootstrap Grid Panels

Enables Bootstrap 3 column classes to be added to regions and panes in Panels.

Supports:
 - col-xs-\*, col-sm-\*, col-md-\*, col-lg-\*
 - col-xs-offset-\*, col-md-offset-\*, col-md-offset-\*, col-lg-offset-\*
 - col-xs-push-\*, col-md-push-\*, col-md-push-\*, col-lg-push-\*
 - col-xs-pull-\*, col-md-pull-\*, col-md-pull-\*, col-lg-pull-\*
 - hidden-xs, hidden-sm, hidden-md, hidden-lg
 
## Columns

## Using Offset

Move this pane to the right using .col-(xs/sm/md/lg)-offset-\* classes.

These classes increase the left margin of a pane by \* columns. For example, .col-md-offset-4 will move the pane right by four columns on the medium and large breakpoints.

Note:

- Offsets **inherit up to larger breakpoints** unless you specify otherwise.
- An **offset will push panes** that follow it in the same section over to the right also.
- If you need to **push this pane to the right** and pull **another pane in the same section to the left** for a certain breakpoint, **use Push and Pull** instead.

See the [Bootstrap documentation](http://getbootstrap.com/css/#grid-offsetting) on *Offset* for more information.

## Using Push

Move this pane to the right using the css property: left:

This class increase the left css propery of a pane by \* columns. For example, .col-md-push-4 will move this pane right by four columns on the medium and large breakpoints.

Note:

- Push **inherits up to larger breakpoints** unless you specify otherwise.
- A **push will not push panes** that follow it in the same section.

See the [Bootstrap documentation](http://getbootstrap.com/css/#grid-column-ordering) on **Push** for more information.

## Using Pull

Move this pane to the left using the css property: right:

This class increase the right css propery of a pane by \* columns. For example, .col-md-pull-4 will move this pane left by four columns on the medium and large breakpoints.

Note:

- Pull **inherits up to larger breakpoints** unless you specify otherwise.
- A pull **will not pull panes** that follow it in the same section.

See the [Bootstrap documentation](http://getbootstrap.com/css/#grid-column-ordering) on **Pull**  for more information.

## Using Visibility

Although this functionality should be used sparingly, you can **hide a pane** on individual breakpoints.

The Bootstrap term for this functionality is **Responsive Utilities**.

Note: Visibility classes do not inherit up. If you set a pane to be hidden on the xs breakpoint for example, it will still appear on the other breakpoints. And vice-versa.

See the [Bootstrap documentation](http://getbootstrap.com/css/#responsive-utilities) on  **Responsive Utilities** for more information.

![pane-style-settings-1](https://cloud.githubusercontent.com/assets/2240510/6538025/83c6e0c6-c454-11e4-83a7-f11417465d52.png)


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

- Ensure you have [cTools and Page Manager](http://drupal.org/project/ctools) and [Panels](https://www.drupal.org/project/panels) contrib modules enabled
- Clone this repository into your modules directory
- Enable the **Bootstrap Grid Panels** module

## Usage

TODO: Write usage instructions and add screenshots.


## License

TODO: Write license
