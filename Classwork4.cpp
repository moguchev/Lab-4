#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
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
    // 1
    int N = 0;
    std::vector<int> v = generate_random_vector<int>(N, -100, 50);
    std::cout << " New Array:" << std::endl;
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << ' ';
std::cout << std::endl;
