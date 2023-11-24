#include <iostream>
#include <cmath>
#include <stack>
#include <string>

using namespace std;

double calculateExpression(const string& expression) {
    stack<double> operands;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); ++i) {
        if (expression[i] == ' ') {
            continue;
        } else if (isdigit(expression[i])) {
            string operandStr = "";
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                operandStr += expression[i];
                i++;
            }
            i--;

            double operand = stod(operandStr);
            operands.push(operand);
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char oper = operators.top();
                operators.pop();

                double operand2 = operands.top();
                operands.pop();

                double operand1 = operands.top();
                operands.pop();

                if (oper == '+') {
                    operands.push(operand1 + operand2);
                } else if (oper == '-') {
                    operands.push(operand1 - operand2);
                } else if (oper == '*') {
                    operands.push(operand1 * operand2);
                } else if (oper == '/') {
                    operands.push(operand1 / operand2);
                }
            }
            operators.pop(); // Remove '(' from stack
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!operators.empty() && (expression[i] == '*' || expression[i] == '/') &&
                   (operators.top() == '*' || operators.top() == '/')) {
                char oper = operators.top();
                operators.pop();

                double operand2 = operands.top();
                operands.pop();

                double operand1 = operands.top();
                operands.pop();

                if (oper == '*') {
                    operands.push(operand1 * operand2);
                } else if (oper == '/') {
                    operands.push(operand1 / operand2);
                }
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        char oper = operators.top();
        operators.pop();

        double operand2 = operands.top();
        operands.pop();

        double operand1 = operands.top();
        operands.pop();

        if (oper == '+') {
            operands.push(operand1 + operand2);
        } else if (oper == '-') {
            operands.push(operand1 - operand2);
        } else if (oper == '*') {
            operands.push(operand1 * operand2);
        } else if (oper == '/') {
            operands.push(operand1 / operand2);
        }
    }

    return operands.top(); // The final result will be on top of the operand stack
}

int main() {
    string input = "3+(4 - abs(-5))*6";

    double result = calculateExpression(input);

    cout << "Result: " << result << endl;

    return 0;
}

