#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>

// Функция вывода массива
void print_array(int *pM, int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << pM[i] << ' ';
    std::cout << std::endl;
}
// Сортировка массива (долгая)
void sort_array(int *pM, int size)
{
    for (int i = 0, j = 0, temp = 0; i < size; ++i)
    {
        j = i;
        for (int k = 0; k < size; ++k)
        {
            if (pM[j] < pM[k])  // < в порядке возрастания, > в порядке убывания
            {
                j = k;
            }
            temp = pM[i];
            pM[i] = pM[j];
            pM[j] = temp;
        }
    }
    for (int i = 0; i < size; ++i)
        std::cout << pM[i] << ' ';
    std::cout << std::endl;
}
// Сортировка массива методом пузырька
void sort_array_puz(int *pM, int size)
{
    for (int i = 0, temp = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (pM[j] > pM[j + 1])
            {
                temp = pM[j];
                pM[j] = pM[j + 1];
                pM[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; ++i)
        std::cout << pM[i] << ' ';
    std::cout << std::endl;
}
// Сортировка массива методом пузырька улучшенная
void sort_array_puz_mod(int *pM, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        bool flag = true;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (pM[j] > pM[j + 1])
            {
                int temp = pM[j];
                pM[j] = pM[j + 1];
                pM[j + 1] = temp;
                flag = false;
            }
        }
        if (flag) break;
    }
    for (int i = 0; i < size; ++i)
        std::cout << pM[i] << ' ';
    std::cout << std::endl;
}
// Зеркальное отображение массива
void reverse_array(int *pM, int size)
{
    for (int i = 0, tpm = 0; i < size / 2; ++i)
    {
        tpm = pM[i];
        pM[i] = pM[size - i - 1];
        pM[size - i - 1] = tpm;
    }
    for (int i = 0; i < size; ++i)
        std::cout << pM[i] << ' ';
    std::cout << std::endl;
}
int main()
{
    // Задание динамического массива c клавиатуры
    std::cout << " Enter size of new array " << std::endl;
    int size = 0;
    std::cin >> size;
    int *array = new int[size];
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
    print_array(array, size);
    sort_array_puz(array, size);
    reverse_array(array, size);
    // Задание динамического массива случайными значениями
    srand(time(0));
    std::cout << " Enter size of new array " << std::endl;
    int size1 = 0;
    std::cin >> size1;
    int *array1 = new int[size1];
    for (int i = 0; i < size1; i++)
    {
        array1[i] = (rand()%10 + 1);
    }
    print_array(array1, size1);
    sort_array_puz_mod(array1, size1);
    reverse_array(array1, size1);
    system("pause");
}
