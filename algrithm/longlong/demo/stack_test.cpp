#include <iostream>
#include "data_struct/Stack.h"

using namespace ll::algorithm;
using std::cout;
using std::endl;

int main() {
  Stack<int> s1{ 0 };
  try {
    s1.push(1);
  } catch (StackException e) {
    cout << e.what() << endl;
  }

  Stack<int> s2;
  try {
    s2.pop();
  } catch (StackException e) {
    cout << e.what() << endl;
  }
  s2.push(0);
  s2.push(1);
  cout << "capacity " << s2.capacity() << endl;
  cout << "pop " << s2.pop() << endl;
  cout << "empty " << s2.empty() << endl;
  cout << "pop " << s2.pop() << endl;
  cout << "empty " << s2.empty() << endl; 
  
  return 0;
}