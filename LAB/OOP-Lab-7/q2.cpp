#include <vector>
#include <array>
template <class T>
using Vec = std::vector<T>;
template <class C>
Vec<Vec<double>> create_ragged_array(const C &c, double val)
{
    Vec<Vec<double>> out;
    for (auto n : c)
        out.emplace_back(n, val);
    return out;
}

template <class C>
double **create_ragged_array_no_vec(const C &c, double val)
{
    auto out = new double *[c.size()];
    int i = 0;
    for (auto n : c)
    {
        out[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            out[i][j] = val;
        }
        i++;
    }
    return out;
}

class Ragged_array
{
public:
    Ragged_array() = default;
    Ragged_array(const Vec<Vec<double>> &data)
    {
        for (auto v : data)
        {
            Vec<double> row;
            for (auto x : v)
            {
                row.push_back(x);
            }
            this->data.push_back(row);
        }
    }
    Ragged_array(const Ragged_array &other)
    {
        for (auto v : other.data)
        {
            Vec<double> row;
            for (auto x : v)
            {
                row.push_back(x);
            }
            this->data.push_back(row);
        }
    }
    ~Ragged_array()
    {
        for (auto &v : data)
        {
            v.clear();
        }
        data.clear();
    }
    Vec<Vec<double>> data;

    template <class C>
    Ragged_array copy_ragged_array(const C &c)
    {
        Vec<Vec<double>> out;
        for (auto v : c)
        {
            Vec<double> row;
            for (auto x : v)
            {
                row.push_back(x);
            }
            out.push_back(row);
        }
        return Ragged_array(out);
    }

    void del_ragged_array()
    {
        for (auto &v : this->data)
        {
            v.clear();
        }
        this->data.clear();
    }

    auto Data() -> decltype(data)
    {
        return this->data;
    }
};

#include <iostream>
using namespace std;
int main()
{
    auto dims = {2, 5, 3};
    auto rg_arr = create_ragged_array(dims, 1.3);
    for (const auto &v : rg_arr)
    {
        for (auto x : v)
            std::cout << ' ' << x;
        std::cout << '\n';
    }
    std::cout << std::endl;

    cout << "====================2.1====================" << endl;

    double **rg_arr2 = create_ragged_array_no_vec(dims, 1.3);
    int i = 0;
    while (i < dims.size())
    {
        double *row = *rg_arr2;
        while (*row != 0)
        {
            cout << *row << ' ';
            row++;
        }
        cout << endl;
        rg_arr2++;
        i++;
    }

    cout << "====================2.2====================" << endl;
    std::array<std::size_t, 3> dims_1{2, 6, 4};
    Vec<Vec<double>> data{
        {1.2, 2.3},
        {5, 2, 1.1, 3, 7},
        {4.2, 2.3, 3.5}};
    auto rg_arr3 = Ragged_array(create_ragged_array(dims_1, 0.5));
    auto rg_arr4 = Ragged_array(data);

    for (const auto &v : rg_arr3.Data())
    {
        for (auto x : v)
            std::cout << ' ' << x;
        std::cout << '\n';
    }

    for (const auto &v : rg_arr4.Data())
    {
        for (auto x : v)
            std::cout << ' ' << x;
        std::cout << '\n';
    }

    // print rg_arr3, rg_arr4
    rg_arr4.del_ragged_array();
    rg_arr3.del_ragged_array();

    cout << "====================2.3====================" << endl;

    Ragged_array rg_arr5;

    auto rg_arr6 = rg_arr5.copy_ragged_array(create_ragged_array(dims_1, 0.5));
    for (const auto &v : rg_arr6.Data())
    {
        for (auto x : v)
            std::cout << ' ' << x;
        std::cout << '\n';
    }
}