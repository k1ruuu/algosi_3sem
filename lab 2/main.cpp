#include <iostream>
#include <string>
#include <stack>

bool is_valid(const std::string& str) {
    std::stack<char> s;

    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c); 
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty() || (c == ')' && s.top() != '(') ||
                (c == '}' && s.top() != '{') || (c == ']' && s.top() != '[')) {
                return false;
            }
            s.pop();
        }
    }

    return s.empty(); 
}

int getOperatorPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; 
}

double Operators(double op1, double op2, char op) {
    switch (op) {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        if (op2 == 0) {
            std::cerr << "Деление на 0!";
        }
        else {
            return op1 / op2;
        }
    default:
        return 0.0;
    }
}

// Функция для выполнения математических вычислений
double Calculations(std::string& str) {
    std::stack<double> ops;
    std::stack<char> operators;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            continue;
        }
        else if (isdigit(str[i])) {
            // Обработка чисел.
            double operand = 0;
            while (i < str.length() && (isdigit(str[i]))) {
                operand = operand * 10 + (str[i] - '0');
                i++;
            }
            i--;
            ops.push(operand);
        }
        // Обработка операторов.
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            while (!operators.empty() && getOperatorPriority(operators.top()) >= getOperatorPriority(str[i])) {
                double operand2 = ops.top();
                ops.pop();
                double operand1 = ops.top();
                ops.pop();
                char op = operators.top();
                operators.pop();
                double result = Operators(operand1, operand2, op);
                ops.push(result);
            }
            operators.push(str[i]);
        }
        // Обработка скобок
        else if (str[i] == '(') {
            operators.push(str[i]);
        }
        else if (str[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double operand2 = ops.top();
                ops.pop();
                double operand1 = ops.top();
                ops.pop();
                char op = operators.top();
                operators.pop();
                double result = Operators(operand1, operand2, op);
                ops.push(result);
            }
            operators.pop();
        }
        else if (str[i] == '=') {
            // Обработка равенства
            while (!operators.empty()) {
                double operand2 = ops.top();
                ops.pop();
                double operand1 = ops.top();
                ops.pop();
                char op = operators.top();
                operators.pop();
                double result = Operators(operand1, operand2, op);
                ops.push(result);
            }
        }
        else {
            std::cerr << "Неизвестный символ: " << str[i] << std::endl;
            exit(1);
        }
    }

    if (ops.size() == 1) {
        return ops.top();
    }
    else {
        std::cerr << "Неверное расположение операторов!" << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    std::string input;
    std::cout << "Введите математическое выражение: ";
    std::cin >> input;

    if (is_valid(input)) {
        double result = Calculations(input);
        std::cout << "Результат: " << result << std::endl;
    }
    else {
        std::cerr << "Неправильное расположение скобок!" << std::endl;
    }
}
