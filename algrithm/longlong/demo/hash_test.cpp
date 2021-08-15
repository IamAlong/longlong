#include "head.h"
#include "data_struct/hash.hpp"

using namespace ll::algorithm;

int main() {
  HashTable<int, int> hash_test;

  auto i = hash_test[1];
  cout << i << endl;
  hash_test[1] = 1;
  cout << hash_test[1] << endl;

  for (auto i = 0; i < 10; i++) {
    hash_test[i];
  }

  cout << hash_test[1] << endl;

  cout << "size: " << hash_test.get_size() << endl
    << "cap: " << hash_test.get_cap() << endl
    << "rate: " << hash_test.get_rate() << endl;

  return 0;
}