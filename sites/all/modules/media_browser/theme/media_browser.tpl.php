<?php 
  switch ($options['position']) {
    
    default:
    case 'right':
      $top = '<tr><td width="60%" valign="top">';
      $middle = '</td><td width="40%" valign="top">';
      $bottom = '</td></tr>';
      $first = $attachment;
      $second = $rows;
      break;
    case 'left':
      $top = '<tr><td width="40%" valign="top">';
      $middle = '</td><td width="60%" valign="top">';
      $bottom = '</td></tr>';
      $first = $rows;
      $second = $attachment;
      break;
   	case 'top':
      $top = '<tr><td valign="top">';
      $middle = '</td></tr><tr><td valign="top">';
      $bottom = '</td></tr>';
      $first = $rows;
      $second = $attachment;
      break;
    case 'bottom':
      $top = '<tr><td valign="top">';
      $middle = '</td></tr><tr><td valign="top">';
      $bottom = '</td></tr>';
      $first = $attachment;
      $second = $rows;
      break;
  }
?>

<div>

  <table class="media_browser_container position_<?php print $options['position']; ?>">
    <tbody>
     <?php print $top; ?>
        <div class="media_browser_attachment <?php print $options['class']; ?>">
          <?php print $first; ?>
        </div>
     <?php print $middle; ?>
        <div class="media_browser_list"> 
          <?php print $second; ?>        
        </div> 
     <?php print $bottom; ?>
    </tbody>
  </table>

</div>