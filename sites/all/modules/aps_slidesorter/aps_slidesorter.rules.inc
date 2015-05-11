<?php

/**
 * Implements hook_rules_event_info().
 */
function aps_slidesorter_rules_event_info() {
  $events = array(
    'aps_slidesorter_create_saved_queue' => array(
    	'label' => t('User saves new Saved queue'),
    	'group' => t('Slide sorter'),
    	'variables' => array(
        'list' => array(
          'type' => 'list',
          'label' => t('List of Node IDs')
        ),
      ),
    ),
    'aps_slidesorter_create_archived_queue' => array(
	    'label' => t('User saves new Archived queue'), 
	    'group' => t('Slide sorter'), 
	    'variables' => array(
        'list' => array(
          'type' => 'list',
          'label' => t('List of Node IDs')
        ),
      ),
    ),
  );
  return $events;
}

/**
 * Implement hook_rules_action_info().
 */
function aps_slidesorter_rules_action_info() {
  return array(
    'aps_slidesorter_return_filepath' => array(
      'label' => t('Return exact filepath from URI address'),
      'group' => t('Slide sorter'),
      'parameter' => array(
        'uri' => array(
          'type' => 'uri',
          'label' => t('File URI address'),
          'description' => t('Enter the URI address of the file to be retrieved.'),
        ),
      ),
      'provides' => array(
        'exact_filepath' => array(
          'type' => 'text',
          'label' => t('Filepath'),
        ),
      ),
    ),
  );
}

// This callback that returns the filepath for the file.
function aps_slidesorter_return_filepath($uri) {
  $filepath = drupal_realpath($uri);
 
  return array(
    'exact_filepath' => $filepath,
  );
}