#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <typeinfo>
#include <list>
#include <random>
#include <fstream>

using namespace std;


// Start::1.1

// remove 
// template <typename T>
// void lshift(vector<T> &v, int n)
// {
//     for (int i = 0; i < n; ++i)
//         if (v.size() > 0)
//         {
//             v.erase(v.begin());
//         }
// }

// // insert 0
// template <typename T>
// void rshift(vector<T> &v, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         v.insert(v.begin(), 0);
//     }
// }

// int main()
// {
//     vector<double> vec{2, 1, 4, 3, 7};
//     lshift(vec, 3);
//     for (int i = 0; i < vec.size(); i++)
//     {
//         cout << vec[i] << " ";
//     }
//     cout << endl;
//     rshift(vec, 2);
//     for (int i = 0; i < vec.size(); i++)
//     {
//         cout << vec[i] << " ";
//     }
//     return 0;
// }
// End::1.1



// Start::1.2

// template <typename T>
// void remove_negative(vector<T> &v) { 
      
//     v.erase( remove_if( v.begin(), v.end(), [](int i){ return i < 0; } ), v.end() );
     
// };

// int main() {
//     vector<double> vec = {0.8, -5.1, 1.6, -6.5, 10.5};
//     remove_negative(vec);
//     for(int i = 0; i<vec.size(); i++) {
//         cout << vec[i] << " ";
//     }
//     return 0;
// }

// End::1.2



// Start::1.3

// template <typename T>
// vector<double> scale(vector<T> &v, double n) { 
//     double multiple = n;
//     for(int i = 0; i<v.size(); i++) {
//         v[i] *= multiple;
//     }
//     return v;
// };

// template <typename T>
// vector<double> add(vector<T> &v1, vector<T> &v2) { 
//     vector<double> new_vec = v2;
//     for(int i = 0; i<v1.size(); i++) {
//         new_vec[i] += v1[i];
//     }
    
//     return new_vec;
// };

    

// int main() {
//     vector<double> vec1{2, 1, 4, 3, 7};
//     vector<double> vec2{1, 3, 2, 5};

//     auto vec3 = scale(vec1, 1.5);
//     for(int i = 0; i<vec3.size(); i++) {
//         cout << vec3[i] << " ";
//     }
//     cout << endl;
//     cout << vec3[1] << endl;
    
   

//     auto vec4 = add(vec2, vec3);
//     for(int i = 0; i<vec4.size(); i++) {
//         cout << vec4[i] << " ";
//     }

//     cout << endl;

//     for(int i = 0; i < vec3.size(); i++) {
//         cout << vec3[i] << " ";
    
//     }

//     cout << endl;

//     vector<double> new_vec = scale(vec2, -2.2);
//     auto vec5 = add(vec3, new_vec);
//     for(int i = 0; i<vec5.size(); i++) {
//         cout << vec5[i] << " ";
//     }

//      auto vec4 = add(vec2, vec3);
//      for(int i = 0; i<vec4.size(); i++) {
//      cout << vec4[i] << " ";
// }

//      for(int i = 0; i<vec5.size(); i++) {
//      cout << vec5[i] << " ";
//      return 0;
// }
// End::1.3



// Start::1.4

// template <typename T>
// void remove_negative(list<T> &v) { 
      
//     v.erase( remove_if( v.begin(), v.end(), [](int i){ return i < 0; } ), v.end() );
     
// };

// int main() {
//     double n;
//     list<double> list1 = {0.8, -5.1, 1.6, -6.5, 10.5};
//     remove_negative(list1);

//     list<double>::iterator myitr;
//     for (myitr = list1.begin(); myitr != list1.end(); ++myitr) {
//         cout << *myitr << endl;
//     }   

// }

// Ends 1.4



// Start::2.0


// void wordsTypeFunction(vector<string> &vec) {

//     vector<string> attr, non_attr;
    
//     cout << "Test words: ";
//     for(int i = 0; i < vec.size(); i++) {
//         cout << vec[i] << " ";
//     }

