#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout
            << "Данная программа находит наибольший, наименьший элементы массива и среднее арифметическое элементов массива.\n";

    std::cout << "Введите количество элементов в массиве:";
    int length;
    std::cin >> length;

    std::cout << "Введите элементы массива:\n";
    int *array = new int[length];
    int i = 0;
    while (i < length) {
        std::cin >> array[i];
        ++i;
    }
    system("pause");
    return 0;
}