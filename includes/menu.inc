<?php

/**
 * @file
 * 
 * Menu system callbacks for Monitor Pop Customizations.
 */
function musiclibrary_playlist_menu_track_edit_playlists($track, $playlist = NULL, $method = 'ajax') {
  ctools_include('ajax');
  ctools_include('playlists', 'musiclibrary_playlist', 'includes');
  ctools_include('inline', 'musiclibrary_playlist', 'includes');

  $form_state = array(
    'ajax'      => ($method == 'ajax'),
    'node'      => $track,
    'title'     => $track->title,
    'playlist'  => $playlist
  );
  
  $output = musiclibrary_playlist_inline_form_wrapper('musiclibrary_playlist_track_edit_playlists_form', $form_state);
  if (!empty($form_state['executed'])) {
    $output = array();
    $changes = $form_state['changes'];
    $add_commands = array();
    $remove_commands = array();
    $new_commands = array();
    if (!empty($playlist)) {
      foreach($changes as $type => $playlists) {
        foreach($playlists as $nid) {
          switch($type) {
            case 'add':
              // Clone the clicked upon row to a new table and update the classes for the table context.

              $add_commands[] = array(
                'command' => 'musiclibrary_playlist_copy_to',
                'selector' => 'tr.musiclibrary-playlist-row-playlist-' . $playlist->nid . '.musiclibrary-playlist-row-track-' . $track->nid,
                'destination' => 'table.musiclibrary-playlist-row-playlist-' . $nid,
                'add_classes' => 'musiclibrary-playlist-row-playlist-' . $nid,
                'remove_classes' => 'musiclibrary-playlist-row-playlist-' . $playlist->nid,
                'link_selector' => '.musiclibrary-playlist-inline-add',
                'link_href' => 'mp/nojs/' . $track->nid . '/playlists/' . $nid,
                'remove_link_selector' => '.musiclibrary-playlist-inline-remove',
                'remove_link_href' => 'mp/nojs/' . $track->nid . '/playlists/' . $nid . '/remove/' . drupal_get_token($nid)
              );
              $add_commands[] = ajax_command_restripe('table:has(.musiclibrary-playlist-row-playlist-' . $nid . ')');

              // $add_commands[] = ctools_ajax_command_reload();
              break;
            case 'remove':
              // Remove any removed tracks.
              $remove_commands[] = ajax_command_invoke('tr.musiclibrary-playlist-row-playlist-' . $nid . '.musiclibrary-playlist-row-track-' . $track->nid, 'fadeOut');
              $remove_commands[] = ajax_command_replace('tr.musiclibrary-playlist-row-playlist-' . $nid . '.musiclibrary-playlist-row-track-' . $track->nid, 'removed track from playlis <a href="library">Browse tracks from the library</a>t');
              $remove_commands[] = ajax_command_restripe('table:has(.musiclibrary-playlist-row-playlist-' . $nid . ')');
              break;
            case 'new':

              $new_commands[] = array(
                'command' => 'musiclibrary_playlist_add_new_playlist',
                'view_html' => musiclibrary_playlist_playlists_get_view($nid)
              );

              // $new_commands[] = ctools_ajax_command_reload();
              break;
          }

        }
      }
    }
    $output = $add_commands;
    $output = array_merge($output, $new_commands);
    $output[] = musiclibrary_playlist_inline_command_dismiss();
    $output = array_merge($output, $remove_commands);
  }

  print ajax_render($output);
}

