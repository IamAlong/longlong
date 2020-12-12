#include <iostream>
#include "util.hpp"

using namespace ll::algrithm;

int main() {
  each<int> e = [](int& data){std::cout << data << " ";};
  int a[5] = {1, 2, 3, 4, 5};
  int b[5] = {1, 2, 3, 4, 5};
  int c[10];
  // Test merge
  merge<int>(a, 5, b, 5, c, [](int a, int b){return a < b;});

  // Test for_each
  for_each<int>(c, c + 10, e);
  std::cout << std::endl;

  // Test find
  std::cout << find<int>(c, 10, 2) << std::endl;
  return 0;
}