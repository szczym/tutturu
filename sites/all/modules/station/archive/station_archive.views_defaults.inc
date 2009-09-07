<?php

// $Id: station_archive.views_defaults.inc,v 1.1 2009/04/19 23:01:59 drewish Exp $

/**
 * Implementation of hook_views_default_views().
 */
function station_archive_views_default_views() {
  $view = new stdClass();
  $view->name = 'station_archive_audio';
  $view->description = 'Archived audio';
  $view->access = array (
);
  $view->view_args_php = '';
  $view->page = TRUE;
  $view->page_title = 'Archive';
  $view->page_header = '';
  $view->page_header_format = '1';
  $view->page_footer = '';
  $view->page_footer_format = '1';
  $view->page_empty = 'Sorry, no audio could be found for this program.';
  $view->page_empty_format = '1';
  $view->page_type = 'teaser';
  $view->url = 'station/archives';
  $view->use_pager = TRUE;
  $view->nodes_per_page = '30';
  $view->menu = TRUE;
  $view->menu_title = 'Archive';
  $view->menu_tab = FALSE;
  $view->menu_tab_weight = '0';
  $view->menu_tab_default = FALSE;
  $view->menu_tab_default_parent = NULL;
  $view->menu_tab_default_parent_type = 'tab';
  $view->menu_parent_tab_weight = '0';
  $view->menu_parent_title = '';
  $view->sort = array (
    array (
      'tablename' => 'node',
      'field' => 'created',
      'sortorder' => 'DESC',
      'options' => 'normal',
    ),
  );
  $view->argument = array (
    array (
      'type' => 'station_archive_program_nid',
      'argdefault' => '4',
      'title' => 'Archive of %1',
      'options' => '',
      'wildcard' => 'all',
      'wildcard_substitution' => 'all programs',
    ),
    array (
      'type' => 'rss_feed',
      'argdefault' => '2',
      'title' => '',
      'options' => '',
      'wildcard' => '',
      'wildcard_substitution' => '',
    ),
  );
  $view->field = array (
  );
  $view->filter = array (
    array (
      'tablename' => 'node',
      'field' => 'type',
      'operator' => 'OR',
      'options' => '',
      'value' => array (
  0 => 'audio',
),
    ),
  );
  $view->exposed_filter = array (
  );
  $view->requires = array(node);
  $views[$view->name] = $view;





  $view = new stdClass();
  $view->name = 'station_archive_audio_rss';
  $view->description = 'Station Archive';
  $view->access = array (
);
  $view->view_args_php = '';
  $view->page = TRUE;
  $view->page_title = 'Program Archive';
  $view->page_header = '';
  $view->page_header_format = '1';
  $view->page_footer = '';
  $view->page_footer_format = '1';
  $view->page_empty = '';
  $view->page_empty_format = '1';
  $view->page_type = 'views_rss';
  $view->url = 'station/archives/rss';
  $view->use_pager = TRUE;
  $view->nodes_per_page = '20';
  $view->sort = array (
    array (
      'tablename' => 'node',
      'field' => 'created',
      'sortorder' => 'DESC',
      'options' => 'normal',
    ),
  );
  $view->argument = array (
    array (
      'type' => 'station_archive_program_nid',
      'argdefault' => '2',
      'title' => 'Archive of %1',
      'options' => '',
      'wildcard' => 'all',
      'wildcard_substitution' => 'all programs',
    ),
  );
  $view->field = array (
  );
  $view->filter = array (
    array (
      'tablename' => 'node',
      'field' => 'type',
      'operator' => 'OR',
      'options' => '',
      'value' => array (
  0 => 'audio',
),
    ),
  );
  $view->exposed_filter = array (
  );
  $view->requires = array(node);
  $views[$view->name] = $view;



  return $views;
}
