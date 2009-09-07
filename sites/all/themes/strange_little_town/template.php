<?php
// $Id: template.php,v 1.1.2.11 2009/02/22 19:36:22 gibbozer Exp $

/**
 * Force refresh of theme registry.
 * DEVELOPMENT USE ONLY - COMMENT OUT FOR PRODUCTION
 */
// drupal_rebuild_theme_registry();

/**
 * Initialize theme settings
 */
if (is_null(theme_get_setting('page_class'))) {
  global $theme_key;
  // Save default theme settings
  $defaults = array(
    'page_class'     => 'medium',
    'iepngfix'       => 1,
    'custom'         => 0,
    'breadcrumb'     => 0,
    'totop'          => 0,
  );

  variable_set(
    str_replace('/', '_', 'theme_'. $theme_key .'_settings'),
    array_merge(theme_get_settings($theme_key), $defaults)
  );
  // Force refresh of Drupal internals
  theme_get_setting('', TRUE);
}

function phptemplate_preprocess(&$vars, $hook) {
  global $theme;

  // Set Page Class
  $vars['page_class'] = theme_get_setting('page_class');

  // Hide breadcrumb on all pages
  if (theme_get_setting('breadcrumb') == 0) {
    $vars['breadcrumb'] = '';  
  }

  $vars['closure'] .= '
  <p id="theme-credit"><a href="http://drupal.org/project/strange_little_town">Strange Little Town</a> | '. t('Original Designed : ') . '<a href="http://magical.nu/">Magical.nu</a> | '. t('Drupal Ported : '). '<a href="http://webzer.net/">Webzer.net</a></p>
  ';

  // Theme primary and secondary links.
  $vars['primary_menu'] = theme('links', $vars['primary_links'], array('class' => 'links primary-menu'));
  $vars['secondary_menu'] = theme('links', $vars['secondary_links'], array('class' => 'links secondary-menu'));

  // Set Accessibility nav bar
  if ($vars['primary_menu'] != '') {
  $vars['nav_access'] = '
    <ul id="nav-access" class="hidden">
      <li><a href="#primary-menu" accesskey="N" title="'.t('Skip to Primary Menu').'">'. t('Skip to Primary Menu') .'</a></li>
      <li><a href="#main-content" accesskey="M" title="'.t('Skip to Main Content').'">'.t('Skip to Main Content').'</a></li>
    </ul>
  ';
  }
  else {
  $vars['nav_access'] = '
    <ul id="nav-access" class="hidden">
      <li><a href="#main-content" accesskey="M" title="'.t('Skip to Main Content').'">'.t('Skip to Main Content').'</a></li>
    </ul>
  ';
  }

  // Set Back to Top link toggle
  $vars['to_top'] = theme_get_setting('totop');
  if (theme_get_setting('totop') == 0) {
    $vars['to_top'] = '';
  }
  else {
    $vars['to_top'] = '<p id="to-top"><a href="#page">'. t('Back To Top') .'</a></p>';
  }

  // Comments count
  if (isset($vars['node']->links['comment_comments'])) {
    if ($vars['teaser']) {
      $all = comment_num_all($vars['node']->nid);
      $vars['comments_count'] = format_plural($all, '1 comment', '@count comments');
    }
  }


  // Make sure framework styles are placed above all others.
  $vars['css_alt'] = css_reorder($vars['css']);
  $vars['styles'] = drupal_get_css($vars['css_alt']);

}

/**
 * This rearranges how the style sheets are included so the framework styles
 * are included first.
 * Code sample from "Ninesixty" Drupal7.x Theme
 */
function css_reorder($css) {
  global $theme_info, $base_theme_info;

  // Dig into the framework .info data.
  $framework = !empty($base_theme_info) ? $base_theme_info[0]->info : $theme_info->info;

  // Pull framework styles from the themes .info file and place them above all stylesheets.
  if (isset($framework['stylesheets'])) {
    foreach ($framework['stylesheets'] as $media => $styles_from_webzer) {
      // Setup framework group.
      if (isset($css[$media])) {
        $css[$media] = array_merge(array('framework' => array()), $css[$media]);
      }
      else {
        $css[$media]['framework'] = array();
      }
      foreach ($styles_from_webzer as $style_from_webzer) {
        // Force framework styles to come first.
        if (strpos($style_from_webzer, 'framework') !== FALSE) {
          $framework_shift = $style_from_webzer;
          $remove_styles = array($style_from_webzer);
          $css[$media]['framework'][$framework_shift] = TRUE;
          foreach ($remove_styles as $remove_style) {
            unset($css[$media]['theme'][$remove_style]);
          }
        }
      }
    }
  }
  return $css;
}

/**
 *  Create some custom classes for comments
 */
function comment_classes($comment) {
  $node = node_load($comment->nid);
  global $user;
 
  $output .= ($comment->new) ? ' comment-new' : ''; 
  $output .=  ' '. $status .' '; 
  if ($node->name == $comment->name) {	
    $output .= 'node-author';
  }
  if ($user->name == $comment->name) {	
    $output .=  ' mine';
  }
  return $output;
}

/**
 *  Change Feed Icon
 */
function phptemplate_feed_icon($url, $title) {
    return '<a href="'. check_url($url) .'" class="feed-icon" title="'.t('Syndicate content').'">'.t('RSS').'</a>';
}

/**
 * Set default form file input size 
 */
function phptemplate_file($element) {
  $element['#size'] = 40;
  return theme_file($element);
}

/**
 *  Set Custom Stylesheet
 */
if (theme_get_setting('custom')) {
  drupal_add_css(drupal_get_path('theme', 'strange_little_town') .'/css/custom.css', 'theme');
}

/**
 *  Add IE PNG Transparent fix
 */
if (theme_get_setting('iepngfix')) {
  drupal_add_js(drupal_get_path('theme', 'strange_little_town') .'/js/jquery.pngFix.js', 'theme');
}