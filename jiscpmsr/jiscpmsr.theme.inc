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
    '#weight' => -20,
  );
  //load project manager info and display
  $project_manager = array();
  $results = db_query('SELECT project_manager_uid FROM {jiscpmproject} WHERE nid = %d', $loadproject->nid);
  while ($rows = db_fetch_object($results)) {
    $project_manager = user_load($rows->project_manager_uid);
  }
  if ($project_manager->uid != -1)
  {
  	$node->content['projectmanager'] = array(
    	'#prefix' => '<div class="jiscpmfields">',
    	'#suffix' => '</div>',
    	'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'projectmanager') : -19,
		'#value' => theme('jiscpm_view_item', t('Project Manager'), l($project_manager->name, 'user/'. $project_manager->uid)),
  	);
  }
  else
  {
	  
  }
  $node->content['group3'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group3') : -18,
  );

  $node->content['group3']['sr_product_process'] = array(
	'#value' => theme('jiscpm_view_item', t('Product/Process'),$node->jiscpmsrs[0]['sr_product_process']),
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
  /*$node->content['body_field'] = array(
    '#prefix' => '<div class="jiscpmbody">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Description'), $node->content['body']['#value']),
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'body_field') : -18,
  );
  unset($node->content['body']);*/
  
  return $node;
}