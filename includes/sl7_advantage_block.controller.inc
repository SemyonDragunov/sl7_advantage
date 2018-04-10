<?php

class SL7AdvantageBlock extends Entity
{
  public function __construct($values = array()) {
    parent::__construct($values, 'sl7_advantage_block');
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }

  protected function defaultLabel() {
    return $this->bid;
  }

  protected function defaultUri() {
    return array('path' => $this->realPath());
  }

  public function realPath() {
    return SL7_ADVANTAGE_ADMIN_PATH . '/%/' . $this->identifier();
  }
}

class SL7AdvantageBlockController extends EntityAPIController
{
  public function __construct($entityType) {
    parent::__construct($entityType);
  }

  public function create(array $values = array()) {
    global $user;

    $values += array(
      'bid' => '',
      'sid' => '',
      'is_new' => TRUE,
      'uid' => $user->uid,
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

class SL7AdvantageBlockMetadataController extends EntityDefaultMetadataController
{
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();

    $properties = &$info[$this->type]['properties'];

    $properties['uid'] = array(
      'label' => t('Creator'),
      'description' => t('Username of the user who created the block.'),
      'type' => 'user',
      'computed' => TRUE,
      'entity views field' => TRUE,
    );

    $properties['sid']['type'] = 'integer';
    $properties['sid']['label'] = t('ID Advantage');
    $properties['sid']['description'] = t('ID Advantages of this block.');

    $properties['created']['type'] = 'date';
    $properties['created']['label'] = t('Date of creation');
    $properties['created']['description'] = t('Time to create the block.');

    $properties['changed']['type'] = 'date';
    $properties['changed']['label'] = t('Last Modified');
    $properties['changed']['description'] = t('Date and time of the last block change.');

    return $info;
  }
}

class SL7AdvantageBlockViewsController extends EntityDefaultViewsController {

  public function views_data() {
    $data = parent::views_data();

    $data['sl7_advantage_block']['operations'] = array(
      'field' => array(
        'title' => t('Operations'),
        'help' => t('Shows all possible operations.'),
        'handler' => 'sl7_advantage_handler_sl7_advantage_block_operations',
      ),
    );

    return $data;
  }
}