<?php

function features_profiler_get_components($type = 'supported', $feature = NULL) {
  $return = array();
  $profiler_components = array();
  $enabled_components = array_keys(features_get_components());
  sort($enabled_components);

  switch ($type) {
    case 'supported':
      return array_intersect($enabled_components, $profiler_components);
      break;
    case 'unsupported':
      return array_diff($enabled_components, $profiler_components);
      break;
  }
}

function features_profiler_scribbler() {
  $output = '<h2>Features Profiler</h2>';

  if ($unsupported = features_profiler_get_components('unsupported')) {
    drupal_set_message(
        t(
            'Features Profiler does not currently support the following enabled components:<br>!components',
            array('!components' => implode('<br>', $unsupported))
        ),
        'warning'
    );
  }

  foreach (features_profiler_get_components() as $component) {
    $output .= '<h4>'. $component . '</h4>';
  }
  return $output;
}

function features_profiler_form($form, $form_state, $feature = NULL) {
  $form = array();
  return $form;
}

function features_profiler_settings_form($form, $form_state, $feature = NULL) {
  $form = array();
  return $form;
}
