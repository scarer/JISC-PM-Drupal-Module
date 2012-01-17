<?php
// $Id: $

/**
 * @file
 */

function jiscpmrisk_list() {
  global $base_url;
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), '/');
  $breadcrumb[] = l(t('JISC PM'), 'jiscpm/dashboard');
  drupal_set_breadcrumb($breadcrumb);
  $header = array(
      array('data' => t('Risk'), 'field' => 'title'),
      array('data' => t('Probability'), 'field' => 'risk_probability'),
      array('data' => t('Impact'), 'field' => 'risk_impact'),
      array('data' => t('Start'), 'field' => 'risk_start'),
      array('data' => t('End'), 'field' => 'risk_end'),
      array('data' => t('Owner'), 'field' => 'risk_owner_uid'),
      array('data' => t('Project'), 'field' => 'project_nid')
  );

  $sql  = "SELECT n.title, n.nid, j.risk_probability, j.risk_impact, j.risk_start, j.risk_end, 
  j.risk_owner_uid, j.project_nid FROM {node} n JOIN {jiscpmrisk} j ON n.nid = j.nid WHERE n.status=1 AND 
  n.type='jiscpmrisk'";
  //$sql .= tablesort_sql($header);
  $result = pager_query($sql, 50);
  while ( $records = db_fetch_object($result) )
  {
    $owner = user_load($records->risk_owner_uid);
    $project = node_load($records->project_nid);
  	$rows[] = array('<a href="' . $base_url . '/node/' . $records->nid . '">' . $records->title . '</a>', 
  	$records->risk_probability, $records->risk_impact, date('d-m-Y', $records->risk_start), date('d-m-Y', $records->risk_end), 
  	'<a href="' . $base_url . '/user/' . $owner->uid . '">' . $owner->name . '</a>', '<a href="' . $base_url . '/node/' . 
  	$project->nid . '">' . $project->title . '</a>');
  }
  $pager = theme('pager', NULL, 50, 0);
  if ( count($rows) && !empty($pager))
  {
    $rows[] = array(array('data' => $pager, 'colspan' => '6'));
  }
  
  if ( count($rows) )
  {
    $output .= theme('table', $header, $rows);
  }
  else
  {
    drupal_set_message("There are no risks", 'status');
  }
  $module_path = drupal_get_path('module', 'jiscpm');
  $full_path = $module_path .'/jiscpm.css';
  drupal_add_css($full_path);
  //print link to add new risks
  $output .= '<div class="links"><ul class="links inline"><li class="jiscpm_add">
  <a href="' . $base_url . '/node/add/jiscpmrisk">Add Risk</a></li></ul></div>';
  print theme('page', $output);
}

