/**
 * @file
 * 
 * CTools AJAX Responder for inline form.
 */
(function ($) {
  Drupal.musiclibrary_playlist = Drupal.musiclibrary_playlist || {};
  Drupal.musiclibrary_playlist.inline = {};
  Drupal.musiclibrary_playlist.inline.active_elements = [];

  Drupal.musiclibrary_playlist.inline.submitAjaxForm = function(e) {
    var url = $(this).attr('action');
    var form = $(this);
    
    setTimeout(function() { Drupal.CTools.AJAX.ajaxSubmit(form, url); }, 1);
    return false;
  };
  
  /**
   * AJAX command to dismiss BeautyTip.
   */
  Drupal.musiclibrary_playlist.inline.musiclibrary_playlist_inline_dismiss = function(ajax, response, status) {
    $('.musiclibrary-playlist-inline-active').removeClass('musiclibrary-playlist-inline-active').btOff();
  };

  /**
   * AJAX command to place HTML within a BeautyTip.
   */
  Drupal.musiclibrary_playlist.inline.musiclibrary_playlist_inline_display = function(ajax, response, status) {
    $('.musiclibrary-playlist-inline-active').removeClass('musiclibrary-playlist-inline-active').btOff();
    var settings = {};
    settings = Drupal.settings.musiclibrary_playlist_inline;
    settings.trigger = 'none';
    $active_element = $(ajax.element);
    $active_element.bt(response.data, Drupal.settings.musiclibrary_playlist_inline).btOn().addClass('musiclibrary-playlist-inline-active');
    Drupal.attachBehaviors();    
  }
  
  /**
   * AJAX command to copy one element and append it to another.
   */
  Drupal.musiclibrary_playlist.inline.musiclibrary_playlist_copy_to = function(ajax, response, status) {
    $element = $(response.selector).clone();
    $element.addClass(response.add_classes);
    $element.removeClass(response.remove_classes);
    $element.find(response.link_selector).attr('href', response.link_href).removeClass('musiclibrary-playlist-inline-processed');
    $element.find(response.remove_link_selector).attr('href', response.remove_link_href).removeClass('musiclibrary-playlist-inline-processed');
    $(response.destination).append($element);
    Drupal.attachBehaviors();
    $('.sm2-360ui').remove();
    $('a.sm2_link').each(function() {
      $(this).attr('href', $(this).attr('href') + Math.random());
    })
    threeSixtyPlayer.init(soundManager);
  }


  /**
   * AJAX command to add an empty Playlist to the view.
   */
  Drupal.musiclibrary_playlist.inline.musiclibrary_playlist_add_new_playlist = function(ajax, response, status) {
    var $empty_table = $(response.view_html).find('.playlist-wrap');
    $('.musiclibrary-playlist-playlists-view .view-content').prepend($empty_table);
    Drupal.attachBehaviors($empty_table);
    $('.sm2-360ui').remove();
    $('a.sm2_link').each(function() {
      $(this).attr('href', $(this).attr('href') + Math.random());
    })
    threeSixtyPlayer.init(soundManager);
  }
  
  // Define our custom AJAX commands.
  $(function() {
    Drupal.ajax.prototype.commands.musiclibrary_playlist_inline_display   = Drupal.musiclibrary_playlist.inline.musiclibrary_playlist_inline_display;
    Drupal.ajax.prototype.commands.musiclibrary_playlist_inline_dismiss   = Drupal.musiclibrary_playlist.inline.musiclibrary_playlist_inline_dismiss;
    Drupal.ajax.prototype.commands.musiclibrary_playlist_copy_to          = Drupal.musiclibrary_playlist.inline.musiclibrary_playlist_copy_to;
    Drupal.ajax.prototype.commands.musiclibrary_playlist_add_new_playlist = Drupal.musiclibrary_playlist.inline.musiclibrary_playlist_add_new_playlist;
  });
 
  /**
   * Define our Drupal behaviors.
   */
  Drupal.behaviors.musiclibrary_playlist_inline = {
    attach: function(context) {
      $('a.musiclibrary-playlist-inline:not(.musiclibrary-playlist-inline-processed)', context)
        .addClass('musiclibrary-playlist-inline-processed')
        // .click(Drupal.musiclibrary_playlist.inline.musiclibrary_playlist_inline_display)
        .each(function () {
          // Create a drupal ajax object
          var element_settings = {};
          if ($(this).attr('href')) {
            element_settings.url = $(this).attr('href');
            element_settings.event = 'click';
            element_settings.progress = { type: 'throbber' };
          }
          var base = $(this).attr('href');
          Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);

          // Attach the display behavior to the ajax object
        }
      );

      // Bind our custom event to the form submit
      $('.bt-content form:not(.musiclibrary-playlist-inline-processed)', context)
        .addClass('musiclibrary-playlist-inline-processed')
        .each(function() {
          var element_settings = {};
          element_settings.url = $(this).attr('action');
          element_settings.event = 'submit';
          element_settings.progress = { 'type': 'throbber' }
          var base = $(this).attr('id');

          Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
          Drupal.ajax[base].form = $(this);

          $('input[type=submit], button', this).click(function() {
            Drupal.ajax[base].element = this;
            this.form.clk = this;
          });
        });
        
        /*
        $('.musiclibrary-playlist-playlists-view table:not(.musiclibrary-playlist-inline-processed)', context)
          .addClass('musiclibrary-playlist-inline-processed')
          .each(function() {
            

            // Hide rows in tables with no tracks.
            $table.filter('.musiclibrary-playlist-row-track-').find('tbody tr').hide();
          });
        */  

    }
  };
  

  
})(jQuery);

