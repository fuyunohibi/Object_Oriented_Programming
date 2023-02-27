#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


template <class T>
T remove_negative(T& vec)
{   
    T vec2;
    copy(vec.begin(), vec.end(), std::back_inserter(vec2));
    vec2.erase(remove_if(vec2.begin(), vec2.end(), [](double x){return x < 0;}), vec2.end());
    return vec2;
}


int main() {
    vector<double> vec1 = {0.8, -5.1, 1.6, -6.5, 10.5};
    auto vec2 = remove_negative(vec1);

    cout << "vec1: ";
    for(auto element: vec1) cout << element << "  ";

    cout << endl;

    cout << "vec2: ";
    for(auto element: vec2) cout << element << "  ";

    cout << endl;
    //list
    cout << "li1: ";
    list<double> li1(vec1.rbegin(), vec1.rend());
    for(auto element: li1) cout << element << "  ";

    cout << endl;

    cout << "li2: ";
    auto li2 = remove_negative(li1);
    for(auto element: li2) cout << element << "  ";

    return 0;
}