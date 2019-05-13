<?php
/**
 * Implements hook_views_data().
 */
function phu_views_views_data() {
  $data['phu_views_views_data']['table']['group'] = t('Phu custom field');
  $data['phu_views_views_data']['table']['join'] = array(
    // Exist in all views.
    '#global' => array(),
  );

  $data['phu_views_views_data']['phu_total_comments_custom_field'] = array(
    'title' => t('Phu total comments custom field'),
    'help' => t('Total comments of node'),
    'field' => array(
      'handler' => 'views_handler_phu_total_comments_custom_field',
    ),
  );

  return $data;
}
