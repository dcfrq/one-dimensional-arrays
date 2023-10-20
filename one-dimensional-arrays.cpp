#include <iostream>
#include <exception>

using namespace std;

//���������� ������, ��� ����, ����� main ����� ���� �������� ������
void inArray(int* arr, int size);
void outArray(int* array, int size);
bool isOrderArray(int* array, int size);
void permutationArray(int* array, int size);

int main() {
    setlocale(LC_ALL, "ru"); //������������

    const int SIZE = 5;
    int* array{ new int[SIZE] }; //������ � ������������ ������

    const int count = 10;
    int arr[count] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //���������� ������

    //���� try catch ��� ����� �������
    try {
        inArray(array, SIZE);
    }
    catch (exception& ex) {
        cerr << ex.what() << endl;
    }

    //���� �������� �� ���������� ������� � ������������ ������ � ����������� �������
    cout << endl << isOrderArray(array, SIZE) << endl;
    cout << endl << isOrderArray(arr, count) << endl;

    //���� ������������ ��������� ������� � ������������ ������ � ����������� �������
    permutationArray(array, SIZE);
    cout << endl;
    permutationArray(arr, count);
    cout << endl;

    //���� ������ ������� � ������������ ������ � ����������� �������
    outArray(array, SIZE);
    outArray(arr, count);

    delete[] array;
    return 0;
}

//������� ��� ����� �������
void inArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        if (cin.fail()) {
            throw exception("������ �����, ���� ������������� �������� ������� ");
        }
    }
}

//������� ��� ������ �������
void outArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}

//�������, �������� ���������� �������
bool isOrderArray(int* array, int size) {
    for (int i = 1; i < size; i++) {
        if (array[i - 1] > array[i]) {
            return false;
        }
    }
    return true;
}

//������� ��� ������������ ��������� � �������
void permutationArray(int* array, int size) {
    int lenght = size % 2 ? size - 1 : size;
    for (int i = 1; i < lenght; i += 2) {
        int tmp = array[i - 1];
        array[i - 1] = array[i];
        array[i] = tmp;
    }
}