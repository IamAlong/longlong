#include <cstring>
#include "handler.h"

namespace ll {

namespace algrithm {

template<typename Type>
int find(Type* _datas, int _datas_cnt, Type data) {
  int left = 0, right = _datas_cnt;
  
  while (left >= 0 && left <= right) {
    int mid = left + (right - left) / 2;
    if (data == _datas[mid]) {
      return mid;
    } else if (_datas[mid] < data) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

template<typename Type>
void merge(Type* _datas_f, int _datas_f_len, Type* _datas_s, int _datas_s_len, Type* _res, cmp2<Type> c) {
  int datas_f_cp[_datas_f_len];
  std::memcpy(datas_f_cp, _datas_f, _datas_f_len * sizeof(Type));
  int datas_s_cp[_datas_s_len];
  std::memcpy(datas_s_cp, _datas_s, _datas_s_len * sizeof(Type));
  int k = 0, i = 0, j = 0;
  for (; i < _datas_f_len && j < _datas_s_len;) {
    if (c(datas_f_cp[i], datas_s_cp[j])) {
      _res[k++] = datas_f_cp[i++];
    } else {
      _res[k++] = datas_s_cp[j++];
    }
  }
  for (; i < _datas_f_len;) {
    _res[k++] = datas_f_cp[i++];
  }
  for (; j < _datas_s_len;) {
    _res[k++] = datas_s_cp[j++];
  }
}

template<typename Type>
void for_each(Type* _start, Type* _end, each<Type&> _h) {
  for (; _start != _end; ++_start) {
    _h(*_start);
  }
}

template<typename Type>
void swap(Type& _lh, Type& _rh) {
  Type tmp = _lh;
  _lh = _rh;
  _rh = tmp;
}

} // algrithm

}// ll