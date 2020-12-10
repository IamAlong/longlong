#include <functional>
namespace ll {

namespace algrithm {

template<typename Type>
using handler = std::function<void(Type*, void*)>;

template<typename Type>
int find(Type* _datas, int _datas_cnt,Type data) {
  return 0;
}

template<typename Type>
void merge(Type* _datas_f, int _datas_f_len, Type* _datas_s, int _datas_s_len) {

}

template<typename Type>
void for_each(Type* _start, Type* _end, handler<Type> _h) {

}

} // algrithm

}// ll