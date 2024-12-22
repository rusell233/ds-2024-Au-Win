#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include <string>
#include <vector>
#include <stack>

class ExpressionEvaluator {
public:
    // 计算中缀表达式的值
    double evaluate(const std::string& infix);

private:
    // 返回操作符的优先级
    int precedence(char op);
    // 应用操作符到两个操作数上
    double applyOp(double a, double b, char op);
    // 检查字符是否是操作符
    bool isOperator(char c);
    // 检查字符串是否是有效的数字
    bool isValidNumber(const std::string& s);
    // 将中缀表达式转换为后缀表达式
    std::vector<std::string> infixToPostfix(const std::string& infix);
    // 计算后缀表达式的值
    double evaluatePostfix(const std::vector<std::string>& postfix);
};

#endif // EXPRESSION_EVALUATOR_H