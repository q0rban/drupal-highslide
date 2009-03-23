<?php
// $Id$

/**
 * @file
 * Configuration forms
 * @todo add variables for the imagecache thumbnail and full image preset.
 */

/**
 * 
 */
function highslide_options_form() {
  $options = variable_get('highslide_options', highslide_default_options());
  $form = array();

  $form['highslide_options']['#tree'] = TRUE;
/*
  $form['highslide_options']['hideOnContentClick'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Hide on click'),
    '#description'    => t('Hides the zoomed item when clicked.'),
    '#default_value'  => $options['hideOnContentClick'],
  );

  $form['highslide_options']['overlayShow'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Overlay'),
    '#description'    => t('If checked, shows an overlay behind the zoomed content.'),
    '#default_value'  => $options['overlayShow'],
  );
*/
  $form['highslide_options']['graphicsDir'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Highslide Graphics Directory'),
    '#default_value'  => $options['graphicsDir'],
  );
  $form['highslide_options']['dimmingOpacity'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Dimming Opacity'),
    '#description'    => t('Opacity of background dimming (from 0 to 1).'),
    '#default_value'  => $options['dimmingOpacity'],
  );
  $form['highslide_options']['dimmingDuration'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Dimming Duration'),
    '#description'    => t('Duration of dimming in ms.'),
    '#default_value'  => $options['dimmingDuration'],
  );
/*
  $form['highslide_options']['zoomSpeedIn'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Zoom in speed'),
    '#description'    => t('Speed in milliseconds of the zooming-in animation. FancyBox defaults to 500 if you leave this blank.(no animation if 0)'),
    '#default_value'  => $options['zoomSpeedIn'],
  );

  $form['highslide_options']['zoomSpeedOut'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Zoom out speed'),
    '#description'    => t('Speed in milliseconds of the zooming-out animation. FancyBox defaults to 600 if you leave this blank. (no animation if 0)'),
    '#default_value'  => $options['zoomSpeedOut'],
  );
 
  $form['highslide_options']['frameWidth'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Inline content width'),
    '#description'    => t('Width in pixels of iframed and inline html content, i.e. 640.  FancyBox defaults to 600 if you leave this blank.'),
    '#default_value'  => $options['frameWidth'],
  );

  $form['highslide_options']['frameHeight'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Inline content height'),
    '#description'    => t('Height in pixels of iframed and inline html content, i.e. 480.  FancyBox defaults to 400 if you leave this blank.'),
    '#default_value'  => $options['frameHeight'],
  );
 
  $form['highslide_options']['selectors'] = array(
    '#type'           => 'textfield',
    '#title'          => t('jQuery Selector(s)'),
    '#description'    => t('Comma separated list of CSS Selectors FancyBox should affect.  A \'.highslide\' selector is already added by default.  You should only use this form if you know what you\'re doing.'),
    '#default_value'  => $options['selectors'],
  );
*/

  $form['highslide_options']['align'] = array(
    '#type' => 'radios',
    '#title' => t('Align'),
    '#default_value' => $options['align'],
    '#options' => array(
      'auto' => t('Auto'),
      'center' => t('Center'),
    ),
    '#description' => t('Position of the full image in the client.  <a href="@href" target="_blank">Click here</a> for more details.', array('@href' => 'http://highslide.com/ref/hs.align')),
  );

  $form['highslide_options']['outlineType'] = array(
    '#type' => 'select',
    '#title' => t('Outline'),
    '#default_value' => $options['outlineType'],
    '#options' => array(
      'null' => t('None'),
      'beveled' => t('Beveled'),
      'drop-shadow' => t('Drop Shadow'),
      'glossy-dark' => t('Glossy Dark'),
      'outer-glow' => t('Outer Glow'),
      'rounded-white' => t('Rounded White'),
      'rounded-black' => t('Rounded Black'),
    ),
    '#description' => t('The graphic outline to display around the expanded content.  <a href="@href" target="_blank">Click here</a> for more details.', array('@href' => 'http://highslide.com/ref/hs.outlineType')),
  );

  $form = system_settings_form($form);

  //$form['#submit'] = array('highslide_options_form_submit');

  return $form;
}

