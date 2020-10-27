#pragma once
#ifndef MIDTERM_SOLUTION_SRCS_TREEUTIL_H_
#define MIDTERM_SOLUTION_SRCS_TREEUTIL_H_
#include <algorithm >
#include <iostream >
#include <vector >

#include "node.h"
class TreeUtil {
 public:
  static TreeUtil* GetInstance();
  Node* Balance(Node* node);
  bool IsBinarySearchTree(const Node* node);
  int CalcHeight(const Node* node);

 private:
  static TreeUtil* instance_;
  TreeUtil() {}
};
#endif  // MIDTERM_SOLUTION_SRCS_TREEUTIL_H_