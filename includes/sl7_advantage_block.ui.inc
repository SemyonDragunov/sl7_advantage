<?php

/**
 * UI controller for sl7_advantage_block.
 */
class SL7AdvantageBlockUIController extends EntityDefaultUIController {

  public function hook_menu() {

    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%sl7_advantage_block';

    $items[$this->path . '/add'] = array(
      'title'            => t('Create block'),
      'page callback'    => 'sl7_advantage_block_get_edit_form',
      'page arguments'   => array('create', NULL, $id_count - 1),
      'access callback'  => 'sl7_advantage_block_access',
      'access arguments' => array('administer'),
      'type'             => MENU_LOCAL_TASK,
      'context'          => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'weight'           => -9,
    );

    $items[$this->path . '/' . $wildcard . '/edit'] = array(
      'title'            => t('Edit block'),
      'page callback'    => 'sl7_advantage_block_get_edit_form',
      'page arguments'   => array('edit', $id_count),
      'load arguments'   => array($this->entityType),
      'access callback'  => 'sl7_advantage_block_access',
      'access arguments' => array('administer'),
      'type'             => MENU_LOCAL_TASK,
      'weight'           => -8,
      'context'          => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );

    $items[$this->path . '/' . $wildcard . '/delete'] = array(
      'title'            => t('Delete block'),
      'page callback'    => 'drupal_get_form',
      'page arguments'   => array('sl7_advantage_block_delete_form', $id_count),
      'load arguments'   => array($this->entityType),
      'access callback'  => 'sl7_advantage_block_access',
      'access arguments' => array('administer'),
      'type'             => MENU_LOCAL_TASK,
      'context'          => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'weight'           => -7,
    );

    $module_path = drupal_get_path('module', $this->entityInfo['module']);
    foreach ($items as &$item) {
      $item['file'] = 'includes/sl7_advantage_block.ui.inc';
      $item['file path'] = $module_path;
    }
    unset($item);

    return $items;
  }

  public function form($form, &$form_state) {
    $block = $form_state['sl7_advantage_block'];

    field_attach_form('sl7_advantage_block', $block, $form, $form_state);

    $form['actions'] = array(
      '#type' => 'actions',
    );
    $form['actions']['submit'] = array(
      '#type'   => 'submit',
      '#value'  => !empty($block->bid) ? t('Save') : t('Create'),
      '#weight' => 0,
    );
    $form['actions']['delete'] = array(
      '#markup' => !empty($block->bid) ? l(t('Delete'), $block->realPath() . '/delete', array('attributes' => array('class' => array('button remove')), 'query' => array('destination' => SL7_ADVANTAGE_ADMIN_PATH . '/'  . $block->sid))) : '',
    );

    return $form;
  }

  public function formValidate($form, &$form_state) {

  }

  public function formSubmit($form, &$form_state) {
    $block = $this->entityFormSubmitBuildEntity($form, $form_state);
    $block->save();

    $form_state['redirect'] = SL7_ADVANTAGE_ADMIN_PATH . '/' . $block->sid;

    if (!empty($block->is_new)) {
      drupal_set_message(t("Block created."));
    }
    else {
      drupal_set_message(t("Block saved."));
    }
  }

  public function deleteForm($form, &$form_state) {
    $block = $form_state['sl7_advantage_block'];

    $form = confirm_form($form,
      t("Are you sure about the removal of the block?"),
      SL7_ADVANTAGE_ADMIN_PATH . '/' . $block->sid,
      '<p>' . t('The deletion can not be undone.') . '</p>',
      t('Delete'),
      t('Cancel'),
      'confirm'
    );

    return $form;
  }

  public function deleteFormSubmit($form, &$form_state) {
    $block = $form_state['sl7_advantage_block'];
    sl7_advantage_block_delete($block);
    drupal_set_message(t("Block deleted."));

    $form_state['redirect'] = SL7_ADVANTAGE_ADMIN_PATH . '/' . $block->sid;
  }
}

function sl7_advantage_block_edit_form($form, &$form_state) {
  return entity_ui_controller($form_state['entity_type'])->form($form, $form_state);
}

function sl7_advantage_block_edit_form_validate($form, &$form_state) {
  entity_ui_controller($form_state['entity_type'])->formValidate($form, $form_state);
}

function sl7_advantage_block_edit_form_submit($form, &$form_state) {
  entity_ui_controller($form_state['entity_type'])->formSubmit($form, $form_state);
}

function sl7_advantage_block_delete_form($form, &$form_state, $block) {
  $entity_type = 'sl7_advantage_block';
  $form_state['entity_type'] = $entity_type;
  $form_state[$entity_type] = $block;
  return entity_ui_controller($form_state['entity_type'])->deleteForm($form, $form_state);
}

function sl7_advantage_block_delete_form_submit($form, &$form_state) {
  entity_ui_controller($form_state['entity_type'])->deleteFormSubmit($form, $form_state);
}

function sl7_advantage_block_get_edit_form($op = 'create', $block = NULL, $sl7_advantage_service = NULL) {
  $form_state = array(
    'entity_type' => 'sl7_advantage_block',
    'op' => $op,
  );

  switch ($op) {
    case 'create':
      drupal_set_title('Создать пункт');
      $service = sl7_advantage_service_load($sl7_advantage_service);
      $form_state['sl7_advantage_block'] = entity_create('sl7_advantage_block', array('sid' => $service->sid));
      break;
    case 'edit':
      $form_state['sl7_advantage_block'] = is_object($block) ? $block : sl7_advantage_block_load($block);
      drupal_set_title(t('Edit block'));
      break;
    default:
      $form_state['sl7_advantage_block'] = $block;
      break;
  }

  form_load_include($form_state, 'inc', 'sl7_advantage_block', 'includes/sl7_advantage_block.ui');

  $form_state['build_info']['args'] = array($op, $block);

  return drupal_build_form('sl7_advantage_block_edit_form', $form_state);
}