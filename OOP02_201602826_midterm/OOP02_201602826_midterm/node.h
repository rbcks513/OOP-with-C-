#pragma once
#ifndef MIDTERM_SOLUTION_SRCS_NODE_H_
#define MIDTERM_SOLUTION_SRCS_NODE_H_
#include <string >

#include "value.h"
class Node {
 public:
  explicit Node(Value* value);
  Node* left() const;
  Node* right() const;
  const Value& value() const;
  void AddLeft(Node* left);
  void AddRight(Node* right);
  bool operator<=(const Node& node) const;
  std ::string ToString() const;

 private:
  const Value* value_;
  Node* left_;
  Node* right_;
};
#endif  // MIDTERM_SOLUTION_SRCS_NODE_H_