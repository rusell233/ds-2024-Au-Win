#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include "HeapSort.h"

// ��������Ƿ�����
template<typename T>
bool check(const std::vector<T>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i - 1] > vec[i]) {
            return false;
        }
    }
    return true; // ��������������
}

// ���ɲ���Ԫ���ظ�����
std::vector<int> generatePartiallyRepeatedVector(size_t size) {
    std::vector<int> vec(size);
    std::iota(vec.begin(), vec.end(), 0); // �������������
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(vec.begin(), vec.end(), gen); // ��������
    return vec;
}

int main() {
    // ��ʼ����ͬ�������ݵ�����
    std::vector<int> randomVec(1000000), orderedVec(1000000), reverseVec(1000000), repetitiveVec(1000000);

    // �����������
    std::random_device rd;
    std::mt19937 gen(rd()); // ʹ������豸��ʼ��Mersenne Twister������
    std::uniform_int_distribution<> dis(0, 999999); // ����һ�����ȷֲ���������Χ

    // ����������
    std::generate(randomVec.begin(), randomVec.end(), [&] { return dis(gen); });

    // �����������
    std::iota(orderedVec.begin(), orderedVec.end(), 0);

    // �����������
    std::iota(reverseVec.begin(), reverseVec.end(), 1000000);

    // ����ظ�Ԫ������
    repetitiveVec = generatePartiallyRepeatedVector(1000000);

    // ���ڼ�ʱ�ı���
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    // �����������
    {
        std::vector<int> temp = randomVec;
        start = std::chrono::high_resolution_clock::now();
        heapSort(temp);
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Random sequence heapSort time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";
        std::cout << "Random sequence is " << (check(temp) ? "sorted" : "not sorted") << std::endl;

        temp = randomVec;
        start = std::chrono::high_resolution_clock::now();
        std::make_heap(temp.begin(), temp.end());
        std::sort_heap(temp.begin(), temp.end());
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Random sequence std::sort_heap time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";
        std::cout << "Random sequence is " << (check(temp) ? "sorted" : "not sorted") << std::endl;
    }

    // ������������
    {
        std::vector<int> temp = orderedVec;
        start = std::chrono::high_resolution_clock::now();
        heapSort(temp);
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Ordered sequence heapSort time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";
        std::cout << "Ordered sequence is " << (check(temp) ? "sorted" : "not sorted") << std::endl;

        temp = orderedVec;
        start = std::chrono::high_resolution_clock::now();
        std::make_heap(temp.begin(), temp.end());
        std::sort_heap(temp.begin(), temp.end());
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Ordered sequence std::sort_heap time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";
        std::cout << "Ordered sequence is " << (check(temp) ? "sorted" : "not sorted") << std::endl;
    }

    // ������������
    {
        std::vector<int> temp = reverseVec;
        start = std::chrono::high_resolution_clock::now();
        heapSort(temp);
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Reverse sequence heapSort time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";
        std::cout << "Reverse sequence is " << (check(temp) ? "sorted" : "not sorted") << std::endl;

        temp = reverseVec;
        start = std::chrono::high_resolution_clock::now();
        std::make_heap(temp.begin(), temp.end());
        std::sort_heap(temp.begin(), temp.end());
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Reverse sequence std::sort_heap time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";
        std::cout << "Reverse sequence is " << (check(temp) ? "sorted" : "not sorted") << std::endl;
    }

    // �����ظ�Ԫ������
    {
        std::vector<int> temp = repetitiveVec;
        start = std::chrono::high_resolution_clock::now();
        heapSort(temp);
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Repetitive sequence heapSort time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";
        std::cout << "Repetitive sequence is " << (check(temp) ? "sorted" : "not sorted") << std::endl;

        temp = repetitiveVec;
        start = std::chrono::high_resolution_clock::now();
        std::make_heap(temp.begin(), temp.end());
        std::sort_heap(temp.begin(), temp.end());
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Repetitive sequence std::sort_heap time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";
        std::cout << "Repetitive sequence is " << (check(temp) ? "sorted" : "not sorted") << std::endl;
    }

    return 0;
}