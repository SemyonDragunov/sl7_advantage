<?php

/**
 * Preprocess for sl7-advantage-service.tpl.php
 */
function template_preprocess_sl7_advantage_service(&$variables) {
  $variables['blocks'] = sl7_advantage_block_load_multiple(FALSE, array('sid' => $variables['element']->sid));
  $variables['output_blocks'] = array();

  foreach ($variables['blocks'] as $bid => $block) {
    // Weight.
    $weight = sl7_advantage_block_get_weight($bid);
    while (isset($variables['output_blocks'][$weight])) {
      $weight++;
    }
    $variables['output_blocks'][$weight] = $block;

    // Fields.
    foreach ($block as $name => $value) {
      if (preg_match('/sl7_advantage_|field_/', $name)) {
        $variables['blocks_content'][$bid][$name] = field_view_field('sl7_advantage_block', $block, $name, array('label' => 'hidden'));
      }
    }
    rsort($variables['blocks_content'][$bid]);
  }

  ksort($variables['output_blocks']);
}