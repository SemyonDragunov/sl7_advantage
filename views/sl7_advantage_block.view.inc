<?php

$view = new view();
$view->name = 'sl7_advantage_block';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'sl7_advantage_block';
$view->human_name = t('Advantage - block');
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Advantage section';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'more';
$handler->display->display_options['access']['type'] = 'perm';
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
/* Поле: Преимущества - блок: Идентификатор Преимущества - Block */
$handler->display->display_options['fields']['bid']['id'] = 'bid';
$handler->display->display_options['fields']['bid']['table'] = 'sl7_advantage_block';
$handler->display->display_options['fields']['bid']['field'] = 'bid';
$handler->display->display_options['fields']['bid']['label'] = 'ID';
$handler->display->display_options['fields']['bid']['separator'] = '';

/* Display: Advantage page */
$handler = $view->new_display('page', 'Advantage page', 'service_manage_page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Advantage page';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'sl7_advantage administer';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* Поведение при отсутствии результатов: Глобальный: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['label'] = 'Нет пунктов';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'В данном преимуществе more нет пунктов. Создайте пункт через вкладку вверху страницы.';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Поле: Преимущества - блок: Идентификатор Преимущества - Block */
$handler->display->display_options['fields']['bid']['id'] = 'bid';
$handler->display->display_options['fields']['bid']['table'] = 'sl7_advantage_block';
$handler->display->display_options['fields']['bid']['field'] = 'bid';
$handler->display->display_options['fields']['bid']['label'] = 'ID';
$handler->display->display_options['fields']['bid']['exclude'] = TRUE;
$handler->display->display_options['fields']['bid']['separator'] = '';
$handler->display->display_options['fields']['bid']['prefix'] = 'Block ';
/* Поле: Draggableviews: Преимущества - Block */
$handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
$handler->display->display_options['fields']['draggableviews']['table'] = 'sl7_advantage_block';
$handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
$handler->display->display_options['fields']['draggableviews']['label'] = '';
$handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Сохранить';
$handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
/* Поле: Преимущества - блок: Заголовок */
$handler->display->display_options['fields']['sl7_advantage_title']['id'] = 'sl7_advantage_title';
$handler->display->display_options['fields']['sl7_advantage_title']['table'] = 'field_data_sl7_advantage_title';
$handler->display->display_options['fields']['sl7_advantage_title']['field'] = 'sl7_advantage_title';
$handler->display->display_options['fields']['sl7_advantage_title']['label'] = '';
$handler->display->display_options['fields']['sl7_advantage_title']['exclude'] = TRUE;
$handler->display->display_options['fields']['sl7_advantage_title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['sl7_advantage_title']['type'] = 'text_plain';
$handler->display->display_options['fields']['sl7_advantage_title']['settings'] = array(
  'trim_length' => '150',
);
/* Поле: Преимущества - блок: Изображение */
$handler->display->display_options['fields']['sl7_advantage_image']['id'] = 'sl7_advantage_image';
$handler->display->display_options['fields']['sl7_advantage_image']['table'] = 'field_data_sl7_advantage_image';
$handler->display->display_options['fields']['sl7_advantage_image']['field'] = 'sl7_advantage_image';
$handler->display->display_options['fields']['sl7_advantage_image']['label'] = '';
$handler->display->display_options['fields']['sl7_advantage_image']['exclude'] = TRUE;
$handler->display->display_options['fields']['sl7_advantage_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['sl7_advantage_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['sl7_advantage_image']['settings'] = array(
  'image_style' => 'thumbnail',
  'image_link' => '',
);
/* Поле: Преимущества - блок: Описание */
$handler->display->display_options['fields']['sl7_advantage_body']['id'] = 'sl7_advantage_body';
$handler->display->display_options['fields']['sl7_advantage_body']['table'] = 'field_data_sl7_advantage_body';
$handler->display->display_options['fields']['sl7_advantage_body']['field'] = 'sl7_advantage_body';
$handler->display->display_options['fields']['sl7_advantage_body']['label'] = '';
$handler->display->display_options['fields']['sl7_advantage_body']['exclude'] = TRUE;
$handler->display->display_options['fields']['sl7_advantage_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['sl7_advantage_body']['type'] = 'text_trimmed';
$handler->display->display_options['fields']['sl7_advantage_body']['settings'] = array(
  'trim_length' => '70',
);
/* Поле: Глобальный: Пользовательский текст */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[sl7_advantage_title]<br />
[sl7_advantage_image]<br />
[sl7_advantage_body]';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Поле: Преимущества - блок: Действия */
$handler->display->display_options['fields']['operations']['id'] = 'operations';
$handler->display->display_options['fields']['operations']['table'] = 'sl7_advantage_block';
$handler->display->display_options['fields']['operations']['field'] = 'operations';
$handler->display->display_options['fields']['operations']['label'] = '';
$handler->display->display_options['fields']['operations']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Критерий сортировки: Draggableviews: Вес */
$handler->display->display_options['sorts']['weight']['id'] = 'weight';
$handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
$handler->display->display_options['sorts']['weight']['field'] = 'weight';
$handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'sl7_advantage_block:page_1';
$handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Контекстный фильтр: Преимущества - блок: ID преимущества */
$handler->display->display_options['arguments']['sid']['id'] = 'sid';
$handler->display->display_options['arguments']['sid']['table'] = 'sl7_advantage_block';
$handler->display->display_options['arguments']['sid']['field'] = 'sid';
$handler->display->display_options['arguments']['sid']['default_action'] = 'default';
$handler->display->display_options['arguments']['sid']['exception']['title'] = 'Все';
$handler->display->display_options['arguments']['sid']['default_argument_type'] = 'raw';
$handler->display->display_options['arguments']['sid']['default_argument_options']['index'] = '3';
$handler->display->display_options['arguments']['sid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['sid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['sid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['path'] = '-';
$translatables['sl7_advantage_block'] = array(
  t('Master'),
  t('Advantage section'),
  t('more'),
  t('Apply'),
  t('Clear'),
  t('Sort'),
  t('Ascending'),
  t('Descending'),
  t('ID'),
  t('.'),
  t('Advantage page'),
  t('No blocks'),
  t('In this Advantage there are no blocks. Create a block through the tab at the top.'),
  t('Block '),
  t('[sl7_advantage_title]<br />
[sl7_advantage_image]<br />
[sl7_advantage_body]'),
  t('Все'),
);
