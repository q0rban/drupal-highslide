$(function () {
  $('a.highslide').each(function() {
    this.onclick = function() {
      return hs.expand(this);
    }
  });
  $('a.highslide-html-link').click(function() {
    var href = $(this).attr('href');
    href = href.substr(1, href.length - 1);
    return hs.htmlExpand(this, { 
        contentId: href,
        anchor: 'auto',
        outlineType: 'rounded-white',
        outlineWhileAnimating: true
      }
    );
  });
  $('a.highslide-ajax-link, a.highslide-ajax-link-wide').each(function() {
    this.onclick = function () {
      return hs.htmlExpand(this, {
          minHeight: 500,
          objectType: 'ajax',
          outlineType: 'rounded-white', 
          outlineWhileAnimating: true,
          preserveContent: true
        }
      );
    }
  });
  $('.highslide-close').each(function() {
    this.onclick = function() {
      return hs.close(this);
    }
  });

  var settings = Drupal.settings.highslide.options;

  hs.graphicsDir = settings.graphicsDir;
  hs.align = settings.align;
  hs.outlineType = settings.outlineType;
  hs.dimmingOpacity = settings.dimmingOpacity;
  hs.dimmingDuration = settings.dimmingDuration;
  hs.lang.loadingText = '<img src="' + settings.graphicsDir + 'sprocket-loader.gif" alt="" />';

  hs.showCredits = false;
  hs.expandDuration = 300;
  hs.marginLeft = 35;
  hs.marginRight = 35;
  hs.marginTop = 30;
  hs.marginBottom = 20;
  hs.numberOfImagesToPreload = 5;
  hs.captionSlideSpeed = 0;
  hs.spaceForCaption = 60;
  hs.easing = 'easeOutQuad';
  hs.easingClose = 'easeInQuad';
  hs.fadeInOut = true;
  hs.restoreCursor = 'restore.png';

  hs.registerOverlay({
  	overlayId: 'closebutton',
  	position: 'top left',
  	fade: 2, 
  	useOnHtml: true
	});
});