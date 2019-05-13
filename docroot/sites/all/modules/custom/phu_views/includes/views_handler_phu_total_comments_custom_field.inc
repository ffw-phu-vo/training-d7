<?php
/**
 * @file
 * Custom views handler definition.
 *
 * Place this code in
 * /sites/all/[custom_module_name]/includes/views_handler_my_custom_field.inc
 */

/**
 * Custom handler class.
 *
 * @ingroup views_field_handlers
 */
class views_handler_phu_total_comments_custom_field extends views_handler_field {

  /**
   * {@inheritdoc}
   *
   * Perform any database or cache data retrieval here. In this example there is
   * none.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * {@inheritdoc}
   *
   * Modify any end user views settings here. Debug $options to view the field
   * settings you can change.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['phu_test_checkbox_custom'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

  /**
   * {@inheritdoc}
   *
   * Make changes to the field settings form seen by the end user when adding
   * your field.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['phu_test_checkbox_custom'] = array(
      '#title' => t('Phu test checkbox custom'),
      '#description' => t('Description test checkbox custom'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['phu_test_checkbox_custom'],
    );
  }

  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    if ($this->options['phu_test_checkbox_custom'] == TRUE) {
      return t('Test checkbox');
    }
    else {
      // dsm($this->options['phu_test_checkbox_custom']);
      // dsm($values);
      $nid = $values->nid;
      $result = db_select('comment', 'c')
      ->fields('c', array('nid'))
      ->condition('c.nid', $nid, '=')
      ->countQuery()
      ->execute()
      ->fetchField();
      // dsm($result);
      return t( $result . ' comments');
    }
  }
}
