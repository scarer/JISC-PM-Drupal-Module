<?php
/**
 * @file
 */

function jiscpmsr_list() {
  global $base_url;
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), '/');
  $breadcrumb[] = l(t('JISC PM'), 'jiscpm/dashboard');
  drupal_set_breadcrumb($breadcrumb);
  
  $header = array(
      array('data' => t('Status Report'), 'field' => 'title'),
      array('data' => t('Focus Area'), 'field' => 'sr_focus_area'),
      array('data' => t('Product / Process'), 'field' => 'sr_product_process'),
      array('data' => t('Reporting Start'), 'field' => 'sr_start'),
      array('data' => t('Reporting End'), 'field' => 'sr_end'),
      array('data' => t('Author'), 'field' => 'name'),
  );

  $sql  = "SELECT n.title, n.nid, j.sr_focus_area, j.sr_product_process, j.sr_start, j.sr_end, 
  u.name, u.uid FROM {node} n JOIN {jiscpmsr} j ON n.nid = j.nid LEFT JOIN {users} u ON n.uid = u.uid 
  WHERE n.status=1 AND n.type='jiscpmsr'";
  //$sql .= tablesort_sql($header);
  $result = pager_query($sql, 50);
  while ( $records = db_fetch_object($result) ) {
$rows[] = array('<a href="' . $base_url . '/node/' . $records->nid . '">' . $records->title . '</a>', 
$records->sr_focus_area, $records->sr_product_process, date('d-m-Y', $records->sr_start), date('d-m-Y', $records->sr_end), '<a href="' . $base_url . '/user/' . $records->uid . '">' . $records->name . '</a>');
  }
  $pager = theme('pager', NULL, 50, 0);
  if ( count($rows) && !empty($pager)) {
    $rows[] = array(array('data' => $pager, 'colspan' => '6'));
  }
  
  if ( count($rows) ) {
    $output = theme('table', $header, $rows);
  }
  else {
    drupal_set_message(t("There are no status reports"), 'status');
  }
  $module_path = drupal_get_path('module', 'jiscpm');
  $full_path = $module_path .'/jiscpm.css';
  drupal_add_css($full_path);
  //print link to add new status reports
  $output .= '<div class="links"><ul class="links inline"><li class="jiscpm_add">
  <a href="' . $base_url . '/node/add/jiscpmsr">Add Status Report</a></li></ul></div>';
  print theme('page', $output);

}

