#ifndef _QUEUE_INL_H_
#define _QUEUE_INL_H_

#include "base.h"

namespace ll {

namespace algorithm {

  template<typename Type>
  Queue<Type>::Queue()
    : cap { default_capacity },
      queue_size { 0 },
      head { 0 },
      tail { 0 } {
    datas.resize(cap);
  }

  template<typename Type>
  Queue<Type>::Queue(size_t cap)
    : cap { cap },
      queue_size { 0 },
      head { 0 },
      tail { 0 } {
    datas.resize(cap);
  }

  template<typename Type>
  bool Queue<Type>::empty() const noexcept {
    return queue_size == 0;
  }

  template<typename Type>
  size_t Queue<Type>::capacity() const noexcept {
    return cap;
  }

  template<typename Type>
  size_t Queue<Type>::size() const noexcept {
    return queue_size;
  }

  template<typename Type>
  void Queue<Type>::enqueue(const Type& data) throw (DataException) {
    if (queue_size == cap) {
      throw DataException("queue is full");
    }
    datas[head] = data;
    head = (head + 1) % cap;
    ++queue_size;
  }

  template<typename Type>
  Type Queue<Type>::dequeue() throw (DataException) {
    if (0 == queue_size) {
      throw DataException("queue is empty");
    }
    Type data = datas[tail];
    tail = (tail + 1) % cap;
    --queue_size;
    return data;
  }

  template<typename Type>
  Type Queue<Type>::front() {
    return datas[tail]; 
  }

  template<typename Type>
  Deque<Type>::Deque()
    : cap { default_capacity },
      deque_size { 0 },
      head { 0 },
      tail { 0 } {
    datas.clear();
  }

  template<typename Type>
  Deque<Type>::Deque(size_t cap)
    : cap { cap },
      deque_size { 0 },
      head { 0 },
      tail { 0 } {
    datas.clear();
  }

  template<typename Type>
  bool Deque<Type>::empty() const noexcept {
    return deque_size == 0;
  }

  template<typename Type>
  size_t Deque<Type>::size() const noexcept {
    return deque_size;
  }

  template<typename Type>
  size_t Deque<Type>::capacity() const noexcept {
    return cap * datas.size();
  }

  template<typename Type>
  Type& Deque<Type>::front() {
    return datas[tail / cap][tail % cap];
  }

  template<typename Type>
  Type& Deque<Type>::back() {
    return datas[(head - 1) / cap][(head - 1) % cap];
  }
  
  template<typename Type>
  void Deque<Type>::offset() {
    datas.resize(datas.size() + 1);
    for (auto i = datas.size() - 1; i > 0; --i) {
      datas[i] = datas[i - 1];
    }
    vector<Type> tmp(cap);
    datas[0] = tmp;
  }

  template<typename Type>
  void Deque<Type>::push_front(const Type& data) {
    if (tail == 0) {
      offset();
      tail = cap;
      head += cap;
    }
    datas[(tail - 1) / cap][(tail - 1) % cap] = data;
    --tail;
    ++deque_size;
  }

  template<typename Type>
  void Deque<Type>::push_back(const Type& data) {
    if (head == cap * datas.size()) {
      vector<Type> tmp(cap);
      datas.push_back(tmp);
    }
    datas[head / cap][head % cap] = data;
    ++head;
    ++deque_size;
  }

  template<typename Type>
  void Deque<Type>::pop_front() {
    if (!empty()) {
      ++tail;
      --deque_size;
    }
  }

  template<typename Type>
  void Deque<Type>::pop_back() {
    if (!empty()) {
      --head;
      --deque_size;
    }
  }

}

}

#endif