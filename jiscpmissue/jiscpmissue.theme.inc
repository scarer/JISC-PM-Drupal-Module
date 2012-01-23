<?php
// $Id: $

/**
 * @file
 */

function theme_jiscpmissue_list($header, $risks) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') .'/jiscpm.css', 'module');

  $rows = array();
  foreach ($risks as $key => $risk) {
    $rows[] = array(
      jiscpm_icon('riskcategory_'. $risk->riskcategory, $risk->riskcategory),
      l($risk->organization_title, 'node/'. $risk->organization_nid),
      l($risk->title, 'node/'. $risk->nid) . theme('mark', node_mark($risk->nid, $risk->changed)),
      jiscpm_icon('status_'. $risk->riskstatus, $risk->riskstatus),
      jiscpm_icon('priority_'. $risk->riskpriority, $risk->riskpriority),
      array(
        'data' => jiscpm_icon_edit_node($risk, $_GET) .'&nbsp;'. jiscpm_icon_delete_node($risk, $_GET),
        'class' => 'jiscpm_list_operations',
      ),
    );
  }
  $o  = theme('table', $header, $rows);
  return $o;
}

function theme_jiscpmissue_view($node, $teaser = FALSE, $page = FALSE) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');
  
  $node = node_prepare($node, $teaser);
  
  $node->content['links'] = array(
    '#prefix' => '<div class="jiscpmlinks"><dl>',
    '#suffix' => '</dl></div>',
    '#weight' => -25,
  );
  
  $node->content['links']['expenses'] = theme('jiscpm_link', 'jiscpmissue', 'jiscpmexpense', $node->nid, 1);
  $node->content['links']['notes'] = theme('jiscpm_link', 'jiscpmissue', 'jiscpmnote', $node->nid, 2);
  $node->content['links']['tasks'] = theme('jiscpm_link', 'jiscpmissue', 'jiscpmtask', $node->nid, 3);
  $node->content['links']['tickets'] = theme('jiscpm_link', 'jiscpmissue', 'jiscpmticket', $node->nid, 4);  
  $node->content['links']['timetrackings'] = theme('jiscpm_link', 'jiscpmissue', 'jiscpmtimetracking', $node->nid, 5);
  
  $node->content['group1'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );
  $project = node_load($node->issues[0]['project_nid']);
  $node->content['group1']['project'] = array(
    '#prefix' => '<strong>Project</strong><div class="project">',
    '#suffix' => '</div>',
    '#value' => l($project->title, 'node/' . $project->nid),
    '#weight' => 1,
  );

  $node->content['group2'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );
  $node->content['group2']['issue_progress'] = array(
    '#prefix' => '<strong>Progress on issue</strong><div class="issueprogress">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->issues[0]['issue_progress'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => 1,
  );
  $node->content['group3'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group3') : -18,
  );
  $node->content['group3']['issue_resolved'] = array(
    '#prefix' => '<strong>Is the issue resolved?</strong><div class="issueresolved">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->issues[0]['issue_resolved'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => 1,
  );
  $node->content['group4'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group4') : -17,
  );
  $node->content['group4']['issue_resolution'] = array(
    '#prefix' => '<strong>Issue resolution</strong><div class="issueresolution">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->issues[0]['issue_resolution'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => 1,
  );
  $node->content['group5'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -16,
  );
  $owner = user_load($node->issues[0]['issue_owner_uid']);
  $node->content['group5']['issue_owner_uid'] = array(
    '#prefix' => '<strong>Issue owner</strong><div class="issueowneruid">',
    '#suffix' => '</div>',
    '#value' => l($owner->name, 'user/' . $owner->uid),
    '#weight' => 1,
  );
  $node->content['body_field'] = array(
    '#prefix' => '<div class="jiscpmbody">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Description'), $node->content['body']['#value']),
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'body_field') : -15,
  );
  unset($node->content['body']);
  
  return $node;
}