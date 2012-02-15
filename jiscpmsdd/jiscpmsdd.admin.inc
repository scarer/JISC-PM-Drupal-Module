<?php
/**
* @file
*/

function jiscpmsdd_list() {
global $base_url;
$breadcrumb = array();
$breadcrumb[] = l(t('Home'), '/');
$breadcrumb[] = l(t('JISC PM'), 'jiscpm/dashboard');
drupal_set_breadcrumb($breadcrumb);

$header = array(
array('data' => t('System Design Document'), 'field' => 'title'),
array('data' => t('Project'), 'field' => 'project_nid'),
array('data' => t('Author'), 'field' => 'uid'),
);

$sql  = "SELECT n.title, n.uid, n.nid, j.project_nid, j.system_overview, j.system_architecture, j.data_design, 
j.component_design, j.user_interfaces, j.hardware_interfaces, j.software_interfaces FROM {node} n JOIN {jiscpmsdd} j ON n.nid = j.nid  
WHERE n.status=1 AND n.type='jiscpmsdd'";
//$sql .= tablesort_sql($header);
$result = pager_query($sql, 50);
while ( $records = db_fetch_object($result) ) {
$project = node_load($records->project_nid);
$author = user_load($records->uid);
$rows[] = array('<a href="' . $base_url . '/node/' . $records->nid . '">' . $records->title . '</a>', '<a href="' . $base_url . '/node/' . $records->project_nid . '">' . $project->title . '</a>', 
'<a href="' . $base_url . '/user/' . $author->uid . '">' . $author->name . '</a>');
}
$pager = theme('pager', NULL, 50, 0);
if ( count($rows) && !empty($pager)) {
$rows[] = array(array('data' => $pager, 'colspan' => '3'));
}

if ( count($rows) ) {
$output = theme('table', $header, $rows);
}
else {
drupal_set_message("There are no system design documents", 'status');
}
$module_path = drupal_get_path('module', 'jiscpm');
$full_path = $module_path .'/jiscpm.css';
drupal_add_css($full_path);
//print link to add new status reports
$output .= '<div class="links"><ul class="links inline"><li class="jiscpm_add">
<a href="' . $base_url . '/node/add/jiscpmsdd">Add System Design Document</a></li></ul></div>';
print theme('page', $output);

}

