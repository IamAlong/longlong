#include <functional>

namespace ll {

namespace algrithm {

using cmp = std::function<bool(int, int)>;
template<typename Type>
using cmp2 = std::function<bool(Type, Type)>;

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

} // namespace sort

} // namespace ll
