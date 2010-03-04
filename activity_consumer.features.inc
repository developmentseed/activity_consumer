<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function activity_consumer_ctools_plugin_api() {
  module_load_include('inc', 'activity_consumer', 'activity_consumer.defaults');
  $args = func_get_args();
  return call_user_func_array('_activity_consumer_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_data_default().
 */
function activity_consumer_data_default() {
  module_load_include('inc', 'activity_consumer', 'activity_consumer.defaults');
  $args = func_get_args();
  return call_user_func_array('_activity_consumer_data_default', $args);
}

/**
 * Implementation of hook_feeds_importer_default().
 */
function activity_consumer_feeds_importer_default() {
  module_load_include('inc', 'activity_consumer', 'activity_consumer.defaults');
  $args = func_get_args();
  return call_user_func_array('_activity_consumer_feeds_importer_default', $args);
}

/**
 * Implementation of hook_node_info().
 */
function activity_consumer_node_info() {
  module_load_include('inc', 'activity_consumer', 'activity_consumer.features.node');
  $args = func_get_args();
  return call_user_func_array('_activity_consumer_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function activity_consumer_views_default_views() {
  module_load_include('inc', 'activity_consumer', 'activity_consumer.features.views');
  $args = func_get_args();
  return call_user_func_array('_activity_consumer_views_default_views', $args);
}
