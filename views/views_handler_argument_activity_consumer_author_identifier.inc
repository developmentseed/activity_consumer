<?php

class views_handler_argument_activity_consumer_author_identifier extends views_handler_argument {
  /**
   * Override of set_argument().
   * Translate a numeric uid on the provider to an absolute openid identifier.
   */
  function set_argument($arg) {
    if (is_numeric($arg)) {
      $arg = url("user/{$arg}/identity", array('absolute' => TRUE));
    }
    $this->argument = $arg;
    return $this->validate_arg($arg);
  }

  /**
   * Override the behavior of title(). Get the name of the user.
   */
  function title() {
    if (!empty($this->argument) && $uid = openid_provider_sso_get_uid($this->argument)) {
      return db_result(db_query("SELECT u.name FROM {users} u WHERE u.uid = %d", $uid));
    }
    return variable_get('anonymous', t('Anonymous'));
  }
}
