<?php
/**
 * @file
 * mc_front_page_post_setup.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mc_front_page_post_setup_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function mc_front_page_post_setup_image_default_styles() {
  $styles = array();

  // Exported image style: flexslider_full.
  $styles['flexslider_full'] = array(
    'effects' => array(
      0 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 500,
        ),
        'weight' => 0,
      ),
    ),
    'name' => 'flexslider_full',
    'label' => 'flexslider_full',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function mc_front_page_post_setup_node_info() {
  $items = array(
    'front_page_post' => array(
      'name' => t('Front Page Post'),
      'base' => 'node_content',
      'description' => t('Create a front page post. To add it to the front page carousel or in the list below.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
