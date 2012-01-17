<?php
// $Id: $
/*
function jiscpmbca_views_data() {
  $data['jiscpmbca']['table']['group']  = 'jiscpm';
  $data['jiscpmbca']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );
  
  $data['jiscpmbca']['organization_nid'] = array(
    'title' => t('bca Organization Node ID'),
    'help' => 'jiscpm bca Organization Node ID',
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
  
  $data['jiscpmbca']['organization_title'] = array(
    'title' => t('bca Organization Title'),
    'help' => 'jiscpm bca Organization Title',
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
  
  $data['jiscpmbca']['bcastatus'] = array(
    'title' => t('bca Status'),
    'help' => 'jiscpm bca Status',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'bca Status',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'bca Status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmbca']['bcacategory'] = array(
    'title' => t('bca Category'),
    'help' => 'jiscpm bca Category',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'bca Category',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'bca Category',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmbca']['bcapriority'] = array(
    'title' => t('bca Priority'),
    'help' => 'jiscpm bca Priority',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'bca Priority',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'bca Priority',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmbca']['pricemode'] = array(
    'title' => t('bca Price Mode'),
    'help' => 'jiscpm bca Price Mode',
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
  
  $data['jiscpmbca']['price'] = array(
    'title' => t('bca Price'),
    'help' => 'jiscpm bca Price',
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
  
  $data['jiscpmbca']['currency'] = array(
    'title' => t('bca Currency'),
    'help' => 'jiscpm bca Currency',
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
  
  $data['jiscpmbca']['datebegin'] = array(
    'title' => t('bca Date Begin'),
    'help' => 'jiscpm bca Date Begin',
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
  
  $data['jiscpmbca']['dateend'] = array(
    'title' => t('bca Date End'),
    'help' => 'jiscpm bca Date End',
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
  
  $data['jiscpmbca']['duration unit'] = array(
    'title' => t('bca Duration Unit'),
    'help' => 'jiscpm bca Duration Unit',
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
  
  $data['jiscpmbca']['duration'] = array(
    'title' => t('bca Duration'),
    'help' => 'jiscpm bca Duration',
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
  
  $data['jiscpmbca']['manager_nid'] = array(
    'title' => t('bca Manager Node ID'),
    'help' => 'jiscpm bca Manager Node ID',
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
  
  $data['jiscpmbca']['manager_title'] = array(
    'title' => t('bca Manager Title'),
    'help' => 'jiscpm bca Manager Title',
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
  
  $data['jiscpmbca']['assigned_nid'] = array(
    'title' => t('bca Assigned Node ID'),
    'help' => 'jiscpm bca Assigned Node ID',
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
  
  $data['jiscpmbca']['assigned_title'] = array(
    'title' => t('bca Assigned Title'),
    'help' => 'jiscpm bca Assigned Title',
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

function jiscpmbca_views_handlers() {
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
function jiscpmbca_date_api_fields($field) {
   $values = array(
    'sql_type' => DATE_UNIX, 
    'tz_handling' => 'site',
    'timezone_field' => '', 
    'offset_field' => '', 
    'related_fields' => array(),
    'granularity' => array('year', 'month', 'day', 'hour', 'minute', 'second'),
  );

  switch ($field) {
    case 'jiscpmbca.datebegin':
    case 'jiscpmbca.dateend':
      return $values;
  }
}
*/
/**
 * Implement hook_date_api_tables().
 */
 /*
function jiscpmbca_date_api_tables() {
  return array('jiscpmbca');
}
*/