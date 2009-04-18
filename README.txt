DESCRIPTION
***************************************************************************
Highslide module implements Highslide JS, an open source image, media and 
gallery viewer written in JavaScript.

It uses imagefields and imagecache to set up various custom formatters, and
can also, using AJAX, load other sections of your site inside a highslide.

AJAX EXAMPLE
***************************************************************************
$options = array();
$options['attributes'] = array('class' => 'highslide-ajax-link');
$options['fragment'] = 'node-1';
print l(t('Click me'), 'node/1', $options);

This would load the contents of node/1 into the current page in a highslide
view.

NOTE: AJAX usage is highly dependent on markup, so keep that in mind when 
programming.