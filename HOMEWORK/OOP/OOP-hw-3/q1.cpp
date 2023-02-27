#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("data1.txt");
    if (!in)
    {
        cout << "Cannot open input file." << endl;
        return 1;
    }

    string line;
    getline(in, line);
    vector<vector<int>> nums(2, vector<int>());
    for (char c : line)
    {
        if (isdigit(c))
        {
            nums.back().push_back(c - '0');
        }
        else if (c == ' ')
        {
            continue;
        }
        else
        {
            nums.emplace_back();
        }
    }
    in.close();

    vector<int> combined;
    for (int i = 0; i < min(nums[0].size(), nums[1].size()); i++)
    {
        combined.push_back(nums[0][i]);
        combined.push_back(nums[1][i]);
    }
    for (int i = min(nums[0].size(), nums[1].size()); i < nums[0].size() + nums[1].size() - combined.size(); i++)
    {
        combined.push_back(nums[i / (nums[0].size() + nums[1].size() - combined.size())][i % (nums[0].size() + nums[1].size() - combined.size())]);
    }
    cout << "=================1.1================="
         << endl;
    for (int num : combined)
    {
        cout << num << " ";
    }
    cout << endl;

    int product = 1; // initialize product to 1
    cout << "=================1.2================="
         << endl;
    for (int i = 0; i < min(nums[0].size(), nums[1].size()); i++)
    {
        cout << nums[0][i] << " * " << nums[1][i] << " = " << nums[0][i] * nums[1][i] << endl;
        product *= nums[0][i] * nums[1][i]; // update product by multiplying
    }
    cout << product << endl;

    cout << "=================1.3================="
         << endl;
    for (int num1 : nums[0])
    {
        for (int num2 : nums[1])
        {
            cout << "(" << num1 << ", " << num2 << "), ";
        }
        cout << endl;
    }

    return 0;
}