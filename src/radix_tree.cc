#include "./radix_tree.h"
#include <iostream>
#include <cmath>

RadixTree::RadixTree(): root_node_(new Node("/")) { }

RadixTree::~RadixTree() {}

bool RadixTree::Lookup(std::string s) {
  Node* current_node = root_node_;
  unsigned int parent_node_prefix_len = current_node->prefix.length();
  auto path_len = s.length();

  while (true) {
    if (parent_node_prefix_len == path_len) {
      return true;
    }

    auto node = current_node->NextNode(s, parent_node_prefix_len);
    if (node == nullptr) {
      return false;
    }

    current_node = node;
    if (current_node->wildcard_child != nullptr) {
      parent_node_prefix_len = path_len;
    } else {
      parent_node_prefix_len += current_node->prefix.length();
    }
  }
}

void RadixTree::Insert(std::string path) {
  Node* current_node = root_node_;

  unsigned int parent_node_prefix_len = current_node->prefix.length();
  int path_len = path.length();

  for (int i = 0; i < path_len; ++i) {
    bool is_wildcard_node = path[i] == '*';
    bool is_last_char = i + 1 == path_len;

    if (is_wildcard_node || is_last_char) {
      std::string node_path = path.substr(parent_node_prefix_len, i);

      current_node = current_node->CreateChild(node_path);
    }

    if (is_wildcard_node) {
      current_node = current_node->CreateWildcardChild();
      parent_node_prefix_len = i + i;
    }
  }
}
