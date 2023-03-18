#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
#include <list>

using namespace std;

struct PersonStruct
{
    vector<string> name;
    vector<int> age;
};

class Person
{
public:
    // =============Ascending Order Name=============
    void ascending_order_name(PersonStruct &people)
    {

        cout << "\n"
             << "The Initialize name: ";
        for (int i = 0; i < people.name.size(); i++)
        {
            if (i == (people.name.size() - 1))
            {
                cout << people.name[i];
            }
            else
            {
                cout << people.name[i] << ", ";
            }
        }
        cout << endl;

        sort(people.name.begin(), people.name.end());

        cout << "The ascending order name: ";

        for (int i = 0; i < people.name.size(); i++)
        {
            if (i == (people.name.size() - 1))
            {
                cout << people.name[i];
            }
            else
            {
                cout << people.name[i] << ", ";
            }
        }

        cout << "\n\n";
    }

    // =============Descending Order Name=============
    void descending_order_name(PersonStruct &people)
    {
        cout << "The Initialize name: ";
        for (int i = 0; i < people.name.size(); i++)
        {
            if (i == (people.name.size() - 1))
            {
                cout << people.name[i];
            }
            else
            {
                cout << people.name[i] << ", ";
            }
        }
        cout << endl;

        sort(people.name.begin(), people.name.end(), greater<string>());

        cout << "The descending order name: ";
        for (int i = 0; i < people.name.size(); i++)
        {
            if (i == (people.name.size() - 1))
            {
                cout << people.name[i];
            }
            else
            {
                cout << people.name[i] << ", ";
            }
        }

        cout << "\n\n";
    }

    // =============Ascending Order Age=============
    void ascending_order_age(PersonStruct &people)
    {
        cout << "The Initialize age: " << endl;
        for (int i = 0; i < people.age.size(); i++)
        {
            if (i == (people.age.size() - 1))
            {
                cout << people.age[i];
            }
            else
            {
                cout << people.age[i] << ", ";
            }
        }
        cout << endl;

        sort(people.age.begin(), people.age.end());

        cout << "The ascending order age: " << endl;
        for (int i = 0; i < people.age.size(); i++)
        {
            if (i == (people.age.size() - 1))
            {
                cout << people.age[i];
            }
            else
            {
                cout << people.age[i] << ", ";
            }
        }
        cout << "\n\n";
    }

    // =============Descending Order Age=============
    void descending_order_age(PersonStruct &people)
    {
        cout << "The Initialize age: " << endl;
        for (int i = 0; i < people.age.size(); i++)
        {
            if (i == (people.age.size() - 1))
            {
                cout << people.age[i];
            }
            else
            {
                cout << people.age[i] << ", ";
            }
        }

        cout << endl;

        sort(people.age.begin(), people.age.end(), greater<int>());

        cout << "The descending order age: " << endl;

        for (int i = 0; i < people.age.size(); i++)
        {
            if (i == (people.age.size() - 1))
            {
                cout << people.age[i];
            }
            else
            {
                cout << people.age[i] << ", ";
            }
        }
        cout << "\n\n";
    }

    void makeMap(PersonStruct &people)
    {
        // mapping string and integer

        map<string, int> myMap;

        cout << setw(10) << left << "NAME" << setw(6) << right << "AGE" << endl;

        for (int i = 0; i < people.name.size(); i++)
        {
            myMap[people.name[i]] = people.age[i];
        }

        for (auto const &pair : myMap)
        {
            cout << setw(10) << left << pair.first << setw(6) << right << pair.second << "\n";
        }
    }

    void extract_names(PersonStruct &people)
    {
        map<string, int> myMap;

        for (int i = 0; i < people.name.size(); i++)
        {
            myMap[people.name[i]] = people.age[i];
        }

        vector<string> name;
        for (auto const &pair : myMap)
        {
            name.push_back(pair.first);
        }

        cout << "\n"
             << "The names: ";

        for (int i = 0; i < name.size(); i++)
        {
            if (i == (name.size() - 1))
            {
                cout << name[i];
            }
            else
            {
                cout << name[i] << ", ";
            }
        }
    }

    void extract_ages(PersonStruct &people)
    {
        map<int, string> myMap;

        for (int i = 0; i < people.name.size(); i++)
        {
            myMap[people.age[i]] = people.name[i];
        }

        vector<int> age;
        for (auto const &pair : myMap)
        {
            age.push_back(pair.first);
        }

        cout << "\n"
             << "The ages: ";

        for (int i = 0; i < age.size(); i++)
        {
            if (i == (age.size() - 1))
            {
                cout << age[i];
            }
            else
            {
                cout << age[i] << ", ";
            }
        }
    }
};

int main()
{
    PersonStruct a;
    a.name = {"Liam", "Noah", "James", "Petch", "Tawan", "Arm", "Capt", "Sugar", "Matt", "Phoom"};
    a.age = {2, 3, 4, 5, 6, 7, 7, 8, 8, 9};

    Person people;
    people.ascending_order_name(a);
    people.descending_order_name(a);
    people.ascending_order_age(a);
    people.descending_order_age(a);

    people.makeMap(a);
    people.extract_names(a);
    people.extract_ages(a);

    return 0;
}
