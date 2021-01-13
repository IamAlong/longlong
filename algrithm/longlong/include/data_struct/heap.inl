#ifndef _HEAP_INL_
#define _HEAP_INL_

#include <vector>
#include <utility>
#include "handler.h"
#include "util.hpp"

#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)
#define PARENT(i) (i / 2)

namespace ll {

namespace algorithm {
  template<typename Type>
  Heap<Type>::Heap() {}

  template<typename Type>
  Heap<Type>::Heap(Type* begin, Type* end, size_t heap_size, cmp2<Type> c) {
    build_heap(begin, end, heap_size, c);
  }

  template<typename Type>
  void Heap<Type>::build_heap(Type* begin, Type* end, size_t heap_size, cmp2<Type> c) {
    this->heap_size = heap_size;
    this->c = c;
    datas.resize(heap_size + 1);
    Type* start = begin;
    for (int i = 1; i < datas.size(); ++i) {
      datas[i] = *start++;
    }
    build_heap();
  }

  template<typename Type>
  std::pair<Type, bool> Heap<Type>::top() {
    if (heap_size > 0) {
      return std::make_pair<Type, bool>(datas[1], true);
    }
    return std::make_pair<Type, bool>(Type(), false);
  }

  template<typename Type>
  bool Heap<Type>::pop() {
    if (heap_size == 0) {
      return false;
    }
    swap(datas[1], datas[heap_size]);
    --heap_size;
    protect_heap(1);
    return true;
  }

  template<typename Type>
  void Heap<Type>::insert(Type data) {
    if (datas.size() - 1 > heap_size) {
      datas[++heap_size] = data;
    } else {
      datas.push_back(data);
      ++heap_size;
    }
    int i = heap_size;
    while (i > 1) {
      if (c(datas[i], datas[PARENT(i)])) {
        swap(datas[PARENT(i)], datas[i]);
        i = PARENT(i);
      } else {
        break;
      }
    }
  }

  template<typename Type>
  size_t Heap<Type>::size() {
    return heap_size;
  }

  template<typename Type>
  void Heap<Type>::build_heap() {
    for (int i = heap_size / 2; i > 0; --i) {
      protect_heap(i);
    }
  }

  template<typename Type>
  void Heap<Type>::protect_heap(int i) {
    while (i <= heap_size / 2) {
      size_t best_idx = i;
      Type best_val = datas[i];
      if (LEFT(i) <= heap_size && c(datas[LEFT(i)], best_val)) {
        best_idx = LEFT(i);
        best_val = datas[LEFT(i)];
      }
      if (RIGHT(i) <= heap_size && c(datas[RIGHT(i)], best_val)) {
        best_idx = RIGHT(i);
      }
      if (best_idx != i) {
        swap(datas[i], datas[best_idx]);
        i = best_idx;
      } else {
        break;
      }
    }
  }
}

}

#endif
