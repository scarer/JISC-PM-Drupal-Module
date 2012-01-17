<?php
// $Id: $

/**
 * @file
 */

function theme_jiscpmsr_list($header, $srs) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') .'/jiscpm.css', 'module');

  $rows = array();
  foreach ($srs as $key => $sr) {
    $rows[] = array(
      jiscpm_icon('srcategory_'. $sr->srcategory, $sr->srcategory),
      l($sr->organization_title, 'node/'. $sr->organization_nid),
      l($sr->title, 'node/'. $sr->nid) . theme('mark', node_mark($sr->nid, $sr->changed)),
      jiscpm_icon('status_'. $sr->srstatus, $sr->srstatus),
      jiscpm_icon('priority_'. $sr->srpriority, $sr->srpriority),
      array(
        'data' => jiscpm_icon_edit_node($sr, $_GET) .'&nbsp;'. jiscpm_icon_delete_node($sr, $_GET),
        'class' => 'jiscpm_list_operations',
      ),
    );
  }
  $o  = theme('table', $header, $rows);
  return $o;
}

function theme_jiscpmsr_view($node, $teaser = FALSE, $page = FALSE) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');
  
  $node = node_prepare($node, $teaser);
  
  $node->content['links'] = array(
    '#prefix' => '<div class="jiscpmlinks"><dl>',
    '#suffix' => '</dl></div>',
    '#weight' => -25,
  );
  
  $node->content['links']['expenses'] = theme('jiscpm_link', 'jiscpmsr', 'jiscpmexpense', $node->nid, 1);
  $node->content['links']['notes'] = theme('jiscpm_link', 'jiscpmsr', 'jiscpmnote', $node->nid, 2);
  $node->content['links']['tasks'] = theme('jiscpm_link', 'jiscpmsr', 'jiscpmtask', $node->nid, 3);
  $node->content['links']['tickets'] = theme('jiscpm_link', 'jiscpmsr', 'jiscpmticket', $node->nid, 4);  
  $node->content['links']['timetrackings'] = theme('jiscpm_link', 'jiscpmsr', 'jiscpmtimetracking', $node->nid, 5);
  
  $node->content['group1'] = array( 
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );
  $loadproject = node_load($node->jiscpmsrs[0]['project_nid']);
  $node->content['group1']['project'] = array(
    '#prefix' => '<div class="project">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Project'), l($loadproject->title, 'node/'. $loadproject->nid)),
    '#weight' => 1,
  );

  $node->content['group2'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );

  $node->content['group2']['sr_focus_area'] = array(
    '#prefix' => '<strong>Focus Area</strong><div class="srfocusarea">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmsrs[0]['sr_focus_area'],
    '#weight' => 1,
  );

  $node->content['group3']['sr_product_process'] = array(
    '#prefix' => '<strong>Product/Process</strong><div class="srproductprocess">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmsrs[0]['sr_product_process'],
    '#weight' => 2,
  );

  $node->content['group4']['sr_overview'] = array(
    '#prefix' => '<strong>Overview</strong><div class="sroverview">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmsrs[0]['sr_overview'],
    '#weight' => 3,
  );

  $node->content['group5'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -16,
  );
  
  $node->content['group5']['sr_milestone_report'] = array(
    '#prefix' => '<strong>Milestone Report</strong><div class="srmilestonereport">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmsrs[0]['sr_milestone_report'],
    '#weight' => 4,
  );
  
  $node->content['group6']['sr_risk_management_report'] = array(
    '#prefix' => '<strong>Risk Management Report</strong><div class="srriskmanagementreport">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmsrs[0]['sr_risk_management_report'],
    '#weight' => 5,
  );
  $node->content['group7']['sr_issues_report'] = array(
    '#prefix' => '<strong>Issues Report</strong><div class="srissuesreport">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmsrs[0]['sr_issues_report'],
    '#weight' => 6,
  );
  $node->content['group8']['sr_project_recommendations'] = array(
    '#prefix' => '<strong>Project Recommendations</strong><div class="srprojectrecommendations">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmsrs[0]['sr_project_recommendations'],
    '#weight' => 7,
  );
  $node->content['group9']['sr_start'] = array(
    '#prefix' => '<strong>Start of reporting period</strong><div class="srstart">',
    '#suffix' => '</div>',
    '#value' => date('d-m-Y', $node->jiscpmsrs[0]['sr_start']),
    '#weight' => 8,
  );
  $node->content['group10']['sr_end'] = array(
    '#prefix' => '<strong>End of reporting period</strong><div class="srend">',
    '#suffix' => '</div>',
    '#value' => date('d-m-Y', $node->jiscpmsrs[0]['sr_end']),
    '#weight' => 9,
  );
  $node->content['group11']['sr_overall_status'] = array(
    '#prefix' => '<strong>Overall Status of Project</strong><div class="sroverallstatus">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmsrs[0]['sr_overall_status'],
    '#weight' => 10,
  );
  $node->content['group12']['sr_project_summary'] = array(
    '#prefix' => '<strong>Project Summary</strong><div class="srprojectsummary">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmsrs[0]['sr_project_summary'],
    '#weight' => 11,
  );
  $node->content['group13']['sr_objectives_for_next_sr'] = array(
    '#prefix' => '<strong>Objectives for Next Status Report</strong><div class="srobjectivesfornextsr">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmsrs[0]['sr_objectives_for_next_sr'],
    '#weight' => 12,
  );
    $node->content['group14']['sr_related_project_information'] = array(
    '#prefix' => '<strong>Related Project Information</strong><div class="srrelatedprojectinformation">',
    '#suffix' => '</div>',
    '#value' => $node->jiscpmsrs[0]['sr_related_project_information'],
    '#weight' => 13,
  );
  /*$node->content['body_field'] = array(
    '#prefix' => '<div class="jiscpmbody">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Description'), $node->content['body']['#value']),
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'body_field') : -18,
  );
  unset($node->content['body']);*/
  
  return $node;
}