#include "expression_evaluator.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cctype>

using namespace std;

// 返回操作符的优先级
int ExpressionEvaluator::precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// 应用操作符到两个操作数上
double ExpressionEvaluator::applyOp(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) {
            cerr << "ILLEGAL" << endl;
            exit(EXIT_FAILURE);
        }
        return a / b;
    default: throw runtime_error("Invalid operator");
    }
}

// 检查字符是否是操作符
bool ExpressionEvaluator::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// 检查字符串是否是有效的数字
bool ExpressionEvaluator::isValidNumber(const string& s) {
    bool hasE = false, hasDot = false, hasSign = false, hasNum = false;
    size_t startPos = s.find_first_not_of("+-");
    for (size_t i = startPos; i < s.length(); ++i) {
        char c = s[i];
        if (isdigit(c)) hasNum = true;
        else if (c == '.') {
            if (hasDot) return false;
            hasDot = true;
        }
        else if (c == 'e' || c == 'E') {
            if (hasE || !hasNum) return false;
            hasE = true;
            hasNum = false; // 重置hasNum以检查e后面是否有数字
        }
        else if ((c == '+' || c == '-') && (i == 0 || s[i - 1] == 'e' || s[i - 1] == 'E')) {
            if (hasSign) return false;
            hasSign = true;
        }
        else {
            return false; // 发现非法字符
        }
    }
    return hasNum; // 必须至少包含一个数字
}

// 将中缀表达式转换为后缀表达式
vector<string> ExpressionEvaluator::infixToPostfix(const string& infix) {
    stack<char> ops;
    vector<string> postfix;
    for (size_t i = 0; i < infix.size(); ++i) {
        if (isspace(infix[i])) continue;
        if (isdigit(infix[i])) {
            string num;
            num += infix[i];
            while (i + 1 < infix.size() && (isdigit(infix[i + 1]) || infix[i + 1] == '.')) {
                num += infix[++i];
            }
            postfix.push_back(num);
        }
        else if (infix[i] == '(') {
            ops.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                postfix.push_back(string(1, ops.top()));
                ops.pop();
            }
            if (!ops.empty() && ops.top() == '(') {
                ops.pop();
            }
            else {
                cerr << "ILLEGAL" << endl;
                exit(EXIT_FAILURE);
            }
        }
        else if (isOperator(infix[i])) {
            while (!ops.empty() && ops.top() != '(' && precedence(ops.top()) >= precedence(infix[i])) {
                postfix.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(infix[i]);
        }
    }
    while (!ops.empty()) {
        if (ops.top() == '(') {
            cerr << "ILLEGAL" << endl;
            exit(EXIT_FAILURE);
        }
        postfix.push_back(string(1, ops.top()));
        ops.pop();
    }
    return postfix;
}

// 计算后缀表达式的值
double ExpressionEvaluator::evaluatePostfix(const vector<string>& postfix) {
    stack<double> values;
    for (const string& token : postfix) {
        if (isOperator(token[0])) {
            double right = values.top(); values.pop();
            double left = values.top(); values.pop();
            values.push(applyOp(left, right, token[0]));
        }
        else if (isValidNumber(token)) {
            values.push(stod(token));
        }
        else {
            cerr << "ILLEGAL" << endl;
            exit(EXIT_FAILURE);
        }
    }
    return values.top();
}

// 计算中缀表达式的值
double ExpressionEvaluator::evaluate(const string& infix) {
    if (infix.empty()) {
        cerr << "ILLEGAL" << endl;
        exit(EXIT_FAILURE);
    }

    vector<string> postfix = infixToPostfix(infix);
    return evaluatePostfix(postfix);
}