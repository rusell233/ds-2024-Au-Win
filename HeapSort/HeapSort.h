#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <algorithm>
#include <vector>

template<typename T>
void heapSort(std::vector<T>& vec) {
    // ʹ��std::make_heap()��vectorת��������
    std::make_heap(vec.begin(), vec.end());

    // ѭ����ֱ������û��Ԫ��
    while (!vec.empty()) {
        // �����Ԫ���ƶ���vector��ĩβ����������
        std::pop_heap(vec.begin(), vec.end());
        // ��vector���Ƴ����Ԫ��
        vec.erase(vec.end() - 1);
    }
}

#endif // HEAPSORT_H
