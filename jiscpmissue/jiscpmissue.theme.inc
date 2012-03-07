<?php
/**
 * @file
 * JISC PM issue theme file.
 */

/**
 * @function
 * Include stylesheet.
 */
function theme_jiscpmissue_list($header, $issues) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm.css', 'module');
}
/**
 * @function
 */
function theme_jiscpmissue_view($node, $teaser = FALSE, $page = FALSE) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');
  $node = node_prepare($node, $teaser);
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
