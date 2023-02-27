#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::cout;
using std:: cin;
using std:: endl;
using std:: string;
using std:: vector;
using std:: map;

int main() {
    map<string, vector<int>> word_numbers;
    string input;
    cout << "Enter the list of word and number: ";
    cin >> input;

    for (int i = 0; i < input.length(); i += 2) {
        string word = input.substr(i, 1);
        int number = input[i + 1] - '0'; // turn ascii to number
        cout << number << endl;  
        word_numbers[word].push_back(number);
    }

    for (const auto &pair : word_numbers) {
        cout << pair.first << ": ";
        for (int num : pair.second) {
            cout << num << ", ";
        }
        cout << std::endl;
    }

    return 0;
}