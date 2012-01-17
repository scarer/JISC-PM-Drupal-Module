<?php
// $Id: jiscpmattribute.admin.inc,v 1.5.4.16 2009/12/12 22:02:18 magnity Exp $

/**
 * @file
 */

function jiscpmattribute_list() {
  $i = new stdClass();
  $i->type = 'jiscpmattribute';

  $header = array(
    array(
      'data' => t('Domain'),
      'field' => 'domain',
    ),
    array(
      'data' => t('Key'),
      'field' => 'akey',
    ),
    array(
      'data' => t('Value'),
      'field' => 'avalue',
    ),
    array(
      'data' => t('Active'),
    ),
    array(
      'data' => t('Default'),
    ),
    array(
      'data' => t('Weight'),
      'field' => 'weight',
      'sort' => 'asc',
    ),
    array(
      'data' => jiscpm_icon_add('jiscpm/attributes/add', $i, $_GET),
      'class' => 'jiscpm_list_operations',
    ),
  );

  $s = "SELECT * FROM {jiscpmattribute}";
  $where = array();
  $args = array();
  $filterfields = array();

  if ($_SESSION['jiscpmattribute_list_filter']['domain']) {
    $where[] = "domain='%s'";
    $args[] = $_SESSION['jiscpmattribute_list_filter']['domain'];
    $filterfields[] = t('Domain');
  }

  if ($_SESSION['jiscpmattribute_list_filter']['akey']) {
    $where[] = "LOWER(akey) LIKE LOWER('%s')";
    $args[] = $_SESSION['jiscpmattribute_list_filter']['akey'];
    $filterfields[] = t('Key');
  }

  if ($_SESSION['jiscpmattribute_list_filter']['avalue']) {
    $where[] = "LOWER(avalue) LIKE LOWER('%s')";
    $args[] = $_SESSION['jiscpmattribute_list_filter']['avalue'];
    $filterfields[] = t('Value');
  }

  if (isset($_SESSION['jiscpmattribute_list_filter']['isactive']) && ($_SESSION['jiscpmattribute_list_filter']['isactive'] != '-')) {
    $where[] = "isactive = %d";
    $args[] = $_SESSION['jiscpmattribute_list_filter']['isactive'];
    $filterfields[] = t('Active');
  }
  
  if (isset($_SESSION['jiscpmattribute_list_filter']['isdefault']) && ($_SESSION['jiscpmattribute_list_filter']['isdefault'] != '-')) {
    $where[] = "isdefault = %d";
    $args[] = $_SESSION['jiscpmattribute_list_filter']['isdefault'];
    $filterfields[] = t('Default');
  }
  
  $itemsperpage = $_SESSION['jiscpmattribute_list_filter']['itemsperpage'];
  if (!$itemsperpage) {
    $itemsperpage = variable_get('jiscpm_default_items_per_page', 10);
  }

  $tablesort = tablesort_sql($header);

  if (count($filterfields) == 0) {
    $filterdesc = t('Not filtered');
  }
  else {
    $filterdesc = t('Filtered by !fields', array('!fields' => implode(", ", array_unique($filterfields))));
  }
  $filterdesc .= ' | '. t('!items items per page', array('!items' => $itemsperpage));
  
  $o = drupal_get_form('jiscpmattribute_list_filter', $filterdesc);
  
  $s = db_rewrite_sql($s, 'jiscpmattribute', 'aid');
  //$s = jiscpm_rewrite_sql($s, $where) . $tablesort;
  $r = pager_query($s, $itemsperpage, 0, NULL, $args);

  $attributes = array();
  while ($attribute = db_fetch_object($r)) {
    $attributes[] = $attribute;
  }

  $o .= drupal_get_form('jiscpmattribute_list_form', $header, $attributes);
  $o .= theme('pager', NULL, $itemsperpage, 0);
  return $o;
}

