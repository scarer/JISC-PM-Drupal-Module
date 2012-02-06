<?php

/**
 * @file
 * Show attribute values rather than keys in jiscpm Views fields.
 */

class jiscpmattribute_handler_field_attributes_domain extends views_handler_field {

  function render($values) {
    $key = check_plain($values->{$this->field_alias});
    $value = check_plain(jiscpmattribute_value($this->definition['domain'], $key));
    return check_plain($value);
  }

}