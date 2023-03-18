#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// // Start::OOP_HW_1.1

// void generateFrame(string warrior, string mage, string ninja, string fighter) {
//     string jw = " Warrior: ", jm = " Mage:    ", jn = " Ninja:   ", jf = " Fighter: ", star = "*";
//     int jwL = jw.length(), jmL = jm.length(), jnL = jn.length(), jfL = jf.length(); // j = Job.
//     int depend1 = 0, depend2 = 0, padding = 1;

//     // Check who's name is the longest for the first block and second block => make columns.
//     if(warrior.length() > ninja.length()) {
//         depend1 += (jwL + warrior.length() + padding*3);
//     } else {
//         depend1 += (jnL + ninja.length() + padding*3);
//     }
//     if(mage.length() > fighter.length()) {
//         depend2 += (jmL + mage.length() + padding*3);

//     } else {
//         depend2 += (jfL + fighter.length() + padding*3);
//     }
    
//     // Initailize row as 9, columns are depend on value (depend1 + depend2 + padding*2)      
//     // padding*2 => star in j = 1 j = last
//     int rows = 9, columns;
//     columns = (depend1 + depend2 + (padding*2));
    
//     for(int i = 1; i <= rows; i++) {
//         for(int j = 1; j <= columns; j++) {
            
//             if(i == 3 && j == 2) {
//                 cout << jw << warrior  ;
//             }
//             if(i == 7 && j == 2) {
//                 cout << jn << ninja ;
//             }
//             if(i == 3 && j == 2) {
//                 cout << setw(depend1 - warrior.length() - 11) << "*" << setw(depend1 - warrior.length() - 3) << jm << mage << setw(depend2 - 13) << "*";
//             }
//             if(i == 7 && j == 2) {
//                 cout << setw(depend1 - warrior.length() - 11) << "*" << setw(depend1 - warrior.length() - 3) << jf << fighter << setw(depend2 - 12) << "*";            
//             }

//             if(i == 1 || i == 5 || i == rows || j == 1 || ((j == depend1 && i != 3) && (j == depend1 && i != 7)) || ((j == columns && i != 3) && (j == columns && i != 7))) { 
//                 cout << "*";
//             } else {
//                 cout << " ";
//             }
//         }
//         cout << endl;  
//     }
// } 

// int main() {
//     generateFrame("Squalla", "Rinoa", "Selphie", "Zell");
//     return 0;
// }

// // END::OOP_HW_1.1


// // Start::OOP_HW_1.2

void generateFrame(string warrior, string mage, string ninja, string fighter) {
    string jw = " Warrior: ", jm = " Mage:    ", jn = " Ninja:   ", jf = " Fighter: ", star = "*";
    int jwL = jw.length(), jmL = jm.length(), jnL = jn.length(), jfL = jf.length(); // j = Job.
    int depend1 = 0, depend2 = 0, padding = 1;

    // Check who's name is the longest for the first block and second block => make columns.
    if(warrior.length() > ninja.length()) {
        depend1 += (jwL + warrior.length() + padding*3);
    } else {
        depend1 += (jnL + ninja.length() + padding*3);
    }
    if(mage.length() > fighter.length()) {
        depend2 += (jmL + mage.length() + padding*3);

    } else {
        depend2 += (jfL + fighter.length() + padding*3);
    }
    
    // Initailize row as 9, columns are depend on value (depend1 + depend2 + padding*2)      
    // padding*2 => star in j = 1 j = last
    int rows = 9, columns;
    columns = (depend1 + depend2 + (padding*2));
    
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            
            if(i == 3 && j == 2) {
                cout << "|" << jw << warrior  ;
            }
            if(i == 7 && j == 2) {
                cout << "|" << jn << ninja ;
            }
            if(i == 3 && j == 2) {
                cout << setw(depend1 - warrior.length() - 11) << "|" << setw(depend1 - warrior.length() - 3) << jm << mage << setw(depend2 - 13) << "|";
            }
            if(i == 7 && j == 2) {
                cout << setw(depend1 - warrior.length() - 11) << "|" << setw(depend1 - warrior.length() - 3) << jf << fighter << setw(depend2 - 12) << "|";            
            }
            
            if(i==1){
                if((j == 1) || (j == depend1) || (j == columns)) {
                cout << "+";
                }
                else {
                    cout <<  "=";
                }
            }
            if (i == 5 )  {
                if((j == 1) || (j == depend1) || (j == columns)) {
                cout << "+";
                }
                else {
                    cout <<  "-";
                }
            }
            if (i == 2 || i == 4 || i == 6 || i == 8) {
                if (j == 1 || j == depend1 || j == columns) {
                    cout << "|";
                }
                else {
                    cout << " ";
                }

            }
            if(i==rows){
                if((j == 1) || (j == depend1) || (j == columns)) {
                cout << "+";
                }
                else {
                    cout <<  "=";
                }
            }
        }
        cout << endl;  
    }
} 

int main() {
    generateFrame("Squalla", "Rinoa", "Selphie", "Zell");
    return 0;
}

// END::OOP_HW_1.2