function jiscpmattribute_list_form($form_id, $header, $attributes) {
  $form = array();

  $form['attributes']['#theme'] = 'jiscpmattribute_list';

  $form['attributes']['header'] = array (
    '#value' => $header,
  );

  foreach ($attributes as $attribute) {
    $i = new stdClass();
    $i->type = 'jiscpmattribute';

    $form['attributes']['attributes'][$attribute->aid]['attribute_domain_'. $attribute->aid] = array (
      '#value' => $attribute->domain,
    );

    $form['attributes']['attributes'][$attribute->aid]['attribute_akey_'. $attribute->aid] = array (
      '#value' => $attribute->akey,
    );

    $form['attributes']['attributes'][$attribute->aid]['attribute_avalue_'. $attribute->aid] = array (
      '#value' => $attribute->avalue,
    );

    $form['attributes']['attributes'][$attribute->aid]['attribute_isactive_'. $attribute->aid] = array (
      '#type' => 'checkbox',
      '#default_value' => $attribute->isactive,
    );

    $form['attributes']['attributes'][$attribute->aid]['attribute_default_'. $attribute->aid] = array (
      '#default_value' => $attribute->isdefault,
    );

    $form['attributes']['attributes'][$attribute->aid]['attribute_weight_'. $attribute->aid] = array (
      '#type' => 'weight',
      '#default_value' => $attribute->weight,
    );

    $form['attributes']['attributes'][$attribute->aid]['attribute_operations_'. $attribute->aid] = array (
      '#value' => jiscpm_icon_edit('jiscpm/attributes/edit/'. $attribute->aid, $i, $_GET) .'&nbsp;'.  jiscpm_icon_delete('jiscpm/attributes/delete/'. $attribute->aid, $i, $_GET),
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#submit' => array('jiscpmattribute_list_submit'),
    '#value' => t('Save'),
  );

  return $form;
}

function jiscpmattribute_list_submit($form, &$form_state) {
  $attributes = array();
  $default_for_domain = array();
  foreach($_POST as $key=>$value) {
    $ar = explode('_', $key);
    if($ar[0]=='attribute') {
      if($ar[1]=='weight') $attributes[$ar[2]]['weight'] = $value;
      if($ar[1]=='isactive') $attributes[$ar[2]]['isactive'] = $value;
      if($ar[1]=='default') {
        $domain = str_replace('|',' ',$ar[2]);
        $default_for_domain[$domain] = $value;
      }
    }
  }

  $s = "UPDATE {jiscpmattribute} SET isactive=%d, weight=%d WHERE aid=%d";  
  foreach($attributes as $aid=>$values) {
    db_query($s, $values['isactive'], $values['weight'], $aid);
  }

  foreach($default_for_domain as $domain=>$aid) {
    $s = "UPDATE {jiscpmattribute} SET isdefault=0 WHERE domain='%s'";  
    db_query($s, $domain);
    $s = "UPDATE {jiscpmattribute} SET isdefault=1 WHERE aid=%d";
    db_query($s, $aid);  
  }

  drupal_set_message(t('Attributes saved'));
}

function jiscpmattribute_list_filter(&$form_state, $filterdesc = 'Filter') {
  $domain = $_SESSION['jiscpmattribute_list_filter']['domain'];
  $akey = $_SESSION['jiscpmattribute_list_filter']['akey'];
  $avalue = $_SESSION['jiscpmattribute_list_filter']['avalue'];
  $isactive = $_SESSION['jiscpmattribute_list_filter']['isactive'];
  $isdefault = $_SESSION['jiscpmattribute_list_filter']['isdefault'];

  $itemsperpage = $_SESSION['jiscpmattribute_list_filter']['itemsperpage'];
  if (!$itemsperpage) {
    $itemsperpage = variable_get('jiscpm_default_items_per_page', 10);
    $_SESSION['jiscpmattribute_list_filter']['itemsperpage'] = $itemsperpage;
  }

  $form['filter'] = array(
    '#type' => 'fieldset',
    '#title' => $filterdesc,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['filter']['group1'] = array(
    '#type' => 'markup',
    '#theme' => 'jiscpm_form_group',
  );

  $form['filter']['group1']['domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Domain'),
    '#default_value' => $domain,
    '#size' => 30,
    '#autocomplete_path' => 'jiscpm/attributes/domain/autocomplete',
  );

  $form['filter']['group1']['akey'] = array(
    '#type' => 'textfield',
    '#title' => t('Key'),
    '#default_value' => $akey,
    '#size' => 20,
  );

  $form['filter']['group1']['avalue'] = array(
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#default_value' => $avalue,
    '#size' => 20,
  );

  $form['filter']['group2'] = array(
    '#type' => 'markup',
    '#theme' => 'jiscpm_form_group',
  );

  $form['filter']['group2']['isactive'] = array(
    '#type' => 'select',
    '#title' => t('Active'),
    '#default_value' => $isactive,
    '#options' => array('-'=>'-', '0'=>t('No'), '1'=>t('Yes')),
  );

  $form['filter']['group2']['isdefault'] = array(
    '#type' => 'select',
    '#title' => t('Default'),
    '#default_value' => $isdefault,
    '#options' => array('-'=>'-', '0'=>t('No'), '1'=>t('Yes')),
  );

  $form['filter']['group3'] = array(
    '#type' => 'markup',
    '#theme' => 'jiscpm_form_group',
  );

  $form['filter']['group3']['itemsperpage'] = array(
    '#type' => 'textfield',
    '#title' => t('Items'),
    '#size' => 10,
    '#default_value' => $itemsperpage,
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
  );

  $form['filter']['group3']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
    '#submit' => array('jiscpmattribute_list_filter_filter'),
  );

  $form['filter']['group3']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset'),
    '#submit' => array('jiscpmattribute_list_filter_reset'),
  );

  return $form;
}

