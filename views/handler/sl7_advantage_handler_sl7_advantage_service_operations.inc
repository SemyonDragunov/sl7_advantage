<?php

class sl7_advantage_handler_sl7_advantage_service_operations extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['sid'] = 'sid';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $sid = $this->get_value($values, 'sid');
    $service = sl7_advantage_service_load($sid);
    $links = array();

    if (sl7_advantage_service_access('administer', $service)) {
      $links['edit'] = array(
        'title' => t('Edit'),
        'href'  => SL7_ADVANTAGE_ADMIN_PATH . '/' . $sid . '/edit',
        'html'  => FALSE,
      );
      $links['edit']['query'] = drupal_get_destination();
    }

    if (sl7_advantage_block_access('administer')) {
      $links['create'] = array(
        'title' => t('Create service'),
        'href'  => SL7_ADVANTAGE_ADMIN_PATH . '/' . $sid . '/add',
        'html'  => FALSE,
      );
      $links['delete']['query'] = drupal_get_destination();
    }

    if (sl7_advantage_service_access('administer', $service)) {
      $links['delete'] = array(
        'title' => t('Delete'),
        'href'  => SL7_ADVANTAGE_ADMIN_PATH . '/' . $sid . '/delete',
        'html'  => FALSE,
      );
      $links['delete']['query'] = drupal_get_destination();
    }

    return theme('links__ctools_dropbutton', array(
      'links' => $links,
      'attributes' => array(
        'class' => array('links', 'inline', 'operations')
      )
    ));
  }
}