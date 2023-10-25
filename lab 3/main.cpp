#include <iostream>
#include <vector>

// Функция для определения количества множителей в числе n
int theNumberOfDividers(int n, int Divider) {
    int count = 0;
    while (n % Divider == 0) {
        n /= Divider;
        count++;
    }
    return count;
}

// Функция для вывода чисел, удовлетворяющих условию
void findNumbers(int x) {
    std::vector<int> result;

    for (int i = 1; i <= x; i++) {
        int number = i;
        int count3 = theNumberOfDividers(number, 3);
        int count5 = theNumberOfDividers(number, 5);
        int count7 = theNumberOfDividers(number, 7);

        if ((count3 >= 0 || count5 >= 0 || count7 >= 0) && (pow(3, count3) * pow(5, count5) * pow(7, count7)) == i) {
            result.push_back(i);
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
