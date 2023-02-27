#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> colors;
    cout << "Enter colors: ";
    string color;
    while (cin >> color)
    {
        colors.push_back(color);
    }

    vector<string> starred;
    vector<string> plain;
    for (const auto &c : colors)
    {
        if (c.front() == '*' && c.back() == '*')
        {
            starred.push_back(c);
        }
        else
        {
            plain.push_back(c);
        }
    }

    for (const auto &s : starred)
    {
        for (const auto &p : plain)
        {
            cout << "(" << s << ", " << p << "), ";
        }
    }
    cout << endl;

    return 0;
}