<?php
/**
 * @file
 * Theme file for JISC PM attributes.
 */

/**
 * @function
 * List of attributes.
 */
function theme_jiscpmattribute_list($form) {
  drupal_add_tabledrag('attributes', 'order', 'sibling', 'attribute-weight');

  $header = array();
  $row = array();

  $header = $form['header']['#value'];
  unset($form['header']);

  foreach (element_children($form['attributes']) as $key) {
    $form['attributes'][$key]['attribute_weight_' . $key]['#attributes']['class'] = 'attribute-weight';
    $domain = drupal_render($form['attributes'][$key]['attribute_domain_' . $key]);
    $isdefault = $form['attributes'][$key]['attribute_default_' . $key]['#default_value'];
    if ($isdefault) {
      $ischecked = 'checked="checked"';
    }
    else {
      $ischecked = '';
    }
    $domain_name = 'attribute_default_' . str_replace(' ', '|', $domain);
    $default_ctl = '<input type="radio" name="' . $domain_name . '" value="' . $key . '" ' . $ischecked . '"/>';
    $data = array(
      $domain,
      drupal_render($form['attributes'][$key]['attribute_akey_' . $key]),
      drupal_render($form['attributes'][$key]['attribute_avalue_' . $key]),
      drupal_render($form['attributes'][$key]['attribute_isactive_' . $key]),
      $default_ctl,
      drupal_render($form['attributes'][$key]['attribute_weight_' . $key]),
      array(
        'data' => drupal_render($form['attributes'][$key]['attribute_operations_' . $key]),
        'class' => 'jiscpm_list_operations',
      ),
    );
    $row['data'] = $data;
    $row['class'] = empty($row['class']) ? 'draggable' : $row['class'] . ' draggable';
    $rows[] = $row;
  }
  $o = theme('table', $header, $rows, array('id' => 'attributes'));
  return $o;
}
