<?php
/**
 * @file
 * Themeing file for jiscpm module.
 */

/**
 * @function
 * Add jiscpm stylesheet and assign classes to data.
 */
function theme_jiscpm_form_group($form) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm.css', 'module');

  $row = array();
  foreach (element_children($form) as $key) {
    array_push($row, drupal_render($form[$key]));
  }
  $rows[] = array('data' => $row, 'class' => 'formgroup');
  $output .= theme('table', array(), $rows, array('class' => 'formgroup'));
  return $output;
}
/**
 * @function
 * Themeing date/time displays by adding class.
 */
function theme_jiscpm_datetime($element) {
  return theme('form_element', $element, '<div class="container-inline">' . $element['#children'] . '</div>');
}
/**
 * @function
 * Themeing dateext displays by addign class.
 */
function theme_jiscpm_dateext($element) {
  return theme('form_element', $element, '<div class="container-inline">' . $element['#children'] . '</div>');
}
/**
 * @function
 * Themeing for jiscpm list report.
 */
function theme_jiscpm_list_report($header, $rows, $title, $footer) {
  $css_all_file = drupal_get_path('module', 'jiscpm') . '/jiscpm_list_report_all.css';
  $css_print_file = drupal_get_path('module', 'jiscpm') . '/jiscpm_list_report_print.css';
  $query_string = '?' . drupal_substr(variable_get('css_js_query_string', '0'), 0, 1);

  $o = "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n";
  $o .= '<html xmlns="http://www.w3.org/1999/xhtml">';
  $o .= '<head>';
  $o .= '<title>' . (drupal_get_title() ? strip_tags(drupal_get_title()) : variable_get('site_name', 'Drupal')) . '</title>';
  $o .= '<link type="text/css" rel="stylesheet" media="all" href="' . base_path() . $css_all_file . $query_string . '" />';
  $o .= '<link type="text/css" rel="stylesheet" media="print" href="' . base_path() . $css_print_file . $query_string . '" />';
  $o .= '</head>';
  $o .= '<body>';
  $o .= '<table class="jiscpm_report_header"><tr>';
  $o .= '<td class="jiscpm_report_myorganization">';
  $o .= '<div class="site_name">' . variable_get('site_name', '') . '</div>';
  $o .= '<div class="site_slogan">' . variable_get('site_slogan', '') . '</div>';
  $o .= '</td>';  $o .= '<td class="jiscpm_report_header">' . variable_get('jiscpm_report_header', '') . '</td>';
  $o .= '</tr></table>';
  $o .= '<div class="jiscpm_list_report_title">' . $title . '</div>';
  $o .= '<div class="jiscpm_list_report_data">';
  $o .= theme('table', $header, $rows);
  $o .= '</div>';
  $o .= '<div class="jiscpm_list_report_footer">' . $footer . '</div>';
  $o .= '</body>';
  $o .= '</html>';

  return $o;
}
/**
 * @function
 * Themeing for jiscpm report.
 */
function theme_jiscpm_report($header, $content, $title, $footer, $headtitle = '') {
  $css_all_file = drupal_get_path('module', 'jiscpm') . '/jiscpm_report_all.css';
  $css_print_file = drupal_get_path('module', 'jiscpm') . '/jiscpm_report_print.css';
  $query_string = '?' . drupal_substr(variable_get('css_js_query_string', '0'), 0, 1);

  $o = "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n";
  $o .= '<html xmlns="http://www.w3.org/1999/xhtml">';
  $o .= '<head>';
  $o .= '<title>' . ($headtitle ? strip_tags($headtitle) : $title) . '</title>';
  $o .= '<link type="text/css" rel="stylesheet" media="all" href="' . base_path() . $css_all_file . $query_string . '" />';
  $o .= '<link type="text/css" rel="stylesheet" media="print" href="' . base_path() . $css_print_file . $query_string . '" />';
  $o .= '</head>';
  $o .= '<body>';
  $o .= '<table class="jiscpm_report_header"><tr>';
  $myorg = node_load(variable_get('jiscpm_organization_nid', 0));
  $o .= '<td class="jiscpm_report_myorganization">';
  $o .= '<div class="site_name">' . variable_get('site_name', '') . '</div>';
  $o .= '<div class="site_slogan">' . variable_get('site_slogan', '') . '</div>';
  $o .= '</td>';
  $o .= '<td class="jiscpm_report_header">' . variable_get('jiscpm_report_header', '') . '</td>';
  $o .= '</tr></table>';
  $o .= '<div class="jiscpm_report_title">' . $title . '</div>';
  $o .= '<div id="jiscpm_report_content">';
  $o .= $content;
  $o .= '</div>';
  $o .= '<div class="jiscpm_report_footer">' . $footer . '</div>';
  $o .= '</body>';
  $o .= '</html>';

  return $o;
}
/**
 * @function
 * Themeing for jiscpm view item.
 */
