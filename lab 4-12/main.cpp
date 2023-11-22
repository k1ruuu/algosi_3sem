#include <iostream>
#include <vector>

//lab 4
void combSort(std::vector<int>& arr) {
    int n = arr.size();
    int gap = n;

    while (gap > 1) {
        // Вычисляем новый интервал
        gap = (gap * 10) / 13;
        if (gap < 1) {
            gap = 1;
        }

        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
            }
        }
    }
}

//lab 5
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    std::vector<int> arr = { 199, 54, 23, 1, 2, 3, 6, 4, 9, 7, 32, 322 };

    /*std::cout << "Исходная последовательность: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    combSort(arr);

    std::cout << "Отсортированная последовательность: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;*/



    std::cout << "Исходная последовательность: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    insertionSort(arr);

    std::cout << "Отсортированная последовательность: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
