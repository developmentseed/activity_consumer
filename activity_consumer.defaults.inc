<?php

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _activity_consumer_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "data" && $api == "data_default") {
    return array("version" => 1);
  }
  else if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_data_default().
 */
function _activity_consumer_data_default() {
  $export = array();
  $data_table = new stdClass;
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Activity feed';
  $data_table->name = 'feeds_data_activity_feed';
  $data_table->table_schema = array(
    'description' => 'InnoDB free: 200704 kB',
    'fields' => array(
      'feed_nid' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => '',
      ),
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => '',
      ),
      'timestamp' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => FALSE,
        'description' => '',
      ),
      'title' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'description' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'author_name' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'author_email' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'url' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
    ),
    'name' => 'feeds_data_activity_feed',
    'indexes' => array(
      'feed_nid' => array(
        '0' => 'feed_nid',
      ),
      'id' => array(
        '0' => 'id',
      ),
      'timestamp' => array(
        '0' => 'timestamp',
      ),
      'url' => array(
        '0' => 'url',
      ),
    ),
    'primary key' => array(
      '0' => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'feed_nid' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'id' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'timestamp' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field_date',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'title' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field_data_markup',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'description' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'author_name' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'author_email' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_activity_consumer_author_identifier',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'url' => array(
        'label' => '',
        'views_field_handler' => 'views_handler_field_url',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
    ),
    'join' => array(),
  );

  $export['feeds_data_activity_feed'] = $data_table;
  return $export;
}

/**
 * Helper to implementation of hook_feeds_importer_default().
 */
function _activity_consumer_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'activity_feed';
  $feeds_importer->config = array(
    'name' => 'Activity feed',
    'description' => 'An importer aggregating activity feeds from activity sources.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSimplePieParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsDataProcessor',
      'config' => array(
        'update_existing' => 0,
        'expire' => '7257600',
        'mappings' => array(
          '0' => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          '1' => array(
            'source' => 'description',
            'target' => 'description',
            'unique' => 0,
          ),
          '2' => array(
            'source' => 'author_name',
            'target' => 'author_name',
            'unique' => 0,
          ),
          '3' => array(
            'source' => 'author_email',
            'target' => 'author_email',
            'unique' => 0,
          ),
          '4' => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 1,
          ),
        ),
      ),
    ),
    'content_type' => 'activity_feed',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['activity_feed'] = $feeds_importer;
  return $export;
}
