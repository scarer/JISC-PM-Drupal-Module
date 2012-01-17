<?php
// $Id: $
/*
function jiscpmissue_views_data() {
  $data['jiscpmissue']['table']['group']  = 'jiscpm';
  $data['jiscpmissue']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );
  
  $data['jiscpmissue']['organization_nid'] = array(
    'title' => t('risk Organization Node ID'),
    'help' => 'jiscpm risk Organization Node ID',
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
  
  $data['jiscpmissue']['organization_title'] = array(
    'title' => t('risk Organization Title'),
    'help' => 'jiscpm risk Organization Title',
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
  
  $data['jiscpmissue']['riskstatus'] = array(
    'title' => t('risk Status'),
    'help' => 'jiscpm risk Status',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'risk Status',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'risk Status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmissue']['riskcategory'] = array(
    'title' => t('risk Category'),
    'help' => 'jiscpm risk Category',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'risk Category',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'risk Category',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmissue']['riskpriority'] = array(
    'title' => t('risk Priority'),
    'help' => 'jiscpm risk Priority',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'risk Priority',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'risk Priority',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['jiscpmissue']['pricemode'] = array(
    'title' => t('risk Price Mode'),
    'help' => 'jiscpm risk Price Mode',
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
  
  $data['jiscpmissue']['price'] = array(
    'title' => t('risk Price'),
    'help' => 'jiscpm risk Price',
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
  
  $data['jiscpmissue']['currency'] = array(
    'title' => t('risk Currency'),
    'help' => 'jiscpm risk Currency',
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
  
  $data['jiscpmissue']['datebegin'] = array(
    'title' => t('risk Date Begin'),
    'help' => 'jiscpm risk Date Begin',
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
  
  $data['jiscpmissue']['dateend'] = array(
    'title' => t('risk Date End'),
    'help' => 'jiscpm risk Date End',
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
  
  $data['jiscpmissue']['duration unit'] = array(
    'title' => t('risk Duration Unit'),
    'help' => 'jiscpm risk Duration Unit',
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
  
  $data['jiscpmissue']['duration'] = array(
    'title' => t('risk Duration'),
    'help' => 'jiscpm risk Duration',
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
  
  $data['jiscpmissue']['manager_nid'] = array(
    'title' => t('risk Manager Node ID'),
    'help' => 'jiscpm risk Manager Node ID',
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
  
  $data['jiscpmissue']['manager_title'] = array(
    'title' => t('risk Manager Title'),
    'help' => 'jiscpm risk Manager Title',
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
  
  $data['jiscpmissue']['assigned_nid'] = array(
    'title' => t('risk Assigned Node ID'),
    'help' => 'jiscpm risk Assigned Node ID',
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
  
  $data['jiscpmissue']['assigned_title'] = array(
    'title' => t('risk Assigned Title'),
    'help' => 'jiscpm risk Assigned Title',
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

function jiscpmissue_views_handlers() {
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
function jiscpmissue_date_api_fields($field) {
   $values = array(
    'sql_type' => DATE_UNIX, 
    'tz_handling' => 'site',
    'timezone_field' => '', 
    'offset_field' => '', 
    'related_fields' => array(),
    'granularity' => array('year', 'month', 'day', 'hour', 'minute', 'second'),
  );

  switch ($field) {
    case 'jiscpmissue.datebegin':
    case 'jiscpmissue.dateend':
      return $values;
  }
}
*/
/**
 * Implement hook_date_api_tables().
 */
 /*
function jiscpmissue_date_api_tables() {
  return array('jiscpmissue');
}
*/