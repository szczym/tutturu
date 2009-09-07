<?php
// $Id: node.tpl.php,v 1.1.2.3 2009/02/12 20:26:23 gibbozer Exp $
?><div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">

  <?php if (!$page): ?>
    <h2 class="title">
      <a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a>
    </h2>
  <?php endif; ?>

  <div class="post-info clear-block">

    <?php if ($submitted): ?>
        <span class="submitted">
          <span class="post-date"><?php print (format_date($node->created, 'custom', 'F jS, Y')) ?></span>
          <span class="time-author">Posted <?php print (format_date($node->created, 'custom', 'g:i A O')) ?> by <?php print $name ?></span>
        </span>

        <?php if($comments_count): ?>
          <span class="commments-count">
	        <a rel="nofollow" href="comment/reply/<?php print $nid ?>/#comment-form" title="<?php print t('Quick Reply to this post') ?>"><?php print $comments_count ?></a>
	      </span>
        <?php endif; ?>

    <?php endif; ?>

  </div>

  <div class="content">
    <?php if ($picture): ?><?php print $picture ?><?php endif; ?>
    <?php print $content ?>
  </div>

  <div class="terms-links">

  <?php if ($terms): ?>
    <div class="terms"> <?php print t('Tags') ?> : <?php print $terms ?></div>
  <?php endif; ?>


    <?php if ($links): ?>
      <div class="node-links">
        <?php print $links; ?>
      </div>
    <?php endif; ?>

  </div>
</div>