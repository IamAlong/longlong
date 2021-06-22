#ifndef _STACK_H_
#define _STACK_H_

#include <vector>
#include "data_exception.h"

namespace ll {

namespace algorithm {

using std::vector;

template<typename Type>
class Stack {
 public:
  Stack();
  Stack(size_t c);
  Stack(Stack& rh) = delete;
  Stack& operator=(const Stack& rh) = delete;
  virtual ~Stack() {}
  bool empty() const;
  size_t capacity() const;
  void push(const Type& d) throw (DataException);
  Type pop() throw (DataException);
 private:
  size_t top;
  size_t cap;
  vector<Type> datas;
};

}

}

#include "stack.inl"

#endif