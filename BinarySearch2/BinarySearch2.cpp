// BinarySearch2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <vector>

bool Sorted(std::vector<int> array) {
    for (int i = 1; i < array.size(); i++) {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }
    return true;
}

void Sort(std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++)
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[i]) {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
}

int BinarySearch(std::vector<int> array, int value) {

    if (!Sorted(array))
        Sort(array);

    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    int Left = 0;
    int Right = array.size();
    int Middle;
    while (Left < Right) {
        Middle = (Left + Right) / 2;
        if (value >= array[Middle]) Left = Middle + 1;
        else Right = Middle;
    }
    --Left;
    if (Left < 0 || array[Left] != value)  return -1;
    return Left;
}

int main()
{
    std::vector<int> a{ 10,2,0,14,43,25,18,1,5,45 };
    std::cout << BinarySearch(a, 25) << std::endl;
    std::vector<int> b{ 3, 6 , 13, 28, 54, 83, 97 };
    std::cout << BinarySearch(b, 2) << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
