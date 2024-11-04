#include "BST.h"
#include <iostream>

int main() {
    // 创建一个整数类型的二叉搜索树
    BinarySearchTree<int> bst;

    // 插入一些元素
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    std::cout << "初始树结构：" << std::endl;
    bst.printTree(std::cout);

    // 移除元素
    std::cout << "移除元素 3：" << std::endl;
    bst.remove(3);
    bst.printTree(std::cout);

    std::cout << "移除元素 5：" << std::endl;
    bst.remove(5);
    bst.printTree(std::cout);

    std::cout << "移除元素 8：" << std::endl;
    bst.remove(8);
    bst.printTree(std::cout);

    return 0;
}