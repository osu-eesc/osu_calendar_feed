<?php
// $Id: node.tpl.php,v 1.1.2.2 2009/11/11 05:26:25 sociotech Exp $
?>

<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">
  <div class="inner">
    <?php print $picture ?>
  
    <?php if ($page == 0): ?>
    <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
    <?php endif; ?>
  
    <?php if ($submitted): ?>
    <div class="meta">
      <span class="submitted"><?php print $submitted ?></span>
    </div>
    <?php endif; ?>
  
    <?php if ($node_top && !$teaser): ?>
    <div id="node-top" class="node-top row nested">
      <div id="node-top-inner" class="node-top-inner inner">
        <?php print $node_top; ?>
      </div><!-- /node-top-inner -->
    </div><!-- /node-top -->
    <?php endif; ?>

    <div class="content clearfix">
    
      <div class="calendar-event-date">

      <?php // print dsm($node); ?>

        <fieldset class="fieldgroup calendar-event-details">
          <legend>Event details</legend>
          <?php  print '<div class="calendar-date">' . $node->field_osu_calendar_date['0']['view'] . '</div>'; ?>
          <?php  if($field_osu_calendar_allday['0']['view'] == 'yes'): ; ?>
            <?php print ' <span class="allday label">(all day)</span>'; ?>
          <?php endif; ?> 

          <?php
            if ($node->field_osu_calendar_description['0']['value']) {
              print '<div class="calendar-event-description">' . $node->field_osu_calendar_description['0']['view'] . '</div>';
            }
            ?>

            <div class="calendar-event-cost"><span class="cost-label label"> Cost:</span>
            <?php
              if ($node->field_osu_calendar_cost['0']['value'] && $node->field_osu_calendar_cost['0']['value'] >= 0.01){
                print ' $' . $node->field_osu_calendar_cost['0']['view'];
              } else {
                print ' free';
              }
              ?>
            </div>

          </fieldset>

          <?php
            if ($node->field_osu_calendar_location['0']['value'] || $node->field_osu_calendar_room['0']['value'] || $node->field_osu_calendar_address['0']['value'] || $node->field_osu_calendar_city['0']['value']) {
              print '<fieldset class="fieldgroup calendar-event-contact-info"><legend>Location</legend>' ;
            }

            if ($node->field_osu_calendar_location['0']['value']){
              print ' ' . $node->field_osu_calendar_location['0']['view'];
            }
            if ($node->field_osu_calendar_room['0']['value']){
              print '<div class="calendar-event-room">Room ' . $node->field_osu_calendar_room['0']['view'] . '</div>';
            }
            
            print '<div class="calendar-event-address">';
            
            if ($node->field_osu_calendar_address['0']['value']) {
              print '<span class="street-address">' . $node->field_osu_calendar_address['0']['view'] . '</span><br />';
            }
            if ($node->field_osu_calendar_city['0']['value']){
              print '<span class="city">' . $node->field_osu_calendar_city['0']['view'] . '</span>';
            }
            if ($node->field_osu_calendar_state['0']['value']){
              print '<span class="state"> ' . $node->field_osu_calendar_state['0']['view'] . '</span>';
            }
            
            print '</div><!-- calendar-event-address -->';

            if ($node->field_osu_calendar_location['0']['value'] || $node->field_osu_calendar_room['0']['value'] || $node->field_osu_calendar_address['0']['value'] || $node->field_osu_calendar_city['0']['value']) {
              print '</fieldset>';
            }
          ?>

          <?php
            if ($node->field_osu_calendar_contact['0']['value'] || $node->field_osu_calendar_phone['0']['value'] || $node->field_osu_calendar_email['0']['email']) {
            print '<fieldset class="fieldgroup calendar-event-contact-info"><legend>For more information contact</legend>';
            }
            if ($node->field_osu_calendar_contact['0']['value']){
              print '<div class="calendar-event-contact-name">' . $node->field_osu_calendar_contact['0']['view'] . '</div>';
            }
            if ($node->field_osu_calendar_phone['0']['value']){
              print '<div class="calendar-event-phone">' . $node->field_osu_calendar_phone['0']['view'] . '</div>';
            }
            if ($node->field_osu_calendar_email['0']['email']){
              if ($node->field_osu_calendar_contact['0']['value']){
                print '<div class="calendar-event-email"><a href="/email/' . $node->nid . '/field_osu_calendar_email">Send ' . $node->field_osu_calendar_contact['0']['view'] . ' an email</a></div>';
              } 
              else {
                print '<div class="calendar-event-email"><a href="/email/' . $node->nid . '/field_osu_calendar_email">Send event contact an email</a></div>';
              }
            }
            if ($node->field_osu_calendar_contact['0']['value'] || $node->field_osu_calendar_phone['0']['value'] || $node->field_osu_calendar_email['0']['email']) {
              print '</fieldset>' ;
            }
          ?>  
          
        </div><!-- calendar-event-date -->
    </div><!-- content clearfix -->
  
    <?php if ($terms): ?>
    <div class="terms">
      <?php // print $terms; ?>
    </div>
    <?php endif;?>
    
    <?php if ($links): ?>
    <div class="links">
      <?php print $links; ?>
    </div>
    <?php endif; ?>
  </div><!-- /inner -->

  <?php if ($node_bottom && !$teaser): ?>
  <div id="node-bottom" class="node-bottom row nested">
    <div id="node-bottom-inner" class="node-bottom-inner inner">
      <?php print $node_bottom; ?>
    </div><!-- /node-bottom-inner -->
  </div><!-- /node-bottom -->
  <?php endif; ?>
</div><!-- /node-<?php print $node->nid; ?> -->
