<?php
// $Id: station_schedule_handler_field_start_time.inc,v 1.1 2008/12/01 17:09:41 drewish Exp $

class station_schedule_handler_field_start_time extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['finish'] = 'finish';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['style'] = array('default' => 'station_hour');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['style'] = array(
      '#type' => 'radios',
      '#title' => t('Style'),
      '#options' => array(
        'station_hour' => t('Time'),
        'station_hour_range' => t('Time range'),
        'station_dayhour_range' => t('Day time range'),
      ),
      '#default_value' => $this->options['style'],
      '#description' => t('Which time style should be used.'),
    );
  }

  function render($values) {
    $start = $values->{$this->field_alias};
    $finish = $values->{$this->aliases['finish']};
    return theme($this->options['style'], $start, $finish);
  }
}
