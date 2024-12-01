#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include "HeapSort.h"

// 检查向量是否有序
template<typename T>
bool check(const std::vector<T>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i - 1] > vec[i]) {
            return false;
        }
    }
    return true; // 否则，向量已排序
}

// 生成部分元素重复序列
std::vector<int> generatePartiallyRepeatedVector(size_t size) {
    std::vector<int> vec(size);
    std::iota(vec.begin(), vec.end(), 0); // 先填充有序序列
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(vec.begin(), vec.end(), gen); // 打乱序列
    return vec;
}

int main() {
    // 初始化不同类型数据的向量
    std::vector<int> randomVec(1000000), orderedVec(1000000), reverseVec(1000000), repetitiveVec(1000000);

    // 随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd()); // 使用随机设备初始化Mersenne Twister生成器
    std::uniform_int_distribution<> dis(0, 999999); // 定义一个均匀分布的整数范围

    // 填充随机向量
    std::generate(randomVec.begin(), randomVec.end(), [&] { return dis(gen); });

    // 填充有序向量
    std::iota(orderedVec.begin(), orderedVec.end(), 0);

    // 填充逆序向量
    std::iota(reverseVec.begin(), reverseVec.end(), 1000000);

    // 填充重复元素向量
    repetitiveVec = generatePartiallyRepeatedVector(1000000);

    // 用于计时的变量
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    // 测试随机序列
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

    // 测试有序序列
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

    // 测试逆序序列
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

    // 测试重复元素序列
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