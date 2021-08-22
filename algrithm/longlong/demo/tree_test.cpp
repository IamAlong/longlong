#include "head.h"
#include "data_struct/binary_tree.hpp"

using namespace ll::algorithm;

int main() {
  BinaryTreeInterview b;
  Ivec pre_order = b.pre_order_rec();
  pre_order.show();

  Ivec in_order = b.in_order_rec();
  in_order.show();

  Ivec post_order = b.post_order_rec();
  post_order.show();

  Ivec level_order = b.level_order_rec();
  level_order.show();

  size_t node_cnt = b.count_nodes();
  Println(node_cnt);

  size_t leaves_cnt = b.count_leaves();
  Println(leaves_cnt);

  size_t depth = b.get_depth();
  Println(depth);

  size_t klevel_cnt = b.count_klevel_nodes(2);
  Println(klevel_cnt);

  BinaryTreeInterview b2;
  bool cmp = b.struct_cmp(b2);
  Println(cmp);

  b2.mirror();
  Ivec pre_order_b2 = b2.pre_order_rec();
  pre_order_b2.show();
  
  return 0;
}