#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

double applyOp(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b != 0 ? a / b : numeric_limits<double>::quiet_NaN(); // 防止除以0
    default: throw runtime_error("Invalid operator");
    }
}

template <typename T>
T pop_and_return(stack<T>& s) {
    if (s.empty()) {
        cout << "ILLEGAL" << endl;
        exit(0);
    }
    T value = s.top();
    s.pop();
    return value;
}

bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

bool is_legitimate(const string& infix) {
    for (char c : infix) {
        if (!isspace(c) && !isdigit(c) && c != '.' && c != 'e' && c != 'E' && !is_op(c)) {
            cout << "ILLEGAL" << endl;
            exit(0);
        }
    }
    return true;
}

double parse_number(const string& infix, size_t& index) {
    double value = 0;
    double fraction = 1;
    bool hasFraction = false;
    bool isNegative = false;

    if (infix[index] == '-') {
        isNegative = true;
        ++index;
    }

    while (index < infix.size() && (isdigit(infix[index]) || infix[index] == '.')) {
        if (infix[index] == '.') {
            hasFraction = true;
        }
        else {
            value = value * 10 + (infix[index] - '0');
            if (hasFraction) {
                fraction *= 0.1;
            }
        }
        ++index;
    }

    value *= fraction;

    if (index < infix.size() && (infix[index] == 'e' || infix[index] == 'E')) {
        ++index;

        if (index < infix.size() && infix[index] == '-') {
            ++index;
        }

        double expValue = 0;
        while (index < infix.size() && isdigit(infix[index])) {
            expValue = expValue * 10 + (infix[index] - '0');
            ++index;
        }

        value *= pow(10, expValue);
    }

    if (isNegative) {
        value = -value;
    }

    return value;
}

double evaluator(const string& infix) {
    is_legitimate(infix);
    stack<double> values;
    stack<char> ops;
    size_t index = 0;
    char prev_op = 0; // 用于存储上一个操作符

    while (index < infix.size()) {
        char c = infix[index];
        if (isspace(c)) {
            ++index;
            continue;
        }

        if (isdigit(c) || c == '.') {
            double num = parse_number(infix, index);
            values.push(num);
        }
        else if (c == '(') {
            ops.push(c);
            ++index;
        }
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = pop_and_return(values);
                double val1 = pop_and_return(values);
                char op = pop_and_return(ops);
                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty() && ops.top() != '(') {
                cout << "ILLEGAL" << endl;
                exit(0);
            }
            ops.pop();
            ++index;
        }
        else if (is_op(c)) {
            if (c == '-' && (prev_op == 0 || prev_op == '+' || prev_op == '-')) {
                // 处理负数的情况
                values.push(-1 * pop_and_return(values));
            }
            else {
                while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                    double val2 = pop_and_return(values);
                    double val1 = pop_and_return(values);
                    char op = pop_and_return(ops);
                    values.push(applyOp(val1, val2, op));
                }
                ops.push(c);
            }
            prev_op = c;
            ++index;
        }
    }

    while (!ops.empty()) {
        if (ops.top() == '(' || ops.top() == ')') {
            cout << "ILLEGAL" << endl;
            exit(0);
        }
        double val2 = pop_and_return(values);
        double val1 = pop_and_return(values);
        char op = pop_and_return(ops);
        values.push(applyOp(val1, val2, op));
    }

    if (values.size() != 1) {
        cout << "ILLEGAL" << endl;
        exit(0);
    }

    return values.top();
}

int main() {
    // 合法的测试用例
    cout << "1.01*(2.2+3*4) = " << evaluator("1.01*(2.2+3*4)") << endl;
    cout << "1+2 = " << evaluator("1+2") << endl;
    cout << "1-2 = " << evaluator("1+2") << endl;
    cout << "1*2 = " << evaluator("1*2") << endl;
    cout << "1/2 = " << evaluator("1/2") << endl;
    cout << "1+2*3 = " << evaluator("1+2*3") << endl;
    cout << "1*(2+3) = " << evaluator("1*(2+3)") << endl;
    cout << "1.01*(2.2+3*4) = " << evaluator("1.01*(2.2+3*4)") << endl;
    cout << "1*(2*(3+4)) = " << evaluator("1*(2*(3+4))") << endl;
    cout << "1+2e2 = " << evaluator("1+2e2") << endl;
    cout << "1+2e-1 = " << evaluator("1+2e-1") << endl;
    cout << "1.1e2+(2.1e-1*3.1e-1) = " << evaluator("1.1e2+(2.1e-1*3.1e-1)") << endl;
    cout << "1+-2 = " << evaluator("1+-2") << endl;
    cout << "1*-2 = " << evaluator("1*-2") << endl;
    cout << "1*(-2+1) = " << evaluator("1*(-2+1)") << endl;
    cout << "-1+2 = " << evaluator("-1+2") << endl;
    cout << "1*(1+2)-1 = " << evaluator("1*(1+2)-1") << endl;

    // 非法的测试用例
    cout << "1+*(1+2) = " << evaluator("1+*(1+2)") << endl;
    cout << "1-((1+2) = " << evaluator("1-((1+2)") << endl;
    cout << "1*(!1+2) = " << evaluator("1*(!1+2)") << endl;
    cout << "1.00.1+(1+2) = " << evaluator("1.00.1+(1+2)") << endl;
    cout << "1/(1-1) = " << evaluator("1/(1-1)") << endl;
    cout << "1+--2 = " << evaluator("1+--2") << endl;
    cout << "1++2 = " << evaluator("1++2") << endl;
    cout << "1-(1+2)- = " << evaluator("1-(1+2)-") << endl;
    cout << "1*2e--2 = " << evaluator("1*2e--2") << endl;
    cout << "1*2e = " << evaluator("1*2e") << endl;

    return 0;
}