#ifndef RADIX_TREE_H
#define RADIX_TREE_H

#include <string>
#include <vector>
#include <map>

struct Node {
public:
  std::string prefix;
  std::map<char, Node*> children;
  Node* wildcard_child;

  Node(std::string pre) {
    prefix = pre;
  }

  Node() {
    wildcard_child = nullptr;
  }

  virtual Node* CreateChild(std::string prefix) {
    char label = prefix[0];

    Node* child = children[label];
    if (child == nullptr) {
      children[label] = new Node(prefix);
      return children[label];
    }

    int i = 0;
    int prefix_len = prefix.length();
    for (; i < child->prefix.length(); ++i) {
      if (i > prefix_len || prefix[i] != child->prefix[i]) {
        std::string parent_prefix = child->prefix.substr(0, i);
        std::string child_prefix = child->prefix.substr(i);

        child->prefix = child_prefix;
        Node* split_child = new Node(parent_prefix);
        split_child->children[child_prefix[0]] = child;
        children[parent_prefix[0]] = split_child;

        // create prefix child
        return split_child->CreateChild(prefix.substr(i));
      }
    }
    return child->CreateChild(prefix.substr(i));
  }

  virtual Node* CreateWildcardChild() {
    if (wildcard_child != nullptr) {
      return wildcard_child;
    }

    wildcard_child = new Node();
    return wildcard_child;
  }



  Node* NextNode(std::string path, int idx) {
    auto child = children[path[idx]];
    if (!child) {
      return wildcard_child;
    }
    return child;
  }
};

class RadixTree {
public:
  RadixTree();
  ~RadixTree();

  void Insert(std::string s);
  bool Lookup(std::string s);
private:
  Node* root_node_;
};

#endif