/**
 * Save the variable and call the js save function.
 *
function highslide_options_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  if ($values['op'] == t('Reset to defaults')) {
    variable_del('highslide_options');
    drupal_set_message(t('The Highslide settings have been reset to their default values.'));
  }
  else {
    variable_set('highslide_options', $values['options']);
    drupal_set_message(t('The Highslide settings have been saved.'));
  }
}
 */

/**
 *
 */
function highslide_formatter_list() {
  $header = array(t('Name'), t('Label'), t('Actions'));
  $rows = array();
  foreach (highslide_formatters() as $formatter) {
    $row = array();
    $row[] = l($formatter['name'], 'admin/settings/highslide/formatters/'. $formatter['name']);
    $row[] = $formatter['label'];
    $links = array();
    $links[] = l(t('Edit'), 'admin/settings/highslide/formatters/'. $formatter['name']);
    $links[] = l(t('Delete'), 'admin/settings/highslide/formatters/'. $formatter['name'] .'/delete');
    $row[] = implode('&nbsp;|&nbsp;', $links);
    $rows[] = $row;
  }
  $output = theme('table', $header, $rows);

  return $output;
}

function highslide_formatter_form($form_state, $op = 'add', $formatter = array()) {
  if ($op == 'edit' && empty($formatter)) {
    drupal_set_message(t('The specified formatter was not found.'), 'error');
    drupal_goto('admin/settings/highslide/formatters');
  }
  $form = array();
  $form['name'] = array(
    '#type' => 'textfield',
    '#size' => '64',
    '#title' => t('Formatter Name'),
    '#default_value' => $formatter['name'],
    '#description' => t('Please only use lowercase alphanumeric characters, and underscores (_) for names.'),
    '#required' => TRUE,
  );
  $form['label'] = array(
    '#type' => 'textfield',
    '#size' => '64',
    '#title' => t('Label'),
    '#default_value' => $formatter['label'],
    '#description' => t('The label is displayed in the styling drop downs for an imagefield.'),
    '#required' => TRUE,
  );

  $form['thumb'] = array(
    '#title' => t('Thumb preset'),
    '#type' => 'select',
    '#default_value' => $formatter['thumb'],
    '#options' => _highslide_imagecache_presets(),
    '#required' => TRUE,
  );
  $form['full'] = array(
    '#title' => t('Full preset'),
    '#type' => 'select',
    '#default_value' => $formatter['full'],
    '#options' => _highslide_imagecache_presets(),
    '#required' => TRUE,
  );

  $form['captions'] = array(
    '#title' => t('Captions'),
    '#description' => t('The caption is taken from the image description.  Check where you would like the caption to display.'),
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
  );
  $form['captions']['caption'] = array(
    '#title' => t('Display'),
    '#type' => 'checkboxes',
    '#default_value' => isset($formatter['caption']) ? $formatter['caption'] : array('full'),
    '#options' => array(
      'thumb' => t('Thumb'),
      'full' => t('Full'),
    ),
  );
  $form['captions']['caption_field'] = array(
    '#title' => t('Content field'),
    '#description' => t('Specify which CCK text field you would like to use as the contents for the caption.  The description on the image field is used by default.'),
    '#type' => 'select',
    '#default_value' => isset($formatter['caption_field']) ? $formatter['caption_field'] : array('default'),
    '#options' => _highslide_formatter_fields(),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => ($op == 'edit') ? t('Update Formatter') : t('Create New Formatter'),
  );/*

  // Display a preview image for this action. Put it below the submit button so
  // users don't have to do a bunch of scrolling.
  $preview_path = file_create_path('imagecache_sample.png');
  if (!file_exists($preview_path)) {
    // Copy of the image into the files directory so rather than generating it
    // from the original so we don't end up creating subdirectories mirroring
    // the path to the this module.
    $preview_path = drupal_get_path('module', 'imagecache_ui') .'/sample.png';
    file_copy($preview_path, 'imagecache_sample.png');
  }
  imagecache_image_flush($preview_path);
  $imagecache_path = imagecache_create_url($preset['presetname'], $preview_path) .'?'. time();
  $form['preview'] = array(
    '#type' => 'item',
    '#title' => t('Preview'),
    '#value' => l($imagecache_path, $imagecache_path) .'<br />'. l("<img src='$imagecache_path' />", $imagecache_path, array('html' => true)),
  );

  return $form;*/

  return $form;
}

