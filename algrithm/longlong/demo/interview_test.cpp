#include <vector>
#include <iostream>
#include "interview.h"

using namespace ll::algrithm;

void test_get_maximum() {
  int a[16] = { 1, 2, 3, -4, -1, -3, -5, 6, -10, 1, 12, -3, -5, 10, 7, 8 };
  std::vector<int> nums { a, a+16 };
  MaximumSubarray ms { nums };
  auto res = ms.get_maximum(0, 15);
  std::cout << res.to_string() << std::endl;
  res = ms.get_maximum_v2();
  std::cout << res.to_string() << std::endl;
}

int main() {
  test_get_maximum();
  return 0;
}