<?php

$view = new view();
$view->name = 'sl7_advantage_service';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'sl7_advantage_service';
$view->human_name = t('Advantage - service');
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Descending';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'more';
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Apply';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sort';
$handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'label' => 'label',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'label' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['sticky'] = TRUE;
/* Поле: Преимущества - услуга: Название преимущества */
$handler->display->display_options['fields']['label']['id'] = 'label';
$handler->display->display_options['fields']['label']['table'] = 'sl7_advantage_service';
$handler->display->display_options['fields']['label']['field'] = 'label';
$handler->display->display_options['fields']['label']['label'] = 'Advantage';
/* Критерий сортировки: Преимущества - услуга: Дата создания */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'sl7_advantage_service';
$handler->display->display_options['sorts']['created']['field'] = 'created';

/* Display: Descending */
$handler = $view->new_display('page', 'Descending', 'manage_page');
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'sl7_advantage administer';
$handler->display->display_options['defaults']['header'] = FALSE;
/* Шапка: Глобальный: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['label'] = 'Customize display';
$handler->display->display_options['header']['area']['content'] = '<p><a href="/admin/structure/block">Customize the display of benefits on the page. </a></p>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* Поведение при отсутствии результатов: Глобальный: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['label'] = 'Not Advantage';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = '<p>Not Advantage. <a href="/admin/control-panel/apps/advantage/add">Create.</a></p>';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Поле: Преимущества - услуга: Идентификатор Преимущества - услуга */
$handler->display->display_options['fields']['sid']['id'] = 'sid';
$handler->display->display_options['fields']['sid']['table'] = 'sl7_advantage_service';
$handler->display->display_options['fields']['sid']['field'] = 'sid';
$handler->display->display_options['fields']['sid']['label'] = '';
$handler->display->display_options['fields']['sid']['exclude'] = TRUE;
$handler->display->display_options['fields']['sid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['sid']['separator'] = '';
/* Поле: Преимущества - услуга: URL */
$handler->display->display_options['fields']['url']['id'] = 'url';
$handler->display->display_options['fields']['url']['table'] = 'views_entity_sl7_advantage_service';
$handler->display->display_options['fields']['url']['field'] = 'url';
$handler->display->display_options['fields']['url']['label'] = '';
$handler->display->display_options['fields']['url']['exclude'] = TRUE;
$handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
$handler->display->display_options['fields']['url']['link_to_entity'] = 0;
/* Поле: Преимущества - услуга: Название преимущества */
$handler->display->display_options['fields']['label']['id'] = 'label';
$handler->display->display_options['fields']['label']['table'] = 'sl7_advantage_service';
$handler->display->display_options['fields']['label']['field'] = 'label';
$handler->display->display_options['fields']['label']['label'] = 'Advantage';
$handler->display->display_options['fields']['label']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['label']['alter']['path'] = '[url]';
/* Поле: Преимущества - услуга: Действия */
$handler->display->display_options['fields']['operations']['id'] = 'operations';
$handler->display->display_options['fields']['operations']['table'] = 'sl7_advantage_service';
$handler->display->display_options['fields']['operations']['field'] = 'operations';
$handler->display->display_options['fields']['operations']['label'] = '';
$handler->display->display_options['fields']['operations']['element_label_colon'] = FALSE;
$handler->display->display_options['path'] = '-';
$translatables['sl7_advantage_service'] = array(
  t('Master'),
  t('Descending'),
  t('more'),
  t('Apply'),
  t('Clear'),
  t('Sort'),
  t('Ascending'),
  t('Descending'),
  t('Advantage'),
  t('Customize display'),
  t('<p><a href="/admin/structure/block">Customize the display of benefits on the page. </a></p>'),
  t('Not Advantage'),
  t('<p>Not Advantage. <a href="/admin/control-panel/apps/advantage/add">Create.</a></p>'),
  t('.'),
);
