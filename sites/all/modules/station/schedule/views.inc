<?php

// $Id: views.inc,v 1.19 2008/03/25 07:11:28 drewish Exp $

/**
 * Implementation of hook_views_tables().
 */
function station_schedule_views_tables() {
  $tables['station_djs'] = array(
    'name' => 'station_djs',
    'join' => array(
      'left' => array(
        'table' => 'node',
        'field' => 'nid'
      ),
      'right' => array(
        'field' => 'nid'
      )
    ),
    'fields' => array(
      'djs' => array(
        'name' => t('Station Program: DJs'),
        'help' => t("The program's DJs."),
        'sortable' => FALSE,
        'notafield' => TRUE,
        'handler' => 'station_handler_field_schedule_djs',
      ),
    ),
  );
  $tables['station_schedule'] = array(
    'name' => 'station_schedule',
    'join' => array(
      'left' => array(
        'table' => 'node',
        'field' => 'nid'
      ),
      'right' => array(
        'field' => 'nid'
      )
    ),
    'fields' => array(
      'streams' => array(
        'name' => t('Station Schedule: Web streams'),
        'help' => t("Web stream links"),
        'sortable' => FALSE,
        'handler' => 'station_handler_field_schedule_streams',
      ),
    ),
  );
  $tables['station_schedule_item_current'] = array(
    'name' => 'station_schedule_item',
    'join' => array(
      'left' => array(
        'table' => 'station_schedule',
        'field' => 'nid',
      ),
      'right' => array(
        'field' => 'schedule_nid'
      ),
      'extra' => array(
        'start <= ***CURRENT_STATION_MINUTE***' => NULL,
        'finish > ***CURRENT_STATION_MINUTE***' => NULL,
      ),
    ),
    'fields' => array(
      'program_nid' => array(
        'name' => t('Station Schedule: Current program'),
        'help' => t("The currently schedule program."),
        'sortable' => TRUE,
        'handler' => 'station_handler_field_schedule_current_program',
        'addlfields' => array('iid', 'start', 'finish'),
      ),
    ),
  );
  $tables['station_program_schedule_node'] = array(
    'name' => 'node',
    'join' => array(
      'left' => array(
        'table' => 'station_schedule_item',
        'field' => 'schedule_nid'
      ),
      'right' => array(
        'field' => 'nid'
      )
    ),
    'fields' => array(
      'title' => array(
        'name' => t('Station Program: Schedule Title'),
        'sortable' => TRUE,
        'handler' => 'station_handler_field_program_schedule_title',
        'option' => array(
           '#type' => 'select',
           '#options' => array(
             'link' => 'As link to schedule',
             'nolink' => 'Without link'
           ),
        ),
        'addlfields' => array('nid'),
        'help' => t('Title of the schedule.'),
      ),
    ),
  );
  $tables['station_schedule_item'] = array(
    'name' => 'station_schedule_item',
    'join' => array(
      'left' => array(
        'table' => 'node',
        'field' => 'nid'
      ),
      'right' => array(
        'field' => 'program_nid'
      )
    ),
    'fields' => array(
      'start' => array(
        'name' => t('Station Program: Single scheduled time'),
        'help' => t("Single instance of the program on the schedule. Use this when you want a program displayed for each time it's scheduled."),
        'sortable' => TRUE,
        'sort_handler' => 'station_handler_field_sort_schedule_item_start',
        'handler' => 'station_handler_field_schedule_time',
        'option' => array(
          '#type' => 'select',
          '#options' => array(
            'hour' => t('Show only hours'),
            'dayhour' => t('Show days and hours'),
          ),
        ),
        'addlfields' => array('finish', 'schedule_nid'),
      ),
      'times' => array(
        'name' => t('Station Program: All scheduled times'),
        'help' => t("Summary of all the times the program is scheduled."),
        'sortable' => FALSE,
        'notafield' => TRUE,
        'handler' => 'station_handler_field_schedule_times',
      ),
      'archive_links' => array(
        'name' => t('Station Program: Archive listen and RSS links'),
        'help' => t("Links to both a page and feed for the program's archived audio."),
        'sortable' => FALSE,
        'notafield' => TRUE,
        'handler' => 'station_handler_field_listen_links',
        'option' => array(
           '#type' => 'select',
           '#options' => array(
             'icon' => t('Icon'),
             'icon_text' => t('Icon and text'),
            ),
        ),
      ),
      'archive_link_page' => array(
        'name' => t('Station Program: Archive listen link'),
        'help' => t("Link to the program's archived audio page."),
        'sortable' => FALSE,
        'notafield' => TRUE,
        'handler' => 'station_handler_field_listen_link_page',
        'option' => array(
           '#type' => 'select',
           '#options' => array(
             'icon' => t('Icon'),
             'icon_text' => t('Icon and text'),
            ),
        ),
      ),
      'archive_link_rss' => array(
        'name' => t('Station Program: Archive RSS link'),
        'help' => t("Link to the program's archived audio feed."),
        'sortable' => FALSE,
        'notafield' => TRUE,
        'handler' => 'station_handler_field_listen_link_rss',
        'option' => array(
           '#type' => 'select',
           '#options' => array(
             'icon' => t('Icon'),
             'icon_text' => t('Icon and text'),
            ),
        ),
      ),
    ),
    'filters' => array(
      'is_scheduled' => array(
        'name' => t('Station Program: Scheduled'),
        'operator' => 'views_handler_operator_yesno',
        'handler' => 'station_handler_filter_is_scheduled',
        'help' => t("Filter whether the node is on a schedule."),
      ),
      'now_playing' => array(
        'name' => t('Station Program: Now playing'),
        'cacheable' => FALSE,
        'operator' => array('IS' => t('now playing')),
        'value' => '',
        'handler' => 'station_handler_filter_now_playing',
        'help' => t("Filter down to the program that is currently being broadcast."),
      ),
    ),
    'sorts' => array(
      'start' => array(
        'name' => t('Station Program: Start time'),
        'help' => t('Sort the nodes based on their scheduled starting time.'),
        'handler' => 'station_handler_sort_schedule_item_start',
      ),
    ),
  );

  // If there's no archive, remove the archive link fields.
  if (!station_has_archive()) {
    unset($tables['station_schedule_item']['fields']['archive_links']);
    unset($tables['station_schedule_item']['fields']['archive_link_page']);
    unset($tables['station_schedule_item']['fields']['archive_link_rss']);
  }

  return $tables;
}

