#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <limits>
#include <cstdlib>
#include <vector>

using namespace std;

template <typename T>
T pop_and_return(std::stack<T>& s) {
    if (s.empty()) {
        throw std::runtime_error("ȱ��Ԫ�أ�");
    }
    T value = s.top(); // ��ȡջ��Ԫ��
    s.pop(); // �Ƴ�ջ��Ԫ��
    return value; // ����ջ��Ԫ�ص�ֵ
}

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

double applyOp(double a, double b, char op)
{
    switch (op)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b != 0 ? a / b : numeric_limits<double>::quiet_NaN();
    default: throw runtime_error("Invalid operator");
    }
}

int is_op(char c) {
    if (c == '+' || c == '-' || c == '(' || c == ')' || c == '*' || c == '/') {
        return 1;
    }
    return 0;
}

int is_legitimate(const string& infix) {
    for (char c : infix) {
        if (!isspace(c) && !isdigit(c) && !is_op(c) && c != '.' && c != 'e') {
            throw std::runtime_error("�����ַ�������");
        }
    }
    return 1;
}

bool in_Bds(size_t i, const string& infix) {
    return i < infix.size();
}

double evaluator(const string& infix) {
    try {
        is_legitimate(infix);
        stack<double> n;
        stack<char> s;
        int isNegative = 1;
        int pow = 1;
        for (size_t i = 0; in_Bds(i, infix); ++i)
        {
            if (isspace(infix[i]))
            {
                continue;
            }
            if (isdigit(infix[i])) {
                int count = 0;
                size_t start = i;
                while (in_Bds(i, infix) && (isdigit(infix[i]) || infix[i] == '.')) {
                    if (infix[i] == '.') {
                        count++;
                    }
                    ++i;
                }
                if (count > 1)throw std::runtime_error("���С����");
                if (infix[i] == 'e' || infix[i] == 'E') {
                    string m = "";
                    i++;
                    if (i >= infix.size() || (infix[i] != '-' && !isdigit(infix[i]))) {
                        throw std::runtime_error("��ѧ��������ʽ����ȷ");
                    }
                    if (isdigit(infix[i]) || infix[i] == '+' || infix[i] == '-') {
                        do {
                            m += infix[i];
                            i++;
                        } while (isdigit(infix[i]) && in_Bds(i, infix));
                        pow = stod(m);
                    }
                    if (in_Bds(i, infix) && !is_op(infix[i])) {
                        throw std::runtime_error("��ѧ��������ʽ����ȷ");
                    }
                }
                n.push(pow * isNegative * stod(infix.substr(start, i - start)));
                isNegative = 1;
                i--;
            }
            else if (infix[i] == '(') {
                s.push(infix[i]);
            }
            else if (infix[i] == ')') {
                while (!s.empty() && s.top() != '(')
                {
                    char op = pop_and_return(s);
                    n.push(applyOp(pop_and_return(n), pop_and_return(n), op));
                }
                if (!s.empty() && s.top() != '(') {
                    throw std::runtime_error("���Ų�ƥ��");
                }
                s.pop(); // ���� '('
            }
            else
            { // ������
                if ((i == 0 || is_op(infix[i - 1])) && infix[i - 1] != ')' && infix[i] == '-' && isNegative == 1)
                {
                    isNegative = -1;
                    continue;
                }
                while (!s.empty() && precedence(s.top()) >= precedence(infix[i])) {
                    char op = pop_and_return(s);
                    n.push(applyOp(pop_and_return(n), pop_and_return(n), op));
                }
                if (n.empty() && !s.empty()) {
                    throw std::runtime_error("���������");
                }
                s.push(infix[i]);
            }
        }
        while (!s.empty()) {
            if (s.top() == '(' || s.top() == ')') {
                throw std::runtime_error("���Ų�ƥ��");
            }
            char op = pop_and_return(s);
            n.push(applyOp(pop_and_return(n), pop_and_return(n), op));
        }
        double result = pop_and_return(n);
        if (!n.empty()) {
            throw std::runtime_error("����������");
        }
        return result;
    }
    catch (const exception& e) {
        cout << "���ִ���: " << e.what() << '\n';
        return false;
    }
    return true;
}

bool evaluate(const string& infix, double& result) {
    try {
        result = evaluator(infix);
        return true;
    }
    catch (const exception& e) {
        cout << "An exception occurred: " << e.what() << '\n';
        return false;
    }
}

int main() {
    double result;
    vector<string> expressions = {
        // ��ȷ�ı��ʽ
        "3 + 4","6 - 2",
        "2 * 3","8 / 2",
        "3 + 5 * 2","(3 + 5) * 2",
        "10 / 2 + 3 - 1","3.5 + 2","10 - 5.5",
        "2 * (3 + 4) / 5",
        "1e2","1.5e-3","1.0E+5","1.2e1+3",
        // ����ı��ʽ
        "3 + * 4", // ȱ�ٲ�����
        "3 + ( 4", // ȱ�ٱ�����
        "3 + 4 *", // ����Ĳ�����
        "3 + 4 5", // ȱ�ٲ�����
        "3 ++ 4", // ����ļӺ�
        "3 + ( 4 * )", // �ձ��ʽ
        "3 + . . 4", // ���С����
        "3e++2", // ����Ŀ�ѧ������
        "3e-2.5", // ��ָ����������
        "3e", // ȱ��ָ��
        "3e-", // ȱ��ָ��
        "3.2.4", // �����С����ʹ��
        "3 + (4 * 5", // ���Ų�ƥ��
        "- - 3", // ��������
    };

    for (const string& expr : expressions) {
        cout << "������׺���ʽ: " << expr << endl;
        if (!evaluate(expr, result)) {
            cout << "���ʽ����: " << expr << endl;
        }
        else {
            cout << "Result: " << result << endl;
        }
    }
}