<?php
/**
 * @file
 * JISC PM risk theme.
 */

/**
 * @function
 * Lists all risks.
 */
function theme_jiscpmrisk_list($header, $risks) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm.css', 'module');
  $rows = array();
  foreach ($risks as $key => $risk) {
    $rows[] = array(
      jiscpm_icon('riskcategory_' . $risk->riskcategory, $risk->riskcategory),
      l($risk->title, 'node/' . $risk->nid) . theme('mark', node_mark($risk->nid, $risk->changed)),
      jiscpm_icon('status_' . $risk->riskstatus, $risk->riskstatus),
      jiscpm_icon('priority_' . $risk->riskpriority, $risk->riskpriority),
      array(
        'data' => jiscpm_icon_edit_node($risk, $_GET) . '&nbsp;' . jiscpm_icon_delete_node($risk, $_GET),
        'class' => 'jiscpm_list_operations',
      ),
    );
  }
  $o  = theme('table', $header, $rows);
  return $o;
}
/**
 * @function
 * View of a risk.
 */
function theme_jiscpmrisk_view($node, $teaser = FALSE, $page = FALSE) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');
  $node = node_prepare($node, $teaser);
  $node->content['group1'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );
  $loadproject = node_load($node->jiscpmrisks[0]['project_nid']);
  $node->content['group1']['project'] = array(
    '#prefix' => '<div class="project">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Project'), l($loadproject->title, 'node/' . $loadproject->nid)),
    '#weight' => 1,
  );
  $node->content['group2'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );
  $node->content['group2']['risk_probability'] = array(
    '#prefix' => '<strong>Risk Probability</strong><div class="riskprobability">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmrisks[0]['risk_probability'],
    '#weight' => 1,
  );
  $node->content['group3']['risk_impact'] = array(
    '#prefix' => '<strong>Risk Impact</strong><div class="riskimpact">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmrisks[0]['risk_impact'],
    '#weight' => 2,
  );
  $node->content['group4']['risk_timescale'] = array(
    '#prefix' => '<strong>Risk Timescale</strong><div class="risktimescale">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmrisks[0]['risk_timescale'],
    '#weight' => 3,
  );
  $node->content['group5'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -16,
  );
  $node->content['group5']['risk_residual'] = array(
    '#prefix' => '<strong>Residual Risk</strong><div class="riskresidual">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->jiscpmrisks[0]['risk_residual'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => 4,
  );
  $node->content['group6']['risk_early_warning_signs'] = array(
    '#prefix' => '<strong>Early Warning Signs</strong><div class="riskearlywarningsigns">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->jiscpmrisks[0]['risk_early_warning_signs'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => 5,
  );
  $loaduser = user_load($node->jiscpmrisks[0]['risk_owner_uid']);
  $node->content['group7']['risk_owner_uid'] = array(
    '#prefix' => '<strong>Risk Owner</strong><div class="riskowneruid">',
    '#suffix' => '</div>',
    '#value' => l($loaduser->name, 'user/' . $node->jiscpmrisks[0]['risk_owner_uid']),
    '#weight' => 6,
  );
  $node->content['group8']['risk_timescale'] = array(
    '#prefix' => '<strong>Risk Timescale</strong><div class="risktimescale">',
    '#suffix' => '</div>',
    '#value' => date('d-m-Y', $node->jiscpmrisks[0]['risk_start']) . ' to ' . date('d-m-Y', $node->jiscpmrisks[0]['risk_end']),
    '#weight' => 7,
  );
  $node->content['group9']['risk_category'] = array(
    '#prefix' => '<strong>Risk Category</strong><div class="riskcategory">',
    '#suffix' => '</div>',
    '#value' => t($node->jiscpmrisks[0]['risk_category']),
    '#weight' => 8,
  );
  $node->content['group10']['risk_management_approach'] = array(
    '#prefix' => '<strong>Risk Management Approach</strong><div class="riskmanagementapproach">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->jiscpmrisks[0]['risk_management_approach'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => 9,
  );
  return $node;
}
