#ifndef _STACK_INL_
#define _STACK_INL_

#include <limits>

namespace ll {

namespace algorithm {
  static const size_t default_capacity = 1 << 6;
  template<typename Type>
  Stack<Type>::Stack()
    : top { 0 },
      cap { default_capacity } {
    datas.resize(cap);
  }

  template<typename Type>
  Stack<Type>::Stack(size_t c)
    : top { 0 },
       cap { c } {
    datas.resize(cap);
  }

  template<typename Type>
  bool Stack<Type>::empty() const {
    return top == 0;
  }

  template<typename Type>
  size_t Stack<Type>::capacity() const {
    return cap;
  }

  template<typename Type>
  void Stack<Type>::push(const Type& d) throw (DataException) {
    if (cap == top) {
      throw DataException("stack is full");
    }
    datas[top++] = d;
  }

  template<typename Type>
  Type Stack<Type>::pop() throw (DataException) {
    if (empty()) {
      throw DataException("stack is empty");
    }
    return datas[--top];
  }

}

}

#endif