<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function osu_calendar_feed_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function osu_calendar_feed_node_info() {
  $items = array(
    'osu_calendar_feed' => array(
      'name' => t('OSU Calendar Feed Page'),
      'module' => 'features',
      'description' => t('Used by osu_calendar_feed feature for importing and updating events from the OSU calendar via xml.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function osu_calendar_feed_views_api() {
  return array(
    'api' => '2',
  );
}
