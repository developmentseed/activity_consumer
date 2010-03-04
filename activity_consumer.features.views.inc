<?php

/**
 * Helper to implementation of hook_views_default_views().
 */
function _activity_consumer_views_default_views() {
  $views = array();

  // Exported view: activity_consumer_user
  $view = new view;
  $view->name = 'activity_consumer_user';
  $view->description = 'Activity by user';
  $view->tag = 'activity_consumer';
  $view->view_php = '';
  $view->base_table = 'feeds_data_activity_feed';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'timestamp' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'medium',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'timestamp',
      'table' => 'feeds_data_activity_feed',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'feeds_data_activity_feed',
      'field' => 'title',
      'relationship' => 'none',
      'format' => 'default',
    ),
  ));
  $handler->override_option('sorts', array(
    'timestamp' => array(
      'order' => 'DESC',
      'id' => 'timestamp',
      'table' => 'feeds_data_activity_feed',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Affiliate sites');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', 'mini');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'timestamp' => 'timestamp',
      'title' => 'title',
    ),
    'info' => array(
      'timestamp' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('block', 'Activity on affiliate sites', 'block_1');
  $handler->override_option('block_description', 'Activity on affiliate sites');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('block', 'User activity on affiliate sites', 'block_2');
  $handler->override_option('arguments', array(
    'author_email' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '%1 on affiliate sites',
      'breadcrumb' => '',
      'default_argument_type' => 'user',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'id' => 'author_email',
      'table' => 'feeds_data_activity_feed',
      'field' => 'author_email',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
        '4' => 0,
      ),
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'book' => 0,
        'event' => 0,
        'feed_ical' => 0,
        'feed_ical_item' => 0,
        'group' => 0,
        'profile' => 0,
        'shoutbox' => 0,
        'activity_feed' => 0,
        'casetracker_basic_case' => 0,
        'casetracker_basic_project' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_is_member' => 'OG_VIEWS_DO_NOT_VALIDATE_MEMBERSHIP',
      'validate_argument_group_node_type' => array(
        'group' => 0,
      ),
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'module' => array(
      'operator' => '=',
      'value' => 'openid',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'case' => 1,
      'id' => 'module',
      'table' => 'authmap',
      'field' => 'module',
      'relationship' => 'author_email',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('block_description', 'User activity on affiliate sites');
  $handler->override_option('block_caching', -1);
  $translatables['activity_consumer_user'] = array(
    t('Activity on affiliate sites'),
    t('Affiliate sites'),
    t('Defaults'),
    t('User activity on affiliate sites'),
  );

  $views[$view->name] = $view;

  return $views;
}