function jiscpmattribute_list_filter_filter($form, &$form_state) {
  $_SESSION['jiscpmattribute_list_filter']['domain'] = $form_state['values']['domain'];
  $_SESSION['jiscpmattribute_list_filter']['akey'] = $form_state['values']['akey'];
  $_SESSION['jiscpmattribute_list_filter']['avalue'] = $form_state['values']['avalue'];
  $_SESSION['jiscpmattribute_list_filter']['isactive'] = $form_state['values']['isactive'];
  $_SESSION['jiscpmattribute_list_filter']['isdefault'] = $form_state['values']['isdefault'];
  $_SESSION['jiscpmattribute_list_filter']['itemsperpage'] = $form_state['values']['itemsperpage'];
}

function jiscpmattribute_list_filter_reset($form, &$form_state) {
  unset($_SESSION['jiscpmattribute_list_filter']);
}

function jiscpmattribute_add() {
  $attribute = new stdClass();
  return jiscpmattribute_form($attribute);
}

function jiscpmattribute_add_submit($form, &$form_state) {
  if($form_state['values']['isdefault']) {
    db_query("UPDATE {jiscpmattribute} SET isdefault=0 WHERE domain='%s'", $form_state['values']['domain']);
  }

  db_query("INSERT INTO {jiscpmattribute} (domain, akey, avalue, parent_domain, weight, isactive, isdefault) 
  VALUES ('%s', '%s', '%s', '%s', %d, %d, %d)", 
  $form_state['values']['domain'], $form_state['values']['akey'], $form_state['values']['avalue'], $form_state['values']['parent_domain'], 
  $form_state['values']['weight'], $form_state['values']['isactive'], $form_state['values']['isdefault']);

  if ($_REQUEST['destination']) {
    $destination = urldecode($_REQUEST['destination']);
  }
  else {
    $destination = 'jiscpm/attributes';
  }
  drupal_goto($destination);
}

