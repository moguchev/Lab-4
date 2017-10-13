#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
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

int main()
{
    std::cout << " Enter the size of the array" << std::endl;
    int size_array = 0;
    std::cin >> size_array;
    std::vector<int> v = generate_random_vector<int>(size_array, -100, 50);
    std::cout << " New Array:" << std::endl;
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << ' ';
    std::cout << std::endl;
    int j = 0;
    int freebox = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        j = i;
        for (int k = 0; k < v.size(); ++k)
        {
            if (v[j] < v[k])
            {
                j = k;
            }
            freebox = v[i];
            v[i] = v[j];
            v[j] = freebox;
        }
    }
    /*
    for(int i = 0, t = 0; i < v.size()/2; ++i)
    {
        t = v[i];
        v[i] = v[v.size() - i - 1];
        v[v.size() - i - 1] = t;
    }
    */
    std::cout << " sort Array:" << std::endl;
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << ' ';
    std::cout << std::endl;
    system ("pause");
}
