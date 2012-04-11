<?php

/**
 * @file
 * Field handler to display all taxonomy terms of a node.
 */
class musiclibrary_playlist_views_handler_field_term_node_tid extends views_handler_field_term_node_tid {
  function init(&$view, &$options) {
    parent::init($view, $options); 
  }

  function pre_render(&$values) {
    $this->field_alias = $this->aliases['nid'];
    $nids = array();
    foreach ($values as $result) {
      if (!empty($result->{$this->aliases['nid']})) {
        $nids[] = $result->{$this->aliases['nid']};
      }
    }

    if ($nids) {
      $query = db_select('taxonomy_term_data', 'td');
      $query->innerJoin('taxonomy_index', 'tn', 'td.tid = tn.tid');
      $query->innerJoin('taxonomy_vocabulary', 'tv', 'td.vid = tv.vid');
      $query->leftJoin('taxonomy_term_hierarchy', 'th', 'th.tid = td.tid');
      $query->leftJoin('taxonomy_term_data', 'tdp', 'th.parent = tdp.tid');
      $query->fields('td');
      $query->addField('tn', 'nid', 'node_nid');
      $query->addField('tv', 'name', 'vocabulary');
      $query->addField('tv', 'machine_name', 'vocabulary_machine_name');
      $query->addField('tdp', 'name', 'parent');
      $query->addExpression('COALESCE(tdp.name, td.name)', 'sortby1');
      $query->addExpression('ISNULL(tdp.name)', 'sortby2');
      $query->orderBy('sortby1');
      $query->orderBy('sortby2', 'DESC');
      $query->orderby('td.weight');
      $query->orderby('td.name');
      $query->condition('tn.nid', $nids);
      $query->addTag('term_access');
      $vocabs = array_filter($this->options['vocabularies']);
      if (!empty($this->options['limit']) && !empty($vocabs)) {
        $query->condition('tv.machine_name', $vocabs);
      }
      $result = $query->execute();

      foreach ($result as $term) {
        $this->items[$term->node_nid][$term->tid]['name'] = check_plain($term->name);
        if (!empty($term->parent)) {
          $this->items[$term->node_nid][$term->tid]['name'] = check_plain($term->parent) . ' > ' . $this->items[$term->node_nid][$term->tid]['name'];
        }
        $this->items[$term->node_nid][$term->tid]['tid'] = $term->tid;
        $this->items[$term->node_nid][$term->tid]['vocabulary_machine_name'] = check_plain($term->vocabulary_machine_name);
        $this->items[$term->node_nid][$term->tid]['vocabulary'] = check_plain($term->vocabulary);

        if (!empty($this->options['link_to_taxonomy'])) {
          $this->items[$term->node_nid][$term->tid]['make_link'] = TRUE;
          $this->items[$term->node_nid][$term->tid]['path'] = 'taxonomy/term/' . $term->tid;
        }
      }
    }
  }
}

