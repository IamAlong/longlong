/**
 *
 */
#include "sort.h"
#include "util.hpp"

using namespace ll::algrithm;

void InsertionSort::sort(int* start, int* end, cmp c) {
  int* cur = start + 1;
  for (; cur != end; cur++) {
    int num = *cur;
    int* tmp = cur;
    while (c(num, *(tmp - 1))) {
      *tmp = *(tmp - 1);
      --tmp;
    }
    *tmp = num;
  }
}

void MergeSort::sort(int* start, int* end, cmp c) {
  if (start < end - 1) {
    sort(start, start + (end - start) / 2, c);
    sort(start + (end - start) / 2, end, c);
    merge(start, (end - start) / 2, start + (end - start) / 2, (end - start) / 2, start, c);
  }
}

void SelectSort::sort(int* start, int* end, cmp c) {
  int* cur = start;
  for (; cur < end - 1; cur++) {
    int* tmp  = cur;
    for (int* i = cur + 1; i < end; i++) {
      if (c(*i, *tmp)) {
          tmp = i;
      }
    }
    swap(*cur, *tmp);
  }
}

void BubbleSort::sort(int* start, int* end, cmp c) {
  int* cur = start;
  for (; cur != end; cur++) {
    bool finish = true;
    for (int* tmp = end - 1; tmp != cur; tmp--) {
      if (c(*tmp, *(tmp - 1))) {
        swap(*tmp, *(tmp - 1));
        finish = false;
      }
    }
    if (finish) {
      break;
    }
  }
} 