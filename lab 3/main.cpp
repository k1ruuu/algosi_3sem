#include <iostream>
#include <vector>

// Функция для вывода чисел, удовлетворяющих условию
void findNumbers(int x) {
    std::vector<int> result;

    for (int k = 0; k <= 10; k++) { // Пусть K, L, M могут быть от 0 до 10
        for (int l = 0; l <= 10; l++) {
            for (int m = 0; m <= 10; m++) {
                if (pow(3, k) * pow(5, l) * pow(7, m) <= x) {
                    result.push_back(pow(3, k) * pow(5, l) * pow(7, m));
                }
                else {
                    break;
                }
            }
        }
    }

    std::cout << "Числа, удовлетворяющие условию:";
    for (int num : result) {
        std::cout << " " << num;
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    int x;
    std::cout << "Введите число x: ";
    std::cin >> x;

    findNumbers(x);

    return 0;
}
