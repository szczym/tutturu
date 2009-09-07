<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _video_transcode_node_info() {
  $items = array(
    'video' => array(
      'name' => t('video'),
      'module' => 'node',
      'description' => t(''),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
    ),
  );
  return $items;
}
