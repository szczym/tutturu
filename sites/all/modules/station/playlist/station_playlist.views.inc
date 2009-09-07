<?php
// $Id: station_playlist.views.inc,v 1.1 2009/03/11 07:47:02 drewish Exp $

/**
 * Implementation of hook_views_data().
 */
function station_playlist_views_data() {
  // Basic table information.

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['station_playlist_track']['table']['group']  = t('Station playlist track');
  $data['station_playlist_track']['table']['base'] = array(
    'field' => 'iid',
    'title' => t('Station Playlist Track'),
    'help' => t('Station playlist track entries.'),
  );

  // For other base tables, explain how we join
  $data['station_playlist_track']['table']['join'] = array(
    'node' => array(
      'handler' => 'views_join', // this is actually optional
      'arguments' => array('station_playlist_track', 'node', 'nid', 'nid'),
     ),
  );

  // ----------------------------------------------------------------
  // Fields
  $data['station_playlist_track']['nid'] = array(
    'title' => t('Playlist node'),
    'help' => t("The playlist this track is attached to."),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Playlist'),
    ),
  );
  $data['station_playlist_track']['artist'] = array(
    'title' => t('Artist'),
    'help' => t("Album artist name."),
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
  $data['station_playlist_track']['album'] = array(
    'title' => t('Album title'),
    'help' => t("Title of the album album."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
     'filter' => array(
       'handler' => 'views_handler_filter_string',
       'label' => t('Album'),
       ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['station_playlist_track']['title'] = array(
    'title' => t('Title'),
    'help' => t("Title of the track."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
     'filter' => array(
       'handler' => 'views_handler_filter_string',
       'label' => t('Label'),
       ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}
