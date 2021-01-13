#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include <vector>
#include <utility>
#include "handler.h"
// using namespace ll::algorithm;
namespace ll {

namespace algorithm {

template<typename Type>
class Heap {
 public:
  Heap();
  Heap(Type* begin, Type* end, size_t heap_szie, cmp2<Type> c = std::less<Type>());
  void build_heap(Type* begin, Type* end, size_t heap_szie, cmp2<Type> c = std::less<Type>());
  std::pair<Type, bool> top();
  bool pop();
  void insert(Type data);
  size_t size();

 protected:
  void protect_heap(int i);
  std::vector<Type> datas;
  size_t heap_size;
  cmp2<Type> c;

 private:
  void build_heap();
};

}

}

#include "heap.inl"

#endif