/**
 * Implementation of hook_views_query_substitutions().
 *
 * Substitute current time; this works with cached queries.
 */
function station_schedule_views_query_substitutions($view) {
  $timestamp = station_local_ts(time());
  $minute = station_minute_from_day_hour(date('w', $timestamp), date('G', $timestamp));
  return array('***CURRENT_STATION_MINUTE***' => $minute);
}

/**
 * Implementation of hook_views_arguments().
 */
function station_schedule_views_arguments() {
  $arguments = array(
    'station_schedule_argument_schedule_item_day' => array(
      'name' => t('Station Schedule: Day of week'),
      'handler' => 'station_schedule_argument_schedule_item_day',
      'help' => t('Limit the schedule items to a single day of the week.'),
    ),
    'station_schedule_argument_schedule_nid' => array(
      'name' => t('Station Program: Schedule NID'),
      'handler' => 'station_schedule_argument_schedule_nid',
      'help' => t('The Schedule NID argument allows you to filter programs attached to the specified schedule.'),
    ),
  );
  return $arguments;
}

function station_schedule_argument_schedule_item_day($op, &$query, $a1, $a2 = NULL) {
  $min_in_day = MINUTES_IN_DAY;

  switch($op) {
    case 'summary':
      $query->ensure_table('station_schedule_item');
      // Need to do the modulus by week to avoid having Sunday listed twice as 0 and 7.
      $fieldinfo['field'] = "CAST(station_schedule_item.start / $min_in_day AS UNSIGNED INTEGER) %% 7";
      $fieldinfo['fieldname'] = 'station_schedule_item_start_day';
      return $fieldinfo;

    case 'sort':
      $query->ensure_table('station_schedule_item');
      $first_day = 7 - variable_get('date_first_day', 0);
      if ($first_day != 0) {
        $formula = "(CAST(station_schedule_item.start / $min_in_day AS UNSIGNED INTEGER) + $first_day) %% 7";
      }
      else {
        $formula = "CAST(station_schedule_item.start / $min_in_day AS UNSIGNED INTEGER)";
      }
      $query->add_orderby(NULL, $formula, $a1, 'station_schedule_item_start_day_sort');

      break;

    case 'link':
      dvm($query);
      $day = (int) $query->station_schedule_item_start_day;
      $dayname = station_day_name($day);
      return l($dayname, $a2 .'/'. $dayname);

    case 'filter':
      $day = station_valid_day($a2);
      $start = $day * MINUTES_IN_DAY;
      $finish = $start + MINUTES_IN_DAY;
      $query->ensure_table('station_schedule_item');
      $query->add_where("station_schedule_item.finish > %d AND station_schedule_item.start < %d", $start, $finish);
      break;

    case 'title':
      return station_day_name(station_valid_day($a2));
  }
}

