<?php

function sl7_advantage_service_access($op, $service = NULL, $account = NULL) {
  $rights = &drupal_static(__FUNCTION__, array());

  if (!empty($account)) {
    $account = is_object($account) ? $account : user_load($account);
  }
  else {
    $account = $GLOBALS['user'];
  }

  if ($account->uid == 1) {
    return TRUE;
  }

  if (isset($rights[$account->uid][$op])) {
    return $rights[$account->uid][$op];
  }

  if (user_access("sl7_advantage administer", $account)) {
    $rights[$account->uid][$op] = TRUE;
    return TRUE;
  }

  if (!$service) {
    if (user_access("sl7_advantage $op", $account)) {
      $rights[$account->uid][$op] = TRUE;
      return TRUE;
    }
    else {
      $rights[$account->uid][$op] = FALSE;
      return FALSE;
    }
  }

  return FALSE;
}

function sl7_advantage_service_create($values = array()) {
  return entity_get_controller('sl7_advantage_service')->create($values);
}

function sl7_advantage_service_load($sid, $reset = FALSE) {
  $service = sl7_advantage_service_load_multiple(array($sid), array(), $reset);
  return reset($service);
}

function sl7_advantage_service_load_multiple($sids = array(), $conditions = array(), $reset = FALSE) {
  $ids = empty($sids) ? FALSE : $sids;
  return entity_load('sl7_advantage_service', $ids, $conditions, $reset);
}

function sl7_advantage_service_save(SL7AdvantageService $service) {
  entity_save('sl7_advantage_service', $service);
}

function sl7_advantage_service_delete(SL7AdvantageService $service) {
  entity_delete('sl7_advantage_service', entity_id('sl7_advantage_service', $service));
}

function sl7_advantage_service_delete_multiple(array $sids) {
  entity_delete_multiple('sl7_advantage_service', $sids);
}

function sl7_advantage_service_title(SL7AdvantageService $service) {
  return $service->defaultLabel();
}