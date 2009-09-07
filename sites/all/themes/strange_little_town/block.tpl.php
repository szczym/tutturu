<?php
// $Id: block.tpl.php,v 1.1.2.1 2009/02/11 11:50:42 gibbozer Exp $
?>
<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="block block-<?php print $block->module ?>">
<?php if ($block->subject): ?>
  <h2 class="block-title"><?php print $block->subject ?></h2>
<?php endif;?>

  <div class="content">
    <?php print $block->content ?>
  </div>
</div>