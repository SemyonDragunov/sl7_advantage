<?php

function sl7_advantage_block_access($op, $block = NULL, $account = NULL, $entity_type = NULL) {
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

  if (!$block) {
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

function sl7_advantage_block_create($values = array()) {
  return entity_get_controller('sl7_advantage_block')->create($values);
}

function sl7_advantage_block_load($bid, $reset = FALSE) {
  $block = sl7_advantage_block_load_multiple(array($bid), array(), $reset);
  return reset($block);
}

function sl7_advantage_block_load_multiple($bids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('sl7_advantage_block', $bids, $conditions, $reset);
}

function sl7_advantage_block_save(SL7AdvantageBlock $block) {
  entity_save('sl7_advantage_block', $block);
}

function sl7_advantage_block_delete(SL7AdvantageBlock $block) {
  entity_delete('sl7_advantage_block', entity_id('sl7_advantage_block', $block));
}

function sl7_advantage_block_delete_multiple($bids) {
  entity_delete_multiple('sl7_advantage_block', $bids);
}

/**
 * Return weight Service.
 * @param mixed $block SL7AdvantageBlock or bid.
 * @return mixed
 */
function sl7_advantage_block_get_weight($block) {
  $bid = is_object($block) ? $block->bid : $block;

  $weight = db_select('draggableviews_structure', 'ds')
    ->condition('ds.view_name', 'sl7_advantage_block')
    ->condition('ds.view_display', 'service_manage_page')
    ->condition('ds.entity_id', $bid)
    ->fields('ds', array('weight'))
    ->execute()
    ->fetchField();

  if (empty($weight)) $weight = 0;

  return $weight;
}