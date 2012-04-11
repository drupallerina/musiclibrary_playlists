(function ($) {
  Drupal.acq_monitorpop = Drupal.acq_monitorpop || {};
  Drupal.acq_monitorpop.playlists = Drupal.acq_monitorpop.playlists || {};
  Drupal.acq_monitorpop.playlists.header_click = function() {
    $(this).toggleClass('collapsed');
    if ($(this).hasClass('collapsed')) {
      $(this).parents('.playlist-header').next('div.playlist-table-wrap').slideUp('fast');
    }
    else {
      $(this).parents('.playlist-header').next('div.playlist-table-wrap').slideDown('fast');
    }
    return false;
  }
  
  Drupal.behaviors.acq_monitorpop = {
    attach: function(context) {
        
      $('div.playlist-header h2.playlist-title a')
        .not('.collapse-processed')
        .addClass('collapse-processed')
        .click(Drupal.acq_monitorpop.playlists.header_click);
    }
  }
})(jQuery);
