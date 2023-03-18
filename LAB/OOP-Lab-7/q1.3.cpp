#include <iostream>
#include <vector>
#include <utility> // for pair

using namespace std;

// ========================Start::1.3========================

vector<pair<double, double>> create_pairs(const vector<double> &arr)
{
    vector<pair<double, double>> pairs;
    for (int i = 0; i < arr.size() - 1; i += 2)
    {
        pairs.push_back(make_pair(arr[i], arr[i + 1]));
    }
    return pairs;
}

int main()
{
    vector<double> data{1.2, 2.3, 5, 2, 1.1, 3, 7};
    vector<pair<double, double>> pairs = create_pairs(data);
    cout << "Pairs: { " << endl;

    for (int i = 0; i < pairs.size(); i++)
    {
        cout << "    {" << pairs[i].first << " " << pairs[i].second << "}";
        if (i != pairs.size() - 1)
        {
            cout << "," << endl;
        }
        else
        {
            cout << endl;
        }
    }
    cout << "}" << endl;
    return 0;
}

// ========================End::1.3========================