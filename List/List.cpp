#include "list.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

// ���� List ��Ļ�������
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

// ���� List ��ĵ���������
void testIterators() {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // ���� const_iterator
    {
        List<int>::const_iterator it = list.begin();
        assert(*it == 1);
        ++it;
        assert(*it == 2);
        --it;
        assert(*it == 1);
    }

    // ���� iterator
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

    // ���� end ������
    {
        List<int>::iterator it = list.end();
        --it;
        assert(*it == 3);
    }

    // ���� const_iterator �� iterator �ıȽ�
    {
        List<int>::iterator it1 = list.begin();
        List<int>::const_iterator it2 = list.begin();
        assert(it1 == it2);
    }
}

// ���� List ��Ĳ����ɾ������
void testInsertAndErase() {
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    // ���Բ���
    auto it = list.begin();
    ++it;
    list.insert(it, 10);
    assert(list.size() == 3);
    assert(list.front() == 1);
    assert(list.back() == 2);
    it = list.begin();
    ++it;
    assert(*it == 10);

    // ����ɾ��
    list.erase(it);
    assert(list.size() == 2);
    assert(list.front() == 1);
    assert(list.back() == 2);
}

// ���� List ����쳣����
void testExceptions() {
    List<int> list;
    try {
        list.at(10);  // Ӧ���׳� std::out_of_range �쳣
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