<?php

/**
 * @file
 */
function jiscpmproject_views_data() {
  $data['jiscpmproject']['table']['group']  = 'jiscpm';
  $data['jiscpmproject']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );
  
  
  $data['jiscpmproject']['projectstatus'] = array(
    'title' => t('Project Status'),
    'help' => 'jiscpm Project Status',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'Project Status',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'Project Status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmproject']['projectcategory'] = array(
    'title' => t('Project Category'),
    'help' => 'jiscpm Project Category',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'Project Category',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'Project Category',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmproject']['projectpriority'] = array(
    'title' => t('Project Priority'),
    'help' => 'jiscpm Project Priority',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'Project Priority',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'Project Priority',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmproject']['datebegin'] = array(
    'title' => t('Project Date Begin'),
    'help' => 'jiscpm Project Date Begin',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  $data['jiscpmproject']['dateend'] = array(
    'title' => t('Project Date End'),
    'help' => 'jiscpm Project Date End',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
 } 

function jiscpmproject_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'jiscpmattribute'),
    ),
    'handlers' => array(
      'jiscpmattribute_handler_field_attributes_domain' => array(
        'parent' => 'views_handler_field',
      ),
      'jiscpmattribute_handler_filter_attributes_domain' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
    ),
  );
}


/**
 * Implementation of hook_date_api_fields().
 * on behalf of core fields.
 * 
 * All modules that create custom fields that use the 
 * 'views_handler_field_date' handler can provide
 * additional information here about the type of
 * date they create so the date can be used by
 * the Date API views date argument and date filter.
 */

function jiscpmproject_date_api_fields($field) {
   $values = array(
    'sql_type' => DATE_UNIX, 
    'tz_handling' => 'site',
    'timezone_field' => '', 
    'offset_field' => '', 
    'related_fields' => array(),
    'granularity' => array('year', 'month', 'day', 'hour', 'minute', 'second'),
  );

  switch ($field) {
    case 'jiscpmproject.datebegin':
    case 'jiscpmproject.dateend':
      return $values;
  }
}

/**
 * Implement hook_date_api_tables().
 */
function jiscpmproject_date_api_tables() {
  return array('jiscpmproject');
}