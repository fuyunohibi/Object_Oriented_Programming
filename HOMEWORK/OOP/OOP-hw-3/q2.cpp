#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

auto split(const string &s, const string &delim)
{
    vector<string> result;
    size_t start = 0;
    size_t end = s.find(delim);
    while (end != string::npos)
    {
        result.push_back(s.substr(start, end - start));
        start = end + delim.length();
        end = s.find(delim, start);
    }
    result.push_back(s.substr(start, end));
    return result;
}

int main()
{
    ifstream in("data3.txt");
    if (!in)
    {
        cout << "Cannot open input file." 
        << endl;
        return 1;
    }

    string line;
    vector<string> lines;
    while (getline(in, line))
    {
        lines.push_back(line);
    }

    in.close();

    vector<string> nums_nonsplit;
    nums_nonsplit = split(lines[0], "; ");

    vector<vector<string>> nums;

    for (int i = 0; i < nums_nonsplit.size(); i++)
    {
        nums.push_back(split(nums_nonsplit[i], " "));
    }

    cout << "=================2.1=================" 
    << endl;

    for (int i = 0; i < nums.size(); i++)
    {
        double sum = 0;
        for (int j = 0; j < nums[i].size(); j++)
        {
            sum += std::stod(nums[i][j]);
        }
        cout << sum / nums[i].size() << " ";
    }

    cout << endl
         << endl
         << "=================2.2=================" 
         << endl;

    for (int i = 0; i < nums[0].size(); i++)
    {
        for (int j = 0; j < nums[1].size(); j++)
        {
            for (int k = 0; k < nums[2].size(); k++)
            {
                cout << "(" << nums[0][i] << ", " << nums[1][j] << ", " << nums[2][k] << ") ";
            }
            cout << endl;
        }
    }

    return 0;
}