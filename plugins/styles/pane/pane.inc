<?php

/**
 * Author: P.Brady
 */

/**
 * @file
 * 
 * Allows a Panels pane to be configured with column widths, offsets,
 * pushes and pulls, according to the classes the Bootstrap 3 grid expects.
 *
 */

// Plugin definition
$path = drupal_get_path('module', 'bootstrap_grid_panels') . '/plugins/styles/pane';
$plugin = array(
  'title' => t('Pane'),
  'pane settings form' => 'panels_grid_styles_pane_settings_form',
  'render pane' => 'panels_grid_styles_pane_style_render_pane',
  'hook theme' => array(
    'pane_help_offset' => array(
      'template' => 'pane--help-offset',
      'path' => $path . '/help',
    ),
    'pane_help_push' => array(
      'template' => 'pane--help-push',
      'path' => $path . '/help',
    ),    
    'pane_help_pull' => array(
      'template' => 'pane--help-pull',
      'path' => $path . '/help',
    ),  
    'pane_help_visibility' => array(
      'template' => 'pane--help-visibility',
      'path' => $path . '/help',
    ),      
  ),
);


/**
 * Pane settings form callback.
 */
function panels_grid_styles_pane_settings_form($style_settings) {

  // Theme the form though pane--settings-form.tpl.php 
  $form['#theme'] = array('pane__settings_form');

  /** Columns **/
  $form['use_columns'] = array(
    '#type' => 'checkbox',
    '#title' => t('<strong>Columns</strong>'),
    '#default_value' => (isset($style_settings['use_columns'])) ? $style_settings['use_columns'] : '',
  );

  $form['columns'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[use_columns]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['columns']['xs'] = array(
    '#type' => 'select',
    '#title' => t('extra small (col-xs-*)'),
    '#prefix' => '<div class="panel-body"><div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the column width of this pane for extra small devices IE. mobile phones.'),
    '#options' => panels_grid_styles_pane_settings_options('col_xs_', $prefix = FALSE, $start = 1),
    '#default_value' => (isset($style_settings['columns']['xs'])) ? $style_settings['columns']['xs'] : 'col_xs_12',
  );

  $form['columns']['sm'] = array(
    '#type' => 'select',
    '#title' => t('small (col-sm-*)'),
    '#prefix' => '<div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the column width of this pane for <em>small</em> devices IE. mobile phones.'),
    '#options' => panels_grid_styles_pane_settings_options('col_sm_', $prefix = FALSE, $start = 1, $none = FALSE, $inherit = TRUE),
    '#default_value' => (isset($style_settings['columns']['sm'])) ? $style_settings['columns']['sm'] : 'inherit',
  );  
  
  $form['columns']['md'] = array(
    '#type' => 'select',
    '#title' => t('medium (col-md-*)'),
    '#prefix' => '<div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the column width of this pane for <em>medium</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_md_', $prefix = FALSE, $start = 1, $none = FALSE, $inherit = TRUE),
    '#default_value' => (isset($style_settings['columns']['md'])) ? $style_settings['columns']['md'] : 'inherit',
  ); 

  $form['columns']['lg'] = array(
    '#type' => 'select',
    '#title' => t('large (col-lg-*)'),
    '#prefix' => '<div class="col-sm-3">',
    '#suffix' => '</div></div>',
    '#description' => t('Set the column width of this pane for <em>large</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_lg_', $prefix = FALSE, $start = 1, $none = FALSE, $inherit = TRUE),
    '#default_value' => (isset($style_settings['columns']['lg'])) ? $style_settings['columns']['lg'] : 'inherit',
  ); 

  /** End columns **/

  /** Offsets **/

  $form['use_offset'] = array(
    '#type' => 'checkbox',
    '#title' => t('<strong>Offset</strong>'),
    '#default_value' => (isset($style_settings['use_offset'])) ? $style_settings['use_offset'] : '',
  );

  $form['offset'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[use_offset]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['offset']['show_help'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show help for the <em>\'Offset\'</em> classes?'),
    '#default_value' => 0,
    '#prefix' => '<div class="col-sm-12">',
    '#suffix' => '</div>',
  );

  $form['offset']['help'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[offset][show_help]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['offset']['help']['text'] = array(
    '#markup' => theme('pane_help_offset'),
  );

  $form['offset']['xs'] = array(
    '#type' => 'select',
    '#title' => t('Offset: extra small (col-xs-*)'),
    '#prefix' => '<div class="panel-body"><div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the column offset width of this pane for <em>extra small</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_xs_offset_', FALSE, $start = 1, $none = TRUE),
    '#default_value' => (isset($style_settings['offset']['xs'])) ? $style_settings['offset']['xs'] : 'none',
  );

  $form['offset']['sm'] = array(
    '#type' => 'select',
    '#title' => t('Offset: small (col-sm-*)'),
    '#prefix' => '<div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the column offset width of this pane for <em>small</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_sm_offset_', FALSE, $start = 0, $none = FALSE, $inherit = TRUE),
    '#default_value' => (isset($style_settings['offset']['sm'])) ? $style_settings['offset']['sm'] : 'none',
  );  
  
  $form['offset']['md'] = array(
    '#type' => 'select',
    '#title' => t('Offset: medium (col-md-*)'),
    '#prefix' => '<div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the column offset width of this pane for <em>medium</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_md_offset_', FALSE, $start = 0, $none = FALSE, $inherit = TRUE),
    '#default_value' => (isset($style_settings['offset']['md'])) ? $style_settings['offset']['md'] : 'none',
  ); 

  $form['offset']['lg'] = array(
    '#type' => 'select',
    '#title' => t('Offset: large (col-lg-*)'),
    '#prefix' => '<div class="col-sm-3">',
    '#suffix' => '</div></div>',
    '#description' => t('Set the column offset width of this pane for <em>large</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_lg_offset_', FALSE, $start = 0, $none = FALSE, $inherit = TRUE),
    '#default_value' => (isset($style_settings['offset']['lg'])) ? $style_settings['offset']['lg'] : 'none',
  ); 

  /** End Offsets **/

  /** Pushes **/

  $form['use_push'] = array(
    '#type' => 'checkbox',
    '#title' => t('<strong>Push</strong>'),
    '#default_value' => (isset($style_settings['use_push'])) ? $style_settings['use_push'] : '',
  );

  $form['push'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[use_push]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['push']['show_help'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show help for the <em>\'Push\'</em> classes?'),
    '#default_value' => 0,
    '#prefix' => '<div class="col-sm-12">',
    '#suffix' => '</div>',
  );

  $form['push']['help'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[push][show_help]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['push']['help']['text'] = array(
    '#markup' => theme('pane_help_push'),
  );

  $form['push']['xs'] = array(
    '#type' => 'select',
    '#title' => t('Push: extra small (col-xs-*)'),
    '#prefix' => '<div class="panel-body"><div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the column push of this pane for <em>extra small</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_xs_push_', FALSE, $start = 1, $none = TRUE),
    '#default_value' => (isset($style_settings['push']['xs'])) ? $style_settings['push']['xs'] : 'none',
  );

  $form['push']['sm'] = array(
    '#type' => 'select',
    '#title' => t('Push: small (col-sm-*)'),
    '#prefix' => '<div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the column push of this pane for <em>small</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_sm_push_', FALSE, $start = 0, $none = FALSE, $inherit = TRUE),
    '#default_value' => (isset($style_settings['push']['sm'])) ? $style_settings['push']['sm'] : 'none',
  );  
  
  $form['push']['md'] = array(
    '#type' => 'select',
    '#title' => t('Push: medium (col-md-*)'),
    '#prefix' => '<div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the column push of this pane for <em>medium</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_md_push_', FALSE, $start = 0, $none = FALSE, $inherit = TRUE),
    '#default_value' => (isset($style_settings['push']['md'])) ? $style_settings['push']['md'] : 'none',
  ); 

  $form['push']['lg'] = array(
    '#type' => 'select',
    '#title' => t('Push: large (col-lg-*)'),
    '#prefix' => '<div class="col-sm-3">',
    '#suffix' => '</div></div>',
    '#description' => t('Set the column push of this pane for <em>large</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_lg_push_', FALSE, $start = 0, $none = FALSE, $inherit = TRUE),
    '#default_value' => (isset($style_settings['push']['lg'])) ? $style_settings['push']['lg'] : 'none',
  ); 

  /** End Pushes **/

  /** Pulls **/

  $form['use_pull'] = array(
    '#type' => 'checkbox',
    '#title' => t('<strong>Pull</strong>'),
    '#default_value' => (isset($style_settings['use_pull'])) ? $style_settings['use_pull'] : '',
  );

  $form['pull'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[use_pull]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['pull']['show_help'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show help for the <em>\'Pull\'</em> classes?'),
    '#default_value' => 0,
    '#prefix' => '<div class="col-sm-12">',
    '#suffix' => '</div>',
  );

  $form['pull']['help'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[pull][show_help]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['pull']['help']['text'] = array(
    '#markup' => theme('pane_help_pull'),
  );

  $form['pull']['xs'] = array(
    '#type' => 'select',
    '#title' => t('Pull: extra small (col-xs-*)'),
    '#prefix' => '<div class="panel-body"><div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the column pull of this pane for <em>extra small</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_xs_pull_', FALSE, $start = 1, $none = TRUE),
    '#default_value' => (isset($style_settings['pull']['xs'])) ? $style_settings['pull']['xs'] : 'none',
  );

  $form['pull']['sm'] = array(
    '#type' => 'select',
    '#title' => t('Pull: small (col-sm-*)'),
    '#prefix' => '<div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the column pull of this pane for <em>small</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_sm_pull_', FALSE, $start = 0, $none = FALSE, $inherit = TRUE),
    '#default_value' => (isset($style_settings['pull']['sm'])) ? $style_settings['pull']['sm'] : 'none',
  );  
  
  $form['pull']['md'] = array(
    '#type' => 'select',
    '#title' => t('Pull: medium (col-md-*)'),
    '#prefix' => '<div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the column pull of this pane for <em>medium</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_md_pull_', FALSE, $start = 0, $none = FALSE, $inherit = TRUE),
    '#default_value' => (isset($style_settings['pull']['md'])) ? $style_settings['pull']['md'] : 'none',
  ); 

  $form['pull']['lg'] = array(
    '#type' => 'select',
    '#title' => t('Pull: large (col-lg-*)'),
    '#prefix' => '<div class="col-sm-3">',
    '#suffix' => '</div></div>',
    '#description' => t('Set the column pull of this pane for <em>large</em> devices IE.'),
    '#options' => panels_grid_styles_pane_settings_options('col_lg_pull_', FALSE, $start = 0, $none = FALSE, $inherit = TRUE),
    '#default_value' => (isset($style_settings['pull']['lg'])) ? $style_settings['pull']['lg'] : 'none',
  ); 

  /** End Pulls **/

  /** Visibility classes **/
  
  $form['use_visibility'] = array(
    '#type' => 'checkbox',
    '#title' => t('<strong>Visibility</strong>'),
    '#default_value' => (isset($style_settings['use_visibility'])) ? $style_settings['use_visibility'] : '',
  );

  $form['visibility'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[use_visibility]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['visibility']['show_help'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show help for the <em>\'Visibility\'</em> classes?'),
    '#default_value' => 0,
    '#prefix' => '<div class="col-sm-12">',
    '#suffix' => '</div>',
  );

  $form['visibility']['help'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="settings[visibility][show_help]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['visibility']['help']['text'] = array(
    '#markup' => theme('pane_help_visibility'),
  );

  $form['visibility']['hidden'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Hidden on?'),
    '#prefix' => '<div class="panel-body"><div class="col-sm-3">',
    '#suffix' => '</div>',
    '#description' => t('Set the breakpoints for which this pane should be <strong>hidden</strong>.'),
    '#options' => array(
      'hidden_xs' => t('xs (extra small)'),
      'hidden_sm' => t('sm (small)'),
      'hidden_md' => t('md (medium)'),
      'hidden_lg' => t('lg (large)'),
    ),
    '#default_value' => (isset($style_settings['visibility']['hidden'])) ? $style_settings['visibility']['hidden'] : 'none',
  );

  /** END Visibility classes **/

  return $form;
}



