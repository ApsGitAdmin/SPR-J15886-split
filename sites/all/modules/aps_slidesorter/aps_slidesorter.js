(function($) {
  Drupal.aps_pageexit = {};
  var time = false;

  Drupal.behaviors.apsPageExit = {
    attach : function(context) {
      // Catch all links and buttons EXCEPT for "#" links
      //$("a, button, input[type='submit']:not(.node-edit-protection-processed)")
      $("a, button, input[type='submit']").each(function() {
        $(this).click(function() {
          // return when a "#" link is clicked so as to skip the
          // window.onbeforeunload function
          if ($(this).attr("href") != "#") {
            return 0;
          }
        });
      });

      // Handle backbutton, exit etc.
      window.onbeforeunload = function() {
        if (!Drupal.settings.page_exit.begin && !Drupal.settings.page_exit.end) {
          var begin = Date.parse(Drupal.settings.page_exit.start_time);
          var end = Date.parse(Drupal.settings.page_exit.end_time);

          var dt = new Date();
          var now = Date.today().set({ hour: dt.getHours(), minute: dt.getMinutes(), seconds: dt.getSeconds()});

          if (now > begin && end > now) {
            time = true;
          }
        }
        if (time) {
          return (Drupal.t("This webcast has not ended yet."));
        }
      }

      window.onunload = function () {
        $.ajax({
          type: 'POST',
          async: false,
          url: Drupal.settings.basePath + 'aps_pageexit/timeout',
          dataType: 'json',
          data: 'js=1'
        });
      }
    }
  };
})(jQuery);