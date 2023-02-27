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
  std::map<std::string, int> count;
  std::string input;
  std::cout << "Enter the list of word and number: ";
  std::cin >> input;

  for (int i = 0; i < input.size(); i += 2) {
    std::string word = input.substr(i, 1);
    int number = input[i + 1] - '0';
    count[word] += number;
  }

  std::cout << "Results: " << std::endl;
  for (const auto &p : count) {
    std::cout << p.first << ": " << p.second << std::endl;
  }

  return 0;
}
