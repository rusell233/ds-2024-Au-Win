#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stack>
#include <stdexcept>
#include <string>
#include <limits>

double evaluator(const std::string& infix);
bool evaluate(const std::string& infix, double& result);

template <typename T>
T pop_and_return(std::stack<T>& s);

int precedence(char op);

double applyOp(double a, double b, char op);

int is_op(char c);

int is_legitimate(const std::string& infix);

bool in_Bds(size_t i, const std::string& infix);

#endif // CALCULATOR_H