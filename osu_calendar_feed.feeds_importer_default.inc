<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function osu_calendar_feed_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'calendar_feeds';
  $feeds_importer->config = array(
    'name' => 'calendar_feeds',
    'description' => 'Extension calendar feeds from calendar.oregonstate.edu',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'uid',
          'xpathparser:1' => 'description',
          'xpathparser:2' => 'summary',
          'xpathparser:3' => 'dtstart',
          'xpathparser:4' => 'dtend',
          'xpathparser:5' => 'location',
          'xpathparser:6' => 'xproperties[@name=\'x-osu-address\']',
          'xpathparser:7' => 'xproperties[@name=\'x-osu-room\']',
          'xpathparser:8' => 'xproperties[@name=\'x-osu-city\']',
          'xpathparser:9' => 'xproperties[@name=\'x-osu-state\']',
          'xpathparser:10' => 'xproperties[@name=\'x-osu-cost\']',
          'xpathparser:11' => 'xproperties[@name=\'x-osu-subtitle\']',
          'xpathparser:12' => 'xproperties[@name=\'x-osu-calendar\']',
          'xpathparser:13' => 'contacts',
          'xpathparser:14' => 'xproperties[@name=\'x-osu-contact-dept\']',
          'xpathparser:15' => 'xproperties[@name=\'x-osu-contact-phone\']',
          'xpathparser:16' => 'xproperties[@name=\'x-osu-contact-email\']',
          'xpathparser:17' => 'xproperties[@name=\'x-osu-allday\']',
          'xpathparser:18' => 'xproperties[@name=\'x-osu-eventlink\']',
        ),
        'rawXML' => array(
          'xpathparser:1' => 'xpathparser:1',
          'xpathparser:6' => 'xpathparser:6',
          'xpathparser:7' => 'xpathparser:7',
          'xpathparser:8' => 'xpathparser:8',
          'xpathparser:9' => 'xpathparser:9',
          'xpathparser:10' => 'xpathparser:10',
          'xpathparser:11' => 'xpathparser:11',
          'xpathparser:12' => 'xpathparser:12',
          'xpathparser:13' => 'xpathparser:13',
          'xpathparser:14' => 'xpathparser:14',
          'xpathparser:15' => 'xpathparser:15',
          'xpathparser:16' => 'xpathparser:16',
          'xpathparser:17' => 'xpathparser:17',
          'xpathparser:18' => 'xpathparser:18',
          'xpathparser:0' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
        ),
        'context' => '//vcalendar/vevent',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
          ),
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'osu_calendar_feed',
        'input_format' => '2',
        'update_existing' => '1',
        'expire' => '14515200',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_osu_calendar_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_osu_calendar_title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_osu_calendar_date:start',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_osu_calendar_date:end',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_osu_calendar_location',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_osu_calendar_address',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_osu_calendar_room',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_osu_calendar_city',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_osu_calendar_state',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_osu_calendar_cost',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_osu_calendar_subtitle',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_osu_calendar_calendars',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_osu_calendar_contact',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_osu_calendar_contact_dept',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_osu_calendar_contact_phone',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_osu_calendar_contact_email',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_osu_calendar_allday',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_osu_calendar_link',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
  );
  $export['calendar_feeds'] = $feeds_importer;

  return $export;
}
