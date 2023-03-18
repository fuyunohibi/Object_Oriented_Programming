#include <iostream>
#include <vector>

using namespace std;

// ========================Start::1.4========================

// create_pairs function taking a C-style array as parameter
vector<pair<double, double>> create_pairs(const double arr[], const int size)
{
    vector<pair<double, double>> pairs;
    for (int i = 0; i < size - 1; i += 2)
    {
        pairs.push_back(make_pair(arr[i], arr[i + 1]));
    }
    return pairs;
}

int main()
{
    // C-style array
    double data[] = {1.2, 2.3, 5, 2, 1.1, 3, 7};
    int size = sizeof(data) / sizeof(data[0]);

    // create pairs from C-style array
    vector<pair<double, double>> pairs = create_pairs(data, size);

    // print the pairs
    for (const auto &p : pairs)
    {
        cout << "Pair: {" << p.first << ", " << p.second << "}" << endl;
    }

    return 0;
}

// ========================End::1.4========================
