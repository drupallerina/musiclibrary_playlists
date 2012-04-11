(function ($) {
  
  Drupal.musiclibrary_playlist = Drupal.musiclibrary_playlist || {};
  Drupal.musiclibrary_playlist.filters = {};
  Drupal.musiclibrary_playlist.filters.cb_onchange = function() {
    var thischecked = $(this).attr('checked');
    
    // $(this).parents('li').first().find('ul input[type="checkbox"]').attr('checked', thischecked);
    if (thischecked) {
      //$(this).parents('div.form-item').first().removeClass('mp-filter-cb-disable');
      $(this).parents('li').first().find('ul').slideDown();
    }
    else {
      $(this).parents('li').first().find('ul:not(:has("input:checked"))').slideUp();
    }
    /*
    $parent_cb = $(this)
      .parents('ul').first()
      .parents('li').first()
      .find('> div.form-item input[type="checkbox"]');
    $children_cb = $parent_cb.parents('li').first().find('ul input[type="checkbox"]');
    all_checked = ($children_cb.length == $children_cb.filter(':checked').length);
    some_checked = $children_cb.filter(':checked').length > 0 ? true : false;
    $parent_cb.attr('checked', all_checked);
    $parent_cb.parents('div.form-item').first().toggleClass('mp-filter-cb-disable', some_checked && !all_checked);
    */
   
    $.uniform.update();
    
    $(this).parents('form').find('input[type="submit"].ctools-use-ajax').click();
    $('.view-library .view-content, .view-Playlists .view-content').replaceWith('<div>Please wait...</div>');
    
  }
  Drupal.behaviors.ZZmusiclibrary_playlist_filters = {
    attach: function(context) {
      $forms = $('#views-exposed-form-library-library, #views-exposed-form-Playlists-playlists');
      $forms.find('ul li:not(.musiclibrary-playlist-processed)').each(function() {
        $(this).addClass('musiclibrary-playlist-processed')
          .not(':has(input:checked)')
          .find('ul')
          .hide();
        // $(this).has('ul').addClass('mp-filter-parent').has('input:checked').find('div.form-item').first().addClass('mp-filter-cb-disable');
      });
        
      $forms.find('input[type="checkbox"]:not(.musiclibrary-playlist-uniform)').uniform().addClass('musiclibrary-playlist-uniform');
      $forms.find('input[type="checkbox"]').change(Drupal.musiclibrary_playlist.filters.cb_onchange);
      $forms.find('fieldset:has(:checked)').removeClass('collapsed');
    }
  }
})(jQuery);
