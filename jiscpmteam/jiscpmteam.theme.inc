<?php

/**
 * @file
 */

function theme_jiscpmteam_list($header, $teams) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') .'/jiscpm.css', 'module');

  $rows = array();
  foreach ($teams as $key => $team) {
    $rows[] = array(
      jiscpm_icon('teamcategory_'. $team->teamcategory, $team->teamcategory),
      l($team->organization_title, 'node/'. $team->organization_nid),
      l($team->title, 'node/'. $team->nid) . theme('mark', node_mark($team->nid, $team->changed)),
      jiscpm_icon('status_'. $team->teamstatus, $team->teamstatus),
      jiscpm_icon('priority_'. $team->teampriority, $team->teampriority),
      array(
        'data' => jiscpm_icon_edit_node($team, $_GET) .'&nbsp;'. jiscpm_icon_delete_node($team, $_GET),
        'class' => 'jiscpm_list_operations',
      ),
    );
  }
  $o  = theme('table', $header, $rows);
  return $o;
}

function theme_jiscpmteam_view($node, $teaser = FALSE, $page = FALSE) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');
  
  $node = node_prepare($node, $teaser);
  
  $node->content['links'] = array(
    '#prefix' => '<div class="jiscpmlinks"><dl>',
    '#suffix' => '</dl></div>',
    '#weight' => -25,
  );
  
  $node->content['links']['expenses'] = theme('jiscpm_link', 'jiscpmteam', 'jiscpmexpense', $node->nid, 1);
  $node->content['links']['notes'] = theme('jiscpm_link', 'jiscpmteam', 'jiscpmnote', $node->nid, 2);
  $node->content['links']['tasks'] = theme('jiscpm_link', 'jiscpmteam', 'jiscpmtask', $node->nid, 3);
  $node->content['links']['tickets'] = theme('jiscpm_link', 'jiscpmteam', 'jiscpmticket', $node->nid, 4);  
  $node->content['links']['timetrackings'] = theme('jiscpm_link', 'jiscpmteam', 'jiscpmtimetracking', $node->nid, 5);
  $actions .= '<p><table><th>Title</th><th>Description</th><th>Delivery Date</th>';

  //generate output for jiscpm team running costs other
  $members_o .= '<p><table><th>Member</th><th>Description</th>';
  for ($m = 0; $m < count ($node->members); $m ++) {
    $user = user_load($node->members[$m]['member_uid']);  
$members_o .= '<tr><td><a href="?q=user/' . $user->uid . '">' . $user->name . '</a></td><td>' . check_markup($node->members[$m]['member_description'], FILTER_FORMAT_DEFAULT, FALSE) . '</td></tr>';
  }
  $members_o .= '</table></p>';
  
  $node->content['group1'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );

  $node->content['group2'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );

  //load project
  $project = node_load($node->jiscpmteams[0]['project_nid']);
  $node->content['group2']['teamproject'] = array(
    '#prefix' => '<div class="teamproject">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Project'), l($project->title, 'node/' . $project->nid)),
    '#weight' => -18,
  );
  
    $node->content['group3'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group3') : -17,
  ); 
  
  $node->content['group3']['members'] = array(
    '#prefix' => '<strong>Team Members</strong><div class="members">',
    '#suffix' => '</div>',
    '#value' => t($members_o),
    '#weight' => -9,
  );
  $node->content['description'] = array(
    '#prefix' => '<strong>Team Description</strong><div class="jiscpmteamdescription">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->jiscpmteams[0]['team_description'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'body_field') : -20,
  );
  unset($node->content['body']);
  
  return $node;
}