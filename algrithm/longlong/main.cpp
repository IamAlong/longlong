#include "sort.h"
using namespace ll::algrithm;

int main() {
  SortInterface* ss = new InsertionSort();
  int a;
  ss->sort(&a, &a);
  return 0;
}