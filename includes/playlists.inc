<?php
/**
 * Form API form builder function.
 * 
 * @param array $form
 *   Not sure what this argument is exactly.
 * @param array $form_state
 * @return array 
 */
function musiclibrary_playlist_track_edit_playlists_form($form, $form_state) {
  global $user;
  $form = array();
  $track = $form_state['node'];
  
  // Get all of the user's existing playlists.
  $query = new EntityFieldQuery();
  $entities = $query->entityCondition('entity_type', 'node')
                    ->entityCondition('bundle', 'playlist')
                    ->propertyOrderBy('title')
                    ->propertyCondition('uid', $user->uid)
                    ->execute();
  $playlists = node_load_multiple(array_keys($entities['node']));

  // Create an array of playlist options.
  $options = array();
  $default_values = array();
  foreach($playlists as $playlist) {
    $options[$playlist->nid] = $playlist->title;
    // If current track is in the playlist add the playlist to default_values.
    if (!empty($playlist->field_track['und'])) {
      foreach($playlist->field_track['und'] as $ptracks) {       
        foreach($ptracks as $nid) {
          if ($nid == $track->nid) {
            $default_values[] = $playlist->nid;
          }
        }
      }
    }
  }
  
  if (!empty($options)) {
    $form['playlists'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Add this track to the playlists below:'),
      '#options' => $options,
      '#default_value' => $default_values,
      '#multiple' => TRUE
    );
  }
  else {
    $form['playlists'] = array(
      '#type' => 'markup',
      '#markup' => '<p>' . t("You don't have any playlists yet!") . '</p>'
    );
  }
  
  $form['new_playlist'] = array(
    '#type' => 'fieldset',
    //'#attributes' = array('class' => 'add-to-new-playlist');
    '#title' => 'Or add this track to a new playlist:',
    '#collapsed' => FALSE,
    'new_title' => array(
      '#type' => 'textfield',
      '#title' => t('Playlist Name'),
    )
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Update Track Playlists'
  );
    
  return $form;
}

function musiclibrary_playlist_track_edit_playlists_form_submit($form, &$form_state) {
  $new_pl_ids = array_values($form_state['values']['playlists']);
  $old_pl_ids = $form_state['complete form']['playlists']['#default_value'];
  $track = $form_state['node'];
  
  $changes = array();
  
  //todo: check to see if a playlist of this name exsts before creating one
  if ($new_playlist_title = $form_state['values']['new_title']) {
    $new_playlist = musiclibrary_playlist_playlists_create_playlist($new_playlist_title, $track);
    $changes['new'][] = $new_playlist->nid;
  }
  
  foreach($new_pl_ids as $new_id) {
    if ($new_id && !in_array($new_id, $old_pl_ids)) {
      $playlist = node_load($new_id);
      $playlist->field_track['und'] = empty($playlist->field_track['und']) ? array() : $playlist->field_track['und'];
      $playlist->field_track['und'][] = array('nid' => $track->nid);
      
      node_save($playlist);
      $changes['add'][] = $playlist->nid;
    }
  }
  
  foreach($old_pl_ids as $old_id) {
    if (!in_array($old_id, $new_pl_ids)) {
      $playlist = node_load($old_id);
      $playlist->field_track['und'] = empty($playlist->field_track['und']) ? array() : $playlist->field_track['und'];
      foreach($playlist->field_track['und'] as $key => $track_nid) {
        if ($track_nid['nid'] == $track->nid) {
          unset($playlist->field_track['und'][$key]);
        }
      }
      
      node_save($playlist);
      $changes['remove'][] = $playlist->nid;
    }
  }
  
  $form_state['changes'] = $changes;
  
}

function musiclibrary_playlist_playlists_get_view($nid) {
  $view = views_get_view('Playlists');
  $html = $view->preview('playlists', array($nid));
  return $html;
}

function musiclibrary_playlist_playlists_remove_track($playlist, $track_nid) {
  $changes = array();
  $changes['remove'] = array();
  if (is_array($playlist->field_track) && is_array($playlist->field_track['und'])) {
    foreach($playlist->field_track['und'] as $key => $track) {
      if ($track['nid'] == $track_nid) {
        unset($playlist->field_track['und'][$key]);
        $changes['remove'][] = $playlist->nid;
      }
    }
    if (!empty($changes['remove'])) {
      node_save($playlist);
    }
  }
  return $changes;
}

function musiclibrary_playlist_playlists_edit_form($form, $form_state) {
  $default_value = '';
  if (!empty($form_state['node'])) {
    $default_value = $form_state['node']->title;
  }
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Playlist Name'),
    '#default_value' => $default_value
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => empty($form_state['node']) ? t('Create Playlist') : t('Save Playlist')
  );
  return $form;
}

function musiclibrary_playlist_playlists_edit_form_submit($form, &$form_state) {
  // dpm($form);
  // dpm($form_state);
  $changes = array();
  if (!empty($form_state['node'])) {
    $changes['update'] = array();
    // node_object_prepare($form_state['node']);
    $form_state['node']->title = $form_state['values']['title'];
    node_save($form_state['node']);
    $changes['update'][] = $form_state['node']->nid;
  }
  else {
    $changes['new'] = array();
    $new_playlist = musiclibrary_playlist_playlists_create_playlist($form_state['values']['title']);
    if (!empty($new_playlist->nid)) {
      $changes['new'][] = $new_playlist->nid;
    }
  }
  $form_state['changes'] = $changes;
}



function musiclibrary_playlist_playlists_delete_form($form, $form_state) {

  $form['warning'] = array(
    '#type' => 'item',
    '#markup' => t('Are you sure you want to delete this entire playlist?'),
    '#weight' => -1,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Delete Playlist'),
    '#weight' => 0,
  );
  return $form;

}

function musiclibrary_playlist_playlists_delete_form_submit($form, &$form_state) {
  //dpm($form);
  //dpm($form_state);
  $changes = array();
  if (!empty($form_state['node'])) {
    $changes['update'] = array();
    // node_object_prepare($form_state['node']);
    //$form_state['node']->title = $form_state['values']['title'];
    node_delete($form_state['node']->nid);
    $changes['remove'][] = $form_state['node']->nid;
  }
  $form_state['changes'] = $changes;
}



function musiclibrary_playlist_playlists_create_playlist($title, $track = NULL) {
  $new_playlist = new stdClass();
  $new_playlist->type = 'playlist';
  $new_playlist->language = LANGUAGE_NONE;
  node_object_prepare($new_playlist);
  $new_playlist->title = $title;
  if (!empty($track)) {
    $new_playlist->field_track = array(
      'und' => array(array(
        'nid' => $track->nid
      ))
    );
  }
  node_save($new_playlist);
  return $new_playlist;
}

