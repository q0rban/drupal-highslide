<a href="<?php print url('user/login'); ?>" id="highslide-login-link"><?php print t('Login'); ?></a>
<?php if ($user_access): ?>
<div class="highslide-html-content" id="highslide-login">
  <div class="highslide-header">
    <ul>
      <li class="highslide-move"><a href="javascript:;"><?php print t('Move'); ?></a></li>
      <li class="highslide-close"><a href="javascript:;"><?php print t('Close'); ?></a></li>
    </ul>
  </div> <!-- /.highslide-header -->
  <div class="highslide-body">
    <h3>Login to <?php print variable_get('site_name', 'Drupal'); ?></h3>
    <?php print drupal_get_form('user_login_block') ?>
  </div> <!-- /.highslide-body -->
</div> <!-- /#highslide-login -->
<?php endif; ?>