function jiscpmattribute_edit($form_state, $aid) {
  $attribute = array();
  if ($aid) {
    $r = db_query("SELECT * FROM {jiscpmattribute} WHERE aid=%d", $aid);
    $attribute = db_fetch_object($r);
  }
  return jiscpmattribute_form($attribute);
}

function jiscpmattribute_edit_submit($form, &$form_state) {
  if($form_state['values']['isdefault']) {
    db_query("UPDATE {jiscpmattribute} SET isdefault=0 WHERE domain='%s'", $form_state['values']['domain']);
  }

  db_query("UPDATE {jiscpmattribute} SET domain='%s', akey='%s', avalue='%s', 
  parent_domain='%s', weight=%d, isactive=%d, isdefault=%d WHERE aid=%d", 
  $form_state['values']['domain'], $form_state['values']['akey'], $form_state['values']['avalue'], 
  $form_state['values']['parent_domain'], $form_state['values']['weight'], $form_state['values']['isactive'], $form_state['values']['isdefault'], $form_state['values']['aid']);

  if ($_REQUEST['destination']) {
    $destination = urldecode($_REQUEST['destination']);
  }
  else {
    $destination = 'jiscpm/attributes';
  }
  drupal_goto($destination);
}

function jiscpmattribute_form_delete($form, &$form_state) {
  $destination = drupal_get_destination(); 
  if(array_key_exists('destination', $_REQUEST)) unset($_REQUEST['destination']);
  drupal_goto('jiscpm/attributes/delete/'. $form_state['values']['aid'], $destination);
}

function jiscpmattribute_delete($form_state, $aid) {
  $destination = drupal_get_destination();
  if(array_key_exists('destination', $_REQUEST)) {
    $destination = $_REQUEST['destination'];
    unset($_REQUEST['destination']);
    $form['destination'] = array('#type' => 'value', '#value' => $destination);
  }

  $form['aid'] = array('#type' => 'value', '#value' => $aid);
  $r = db_query("SELECT * FROM {jiscpmattribute} WHERE aid=%d", $aid);
  $a = db_fetch_object($r);
  $title = $a->domain .' : '. $a->avalue;

  return confirm_form($form,
  t('Are you sure you want to delete the attribute %title?', array('%title' => $title)),
  array('path'=>'jiscpm/attributes/edit/'. $aid, 'query'=>$destination),
  t('This action cannot be undone.'),
  t('Delete'), t('Cancel'));
}

function jiscpmattribute_delete_submit($form, &$form_state) {
  if ($form_state['values']['aid']) {
    db_query('DELETE FROM {jiscpmattribute} WHERE aid=%d', $form_state['values']['aid']);
    drupal_set_message('jiscpm attribute deleted');
    if ($form_state['values']['destination']) {
      $destination = $form_state['values']['destination'];
    }
    else {
      $destination = 'jiscpm/attributes';
    }
    drupal_goto($destination);
  }
}

