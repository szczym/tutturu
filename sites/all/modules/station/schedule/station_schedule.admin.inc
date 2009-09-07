<?php
// $Id: station_schedule.admin.inc,v 1.4 2008/12/14 20:23:47 drewish Exp $

/**
 * Admin settings form.
 */
function station_schedule_admin_settings() {
  $form['bc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Backwards compatibility'),
  );
  $schedules = array();
  foreach (station_get_schedules() as $nid => $schedule) {
    $schedules[$nid] = $schedule['title'];
  }
  $form['bc']['station_schedule_redirect_old_urls'] = array(
    '#type' => 'checkbox',
    '#title' => t('Redirect old links'),
    '#default_value' => variable_get('station_schedule_redirect_old_urls', 0),
    '#options' => $schedules,
    '#description' => t("Checking this will ensure that the station module continues to redirect old <code>/schedule</code> and <code>/station/schedule</code> links."),
  );
  $form['bc']['station_schedule_default'] = array(
    '#type' => 'select',
    '#title' => t('Default schedule'),
    '#default_value' => variable_get('station_schedule_default', 0),
    '#options' => $schedules,
    '#description' => t("This you select the schedule that will be used as the default for backwards compatibility."),
  );

  $form['station_schedule_program_node_type'] = array(
    '#type' => 'item',
    '#title' => t('Scheduled node type'),
    '#value' => t('The schedule is using the %type node provided by the %module module.', array('%type' => 'station_program', '%module' => node_get_types('module', 'station_program'))),
  );

  $form['module_cvs_id'] = array(
    '#type' => 'item',
    '#value' => '<pre>'. STATION_SCHEDULE_CVS_ID .'</pre>',
  );

  return system_settings_form($form);
}
