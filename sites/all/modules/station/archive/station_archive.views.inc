<?php

// $Id: station_archive.views.inc,v 1.1 2009/04/19 23:01:59 drewish Exp $

/**
 * Implementation of hook_views_tables().
 */
function station_archive_views_data() {
  $data['station_archive_item']['table']['group']  = t('Station archive');
  $data['station_archive_item']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'audio_nid'
  );

  $data['station_archive_item']['aired'] = array(
    'title' => t('Station Archive: Air date'),
    'help' => t('Date the audio was aired.'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'views_handler_field_date',
    ),
  );

  $data['station_archive_item']['imported'] = array(
    'title' => t('Station Archive: Import date'),
    'help' => t('Date the audio was imported into the station archive.'),
    'field' => array('sortable' => TRUE,
    'handler' => 'views_handler_field_date',
      'option' => 'string',
    ),
  );

  $data['station_archive_item']['permanent'] = array(
    'title' => t('Station Archive: Is in permanent archive'),
    'help' => t('Filter whether the node is part of the permanent archive.'),
    'filters' => array(),
  );
  $data['station_archive_item']['program_nid'] = array(
    'title' => t('Station Archive: Audio by Program'),
    'help' => t('The Program NID argument allows visitors to filter archived audio to those of the specified program.'),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    )
  );
  $data['station_archive_program']['table']['join']['station_archive_item'] = array(
     'left_field' => 'program_nid',
     'field' => 'program_nid',
  );

  $data['station_archive_program']['title'] = array(
    'title' => t('Station Archive: Program title'),
    'help' => t('The program that this audio is a recording of.'),
    'field' => array(
      'sortable' => TRUE,
      'handler' => 'station_archive_handler_audio_program_title_field',
      'option' => array(
        '#type' => 'select',
        '#options' => array(
          'link' => 'As link',
          'nolink' => 'Without link'
        ),
      ),
    ),
  );
  return $data;
}

/**
 * Implementation of hook_views_arguments().
 */
function station_archive_views_arguments() {
  $arguments = array(
    'station_archive_program_nid' => array(
      'name' => t('Station Archive: Audio by Program'),
      'handler' => 'station_archive_arg_program_nid_handler',
      'help' => t('The Program NID argument allows visitors to filter archived audio to those of the specified program.'),
    ),
  );
  return $arguments;
}


/**
 * Handle the program node id argument.
 */
function station_archive_arg_program_nid_handler($op, &$query, $argtype, $arg = '') {
  switch($op) {
    case 'summary':
      // add these up front to avoid a wacky bug with rewriting
      $query->ensure_table('node');
      $query->add_field('nid', 'node');
      // now onto our regularly scheduled program
      $query->ensure_table('station_archive_item');
      $query->ensure_table('station_archive_program');
      $query->add_field('title', 'station_archive_program');
      $query->add_field('program_nid', 'station_archive_program');
      $query->add_where('station_archive_program.program_nid IS NOT NULL');
      $fieldinfo['field'] = "station_archive_program.title";
      return $fieldinfo;
    case 'sort':
      $query->ensure_table('station_archive_program');
      $query->add_orderby('station_archive_program', 'title', $argtype);
      break;
    case 'filter':
      $query->ensure_table("station_archive_item");
      $query->add_where("station_archive_item.program_nid = %d", $arg);
      break;
    case 'link':
      return l($query->title, "$arg/" . intval($query->program_nid));
    case 'title':
      $node = db_fetch_object(db_query("SELECT sap.title FROM {station_archive_program} sap WHERE sap.program_nid=%d", $query));
      return check_plain($node->title);
  }
}

function station_archive_handler_timestamp_field($fieldinfo, $fielddata, $value, $data) {
  return l(format_date($value, 'custom', 'j-n-y'), "node/$data->nid");
}

function station_archive_handler_audio_program_title_field($fieldinfo, $fielddata, $value, $data) {
  $schedule = station_default_schedule();
  if ($fielddata['options'] == 'link' && isset($schedule['base_url']) && !empty($data->station_archive_program_program_nid)) {
    return l($value, $schedule['base_url'] .'/node/'. $data->station_archive_program_program_nid);
  }
  return check_plain($value);
}
