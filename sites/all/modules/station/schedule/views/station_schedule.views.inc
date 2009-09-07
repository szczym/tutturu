<?php
// $Id: station_schedule.views.inc,v 1.5 2009/03/11 07:23:20 drewish Exp $

/**
 * Implementation of hook_views_handlers().
 */
function station_schedule_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'station_schedule') . '/views',
    ),
    'handlers' => array(
      // Field handlers
      'station_schedule_handler_field_start_time' => array(
        'parent' => 'views_handler_field',
      ),
      'station_schedule_handler_field_finish_time' => array(
        'parent' => 'views_handler_field',
      ),
      'station_schedule_handler_field_iid_link' => array(
        'parent' => 'views_handler_field',
      ),
      'station_schedule_handler_field_iid_link_edit' => array(
        'parent' => 'station_schedule_handler_field_iid_link',
      ),
      'station_schedule_handler_field_iid_link_remove' => array(
        'parent' => 'station_schedule_handler_field_iid_link',
      ),

      // Sort handlers
      'station_schedule_handler_sort_time' => array(
        'parent' => 'views_handler_sort',
      ),

      // Argument handlers
      'station_schedule_handler_argument_day' => array(
        'parent' => 'views_handler_argument',
      ),

      // Filter handlers
//      'station_schedule_handler_filter_time' => array(
//        'parent' => 'views_handler_filter_numeric',
//      ),
    ),
  );
}

/**
 * Implementation of hook_views_plugins().
 */
function station_schedule_views_plugins() {
  return array(
    'module' => 'station_schedule', // This just tells our themes are elsewhere.
//    'argument validator' => array(
//      'station_schedule_day' => array(
//        'title' => t('Validate day'),
//        'handler' => 'station_schedule_plugin_argument_validate_day',
//      ),
//    ),
  );
}

/**
 * Implementation of views_query_substitutions().
 */
function station_schedule_views_query_substitutions($view) {
  $timestamp = station_local_ts(time());
  $minute = station_minute_from_day_hour(date('w', $timestamp), date('G', $timestamp));
  return array('***CURRENT_STATION_MINUTE***' => $minute);
}

/**
 * Implementation of hook_views_data().
 */
function station_schedule_views_data() {
  // ----------------------------------------------------------------
  // Basic table information.

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['station_schedule']['table']['group']  = t('Station schedule');

  // For other base tables, explain how we join
  $data['station_schedule']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  // ----------------------------------------------------------------
  // Fields
  $data['station_schedule']['incrememnt'] = array(
    'title' => t('Scheduling increment'),
    'help' => t("The schedule's block size in minutes."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
     'filter' => array(
       'handler' => 'views_handler_filter_numeric',
       'label' => t('Number'),
       ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['station_schedule']['unscheduled_message'] = array(
    'title' => t('Unscheduled message'),
    'help' => t("Message displayed when there is no scheduled programming."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
     'filter' => array(
       'handler' => 'views_handler_filter_string',
       'label' => t('Artist'),
       ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );



  // ----------------------------------------------------------------
  // Basic table information.

  $data['station_schedule_item']['table']['group']  = t('Station schedule item');
  $data['station_schedule_item']['table']['base'] = array(
    'field' => 'iid',
    'title' => t('Station Schedule Item'),
    'help' => t("Items on the station's schedules."),
  );

  // For other base tables, explain how we join
  $data['station_schedule_item']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'program_nid',
    ),
  );

  // ----------------------------------------------------------------
  // Fields
  $data['station_schedule_item']['iid'] = array(
    'title' => t('Schedule item id'),
    'help' => t("The schedule item's id."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
     ),
  );
  $data['station_schedule_item']['link_iid'] = array(
    'field' => array(
      'title' => t('View link'),
      'help' => t('Provide a simple link to the schedule item.'),
      'handler' => 'station_schedule_handler_field_iid_link',
    ),
  );
  $data['station_schedule_item']['edit_iid'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the schedule item.'),
      'handler' => 'station_schedule_handler_field_iid_link_edit',
    ),
  );
  $data['station_schedule_item']['remove_iid'] = array(
    'field' => array(
      'title' => t('Remove link'),
      'help' => t('Provide a simple link to remove the schedule item.'),
      'handler' => 'station_schedule_handler_field_iid_link_remove',
    ),
  );
  $data['station_schedule_item']['schedule_nid'] = array(
    'title' => t('Schedule item schedule'),
    'help' => t("The schedule the time is on."),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'field' => 'schedule_nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Schedule'),
    ),
  );
  $data['station_schedule_item']['program_nid'] = array(
    'title' => t('Schedule item program'),
    'help' => t("The scheduled program."),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'field' => 'schedule_nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Program'),
    ),
  );
  $data['station_schedule_item']['start'] = array(
    'title' => t('Time'),
    'help' => t("Schedule instance start time."),
    'field' => array(
      'handler' => 'station_schedule_handler_field_start_time',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'station_schedule_handler_argument_day',
      'label' => t('Day of week'),
    ),
//    'filter' => array(
//      'handler' => 'station_schedule_handler_filter_time',
//      'label' => t('Start'),
//    ),
    'sort' => array(
      'handler' => 'station_schedule_handler_sort_time',
    ),
  );
  $data['station_schedule_item']['finish'] = array(
    'title' => t('Finish'),
    'help' => t("Schedule instance completion time."),
    'field' => array(
      'handler' => 'station_schedule_handler_field_finish_time',
      'click sortable' => TRUE,
     ),
//     'filter' => array(
//       'handler' => 'station_schedule_handler_filter_time',
//       'label' => t('Finish'),
//     ),
    'sort' => array(
      'handler' => 'station_schedule_handler_sort_time',
    ),
  );
  $data['station_schedule_item']['may_archive'] = array(
    'title' => t('May be archived'),
    'help' => t("Is this program allowed to be stored in the Station Archive."),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
     ),
     'filter' => array(
       'handler' => 'views_handler_filter_boolean_operator',
       'label' => t('Active'),
       ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}
