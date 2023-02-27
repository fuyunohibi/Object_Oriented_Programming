#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Input:
// C *C++* Rust* *Python* * *Java

string unstylize(string m){

    // remove "*" 
    if (m.front() == '*' && m.back() == '*' && m.size() > 1){
        m.erase(0, 1);
        m.erase(m.size() - 1, 1);
    }

    return m;
}

auto split(string m, char d){
    vector<string> result;
    string line;
    stringstream stream(m);

    while (getline(stream, line, d)){
        result.push_back(line);
    }

    return result;
}



int main(){

    string m;
    cout << "Please Enter the strings: ";
    getline(cin, m);
    auto words = split(m, ' ');

    // Question 1.1
    for (const auto& w: words) {
        cout << unstylize(w) << " ";
    }
    cout << endl;


    // Question 1.2
    auto words2 = words;
    reverse(words2.begin(), words2.end());
    for (const auto& w: words2) {
        cout << unstylize(w) << " ";
    }
    cout << endl;


    // Question 1.3
    auto words3 = words;
    vector<string> new_vec;
    
    for (const auto& w: words3) {
        new_vec.push_back(unstylize(w));
    }

    sort(new_vec.begin(), new_vec.end());
    for (const auto& w: new_vec) {
        cout << w << " ";
    }
}

