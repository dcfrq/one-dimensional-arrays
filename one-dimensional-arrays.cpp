#include <iostream>
#include <exception>

using namespace std;

//Объявление функий, для того, чтобы main можно было оставить сверху
void inArray(int* arr, int size);
void outArray(int* array, int size);
bool isOrderArray(int* array, int size);
void permutationArray(int* array, int size);

int main() {
    setlocale(LC_ALL, "ru"); //Локиализация

    const int SIZE = 5;
    int* array{ new int[SIZE] }; //Массив в динамической памяти

    const int count = 10;
    int arr[count] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //Встроенный массив

    //Блок try catch для ввода массива
    try {
        inArray(array, SIZE);
    }
    catch (exception& ex) {
        cerr << ex.what() << endl;
    }

    //Блок проверки на сортировку массива в динамической памяти и встроенного массива
    cout << endl << isOrderArray(array, SIZE) << endl;
    cout << endl << isOrderArray(arr, count) << endl;

    //Блок перестановки элементов массива в динамической памяти и встроенного массива
    permutationArray(array, SIZE);
    cout << endl;
    permutationArray(arr, count);
    cout << endl;

    //Блок вывода массива в динамической памяти и встроенного массива
    outArray(array, SIZE);
    outArray(arr, count);

    delete[] array;
    return 0;
}

//Функция для ввода массива
void inArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        if (cin.fail()) {
            throw exception("Ошибка ввода, надо целочисленные значения вводить ");
        }
    }
}

//функция для вывода массива
void outArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}

//Функция, проверка сортировки массива
bool isOrderArray(int* array, int size) {
    for (int i = 1; i < size; i++) {
        if (array[i - 1] > array[i]) {
            return false;
        }
    }
    return true;
}

//Функция для перестановки слогаемых в массиве
void permutationArray(int* array, int size) {
    int lenght = size % 2 ? size - 1 : size;
    for (int i = 1; i < lenght; i += 2) {
        int tmp = array[i - 1];
        array[i - 1] = array[i];
        array[i] = tmp;
    }
}