function musiclibrary_playlist_menu_track_remove_playlists($track, $playlist, $token, $method = 'ajax') {
  if (!drupal_valid_token($token, $playlist->nid)) {
    drupal_access_denied();
  }
  
  ctools_include('playlists', 'musiclibrary_playlist', 'includes');
  $changes = musiclibrary_playlist_playlists_remove_track($playlist, $track->nid);
  $remove_commands = array();
  if (!empty($changes['remove'])) {
    foreach($changes['remove'] as $nid) {
      /*
      $remove_commands[] = ajax_command_invoke(
          'tr.musiclibrary-playlist-row-playlist-' . $nid . '.musiclibrary-playlist-row-track-' . $track->nid, 
          'fadeOut', 
          array('function() { $(this).remove(); }')
        );
       * 
       */
      //$command = ajax_command_remove('tr.musiclibrary-playlist-row-playlist-' . $nid . '.musiclibrary-playlist-row-track-' . $track->nid);
      $remove_commands[] = ajax_command_remove('tr.musiclibrary-playlist-row-playlist-' . $nid . '.musiclibrary-playlist-row-track-' . $track->nid, array('effect' => 'fade'));
      $remove_commands[] = ajax_command_restripe(':has(.musiclibrary-playlist-row-playlist-' . $nid . ') table');
    }
  }
  
  print ajax_render($remove_commands);
}

function musiclibrary_playlist_menu_playlists_add($method = 'ajax') {
  ctools_include('ajax');
  ctools_include('playlists', 'musiclibrary_playlist', 'includes');
  ctools_include('inline', 'musiclibrary_playlist', 'includes');
  
  $form_state = array(
    'ajax'  => ($method == 'ajax'),
  );
  $output = musiclibrary_playlist_inline_form_wrapper('musiclibrary_playlist_playlists_edit_form', $form_state);
  if (!empty($form_state['executed']) && is_array($form_state['changes'])) {
    $changes = $form_state['changes'];
    /*
    foreach($changes['new'] as $nid) {
     
      $output[] = array(
        'command' => 'musiclibrary_playlist_add_new_playlist',
        'view_html' => musiclibrary_playlist_playlists_get_view($nid)
      );
      
    }
     * 
     */
    drupal_set_message('Your playlist has been created.');
    $output[] = ctools_ajax_command_reload();
    $output[] = musiclibrary_playlist_inline_command_dismiss();
  }

  print ajax_render($output);
}

function musiclibrary_playlist_menu_playlists_edit($node, $method) {
  ctools_include('ajax');
  ctools_include('playlists', 'musiclibrary_playlist', 'includes');
  ctools_include('inline', 'musiclibrary_playlist', 'includes');
  
  $output = array();
  if ($node->type == 'playlist') {
  
    $form_state = array(
      'ajax'  => ($method == 'ajax'),
      'node' => $node
    );
    
    $output = musiclibrary_playlist_inline_form_wrapper('musiclibrary_playlist_playlists_edit_form', $form_state);
    if (!empty($form_state['executed']) && is_array($form_state['changes'])) {
      $output[] = ajax_command_html('.musiclibrary-playlist-playlist-' . $node->nid . ' .playlist-title a', 
          $node->title);
      $output[] = musiclibrary_playlist_inline_command_dismiss();
    }
  }
  else {
    $output[] = ajax_command_alert('Node is not a playlist.');
  }
    

  print ajax_render($output);
}

function musiclibrary_playlist_menu_playlists_delete($node, $method) {
  ctools_include('ajax');
  ctools_include('playlists', 'musiclibrary_playlist', 'includes');
  ctools_include('inline', 'musiclibrary_playlist', 'includes');
  
  $output = array();
  if ($node->type == 'playlist') {
  
    $form_state = array(
      'ajax'  => ($method == 'ajax'),
      'node' => $node
    );
    
    $output = musiclibrary_playlist_inline_form_wrapper('musiclibrary_playlist_playlists_delete_form', $form_state);
    if (!empty($form_state['executed']) && is_array($form_state['changes'])) {
      $output[] = ctools_ajax_command_reload();  
      drupal_set_message('Your playlist has been deleted.');
      $output[] = musiclibrary_playlist_inline_command_dismiss();
      $output[] = ajax_command_remove('.musiclibrary-playlist-playlist-' . $node->nid);
    }
  }
  else {
    $output[] = ajax_command_alert('Node is not a playlist.');
  }
    

  print ajax_render($output);
}

function musiclibrary_playlist_menu_test() {
  return 'output';
}
