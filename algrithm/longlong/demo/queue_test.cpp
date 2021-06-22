#include "head.h"

#include "data_struct/queue.h"

using namespace ll::algorithm;

int main() {
  Queue<int> q { 0 };
  try {
    cout << "empty " << q.empty() << endl;
    cout << "capacity " << q.capacity() << endl;
    cout << "size " << q.size() << endl;
    q.enqueue(0);
  } catch (DataException e) {
    cout << e.what() << endl;
  }
  try {
    q.dequeue();
  } catch (DataException e) {
    cout << e.what() << endl;
  }

  Queue<int> q2;
  q2.enqueue(0);
  q2.enqueue(1);

  cout << q2.dequeue() << endl;
  cout << q2.dequeue() << endl;
  cout << "empty " << q2.empty() << endl;
  cout << "capacity " << q2.capacity() << endl;
  cout << "----------deque---------" << endl;
  Deque<int> dq;
  cout << "capacity: " << dq.capacity() << endl;
  cout << "empty: " << dq.empty() << endl;
  cout << "size: " << dq.size()  << endl;
  dq.push_back(1);
  cout << "front: " << dq.front() << endl;
  cout << "back: " << dq.back() << endl;
  dq.push_front(0);
  cout << "front: " << dq.front() << endl;
  cout << "back: " << dq.back() << endl;
  dq.push_back(2);
  cout << "front: " << dq.front() << endl;
  cout << "back: " << dq.back() << endl;
  for (auto i = 3; i < 1024; i++) {
    dq.push_back(i);
  }
  dq.push_front(-1);
  dq.push_back(1024);
  cout << "front: " << dq.front() << endl;
  cout << "back: " << dq.back() << endl;
  dq.pop_back();
  dq.pop_front();
  cout << "front: " << dq.front() << endl;
  cout << "back: " << dq.back() << endl;
  return 0;
}