function theme_jiscpm_view_item($label, $value) {
  $o = '<div class="label"><span class="label">' . $label . ':&nbsp;</span></div><div class="value">' . $value . '&nbsp;</div>';
  return $o;
}

/**
 * @function
 * Themeing for jiscpm dashboard.
 */
function theme_jiscpm_dashboard() {
  $o = '<div id="jiscpmdashboard">';
  $o .= '<dl class="jiscpmdashboard">';
  $o .= '<div class="jiscpmdashboard">';
  $o .= theme('jiscpm_link', '', 'jiscpmorganization');
  $o .= theme('jiscpm_link', '', 'jiscpmperson');
  $o .= theme('jiscpm_link', '', 'jiscpmteam');
  $o .= theme('jiscpm_link', '', 'jiscpmproject');
  $o .= theme('jiscpm_link', '', 'jiscpmtask');
  $o .= theme('jiscpm_link', '', 'jiscpmticket');
  $o .= theme('jiscpm_link', '', 'jiscpmtimetracking');
  $o .= '</div>';
  $o .= '<div class="jiscpmdashboard">';
  $o .= theme('jiscpm_link', '', 'jiscpmnote');
  $o .= theme('jiscpm_link', '', 'jiscpminvoice');
  $o .= theme('jiscpm_link', '', 'jiscpmexpense');
  $o .= theme('jiscpm_link', '', 'jiscpmknowledgebase');
  $o .= theme('jiscpm_link', '', 'jiscpmattribute');
  $o .= theme('jiscpm_link', '', 'jiscpmconfiguration');
  $o .= '</div>';
  $o .= '</dl>';
  $o .= '</div>';
  return $o;
}
/**
 * @function
 * Themeing for jiscpm links.
 */
