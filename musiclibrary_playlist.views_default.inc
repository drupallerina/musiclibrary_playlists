<?php
/**
 * @file
 * musiclibrary_playlist.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function musiclibrary_playlist_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'Playlists';
  $view->description = 'Various views for Playlists';
  $view->tag = 'playlists';
  $view->base_table = 'node';
  $view->human_name = 'Playlists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Playlist';
  $handler->display->display_options['css_class'] = 'musiclibrary-playlist-playlists-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Update';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 0;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'keys' => array(
      'more_options' => array(
        'bef_filter_description' => '',
      ),
    ),
    'tid_2' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'tid' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'tid_1' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_instruments_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_tempo_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = 'title';
  $handler->display->display_options['style_options']['columns'] = array(
    'php' => 'php',
    'title' => 'title',
    'field_artist' => 'field_artist',
    'tid' => 'tid',
    'name' => 'name',
    'field_genre' => 'field_genre',
    'field_mood' => 'field_mood',
    'field_audio' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'php' => array(
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_artist' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_genre' => array(
      'align' => '',
      'separator' => '<br>',
    ),
    'field_mood' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_audio' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['exposed_block'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<ul>
<ol>
<a class="musiclibrary-playlist-inline" href="mp/nojs/add/playlists"><img src="/sites/default/files/icons/createnewlist.png" alt="Create New Playlist" /></a>
</ol>
</ul>
<br>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<a class="mp-custom-inline" href="mp/nojs/add/playlists">You currently have no playlists. Please create one.</a>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Taxonomy term: Content with term */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'taxonomy_index';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_audio']['id'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio']['table'] = 'field_data_field_audio';
  $handler->display->display_options['fields']['field_audio']['field'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio']['label'] = '';
  $handler->display->display_options['fields']['field_audio']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_audio']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_audio']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_audio']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_audio']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_audio']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_audio']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_audio']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_audio']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Artist */
  $handler->display->display_options['sorts']['field_artist_tid']['id'] = 'field_artist_tid';
  $handler->display->display_options['sorts']['field_artist_tid']['table'] = 'field_data_field_artist';
  $handler->display->display_options['sorts']['field_artist_tid']['field'] = 'field_artist_tid';
  $handler->display->display_options['sorts']['field_artist_tid']['ui_name'] = 'Artist';
  $handler->display->display_options['sorts']['field_artist_tid']['expose']['label'] = 'Artist';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'track' => 'track',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Filter by Genre */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['ui_name'] = 'Filter by Genre';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Genre';
  $handler->display->display_options['filters']['tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'genre';
  $handler->display->display_options['filters']['tid']['error_message'] = 1;
  /* Filter criterion: Filter by Mood */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['ui_name'] = 'Filter by Mood';
  $handler->display->display_options['filters']['tid_1']['group'] = 1;
  $handler->display->display_options['filters']['tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator_id'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['label'] = 'Mood';
  $handler->display->display_options['filters']['tid_1']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['identifier'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid_1']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid_1']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_1']['vocabulary'] = 'mood';
  $handler->display->display_options['filters']['tid_1']['hierarchy'] = 1;
  $handler->display->display_options['filters']['tid_1']['error_message'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_2']['id'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_2']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_2']['group'] = 1;
  $handler->display->display_options['filters']['tid_2']['type'] = 'select';
  $handler->display->display_options['filters']['tid_2']['vocabulary'] = 'genre';

  /* Display: Playlists */
  $handler = $view->new_display('page', 'Playlists', 'playlists');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Main table view for playlists';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'library musiclibrary-playlist-row-track-[nid_1] musiclibrary-playlist-row-playlist-[nid]';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'nid_1' => 'nid_1',
    'title_1' => 'title_1',
    'field_audio' => 'field_audio',
    'title' => 'title',
    'term_node_tid_5' => 'term_node_tid_5',
    'term_node_tid' => 'term_node_tid',
    'term_node_tid_1' => 'term_node_tid_1',
    'term_node_tid_3' => 'term_node_tid_3',
    'term_node_tid_4' => 'term_node_tid_4',
    'term_node_tid_2' => 'term_node_tid_2',
    'path' => 'path',
    'nothing' => 'nothing',
    'field_audio_1' => 'field_audio_1',
    'nothing_1' => 'nothing_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_audio' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'term_node_tid_5' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'term_node_tid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'term_node_tid_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'term_node_tid_3' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'term_node_tid_4' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'term_node_tid_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'path' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_audio_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Track (field_track) */
  $handler->display->display_options['relationships']['field_track_nid']['id'] = 'field_track_nid';
  $handler->display->display_options['relationships']['field_track_nid']['table'] = 'field_data_field_track';
  $handler->display->display_options['relationships']['field_track_nid']['field'] = 'field_track_nid';
  $handler->display->display_options['relationships']['field_track_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_track_nid']['delta'] = '-1';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_track_nid';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 0;
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_audio']['id'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio']['table'] = 'field_data_field_audio';
  $handler->display->display_options['fields']['field_audio']['field'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio']['relationship'] = 'field_track_nid';
  $handler->display->display_options['fields']['field_audio']['label'] = 'play';
  $handler->display->display_options['fields']['field_audio']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_audio']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_audio']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_audio']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_audio']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_audio']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_audio']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_audio']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_audio']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_audio']['type'] = 'soundmanager2_ui360';
  $handler->display->display_options['fields']['field_audio']['settings'] = array(
    'inline' => 1,
    'visualization' => 0,
    'waveform' => 1,
    'eq' => 0,
    'amplifier' => 0,
    'diameter' => '25',
  );
  $handler->display->display_options['fields']['field_audio']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_track_nid';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Artist */
  $handler->display->display_options['fields']['term_node_tid_5']['id'] = 'term_node_tid_5';
  $handler->display->display_options['fields']['term_node_tid_5']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_5']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_5']['relationship'] = 'field_track_nid';
  $handler->display->display_options['fields']['term_node_tid_5']['ui_name'] = 'Artist';
  $handler->display->display_options['fields']['term_node_tid_5']['label'] = 'artist';
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['text'] = '<a href="/playlists?tid_5%5B%5D=[term_node_tid_5-tid]">[term_node_tid_5-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['vocabularies'] = array(
    'artist' => 'artist',
    'genre' => 0,
    'mood' => 0,
    'instruments' => 0,
    'tempo' => 0,
    'keywords' => 0,
    'album' => 0,
  );
  /* Field: Genre */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['relationship'] = 'field_track_nid';
  $handler->display->display_options['fields']['term_node_tid']['ui_name'] = 'Genre';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'genre';
  $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['text'] = '<a href="/playlists?tid%5B%5D=[term_node_tid-tid]">[term_node_tid-name]</a>';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'genre' => 'genre',
    'mood' => 0,
    'instruments' => 0,
    'tempo' => 0,
    'keywords' => 0,
    'artist' => 0,
    'album' => 0,
  );
  /* Field: Mood */
  $handler->display->display_options['fields']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['fields']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_1']['relationship'] = 'field_track_nid';
  $handler->display->display_options['fields']['term_node_tid_1']['ui_name'] = 'Mood';
  $handler->display->display_options['fields']['term_node_tid_1']['label'] = 'mood';
  $handler->display->display_options['fields']['term_node_tid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['text'] = '<a href="/playlists?tid_1%5B%5D=[term_node_tid_1-tid]">[term_node_tid_1-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['vocabularies'] = array(
    'mood' => 'mood',
    'genre' => 0,
    'instruments' => 0,
    'tempo' => 0,
    'keywords' => 0,
    'artist' => 0,
    'album' => 0,
  );
  /* Field: Instruments */
  $handler->display->display_options['fields']['term_node_tid_3']['id'] = 'term_node_tid_3';
  $handler->display->display_options['fields']['term_node_tid_3']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_3']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_3']['relationship'] = 'field_track_nid';
  $handler->display->display_options['fields']['term_node_tid_3']['ui_name'] = 'Instruments';
  $handler->display->display_options['fields']['term_node_tid_3']['label'] = 'instruments';
  $handler->display->display_options['fields']['term_node_tid_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['text'] = '<a href="/playlists?tid_3%5B%5D=[term_node_tid_3-tid]">[term_node_tid_3-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['vocabularies'] = array(
    'instruments' => 'instruments',
    'artist' => 0,
    'album' => 0,
    'genre' => 0,
    'keywords' => 0,
    'mood' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  /* Field: Tempo */
  $handler->display->display_options['fields']['term_node_tid_4']['id'] = 'term_node_tid_4';
  $handler->display->display_options['fields']['term_node_tid_4']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_4']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_4']['relationship'] = 'field_track_nid';
  $handler->display->display_options['fields']['term_node_tid_4']['ui_name'] = 'Tempo';
  $handler->display->display_options['fields']['term_node_tid_4']['label'] = 'tempo';
  $handler->display->display_options['fields']['term_node_tid_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['text'] = '<a href="/playlists?tid_4%5B%5D=[term_node_tid_4-tid]">[term_node_tid_4-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['vocabularies'] = array(
    'tempo' => 'tempo',
    'artist' => 0,
    'album' => 0,
    'genre' => 0,
    'instruments' => 0,
    'keywords' => 0,
    'mood' => 0,
    'tags' => 0,
  );
  /* Field: Keywords */
  $handler->display->display_options['fields']['term_node_tid_2']['id'] = 'term_node_tid_2';
  $handler->display->display_options['fields']['term_node_tid_2']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_2']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_2']['relationship'] = 'field_track_nid';
  $handler->display->display_options['fields']['term_node_tid_2']['ui_name'] = 'Keywords';
  $handler->display->display_options['fields']['term_node_tid_2']['label'] = 'keywords';
  $handler->display->display_options['fields']['term_node_tid_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['vocabularies'] = array(
    'keywords' => 'keywords',
    'artist' => 0,
    'album' => 0,
    'genre' => 0,
    'instruments' => 0,
    'mood' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_track_nid';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'edit track';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<img src="/sites/default/files/icons/edit-track.png" alt="Edit Track" />';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'mp/nojs/[nid_1]/playlists/[nid]';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'musiclibrary-playlist-inline';
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_audio_1']['id'] = 'field_audio_1';
  $handler->display->display_options['fields']['field_audio_1']['table'] = 'field_data_field_audio';
  $handler->display->display_options['fields']['field_audio_1']['field'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio_1']['relationship'] = 'field_track_nid';
  $handler->display->display_options['fields']['field_audio_1']['label'] = 'download';
  $handler->display->display_options['fields']['field_audio_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_audio_1']['alter']['text'] = '<a href="/download/file/fid/[field_audio_1-fid]"><img src="/sites/default/files/icons/downloadicon.png"></a>';
  $handler->display->display_options['fields']['field_audio_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_audio_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_audio_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_audio_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_audio_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_audio_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_audio_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_audio_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_audio_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_audio_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_audio_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_audio_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_audio_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_audio_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_audio_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_audio_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_audio_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_audio_1']['type'] = 'media_link';
  $handler->display->display_options['fields']['field_audio_1']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'remove';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<img src="/sites/default/files/icons/removeicon.png" alt="Remove Track from Playlist" />';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'mp/nojs/[nid_1]/playlists/[nid]/remove/[token]';
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['alt'] = 'Remove track from playlist';
  $handler->display->display_options['fields']['nothing_1']['alter']['link_class'] = 'musiclibrary_playlist-inline';
  $handler->display->display_options['fields']['nothing_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['nid']['title'] = '%1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 0;
  /* Filter criterion: Keywords */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['relationship'] = 'field_track_nid';
  $handler->display->display_options['filters']['keys']['ui_name'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['group'] = 0;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Criteria';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'playlist' => 'playlist',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Filter by Artist */
  $handler->display->display_options['filters']['tid_2']['id'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_2']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_2']['relationship'] = 'field_track_nid';
  $handler->display->display_options['filters']['tid_2']['ui_name'] = 'Filter by Artist';
  $handler->display->display_options['filters']['tid_2']['group'] = 0;
  $handler->display->display_options['filters']['tid_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_2']['expose']['operator_id'] = 'tid_2_op';
  $handler->display->display_options['filters']['tid_2']['expose']['label'] = 'Artist';
  $handler->display->display_options['filters']['tid_2']['expose']['operator'] = 'tid_2_op';
  $handler->display->display_options['filters']['tid_2']['expose']['identifier'] = 'tid_5';
  $handler->display->display_options['filters']['tid_2']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid_2']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid_2']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid_2']['type'] = 'select';
  $handler->display->display_options['filters']['tid_2']['vocabulary'] = 'artist';
  $handler->display->display_options['filters']['tid_2']['error_message'] = 1;
  /* Filter criterion: Filter by Genre */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'field_track_nid';
  $handler->display->display_options['filters']['tid']['ui_name'] = 'Filter by Genre';
  $handler->display->display_options['filters']['tid']['operator'] = 'and';
  $handler->display->display_options['filters']['tid']['group'] = 0;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Genre';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'genre';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['tid']['error_message'] = 1;
  /* Filter criterion: Filter by Mood */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['relationship'] = 'field_track_nid';
  $handler->display->display_options['filters']['tid_1']['ui_name'] = 'Filter by Mood';
  $handler->display->display_options['filters']['tid_1']['group'] = 0;
  $handler->display->display_options['filters']['tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator_id'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['label'] = 'Mood';
  $handler->display->display_options['filters']['tid_1']['expose']['operator'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['identifier'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid_1']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid_1']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_1']['vocabulary'] = 'mood';
  $handler->display->display_options['filters']['tid_1']['hierarchy'] = 1;
  $handler->display->display_options['filters']['tid_1']['error_message'] = 1;
  /* Filter criterion: Filter by Instruments */
  $handler->display->display_options['filters']['field_instruments_tid']['id'] = 'field_instruments_tid';
  $handler->display->display_options['filters']['field_instruments_tid']['table'] = 'field_data_field_instruments';
  $handler->display->display_options['filters']['field_instruments_tid']['field'] = 'field_instruments_tid';
  $handler->display->display_options['filters']['field_instruments_tid']['relationship'] = 'field_track_nid';
  $handler->display->display_options['filters']['field_instruments_tid']['ui_name'] = 'Filter by Instruments';
  $handler->display->display_options['filters']['field_instruments_tid']['group'] = 0;
  $handler->display->display_options['filters']['field_instruments_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_instruments_tid']['expose']['operator_id'] = 'field_instruments_tid_op';
  $handler->display->display_options['filters']['field_instruments_tid']['expose']['label'] = 'Instruments';
  $handler->display->display_options['filters']['field_instruments_tid']['expose']['operator'] = 'field_instruments_tid_op';
  $handler->display->display_options['filters']['field_instruments_tid']['expose']['identifier'] = 'tid_3';
  $handler->display->display_options['filters']['field_instruments_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_instruments_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_instruments_tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['field_instruments_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_instruments_tid']['vocabulary'] = 'instruments';
  $handler->display->display_options['filters']['field_instruments_tid']['error_message'] = 1;
  /* Filter criterion: Filter by Tempo */
  $handler->display->display_options['filters']['field_tempo_tid']['id'] = 'field_tempo_tid';
  $handler->display->display_options['filters']['field_tempo_tid']['table'] = 'field_data_field_tempo';
  $handler->display->display_options['filters']['field_tempo_tid']['field'] = 'field_tempo_tid';
  $handler->display->display_options['filters']['field_tempo_tid']['relationship'] = 'field_track_nid';
  $handler->display->display_options['filters']['field_tempo_tid']['ui_name'] = 'Filter by Tempo';
  $handler->display->display_options['filters']['field_tempo_tid']['group'] = 0;
  $handler->display->display_options['filters']['field_tempo_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tempo_tid']['expose']['operator_id'] = 'field_tempo_tid_op';
  $handler->display->display_options['filters']['field_tempo_tid']['expose']['label'] = 'Tempo';
  $handler->display->display_options['filters']['field_tempo_tid']['expose']['operator'] = 'field_tempo_tid_op';
  $handler->display->display_options['filters']['field_tempo_tid']['expose']['identifier'] = 'tid_4';
  $handler->display->display_options['filters']['field_tempo_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_tempo_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_tempo_tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['field_tempo_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tempo_tid']['vocabulary'] = 'tempo';
  $handler->display->display_options['filters']['field_tempo_tid']['error_message'] = 1;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 0;
  $handler->display->display_options['path'] = 'playlists';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'my playlists';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Tracks';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';
  $export['Playlists'] = $view;

  $view = new view;
  $view->name = 'library';
  $view->description = 'Various views for Tracks';
  $view->tag = 'tracks';
  $view->base_table = 'node';
  $view->human_name = 'Library';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Playlist';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    6 => '6',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Update';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 0;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'keys' => array(
      'more_options' => array(
        'bef_filter_description' => '',
      ),
    ),
    'tid_2' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'tid' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'tid_1' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_instruments_tid' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_tempo_tid' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = 'title';
  $handler->display->display_options['style_options']['columns'] = array(
    'php' => 'php',
    'title' => 'title',
    'field_artist' => 'field_artist',
    'tid' => 'tid',
    'name' => 'name',
    'field_genre' => 'field_genre',
    'field_mood' => 'field_mood',
    'field_audio' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'php' => array(
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_artist' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_genre' => array(
      'align' => '',
      'separator' => '<br>',
    ),
    'field_mood' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_audio' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['exposed_block'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Please add some more search terms';
  /* Relationship: Taxonomy term: Content with term */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'taxonomy_index';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_audio']['id'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio']['table'] = 'field_data_field_audio';
  $handler->display->display_options['fields']['field_audio']['field'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio']['label'] = '';
  $handler->display->display_options['fields']['field_audio']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_audio']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_audio']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_audio']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_audio']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_audio']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_audio']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_audio']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_audio']['field_api_classes'] = 0;
  /* Sort criterion: Artist */
  $handler->display->display_options['sorts']['field_artist_tid']['id'] = 'field_artist_tid';
  $handler->display->display_options['sorts']['field_artist_tid']['table'] = 'field_data_field_artist';
  $handler->display->display_options['sorts']['field_artist_tid']['field'] = 'field_artist_tid';
  $handler->display->display_options['sorts']['field_artist_tid']['ui_name'] = 'Artist';
  $handler->display->display_options['sorts']['field_artist_tid']['expose']['label'] = 'Artist';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'track' => 'track',
  );
  /* Filter criterion: Filter by Genre */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['ui_name'] = 'Filter by Genre';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Genre';
  $handler->display->display_options['filters']['tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'genre';
  $handler->display->display_options['filters']['tid']['error_message'] = 1;
  /* Filter criterion: Filter by Mood */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['ui_name'] = 'Filter by Mood';
  $handler->display->display_options['filters']['tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator_id'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['label'] = 'Mood';
  $handler->display->display_options['filters']['tid_1']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['identifier'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid_1']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid_1']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_1']['vocabulary'] = 'mood';
  $handler->display->display_options['filters']['tid_1']['hierarchy'] = 1;
  $handler->display->display_options['filters']['tid_1']['error_message'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_2']['id'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_2']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_2']['type'] = 'select';
  $handler->display->display_options['filters']['tid_2']['vocabulary'] = 'genre';

  /* Display: Library (page) */
  $handler = $view->new_display('page', 'Library (page)', 'library');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Table view for the music library';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'library';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_audio' => 'field_audio',
    'title' => 'title',
    'term_node_tid_5' => 'term_node_tid_5',
    'term_node_tid' => 'term_node_tid',
    'term_node_tid_1' => 'term_node_tid_1',
    'term_node_tid_3' => 'term_node_tid_3',
    'term_node_tid_4' => 'term_node_tid_4',
    'term_node_tid_2' => 'term_node_tid_2',
    'field_playlist' => 'field_playlist',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_audio' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
    ),
    'term_node_tid_5' => array(
      'align' => '',
      'separator' => '',
    ),
    'term_node_tid' => array(
      'align' => '',
      'separator' => '',
    ),
    'term_node_tid_1' => array(
      'align' => '',
      'separator' => '',
    ),
    'term_node_tid_3' => array(
      'align' => '',
      'separator' => '',
    ),
    'term_node_tid_4' => array(
      'align' => '',
      'separator' => '',
    ),
    'term_node_tid_2' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_playlist' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_audio']['id'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio']['table'] = 'field_data_field_audio';
  $handler->display->display_options['fields']['field_audio']['field'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio']['label'] = 'play';
  $handler->display->display_options['fields']['field_audio']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_audio']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_audio']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_audio']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_audio']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_audio']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_audio']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_audio']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_audio']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_audio']['type'] = 'soundmanager2_ui360';
  $handler->display->display_options['fields']['field_audio']['settings'] = array(
    'inline' => 1,
    'visualization' => 0,
    'waveform' => 1,
    'eq' => 0,
    'amplifier' => 0,
    'diameter' => '25',
  );
  $handler->display->display_options['fields']['field_audio']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Artist */
  $handler->display->display_options['fields']['term_node_tid_5']['id'] = 'term_node_tid_5';
  $handler->display->display_options['fields']['term_node_tid_5']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_5']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_5']['ui_name'] = 'Artist';
  $handler->display->display_options['fields']['term_node_tid_5']['label'] = 'artist';
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['text'] = '<a href="/library?tid_5%5B%5D=[term_node_tid_5-tid]">[term_node_tid_5-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['vocabularies'] = array(
    'artist' => 'artist',
    'workbench_access' => 0,
    'album' => 0,
    'genre' => 0,
    'instruments' => 0,
    'keywords' => 0,
    'mood' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  /* Field: Genre */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['ui_name'] = 'Genre';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'genre';
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['text'] = '<a href="/library?tid%5B%5D=[term_node_tid-tid]">[term_node_tid-name]</a>';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'genre' => 'genre',
    'workbench_access' => 0,
    'artist' => 0,
    'album' => 0,
    'instruments' => 0,
    'keywords' => 0,
    'mood' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  /* Field: Mood */
  $handler->display->display_options['fields']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['fields']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_1']['ui_name'] = 'Mood';
  $handler->display->display_options['fields']['term_node_tid_1']['label'] = 'mood';
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['text'] = '<a href="/library?tid_1%5B%5D=[term_node_tid_1-tid]">[term_node_tid_1-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['vocabularies'] = array(
    'mood' => 'mood',
    'workbench_access' => 0,
    'artist' => 0,
    'album' => 0,
    'genre' => 0,
    'instruments' => 0,
    'keywords' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'playlist';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<img src="/sites/default/files/icons/addtoplaylist.png" alt="Add to Playlist" />';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'mp/nojs/[nid]/playlists';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['alt'] = 'Add or remove this track to new or existing playlists.';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'musiclibrary-playlist-inline';
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Instruments */
  $handler->display->display_options['fields']['term_node_tid_3']['id'] = 'term_node_tid_3';
  $handler->display->display_options['fields']['term_node_tid_3']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_3']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_3']['ui_name'] = 'Instruments';
  $handler->display->display_options['fields']['term_node_tid_3']['label'] = 'instruments';
  $handler->display->display_options['fields']['term_node_tid_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['text'] = '<a href="/library?tid_3%5B%5D=[term_node_tid_3-tid]">[term_node_tid_3-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['vocabularies'] = array(
    'instruments' => 'instruments',
    'workbench_access' => 0,
    'artist' => 0,
    'album' => 0,
    'genre' => 0,
    'keywords' => 0,
    'mood' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  /* Field: Tempo */
  $handler->display->display_options['fields']['term_node_tid_4']['id'] = 'term_node_tid_4';
  $handler->display->display_options['fields']['term_node_tid_4']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_4']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_4']['ui_name'] = 'Tempo';
  $handler->display->display_options['fields']['term_node_tid_4']['label'] = 'tempo';
  $handler->display->display_options['fields']['term_node_tid_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['text'] = '<a href="/library?tid_4%5B%5D=[term_node_tid_4-tid]">[term_node_tid_4-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['vocabularies'] = array(
    'tempo' => 'tempo',
    'workbench_access' => 0,
    'artist' => 0,
    'album' => 0,
    'genre' => 0,
    'instruments' => 0,
    'keywords' => 0,
    'mood' => 0,
    'tags' => 0,
  );
  /* Field: Keywords */
  $handler->display->display_options['fields']['term_node_tid_2']['id'] = 'term_node_tid_2';
  $handler->display->display_options['fields']['term_node_tid_2']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_2']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_2']['ui_name'] = 'Keywords';
  $handler->display->display_options['fields']['term_node_tid_2']['label'] = 'keywords';
  $handler->display->display_options['fields']['term_node_tid_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['vocabularies'] = array(
    'keywords' => 'keywords',
    'workbench_access' => 0,
    'artist' => 0,
    'album' => 0,
    'genre' => 0,
    'instruments' => 0,
    'mood' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Keywords */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['ui_name'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['group'] = 0;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Library';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'track' => 'track',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Filter by Artist */
  $handler->display->display_options['filters']['tid_2']['id'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_2']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_2']['ui_name'] = 'Filter by Artist';
  $handler->display->display_options['filters']['tid_2']['operator'] = 'and';
  $handler->display->display_options['filters']['tid_2']['group'] = 0;
  $handler->display->display_options['filters']['tid_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_2']['expose']['operator_id'] = 'tid_2_op';
  $handler->display->display_options['filters']['tid_2']['expose']['label'] = 'Artist';
  $handler->display->display_options['filters']['tid_2']['expose']['operator'] = 'tid_2_op';
  $handler->display->display_options['filters']['tid_2']['expose']['identifier'] = 'tid_5';
  $handler->display->display_options['filters']['tid_2']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid_2']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid_2']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid_2']['type'] = 'select';
  $handler->display->display_options['filters']['tid_2']['vocabulary'] = 'artist';
  $handler->display->display_options['filters']['tid_2']['error_message'] = 1;
  /* Filter criterion: Filter by Genre */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['ui_name'] = 'Filter by Genre';
  $handler->display->display_options['filters']['tid']['operator'] = 'and';
  $handler->display->display_options['filters']['tid']['group'] = 0;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Genre';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'genre';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['tid']['error_message'] = 1;
  /* Filter criterion: Filter by Mood */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['ui_name'] = 'Filter by Mood';
  $handler->display->display_options['filters']['tid_1']['operator'] = 'and';
  $handler->display->display_options['filters']['tid_1']['group'] = 0;
  $handler->display->display_options['filters']['tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator_id'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['label'] = 'Mood';
  $handler->display->display_options['filters']['tid_1']['expose']['operator'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['identifier'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid_1']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid_1']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_1']['vocabulary'] = 'mood';
  $handler->display->display_options['filters']['tid_1']['hierarchy'] = 1;
  $handler->display->display_options['filters']['tid_1']['error_message'] = 1;
  /* Filter criterion: Filter by Instruments */
  $handler->display->display_options['filters']['field_instruments_tid']['id'] = 'field_instruments_tid';
  $handler->display->display_options['filters']['field_instruments_tid']['table'] = 'field_data_field_instruments';
  $handler->display->display_options['filters']['field_instruments_tid']['field'] = 'field_instruments_tid';
  $handler->display->display_options['filters']['field_instruments_tid']['ui_name'] = 'Filter by Instruments';
  $handler->display->display_options['filters']['field_instruments_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_instruments_tid']['group'] = 0;
  $handler->display->display_options['filters']['field_instruments_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_instruments_tid']['expose']['operator_id'] = 'field_instruments_tid_op';
  $handler->display->display_options['filters']['field_instruments_tid']['expose']['label'] = 'Instruments';
  $handler->display->display_options['filters']['field_instruments_tid']['expose']['operator'] = 'field_instruments_tid_op';
  $handler->display->display_options['filters']['field_instruments_tid']['expose']['identifier'] = 'tid_3';
  $handler->display->display_options['filters']['field_instruments_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_instruments_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_instruments_tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['field_instruments_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_instruments_tid']['vocabulary'] = 'instruments';
  $handler->display->display_options['filters']['field_instruments_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_instruments_tid']['error_message'] = 1;
  /* Filter criterion: Filter by Tempo */
  $handler->display->display_options['filters']['field_tempo_tid']['id'] = 'field_tempo_tid';
  $handler->display->display_options['filters']['field_tempo_tid']['table'] = 'field_data_field_tempo';
  $handler->display->display_options['filters']['field_tempo_tid']['field'] = 'field_tempo_tid';
  $handler->display->display_options['filters']['field_tempo_tid']['ui_name'] = 'Filter by Tempo';
  $handler->display->display_options['filters']['field_tempo_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_tempo_tid']['group'] = 0;
  $handler->display->display_options['filters']['field_tempo_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tempo_tid']['expose']['operator_id'] = 'field_tempo_tid_op';
  $handler->display->display_options['filters']['field_tempo_tid']['expose']['label'] = 'Tempo';
  $handler->display->display_options['filters']['field_tempo_tid']['expose']['operator'] = 'field_tempo_tid_op';
  $handler->display->display_options['filters']['field_tempo_tid']['expose']['identifier'] = 'tid_4';
  $handler->display->display_options['filters']['field_tempo_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_tempo_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_tempo_tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['field_tempo_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tempo_tid']['vocabulary'] = 'tempo';
  $handler->display->display_options['filters']['field_tempo_tid']['error_message'] = 1;
  $handler->display->display_options['path'] = 'library';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Search';
  $handler->display->display_options['menu']['weight'] = '-11';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Tracks';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';
  $export['library'] = $view;

  $view = new view;
  $view->name = 'library_admin';
  $view->description = 'Library admin view';
  $view->tag = 'admin';
  $view->base_table = 'node';
  $view->human_name = 'Manage Library';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Playlist';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'status' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
    'keys' => array(
      'more_options' => array(
        'bef_filter_description' => '',
      ),
    ),
    'tid_2' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100, 200';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = 'title';
  $handler->display->display_options['style_options']['columns'] = array(
    'php' => 'php',
    'title' => 'title',
    'field_artist' => 'field_artist',
    'tid' => 'tid',
    'name' => 'name',
    'field_genre' => 'field_genre',
    'field_mood' => 'field_mood',
    'field_audio' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'php' => array(
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_artist' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_genre' => array(
      'align' => '',
      'separator' => '<br>',
    ),
    'field_mood' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_audio' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['exposed_block'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links">
<li>
<a href="/node/add/track">Add track</a>
</li>
</ul>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no items in the library';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Taxonomy term: Content with term */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'taxonomy_index';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_audio']['id'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio']['table'] = 'field_data_field_audio';
  $handler->display->display_options['fields']['field_audio']['field'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio']['label'] = '';
  $handler->display->display_options['fields']['field_audio']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_audio']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_audio']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_audio']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_audio']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_audio']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_audio']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_audio']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_audio']['field_api_classes'] = 0;
  /* Sort criterion: Artist */
  $handler->display->display_options['sorts']['field_artist_tid']['id'] = 'field_artist_tid';
  $handler->display->display_options['sorts']['field_artist_tid']['table'] = 'field_data_field_artist';
  $handler->display->display_options['sorts']['field_artist_tid']['field'] = 'field_artist_tid';
  $handler->display->display_options['sorts']['field_artist_tid']['ui_name'] = 'Artist';
  $handler->display->display_options['sorts']['field_artist_tid']['expose']['label'] = 'Artist';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'track' => 'track',
  );
  /* Filter criterion: Filter by Genre */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['ui_name'] = 'Filter by Genre';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Genre';
  $handler->display->display_options['filters']['tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'genre';
  $handler->display->display_options['filters']['tid']['error_message'] = 1;
  /* Filter criterion: Filter by Mood */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['ui_name'] = 'Filter by Mood';
  $handler->display->display_options['filters']['tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator_id'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['label'] = 'Mood';
  $handler->display->display_options['filters']['tid_1']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['identifier'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid_1']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid_1']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_1']['vocabulary'] = 'mood';
  $handler->display->display_options['filters']['tid_1']['hierarchy'] = 1;
  $handler->display->display_options['filters']['tid_1']['error_message'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_2']['id'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_2']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_2']['type'] = 'select';
  $handler->display->display_options['filters']['tid_2']['vocabulary'] = 'genre';

  /* Display: Library (page) */
  $handler = $view->new_display('page', 'Library (page)', 'library');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Table view for the music library';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'library';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_audio' => 'field_audio',
    'title' => 'title',
    'term_node_tid_5' => 'term_node_tid_5',
    'term_node_tid' => 'term_node_tid',
    'term_node_tid_1' => 'term_node_tid_1',
    'term_node_tid_3' => 'term_node_tid_3',
    'term_node_tid_4' => 'term_node_tid_4',
    'term_node_tid_2' => 'term_node_tid_2',
    'field_playlist' => 'field_playlist',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_audio' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
    ),
    'term_node_tid_5' => array(
      'align' => '',
      'separator' => '',
    ),
    'term_node_tid' => array(
      'align' => '',
      'separator' => '',
    ),
    'term_node_tid_1' => array(
      'align' => '',
      'separator' => '',
    ),
    'term_node_tid_3' => array(
      'align' => '',
      'separator' => '',
    ),
    'term_node_tid_4' => array(
      'align' => '',
      'separator' => '',
    ),
    'term_node_tid_2' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_playlist' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Comment: Comments of the node */
  $handler->display->display_options['relationships']['cid']['id'] = 'cid';
  $handler->display->display_options['relationships']['cid']['table'] = 'node';
  $handler->display->display_options['relationships']['cid']['field'] = 'cid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Actions';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
    'action::node_publish_action' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
    'action::node_unpublish_action' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_audio']['id'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio']['table'] = 'field_data_field_audio';
  $handler->display->display_options['fields']['field_audio']['field'] = 'field_audio';
  $handler->display->display_options['fields']['field_audio']['label'] = 'play';
  $handler->display->display_options['fields']['field_audio']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_audio']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_audio']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_audio']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_audio']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_audio']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_audio']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_audio']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_audio']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_audio']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_audio']['type'] = 'soundmanager2_ui360';
  $handler->display->display_options['fields']['field_audio']['settings'] = array(
    'inline' => 1,
    'visualization' => 0,
    'waveform' => 1,
    'eq' => 0,
    'amplifier' => 0,
    'diameter' => '25',
  );
  $handler->display->display_options['fields']['field_audio']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_audio']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Artist */
  $handler->display->display_options['fields']['term_node_tid_5']['id'] = 'term_node_tid_5';
  $handler->display->display_options['fields']['term_node_tid_5']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_5']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_5']['ui_name'] = 'Artist';
  $handler->display->display_options['fields']['term_node_tid_5']['label'] = 'artist';
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['text'] = '<a href="/admin/content/library?tid_5%5B%5D=[term_node_tid_5-tid]">[term_node_tid_5-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid_5']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_5']['vocabularies'] = array(
    'artist' => 'artist',
    'album' => 0,
    'genre' => 0,
    'instruments' => 0,
    'keywords' => 0,
    'mood' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  /* Field: Album */
  $handler->display->display_options['fields']['term_node_tid_6']['id'] = 'term_node_tid_6';
  $handler->display->display_options['fields']['term_node_tid_6']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_6']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_6']['ui_name'] = 'Album';
  $handler->display->display_options['fields']['term_node_tid_6']['label'] = 'Album';
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['text'] = '<a href="/admin/content/library?tid_6%5B%5D=[term_node_tid_6-tid]">[term_node_tid_6-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_6']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_6']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_6']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_6']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_6']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_6']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid_6']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_6']['vocabularies'] = array(
    'album' => 'album',
    'artist' => 0,
    'genre' => 0,
    'instruments' => 0,
    'keywords' => 0,
    'mood' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  /* Field: Genre */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['ui_name'] = 'Genre';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'genre';
  $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['text'] = '<a href="/library?tid%5B%5D=[term_node_tid-tid]">[term_node_tid-name]</a>';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'genre' => 'genre',
    'artist' => 0,
    'album' => 0,
    'instruments' => 0,
    'keywords' => 0,
    'mood' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  /* Field: Mood */
  $handler->display->display_options['fields']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['fields']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_1']['ui_name'] = 'Mood';
  $handler->display->display_options['fields']['term_node_tid_1']['label'] = 'mood';
  $handler->display->display_options['fields']['term_node_tid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['text'] = '<a href="/library?tid_1%5B%5D=[term_node_tid_1-tid]">[term_node_tid_1-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_1']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_1']['vocabularies'] = array(
    'mood' => 'mood',
    'artist' => 0,
    'album' => 0,
    'genre' => 0,
    'instruments' => 0,
    'keywords' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  /* Field: Instruments */
  $handler->display->display_options['fields']['term_node_tid_3']['id'] = 'term_node_tid_3';
  $handler->display->display_options['fields']['term_node_tid_3']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_3']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_3']['ui_name'] = 'Instruments';
  $handler->display->display_options['fields']['term_node_tid_3']['label'] = 'instruments';
  $handler->display->display_options['fields']['term_node_tid_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['text'] = '<a href="/library?tid_3%5B%5D=[term_node_tid_3-tid]">[term_node_tid_3-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid_3']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_3']['vocabularies'] = array(
    'instruments' => 'instruments',
    'workbench_access' => 0,
    'artist' => 0,
    'album' => 0,
    'genre' => 0,
    'keywords' => 0,
    'mood' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  /* Field: Tempo */
  $handler->display->display_options['fields']['term_node_tid_4']['id'] = 'term_node_tid_4';
  $handler->display->display_options['fields']['term_node_tid_4']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_4']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_4']['ui_name'] = 'Tempo';
  $handler->display->display_options['fields']['term_node_tid_4']['label'] = 'tempo';
  $handler->display->display_options['fields']['term_node_tid_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['text'] = '<a href="/library?tid_4%5B%5D=[term_node_tid_4-tid]">[term_node_tid_4-name]</a>';
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid_4']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_4']['vocabularies'] = array(
    'tempo' => 'tempo',
    'workbench_access' => 0,
    'artist' => 0,
    'album' => 0,
    'genre' => 0,
    'instruments' => 0,
    'keywords' => 0,
    'mood' => 0,
    'tags' => 0,
  );
  /* Field: Keywords */
  $handler->display->display_options['fields']['term_node_tid_2']['id'] = 'term_node_tid_2';
  $handler->display->display_options['fields']['term_node_tid_2']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid_2']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid_2']['ui_name'] = 'Keywords';
  $handler->display->display_options['fields']['term_node_tid_2']['label'] = 'keywords';
  $handler->display->display_options['fields']['term_node_tid_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid_2']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid_2']['vocabularies'] = array(
    'keywords' => 'keywords',
    'workbench_access' => 0,
    'artist' => 0,
    'album' => 0,
    'genre' => 0,
    'instruments' => 0,
    'mood' => 0,
    'tags' => 0,
    'tempo' => 0,
  );
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Node: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'track' => 'track',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Comment: Title */
  $handler->display->display_options['filters']['subject']['id'] = 'subject';
  $handler->display->display_options['filters']['subject']['table'] = 'comment';
  $handler->display->display_options['filters']['subject']['field'] = 'subject';
  $handler->display->display_options['filters']['subject']['relationship'] = 'cid';
  $handler->display->display_options['filters']['subject']['operator'] = 'contains';
  $handler->display->display_options['filters']['subject']['group'] = 0;
  $handler->display->display_options['filters']['subject']['exposed'] = TRUE;
  $handler->display->display_options['filters']['subject']['expose']['operator_id'] = 'subject_op';
  $handler->display->display_options['filters']['subject']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['subject']['expose']['operator'] = 'subject_op';
  $handler->display->display_options['filters']['subject']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['subject']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['subject']['expose']['multiple'] = FALSE;
  /* Filter criterion: Filter by Artist */
  $handler->display->display_options['filters']['tid_2']['id'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_2']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_2']['ui_name'] = 'Filter by Artist';
  $handler->display->display_options['filters']['tid_2']['group'] = 0;
  $handler->display->display_options['filters']['tid_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_2']['expose']['operator_id'] = 'tid_2_op';
  $handler->display->display_options['filters']['tid_2']['expose']['label'] = 'Artist';
  $handler->display->display_options['filters']['tid_2']['expose']['operator'] = 'tid_2_op';
  $handler->display->display_options['filters']['tid_2']['expose']['identifier'] = 'tid_5';
  $handler->display->display_options['filters']['tid_2']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['tid_2']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid_2']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid_2']['type'] = 'select';
  $handler->display->display_options['filters']['tid_2']['vocabulary'] = 'artist';
  $handler->display->display_options['filters']['tid_2']['error_message'] = 1;
  /* Filter criterion: Filter by Album */
  $handler->display->display_options['filters']['field_album_tid']['id'] = 'field_album_tid';
  $handler->display->display_options['filters']['field_album_tid']['table'] = 'field_data_field_album';
  $handler->display->display_options['filters']['field_album_tid']['field'] = 'field_album_tid';
  $handler->display->display_options['filters']['field_album_tid']['ui_name'] = 'Filter by Album';
  $handler->display->display_options['filters']['field_album_tid']['group'] = 0;
  $handler->display->display_options['filters']['field_album_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_album_tid']['expose']['operator_id'] = 'field_album_tid_op';
  $handler->display->display_options['filters']['field_album_tid']['expose']['label'] = 'Album';
  $handler->display->display_options['filters']['field_album_tid']['expose']['operator'] = 'field_album_tid_op';
  $handler->display->display_options['filters']['field_album_tid']['expose']['identifier'] = 'tid_6';
  $handler->display->display_options['filters']['field_album_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_album_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_album_tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['field_album_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_album_tid']['vocabulary'] = 'album';
  $handler->display->display_options['filters']['field_album_tid']['error_message'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/library';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Music Library';
  $handler->display->display_options['menu']['weight'] = '-11';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Tracks';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';
  $export['library_admin'] = $view;

  return $export;
}
