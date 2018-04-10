<?php

/**
 * UI controller for sl7_advantage_service.
 */
class SL7AdvantageServiceUIController extends EntityDefaultUIController {

  public function hook_menu() {

    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%sl7_advantage_service';

    $items[$this->path] = array(
      'title' => t('Advantage'),
      'description' => t('Manage block sets.'),
      'page callback' => 'views_embed_view',
      'page arguments' => array('sl7_advantage_service', 'manage_page'),
      'access arguments' => array('sl7_advantage administer'),
    );

    $items[$this->path . '/add'] = array(
      'title'            => t('Create Advantage'),
      'page callback'    => 'sl7_advantage_service_get_edit_form',
      'page arguments'   => array('create', NULL),
      'access callback'  => 'sl7_advantage_service_access',
      'access arguments' => array('administer'),
      'type'             => MENU_LOCAL_TASK,
      'weight'           => -9,
      'context'          => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );

    $items[$this->path . '/' . $wildcard] = array(
      'title callback'   => 'sl7_advantage_service_title',
      'title arguments'  => array($id_count),
      'page callback'    => 'views_embed_view',
      'page arguments'   => array('sl7_advantage_block', 'service_manage_page'),
      'access arguments' => array('sl7_advantage administer'),
      'load arguments'   => array($this->entityType),
      'type'             => MENU_NORMAL_ITEM,
    );

    $items[$this->path . '/' . $wildcard . '/view'] = array(
      'title'  => t('Viewing blocks'),
      'type'   => MENU_DEFAULT_LOCAL_TASK,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'weight' => -10,
    );

    $items[$this->path . '/' . $wildcard . '/edit'] = array(
      'title'            => t('Edit Advantage'),
      'page callback'    => 'sl7_advantage_service_get_edit_form',
      'page arguments'   => array('edit', $id_count),
      'load arguments'   => array($this->entityType),
      'access callback'  => 'sl7_advantage_service_access',
      'access arguments' => array('administer'),
      'type'             => MENU_LOCAL_TASK,
      'weight'           => -8,
      'context'          => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );

    $items[$this->path . '/' . $wildcard . '/delete'] = array(
      'title'            => t('Delete Advantage'),
      'page callback'    => 'drupal_get_form',
      'page arguments'   => array('sl7_advantage_service_delete_form', $id_count),
      'load arguments'   => array($this->entityType),
      'access callback'  => 'sl7_advantage_service_access',
      'access arguments' => array('administer'),
      'type'             => MENU_LOCAL_TASK,
      'context'          => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'weight'           => -7,
    );

    $module_path = drupal_get_path('module', $this->entityInfo['module']);
    foreach ($items as &$item) {
      $item['file'] = 'includes/sl7_advantage_service.ui.inc';
      $item['file path'] = $module_path;
    }
    unset($item);

    return $items;
  }

  public function form($form, &$form_state) {

    $service = $form_state['sl7_advantage_service'];

    $form['label'] = array(
      '#type' => 'textfield',
      '#title' => t('Advantage title'),
      '#default_value' => !empty($service->label) ? $service->label : '',
      '#maxlength' => 128,
      '#required' => TRUE,
    );

    $form['grid'] = array(
      '#type' => 'select',
      '#title' => t('Count of blocks in a row'),
      '#options' => array(1 => '1', 2 => '2', 3 => '3', 4 => '4'),
      '#default_value' => !empty($service->grid) ? $service->grid : '3',
      '#required' => TRUE,
    );

    field_attach_form('sl7_advantage_service', $service, $form, $form_state);

    $form['actions'] = array(
      '#type' => 'actions',
    );
    $form['actions']['submit'] = array(
      '#type'   => 'submit',
      '#value'  => !empty($service->sid) ? t('Save') : t('Create'),
      '#weight' => 0,
    );
    $form['actions']['delete'] = array(
      '#markup' => !empty($service->sid) ? l(t('Delete'), $service->realPath() . '/delete', array('attributes' => array('class' => array('button remove')), 'query' => array('destination' => SL7_ADVANTAGE_ADMIN_PATH))) : '',
    );

    return $form;
  }

  public function formValidate($form, &$form_state) {

  }

  public function formSubmit($form, &$form_state) {
    $service = $this->entityFormSubmitBuildEntity($form, $form_state);
    $label = check_plain($service->label);
    $service->save();

    $form_state['redirect'] = $service->realPath();

    if (!empty($service->is_new)) {
      drupal_set_message("Advantage @label created.", array('@label' => $label));
    }
    else {
      drupal_set_message("Advantage @label saved.", array('@label' => $label));
    }
  }

  public function deleteForm($form, &$form_state) {
    $service = $form_state['sl7_advantage_service'];
    $label = check_plain($service->label);

    $form = confirm_form($form,
    	t("This will remove all blocks in this advantage. Are you sure about removing the advantages of @label", array('@label' => $label)),
      SL7_ADVANTAGE_ADMIN_PATH,
      '<p>' . t('The deletion can not be undone.') . '</p>',
      t('Delete'),
      t('Cancel'),
      'confirm'
    );

    return $form;
  }

  public function deleteFormSubmit($form, &$form_state) {
    $service = $form_state['sl7_advantage_service'];
    $label = check_plain($service->label);

    sl7_advantage_service_delete($service);

    drupal_set_message(t("Advantage @label deleted.", array('@label' => $label)));

    $form_state['redirect'] = SL7_ADVANTAGE_ADMIN_PATH;
  }
}

function sl7_advantage_service_edit_form($form, &$form_state) {
  return entity_ui_controller($form_state['entity_type'])->form($form, $form_state);
}

function sl7_advantage_service_edit_form_validate($form, &$form_state) {
  entity_ui_controller($form_state['entity_type'])->formValidate($form, $form_state);
}

function sl7_advantage_service_edit_form_submit($form, &$form_state) {
  entity_ui_controller($form_state['entity_type'])->formSubmit($form, $form_state);
}

function sl7_advantage_service_delete_form($form, &$form_state, $service) {
  $entity_type = 'sl7_advantage_service';
  $form_state['entity_type'] = $entity_type;
  $form_state[$entity_type] = is_object($service) ? $service : sl7_advantage_service_load($service);
  return entity_ui_controller($form_state['entity_type'])->deleteForm($form, $form_state);
}

function sl7_advantage_service_delete_form_submit($form, &$form_state) {
  entity_ui_controller($form_state['entity_type'])->deleteFormSubmit($form, $form_state);
}

function sl7_advantage_service_get_edit_form($op = 'create', $service = NULL) {
  $form_state = array(
    'entity_type' => 'sl7_advantage_service',
    'op' => $op,
  );

  switch ($op) {
    case 'create':
      drupal_set_title(t('Create Advantage'));
      $form_state['sl7_advantage_service'] = sl7_advantage_service_create();
      break;
    case 'edit':
      $form_state['sl7_advantage_service'] = is_object($service) ? $service : sl7_advantage_service_load($service);
      drupal_set_title(t('Edit of ') . $form_state['sl7_advantage_service']->label);
      break;
    default:
      $form_state['sl7_advantage_service'] = is_object($service) ? $service : sl7_advantage_service_load($service);
      break;
  }

  form_load_include($form_state, 'inc', 'sl7_advantage_service', 'includes/sl7_advantage_service.ui');

  $form_state['build_info']['args'] = array($op, $service);

  return drupal_build_form('sl7_advantage_service_edit_form', $form_state);
}