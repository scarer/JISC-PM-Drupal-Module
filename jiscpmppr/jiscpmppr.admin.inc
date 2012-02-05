<?php
/**
 * @file
 */

function jiscpmppr_list() {
  global $base_url;
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), '/');
  $breadcrumb[] = l(t('JISC PM'), 'jiscpm/dashboard');
  drupal_set_breadcrumb($breadcrumb);
  
  $header = array(
      array('data' => t('PPR'), 'field' => 'title'),
      array('data' => t('Author'), 'field' => 'uid'),
      array('data' => t('Project'), 'field' => 'project_nid'),
  );

  $sql  = "SELECT n.title, n.nid, n.uid, j.project_nid FROM {node} n JOIN {jiscpmppr} j ON n.nid = 
  j.nid WHERE n.status=1 AND n.type='jiscpmppr'";
  //$sql .= tablesort_sql($header);
  $result = pager_query($sql, 50);
  while ( $records = db_fetch_object($result) )
  {
    $author = user_load($records->uid);
    $project = node_load($records->project_nid);
  	$rows[] = array('<a href="' . $base_url . '/node/' . $records->nid . '">' . $records->title . '</a>', 
  	'<a href="' . $base_url . '/user/' . $owner->uid . '">' . $owner->name . '</a>', '<a href="' . $base_url .'/node/' . 
  	$project->nid . '">' . $project->title . '</a>');
  }
  $pager = theme('pager', NULL, 50, 0);
  if ( count($rows) && !empty($pager))
  {
    $rows[] = array(array('data' => $pager, 'colspan' => '3'));
  }
  
  if ( count($rows) )
  {
    $output .= theme('table', $header, $rows);
  }
  else
  {
    drupal_set_message("There are no post project reviews", 'status');
  }
  $module_path = drupal_get_path('module', 'jiscpm');
  $full_path = $module_path .'/jiscpm.css';
  drupal_add_css($full_path);
  //print link to add new pprs
  $output .= '<div class="links"><ul class="links inline"><li class="jiscpm_add">
  <a href="' . $base_url . '/node/add/jiscpmppr">Add Post-Project Review</a></li></ul></div>';
  print theme('page', $output);
}

