<?php
// $Id: $

/**
 * This is the view of all the JISC PM Projects that have been posted to the site.
 * TODO: Add filters to view based on status and priority values
 * Author: Sarah Vardy
 * @file
 */

function jiscpmproject_list() {
  global $base_url;
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), '/');
  $breadcrumb[] = l(t('JISC PM'), 'jiscpm/dashboard');
  drupal_set_breadcrumb($breadcrumb);

  $header = array(
      array('data' => t('Project'), 'field' => 'title'),
      array('data' => t('Status'), 'field' => 'projectstatus'),
      array('data' => t('Priority'), 'field' => 'projectpriority'),
      array('data' => t('Date Begin'), 'field' => 'datebegin'),
      array('data' => t('Date End'), 'field' => 'dateend')
  );

  $sql  = "SELECT n.title, n.nid, j.projectstatus, j.projectpriority, j.datebegin, j.dateend 
  FROM {node} n JOIN {jiscpmproject} j ON n.nid = j.nid WHERE n.status=1 AND n.type='jiscpmproject'";
  //$sql .= tablesort_sql($header);
  $result = pager_query($sql, 50);
  while ( $records = db_fetch_object($result) )
  {
  	$rows[] = array('<a href="' . $base_url . '/node/' . $records->nid . '">' . $records->title . '</a>', 
  	$records->projectstatus, $records->projectpriority, date('d-m-Y', $records->datebegin), 
  	date('d-m-Y', $records->dateend));
  }
  $pager = theme('pager', NULL, 50, 0);
  if ( count($rows) && !empty($pager))
  {
    $rows[] = array(array('data' => $pager, 'colspan' => '5'));
  }
  
  if ( count($rows) )
  {
    $output .= theme('table', $header, $rows);
  }
  else
  {
    drupal_set_message("There are no projects", status);
  }
  $module_path = drupal_get_path('module', 'jiscpm');
  $full_path = $module_path .'/jiscpm.css';
  drupal_add_css($full_path);
  //print link to add new projects
  $output .= '<div class="links"><ul class="links inline"><li class="jiscpm_add">
  <a href="' . $base_url . '/node/add/jiscpmproject">Add Project</a></li></ul></div>';
  print theme('page', $output);
}