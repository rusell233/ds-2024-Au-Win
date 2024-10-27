#include "list.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

// 测试 List 类的基本功能
void testBasicOperations() {
    List<int> list;

    assert(list.empty() == true);
    assert(list.size() == 0);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    assert(list.size() == 3);
    assert(list.front() == 1);
    assert(list.back() == 3);

    list.pop_front();
    list.pop_back();

    assert(list.size() == 1);
    assert(list.front() == 2);
    assert(list.back() == 2);

    list.clear();
    assert(list.empty() == true);
}

// 测试 List 类的迭代器功能
void testIterators() {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // 测试 const_iterator
    {
        List<int>::const_iterator it = list.begin();
        assert(*it == 1);
        ++it;
        assert(*it == 2);
        --it;
        assert(*it == 1);
    }

    // 测试 iterator
    {
        List<int>::iterator it = list.begin();
        assert(*it == 1);
        ++it;
        assert(*it == 2);
        --it;
        assert(*it == 1);
        *it = 10;
        assert(list.front() == 10);
    }

    // 测试 end 迭代器
    {
        List<int>::iterator it = list.end();
        --it;
        assert(*it == 3);
    }

    // 测试 const_iterator 和 iterator 的比较
    {
        List<int>::iterator it1 = list.begin();
        List<int>::const_iterator it2 = list.begin();
        assert(it1 == it2);
    }
}

// 测试 List 类的插入和删除功能
void testInsertAndErase() {
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    // 测试插入
    auto it = list.begin();
    ++it;
    list.insert(it, 10);
    assert(list.size() == 3);
    assert(list.front() == 1);
    assert(list.back() == 2);
    it = list.begin();
    ++it;
    assert(*it == 10);

    // 测试删除
    list.erase(it);
    assert(list.size() == 2);
    assert(list.front() == 1);
    assert(list.back() == 2);
}

// 测试 List 类的异常处理
void testExceptions() {
    List<int> list;
    try {
        list.at(10);  // 应该抛出 std::out_of_range 异常
        assert(false);
    }
    catch (const std::out_of_range& e) {
        assert(true);
    }
}

int main() {
    testBasicOperations();
    testIterators();
    testInsertAndErase();
    testExceptions();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}