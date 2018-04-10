<?php

class SL7AdvantageService extends Entity
{
  public function __construct($values = array()) {
    parent::__construct($values, 'sl7_advantage_service');
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }

  public function defaultLabel() {
    return $this->label;
  }

  public function defaultUri() {
    return array('path' => $this->realPath());
  }

  public function realPath() {
    return SL7_ADVANTAGE_ADMIN_PATH . '/' . $this->identifier();
  }
}

class SL7AdvantageServiceController extends EntityAPIController
{
  public function __construct($entityType) {
    parent::__construct($entityType);
  }

  public function create(array $values = array()) {
    global $user;

    $values += array(
      'sid' => '',
      'is_new' => TRUE,
      'label' => '',
      'uid' => $user->uid,
      'grid' => 3,
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
    );

    return parent::create($values);
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (empty($entity->is_new)) $entity->changed = REQUEST_TIME;
    return parent::save($entity, $transaction);
  }
}

class SL7AdvantageServiceMetadataController extends EntityDefaultMetadataController
{
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();

    $properties = &$info[$this->type]['properties'];

    $properties['label']['label'] = t('Advantage title');

    $properties['uid'] = array(
    	'label' => t('Creator'),
      'description' => t('Username of the user who created the Advantage.'),
      'type' => 'user',
      'computed' => TRUE,
      'entity views field' => TRUE,
    );

    $properties['grid'] = array(
      'label' => t('Count of blocks in a row'),
      'description' => t('How many blocks will be displayed on a large monitor in a row.'),
      'type' => 'integer',
      'computed' => TRUE,
      'entity views field' => TRUE,
    );

    $properties['created']['type'] = 'date';
    $properties['created']['label'] = t('Date of creation');
    $properties['created']['description'] = t('Time to create the Advantage.');

    $properties['changed']['type'] = 'date';
    $properties['changed']['label'] = t('Last Modified');
    $properties['changed']['description'] = t('Date and time of the last Advantage change.');

    return $info;
  }
}

class SL7AdvantageServiceViewsController extends EntityDefaultViewsController {

  public function views_data() {
    $data = parent::views_data();

    $data['sl7_advantage_service']['operations'] = array(
      'field' => array(
      	'title' => t('Operations'),
      	'help' => t('Shows all possible operations.'),
        'handler' => 'sl7_advantage_handler_sl7_advantage_service_operations',
      ),
    );

    return $data;
  }
}