<?php
/**
 * @file
 */

/**
 * @function
 * Implements hook_views_data().
 */
function jiscpmteam_views_data() {
  $data['jiscpmteam']['table']['group']  = 'jiscpm';
  $data['jiscpmteam']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );
  $data['jiscpmteam']['members'] = array(
    'title' => t('Team Members'),
    'help' => 'jiscpm Team Members',
    'field' => array(
      'handler' => 'jiscpmteam_handler_field_teammembers',
      'click sortable' => FALSE,
    ),
  );
  return $data;
}
/**
 * @function
 * Implements hook_views_handlers().
 */
function jiscpmteam_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'jiscpmteam'),
    ),
    'handlers' => array(
      'jiscpmteam_handler_field_teammembers' => array(
        'parent' => 'views_handler_field_prerender_list',
      ),
    ),
  );
}
