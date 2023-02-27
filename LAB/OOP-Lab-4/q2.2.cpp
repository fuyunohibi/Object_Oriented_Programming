#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template <class T>
bool all_zeroes(T begin, T end) {
    return all_of(begin, end, [](int x){return x == 0;});
}
int main() {
    vector<int> vec1{1, 0, 2, 3};
    vector<int> vec2(10);

    bool z1 = all_zeroes(vec1.begin(), vec1.end());
    bool z2 = all_zeroes(vec2.begin(), vec2.end());

    list<int> li1(vec1.rbegin(), vec1.rend());
    list<int> li2(10);

    bool zz1 = all_zeroes(li1.begin(), li1.end());
    bool zz2 = all_zeroes(li2.begin(), li2.end());
    cout << z1 << endl;
    cout << z2 << endl;
    cout << zz1 << endl;
    cout << zz2 << endl;
    return 0;
}