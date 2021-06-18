#ifndef _STACK_H_
#define _STACK_H_

#include <exception>
#include <string>
#include <vector>

namespace ll {

namespace algorithm {

using std::exception;
using std::string;
using std::vector;

class StackException : public exception {
  public:
    StackException(const string& msg)
        : messag { msg } {
    }

    const char* what() noexcept {
        return messag.c_str();
    }

  private:
    string messag;
};

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
    void push(const Type& d) throw (StackException);
    Type pop() throw (StackException);
  private:
    size_t top;
    size_t cap;
    vector<Type> datas;
};

}

}

#include "Stack.inl"

#endif