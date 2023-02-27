#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// start::2.1
// double convertFarenhiet(double farenhiet){
//     return (farenhiet - 32) * 5 / 9;
// }

// int main(){
//     int f = 0;
//     cout << fixed << setprecision(1);

//     cout << "Fahr\tCelcius" << endl;
//     while(f <= 300){
//         cout << setw(3) << f << "\t" << setw(7) << convertFarenhiet(f) << endl;
//         f += 20;
//     }
// }
// end::2.1



// start::2.2
// double convertFarenhiet(double farenhiet){
//     return (farenhiet - 32) * 5 / 9;
// }

// int main(){
//     int f = 0;
//     cout << fixed << setprecision(1);

//     cout << "Fahr\tCelcius" << endl;
//     while(f <= 300){
//         cout << setw(3) << f << "\t" << setw(7) << convertFarenhiet(f) << endl;
//         f += 40;
//     }
// }
// end::2.2



// start::2.3
double convertFarenhiet(double farenhiet){
    return (farenhiet - 32) * 5 / 9; 
}


int main(){
    int f = 300;
    cout << fixed << setprecision(1);

    cout << "Fahr\tCelcius" << endl;
    while(f >= 0){
        cout << setw(3) << f << setw(12) << convertFarenhiet(f) << endl;
        f -= 20;
    }
}
// end::2.3


