<?php
// $Id: theme-settings.php,v 1.1.2.6 2009/02/22 19:36:22 gibbozer Exp $

function phptemplate_settings($saved_settings) {

  $settings = theme_get_settings('strange_little_town');

/**
 * The default values for the theme variables. Make sure $defaults exactly
 * matches the $defaults in the template.php file.
 */
  $defaults = array(
    'page_class'     => 'medium',
    'iepngfix'       => 1,
    'custom'         => 0,
    'breadcrumb'     => 0,
    'totop'          => 0,
  );

  // Merge the saved variables and their default values
  $settings = array_merge($defaults, $saved_settings);

  // Create theme settings form widgets using Forms API
  // colourise Fieldset
  $form['container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Strange Little Town Theme Settings'),
    '#description' => t('Use these settings to change what and how information is displayed in <strong>Strange Little Town</strong> theme.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['container']['page_class'] = array(
    '#type' => 'radios',
    '#title' => t('Page Width'),
    '#description'   => t('Select the page width you need. <strong>Be careful</strong>, the Narrow and Medium Width may not suite 2 sidebars.'),
    '#default_value' => $settings['page_class'],
    '#options' => array(
      'narrow' => t('Narrow (Fixed width: 780px)'),
      'medium' => t('Medium (Fixed width: 840px)'),
      'wide' => t('Wide (Fixed width: 960px)'),
      'super-wide' => t('Super Wide (Fixed width: 1020px)'),
      'extreme-wide' => t('Extreme Wide (Fixed width: 1140px)'),
      'fluid' => t('Fluid (min-width: 780px)'),
    ),
  );

  $form['container']['features'] = array(
    '#type' => 'fieldset',
    '#title' => t('Other Features'),
	'#description'   => t('Check / Uncheck each themes features you want to activate or deactivate for your site.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['container']['features']['iepngfix'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use <strong>IE Transparent PNG Fix</strong>'),
    '#default_value' => $settings['iepngfix'],
  );

  $form['container']['features']['custom'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add <strong>Customized Stylesheet (custom.css)</strong>'),
    '#default_value' => $settings['custom'],
  );

  $form['container']['features']['breadcrumb'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show <strong>Breadcrumbs</strong>'),
    '#default_value' => $settings['breadcrumb'],
  );

  $form['container']['features']['totop'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show <strong>Back to Top link</strong> (the link will appear at footer)'),
    '#default_value' => $settings['totop'],
  );

  return $form;
}