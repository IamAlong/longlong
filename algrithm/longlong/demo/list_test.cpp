#define FOR_TEST
#include "head.h"
#include "data_struct/list.hpp"

using namespace ll::algorithm;

int main() {
  List<int> l1;
  for (auto i = 0; i < 5; i++) {
    l1.push_back(i);
  }
  vector<int> v = l1.print();
  cout << "l1 first print ";
  for (auto d : v) {
    cout << d << " ";
  }
  cout << endl;
  List<int> l2 = l1;
  v = l2.print();
  cout << "l2 first print ";
  for (auto d : v) {
    cout << d << " ";
  }
  cout << endl;
  auto node =  l1.search(2);
  l1.erase(node);
  v = l1.print();
  cout << "l1 second print ";
  for (auto d : v) {
    cout << d << " ";
  }
  cout << endl;
  List<int> l3;
  l3 = l2;
  v = l3.print();
  cout << "l3 first print ";
  for (auto d : v) {
    cout << d << " ";
  }
  cout << endl;

  DoublyList<int> dl1;
  for (int i = 0; i < 5; i++) {
    dl1.push_back(i);
  }
  v = dl1.print();
  cout << "dl1 first print ";
  for (auto d : v) {
    cout << d << " ";
  }
  cout << endl;

  auto n = dl1.search(2);
  cout << "search data " << n->data << endl;
  dl1.insert(4, n);
  v = dl1.print();
  cout << "dl1 second print ";
  for (auto d : v) {
    cout << d << " ";
  }
  cout << endl;

  dl1.erase(n->pre);
  v = dl1.print();
  cout << "dl1 third print ";
  for (auto d : v) {
    cout << d << " ";
  }
  cout << endl;

  return 0;
}