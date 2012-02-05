<?php

/**
 * Show attribute values rather than keys in jiscpm Views fields.
 */

class jiscpmattribute_handler_field_attributes_domain extends views_handler_field {

  function render($values) {
    $key = $values->{$this->field_alias};
    $value = jiscpmattribute_value($this->definition['domain'], $key);
    return check_plain($value);
  }

}