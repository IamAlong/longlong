#include <vector>
#include "interview.h"
#include "head.h"

using namespace ll::algorithm;

void test_get_maximum() {
  int a[16] = { 1, 2, 3, -4, -1, -3, -5, 6, -10, 1, 12, -3, -5, 10, 7, 8 };
  std::vector<int> nums { a, a+16 };
  MaximumSubarray ms { nums };
  auto res = ms.get_maximum(0, 15);
  std::cout << res.to_string() << std::endl;
  res = ms.get_maximum_v2();
  std::cout << res.to_string() << std::endl;
}

void test_get_min_max() {
  int a[15] = { 2, 3, -4, -1, -3, -5, 6, -10, 1, 12, -3, -5, 10, 7, 8 };
  std::vector<int> nums { a, a+16 };
  GetMinAndMax gmam { nums };
  int min, max;
  gmam.get_min_max(min, max);
  std::cout << "test_get_min_max: min=" << min << ", max=" << max << std::endl;
}

void test_find_kth_num() {
  int a[16] = { 1, 2, 3, -4, -1, -3, -5, 6, -10, 1, 12, -3, -5, 10, 7, 8 };
  std::vector<int> nums { a, a+16 };
  FindKthNum fkn;
  int res = fkn.find_kth_num(nums.begin(), nums.end(), 8);
  std::cout << "test_find_kth_num: res=" << res << std::endl;
}

void test_queue_use_stack() {
  QueueUseStack q;
  for (int i = 0; i < 10; ++i) {
    q.enqueue(i);
  }
  cout << "first: " << q.front();
  q.dequeue();
  cout << "second: " << q.front() << endl;
}

void test_stack_use_queue() {
  StackUseQueue s;
  for (int i = 0; i < 10; ++i) {
    s.push(i);
  }
  cout << "first: " << s.top();
  s.pop();
  cout << "second: " << s.top() << endl;
}

int main() {
  test_get_maximum();
  test_get_min_max();
  test_find_kth_num();
  test_queue_use_stack();
  test_stack_use_queue();
  return 0;
}