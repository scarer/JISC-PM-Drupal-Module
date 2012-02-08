<?php
/**
 * @file
 */

function theme_jiscpmppr_list($header, $pprs) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') .'/jiscpm.css', 'module');
}

function theme_jiscpmppr_view($node, $teaser = FALSE, $page = FALSE) {
  drupal_add_css(drupal_get_path('module', 'jiscpm') . '/jiscpm-node.css', 'module');
  
  $node = node_prepare($node, $teaser);
  
  $node->content['group1'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );

  $node->content['group2'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );

//load project
  $project = node_load($node->pprs[0]['project_nid']);
  $node->content['group2']['pprproject'] = array(
    '#prefix' => '<div class="pprproject">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Project'), l($project->title, 'node/' . $project->nid)),
    '#weight' => 1,
  );

  $node->content['group2']['pprsummaryobjectives'] = array(
    '#prefix' => '<div class="pprstatus">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Summary of objectives'), jiscpmattribute_value('ppr status', check_markup($node->pprs[0]['ppr_summary_objectives'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 2,
  );

  $node->content['group2']['pprbenefitsachieved'] = array(
    '#prefix' => '<div class="pprbenefitsachieved">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Benefits achieved'), jiscpmattribute_value('ppr benefits achieved', check_markup($node->pprs[0]['ppr_benefits_achieved'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 3,
  );

  $node->content['group5'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -16,
  );
  
  $node->content['group5']['pprbenefitsnotachieved'] = array(
    '#prefix' => '<div class="pprbenefitsnotachieved">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Benefits not achieved'), jiscpmattribute_value('ppr benefits not achieved', check_markup($node->pprs[0]['ppr_benefits_not_achieved'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 1,
  );
  
  $node->content['group6'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group6') : -16,
  ); 
  
  $node->content['group6']['pprnegativebenefitsfactors'] = array(
    '#prefix' => '<div class="pprnegativebenefitsfactors">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Negative Factors that led to benefits not being achieved'), jiscpmattribute_value('ppr negative benefits factors not achieved', check_markup($node->pprs[0]['ppr_negative_benefits_factors'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 2,
  );
  
  $node->content['group7'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group7') : -16,
  ); 
  
  $node->content['group7']['pprunderestimatedtasks'] = array(
    '#prefix' => '<div class="pprunderestimatedtasks">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Underestimated tasks'), jiscpmattribute_value('ppr underestimated tasks', check_markup($node->pprs[0]['ppr_underestimated_tasks'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 2,
  );
  
  $node->content['group8'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group8') : -16,
  ); 
  
  $node->content['group8']['pprnegativetimefactors'] = array(
    '#prefix' => '<div class="pprnegativetimefactors">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Negative time factors'), jiscpmattribute_value('ppr negative time factors', check_markup($node->pprs[0]['ppr_negative_time_factors'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 2,
  );
    
  $node->content['group9'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group9') : -16,
  ); 
  
  $node->content['group9']['pprunderestimatedcosts'] = array(
    '#prefix' => '<div class="pprunderestimatedcosts">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Underestimated costs'), jiscpmattribute_value('ppr underestimated costs', check_markup($node->pprs[0]['ppr_underestimated_costs'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 2,
  );
  
  $node->content['group10'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group10') : -16,
  ); 
  
  $node->content['group10']['pproverestimatedcosts'] = array(
    '#prefix' => '<div class="pproverestimatedcosts">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Overestimated costs'), jiscpmattribute_value('ppr overestimated costs', check_markup($node->pprs[0]['ppr_overestimated_costs'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 2,
  );
  
  $node->content['group11'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group11') : -16,
  ); 
  
  $node->content['group11']['pprnegativequalityfactors'] = array(
    '#prefix' => '<div class="pprnegativequalityfactors">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Factors that led to a loss in quality of project outcomes'), jiscpmattribute_value('ppr negative quality factors', check_markup($node->pprs[0]['ppr_negative_quality_factors'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 2,
  );
  
  $node->content['group12'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group12') : -16,
  ); 
  
  $node->content['group12']['pprdeliveredoutputs'] = array(
    '#prefix' => '<div class="pprdeliveredoutputs">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Delivered outputs'), jiscpmattribute_value('ppr delivered outputs', check_markup($node->pprs[0]['ppr_delivered_outputs'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 2,
  );
  $node->content['group13'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group13') : -16,
  ); 
  
  $node->content['group13']['pprunexpectedoutcomes'] = array(
    '#prefix' => '<div class="pprunexpectedoutcomes">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Unexpected outcomes'), jiscpmattribute_value('ppr unexpected outcomes', check_markup($node->pprs[0]['ppr_unexpected_outcomes'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 2,
  );
  $node->content['group14'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group14') : -16,
  ); 
  
  $node->content['group14']['pprlessonslearned'] = array(
    '#prefix' => '<div class="pprlessonslearned">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Lessons learned'), jiscpmattribute_value('ppr lessons learned', check_markup($node->pprs[0]['ppr_lessons_learned'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 2,
  );
  $node->content['group15'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group15') : -16,
  ); 
  
  $node->content['group15']['pprrecommendationsforproject'] = array(
    '#prefix' => '<div class="pprrecommendationsforproject">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Recommendations for project'), jiscpmattribute_value('ppr recommendations for project', check_markup($node->pprs[0]['ppr_recommendations_for_project'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 2,
  );
  $node->content['group16'] = array(
    '#prefix' => '<div class="jiscpmfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group16') : -16,
  ); 
  
  $node->content['group16']['pprrecommendationsforfutureprojects'] = array(
    '#prefix' => '<div class="pprrecommendationsforfutureprojects">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Recommendations for future projects'), jiscpmattribute_value('ppr recommendations for future projects', check_markup($node->pprs[0]['ppr_recommendations_for_future_projects'], FILTER_FORMAT_DEFAULT, FALSE))),
    '#weight' => 2,
  );
  $node->content['body_field'] = array(
    '#prefix' => '<div class="jiscpmbody">',
    '#suffix' => '</div>',
    '#value' => theme('jiscpm_view_item', t('Description'), $node->content['body']['#value']),
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'body_field') : -18,
  );
  unset($node->content['body']);
  
  return $node;
}