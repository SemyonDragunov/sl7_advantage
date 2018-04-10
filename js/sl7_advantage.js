(function ($, Drupal, window, document, undefined) {
    $(function () {

        var $window = $(window),
            sections = $('.sl7-advantage-service-section'),
            mobileWidth = 767;

        function winWidth() {
            var winWidthVal = $window.width();
            return winWidthVal;
        }
        $window.resize(winWidth);

        if (mobileWidth < winWidth()) {
            setTimeout(function() {
                    sections.each(function(i, e) {
                        var sectionHeight = 0,
                            sectionItem = $(e).find('.item');

                        sectionItem.each(function (i, e) {
                            var eHeight = $(e).outerHeight();
                            sectionHeight = eHeight > sectionHeight ? eHeight : sectionHeight;
                        });

                        sectionItem.height(sectionHeight);
                    });
                }
                , 500);
        }

    });
})(jQuery, Drupal, this, this.document);