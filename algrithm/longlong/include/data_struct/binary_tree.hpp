#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_

#include "base.h"

namespace ll {

namespace algorithm {

template<typename Type>
struct BinaryNodeBase {
  BinaryNodeBase()
    : left { nullptr },
      right { nullptr } {}

  virtual ~BinaryNodeBase() {}
  BinaryNodeBase<Type>* left;
  BinaryNodeBase<Type>* right;
};

template<typename Type>
class BinaryTreeBase {
 public:
  BinaryTreeBase()
    : head { nullptr } {}
  
  virtual ~BinaryTreeBase() {
    destory_node(reinterpret_cast<BinaryNodeBase<Type>*>(head));
    head = nullptr;
  }

 protected:
  inline void destory_node(BinaryNodeBase<Type>* node) {
    if (node) {
      destory_node(node->left);
      destory_node(node->right);
      delete node;
    }
  }

  BinaryNodeBase<Type>* head;
};

struct BinaryNodeInterview : public BinaryNodeBase<int> {
  BinaryNodeInterview(int d)
    : data { d } {}
  ~BinaryNodeInterview() = default;
  int data;
};

class BinaryTreeInterview : public BinaryTreeBase<int> {
 public:
  BinaryTreeInterview() {
    build_tree();
  }

  virtual ~BinaryTreeInterview() {
  }

  Ivec pre_order_rec() {
    Ivec res;
    pre_order_rec_inl(reinterpret_cast<BinaryNodeInterview*>(head), res);
    return res;
  }

  Ivec in_order_rec() {
    Ivec res;
    in_order_rec_inl(reinterpret_cast<BinaryNodeInterview*>(head), res);
    return res;
  }

  Ivec post_order_rec() {
    Ivec res;
    post_order_rec_inl(reinterpret_cast<BinaryNodeInterview*>(head), res);
    return res;
  }

 private:
  inline void post_order_rec_inl(BinaryNodeInterview* node, Ivec& res) const {
    if (node) {
      post_order_rec_inl(dynamic_cast<BinaryNodeInterview*>(node->left), res);
      post_order_rec_inl(dynamic_cast<BinaryNodeInterview*>(node->right), res);
      res.push_back(node->data);
    }
  }

  inline void in_order_rec_inl(BinaryNodeInterview* node, Ivec& res) const {
    if (node) {
      in_order_rec_inl(dynamic_cast<BinaryNodeInterview*>(node->left), res);
      res.push_back(node->data);
      in_order_rec_inl(dynamic_cast<BinaryNodeInterview*>(node->right), res);
    }
  }

  inline void pre_order_rec_inl(BinaryNodeInterview* node, Ivec& res) const {
    if (node) {
      res.push_back(node->data);
      pre_order_rec_inl(dynamic_cast<BinaryNodeInterview*>(node->left), res);
      pre_order_rec_inl(dynamic_cast<BinaryNodeInterview*>(node->right), res);
    }
  }
  
  /** build a tree for test
   *        1
   *    2       3
   *  4       5
   *    6
   *      7
   */
  inline void build_tree() {
    head = new BinaryNodeInterview(1);
    head->left = new BinaryNodeInterview(2);
    head->right = new BinaryNodeInterview(3);
    head->left->left = new BinaryNodeInterview(4);
    head->right->left = new BinaryNodeInterview(5);
    head->left->left->right = new BinaryNodeInterview(6);
    head->left->left->right->right = new BinaryNodeInterview(7);
  }
};

}

}

#endif