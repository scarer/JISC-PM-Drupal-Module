<?php
/**
 * @file
 */

/**
 * @function
 * This function lists all BCAs.
 */
function jiscpmbca_list() {
  global $base_url;
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), '/');
  $breadcrumb[] = l(t('JISC PM'), 'jiscpm/dashboard');
  drupal_set_breadcrumb($breadcrumb);
  $header = array(
    array('data' => t('BCA'), 'field' => 'title'),
    array('data' => t('Project'), 'field' => 'nid'),
  );

  $sql  = "SELECT n.title, n.nid, b.project_nid FROM {node} n JOIN {jiscpmbca} b ON n.nid = b.nid 
  WHERE n.status=1 AND n.type='jiscpmbca'";
  $result = pager_query($sql, 50);
  while ($records = db_fetch_object($result)) {
    $project = node_load($records->project_nid);
    $rows[] = array('<a href="' . $base_url . '/node/' . $records->nid . '">' . $records->title . '</a>', '<a href="' . $base_url . '/node/' . $project->nid . '">' . $project->title . '</a>');
  }
  $pager = theme('pager', NULL, 50, 0);
  if (count($rows) && !empty($pager)) {
    $rows[] = array(array('data' => $pager, 'colspan' => '2'));
  }

  if (count($rows)) {
    $output .= theme('table', $header, $rows);
  }
  else {
    drupal_set_message(t("There are no business case assessments"), 'status');
  }
  $module_path = drupal_get_path('module', 'jiscpm');
  $full_path = $module_path . '/jiscpm.css';
  drupal_add_css($full_path);
  // Print link to add new business case assessments.
  $output .= '<div class="links"><ul class="links inline"><li class="jiscpm_add">
  <a href="' . $base_url . '/node/add/jiscpmbca">Add Business Case Assessment</a></li></ul></div>';
  print theme('page', $output);
}
