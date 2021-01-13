#include <iostream>
#include <ctime>
#include "sort.h"
#include "util.hpp"
using namespace ll::algorithm;

int main() {
  SortInterface* ss = new InsertionSort();
  int a[6] = {1, 2, 1, 3, 4, 2};
  std::cout << "Testint insertion sort" << std::endl;
  auto start = std::clock();
  ss->sort(a, a + 6);
  auto end = std::clock();
  std::cout << "insertion sort cost " << end - start << "Ms" << std::endl;
  for (auto i : a) {
    std:: cout << i << " ";
  }
  delete ss;
  std::cout << std::endl << "Test insert sort finish" << std::endl;
  
  ss = new MergeSort();
  int b[6] = {1, 2, 1, 3, 4, 2};
  std::cout << "Testint merge sort" << std::endl;
  start = std::clock();
  ss->sort(b, b + 6);
  end = std::clock();
  std::cout << "merge sort cost " << end - start << "Ms" << std::endl;
  for (auto i : b) {
    std::cout << i << " ";
  }
  delete ss;
  std::cout << std::endl << "Test merge sort finish" << std::endl;

  ss = new SelectSort();
  int c[6] = {1, 2, 1, 3, 4, 2};
  std::cout << "Testint select sort" << std::endl;
  start = std::clock();
  ss->sort(c, c + 6);
  end = std::clock();
  std::cout << "select sort cost " << end - start << "Ms" << std::endl;
  for (auto i : c) {
    std::cout << i << " ";
  }
  delete ss;
  std::cout << std::endl << "Test select sort finish" << std::endl;

  ss = new BubbleSort();
  int d[6] = {1, 2, 1, 3, 4, 2};
  std::cout << "Testint bubble sort" << std::endl;
  start = std::clock();
  ss->sort(d, d + 6);
  end = std::clock();
  std::cout << "bubble sort cost " << end - start << "Ms" << std::endl;
  for (auto i : d) {
    std::cout << i << " ";
  }
  delete ss;
  std::cout << std::endl << "Test bubble sort finish" << std::endl;

  ss = new HeapSort();
  int e[6] = {1, 2, 1, 3, 4, 2};
  std::cout << "Testint heap sort" << std::endl;
  start = std::clock();
  ss->sort(e, e + 6);
  end = std::clock();
  std::cout << "heap sort cost " << end - start << "Ms" << std::endl;
  for (auto i : e) {
    std::cout << i << " ";
  }
  delete ss;
  std::cout << std::endl << "Test heap sort finish" << std::endl;


  return 0;
}