function jiscpmattribute_form($attribute = NULL) {
  $breadcrumb = array();
  $breadcrumb[] = l(t('jiscpm'), 'jiscpm');
  $breadcrumb[] = l(t('Attributes'), 'jiscpm/attributes');
  drupal_set_breadcrumb($breadcrumb);

  if (arg(2)=='add') {
    if (array_key_exists('domain', $_GET) && !$attribute->domain) {
      $attribute->domain = $_GET['domain'];
    }

    if ($_SESSION['jiscpmattribute_list_filter']['domain'] && !$attribute->domain) {
      $attribute->domain = $_SESSION['jiscpmattribute_list_filter']['domain'];
    }
  }

  $form = array();
  if ($attribute->aid) {
    $form['aid'] = array(
      '#type' => 'value',
      '#value' => $attribute->aid,
    );
  }

  $form['group1'] = array(
    '#type' => 'markup',
    '#theme' => 'jiscpm_form_group',
  );

  $form['group1']['domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Domain'),
    '#required' => TRUE,
    '#default_value' => $attribute->domain,
    '#autocomplete_path' => 'jiscpm/attributes/domain/autocomplete',
    '#size' => 40,
  );

  $domains = array();
  $r = db_query("SELECT DISTINCT(domain) d FROM {jiscpmattribute} ORDER BY domain");
  while($i=db_fetch_object($r)) {
    $domains[$i->d] = $i->d;
  }
  $form['group1']['parent_domain'] = array(
    '#type' => 'select',
    '#title' => t('Parent domain'),
    '#required' => FALSE,
    '#default_value' => $attribute->parent_domain,
    '#options' => array(''=>'-') + $domains,
  );

  $form['group2'] = array(
    '#type' => 'markup',
    '#theme' => 'jiscpm_form_group',
  );

  $form['group2']['akey'] = array(
    '#type' => 'textfield',
    '#title' => t('Key'),
    '#required' => TRUE,
    '#default_value' => $attribute->akey,
    '#size' => 25,
  );

  $form['group2']['avalue'] = array(
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#required' => TRUE,
    '#default_value' => $attribute->avalue,
    '#size' => 25,
  );

  $form['group2']['weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => $attribute->weight,
  );

  $form['group3'] = array(
    '#type' => 'markup',
    '#theme' => 'jiscpm_form_group',
  );

  $form['group3']['isactive'] = array(
    '#type' => 'checkbox',
    '#title' => t('Active'),
    '#default_value' => $attribute->isactive,
  );

  $form['group3']['isdefault'] = array(
    '#type' => 'checkbox',
    '#title' => t('Default'),
    '#default_value' => $attribute->isdefault,
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save')
  );

  if ($attribute->aid) {
    $form['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('jiscpmattribute_form_delete'),
    );
  }
  
  return $form;
}

function _jiscpmattibute_domain_options() {
  static $options;
  if (!$options) {
    $r = db_query("SELECT DISTINCT(domain) AS domain_name FROM {jiscpmattribute} ORDER BY domain");
    $options = array();
    while ($d = db_fetch_object($r)) {
      $options[$d->domain_name] = $d->domain_name;
    }
  }
  return $options;
}

function _jiscpmattribute_domain_autocomplete($string = '') {
  static $default_domains;
  if (!$default_domains) {
    $default_domains = array (
      'Country'=>'Country',
      'Currency'=>'Currency',
      'Task status'=>'Task status',
      'Project category'=>'Project category',
      'Project status search'=>'Project status search',
      'Project status'=>'Project status',
      'Ticket priority search'=>'Ticket priority search',
      'Ticket priority'=>'Ticket priority',
      'Ticket category'=>'Ticket category',
      'Ticket status search'=>'Ticket status search',
      'Ticket status'=>'Ticket status',
      'Task status search'=>'Task status search',
      'Price mode'=>'Price mode',
      'Project priority'=>'Project priority',
      'Project priority search'=>'Project priority search',
      'Task category'=>'Task category',
      'Task priority'=>'Task priority',
      'Task priority search'=>'Task priority search',
      'Duration unit'=>'Duration unit',
    );
  }

  $matches = array();
  if ($string) {
    $s = "SELECT DISTINCT(domain) AS domain FROM {jiscpmattribute} WHERE LOWER(domain) LIKE LOWER('%s%%')";
    $s = db_rewrite_sql($s, 'jiscpmattribute', 'aid');
    $result = db_query($s, $string);
    while ($a = db_fetch_object($result)) {
      $matches[$a->domain] = check_plain($a->domain);
    }
  }

  foreach ($default_domains as $domain) {
    if (strpos(strtoupper($domain), strtoupper($string))===false) {
    }
    else {
      $matches[$domain] = $domain;
    }
  }

  $matches = array_slice($matches, 0, 10);

  drupal_json($matches);
}

