#include <vector>
#include <iostream>

#include "data_struct/heap.h"
using namespace ll::algorithm;

int main() {
    int a[8] = {6, 5, 4, 3, 2, 1, 7, 2};
    Heap<int> heap(a, a + 8, 8);

    std::cout << heap.pop() << std::endl;

    heap.insert(0);

    return 0;
}