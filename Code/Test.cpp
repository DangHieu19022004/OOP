#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int evaluateExpression(const std::string& expression) {
    std::stack<int> values;
    std::stack<char> ops;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];
        if (isdigit(c)) {
            int num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                ++i;
            }
            values.push(num);
            --i;
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                if (op == '+')
                    values.push(val1 + val2);
                else if (op == '-')
                    values.push(val1 - val2);
                else if (op == '*')
                    values.push(val1 * val2);
            }
            if (!ops.empty() && ops.top() == '(') ops.pop(); // Remove '(' from the stack
        } else if (c == '+' || c == '-' || c == '*') {
            while (!ops.empty() && ops.top() != '(' &&
                   ((c == '*' || c == '/') && (ops.top() == '*' || ops.top() == '/'))) {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                if (op == '+')
                    values.push(val1 + val2);
                else if (op == '-')
                    values.push(val1 - val2);
                else if (op == '*')
                    values.push(val1 * val2);
            }
            ops.push(c);
        }
    }

    while (!ops.empty()) {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        if (op == '+')
            values.push(val1 + val2);
        else if (op == '-')
            values.push(val1 - val2);
        else if (op == '*')
            values.push(val1 * val2);
    }

    return values.top();
}

int main() {
    std::string expression = "3+(4 - abs(-5))*6";
    int result = evaluateExpression(expression);
    std::cout << "Kết quả: " << result << std::endl;
    return 0;
}
