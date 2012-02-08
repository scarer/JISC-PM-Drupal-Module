<?php
/**
 * @file
 */

function theme_jiscpmrfc_list($header, $risks) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') .'/jiscpm.css', 'module');
}

function theme_jiscpmrfc_view($node, $teaser = FALSE, $page = FALSE) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');
  
  $node = node_prepare($node, $teaser);
  
  $node->content['group0'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group0') : -21,
  );
  $project = node_load($node->rfcs[0]['project_nid']); 
  $node->content['group0']['project'] = array(
    '#prefix' => '<strong>Project</strong><div class="project">',
    '#suffix' => '</div>',
    '#value' => l($project->title, 'node/' . $project->nid),
    '#weight' => 0,
  );
  $node->content['group1'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );

  $node->content['group1']['rationale'] = array(
    '#prefix' => '<strong>Rationale</strong><div class="rationale">',
    '#suffix' => '</div>',
    '#value' => $node->rfcs[0]['rfc_rationale'],
    '#weight' => 1,
  );

  $node->content['group2'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );
  $requestor = user_load($node->rfcs[0]['rfc_requestor_uid']);
  $node->content['group2']['requestoruid'] = array(
    '#prefix' => '<strong>Requestor</strong><div class="requestoruid">',
    '#suffix' => '</div>',
    '#value' => l($requestor->name, 'user/' . $requestor->uid),
    '#weight' => 2,
  );
  
  $node->content['body_field'] = array(
    '#prefix' => '<div class="jiscpmbody">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Description'), $node->content['body']['#value']),
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'body_field') : -18,
  );
  unset($node->content['body']);
  
  return $node;
}