<?php
// $Id$

require_once('profiles/default/default.profile');

/**
 * Provide an installer for our specific set of 
 * modules, content types, and so on.
 * @file
 */

/**
 * Provide details about this profile.
 */
function tutturu_profile_details() {
  return array(
    'name' => 'Tutturu video site',
    'description' => 'Select this profile to install the '
      .'Tutturu media propagation website.',  
  );
}

/**
 * List the modules that should be installed.
 */
function tutturu_profile_modules() {
  return array(
    // Core Drupal, typically enabled by default:
  	'color', 'comment', 'help', 'menu', 'taxonomy', 'dblog', 
    // Core Drupal, required by our modules:
    'trigger', 'upload',
    // Our modules:
    'admin_menu', 'backup_migrate', 'content', 'content_copy', 'ffmpeg_wrapper', 
    'fieldgroup', 'filefield', 'filefield_meta', 'imagefield', 'media_mover_api', 
    'mm_auto_run', 'mm_cck', 'mm_ffmpeg',  'mm_node', 'mm_views', 'views', 
    'views_export', 'views_ui',  'admin_menu_toolbar', 'features', 'video_transcode',
  );
}

/**
 * Walk through final installation tasks
 */
function tutturu_profile_tasks(&$task, $url) {
  
  // TASK 1: profile
  // This will end by sending the user the form.
  if ($task == 'profile') {
     // This is why we required default profile.
    default_profile_tasks(&$task, $url);
 
    // Quote content type from chapter 4:
    $content['type']  = array (
  'name' => 'Video',
  'type' => 'video',
  'description' => st("A <em>video</em> is a multimedia type, is ideal for creating and displaying content that moves or jumps. Movies, video clips, footage, small mobile camera recordings are <em>video</em> entry. By default, a <em>video</em> entry is automatically transcoded to flash and featured on the site's initial home page."),
  'module' => 'node',
  'has_title' => TRUE,
  'title_label' => 'Title',
  'body_label' => 'Description',
  'has_body' => TRUE,
  'custom' => TRUE,
  'modified' => TRUE,
  'locked' => FALSE,
  'is_new' => TRUE,
  'min_word_count' => '0',
  'help' => '',
  'node_options' => 
  array (
    'status' => true,
    'promote' => true,
    'sticky' => false,
    'revision' => false,
  ),
  'upload' => '1',
  'old_type' => 'video',
  'orig_type' => '',
  'module' => 'node',
  'custom' => '1',
  'modified' => '1',
  'locked' => '0',
  'comment' => '2',
  'comment_default_mode' => '4',
  'comment_default_order' => '1',
  'comment_default_per_page' => '50',
  'comment_controls' => '3',
  'comment_anonymous' => 0,
  'comment_subject_field' => '1',
  'comment_preview' => '1',
  'comment_form_location' => '0',
);
$content['fields']  = array (
  0 => 
  array (
    'label' => 'flv',
    'field_name' => 'field_flv',
    'type' => 'filefield',
    'widget_type' => 'filefield_widget',
    'change' => 'Change basic information',
    'weight' => '31',
    'file_extensions' => 'txt, flv',
    'progress_indicator' => 'bar',
    'file_path' => '',
    'max_filesize_per_file' => '',
    'max_filesize_per_node' => '',
    'description' => '',
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'op' => 'Save field settings',
    'module' => 'filefield',
    'widget_module' => 'filefield',
    'columns' => 
    array (
      'fid' => 
      array (
        'type' => 'int',
        'not null' => false,
        'views' => true,
      ),
      'list' => 
      array (
        'type' => 'int',
        'size' => 'tiny',
        'not null' => false,
        'views' => true,
      ),
      'data' => 
      array (
        'type' => 'text',
        'serialize' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'weight' => '31',
      'parent' => '',
      'label' => 
      array (
        'format' => 'hidden',
      ),
      'teaser' => 
      array (
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  1 => 
  array (
    'label' => 'thumbnail',
    'field_name' => 'field_thumbnail',
    'type' => 'filefield',
    'widget_type' => 'imagefield_widget',
    'change' => 'Change basic information',
    'weight' => '32',
    'file_extensions' => 'png gif jpg jpeg',
    'progress_indicator' => 'bar',
    'file_path' => '',
    'max_filesize_per_file' => '',
    'max_filesize_per_node' => '',
    'max_resolution' => 0,
    'min_resolution' => 0,
    'custom_alt' => 0,
    'alt' => '',
    'custom_title' => 0,
    'title_type' => 'textfield',
    'title' => '',
    'use_default_image' => 0,
    'default_image_upload' => '',
    'default_image' => NULL,
    'description' => '',
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'op' => 'Save field settings',
    'module' => 'filefield',
    'widget_module' => 'imagefield',
    'columns' => 
    array (
      'fid' => 
      array (
        'type' => 'int',
        'not null' => false,
        'views' => true,
      ),
      'list' => 
      array (
        'type' => 'int',
        'size' => 'tiny',
        'not null' => false,
        'views' => true,
      ),
      'data' => 
      array (
        'type' => 'text',
        'serialize' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'weight' => '32',
      'parent' => '',
      'label' => 
      array (
        'format' => 'hidden',
      ),
      'teaser' => 
      array (
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
  ),
);
$content['extra']  = array (
  'title' => '-5',
  'body_field' => '0',
  'revision_information' => '20',
  'comment_settings' => '30',
  'menu' => '-2',
  'attachments' => '30',

      //'orig_type' => 'quotes',
    );
    node_type_save((object)$video_type);
    
   
    // Rebuild the menu
    menu_rebuild();
    
    // Do the form:
    $task = 'tutturu_pick_theme';
    $form = drupal_get_form('tutturu_theme_form', $url);
    return $form;
  }
  
  // TASK 2: philosopherbios_pick_theme
  // This will begin after the form submission callback
  // has been executed.
  if($task == 'tutturu_pick_theme') { 
    $form = drupal_get_form('tutturu_theme_form', $url);

    // See if the form was processed:
    if (variable_get('tutturu_theme', FALSE)) {
      // Clean up and finish.
      variable_del('tutturu_theme');
      $task = 'profile-finished';
    } 
    else { 
      return $form; // try again.
    }
  }
}

/**
 * List of custom tasks. This is a callback that 
 * the installer expects.
 */
function tutturu_profile_task_list() {
  return array(
  	'tutturu_pick_theme' => st('Choose Theme'),
  );
}

/**
 * Form for selecting a theme.
 */
function tutturu_theme_form(&$form_state, $url) {
  
  drupal_set_title('Select a Theme');
  
  $form['text'] = array(
    '#value' => 
      st('Do you want to make Yellow trumpet your default theme?'),
    '#weight' => -1, // <- We want it on top!
  );
  $form['choose_theme'] = array(
    '#type' => 'radios',
    '#title' => st('Default Theme'),
    '#default_value' => 0,
    '#options' => array(0 => st('Yellow trumpet'), 1 => st('Strange Little Town'), 2 => st('Singular'), 3 => st('Garland')),
    '#description' => st('Set the default site theme.'),
    '#weight' => 0,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
    '#weight' => 10,
  );
  $form['#action'] = $url;
  $form['#redirect'] = FALSE;

  return $form;
}

/**
 * Form submission callback.
 */
function tutturu_theme_form_submit($form, &$form_state) {
  // Save our state:
  variable_set('tutturu_theme', TRUE);
  
  if($form_state['values']['choose_theme'] == 0) {
    // Enbable Chrysalis theme
    $sql = "UPDATE {system} SET status = 1 "
      ."WHERE type = 'theme' and name = 'yellow_trumpet'";
    db_query($sql);
    
    // Initialize theme system:
    system_theme_data();
    system_initialize_theme_blocks('yellow_trumpet');
    
    // Set theme as default
    variable_set('theme_default','yellow_trumpet');
  } 
  if($form_state['values']['choose_theme'] == 1) {
    // Enbable Chrysalis theme
    $sql = "UPDATE {system} SET status = 1 "
      ."WHERE type = 'theme' and name = 'strange_little_town'";
    db_query($sql);
    
    // Initialize theme system:
    system_theme_data();
    system_initialize_theme_blocks('strange_little_town');
    
    // Set theme as default
    variable_set('theme_default','strange_little_town');
  }
  if($form_state['values']['choose_theme'] == 2) {
    // Enbable Singularis theme
    $sql = "UPDATE {system} SET status = 1 "
      ."WHERE type = 'theme' and name = 'singular'";
    db_query($sql);
    
    // Initialize theme system:
    system_theme_data();
    system_initialize_theme_blocks('singular');
    
    // Set theme as default
    variable_set('theme_default','singular');
  } 
  // Otherwise, leave it at Garland.
}