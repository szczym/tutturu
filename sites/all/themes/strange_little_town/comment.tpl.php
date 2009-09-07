<?php
// $Id: comment.tpl.php,v 1.1.2.4 2009/02/21 17:20:46 gibbozer Exp $

/**
 * @file comment.tpl.php
 * Default theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: Body of the post.
 * - $date: Date and time of posting.
 * - $links: Various operational links.
 * - $new: New comment marker.
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $submitted: By line with date and time.
 * - $title: Linked title.
 *
 * These two variables are provided for context.
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * @see template_preprocess_comment()
 * @see theme_comment()
 */
?>
<div class="comment <?php print comment_classes($comment) .' '. $zebra .' '. $status ?> clear-block">

  <?php if ($title): ?>
    <h3 class="title"><?php print $title ?>
      <?php if ($comment->new): ?><span class="new"><?php print $new ?></span><?php endif; ?>
    </h3>
  <?php endif; ?>

  <div class="comment-info clear-block">

    <?php if ($submitted): ?>
        <span class="submitted">
          <?php print str_replace('(not verified)', '(visitor)', $author); ?>
          <span class="post-date"><?php print (format_date($comment->timestamp, 'custom', 'F jS, Y g:i A O')); ?></span>
        </span>

    <?php endif; ?>

  </div>

  <div class="content">
    <?php if ($picture): ?><?php print $picture ?><?php endif; ?>

    <?php print $content ?>
    <?php if ($signature): ?>
    <div class="user-signature clear-block">
      <?php print $signature ?>
    </div>
    <?php endif; ?>
  </div>

  <?php if ($links): ?>
    <?php print $links ?>
  <?php endif; ?>  
</div>