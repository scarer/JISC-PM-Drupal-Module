<?php

/**
 * @file
 */

/**
 * @function
 * List all teams.
 */
function theme_jiscpmteam_list($header, $teams) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm.css', 'module');
}
/**
 * @function
 * View of team node.
 */
function theme_jiscpmteam_view($node, $teaser = FALSE, $page = FALSE) {
  global $base_url;
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');
  $node = node_prepare($node, $teaser);
  $node->content['group1'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : 0,
  );
  $project = node_load($node->jiscpmteams[0]['project_nid']);
  $node->content['group1']['project'] = array(
    '#prefix' => '<strong>Project</strong><div class="project">',
    '#suffix' => '</div>',
    '#value' => l($project->title, 'node/' . $project->nid),
    '#weight' => 1,
  );
  $node->content['group2'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : 1,
  );
  $node->content['group2']['team_description'] = array(
    '#prefix' => '<strong>Team description</strong><div class="teamdescription">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->jiscpmteams[0]['team_description'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => 1,
  );
  // Table headers for members table.
  $output .= '<table><th>Member</th><th>Description</th>';
  // Get all date for teams and output as a table.
  for ($i = 0; $i < count($node->members); $i++) {
    $member = user_load($node->members[$i]['member_uid']);
    $memberdescription = check_markup($node->members[$i]['member_description'], FILTER_FORMAT_DEFAULT, FALSE);
    $output .= '<tr><td><a href="' . $base_url . '/user/' . $member->uid . '">' . $member->name . '</a></td><td>' . $memberdescription . '</td></tr>';
  }
  $output .= '</table>';
  $node->content['group3'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group3') : 2,
  );
  $node->content['group3']['team_members'] = array(
    '#prefix' => '<strong>Team members</strong><div class="teammembers">',
    '#suffix' => '</div>',
    '#value' => $output,
    '#weight' => 1,
  );
  return $node;
}
