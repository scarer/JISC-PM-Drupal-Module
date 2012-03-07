<?php
/**
 * @file
 * Filter by vocabulary id
 */

class Jiscpmattributehandlerfilterattributesdomain extends views_handler_filter_in_operator {

  /**
   * @function
   * Render the values.
   */
  function getvalueoptions() {
    if (!isset($this->value_options)) {
      $this->value_options = jiscpmattributeattributesbydomain($this->definition['domain']);
      $this->value_options = $this->value_options['values'];
    }
  }
}
