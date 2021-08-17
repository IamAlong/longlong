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
  return 0;
}