function station_schedule_argument_schedule_nid($op, &$query, $a1, $a2 = NULL) {
  switch($op) {
    case 'summary':
      $query->ensure_table('station_schedule_item');
      $query->ensure_table('station_program_schedule_node');
      $query->add_field('title', 'station_program_schedule_node');
      $query->add_field('schedule_nid', 'station_schedule_item');
      $query->add_where('station_schedule_item.schedule_nid IS NOT NULL');
      $fieldinfo['field'] = 'station_schedule_item.schedule_nid';
      return $fieldinfo;

    case 'sort':
      $query->ensure_table('station_schedule_item');
      $query->ensure_table('station_program_schedule_node');
      $query->add_orderby('station_program_schedule_node', 'title', $a1);
      break;

    case 'link':
      return l($query->title, $a2 .'/'. intval($query->schedule_nid));

    case 'filter':
      $query->ensure_table('station_schedule_item');
      $query->add_where('station_schedule_item.schedule_nid = %d', $a2);
      break;

    case 'title':
      $node = db_fetch_object(db_query("SELECT title FROM {node} WHERE nid=%d", $query));
      return check_plain($node->title);
  }
}

function station_handler_field_schedule_current_program($fieldinfo, $fielddata, $value, $data) {
  if (isset($data->station_schedule_item_current_program_nid)) {
    if ($program = node_load($data->station_schedule_item_current_program_nid)) {
      return l($program->title, "node/$program->nid");
    }
  }
  else {
    return check_plain(variable_get('station_block_unschedule',  t("We're on autopilot.")));
  }
}

function station_handler_field_schedule_streams($fieldinfo, $fielddata, $value, $data) {
  $streams = station_schedule_unserialize_streams($data->nid, $data->station_schedule_streams);
  return theme('station_streams', $streams);
}

function station_handler_field_schedule_time($fieldinfo, $fielddata, $value, $data) {
  if (isset($data->station_schedule_item_start) && isset($data->station_schedule_item_finish)) {
    if ($fielddata['options'] == 'hour') {
      return theme('station_hour_range', $data->station_schedule_item_start, $data->station_schedule_item_finish);
    }
    return theme('station_dayhour_range', $data->station_schedule_item_start, $data->station_schedule_item_finish);
  }
}

