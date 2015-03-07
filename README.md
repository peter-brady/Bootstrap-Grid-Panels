# Drupal Bootstrap Grid Panels

Enables Bootstrap 3 column classes to be added to regions and panes in Panels.

Supports:
 - col-xs-\*, col-sm-\*, col-md-\*, col-lg-\*
 - col-xs-offset-\*, col-md-offset-\*, col-md-offset-\*, col-lg-offset-\*
 - col-xs-push-\*, col-md-push-\*, col-md-push-\*, col-lg-push-\*
 - col-xs-pull-\*, col-md-pull-\*, col-md-pull-\*, col-lg-pull-\*
 - hidden-xs, hidden-sm, hidden-md, hidden-lg
 
## Columns

Select the column settings for a pane for the default Bootstrap breakpoints.

You may, for instance, want to set a pane to span twelve columns for extra-small devices, six columns for small devices and larger.

Not that column classes inherit up. So, if you set a pane to six colums on small, that pane will also span six columns on medium and large, as the default option is 'Inherit'.

Column settings for your breakpoints can all be completely customised, though. 

![pane-style-settings-1](https://cloud.githubusercontent.com/assets/2240510/6538025/83c6e0c6-c454-11e4-83a7-f11417465d52.png)


## Using Offset

Move this pane to the right using .col-(xs/sm/md/lg)-offset-\* classes.

These classes increase the left margin of a pane by \* columns. For example, .col-md-offset-4 will move the pane right by four columns on the medium and large breakpoints.

Note:

- Offsets **inherit up to larger breakpoints** unless you specify otherwise.
- An **offset will push panes** that follow it in the same section over to the right also.
- If you need to **push this pane to the right** and pull **another pane in the same section to the left** for a certain breakpoint, **use Push and Pull** instead.

See the [Bootstrap documentation](http://getbootstrap.com/css/#grid-offsetting) on *Offset* for more information.

![pane-style-settings-3](https://cloud.githubusercontent.com/assets/2240510/6538109/a1c72d0a-c455-11e4-8021-de2cb2428251.png)

## Using Push

Move this pane to the right using the css property: left:

This class increase the left css propery of a pane by \* columns. For example, .col-md-push-4 will move this pane right by four columns on the medium and large breakpoints.

Note:

- Push **inherits up to larger breakpoints** unless you specify otherwise.
- A **push will not push panes** that follow it in the same section.

See the [Bootstrap documentation](http://getbootstrap.com/css/#grid-column-ordering) on **Push** for more information.

![pane-style-settings-4](https://cloud.githubusercontent.com/assets/2240510/6538110/a1cd9622-c455-11e4-9ed2-1e216435df26.png)


## Using Pull

Move this pane to the left using the css property: right:

This class increase the right css propery of a pane by \* columns. For example, .col-md-pull-4 will move this pane left by four columns on the medium and large breakpoints.

Note:

- Pull **inherits up to larger breakpoints** unless you specify otherwise.
- A pull **will not pull panes** that follow it in the same section.

See the [Bootstrap documentation](http://getbootstrap.com/css/#grid-column-ordering) on **Pull**  for more information.

![pane-style-settings-5](https://cloud.githubusercontent.com/assets/2240510/6538112/a1debaf6-c455-11e4-9e0a-064c8ddeee84.png)


## Using Visibility

Although this functionality should be used sparingly, you can **hide a pane** on individual breakpoints.

The Bootstrap term for this functionality is **Responsive Utilities**.

Note: Visibility classes do not inherit up. If you set a pane to be hidden on the xs breakpoint for example, it will still appear on the other breakpoints. And vice-versa.

See the [Bootstrap documentation](http://getbootstrap.com/css/#responsive-utilities) on  **Responsive Utilities** for more information.

![pane-style-settings-2](https://cloud.githubusercontent.com/assets/2240510/6538031/9ca33d6a-c454-11e4-9bb1-13b38ec28235.png)



Default Bootstrap container:
----------------------------

By default, regions panes assume the containing region is going to be a default Bootstrap section, like so.

```
<section>                       <-- Full width section (add custom classes below)
  <div class="container">       <-- Default section container (add custom classes below)
    <div class="row">           <-- Row to hold columns IE. Panels panes (add custom classes below)
      <?php print $panes ?>     <-- Panels panes with responsive column settings
    </div>
  </div>    
</section>
```
![section-style-settings-default](https://cloud.githubusercontent.com/assets/2240510/6538008/5247ad3c-c454-11e4-9859-7a8390d836e3.png)

Full width section:
-------------------

You can choose **not to wrap** the rows in a container and a row by selecting **Full-width section** on the region style settings.

```
<section>                   <-- Full-width section (add custom classes below)
  <?php print $panes ?>     <-- Components as Fieldable Panels Panes
</section>
```
![section-style-settings-full-width](https://cloud.githubusercontent.com/assets/2240510/6538009/524c6a5c-c454-11e4-8bfb-73d88a971bce.png)


## Installation

- Ensure you have [cTools and Page Manager](http://drupal.org/project/ctools) and [Panels](https://www.drupal.org/project/panels) contrib modules enabled
- Clone this repository into your modules directory
- Enable the **Bootstrap Grid Panels** module

## Usage

This module essentially just applies the Bootstrap grid classes to your Panels panes and regions. So, your theme CSS will need the **Bootstrap Grid** and **Responsive Utilities** included.

If you use a Bootstrap sub-theme, Bootstrap Grid Panels will work nicely out of the box.

However, if you're using LESS or SASS to compile your theme stylesheets, just ensure the Bootstrap **Grid CSS** and the Bootstrap **Responsive Utitlities** CSS is available in your themes' compiled stylesheets.
