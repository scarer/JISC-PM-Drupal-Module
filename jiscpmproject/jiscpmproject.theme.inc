<?php
/**
 * @file
 * JISC PM Project theme.
 */

/**
 * @function
 * Lists all projects.
 */
function theme_jiscpmproject_list($header, $projects) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm.css', 'module');
  $rows = array();
  foreach ($projects as $key => $project) {
    $rows[] = array(
      jiscpm_icon('projectcategory_' . $project->projectcategory, $project->projectcategory),
      l($project->title, 'node/' . $project->nid) . theme('mark', node_mark($project->nid, $project->changed)),
      jiscpm_icon('status_' . $project->projectstatus, $project->projectstatus),
      jiscpm_icon('priority_' . $project->projectpriority, $project->projectpriority),
      array(
        'data' => jiscpm_icon_edit_node($project, $_GET) . '&nbsp;' . jiscpm_icon_delete_node($project, $_GET),
        'class' => 'jiscpm_list_operations',
      ),
    );
  }
  $o  = theme('table', $header, $rows);
  return $o;
}
/**
 * @function
 * Project view.
 */
function theme_jiscpmproject_view($node, $teaser = FALSE, $page = FALSE) {
  global $base_url;
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');
  $node = node_prepare($node, $teaser);
  $node->content['links'] = array(
    '#prefix' => '<div class="jiscpmlinks"><dl>',
    '#suffix' => '</dl></div>',
    '#weight' => -25,
  );
  $node->content['group10'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group10') : -12,
  );
  // Get node results from database.
  $resultspro = db_query('SELECT jp.project_manager_uid, jp.client_uid, jp.projectcategory, jp.projectstatus, jp.projectpriority, jp.datebegin, jp.dateend, jp.organisational_scope, jp.logical_scope, jp.out_of_scope FROM {jiscpmproject} jp WHERE jp.nid = %d', $node->nid);
  while ($rowspro = db_fetch_object($resultspro)) {
    if ($rowspro->project_manager_uid != -1) {
      $project_manager = user_load($rowspro->project_manager_uid);
      $pm_name = $project_manager->name;
    }
    if ($rowspro->client_uid != -1) {
      $client = user_load($rowspro->client_uid);
      $client_name = $client->name;
    }
    $category = $rowspro->projectcategory;
    $status = $rowspro->projectstatus;
    $priority = $rowspro->projectpriority;
    $begin = date('D m Y', $rowspro->datebegin);
    $end = date('D m Y', $rowspro->dateend);
    $org_scope = $rowspro->organisational_scope;
    $log_scope = $rowspro->logical_scope;
    $out_scope = $rowspro->out_of_scope;
  }
  // Get risks from database.
  $risks_results = db_rewrite_sql(db_query('SELECT n.title, jr.vid, jr.risk_owner_uid FROM {node} n JOIN {jiscpmrisk} jr ON n.nid = jr.nid WHERE jr.project_nid = %d', $node->nid));
  while ($risks_rows = db_fetch_object($risks_results)) {
    $risktitle = $risks_rows->title;
    $risknid = $risks_rows->vid;
    $riskowner = user_load($risks_rows->risk_owner_uid);
    $output_risks .= '<tr><td><a href="' . $base_url . '/node/' . $risknid . '">' . $risktitle . '</a></td><td><a href="user/' . $riskowner->uid . '">' . $riskowner->name . '</a></td>';
  }
  $risks = '<p><table><th>Risk</th><th>Owner</th>' . $output_risks . '</table></p>';
  // Get issues from database.
  $issues_results = db_rewrite_sql(db_query('SELECT n.title, i.nid, i.issue_owner_uid FROM {jiscpmissue} i JOIN {node} n ON i.nid = n.nid WHERE i.project_nid = %d', $node->nid));
  while ($issues_rows = db_fetch_object($issues_results)) {
    $issuetitle = $issues_rows->title;
    $issuenid = $issues_rows->nid;
    $issueowner = user_load($issues_rows->issue_owner_uid);
    $output_issues .= '<tr><td><a href="' . $base_url . '/node/' . $issuenid . '">' . $issuetitle . '</a></td><td><a href="user/' . $issueowner->uid . '">' . $issueowner->name . '</a></td>';
  }
  $issues = '<p><table><th>Issue</th><th>Owner</th>' . $output_issues . '</table></p>';
  // Get business case assessments from database.
  $bca_results = db_rewrite_sql(db_query('SELECT n.title, jb.vid FROM {node} n JOIN {jiscpmbca} jb ON n.nid = jb.nid WHERE jb.project_nid = %d', $node->nid));
  while ($bca_rows = db_fetch_object($bca_results)) {
    $bcatitle = $bca_rows->title;
    $bcanid = $bca_rows->vid;
    $output_bcas .= '<tr><td><a href="' . $base_url . '/node/' . $bcanid . '">' . $bcatitle . '</a></td>';
  }
  $bca = '<p><table><th>BCA</th>' . $output_bcas . '</table></p>';
  // Get post project reviews from database.
  $ppr_results = db_rewrite_sql(db_query('SELECT n.title, ppr.vid FROM {node} n JOIN {jiscpmppr} ppr ON n.nid = ppr.nid WHERE ppr.project_nid = %d', $node->nid));
  while ($ppr_rows = db_fetch_object($ppr_results)) {
    $pprtitle = $ppr_rows->title;
    $pprnid = $ppr_rows->vid;
    $output_pprs .= '<tr><td><a href="' . $base_url . '/node/' . $pprnid . '">' . $pprtitle . '</a></td>';
  }
  $ppr = '<p><table><th>PPR</th>' . $output_pprs . '</table></p>';
  // Get status reports from database.
  $sr_results = db_rewrite_sql(db_query('SELECT n.title, sr.vid, sr.sr_start, sr.sr_end FROM {node} n JOIN {jiscpmsr} sr ON n.nid = sr.nid WHERE sr.project_nid = %d ORDER BY sr.sr_start ASC', $node->nid));
  while ($sr_rows = db_fetch_object($sr_results)) {
    $srtitle = $sr_rows->title;
    $srnid = $sr_rows->vid;
    $output_srs .= '<tr><td><a href="' . $base_url . '/node/' . $srnid . '">' . $srtitle . '</a></td><td>' . date('d-m-Y', $sr_rows->sr_start) . ' to ' . date('d-m-Y', $sr_rows->sr_end) . '</td></tr>';
  }
  $sr = '<p><table><th>Status Report</th><th>Timescale</th>' . $output_srs . '</table></p>';
  // Get requests for change from database.
  $rfc_results = db_rewrite_sql(db_query('SELECT n.title, rfc.vid FROM {node} n JOIN {jiscpmrfc} rfc ON n.nid = rfc.nid WHERE rfc.project_nid = %d', $node->nid));
  while ($rfc_rows = db_fetch_object($rfc_results)) {
    $rfctitle = $rfc_rows->title;
    $rfcnid = $rfc_rows->vid;
    $output_rfcs .= '<tr><td><a href="' . $base_url . '/node/' . $rfcnid . '">' . $rfctitle . '</a></td>';
  }
  $rfcs = '<p><table><th>RFC</th>' . $output_rfcs . '</table></p>';
  // Get project relationships data.
  for ($r = 0; $r < count($node->relationships); $r++) {
    $rel_project = node_load($node->relationships[$r]['relationship_nid']);
    $output_r .= '<tr><td><a href="' . $base_url . '/node/' . $rel_project->nid . '">' . $rel_project->title . '</a></td><td>' . $node->relationships[$r]['relationship_description'] . '</td></tr>';
  }
  $relationships = '<p><table><th>Related project</th><th>Relationship Description</th>' . $output_r . '</table></p>';
  // Get project phases data.
  for ($p = 0; $p < count($node->phases); $p++) {
    $output_p .= '<tr><td valign="top"><strong>' . $node->phases[$p]['phase_title'] . '</strong></td><td valign="top">' .
    check_markup($node->phases[$p]['phase_scope'], FILTER_FORMAT_DEFAULT, FALSE) . '</td><td valign="top">' . date('d-m-Y', $node->phases[$p]['phase_datebegin']) . ' - ' . date('d-m-Y', $node->phases[$p]['phase_dateend']) . '</td></tr>';
  }
  $phases = '<p><table><th>Phase</th><th>Phase Description</th><th>Timescale</th>' . $output_p . '</table></p>';
  // Get project stakeholders data.
  for ($s = 0; $s < count($node->stakeholders); $s++) {
    $stake_user = user_load($node->stakeholders[$s]['stakeholder_uid']);
    $output_s .= '<tr><td><a href="?q=user/' . $stake_user->uid . '">' . $stake_user->name . '</a></td><td>' . check_markup($node->stakeholders[$s]['stakeholder_stake_in_project'], FILTER_FORMAT_DEFAULT, FALSE) . '</td></tr>';
  }
  $stakeholders = '<p><table><th>Stakeholder</th><th>Stake in project</th>' . $output_s . '</table></p>';
  // Get project critical success factors data.
  for ($f = 0; $f < count($node->factors); $f++) {
    $output_f .= '<tr><td>' . $node->factors[$f]['factor_title'] . '</a></td><td>' . check_markup($node->factors[$f]['factor_description'], FILTER_FORMAT_DEFAULT, FALSE) . '</td></tr>';
  }
  $factors = '<p><table><th>Critical Success Factor</th><th>Description</th>' . $output_f . '</table></p>';
  // Get project assumptions data.
  for ($a = 0; $a < count($node->assumptions); $a++) {
    $output_a .= '<tr><td>' . $node->assumptions[$a]['assumption_title'] . '</a></td><td>' . check_markup($node->assumptions[$a]['assumption_description'], FILTER_FORMAT_DEFAULT, FALSE) . '</td></tr>';
  }
  $assumptions = '<p><table><th>Assumption</th><th>Description</th>' . $output_a . '</table></p>';
  // Get project constraints data.
  for ($c = 0; $c < count($node->constraints); $c++) {
    $output_c .= '<tr><td>' . $node->constraints[$c]['constraint_title'] . '</a></td><td>' . check_markup($node->constraints[$c]['constraint_description'], FILTER_FORMAT_DEFAULT, FALSE) . '</td></tr>';
  }
  $constraints = '<p><table><th>Constraint</th><th>Description</th>' . $output_c . '</table></p>';
  // Get project goals and objectives data.
  for ($g = 0; $g < count($node->goals); $g++) {
    $output_g .= '<tr><td>' . $node->goals[$g]['goal_title'] . '</a></td><td>' . check_markup($node->goals[$g]['goal_objectives'], FILTER_FORMAT_DEFAULT, FALSE) . '</td></tr>';
  }
  $goals = '<p><table><th>Goal</th><th>Objectives</th>' . $output_g . '</table></p>';
  // Get project milestone data.
  for ($m = 0; $m < count($node->milestones); $m++) {
    $output_m .= '<tr><td>' . $node->milestones[$m]['milestone_title'] . '</a></td><td>' . date('D d M Y', $node->milestones[$m]['milestone_deliverydate']) . '</td></tr>';
  }
  // Get project team data.
  $team_results = db_rewrite_sql(db_query('SELECT n.title, n.nid, t.team_description FROM {node} n JOIN {jiscpmteam} t ON n.nid = t.nid WHERE t.project_nid = %d', $node->nid));
  while ($t_rows = db_fetch_object($team_results)) {
    $ttitle = $t_rows->title;
    $tnid = $t_rows->nid;
    $tdescription = $t_rows->team_description;
    $output_t .= '<tr><td><a href="' . $base_url . '/node/' . $tnid . '">' . $ttitle . '</a></td><td>' . $tdescription . '</td></tr>';
  }
  $sr = '<p><table><th>Status Report</th><th>Timescale</th>' . $output_srs . '</table></p>';
  $teams = '<p><table><th>Team</th><th>Description</th>' . $output_t . '</table></p>';
  $milestones = '<p><table><th>Milestone</th><th>Delivery Date</th>' . $output_m . '</table></p>';
  $node->content['projectcategory'] = array(
    '#prefix' => '<div class="projectcategory"><h2>Project Category</h2>',
    '#suffix' => '</div>',
    '#value' => t($category),
    '#weight' => -20,
  );
  $node->content['projectstatus'] = array(
    '#prefix' => '<div class="projectstatus"><h2>Project Status</h2>',
    '#suffix' => '</div>',
    '#value' => t($status),
    '#weight' => -18,
  );
  $node->content['projectpriority'] = array(
    '#prefix' => '<div class="projectpriority"><h2>Project Priority</h2>',
    '#suffix' => '</div>',
    '#value' => t($priority),
    '#weight' => -17,
  );
  $node->content['manager'] = array(
    '#prefix' => '<div class="manager"><h2>Project Manager</h2>',
    '#suffix' => '</div>',
    '#value' => t($pm_name),
    '#weight' => -16,
  );
  $node->content['assigned'] = array(
    '#prefix' => '<div class="assigned"><h2>Assigned</h2>',
    '#suffix' => '</div>',
    '#value' => t($client_name),
    '#weight' => -15,
  );
  $node->content['datebegin'] = array(
    '#prefix' => '<div class="datebegin"><h2>Date Begin</h2>',
    '#suffix' => '</div>',
    '#value' => t(date('D d M Y', $node->jiscpmprojects[0]['datebegin'])),
    '#weight' => -14,
  );
  $node->content['dateend'] = array(
    '#prefix' => '<div class="dateend"><h2>Date end</h2>',
    '#suffix' => '</div>',
    '#value' => t(date('D d M Y', $node->jiscpmprojects[0]['dateend'])),
    '#weight' => -13,
  );
  $node->content['body_field'] = array(
    '#prefix' => '<div class="jiscpmbody"><h2>Project Overview</h2>',
    '#suffix' => '</div>',
    '#value' => t($node->content['body']['#value']),
    '#weight' => -12,
  );
  // Start Project Scope fieldset.
  $node->content['scope'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Scope'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => -11,
  );
  $node->content['scope']['projectgoals'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Goals and Objectives'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -11,
  );
  $node->content['scope']['projectgoals']['goals'] = array(
    '#prefix' => '<div class="projectgoals">',
    '#suffix' => '</div>',
    '#value' => $goals,
  );
  $node->content['scope']['successfactors'] = array(
    '#type' => 'fieldset',
    '#title' => t('Critical Success Factors'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -10,
  );
  $node->content['scope']['successfactors']['factors'] = array(
    '#prefix' => '<div class="successfactors">',
    '#suffix' => '</div>',
    '#value' => $factors,
  );
  $node->content['scope']['projectscope'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Scope'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -9,
  );
  $node->content['scope']['projectscope']['organisational_scope'] = array(
    '#prefix' => '<div class="projectscope"><h2>Organisational Scope</h2>',
    '#suffix' => '</div>',
    '#value' => check_markup($org_scope, FILTER_FORMAT_DEFAULT, FALSE),
  );
  $node->content['scope']['projectscope']['logical_scope'] = array(
    '#prefix' => '<div class="projectscope"><h2>Logical Scope</h2>',
    '#suffix' => '</div>',
    '#value' => check_markup($log_scope, FILTER_FORMAT_DEFAULT, FALSE),
  );
  $node->content['scope']['projectscope']['out_of_scope'] = array(
    '#prefix' => '<div class="projectscope"><h2>Out of Scope</h2>',
    '#suffix' => '</div>',
    '#value' => check_markup($out_scope, FILTER_FORMAT_DEFAULT, FALSE),
  );
  $node->content['scope']['relatedprojects'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Relationships'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -8,
  );
  $node->content['scope']['relatedprojects']['relationships'] = array(
    '#prefix' => '<div class="relatedprojects">',
    '#suffix' => '</div>',
    '#value' => $relationships,
  );
  // End scope fieldset.
  // Start risks, constraints and assumptions fieldset.
  $node->content['risks_cons_assump'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Risks, Constraints and Assumptions'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => -7,
  );
  $node->content['risks_cons_assump']['projectrisks'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Risks'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -7,
  );
  $node->content['risks_cons_assump']['projectrisks'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Risks'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -7,
  );
  $node->content['risks_cons_assump']['projectrisks']['risks'] = array(
    '#prefix' => '<div class="projectrisks">',
    '#suffix' => '</div>',
    '#value' => $risks,
  );
  $node->content['risks_cons_assump']['projectconstraints'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Constraints'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -6,
  );
  $node->content['risks_cons_assump']['projectconstraints']['constraints'] = array(
    '#prefix' => '<div class="projectconstraints">',
    '#suffix' => '</div>',
    '#value' => $constraints,
  );
  $node->content['risks_cons_assump']['projectassumptions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Assumptions'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -5,
  );
  $node->content['risks_cons_assump']['projectassumptions']['assumptions'] = array(
    '#prefix' => '<div class="projectassumptions">',
    '#suffix' => '</div>',
    '#value' => $assumptions,
  );
  // End risks, constraints and assumptions fieldset.
  // Start stakeholders fieldset.
  $node->content['stakeholders'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Stakeholders'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => -4,
  );
  $node->content['stakeholders']['projectteams'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Teams'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -4,
  );
  $node->content['stakeholders']['projectteams']['teams'] = array(
    '#prefix' => '<div class="projectteams">',
    '#suffix' => '</div>',
    '#value' => $teams,
  );
  $node->content['stakeholders']['projectstakeholders'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Stakeholders'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -3,
  );
  $node->content['stakeholders']['projectstakeholders']['stakeholders'] = array(
    '#prefix' => '<div class="projectstakeholders">',
    '#suffix' => '</div>',
    '#value' => $stakeholders,
  );
  // End stakeholders fieldset.
  // Start project control fieldset.
  $node->content['projectcontrol'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Control'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => -2,
  );
  $node->content['projectcontrol']['projectissues'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Issues'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -2,
  );
  $node->content['projectcontrol']['projectissues']['issues'] = array(
    '#prefix' => '<div class="projectissues">',
    '#suffix' => '</div>',
    '#value' => $issues,
  );
  $node->content['projectcontrol']['projectrfc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Request For Change'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -1,
  );
  $node->content['projectcontrol']['projectrfc']['rfc'] = array(
    '#prefix' => '<div class="projectrfc">',
    '#suffix' => '</div>',
    '#value' => $rfcs,
  );
  // End project control fieldset.
  // Start project planning/scheduling fieldset.
  $node->content['plan_sched'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Planning/Scheduling'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 0,
  );
  $node->content['plan_sched']['projectphases'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Phases'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 0,
  );
  $node->content['plan_sched']['projectphases']['phases'] = array(
    '#prefix' => '<div class="projectphases">',
    '#suffix' => '</div>',
    '#value' => $phases,
  );
  $node->content['plan_sched']['projectmilestones'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Milestones'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 1,
  );
  $node->content['plan_sched']['projectmilestones']['milestones'] = array(
    '#prefix' => '<div class="projectmilestones">',
    '#suffix' => '</div>',
    '#value' => $milestones,
  );
  // End project planning/scheduling fieldset.
  // Start PM documentation fieldset.
  $node->content['pmdoc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Management Documentation'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 2,
  );
  $node->content['pmdoc']['projectbca'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Business Case Assessment'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 2,
  );
  $node->content['pmdoc']['projectbca']['bca'] = array(
    '#prefix' => '<div class="projectbca">',
    '#suffix' => '</div>',
    '#value' => $bca,
  );
  $node->content['pmdoc']['projectsr'] = array(
    '#type' => 'fieldset',
    '#title' => t('Status Reports'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 3,
  );
  $node->content['pmdoc']['projectsr']['sr'] = array(
    '#prefix' => '<div class="projectsr">',
    '#suffix' => '</div>',
    '#value' => $sr,
  );
  $node->content['pmdoc']['projectppr'] = array(
    '#type' => 'fieldset',
    '#title' => t('Project Post Project Review'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 4,
  );
  $node->content['pmdoc']['projectppr']['ppr'] = array(
    '#prefix' => '<div class="projectppr">',
    '#suffix' => '</div>',
    '#value' => $ppr,
  );
  // End PM documentation fieldset.
  unset($node->content['body']);
  return $node;
}
