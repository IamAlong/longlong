#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <vector>
#include "data_exception.h"

namespace ll {

namespace algorithm {

using std::vector;

template<typename Type>
class Queue {
 public:
  Queue();
  Queue(size_t cap);
  Queue(Queue& rh) = delete;
  Queue& operator=(const Queue& rh) = delete;
  virtual ~Queue() {}

  bool empty() const noexcept;
  size_t capacity() const noexcept;
  size_t size() const noexcept;

  void enqueue(const Type& data) throw (DataException);
  Type dequeue() throw (DataException);
 private:
  size_t queue_size;
  size_t cap;
  size_t head;
  size_t tail;
  vector<Type> datas;
};

template<typename Type>
class Deque {
 public:
  Deque();
  Deque(size_t cap);
  Deque(Deque& rh) = delete;
  Deque& operator=(const Deque& rh) = delete;
  virtual ~Deque() {}

  bool empty() const noexcept;
  size_t size() const noexcept;
  size_t capacity() const noexcept;

  /*
   * 这里和标准库的返回值保持一致
   * ep: push_front(0) -> push_back(1) -> pop_back() -> pop_front()
   * rt: front() -> 1; back() -> 0
   * 当deque为empty时，调用back() 将会crash
   */
  Type& front();
  Type& back();
  
  void push_front(const Type& data);
  void push_back(const Type& data);
  void pop_front();
  void pop_back();

 private:
  void offset();
  
  size_t cap; // 一个数组的容量
  size_t deque_size;
  size_t head;
  size_t tail;
  vector<vector<Type>> datas;
};

}

}

#endif

#include "queue.inl"