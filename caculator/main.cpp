#include "calculator.h"
#include <iostream>
#include <vector>

int main() {
    double result;
    std::vector<std::string> expressions = {
        // 正确的表达式
        "3 + 4","6 - 2",
        "2 * 3","8 / 2",
        "3 + 5 * 2","(3 + 5) * 2",
        "10 / 2 + 3 - 1","3.5 + 2","10 - 5.5",
        "2 * (3 + 4) / 5",
        "1e2","1.5e-3","1.0E+5","1.2e1+3",
        // 错误的表达式
        "3 + * 4", // 缺少操作数
        "3 + ( 4", // 缺少闭括号
        "3 + 4 *", // 多余的操作符
        "3 + 4 5", // 缺少操作符
        "3 ++ 4", // 多余的加号
        "3 + ( 4 * )", // 空表达式
        "3 + . . 4", // 多个小数点
        "3e++2", // 错误的科学记数法
        "3e-2.5", // 负指数不是整数
        "3e", // 缺少指数
        "3e-", // 缺少指数
        "3.2.4", // 错误的小数点使用
        "3 + (4 * 5", // 括号不匹配
        "- - 3", // 连续负号
    };

    for (const std::string& expr : expressions) {
        std::cout << "测试中缀表达式: " << expr << std::endl;
        if (!evaluate(expr, result)) {
            std::cout << "表达式问题: " << expr << std::endl;
        }
        else {
            std::cout << "Result: " << result << std::endl;
        }
    }
    return 0;
}