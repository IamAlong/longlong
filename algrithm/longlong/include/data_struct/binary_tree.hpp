#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_

#include <queue>
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

  Ivec level_order_rec() {
    std::queue<BinaryNodeInterview*> q;
    Ivec res;
    if (!head) {
      return res;
    }
    q.push(reinterpret_cast<BinaryNodeInterview*>(head));
    while(!q.empty()) {
      auto node = q.front();
      res.push_back(node->data);
      if (node->left) {
        q.push(dynamic_cast<BinaryNodeInterview*>(node->left));
      }
      if (node->right) {
        q.push(dynamic_cast<BinaryNodeInterview*>(node->right));
      }
      q.pop();
    }
    return res;
  }

  size_t count_nodes() {
    return count_nodes_inl(reinterpret_cast<BinaryNodeInterview*>(head));
  }

  size_t count_leaves() {
    return count_leaves_inl(reinterpret_cast<BinaryNodeInterview*>(head));
  }

  size_t get_depth() {
    return get_depth_inl(reinterpret_cast<BinaryNodeInterview*>(head));
  }

  size_t count_klevel_nodes(size_t k) {
    return count_klevel_nodes_inl(reinterpret_cast<BinaryNodeInterview*>(head), k);
  }

  bool struct_cmp(const BinaryTreeInterview& rh) {
    return struct_cmp_inl(reinterpret_cast<BinaryNodeInterview*>(this->head), reinterpret_cast<BinaryNodeInterview*>(rh.head));
  }

  // 求树的镜像
  void mirror() {
    mirror_inl(reinterpret_cast<BinaryNodeInterview*>(head));
  }

 private:
  void mirror_inl(BinaryNodeInterview* node) {
    if (!node) {
      return;
    }

    auto tmp = node->left;
    node->left = node->right;
    node->right = tmp;

    mirror_inl(dynamic_cast<BinaryNodeInterview*>(node->left));
    mirror_inl(dynamic_cast<BinaryNodeInterview*>(node->right));
  }

  bool struct_cmp_inl(BinaryNodeInterview* lh_node, BinaryNodeInterview* rh_node) const {
    if (!lh_node && !rh_node) {
      return true;
    } else if (!lh_node || !rh_node) {
      return false;
    }

    return struct_cmp_inl(dynamic_cast<BinaryNodeInterview*>(lh_node->left), dynamic_cast<BinaryNodeInterview*>(rh_node->left))
        && struct_cmp_inl(dynamic_cast<BinaryNodeInterview*>(lh_node->right), dynamic_cast<BinaryNodeInterview*>(rh_node->right));
  }

  inline size_t count_klevel_nodes_inl(BinaryNodeInterview* node, size_t k) const {
    if (node && k == 1) {
      return 1;
    }
    return count_klevel_nodes_inl(dynamic_cast<BinaryNodeInterview*>(node->left), k - 1)
        + count_klevel_nodes_inl(dynamic_cast<BinaryNodeInterview*>(node->right), k - 1);
  }

  inline size_t get_depth_inl(BinaryNodeInterview* node) const {
    if (!node) {
      return 0;
    }
    return std::max(get_depth_inl(dynamic_cast<BinaryNodeInterview*>(node->left)), 
            get_depth_inl(dynamic_cast<BinaryNodeInterview*>(node->right))) + 1;
  }

  inline size_t count_leaves_inl(BinaryNodeInterview* node) const {
    if (!node) {
      return 0;
    }
    if (!node->left && !node->right) {
      return 1;
    }
    return count_leaves_inl(dynamic_cast<BinaryNodeInterview*>(node->left))
          + count_leaves_inl(dynamic_cast<BinaryNodeInterview*>(node->right));
  }

  inline size_t count_nodes_inl(BinaryNodeInterview* node) const {
    if (!node) {
      return 0;
    }
    return count_nodes_inl(dynamic_cast<BinaryNodeInterview*>(node->left))
          + count_nodes_inl(dynamic_cast<BinaryNodeInterview*>(node->right)) + 1;
  }

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