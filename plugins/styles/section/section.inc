<?php

/**
 * Author: P.Brady
 */

/**
 * @file
 * 
 * Allows a Panels region to be configured to be:
 *
 * - Default container
 *  or
 * - Full-width section (likely to be used with the slideshow component)
 *
 */

// Plugin definition
$path = drupal_get_path('module', 'bootstrap_grid_panels') . '/plugins/styles/section';
$plugin = array(
  'title' => t('Section'),
  'description' => t('Create a full-width section'),
  'settings form' => 'bootstrap_panes_styles_section_style_settings_form',
  'render region' => 'bootstrap_panes_styles_section_style_render_region',
  'hook theme' => array(
    'section_default' => array(
      'template' => 'section--default',
      'path' => $path,
      'variables' => array('panes' => NULL, 'custom_classes' => 'NULL'),
    ),
    'section_full_width' => array(
      'template' => 'section--full-width',
      'path' => $path,
      'variables' => array('panes' => NULL, 'custom_classes' => 'NULL', 'bg_pane' => NULL),
    ),
    'section_default_background' => array(
      'template' => 'section--default--background',
      'path' => $path,
      'variables' => array('panes' => NULL, 'custom_classes' => 'NULL'),
    ),
    'section_full_width_background' => array(
      'template' => 'section--full-width--background',
      'path' => $path,
      'variables' => array('panes' => NULL, 'custom_classes' => 'NULL', 'bg_pane' => NULL),
    ),
  ),
);


/**
 * Panels region settings form callback.
 */
function bootstrap_panes_styles_section_style_settings_form($style_settings, $panel_display, $region) {

  $form['section_full_width'] = array(
    '#type' => 'checkbox',
    '#title' => t('Full-width section?'),
    '#default_value' => (isset($style_settings['section_full_width'])) ? $style_settings['section_full_width'] : '',
    '#description' => t('Removes the .container class from &lt;section&gt; and the inner .row. The required row and column classes are added via the component/s you add to this region.'),
  );

  // Wrap HTML output in a container so we can use 
  // Form states - https://api.drupal.org/comment/11049#comment-11049
  $form['output_section_full_width'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[section_full_width]"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  $form['output_section_full_width']['markup'] = array(
    '#markup' => '<strong>Output:</strong>
      <pre>
&lt;section&gt;                   &lt;-- Full-width section (add custom classes below)
  &lt;?php print $panes ?&gt;     &lt;-- Components as Fieldable Panels Panes
&lt;/section&gt;
      </pre>',
  );


  // Wrap HTML output in a container so we can use 
  // Form states - https://api.drupal.org/comment/11049#comment-11049
  $form['output_section_container'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[section_full_width]"]' => array('checked' => FALSE),
      ),
    ),
  );

  // PB: Not nice. Need to convert this to use Render API.
  $form['output_section_container']['markup'] = array(
    '#markup' => '<strong>Output:</strong>
      <pre>
&lt;section&gt;                       &lt;-- Full width section (add custom classes below)
  &ltdiv class=&quot;container&quot;&gt;       &lt;-- Default section container (add custom classes below)
    &lt;div class=&quot;row&quot;&gt;           &lt;-- Row to hold columns IE. Panels panes (add custom classes below)
      &lt;?php print $panes ?&gt;     &lt;-- Panels panes with responsive column settings
    &lt;/div&gt;
  &lt;/div&gt;    
&lt;/section&gt;
      </pre>',
      '#states' => array(
        'visible' => array(
          ':input[name="settings[section_full_width]"]' => array('checked' => FALSE),
        ),
      ),      
  );

  $form['classes_section'] = array(
    '#type' => 'textfield', 
    '#title' => t('Custom classes for <em>&lt;section&gt;</em>'), 
    '#description' => t('A space-separated list of classes to add to the full-width &lt;section&gt; wrapper. Use custom classes here for full-width background images or solid background colours.'),
    '#default_value' => (isset($style_settings['classes_section'])) ? $style_settings['classes_section'] : '',
    );

  $form['classes_container'] = array(
    '#type' => 'textfield', 
    '#title' => t('Custom classes for <em>div.container</em>'), 
    '#description' => t('A space-separated list of classes to add to the container.'),
    '#default_value' => (isset($style_settings['classes_container'])) ? $style_settings['classes_container'] : '',
    );

  $form['classes_row'] = array(
    '#type' => 'textfield', 
    '#title' => t('Custom classes for <em>div.row</em>'), 
    '#size' => 3,
    '#description' => t('A space-separated list of classes to add to the .row column wrapper.'),
    '#default_value' => (isset($style_settings['classes_row'])) ? $style_settings['classes_row'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[section_full_width]"]' => array('checked' => FALSE),
      ),
    ),
  );

  return $form;
}


/**
 * Render a region callback.
 */
function theme_bootstrap_panes_styles_section_style_render_region($vars) {
  
  $panes = $vars['panes'];
  if(!$panes) return;

  $panes = '';
  
  // Handle background pane logic
  // Setup initial vars
  $bg_pane = '';
  $bg_pane_id = isset($vars['settings']['use_background_pane']) ? $vars['settings']['background_pane_container']['background_pane'] : FALSE;

  // Loop through panes.s
  foreach ($vars['panes'] as $pane_id => $pane) {
    $panes .= $pane;
  }

  // Prefix a space to custom classes.
  $custom_classes = $vars['settings'];
  $custom_classes = bootstrap_panes_styles_separate_classes($custom_classes);

  // Hmm, something going on with the styles settings for regions when
  // the region styles are automatically applied.
  // Need to make sure the key exists at least to avoid undefined index warnings
  if (!isset($vars['settings']['section_full_width'])) { $vars['settings']['section_full_width'] = ''; }
  if (!isset($custom_classes['classes_section']))      { $custom_classes['classes_section'] = 'clearfix'; }
  if (!isset($custom_classes['classes_container']))    { $custom_classes['classes_container'] = ''; }
  if (!isset($custom_classes['classes_row']))          { $custom_classes['classes_row'] = ''; }

  // In case we end up with leading or trailing spaces on the <section> class
  $custom_classes['classes_section'] = trim($custom_classes['classes_section']);

  // Render the region through either
  // - section--default.tpl.php or
  // - section--full-width.tpl.php
  // based on the status of the 'full-width section' checkbox
  $section_type = $vars['settings']['section_full_width'] ? 'section_full_width' : 'section_default';
  $section_options = array('panes' => $panes, 'custom_classes' => $custom_classes);

  return theme($section_type, $section_options);
}

/**
 * Helper function to ensure custom classes are
 * space-separated.
 *
 * @param array $classes Class array to space-separate
 * @return array $classes Class array - each value is prefixed with a space
 *
 * The classes string is trimmed later so we don't need to worry about
 * the first value having a space prefixed for now.
 */
function bootstrap_panes_styles_separate_classes($classes) {

  foreach ($classes as $key => &$class) {
    if(!is_array($class) && strpos('classes', $key) !== FALSE) {
      $class != '' ? $class = ' ' . $class : $class;
    }
  }

  return $classes;
}