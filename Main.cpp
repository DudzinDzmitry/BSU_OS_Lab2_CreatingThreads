#include <iostream>
#include <windows.h>

struct MetaArray {
    int *array;
    int length;
    int min;
    int max;
    int average;

    MetaArray(int *array, int length) : array(array), length(length), min(array[0]), max(array[0]), average(array[0]) {}
};

DWORD WINAPI Min_Max(LPVOID lpParameter) {}

DWORD WINAPI Average(LPVOID lpParam) {}

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

    MetaArray *metaArray;
    metaArray = new MetaArray(array, length);

    HANDLE min_max = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) Min_Max, LPVOID(metaArray), 0, NULL);
    if (min_max == NULL) return GetLastError();
    WaitForSingleObject(min_max, INFINITE);
    CloseHandle(min_max);

    HANDLE average = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) Average, LPVOID(metaArray), 0, NULL);
    if (average == NULL) return GetLastError();
    WaitForSingleObject(average, INFINITE);
    CloseHandle(average);

    array[metaArray->min] = metaArray->average;
    array[metaArray->max] = metaArray->average;
    delete metaArray;

    std::cout << "Массив, где наибольший и наименьший элеменеты были заменены средним арифметическим:\n";
    while (i < length) {
        std::cout << array[i] << " ";
        ++i;
    }
    delete[] array;

    system("pause");
    return 0;
}