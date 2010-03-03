<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _activity_consumer_node_info() {
  $items = array(
    'activity_feed' => array(
      'name' => t('Activity feed'),
      'module' => 'features',
      'description' => t('A subscription to an activity feed.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
