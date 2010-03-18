<?php

/**
 * Implementation of hook_views_handlers().
 */
function activity_consumer_views_handlers() {
  return array(
    'info' => array('path' => drupal_get_path('module', 'activity_consumer') .'/views'),
    'handlers' => array(
      'views_handler_argument_activity_consumer_author_identifier' => array('parent' => 'views_handler_argument'),
    ),
  );
}