//     for(const auto& v: vec) {
//         if(v[0] == '[' && v[1] == '[' && v[v.size() - 1] == ']' && v[v.size() - 2] == ']') {
//             attr.push_back(v);
//         }
//         else {
//             non_attr.push_back(v);
//         }
//     }
//     cout << endl;
//     cout << "Attribute: ";
//     for(const auto& v: attr) {
//         cout << v << " ";

//     }
//     cout << endl;
//     cout << "Non-Attribute: ";
//     for(const auto& v: non_attr) {
//         cout << v << " ";
//     }

// }

// int main() {
//     const vector<string> test_words {
//         "switch", "[[noreturn]]",
//         "if", "[[maybe_unused",
//         "for", "[[fallthrough]]"
//     };
    
//     vector<string> vec_test_words = test_words;

//     wordsTypeFunction(vec_test_words);
//     return 0;
// }


// End::2.0

auto extract_attrs(vector<string>& words){
    vector<string> attrs;
    auto it = words.begin();
    while (it != words.end()){
        if (it->find("[[") != string::npos && it->find("]]") != string::npos){
            attrs.push_back(*it);
            it = words.erase(it);
        } else {
            it++;
        }
    }
    return attrs;
}

void print_words(const vector<string>& words, std::ostream& out){
    for (const auto& w: words){
        out << w << " ";
    }
}

void print_words_commas(const vector<string>& words, std::ostream& out){
    int n = words.size();
    for (int i = 0; i < n; i++){
        out << words[i];
        if (i < n - 1){
            out << ", ";
        }
    }
}

auto extract_attrs2(const vector<string>& words, vector<string>& attrs, vector<string>& non_attrs){
    for (const auto& w: words){
        if (w.find("[[") != string::npos && w.find("]]") != string::npos){
            attrs.push_back(w);
        } else {
            non_attrs.push_back(w);
        }
    }
}

std::ostream& print_words_new(std::ostream& out, const vector<string>& words){
    for (const auto& w: words){
        out << w << " ";
    }
    return out;
}

std::ostream& print_words_commas_new(std::ostream& out, const vector<string>& words){
    int n = words.size();
    for (int i = 0; i < n; i++){
        out << words[i];
        if (i < n - 1){
            out << ", ";
        }
    }
    return out;
}

int main()
{
    cout << endl;
    cout << "=====================2.1=====================" << endl;
    const vector<string> test_words{
    "switch", "[[noreturn]]",
    "if", "[[maybe_unused",
    "for", "fallthrough"
    };

    auto non_attrs = test_words;
    auto attrs = extract_attrs(non_attrs);
    cout << "Test words: ";
    print_words(test_words, cout);
    cout << endl;
    cout << "Attributes: ";
    print_words(attrs, cout);
    cout << std::endl;
    cout << "Non attributes: ";
    print_words(non_attrs, cout);
    cout << endl;


    cout << endl;
    cout << "=====================2.2=====================" << endl;
    cout << "Test words: ";
    print_words_commas(test_words, cout);
    cout << endl;
    cout << "Attributes: ";
    print_words_commas(attrs, cout);
    cout << std::endl;
    cout << "Non attributes: ";
    print_words_commas(non_attrs, cout);
    cout << endl;

    cout << endl;
    cout << "=====================2.3=====================" << endl;

    vector<string> attrs_new, non_attrs_new;
    extract_attrs2(
    test_words, attrs_new, non_attrs_new);
    cout << "Test words: ";
    print_words_new(cout, test_words) << endl;
    cout << "Attributes: ";
    print_words_new(cout, attrs_new) << endl;
    cout << "Non attributes: ";
    print_words_new(cout, non_attrs_new) << endl;
    cout << "Attributes: ";
    print_words_new(cout, attrs_new) << endl;

    cout << endl;
    cout << "=====================2.4=====================" << endl;
    cout << "Test words: ";
    print_words_commas_new(cout, test_words) << endl;
    cout << "Attributes: ";
    print_words_commas_new(cout, attrs_new) << endl;
    cout << "Non attributes: ";
    print_words_commas_new(cout, non_attrs_new) << endl;
    cout << "Attributes: ";
    print_words_commas_new(cout, attrs_new) << endl;
    
    return 0;
}


