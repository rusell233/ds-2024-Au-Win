#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <algorithm>
#include <vector>

template<typename T>
void heapSort(std::vector<T>& vec) {
    // 使用std::make_heap()将vector转换成最大堆
    std::make_heap(vec.begin(), vec.end());

    // 循环，直到堆中没有元素
    while (!vec.empty()) {
        // 将最大元素移动到vector的末尾，并调整堆
        std::pop_heap(vec.begin(), vec.end());
        // 从vector中移除最大元素
        vec.erase(vec.end() - 1);
    }
}

#endif // HEAPSORT_H
