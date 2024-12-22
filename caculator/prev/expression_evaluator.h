#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include <string>
#include <vector>
#include <stack>

class ExpressionEvaluator {
public:
    // ������׺���ʽ��ֵ
    double evaluate(const std::string& infix);

private:
    // ���ز����������ȼ�
    int precedence(char op);
    // Ӧ�ò�������������������
    double applyOp(double a, double b, char op);
    // ����ַ��Ƿ��ǲ�����
    bool isOperator(char c);
    // ����ַ����Ƿ�����Ч������
    bool isValidNumber(const std::string& s);
    // ����׺���ʽת��Ϊ��׺���ʽ
    std::vector<std::string> infixToPostfix(const std::string& infix);
    // �����׺���ʽ��ֵ
    double evaluatePostfix(const std::vector<std::string>& postfix);
};

#endif // EXPRESSION_EVALUATOR_H