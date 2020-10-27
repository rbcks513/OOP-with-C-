// "Copyright [2020] <Copyright rbcks513>"
#include <iostream>
#include <vector>


class Node {
 public:
  explicit Node(int value) : value_(value), left_(NULL), right_(NULL) {}
  //  Deep copy to Node
  Node(const Node& node) :
    value_(node.value_), left_(node.left_), right_(node.right_) {}
  ~Node() {
    // delete recursive
    delete left_;
    delete right_;
  }
  //  Add left child to this node
  void operator<<=(Node* node) {
  //  if already have child node
    if (this->left_ != NULL) {
      left_ = new Node(*node);
      delete node;
    } else {
      left_ = new Node(*node);
      delete node;
    }
  }
  //  Add right child to Node
  void operator>>=(Node* node) {
    if (this->right_ != NULL) {
      right_ = new Node(*node);
      delete node;
    } else {
      right_ = new Node(*node);
      delete node;
    }
  }
  int value() {
    if (this == NULL) return NULL;
    return value_;
  }
  Node* left() { return left_; }
  Node* right() { return right_; }
  const Node* left() const {
    return left_;
  }
  const Node* right() const {
    return right_;
  }

 private:
  const int value_;
  Node* left_;
  Node* right_;
};
class TreeUtil {
 public:
  // instance generate
  static TreeUtil* GetTreeUtil() {
    if (s_tree_util_ == NULL) {
      s_tree_util_ = new TreeUtil;
    }
    return s_tree_util_;
  }
  int CalcHeight(const Node* node) {
    if (node->left() == NULL && node->right() == NULL) return 0;
    if (node->left() != NULL) {
      if (node->right() != NULL) {
        if (CalcHeight(node->right()) > CalcHeight(node->left())) {
          return CalcHeight(node->right()) + 1;
        } else {
          return CalcHeight(node->left()) + 1;
        }
      } else {
        return CalcHeight(node->left()) + 1;
      }
    } else {
      return CalcHeight(node->right()) + 1;
    }
  }
  int CalcTotalNumOfNode(const Node* node) {
    if (node->left() == NULL && node->right() == NULL) return 1;
    if (node->left() != NULL) {
      if (node->right() != NULL) {
         return CalcTotalNumOfNode(node->left()) +
                CalcTotalNumOfNode(node->right()) + 1;
      } else {
        return CalcTotalNumOfNode(node->left()) + 1;
      }
    } else {
      return CalcTotalNumOfNode(node->right());
    }
  }
  std::vector<const Node*> GetLeaves(const Node* node) {
    std::vector<const Node*> leaves;
    if (node->left() == NULL && node->right() == NULL) {
      //  this node is leaf
      leaves.push_back(node);
      return leaves;
    }
    if (node->left() != NULL) {
      if (node->right() != NULL) {
        //  add leaves
        leaves.insert(leaves.end(), GetLeaves(node->left()).begin(),
                      GetLeaves(node->left()).end());
        leaves.insert(leaves.end(), GetLeaves(node->right()).begin(),
                      GetLeaves(node->right()).end());
        return leaves;
      } else {
        //  Node already had child is not leaf
        return GetLeaves(node->left());
      }
    } else {
      //  Node already had child is not leaf
      return GetLeaves(node->right());
    }
  }
  bool IsFullBinaryTree(const Node* node) {
    if (node->left() == NULL && node->right() == NULL) return true;
    if (node->left() == NULL && node->right() != NULL) return false;
    if (node->left() != NULL && node->right() == NULL) return false;
    if (node->left() != NULL && node->right() != NULL) {
      if (IsFullBinaryTree(node->left()) && IsFullBinaryTree(node->right())) {
      return true;
      }
    }
  }

 private:
  static TreeUtil* s_tree_util_;
  //  TreeUtil instance
};
TreeUtil* TreeUtil::s_tree_util_ = NULL;

int main() {
  Node* root = new Node(0);
  Node* one = new Node(1);
  Node* two = new Node(2);
  Node* three = new Node(3);
  Node* four = new Node(4);
  Node* five = new Node(5);
  Node* six = new Node(6);
  Node* seven = new Node(7);
  Node* eight = new Node(8);
  Node* nine = new Node(9);
  TreeUtil* trU = TreeUtil::GetTreeUtil();
  *root <<= one;
  *root <<= two;
  *root >>= three;
  *root->left() <<= four;
  *root->left() >>= five;
  *root->right() <<= six;
  *root->right() >>= seven;
  *root->left()->left() <<= eight;
  *root->left()->left() >>= nine;
  std::cout << root->value() << std::endl;
  std::cout << root->left()->value() << std::endl;
  std::cout << root->right()->value() << std::endl;
  std::cout << trU->CalcHeight(root) << std::endl;
  std::cout << trU->CalcTotalNumOfNode(root) << std::endl;
  std::cout << trU->IsFullBinaryTree(root) << std::endl;
}
