<?php
/**
 * @file
 */

/**
 * @function
 * List of BCAs.
 */
function theme_jiscpmbca_list($header, $bcas) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm.css', 'module');
}
/**
 * @function
 * View of BCAs.
 */
function theme_jiscpmbca_view($node, $teaser = FALSE, $page = FALSE) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');
  $node = node_prepare($node, $teaser);
  // Generate output for jiscpm bca actions.
  for ($a = 0; $a < count($node->actions); $a++) {
    $actions .= '<tr><td>' . $node->actions[$a]['action_title'] . '</td><td>' . check_markup($node->actions[$a]['action_description'], FILTER_FORMAT_DEFAULT, FALSE) . '</td><td>' . date('d M Y', $node->actions[$a]['action_deliverydate']) . '</td></tr>';
  }
  $actions .= '</table></p>';
  $staffcosts .= '<p><table><th>Title</th><th>Quantity</th><th>Hours</th><th>Rate</th>';
  // Generate output for jiscpm bca staff costs.
  for ($s = 0; $s < count($node->staff_costs); $s++) {
    $user = user_load($node->staff_costs[$s]['staff_cost_title']);
    $staffcosts .= '<tr><td><a href="?q=user/' . $user->uid . '">' . $user->name . '</a></td><td>' . $node->staff_costs[$s]['staff_cost_quantity'] . '</td><td>' . $node->staff_costs[$s]['staff_cost_hours'] . '</td><td>' . $node->staff_costs[$s]['staff_cost_rate'] . '</td></tr>';
  }
  $staffcosts .= '</table></p>';
  // Generate output for jiscpm bca training costs.
  $trainingcosts .= '<p><table><th>Title</th><th>Description</th><th>Total</th>';
  for ($t = 0; $t < count($node->training_costs); $t++) {
    $trainingcosts .= '<tr><td>' . $node->training_costs[$t]['training_cost_title'] . '</td><td>' . check_markup($node->training_costs[$t]['training_cost_description'], FILTER_FORMAT_DEFAULT, FALSE) . '</td><td>' . $node->training_costs[$t]['training_cost_total'] . '</td></tr>';
  }
  $trainingcosts .= '</table></p>';
  // Generate output for jiscpm bca equipment costs.
  $equipmentcosts .= '<p><table><th>Title</th><th>Description</th><th>Total</th>';
  for ($e = 0; $e < count($node->equipment_costs); $e++) {
    $equipmentcosts .= '<tr><td>' . $node->equipment_costs[$e]['equipment_cost_title'] . '</td><td>' . check_markup($node->equipment_costs[$e]['equipment_cost_description'], FILTER_FORMAT_DEFAULT, FALSE) . '</td><td>' . $node->equipment_costs[$e]['equipment_cost_total'] . '</td></tr>';
  }
  $equipmentcosts .= '</table></p>';
  // Generate output for jiscpm bca other costs.
  $othercosts .= '<p><table><th>Title</th><th>Description</th><th>Total</th>';
  for ($o = 0; $o < count($node->other_costs); $o++) {
    $othercosts .= '<tr><td>' . $node->other_costs[$o]['other_cost_title'] . '</td><td>' . check_markup($node->other_costs[$o]['other_cost_description'], FILTER_FORMAT_DEFAULT, FALSE) . '</td><td>' . $node->other_costs[$o]['other_cost_total'] . '</td></tr>';
  }
  $othercosts .= '</table></p>';
  // Generate output for jiscpm bca running costs training.
  $runningcoststraining .= '<p><table><th>Title</th><th>Description</th><th>Total</th>';
  for ($rct = 0; $rct < count($node->running_cost_trainings); $rct++) {
    $runningcoststraining .= '<tr><td>' . $node->running_cost_trainings[$rct]['running_cost_training_title'] . '</td><td>' . check_markup($node->running_cost_trainings[$rct]['running_cost_training_description'], FILTER_FORMAT_DEFAULT, FALSE) . '</td><td>' . $node->running_cost_trainings[$rct]['running_cost_training_total'] . '</td></tr>';
  }
  $runningcoststraining .= '</table></p>';
  // Generate output for jiscpm bca running costs licensing.
  $runningcostslicensing .= '<p><table><th>Title</th><th>Description</th><th>Total</th>';
  for ($rcl = 0; $rcl < count($node->running_cost_licensings); $rcl++) {
    $runningcostslicensing .= '<tr><td>' . $node->running_cost_licensings[$rcl]['running_cost_licensing_title'] . '</td><td>' . check_markup($node->running_cost_licensings[$rcl]['running_cost_licensing_description'], FILTER_FORMAT_DEFAULT, FALSE) . '</td><td>' . $node->running_cost_licensings[$rcl]['running_cost_licensing_total'] . '</td></tr>';
  }
  $runningcostslicensing .= '</table></p>';
  // Generate output for running costs maintenance.
  $runningcostsmaintenance .= '<p><table><th>Title</th><th>Description</th><th>Total</th>';
  for ($rcm = 0; $rcm < count($node->running_cost_maintenances); $rcm++) {
    $runningcostsmaintenance .= '<tr><td>' . $node->running_cost_maintenances[$rcm]['running_cost_maintenance_title'] . '</td><td>' . check_markup($node->running_cost_maintenances[$rcm]['running_cost_maintenance_description'], FILTER_FORMAT_DEFAULT, FALSE) . '</td><td>' . $node->running_cost_maintenances[$rcm]['running_cost_maintenance_total'] . '</td></tr>';
  }
  $runningcostsmaintenance .= '</table></p>';
  // Generate output for jiscpm bca running costs other.
  $runningcostsother .= '<p><table><th>Title</th><th>Description</th><th>Total</th>';
  for ($rco = 0; $rco < count($node->running_cost_others); $rco++) {
    $runningcostsother .= '<tr><td>' . $node->running_cost_others[$rco]['running_cost_other_title'] . '</td><td>' . check_markup($node->running_cost_others[$rco]['running_cost_other_description'], FILTER_FORMAT_DEFAULT, FALSE) . '</td><td>' . $node->running_cost_others[$rco]['running_cost_other_total'] . '</td></tr>';
  }
  $runningcostsother .= '</table></p>';
  $node->content['group1'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );
  $node->content['group2'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -23,
  );
  // Load project.
  $project = node_load($node->jiscpmbcas[0]['project_nid']);
  $node->content['group2']['bcaproject'] = array(
    '#prefix' => '<div class="bcaproject">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Project'), l($project->title, 'node/' . $project->nid)),
    '#weight' => -23,
  );
  $node->content['group9'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group9') : -22,
  );
  $node->content['group9']['actionsfieldset'] = array(
    '#title' => t('Project Actions'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -22,
  );
  $node->content['group9']['actionsfieldset']['bcaactions'] = array(
    '#prefix' => '<div class="bcaactions">',
    '#suffix' => '</div>',
    '#value' => t($actions),
    '#weight' => -22,
  );
  $node->content['group18'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group18') : -21,
  );
  $node->content['group18']['strategiesfieldset'] = array(
    '#title' => t('Project Strategies'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -21,
  );
  $node->content['group18']['strategiesfieldset'] ['strategies'] = array(
    '#prefix' => '<div class="bca-strategies">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->jiscpmbcas[0]['bca_strategies'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => -21,
  );
  $node->content['group19'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group19') : -20,
  );
  $node->content['group19']['benefitsfieldset'] = array(
    '#title' => t('Project Benefits'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => -20,
  );
  $node->content['group19']['benefitsfieldset']['bcabenefits'] = array(
    '#prefix' => '<div class="bcabenefits">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->jiscpmbcas[0]['bca_benefits'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => -20,
  );
  $node->content['group5'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -19,
  );
  $node->content['group5']['bcaimplications'] = array(
    '#title' => t('Implications of not undertaking project'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $node->content['group5']['bcaimplications']['implications'] = array(
    '#prefix' => '<div class="bcaimplications">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->jiscpmbcas[0]['bca_implications'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => -19,
  );
  $node->content['group6'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group6') : -18,
  );
  $node->content['group6']['bcaalternatives'] = array(
    '#title' => t('Alternatives'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $node->content['group6']['bcaalternatives']['Alternatives'] = array(
    '#prefix' => '<div class="bcaalternatives">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->jiscpmbcas[0]['bca_alternatives'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => -15,
  );
  $node->content['group7'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group7') : -17,
  );
  $node->content['group7']['bcaorganisationalareas'] = array(
    '#title' => t('Organisational Areas Affected'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $node->content['group7']['bcaorganisationalareas']['bca_staff_changes'] = array(
    '#value' => check_markup($node->jiscpmbcas[0]['bca_staff_changes'], FILTER_FORMAT_DEFAULT, FALSE),
    '#prefix' => '<div class="jiscpmbca-staff-changes"><h2>Staff Changes</h2>',
    '#suffix' => '</div>',
  );
  $node->content['group7']['bcaorganisationalareas']['bca_hr_related_issues'] = array(
    '#value' => check_markup($node->jiscpmbcas[0]['bca_hr_related_issues'], FILTER_FORMAT_DEFAULT, FALSE),
    '#prefix' => '<div class="jiscpmbca-hr-related-issues"><h2>HR Related Issues</h2>',
    '#suffix' => '</div>',
  );
  $node->content['group7']['bcaorganisationalareas']['bca_changes_technology'] = array(
    '#value' => check_markup($node->jiscpmbcas[0]['bca_changes_technology'], FILTER_FORMAT_DEFAULT, FALSE),
    '#prefix' => '<div class="jiscpmbca-changes-technology"><h2>Changes to technology</h2>',
    '#suffix' => '</div>',
  );
  $node->content['group7']['bcaorganisationalareas']['bca_process_changes'] = array(
    '#value' => check_markup($node->jiscpmbcas[0]['bca_process_changes'], FILTER_FORMAT_DEFAULT, FALSE),
    '#prefix' => '<div class="jiscpmbca-process-changes"><h2>Process Changes</h2>',
    '#suffix' => '</div>',
  );
  $node->content['group7']['bcaorganisationalareas']['bca_internal_support'] = array(
    '#value' => check_markup($node->jiscpmbcas[0]['bca_internal_support'], FILTER_FORMAT_DEFAULT, FALSE),
    '#prefix' => '<div class="jiscpmbca-internal-support"><h2>Internal Support</h2>',
    '#suffix' => '</div>',
  );
  $node->content['group7']['bcaorganisationalareas']['bca_external_suppport'] = array(
    '#value' => check_markup($node->jiscpmbcas[0]['bca_external_support'], FILTER_FORMAT_DEFAULT, FALSE),
    '#prefix' => '<div class="jiscpmbca-external-support"><h2>External Support</h2>',
    '#suffix' => '</div>',
  );
  $node->content['group8'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group8') : -18,
  );
  $node->content['group8']['bcapayback'] = array(
    '#title' => t('Payback'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $node->content['group8']['bcapayback']['payback'] = array(
    '#prefix' => '<div class="bcapayback">',
    '#suffix' => '</div>',
    '#value' => check_markup($node->jiscpmbcas[0]['bca_payback'], FILTER_FORMAT_DEFAULT, FALSE),
    '#weight' => -22,
  );
  $node->content['group10'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group10') : -16,
  );
  $node->content['group10']['stafffieldset'] = array(
    '#title' => t('Staff Costs'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $node->content['group10']['stafffieldset']['bcastaffcosts'] = array(
    '#prefix' => '<div class="bcastaffcosts"><h2>Staff Costs</h2>',
    '#suffix' => '</div>',
    '#value' => t($staffcosts),
  );
  $node->content['group11'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group11') : -15,
  );
  $node->content['group11']['trainingfieldset'] = array(
    '#title' => t('Training Costs'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $node->content['group11']['trainingfieldset']['bcatrainingcosts'] = array(
    '#prefix' => '<div class="bcatrainingcosts"><h2>Training Costs</h2>',
    '#suffix' => '</div>',
    '#value' => t($trainingcosts),
  );
  $node->content['group12'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group12') : -14,
  );
  $node->content['group12']['equipmentfieldset'] = array(
    '#title' => t('Equipment Costs'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $node->content['group12']['equipmentfieldset']['bcaequipmentcosts'] = array(
    '#prefix' => '<div class="bcaequipmentcosts"><h2>Equipment Costs</h2>',
    '#suffix' => '</div>',
    '#value' => t($equipmentcosts),
  );
  $node->content['group13'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group13') : -13,
  );
  $node->content['group13']['otherfieldset'] = array(
    '#title' => t('Other Costs'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $node->content['group13']['otherfieldset'] ['bcaothercosts'] = array(
    '#prefix' => '<div class="bcaothercosts"><h2>Other Costs</h2>',
    '#suffix' => '</div>',
    '#value' => t($othercosts),
  );
  $node->content['group14'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group14') : -12,
  );
  $node->content['group14']['runtrainfieldset'] = array(
    '#title' => t('Training Running Costs'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $node->content['group14']['runtrainfieldset']['bcarunningcoststraining'] = array(
    '#prefix' => '<div class="bcarunningcoststraining"><h2>Training Running Costs</h2>',
    '#suffix' => '</div>',
    '#value' => t($runningcoststraining),
  );
  $node->content['group15'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group15') : -11,
  );
  $node->content['group15']['runlicfieldset'] = array(
    '#title' => t('Licensing Running Costs'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $node->content['group15']['runlicfieldset']['bcarunningcostslicensing'] = array(
    '#prefix' => '<div class="bcarunningcostslicensing"><h2>Licensing Running Costs</h2>',
    '#suffix' => '</div>',
    '#value' => t($runningcostslicensing),
  );
  $node->content['group16'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group16') : -10,
  );
  $node->content['group16']['runmainfieldset'] = array(
    '#title' => t('Maintenance Running Costs'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $node->content['group16']['runmainfieldset']['bcarunningcostsmaintenance'] = array(
    '#prefix' => '<div class="bcarunningcostsmaintenance"><h2>Maintenance Running Costs</h2>',
    '#suffix' => '</div>',
    '#value' => t($runningcostsmaintenance),
  );
  $node->content['group17'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group16') : -9,
  );
  $node->content['group17']['runotherfieldset'] = array(
    '#title' => t('Other Running Costs'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $node->content['group17']['runotherfieldset']['bcarunningcostsother'] = array(
    '#prefix' => '<div class="bcarunningcostsother"><h2>Other Running Costs</h2>',
    '#suffix' => '</div>',
    '#value' => t($runningcostsother),
  );
  return $node;
}
