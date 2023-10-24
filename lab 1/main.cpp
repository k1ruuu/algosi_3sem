#include <iostream>
#include <stack>
#include <string>

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

int main() {
    setlocale(LC_ALL, "rus");
    std::string input;
    std::cout << "Введите скобочное выражение: ";
    std::cin >> input;

    if (is_valid(input)) {
        std::cout << "Скобочное выражение правильное." << std::endl;
    }
    else {
        std::cout << "Скобочное выражение неправильное." << std::endl;
    }

    return 0;
}
