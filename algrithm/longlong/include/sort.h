#ifndef _SORT_H_
#define _SORT_H_

#include "handler.h"
#include "data_struct/heap.h"

namespace ll {

namespace algorithm {

class SortInterface {
 public:
  virtual void sort(int* start, int* end, cmp c = std::less<int>()) = 0;
};

class InsertionSort : public SortInterface {
 public:
  void sort(int* start, int* end, cmp c = std::less<int>()) override;
};

class MergeSort : public SortInterface {
 public:
  void sort(int* start, int* end, cmp c = std::less<int>()) override;
};

class SelectSort : public SortInterface {
 public:
  void sort(int* start, int* end, cmp c = std::less<int>()) override;
};

class BubbleSort : public SortInterface {
 public:
  void sort(int* start, int* end, cmp c = std::less<int>()) override;
};

class HeapSort : public SortInterface, public Heap<int> {
  public:
   void sort(int *start, int* end, cmp c = std::less<int>()) override;
};

} // namespace sort

} // namespace ll

#endif