function theme_jiscpm_link($source_module = '', $destination_module = '', $node_nid = 0, $weight = 0) {
  switch ($source_module) {
    case "jiscpmorganization":
      $params_key = 'organization_nid';
      break;

    case "jiscpmproject":
      $params_key = 'project_nid';
      break;

    case "jiscpmtask":
      $params_key = 'task_nid';
      break;

    case "jiscpmticket":
      $params_key = 'ticket_nid';
      break;
  }

  switch ($destination_module) {
    case "jiscpmattribute":
      $user_access_check = 'jiscpm: access administration pages';
      $list_text = t('Attributes');
      $list_path = 'jiscpm/dashboard/attributes/';
      $add_icon_type = 'jiscpmattribute';
      $add_path = 'jiscpm/attributes/add';
      $dt_id = 'jiscpmattributes';
      break;

    case "jiscpmconfiguration":
      $user_access_check = 'jiscpm: access administration pages';
      $list_text = t('Configuration');
      $list_path = 'admin/settings/jiscpm';
      $add_icon_type = '';
      $add_path = '';
      $dt_id = 'jiscpmconfiguration';
      break;

    case "jiscpmexpense":
      $user_access_check = 'jiscpm expense: access';
      $list_text = t('Expenses');
      $list_path = 'jiscpm/dashboard/expenses/';
      $add_icon_type = 'jiscpmexpense';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'jiscpmexpenses';
      break;

    case "jiscpminvoice":
      $user_access_check = 'jiscpm invoice: access';
      $list_text = t('Invoices');
      $list_path = 'jiscpm/dashboard/invoices/';
      $add_icon_type = 'jiscpminvoice';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'jiscpminvoices';
      break;

    case "jiscpmknowledgebase":
      $user_access_check = 'jiscpm knowledgebase: access';
      $list_text = t('Knowledge base');
      $list_path = 'jiscpm/dashboard/knowledgebase/';
      $add_icon_type = 'jiscpmknowledgebase';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'jiscpmknowledgebase';
      break;

    case "jiscpmnote":
      $user_access_check = 'jiscpm note: access';
      $list_text = t('Notes');
      $list_path = 'jiscpm/dashboard/notes/';
      $add_icon_type = 'jiscpmnote';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'jiscpmnotes';
      break;

    case "jiscpmorganization":
      $user_access_check = 'jiscpm organization: access';
      $list_text = t('Organizations');
      $list_path = 'jiscpm/dashboard/organizations/';
      $add_icon_type = 'jiscpmorganization';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'jiscpmorganizations';
      break;

    case "jiscpmperson":
      $user_access_check = 'jiscpm person: access';
      $list_text = t('People');
      $list_path = 'jiscpm/dashboard/people/';
      $add_icon_type = 'jiscpmperson';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'jiscpmpeople';
      break;

    case "jiscpmproject":
      $user_access_check = 'jiscpm project: access';
      $list_text = t('Projects');
      $list_path = 'jiscpm/dashboard/projects/';
      $add_icon_type = 'jiscpmproject';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'jiscpmprojects';
      break;

    case "jiscpmtask":
      $user_access_check = 'jiscpm task: access';
      $list_text = t('Tasks');
      $list_path = 'jiscpm/dashboard/tasks/';
      $add_icon_type = 'jiscpmtask';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'jiscpmtasks';
      break;

    case "jiscpmteam":
      $user_access_check = 'jiscpm team: access';
      $list_text = t('Teams');
      $list_path = 'jiscpm/dashboard/teams/';
      $add_icon_type = 'jiscpmteam';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'jiscpmteams';
      break;

    case "jiscpmticket":
      $user_access_check = 'jiscpm ticket: access';
      $list_text = t('Tickets');
      $list_path = 'jiscpm/dashboard/tickets/';
      $add_icon_type = 'jiscpmticket';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'jiscpmtickets';
      break;

    case "jiscpmtimetracking":
      $user_access_check = 'jiscpm timetracking: access';
      $list_text = t('Timetrackings');
      $list_path = 'jiscpm/dashboard/timetrackings/';
      $add_icon_type = 'jiscpmtimetracking';
      $node_links_key = 'timetrackings';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'jiscpmtimetrackings';

      break;
  }

  if (($destination_module == 'jiscpmconfiguration' && user_access($user_access_check)) || (module_exists($destination_module) && user_access($user_access_check))) {
    if ($node_nid == 0) {
      $params = array();
    }
    else {
      $params = array('query' => array($params_key => $node_nid));
    }
    $v = l($list_text, $list_path, $params);
    if (!$add_icon_type == '') {
      $i->type = $add_icon_type;
      if ($node_nid == 0) {
        $params = $_GET;
      }
      else {
        $params = $_GET;
        $params[$params_key] = $node_nid;
      }
      $v .= jiscpm_icon_add($add_path, $i, $params);
    }
    if ($node_nid == 0) {
      $r = variable_get('jiscpm_icons_display', TRUE) ? '<dt id="' . $dt_id . '" class="jiscpmcomponent">' : '<dt class="jiscpmcomponent">';
      $r .= $v;
      $r .= '</dt>';
    }
    else {
      $r = array(
        '#prefix' => variable_get('jiscpm_icons_display', TRUE) ? '<dt id="' . $dt_id . '" class="jiscpmcomponent">' : '<dt class="jiscpmcomponent">',
        '#suffix' => '</dt>',
        '#value' => $v,
        '#weight' => $weight,
      );
    }
    return $r;
  }
}
