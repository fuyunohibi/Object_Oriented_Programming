#include <iostream>

void inverse_numbers(double *v, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        v[i] = -v[i];
    }
}

int main()
{
    double set_of_nums[] = {0, -1, -2, -3, -4, -5, -6, -7, -8, -9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    size_t n = sizeof(set_of_nums) / sizeof(double);

    // starting from v(.data() which is a pointer to the first element of the array)
    // replace n numbers with their negative values which is (.size() which is the number of elements in the array)
    std::cout << set_of_nums[0] << std::endl;
    std::cout << n << std::endl;

    inverse_numbers(set_of_nums, n);

    std::cout << "==========================Q1.1==========================" << std::endl;

    for (size_t i = 0; i < n; i++)
    {
        std::cout << set_of_nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
