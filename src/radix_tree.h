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
    children[label] = new Node(prefix);
    return children[label];
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
