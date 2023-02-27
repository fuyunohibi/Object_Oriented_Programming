#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_prime(int n)
{
    if (n == 2 || n ==3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    // check through all numbers of the form i = 6k - 1 and i = 6k + 1
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false; // n is divisible by i or i + 2
    }
    return true; // no divisor within [5, n) found
}

template <class T>
T median(std::vector<T> vec)
{
    using std::sort;
    using std::vector;
    sort(vec.begin(), vec.end());
    const auto size = vec.size();
    const auto mid = size / 2;
    if (size % 2 == 0) {
        return ((vec[mid] + vec[mid - 1]) / 2);
    }
    else {
        return vec[mid];
    }
    
}

int main()
{
    // vector<int> vec1 = {1, 3, 3, 6, 7, 8, 9};
    // vector<float> vec2 = {1, 2, 3, 4, 5, 6, 8, 9};
    // cout << median(vec1) << endl;
    // cout << median(vec2) << endl;

    // cout << "Enter the upper limit: ";
    // int n;
    // cin >> n;
    // for (int i = 2; i <= n; i++) {
    //     if (is_prime(i))
    //         cout << i << endl;
    }
    // return 0;
}