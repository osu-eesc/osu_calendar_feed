<?php

/**
 * Implementation of hook_strongarm().
 */
function osu_calendar_feed_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_osu_calendar_feed';
  $strongarm->value = '1';
  $export['ant_osu_calendar_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_osu_calendar_feed';
  $strongarm->value = '[field_osu_calendar_title-raw]';
  $export['ant_pattern_osu_calendar_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_osu_calendar_feed';
  $strongarm->value = 0;
  $export['ant_php_osu_calendar_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_osu_calendar_feed';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '19',
    'author' => '18',
    'options' => '20',
    'menu' => '16',
    'book' => '17',
    'path' => '15',
    'path_redirect' => '21',
  );
  $export['content_extra_weights_osu_calendar_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_osu_calendar_feed';
  $strongarm->value = '0';
  $export['language_content_type_osu_calendar_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_osu_calendar_feed';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_osu_calendar_feed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_osu_calendar_feed';
  $strongarm->value = '0';
  $export['upload_osu_calendar_feed'] = $strongarm;

  return $export;
}
