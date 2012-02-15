<?php
/**
* @file
*/

function theme_jiscpmsdd_list($header, $srs) {
drupal_add_css(drupal_get_path('module', 'jiscpm') .'/jiscpm.css', 'module');
}

function theme_jiscpmsdd_view($node, $teaser = FALSE, $page = FALSE) {
drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');

$node = node_prepare($node, $teaser);
//get user classes from database
for ($f = 0; $f < count($node->userclasses); $f ++) {
$user_classes_data .= '<tr><td>' . $node->userclasses[$f]['user_class_name'] . '</a></td><td>' . check_markup($node->userclasses[$f]['user_class_characteristics'], FILTER_FORMAT_DEFAULT, FALSE) . '</td></tr>';
}
$userclasses = '<p><table><th>User Class</th><th>Characteristics</th>' . $user_classes_data . '</table></p>';
//get functional requirements from database
for ($a = 0; $a < count($node->functional); $a ++) {
$functional_data .= '<tr><td>' . $node->functional[$a]['functional_req_desc'] . '</a></td><td>' . check_markup($node->functional[$a]['functional_req_imp'], FILTER_FORMAT_DEFAULT, FALSE) . '</td></tr>';
}
$functionalrequirements = '<p><table><th>Functional Requirement</th><th>Implementation</th>' . $functional_data . '</table></p>';
//get non functional requirements from database
for ($b = 0; $b < count($node->non_functional); $b ++) {
$non_functional_data .= '<tr><td>' . $node->non_functional[$b]['non_functional_req_desc'] . '</a></td><td>' . check_markup($node->non_functional[$b]['non_functional_req_imp'], FILTER_FORMAT_DEFAULT, FALSE) . '</td></tr>';
}
$nonfunctionalrequirements = '<p><table><th>Non Functional Requirement</th><th>Implementation</th>' . $non_functional_data . '</table></p>';
//get terms and definitions from database
for ($c = 0; $c < count($node->definition); $c ++) {
$definition_data .= '<tr><td>' . $node->definition[$c]['definition_term'] . '</a></td><td>' . check_markup($node->definition[$c]['definition_of_term'], FILTER_FORMAT_DEFAULT, FALSE) . '</td></tr>';
}
$definitions = '<p><table><th>Term</th><th>Definition</th>' . $definition_data . '</table></p>';
/* Start output */
$node->content['group1'] = array( 
'#prefix' => '<div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
);
$loadproject = node_load($node->jiscpmsdds[0]['project_nid']);
$node->content['group1']['project'] = array(
'#prefix' => '<div class="project">',
'#suffix' => '</div>',
'#value' => theme('jiscpm_view_item', t('Project'), l($loadproject->title, 'node/'. $loadproject->nid)),
'#weight' => -20,
);
//load project manager info and display
$project_manager = array();
$results = db_query('SELECT project_manager_uid FROM {jiscpmproject} WHERE nid = %d', $loadproject->nid);
while ($rows = db_fetch_object($results)) {
$project_manager = user_load($rows->project_manager_uid);
}
if ($project_manager->uid != -1) {
$node->content['projectmanager'] = array(
'#prefix' => '<div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'projectmanager') : -19,
'#value' => theme('jiscpm_view_item', t('Project Manager'), l($project_manager->name, 'user/'. $project_manager->uid)),
);
}
else {  
}
$node->content['group3'] = array(
'#prefix' => '<div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group3') : -18,
);

$node->content['group3']['system_overview'] = array(
'#value' => theme('jiscpm_view_item', t('System Overview'), check_markup($node->jiscpmsdds[0]['system_overview'], FILTER_FORMAT_DEFAULT, FALSE)),
);
$node->content['group2'] = array(
'#prefix' => '<div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -17,
);

$node->content['group2']['system_architecture'] = array(
'#value' => theme('jiscpm_view_item', t('System Architecture'), check_markup($node->jiscpmsdds[0]['system_architecture'], FILTER_FORMAT_DEFAULT, FALSE)),
'#weight' => 1,
);

$node->content['group9'] = array( 
'#prefix' => '<div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group9') : -16,
);
$node->content['group9']['data_design'] = array(
'#value' => theme('jiscpm_view_item', t('Data Design'), check_markup($node->jiscpmsdds[0]['data_design'], FILTER_FORMAT_DEFAULT, FALSE)),
'#weight' => 0,
);
$node->content['group4'] = array( 
'#prefix' => '<div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group4') : -15,
);
$node->content['group4']['component_design'] = array(
'#value' => theme('jiscpm_view_item', t('Component Design'), check_markup($node->jiscpmsdds[0]['component_design'], FILTER_FORMAT_DEFAULT, FALSE)),
);
$node->content['group11'] = array( 
'#prefix' => '<div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group11') : -14,
);
$node->content['group11']['user_interfaces'] = array(
'#value' => theme('jiscpm_view_item', t('User Interfaces'), check_markup($node->jiscpmsdds[0]['user_interfaces'], FILTER_FORMAT_DEFAULT, FALSE)),
);
$node->content['group12'] = array( 
'#prefix' => '<div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group12') : -13,
);
$node->content['group12']['hardware_interfaces'] = array(
'#value' => theme('jiscpm_view_item', t('Hardware Interfaces'), check_markup($node->jiscpmsdds[0]['hardware_interfaces'], FILTER_FORMAT_DEFAULT, FALSE)),
);

$node->content['group5'] = array(
'#prefix' => '<div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -12,
);

$node->content['group5']['software_interfaces'] = array(
'#value' => theme('jiscpm_view_item', t('Software Interfaces'), check_markup($node->jiscpmsdds[0]['software_interfaces'], FILTER_FORMAT_DEFAULT, FALSE)),
'#weight' => 1,
);

$node->content['group6'] = array(
'#prefix' => '<div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group6') : -11,
);

$node->content['group6']['user_documentation'] = array(
'#value' => theme('jiscpm_view_item', t('User Documentation'), check_markup($node->jiscpmsdds[0]['user_documentation'], FILTER_FORMAT_DEFAULT, FALSE)),
'#weight' => 2,
);

$node->content['group7'] = array(
'#prefix' => '<h2>User Classes</h2><div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group7') : -10,
);

$node->content['group7']['user_classes'] = array(
'#value' => $userclasses,
'#weight' => 2,
);
$node->content['group8'] = array(
'#prefix' => '<h2>Functional Requirements</h2><div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group8') : -9,
);

$node->content['group8']['user_classes'] = array(
'#value' => $functionalrequirements,
'#weight' => 2,
);
$node->content['group13'] = array(
'#prefix' => '<h2>Non Functional Requirements</h2><div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group13') : -8,
);

$node->content['group13']['user_classes'] = array(
'#value' => $nonfunctionalrequirements,
'#weight' => 2,
);
$node->content['group14'] = array(
'#prefix' => '<h2>Terms and Definitions</h2><div class="jiscpmfields">',
'#suffix' => '</div>',
'#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group14') : -7,
);

$node->content['group14']['user_classes'] = array(
'#value' => $definitions,
'#weight' => 2,
);


return $node;
}