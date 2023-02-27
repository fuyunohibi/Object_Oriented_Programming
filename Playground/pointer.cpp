#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void picture() {
        int n = 5;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - i; j++) {
                cout << " ";
            }
            for(int k = 0; k < 2 * i + 1; k++) {
                cout << "*";
            }
            cout << endl;
        }
}

int main() {
    picture();

    // make a star that looks like a pyramid
    

    // void function()
    // int* ptr;
    // int var = 10;
    
    // ptr = &var;

    // int& ref = var;

    // cout << "The address of var is: " << ptr << endl;
    // cout << "The value of var is: " << *ptr << endl;

    // cout << "The address of ref is: " << &ref << endl;
    // cout << "The value of ref is: " << ref << endl;

    // *ptr = 20;
    // var += 10;
    

    // cout << "The value of var is: " << *ptr << endl;



    return 0;

}
