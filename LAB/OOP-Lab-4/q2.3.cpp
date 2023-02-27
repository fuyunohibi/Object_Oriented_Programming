#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

template <class T>
string str_join(string sep, T begin, T end)
{
    string str;
    for (auto it = begin; it != end; it++) {
        str += *it;
        if (next(it) != end) {
            str += sep;
        }
    }
    return str;
}


int main() {
    auto words = vector<string>{"C", "Rust", "C++", "Python"};
    auto str1 = str_join(string(", "), words.begin(), words.end());
    auto words2 = list<string>(words.rbegin(), words.rend());
    auto str2 = str_join(string(", "), words2.begin(), words2.end());

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
}
