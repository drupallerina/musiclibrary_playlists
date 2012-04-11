<?php
/**
 * @file
 * musiclibrary_playlist.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function musiclibrary_playlist_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attributes|node|track|form';
  $field_group->group_name = 'group_attributes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'track';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attributes',
    'weight' => '0',
    'children' => array(
      0 => 'group_track_details',
      1 => 'group_genre',
      2 => 'group_mood',
      3 => 'group_instruments',
      4 => 'group_tempo',
      5 => 'group_keywords',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_attributes|node|track|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_genre|node|track|form';
  $field_group->group_name = 'group_genre';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'track';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attributes';
  $field_group->data = array(
    'label' => 'Genre',
    'weight' => '5',
    'children' => array(
      0 => 'field_genre',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_genre|node|track|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_instruments|node|track|form';
  $field_group->group_name = 'group_instruments';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'track';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attributes';
  $field_group->data = array(
    'label' => 'Instruments',
    'weight' => '7',
    'children' => array(
      0 => 'field_instruments',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_instruments|node|track|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_keywords|node|track|form';
  $field_group->group_name = 'group_keywords';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'track';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attributes';
  $field_group->data = array(
    'label' => 'Keywords',
    'weight' => '9',
    'children' => array(
      0 => 'field_keywords',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_keywords|node|track|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mood|node|track|form';
  $field_group->group_name = 'group_mood';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'track';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attributes';
  $field_group->data = array(
    'label' => 'Mood',
    'weight' => '6',
    'children' => array(
      0 => 'field_mood',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_mood|node|track|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tempo|node|track|form';
  $field_group->group_name = 'group_tempo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'track';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attributes';
  $field_group->data = array(
    'label' => 'Tempo',
    'weight' => '8',
    'children' => array(
      0 => 'field_tempo',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tempo|node|track|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_track_details|node|track|form';
  $field_group->group_name = 'group_track_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'track';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attributes';
  $field_group->data = array(
    'label' => 'Track Details',
    'weight' => '4',
    'children' => array(
      0 => 'field_audio',
      1 => 'field_artist',
      2 => 'field_album',
      3 => 'title',
      4 => 'path',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_track_details|node|track|form'] = $field_group;

  return $export;
}
