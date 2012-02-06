<?php
/**
 * @file
 * Filter by vocabulary id
 */

class jiscpmattribute_handler_filter_attributes_domain extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_options = check_plain(jiscpmattribute_attributes_bydomain($this->definition['domain']));
      $this->value_options = check_plain($this->value_options['values']);
    }
  }
}
