<?php

// $Id: station_schedule.views_default.inc,v 1.4 2009/04/19 21:34:12 drewish Exp $

/**
 * Implementation of hook_views_default_views().
 */
function station_schedule_views_default_views() {
  $view = new view;
  $view->name = 'station_schedules';
  $view->description = 'Station Schedules';
  $view->tag = 'station';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'title' => array(
      'order' => 'ASC',
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'station_schedule' => 'station_schedule',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'status_extra' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_extra',
      'table' => 'node',
      'field' => 'status_extra',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'view station schedule content',
  ));
  $handler->override_option('title', 'Schedule listing');
  $handler->override_option('style_plugin', 'list');
  $handler->override_option('style_options', array(
    'type' => 'ul',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'station/schedules');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Schedules',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'weight' => 0,
  ));
  $views[$view->name] = $view;




  $view = new view;
  $view->name = 'station_scheduled_programs';
  $view->description = 'Scheduled programs';
  $view->tag = 'station';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Title',
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'field_station_program_genre_value' => array(
      'label' => '',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_station_program_genre_value',
      'table' => 'node_data_field_station_program_genre',
      'field' => 'field_station_program_genre_value',
      'relationship' => 'none',
    ),
    'field_station_program_dj_uid' => array(
      'label' => '',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => 1,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => 0,
      ),
      'exclude' => 0,
      'id' => 'field_station_program_dj_uid',
      'table' => 'node_data_field_station_program_dj',
      'field' => 'field_station_program_dj_uid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'title' => array(
      'order' => 'ASC',
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'station_program' => 'station_program',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'status_extra' => array(
      'id' => 'status_extra',
      'table' => 'node',
      'field' => 'status_extra',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'view station program content',
  ));
  $handler->override_option('title', 'Scheduled programs');
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'station/programs/schedule');
  $handler->override_option('menu', array(
    'type' => 'default tab',
    'title' => 'Scheduled',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'normal',
    'title' => 'Programs',
    'weight' => '0',
  ));
  $views[$view->name] = $view;



  $view = new view;
  $view->name = 'station_schedule_items';
  $view->description = 'Station schedule items';
  $view->tag = 'station';
  $view->view_php = '';
  $view->base_table = 'station_schedule_item';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'program_nid' => array(
      'label' => 'Program',
      'required' => 0,
      'id' => 'program_nid',
      'table' => 'station_schedule_item',
      'field' => 'program_nid',
      'relationship' => 'none',
    ),
    'schedule_nid' => array(
      'label' => 'Schedule',
      'required' => 0,
      'id' => 'schedule_nid',
      'table' => 'station_schedule_item',
      'field' => 'schedule_nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'start' => array(
      'label' => 'Time',
      'style' => 'station_hour_range',
      'exclude' => 0,
      'id' => 'start',
      'table' => 'station_schedule_item',
      'field' => 'start',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => 'Program',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'program_nid',
    ),
    'field_station_program_genre_value' => array(
      'label' => 'Genre',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_station_program_genre_value',
      'table' => 'node_data_field_station_program_genre',
      'field' => 'field_station_program_genre_value',
      'relationship' => 'program_nid',
    ),
    'field_station_program_dj_uid' => array(
      'label' => 'DJs',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => 1,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => 0,
      ),
      'exclude' => 0,
      'id' => 'field_station_program_dj_uid',
      'table' => 'node_data_field_station_program_dj',
      'field' => 'field_station_program_dj_uid',
      'relationship' => 'program_nid',
    ),
  ));
  $handler->override_option('sorts', array(
    'start' => array(
      'order' => 'ASC',
      'id' => 'start',
      'table' => 'station_schedule_item',
      'field' => 'start',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'node',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'schedule_nid',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '30',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'poll' => 0,
        'audio' => 0,
        'image' => 0,
        'station_album' => 0,
        'station_program' => 0,
        'station_schedule' => 0,
        'book' => 0,
        'job' => 0,
        'page' => 0,
        'story' => 0,
        'video' => 0,
      ),
      'validate_argument_node_access' => 1,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '1' => 0,
        '2' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'iid' => 'iid',
      'title' => 'title',
    ),
    'info' => array(
      'iid' => array(
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $views[$view->name] = $view;



  $view = new view;
  $view->name = 'station_schedule_day';
  $view->description = 'Station Schedule\'s day view';
  $view->tag = 'station';
  $view->view_php = '';
  $view->base_table = 'station_schedule_item';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'program_nid' => array(
      'label' => 'Program',
      'required' => 0,
      'id' => 'program_nid',
      'table' => 'station_schedule_item',
      'field' => 'program_nid',
      'relationship' => 'none',
    ),
    'schedule_nid' => array(
      'label' => 'Schedule',
      'required' => 0,
      'id' => 'schedule_nid',
      'table' => 'station_schedule_item',
      'field' => 'schedule_nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'start' => array(
      'label' => 'Time',
      'style' => 'station_hour',
      'exclude' => 0,
      'id' => 'start',
      'table' => 'station_schedule_item',
      'field' => 'start',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => 'Program',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'program_nid',
    ),
    'field_station_program_genre_value' => array(
      'label' => 'Genre',
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_station_program_genre_value',
      'table' => 'node_data_field_station_program_genre',
      'field' => 'field_station_program_genre_value',
      'relationship' => 'program_nid',
    ),
    'field_station_program_dj_uid' => array(
      'label' => 'DJs',
      'link_to_node' => 1,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => 1,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => 0,
      ),
      'exclude' => 0,
      'id' => 'field_station_program_dj_uid',
      'table' => 'node_data_field_station_program_dj',
      'field' => 'field_station_program_dj_uid',
      'relationship' => 'program_nid',
    ),
  ));
  $handler->override_option('sorts', array(
    'start' => array(
      'order' => 'ASC',
      'id' => 'start',
      'table' => 'station_schedule_item',
      'field' => 'start',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'node',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'schedule_nid',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'station_schedule' => 'station_schedule',
        'blog' => 0,
        'poll' => 0,
        'audio' => 0,
        'image' => 0,
        'station_album' => 0,
        'station_playlist' => 0,
        'station_program' => 0,
        'book' => 0,
        'location' => 0,
        'page' => 0,
        'story' => 0,
        'video' => 0,
      ),
      'validate_argument_node_access' => 1,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '1' => 0,
        '2' => 0,
      ),
      'validate_argument_type' => 'tid',
      'image_size' => array(
        '_original' => '_original',
        'thumbnail' => 'thumbnail',
        'preview' => 'preview',
      ),
      'validate_argument_php' => '',
    ),
    'start_3' => array(
      'default_action' => 'empty',
      'style_plugin' => 'default_summary',
      'style_options' => array(
        'count' => 1,
        'override' => 0,
        'items_per_page' => '25',
      ),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'id' => 'start_3',
      'table' => 'station_schedule_item',
      'field' => 'start',
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'poll' => 0,
        'audio' => 0,
        'image' => 0,
        'station_album' => 0,
        'station_playlist' => 0,
        'station_program' => 0,
        'station_schedule' => 0,
        'book' => 0,
        'location' => 0,
        'page' => 0,
        'story' => 0,
        'video' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '1' => 0,
        '2' => 0,
      ),
      'validate_argument_type' => 'tid',
      'image_size' => array(
        '_original' => '_original',
        'thumbnail' => 'thumbnail',
        'preview' => 'preview',
      ),
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'status_extra' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_extra',
      'table' => 'node',
      'field' => 'status_extra',
      'relationship' => 'program_nid',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'view schedule content',
  ));
  $handler->override_option('empty', 'There are no programs scheduled for this day.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'start' => 'start',
    ),
    'info' => array(
      'start' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $views[$view->name] = $view;



  return $views;
}