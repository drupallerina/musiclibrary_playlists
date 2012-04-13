<?php
/**
 * @file
 * musiclibrary_playlist.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function musiclibrary_playlist_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function musiclibrary_playlist_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array(
    "version" => "3.0",
    "api" => "3",
    "path" => drupal_get_path('module', 'musiclibrary_playlist'),
    );
  }
}

/**
 * Implements hook_node_info().
 */
function musiclibrary_playlist_node_info() {
  $items = array(
    'playlist' => array(
      'name' => t('Playlist'),
      'base' => 'node_content',
      'description' => t('Select this to create a playlist or collection of tracks.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'track' => array(
      'name' => t('Track'),
      'base' => 'node_content',
      'description' => t('Select this to create individual tracks for the music library. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}


