<?php
// $Id: $

/**
 * @file
 */

function jiscpmrfc_list() {
  $breadcrumb = array();
  /* needs to be rebuilt to include customised page for home page for jiscpm */
  //$breadcrumb[] = l(t('jiscpm'), 'jiscpm');
  $breadcrumb[] = l(t('Home'), '/');
  drupal_set_breadcrumb($breadcrumb);

  
  $i = new stdClass();
  $i->type = 'jiscpmrfc';

  //table headers to be installed in table display of projects
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

  $s  = db_query("SELECT n.title, n.nid, j.rationale, j.requestor_uid FROM {node} n JOIN {jiscpmrfc} j ON n.nid = j.nid WHERE n.status=1 AND n.type='jiscpmrfc'");

  //start of table
  $o .= '<table><th>RFC</th><th>Rationale</th><th>Requestor</th>';
  // output needs to be improved to include filter mechanism and to support drupa table themeing
  //$rfcs = array();
  while ($rfc = db_fetch_object($s)) {
  	$user = user_load($rfc->requestor_uid);
    $o .= '<tr><td><a href="?q=node/' . $rfc->nid . '">' . $rfc->title . '</a></td><td>' . $rfc->rationale . '</td><td><a href="?q=user/' . $user->uid . '">'  . $user->name . '</a></td></tr>';
  }
  //end of table
  $o .= '</table>';

  
  print theme('page', $o);
}

