#ifndef _STACK_INL_
#define _STACK_INL_

#include "base.h"

namespace ll {

namespace algorithm {
  template<typename Type>
  Stack<Type>::Stack()
    : head { 0 },
      cap { default_capacity } {
    datas.resize(cap);
  }

  template<typename Type>
  Stack<Type>::Stack(size_t c)
    : head { 0 },
      cap { c } {
    datas.resize(cap);
  }

  template<typename Type>
  bool Stack<Type>::empty() const {
    return head == 0;
  }

  template<typename Type>
  size_t Stack<Type>::capacity() const {
    return cap;
  }

  template<typename Type>
  void Stack<Type>::push(const Type& d) throw (DataException) {
    if (cap == head) {
      throw DataException("stack is full");
    }
    datas[head++] = d;
  }

  template<typename Type>
  Type Stack<Type>::pop() throw (DataException) {
    if (empty()) {
      throw DataException("stack is empty");
    }
    return datas[--head];
  }

  template<typename Type>
  Type Stack<Type>::top() {
    return datas[head - 1];
  }

}

}

#endif