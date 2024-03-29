#ifndef _BASE_H_
#define _BASE_H_

#include <iostream>
#include <vector>

const size_t default_capacity = 1024;

class Ivec : public std::vector<int> {
 public:
  void show() {
    for (auto itr = begin(); itr != end(); itr++) {
      std::cout << *itr << " ";
    }
    std::cout << std::endl;
  }
};

#endif