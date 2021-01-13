#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include <cstring>
#include "handler.h"

namespace ll {

namespace algorithm {

template<typename Type>
int find(Type* data, int data_cnt, Type it) {
  int left = 0, right = data_cnt;
  
  while (left >= 0 && left <= right) {
    int mid = left + (right - left) / 2;
    if (it == data[mid]) {
      return mid;
    } else if (data[mid] < it) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

template<typename Type>
void merge(Type* data_f, int data_f_len, Type* data_s, int data_s_len, Type* res, cmp2<Type> c) {
  int datas_f_cp[data_f_len];
  std::memcpy(datas_f_cp, data_f, data_f_len * sizeof(Type));
  int datas_s_cp[data_s_len];
  std::memcpy(datas_s_cp, data_s, data_s_len * sizeof(Type));
  int k = 0, i = 0, j = 0;
  for (; i < data_f_len && j < data_s_len;) {
    if (c(datas_f_cp[i], datas_s_cp[j])) {
      res[k++] = datas_f_cp[i++];
    } else {
      res[k++] = datas_s_cp[j++];
    }
  }
  for (; i < data_f_len;) {
    res[k++] = datas_f_cp[i++];
  }
  for (; j < data_s_len;) {
    res[k++] = datas_s_cp[j++];
  }
}

template<typename Type>
void for_each(Type* start, Type* end, each<Type&> h) {
  for (; start != end; ++start) {
    h(*start);
  }
}

template<typename Type>
void swap(Type& lh, Type& rh) {
  Type tmp = lh;
  lh = rh;
  rh = tmp;
}

} // algorithm

}// ll

#endif