/**
 * Render callback.
 */
function theme_panels_grid_styles_pane_style_render_pane($vars) {

  $content = $vars['content'];
  $settings = $vars['settings'];
  if(!$content) return;

  // Process column classes
  $pane_classes = array();
  
  // Process columns
  if ($settings['use_columns'] == 1) {
    foreach ($settings['columns'] as $column_class) {
      if ($column_class != 'inherit') $pane_classes[] = $column_class;
    }
  }

  // Process offset classes
  if ($settings['use_offset'] == 1) {
    foreach ($settings['offset'] as $offset_class) {
      if ($offset_class != 'none' && $offset_class != 'inherit') $pane_classes[] = $offset_class;
    }
  }

  // Process push classes
  if ($settings['use_push'] == 1) {
    foreach ($settings['push'] as $push_class) {
      if ($push_class != 'none' && $push_class != 'inherit') $pane_classes[] = $push_class;
    }
  }

  // Process pull classes
  if ($settings['use_pull'] == 1) {
    foreach ($settings['pull'] as $pull_class) {
      if ($pull_class != 'none' && $pull_class != 'inherit') $pane_classes[] = $pull_class;
    }
  }

  // Process visibility classes
  // We have to check array key exists as lots of panes have been created already.
  // Nothing breaks. Just throws a tons of errors for previously saved panes as the
  // 'use_visibility' key doesn't exist until the pane is saved again.
  if (isset($settings['use_visibility']) && $settings['use_visibility'] == 1) {
    // If we have this pane hidden on all four breakpoints, dont add all
    // the hidden-* classes. Just add one .hidden-all class
    // If all breakpoints have been selected, none of the array keys will
    // be set to zero. 
    if(!in_array('0', $settings['visibility']['hidden'])) {
      $pane_classes[] = 'hidden-all';
    }
    else { // Add individual hidden-* classes
      foreach ($settings['visibility']['hidden'] as $visibility_class) {
        // Check before we add hidden classes
        // as unchecked values are set but set to zero's
        if ($visibility_class){
          $pane_classes[] = $visibility_class;
        }
      }
    }
  }

  // Prepare Form API keys for use as Bootstrap classes
  // Replace underscores with dashes
  array_walk($pane_classes, function(&$item) { $item = str_replace('_', '-', $item); });
  
  // Implode the required column classes into a string
  $vars['content']->css_class = implode(' ', $pane_classes);

  // Return the themed responsive panels pane
  return theme('panels_pane', array('content' => $vars['content'], 'pane' => $vars['pane'], 'display' => $vars['display']));
}

/**
 * Helper function.
 * 
 * Provide an $options array for the column select dropdowns.
 * Exists only to reduce the code in this file.
 */
function panels_grid_styles_pane_settings_options($prefix, $suffix = NULL, $start = 1, $none = NULL, $inherit = NULL){
  
  $options = array();
  if($inherit) $options['inherit'] = 'Inherit';
  if($none) $options['none'] = 'None';
  for ($i = $start; $i <= 12; $i++) {
    if ($i == 0) {
      $options[$prefix . $i . $suffix] = $i . ' (reset)';
    } else {
      $options[$prefix . $i . $suffix] = $i;
    }
  }
  return $options;
}