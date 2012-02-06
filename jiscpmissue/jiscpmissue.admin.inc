<?php
/**
 * @file
 */

function jiscpmissue_list() {
  global $base_url;
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), '/');
  $breadcrumb[] = l(t('JISC PM'), 'jiscpm/dashboard');
  drupal_set_breadcrumb($breadcrumb);

  $header = array(
      array('data' => t('Issue'), 'field' => 'title'),
      array('data' => t('Owner'), 'field' => 'risk_probability'),
      array('data' => t('Project'), 'field' => 'project_nid'),
  );

  $sql  = "SELECT n.title, n.nid, i.project_nid, i.issue_progress, i.issue_resolved, 
  i.issue_owner_uid FROM {node} n JOIN {jiscpmissue} i ON n.nid = i.nid WHERE n.status=1 AND 
  n.type='jiscpmissue'";
  //$sql .= tablesort_sql($header);
  $result = pager_query($sql, 50);
  while ( $records = db_fetch_object($result) ) {
    $project = node_load($records->project_nid);
    $owner = user_load($records->issue_owner_uid);
$rows[] = array('<a href="' . $base_url . '/node/' . $records->nid . '">' . $records->title . '</a>', 
'<a href="' . $base_url . '/user/' . $owner->uid . '">' . $owner->name . '</a>', 
'<a href="' . $base_url . '/node/' . $project->nid . '">' . $project->title . '</a>');
  }
  $pager = theme('pager', NULL, 50, 0);
  if ( count($rows) && !empty($pager)) {
    $rows[] = array(array('data' => $pager, 'colspan' => '3'));
  }
  
  if ( count($rows) ) {
    $output .= theme('table', $header, $rows);
  }
  else {
    drupal_set_message("There are no issues", 'status');
  }
  $module_path = drupal_get_path('module', 'jiscpm');
  $full_path = $module_path .'/jiscpm.css';
  drupal_add_css($full_path);
  //print link to add new issues
  $output .= '<div class="links"><ul class="links inline"><li class="jiscpm_add">
  <a href="' . $base_url . '/node/add/jiscpmissue">Add Issue</a></li></ul></div>';
  print theme('page', $output);
}