function highslide_formatter_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $caption = array_keys(array_filter($values['caption']));
  $formatters = highslide_formatters();

  $formatters[$values['name']] = array(
    'name' => $values['name'],
    'label' => $values['label'],
    'full' => $values['full'],
    'thumb' => $values['thumb'],
    'caption' => $caption,
    'caption_field' => $values['caption_field'],
  );

  variable_set('highslide_formatters', $formatters);

  // Clear caches    
  if (module_exists('content')) {
    content_clear_type_cache();
  }
  drupal_rebuild_theme_registry();

  if ($values['op'] = t('Update Formatter')) {
    drupal_set_message(t('Highslide formatter %name was updated.', array('%name' => $values['label'])));
  }
  else {
    drupal_set_message(t('Highslide formatter %name was created.', array('%name' => $values['label'])));
  }

  $form_state['redirect'] = 'admin/settings/highslide/formatters';
}

function highslide_formatter_form_validate($form, &$form_state) {
  print_r($form_state);
  $values = $form_state['values'];
  // Check for duplicates
  if ($values['op'] != t('Update Formatter')) {
    foreach(highslide_formatters() as $formatter) {    
      if (in_array($values['name'], $formatter)) {
        form_set_error('name', t('The name you have chosen is already in use.'));
        break;
      }
    }
  }

  // Check for illegal characters in preset names
  if (!preg_match('/^[a-z0-9_.]+$/', $values['name'])) {
    form_set_error('name', t('Please only use lowercase alphanumeric characters and underscores (_) for names.'));
  }
}

function highslide_formatter_delete_form($form_state, $formatter = array()) {
  if (empty($formatter)) {
    drupal_set_message(t('The specified preset was not found'), 'error');
    drupal_goto('admin/build/imagecache');
  }

  $form = array();
  $form['name'] = array('#type' => 'value', '#value' => $formatter['name']);

  $question = t('Are you sure you want to delete the formatter %label?', array('%label' => $formatter['label']));
  $path = 'admin/settings/highslide/formatters';
  $descr = t('This action cannot be undone.');
  $yes = t('Delete');
  $no = t('Cancel');

  return confirm_form($form, $question, $path, $descr, $yes, $no);
}

function highslide_formatter_delete_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $formatters = highslide_formatters();
  $formatter = $formatters[$values['name']];

  unset($formatters[$values['name']]);
  variable_set('highslide_formatters', $formatters);
  drupal_set_message(t('Formatter %label (name: %name) was deleted.', array('%label' => $formatter['label'], '%name' => $formatter['name'])));

  $form_state['redirect'] = 'admin/settings/highslide/formatters';
}
/**
 *
 */
function _highslide_imagecache_presets() {
  $presets = imagecache_presets();
  $ret = array();
  foreach($presets as $preset) {
    $ret[$preset['presetname']] = $preset['presetname'];
  }
  return $ret;
}

/**
 *
 */
function _highslide_formatter_fields() {
  $fields = array('default' => 'Image Description', 'title' => 'Title', 'body' => 'Body');
  foreach (content_types() as $type) {
    foreach ($type['fields'] as $field) {
      if ($field['type'] == 'text') {
        $fields[$field['field_name']] = $field['widget']['label'] .' ('. $field['field_name'] .')';
      }
    }
  }
  return $fields;
}