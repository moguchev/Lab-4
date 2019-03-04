#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>
#include <vector>

template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);

    auto lambda = [&e2, &dist]() -> T { return dist(e2); };

    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}
// Функция вывода массива
void print_array(int *pM, int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << pM[i] << ' ';
    std::cout << std::endl;
}
// Функция вывода вектора
void print_vector(const std::vector<int>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
// Сортировка массива (долгая)
void sort_array(int *pM, int size)
{
    for (int i = 0, j = 0, temp = 0; i < size; ++i)
    {
        j = i;
        for (int k = 0; k < size; ++k)

        {            if (pM[j] < pM[k])  // < в порядке возрастания, > в порядке убывания
            {
                j = k;
            }
            temp = pM[i];
            pM[i] = pM[j];
            pM[j] = temp;
        }
    }
}
// Сортировка вектора методом пузырька улучшенная
void sort_vector_puz_mod(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        bool flag = true;
        for (int j = 0; j < vec.size() - i - 1; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                flag = false;
            }
        }
        if (flag) break;
    }
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
}
// Зеркальное отображение вектора
void reverse_vector(std::vector<int> & vec)
{
    for (int i = 0, tpm = 0; i < vec.size() / 2; ++i)
    {
        tpm = vec[i];
        vec[i] = vec[vec.size() - i - 1];
        vec[vec.size() - i - 1] = tpm;
    }
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
    print_array(array, size);
    reverse_array(array, size);
    print_array(array, size);
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
    print_array(array1, size1);
    reverse_array(array1, size1);
    print_array(array1, size1);
    // Задание массива через вектор и его вывод
    std::vector<int> v = generate_random_vector<int>(10, -10, 50);
    std::cout << " New Array:" << std::endl;
    print_vector(v);
    sort_vector_puz_mod(v);
    print_vector(v);
    reverse_vector(v);
    print_vector(v);
    system("pause");
}