function station_handler_field_schedule_times($fieldinfo, $fielddata, $value, $data) {
  if ($program = node_load($data->nid)) {
    $scheduled = array();
    $schedules = station_schedule_get_list();

    if (count($schedules) == 1) {
      foreach (station_schedule_program_get_themed_times($program) as $schedule_nid => $times) {
        $scheduled[] = t('@times', array('@times' => station_anded_list($times)));
      }
    }
    else {
      foreach (station_schedule_program_get_themed_times($program) as $schedule_nid => $times) {
        $scheduled[] = t('On @title @times', array('@title' => $schedules[$schedule_nid]['title'], '@times' => station_anded_list($times)));
      }
    }
    return station_anded_list($scheduled);
  }
}

function station_handler_field_schedule_djs($fieldinfo, $fielddata, $value, $data) {
  if ($program = node_load($data->nid)) {
    return station_anded_list(station_schedule_program_get_themed_djs($program));
  }
}

function station_handler_field_listen_links($fieldinfo, $fielddata, $value, $data) {
  $output = '';
  if ($fielddata['options'] == 'icon') {
    foreach(station_schedule_archive_links($data->nid, TRUE) as $link) {
      $output .= l($link['title'], $link['href'], NULL, NULL, NULL, TRUE, TRUE) .' ';
    }
  }
  else {
    $output = theme('links', station_schedule_archive_links($data->nid, FALSE));
  }
  return $output;
}
function station_handler_field_listen_link_page($fieldinfo, $fielddata, $value, $data) {
  $links = station_schedule_archive_links($data->nid, ($fielddata['options'] == 'icon'));
  return l($links['station_archive_listen']['title'], $links['station_archive_listen']['href'], NULL, NULL, NULL, TRUE, TRUE);
}
function station_handler_field_listen_link_rss($fieldinfo, $fielddata, $value, $data) {
  $links = station_schedule_archive_links($data->nid, ($fielddata['options'] == 'icon'));
  return l($links['station_archive_rss']['title'], $links['station_archive_rss']['href'], NULL, NULL, NULL, TRUE, TRUE);
}

function station_handler_field_program_schedule_title($fieldinfo, $fielddata, $value, $data) {
  if ($fielddata['options'] == 'link') {
    return l($value, "node/$data->station_program_schedule_node_nid");
  }
  return check_plain($value);
}


function _station_schedule_item_start_sort($fieldname) {
  $start_offset = (int) MINUTES_IN_DAY * (7 - variable_get('date_first_day', 0));
  $divisor = (int) MINUTES_IN_WEEK;
  return "(({$fieldname} + {$start_offset}) %% {$divisor})"; 
}

function station_handler_field_sort_schedule_item_start($fielddata, $fieldinfo) {
  return _station_schedule_item_start_sort($fielddata['fullname']); 
}

function station_handler_sort_schedule_item_start($op, &$query, $sortinfo, $sortdata) {
  $formula = _station_schedule_item_start_sort($sortdata['field']);
  $query->add_orderby(NULL, $formula, $sortdata['sortorder'], $sortinfo['table'] . '_start_sort');
}


function station_handler_filter_is_scheduled($op, $filterdata, $filterinfo, &$query) {
  switch ($op) {
  case 'handler':
    $query->ensure_table('station_schedule_item');
    if ($filterdata['operator']) {
      $query->add_where('station_schedule_item.program_nid IS NOT NULL');
    }
    else {
      $query->add_where('station_schedule_item.program_nid IS NULL');
    }
    break;
  }
}

function station_handler_filter_now_playing($op, $filterdata, $filterinfo, &$query) {
  switch ($op) {
  case 'handler':
    $query->ensure_table('node');
    $query->add_field('nid', 'node');
    $minute = '***CURRENT_STATION_MINUTE***';
    $query->add_where('EXISTS (SELECT * FROM {station_schedule_item} WHERE {station_schedule_item}.program_nid = node.nid AND {station_schedule_item}.start <= %d AND {station_schedule_item}.finish > %d)', $minute, $minute);
    break;
  }
}
