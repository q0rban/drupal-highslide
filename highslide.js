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
    $('a#highslide-login-link').click(function() {
      return hs.htmlExpand(this, { 
          contentId: 'highslide-login', 
          anchor: 'auto', 
          outlineType: 'rounded-white', 
          outlineWhileAnimating: true 
        }
      );
    });
    $('a.highslide-ajax-link').each(function() {
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
    $('a.highslide-ajax-link-wide').each(function() {
      this.onclick = function() {
        return hs.htmlExpand(this, { 
            minHeight: 500,
            objectType: 'ajax',
            outlineType: 'rounded-white', 
            outlineWhileAnimating: true,
            width: 600
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
    hs.expandDuration = 350;
    hs.marginLeft = 35;
    hs.marginRight = 35;
    hs.marginTop = 35;
    hs.marginBottom = 65;
    hs.numberOfImagesToPreload = 3;
    hs.captionSlideSpeed = 0;
    hs.spaceForCaption = 60;
    hs.easing = 'easeOutQuad';
    hs.easingClose = 'easeInQuad';
    hs.fadeInOut = true;
    hs.restoreCursor = 'restore.png';

    hs.registerOverlay({thumbnailId: null, position: 'top left', overlayId: 'closebutton', fade: 2});

  });