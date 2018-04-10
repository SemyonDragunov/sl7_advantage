<div class="sl7-advantage-service-section col-<?php print $element->grid; ?>">
  <?php print render($title_prefix); ?>

  <?php foreach ($output_blocks as $weight => $block): ?>
    <div class="item block-<?php echo $block->bid; ?>">
      <?php print drupal_render($blocks_content[$block->bid]); ?>
    </div>
  <?php endforeach; ?>

  <?php print render($title_suffix); ?>
</div>