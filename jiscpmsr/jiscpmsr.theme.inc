<?php
/**
 * @file
 * JISC PM SR theme.
 */

/**
 * @function
 * Lists all SRs.
 */
function theme_jiscpmsr_list($header, $srs) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm.css', 'module');
}
/**
 * @function
 * Provides a view with all content fields for a status report.
 */
function theme_jiscpmsr_view($node, $teaser = FALSE, $page = FALSE) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');
  $node = node_prepare($node, $teaser);
  $node->content['group1'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );
  $loadproject = node_load($node->jiscpmsrs[0]['project_nid']);
  $node->content['group1']['project'] = array(
    '#prefix' => '<div class="project">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Project'), l($loadproject->title, 'node/' . $loadproject->nid)),
    '#weight' => -20,
  );
  // Load project manager info and display.
  $project_manager = array();
  $results = db_query('SELECT project_manager_uid FROM {jiscpmproject} WHERE nid = %d', $loadproject->nid);
  while ($rows = db_fetch_object($results)) {
    $project_manager = user_load($rows->project_manager_uid);
  }
  if ($project_manager->uid != -1) {
    $node->content['projectmanager'] = array(
      '#prefix' => '<div class="jiscpmfields">',
      '#suffix' => '</div>',
      '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'projectmanager') : -19,
      '#value' => theme('jiscpm_view_item', t('Project Manager'), l($project_manager->name, 'user/' . $project_manager->uid)),
    );
  }
  else {
  }
  $node->content['group3'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group3') : -18,
  );
  $node->content['group3']['sr_product_process'] = array(
    '#value' => theme('jiscpm_view_item', t('Product/Process'), $node->jiscpmsrs[0]['sr_product_process']),
  );
  $node->content['group2'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -17,
  );
  $node->content['group2']['sr_focus_area'] = array(
    '#value' => theme('jiscpm_view_item', t('Focus Area'), $node->jiscpmsrs[0]['sr_focus_area']),
    '#weight' => 1,
  );
  $node->content['group9'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group9') : -16,
  );
  $node->content['group9']['sr_start'] = array(
    '#value' => theme('jiscpm_view_item', t('Start of reporting period'), date('d-m-Y', $node->jiscpmsrs[0]['sr_start'])),
    '#weight' => 0,
  );
  $node->content['group9']['sr_end'] = array(
    '#value' => theme('jiscpm_view_item', t('End of reporting period'), date('d-m-Y', $node->jiscpmsrs[0]['sr_end'])),
    '#weight' => 1,
  );
  $node->content['group4'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group4') : -15,
  );
  $node->content['group4']['sr_overview'] = array(
    '#value' => theme('jiscpm_view_item', t('Status Report Overview'), check_markup($node->jiscpmsrs[0]['sr_overview'], FILTER_FORMAT_DEFAULT, FALSE)),
  );
  $node->content['group11'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group11') : -14,
  );
  $node->content['group11']['sr_overall_status'] = array(
    '#value' => theme('jiscpm_view_item', t('Overall Status'), check_markup($node->jiscpmsrs[0]['sr_overall_status'], FILTER_FORMAT_DEFAULT, FALSE)),
  );
  $node->content['group12'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group12') : -13,
  );
  $node->content['group12']['sr_project_summary'] = array(
    '#value' => theme('jiscpm_view_item', t('Project Summary'), check_markup($node->jiscpmsrs[0]['sr_project_summary'], FILTER_FORMAT_DEFAULT, FALSE)),
  );
  $node->content['group5'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -12,
  );
  $node->content['group5']['sr_milestone_report'] = array(
    '#value' => theme('jiscpm_view_item', t('Milestone Report'), check_markup($node->jiscpmsrs[0]['sr_milestone_report'], FILTER_FORMAT_DEFAULT, FALSE)),
    '#weight' => 1,
  );
  $node->content['group5']['sr_risk_management_report'] = array(
    '#value' => theme('jiscpm_view_item', t('Risk Management Report'), check_markup($node->jiscpmsrs[0]['sr_risk_management_report'], FILTER_FORMAT_DEFAULT, FALSE)),
    '#weight' => 2,
  );
  $node->content['group5']['sr_issues_report'] = array(
    '#value' => theme('jiscpm_view_item', t('Issues Report'), check_markup($node->jiscpmsrs[0]['sr_issues_report'], FILTER_FORMAT_DEFAULT, FALSE)),
    '#weight' => 3,
  );
  $node->content['group8'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group8') : -11,
  );
  $node->content['group8']['sr_project_recommendations'] = array(
    '#value' => theme('jiscpm_view_item', t('Project Recommendations'), check_markup($node->jiscpmsrs[0]['sr_project_recommendations'])),
  );
  $node->content['group13'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group13') : -10,
  );
  $node->content['group13']['sr_objectives_for_next_sr'] = array(
    '#value' => theme('jiscpm_view_item', t('Objectives for Next Status Report'), check_markup($node->jiscpmsrs[0]['sr_objectives_for_next_sr'], FILTER_FORMAT_DEFAULT, FALSE)),
  );
  $node->content['group14'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group14') : -9,
  );
  $node->content['group14']['sr_related_project_information'] = array(
    '#value' => theme('jiscpm_view_item', t('Related Project Information'), check_markup($node->jiscpmsrs[0]['sr_related_project_information'], FILTER_FORMAT_DEFAULT, FALSE)),
  );
  return $node;
}
