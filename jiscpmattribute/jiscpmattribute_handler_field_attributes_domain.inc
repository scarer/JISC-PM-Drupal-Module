<?php

/**
 * @file
 * Show attribute values rather than keys in jiscpm Views fields.
 */

class Jiscpmattributehandlerfieldattributesdomain extends views_handler_field {

  /**
   * @function
   * Render the values.
   */
  function render($values) {
    $key = $values->{$this->field_alias};
    $value = jiscpmattribute_value($this->definition['domain'], $key);
    return $value;
  }
}
