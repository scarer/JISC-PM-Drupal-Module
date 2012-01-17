<?php
// $Id: $
/*
function jiscpmsr_views_data() {
  $data['jiscpmsr']['table']['group']  = 'jiscpm';
  $data['jiscpmsr']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );
  
  $data['jiscpmsr']['organization_nid'] = array(
    'title' => t('sr Organization Node ID'),
    'help' => 'jiscpm sr Organization Node ID',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  $data['jiscpmsr']['organization_title'] = array(
    'title' => t('sr Organization Title'),
    'help' => 'jiscpm sr Organization Title',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['jiscpmsr']['srstatus'] = array(
    'title' => t('sr Status'),
    'help' => 'jiscpm sr Status',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'sr Status',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'sr Status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmsr']['srcategory'] = array(
    'title' => t('sr Category'),
    'help' => 'jiscpm sr Category',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'sr Category',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'sr Category',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmsr']['srpriority'] = array(
    'title' => t('sr Priority'),
    'help' => 'jiscpm sr Priority',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'sr Priority',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'sr Priority',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmsr']['pricemode'] = array(
    'title' => t('sr Price Mode'),
    'help' => 'jiscpm sr Price Mode',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['jiscpmsr']['price'] = array(
    'title' => t('sr Price'),
    'help' => 'jiscpm sr Price',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  $data['jiscpmsr']['currency'] = array(
    'title' => t('sr Currency'),
    'help' => 'jiscpm sr Currency',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['jiscpmsr']['datebegin'] = array(
    'title' => t('sr Date Begin'),
    'help' => 'jiscpm sr Date Begin',
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
  
  $data['jiscpmsr']['dateend'] = array(
    'title' => t('sr Date End'),
    'help' => 'jiscpm sr Date End',
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
  
  $data['jiscpmsr']['duration unit'] = array(
    'title' => t('sr Duration Unit'),
    'help' => 'jiscpm sr Duration Unit',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['jiscpmsr']['duration'] = array(
    'title' => t('sr Duration'),
    'help' => 'jiscpm sr Duration',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  $data['jiscpmsr']['manager_nid'] = array(
    'title' => t('sr Manager Node ID'),
    'help' => 'jiscpm sr Manager Node ID',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_equality',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  $data['jiscpmsr']['manager_title'] = array(
    'title' => t('sr Manager Title'),
    'help' => 'jiscpm sr Manager Title',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['jiscpmsr']['assigned_nid'] = array(
    'title' => t('sr Assigned Node ID'),
    'help' => 'jiscpm sr Assigned Node ID',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_equality',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  $data['jiscpmsr']['assigned_title'] = array(
    'title' => t('sr Assigned Title'),
    'help' => 'jiscpm sr Assigned Title',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  return $data;
}

function jiscpmsr_views_handlers() {
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

*/
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
/*
function jiscpmsr_date_api_fields($field) {
   $values = array(
    'sql_type' => DATE_UNIX, 
    'tz_handling' => 'site',
    'timezone_field' => '', 
    'offset_field' => '', 
    'related_fields' => array(),
    'granularity' => array('year', 'month', 'day', 'hour', 'minute', 'second'),
  );

  switch ($field) {
    case 'jiscpmsr.datebegin':
    case 'jiscpmsr.dateend':
      return $values;
  }
}
*/
/**
 * Implement hook_date_api_tables().
 */
 /*
function jiscpmsr_date_api_tables() {
  return array('jiscpmsr');
}
*/