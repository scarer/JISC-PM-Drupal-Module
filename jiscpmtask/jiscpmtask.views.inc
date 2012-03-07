<?php
/**
 * @file
 * JISC PM task views.
 */

/**
 * @function
 * Views data.
 */
function jiscpmtask_views_data() {
  $data['jiscpmtask']['table']['group']  = 'jiscpm';
  $data['jiscpmtask']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );
  $data['jiscpmtask']['stepno'] = array(
    'title' => t('Task Step Number'),
    'help' => 'jiscpm Task Step Number',
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
  $data['jiscpmtask']['organization_nid'] = array(
    'title' => t('Task Organization Node ID'),
    'help' => 'jiscpm Task Organization Node ID',
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
  $data['jiscpmtask']['organization_title'] = array(
    'title' => t('Task Organization Title'),
    'help' => 'jiscpm Task Organization Title',
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
  $data['jiscpmtask']['project_nid'] = array(
    'title' => t('Task Project Node ID'),
    'help' => 'jiscpm Task Project Node ID',
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
  $data['jiscpmtask']['project_title'] = array(
    'title' => t('Task Project Title'),
    'help' => 'jiscpm Task Project Title',
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
  $data['jiscpmtask']['parent_nid'] = array(
    'title' => t('Task Parent Task Node ID'),
    'help' => 'jiscpm Task Patent Task Node ID',
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
  $data['jiscpmtask']['weight'] = array(
    'title' => t('Task Weight'),
    'help' => 'jiscpm Task Weight',
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
  $data['jiscpmtask']['taskstatus'] = array(
    'title' => t('Task Status'),
    'help' => 'jiscpm Task Status',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'Task Status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'Task Status',
    ),
  );
  $data['jiscpmtask']['taskcategory'] = array(
    'title' => t('Task Category'),
    'help' => 'jiscpm Task Category',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'Task Category',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'Task Category',
    ),
  );
  $data['jiscpmtask']['taskpriority'] = array(
    'title' => t('Task Priority'),
    'help' => 'jiscpm Task Priority',
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'jiscpmattribute_handler_field_attributes_domain',
      'domain' => 'Task Priority',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'jiscpmattribute_handler_filter_attributes_domain',
      'domain' => 'Task Priority',
    ),
  );
  $data['jiscpmtask']['pricemode'] = array(
    'title' => t('Task Price Mode'),
    'help' => 'jiscpm Task Price Mode',
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
  $data['jiscpmtask']['price'] = array(
    'title' => t('Task Price'),
    'help' => 'jiscpm Task Price',
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
  $data['jiscpmtask']['currency'] = array(
    'title' => t('Task Currency'),
    'help' => 'jiscpm Task Currency',
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
  $data['jiscpmtask']['datebegin'] = array(
    'title' => t('Task Date Begin'),
    'help' => 'jiscpm Task Date Begin',
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
  $data['jiscpmtask']['dateend'] = array(
    'title' => t('Task Date End'),
    'help' => 'jiscpm Task Date End',
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
  $data['jiscpmtask']['durationunit'] = array(
    'title' => t('Task Duration Unit'),
    'help' => 'jiscpm Task Duration Unit',
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
  $data['jiscpmtask']['duration'] = array(
    'title' => t('Task Duration'),
    'help' => 'jiscpm Task Duration',
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
  $data['jiscpmtask']['assigned_nid'] = array(
    'title' => t('Task Assigned Node ID'),
    'help' => 'jiscpm Task Assigned Node ID',
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
  $data['jiscpmtask']['assigned_title'] = array(
    'title' => t('Task Assigned Title'),
    'help' => 'jiscpm Task Assigned Title',
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
/**
 * @function
 * Implements hook_views_handlers().
 */
function jiscpmtask_views_handlers() {
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
 * @function
 * Implementation of hook_date_api_fields()
 * on behalf of core fields.
 */
function jiscpmtask_date_api_fields($field) {
  $values = array(
    'sql_type' => DATE_UNIX,
    'tz_handling' => 'site',
    'timezone_field' => '',
    'offset_field' => '',
    'related_fields' => array(),
    'granularity' => array('year', 'month', 'day', 'hour', 'minute', 'second'),
  );
  switch ($field) {
    case 'jiscpmtask.datebegin':
    case 'jiscpmtask.dateend':
      return $values;
  }
}

/**
 * @function
 * Implement hook_date_api_tables().
 */
function jiscpmtask_date_api_tables() {
  return array('jiscpmtask');
}
