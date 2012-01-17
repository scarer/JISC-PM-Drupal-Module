<?php
// $Id: $
/*
function jiscpmppr_views_data() {
  $data['jiscpmppr']['table']['group']  = 'jiscpm';
  $data['jiscpmppr']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );
  
  $data['jiscpmppr']['organization_nid'] = array(
    'title' => t('ppr Organization Node ID'),
    'help' => 'jiscpm ppr Organization Node ID',
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
  
  $data['jiscpmppr']['organization_title'] = array(
    'title' => t('ppr Organization Title'),
    'help' => 'jiscpm ppr Organization Title',
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
  
  $data['jiscpmppr']['pprstatus'] = array(
    'title' => t('ppr Status'),
    'help' => 'jiscpm ppr Status',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'ppr Status',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'ppr Status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmppr']['pprcategory'] = array(
    'title' => t('ppr Category'),
    'help' => 'jiscpm ppr Category',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'ppr Category',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'ppr Category',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmppr']['pprpriority'] = array(
    'title' => t('ppr Priority'),
    'help' => 'jiscpm ppr Priority',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'ppr Priority',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'ppr Priority',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmppr']['pricemode'] = array(
    'title' => t('ppr Price Mode'),
    'help' => 'jiscpm ppr Price Mode',
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
  
  $data['jiscpmppr']['price'] = array(
    'title' => t('ppr Price'),
    'help' => 'jiscpm ppr Price',
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
  
  $data['jiscpmppr']['currency'] = array(
    'title' => t('ppr Currency'),
    'help' => 'jiscpm ppr Currency',
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
  
  $data['jiscpmppr']['datebegin'] = array(
    'title' => t('ppr Date Begin'),
    'help' => 'jiscpm ppr Date Begin',
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
  
  $data['jiscpmppr']['dateend'] = array(
    'title' => t('ppr Date End'),
    'help' => 'jiscpm ppr Date End',
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
  
  $data['jiscpmppr']['duration unit'] = array(
    'title' => t('ppr Duration Unit'),
    'help' => 'jiscpm ppr Duration Unit',
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
  
  $data['jiscpmppr']['duration'] = array(
    'title' => t('ppr Duration'),
    'help' => 'jiscpm ppr Duration',
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
  
  $data['jiscpmppr']['manager_nid'] = array(
    'title' => t('ppr Manager Node ID'),
    'help' => 'jiscpm ppr Manager Node ID',
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
  
  $data['jiscpmppr']['manager_title'] = array(
    'title' => t('ppr Manager Title'),
    'help' => 'jiscpm ppr Manager Title',
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
  
  $data['jiscpmppr']['assigned_nid'] = array(
    'title' => t('ppr Assigned Node ID'),
    'help' => 'jiscpm ppr Assigned Node ID',
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
  
  $data['jiscpmppr']['assigned_title'] = array(
    'title' => t('ppr Assigned Title'),
    'help' => 'jiscpm ppr Assigned Title',
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

function jiscpmppr_views_handlers() {
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
function jiscpmppr_date_api_fields($field) {
   $values = array(
    'sql_type' => DATE_UNIX, 
    'tz_handling' => 'site',
    'timezone_field' => '', 
    'offset_field' => '', 
    'related_fields' => array(),
    'granularity' => array('year', 'month', 'day', 'hour', 'minute', 'second'),
  );

  switch ($field) {
    case 'jiscpmppr.datebegin':
    case 'jiscpmppr.dateend':
      return $values;
  }
}
*/
/**
 * Implement hook_date_api_tables().
 */
 /*
function jiscpmppr_date_api_tables() {
  return array('jiscpmppr');
}
*/