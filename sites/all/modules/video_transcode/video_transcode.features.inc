<?php

/**
 * Implementation of hook_content_default_fields().
 */
function video_transcode_content_default_fields() {
  module_load_include('inc', 'video_transcode', 'video_transcode.defaults');
  $args = func_get_args();
  return call_user_func_array('_video_transcode_content_default_fields', $args);
}

/**
 * Implementation of hook_node_info().
 */
function video_transcode_node_info() {
  module_load_include('inc', 'video_transcode', 'video_transcode.features.node');
  $args = func_get_args();
  return call_user_func_array('_video_transcode_node_info', $args);
}
