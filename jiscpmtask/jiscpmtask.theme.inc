<?php

/**
 * @file
 * JISC PM Task theme.
 */

/**
 * @function
 * A list of tasks.
 */
function theme_jiscpmtask_tasks($form) {
  if (count($form['tasks']) > 0 && jiscpmproject_access('update', $form['project']['#value'])) {
    drupal_add_tabledrag('tasks', 'match', 'parent', 'task-parent-nid', 'task-parent-nid', 'task-nid', TRUE);
    drupal_add_tabledrag('tasks', 'order', 'sibling', 'task-weight');
  }
  $header = array();
  $row = array();
  $header = $form['header']['#value'];
  unset($form['header']);
  foreach (element_children($form['tasks']) as $key) {
    $form['tasks'][$key]['task_parent-nid_' . $key]['#attributes']['class'] = 'task-parent-nid';
    $form['tasks'][$key]['task_nid_' . $key]['#attributes']['class'] = 'task-nid';
    $form['tasks'][$key]['task_weight_' . $key]['#attributes']['class'] = 'task-weight';
    $durationunit = $form['tasks'][$key]['task_durationunit_' . $key]['#value'];
    $data = array(
      theme('indentation', $form['tasks'][$key]['task_depth_' . $key]['#value']) . drupal_render($form['tasks'][$key]['task_description_' . $key]),
      drupal_render($form['tasks'][$key]['task_category_' . $key]),
      drupal_render($form['tasks'][$key]['task_status_' . $key]),
      drupal_render($form['tasks'][$key]['task_priority_' . $key]),
      array(
        'data' => sprintf('%.2f', drupal_render($form['tasks'][$key]['task_duration_' . $key])) . ' ' . drupal_substr($durationunit, 0, 1),
        'style' => 'text-align: right'),
      drupal_render($form['tasks'][$key]['task_parent-nid_' . $key]) . drupal_render($form['tasks'][$key]['task_nid_' . $key]),
      drupal_render($form['tasks'][$key]['task_weight_' . $key]),
      array(
        'data' => drupal_render($form['tasks'][$key]['task_operations_' . $key]),
        'class' => 'jiscpm_list_operations',
      ),
    );
    if (!jiscpmproject_access('update', $form['project']['#value'])) {
      unset($data[5]);
      unset($data[6]);
    }
    $row['data'] = $data;
    if (jiscpmproject_access('update', $form['project']['#value'])) {
      $row['class'] = empty($row['class']) ? 'draggable' : $row['class'] . ' draggable';
    }
    $rows[] = $row;
  }
  $o = theme('table', $header, $rows, array('id' => 'tasks'));
  return $o;
}
/**
 * @function
 * A list of tasks.
 */
function theme_jiscpmtask_list($header, $tasks) {
  $rows = array();
  foreach ($tasks as $task) {
    $rows[] = array(
      'class' =>
      'jiscpm_category_' . preg_replace('/[^a-zA-Z]/', '', $task->taskcategory) . ' ' .
      'jiscpm_status_' . preg_replace('/[^a-zA-Z]/', '', $task->taskstatus) . ' ' .
      'jiscpm_priority_' . preg_replace('/[^a-zA-Z]/', '', $task->taskpriority),
      'data' => array(
        l($task->project_title, 'node/' . $task->project_nid),
        l($task->title, 'node/' . $task->nid) . theme('mark', node_mark($task->nid, $task->changed)),
        jiscpm_icon('category_' . $task->taskcategory, $task->taskcategory),
        jiscpm_icon('status_' . $task->taskstatus, $task->taskstatus),
        jiscpm_icon('priority_' . $task->taskpriority, $task->taskpriority),
        array(
          'data' => jiscpm_icon_edit_node($task, $_GET) . '&nbsp;' . jiscpm_icon_delete_node($task, $_GET),
          'class' => 'jiscpm_list_operations',
        ),
      ),
    );
  }
  $o = theme('table', $header, $rows);
  return $o;
}
/**
 * @function
 * A view of a task.
 */
function theme_jiscpmtask_view($node, $teaser = FALSE, $page = FALSE) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');
  $node = node_prepare($node, $teaser);
  $node->content['links'] = array(
    '#prefix' => '<div class="jiscpmlinks">',
    '#suffix' => '</div>',
    '#weight' => -25,
  );
  $node->content['links']['expenses'] = theme('jiscpm_link', 'jiscpmtask', 'jiscpmexpense', $node->nid, $w++);
  $node->content['links']['notes'] = theme('jiscpm_link', 'jiscpmtask', 'jiscpmnote', $node->nid, $w++);
  $node->content['links']['tickets'] = theme('jiscpm_link', 'jiscpmtask', 'jiscpmticket', $node->nid, $w++);
  $node->content['links']['timetrackings'] = theme('jiscpm_link', 'jiscpmtask', 'jiscpmtimetracking', $node->nid, $w++);
  $node->content['group1'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );
  $project = node_load($node->project_nid);
  $node->content['group1']['project'] = array(
    '#prefix' => '<div class="project">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Project'), l($project->title, 'node/' . $node->project_nid)),
    '#weight' => 2,
  );
  $node->content['group1']['stepno'] = array(
    '#prefix' => '<div class="stepno">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Step no.'), $node->stepno),
    '#weight' => 3,
  );
  $node->content['group2'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );
  $node->content['group2']['category'] = array(
    '#prefix' => '<div class="category">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Category'), jiscpmattribute_value('Task category', $node->taskcategory)),
    '#weight' => 1,
  );
  $node->content['group2']['status'] = array(
    '#prefix' => '<div class="jiscpm_status">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Status'), jiscpmattribute_value('Task status', $node->taskstatus)),
    '#weight' => 2,
  );
  $node->content['group2']['priority'] = array(
    '#prefix' => '<div class="priority">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Priority'), jiscpmattribute_value('Task priority', $node->taskpriority)),
    '#weight' => 3,
  );
  $node->content['group5'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -16,
  );
  $assigneduser = user_load($node->assigned_uid);
  $node->content['group5']['assigned'] = array(
    '#prefix' => '<div class="assigned">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Assigned to'), l($assigneduser->name, 'user/' . $node->assigned_uid)),
    '#weight' => 2,
  );
  $node->content['group6'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group6') : -15,
  );
  $node->content['group6']['datebegin'] = array(
    '#prefix' => '<div class="datebegin">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Date begin'), date('d-m-Y', $node->datebegin)),
    '#weight' => 2,
  );
  $node->content['group6']['dateend'] = array(
    '#prefix' => '<div class="dateend">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Date end'), date('d-m-Y', $node->dateend)),
    '#weight' => 3,
  );
  $node->content['body_field'] = array(
    '#prefix' => '<div class="jiscpmbody">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Description'), $node->content['body']['#value']),
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'body_field') : -14,
  );
  unset($node->content['body']);
  return $node;
}
