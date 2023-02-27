#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// class User {
//     string status = "Active";

//     public:
//         string firstname;
//         string lastname;
//         string get_status;

//         User(string firstname, string lastname) {
//             this-> firstname = firstname;
//             this-> lastname  = lastname;
//         }
// };

// int add_user_if_not_exists(vector<User> &users, User account) {

//     for(int i = 0; i < users.size(); i++) {
//         if(users[i].firstname == account.firstname && users[i].lastname == account.lastname) {
//             return i;
//         }
//     }
//     // cout << users[0].firstname;
//     users.push_back(account);
//     return users.size() - 1;
// }

// int main() {
//     User account1("Ko-Kwan", "Mongkholtham");
//     User account2("Saruda", "Tuanwanna");
//     User account3("Natt", "Mongkholtham");
//     User account4("Chintana", "Mongkholtham");

//     vector<User> users;
//     users.push_back(account1);
//     users.push_back(account2);
//     users.push_back(account3);
//     users.push_back(account4);

//     User account0("Ko-Kwan", "Mongkholtham");
//     cout << users.size();
//     add_user_if_not_exists(users, account0);
//     cout << endl;

//     cout << users.size() << endl;
//     cout << users[0].firstname << endl;
//     cout << users[4].firstname << endl;
    



//     return 0;
// }