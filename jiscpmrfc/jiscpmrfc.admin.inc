<?php
/**
 * @file
 * Administration for JISC PM RFCs.
 */

/**
 * @function
 * Lists the RFCs.
 */
function jiscpmrfc_list() {
  global $base_url;
  $breadcrumb = array();
  // Needs to be rebuilt to include customised page for home page for jiscpm.
  $breadcrumb[] = l(t('Home'), '/');
  drupal_set_breadcrumb($breadcrumb);
  $i = new stdClass();
  $i->type = 'jiscpmrfc';
  // Table headers to be installed in table display of projects.
  $header = array(
    array(
      'data' => ' ',
    ),
    array(
      'data' => t('RFC'),
      'field' => 'n.title',
    ),
    array(
      'data' => t('Rationale'),
      'field' => 'jpr.rationale',
    ),
    array(
      'data' => t('Requestor'),
      'field' => 'jpr.requestor',
    ),
  );
  $s = db_query(db_rewrite_sql("SELECT n.title, n.nid, j.rfc_rationale, j.rfc_requestor_uid FROM {node} n JOIN {jiscpmrfc} j ON n.nid = j.nid WHERE n.status=1 AND n.type='jiscpmrfc'"));
  // Start of table.
  $o .= '<table><th>RFC</th><th>Rationale</th><th>Requestor</th>';
  // Output needs to be improved to include filter mechanism
  // and to support drupa table themeing.
  while ($rfc = db_fetch_object($s)) {
    $user = user_load($rfc->rfc_requestor_uid);
    $o .= '<tr><td><a href="?q=node/' . $rfc->nid . '">' . $rfc->title . '</a></td><td>' . $rfc->rfc_rationale . '</td><td><a href="?q=user/' . $user->uid . '">' . $user->name . '</a></td></tr>';
  }
  // End of table.
  $o .= '</table>';
  $module_path = drupal_get_path('module', 'jiscpm');
  $full_path = $module_path . '/jiscpm.css';
  drupal_add_css($full_path);
  $o .= '<div class="links"><ul class="links inline"><li class="jiscpm_add">
  <a href="' . $base_url . '/node/add/jiscpmrfc">Add request for change</a></li></ul></div>';
  print theme('page', $o);
}
