#include <iostream>
#include <string>
#include <cmath>
#include "random.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;


// int main() {1
//     int number = 0;
//     float value = 0;
//     double bigNumber;
//     return 0;
// }

// int main()
// {
//     int number = 0;
//     float value = 0
//     double bigNumber;
//     bigNumber = number + value;
//     return 0;
// }

// int main()
// {
//     int number = 0;
//     float value = 0;
//     double bigNumber;
//     bignumber = number + value;
//     return 0;
// }

// int main()
// {
//     const string ERROR_MESSAGE
//         = "bad string!";
//     cout << "Hello!\n" ;
//     return 0;
// }

// int main()
// {
//     float firstVal = 0;
//     float secondVal = 0;
//     float factor = 1;
//     float result
//         = firstVal - secondVal
//         / factor;
//     cout << result;
//     return 0;
// }

// int main()
// {
//     const double x = 2.0;
//     const double y = 3.1415;
//     double product;
//     x * y = product;
//     return 0;
// }

// int main()
// {
//     cout << "Please enter P1 name: ";
//     string p1_name;
//     cin >> p1_name;
//     cout << "Please enter P2 name: ";
//     string p2_name;
//     cin >> p2_name;
//     cout << "Player 1: " << p1_name << std::endl;
//     cout << "Player 2: " << p2_name << std::endl;
//     cout << "*****************************\n";
//     cout << "*             *             *\n";
//     cout << "*" << "Player 1:" << p1_name << "*" << "Player 2:" << p2_name << "*\n";
//     cout << "*             *             *\n";
//     cout << "*****************************\n";
//     return 0;
// }


// int main()
// {
//     cout << "Please enter P1 name: ";
//     string p1_name;
//     cin >> p1_name;
//     cout << "Please enter P2 name: ";
//     string p2_name;
//     cin >> p2_name;
//     cout << "Player 1: " << p1_name << std::endl;
//     cout << "Player 2: " << p2_name << std::endl;

//     for(int i = 0; i<=14; i++) {
//         cout << "*";
//     }
//     cout << "\n";
//     cout << "*             *\n";
//     cout << "*Player 1:" << p1_name << "*\n";
//     cout << "*             *\n";
//     for(int i = 0; i<=14; i++) {
//         cout << "*";
//     }
//     cout << "\n";
//     cout << "*             *\n";
//     cout << "*Player 2:" << p2_name << " *\n";
//     cout << "*             *\n";
//     for(int i = 0; i<=14; i++) {
//         cout << "*";
//     }

//     return 0;
// }

// void arrow() {

//     int  points, x, y;
//     cout << "Output size: ";
//     cin >> points;

//     for(int x = 1; x < points; x++)
//     {
//     for(int y = 1; y <= x; y++)
//     cout << "*";
//     cout << "\n";
//     }
//     for(int x = points; x >= 0; x--)
//     {
//     for(int y = 1; y <= x; y++)
//     cout << "*";
//     cout << "\n";
//     }

// }

void backArrow() {

    int points, i, j;
    cout << "Output size: ";
    cin >> points;
    for(i = 1; i <= points; i++)
    {
    for(j = i; j < points; j++)
    {
    cout << " ";
    }
    for(j = 1; j <= i; j++)
    {
    cout << "*";
    }
    cout << "\n";
    }
    for(i = points; i >= 1; i--)
    {
    for(j = i; j <= points; j++)
    {
    cout << " ";
    }
    for(j = 1; j < i; j++)
    {
    cout << "*";
    }
    cout << "\n";
    }

}

// int main() {

    // int points;
    // cout << "Output Size: \n";
    // cin  >> points;

    // for(int i = 0; i != points; i++) {
        
    //     for(int j = 1; j<= i; j++){
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }

    // arrow();
    // backArrow();
    
//     return 0;
// }

// template <typename T_>
// inline constexpr
//     T_ pi_v{3.141592653589793238462643383279502884L};

// inline constexpr double pi = pi_v<double>;

// int main()
// {
//     int N = 100;
//     constexpr double rnd_min = -1.0, rnd_max = 1.0;
//     Rand_double rnd{rnd_min, rnd_max};

//     random_device rd;
//     rnd.seed(rd());
//     cout << fixed << setprecision(3);

//     double x1 = rnd();
//     double y1 = rnd();
//     cout << "Point #1: (" << x1 << ", " << y1 << ")\n";

//     double x2 = rnd();
//     double y2 = rnd();
//     cout << "Point #2: (" << x2 << ", " << y2 << ")";
//     cout << endl;


//     int interval, i;
//     double rand_x, rand_y, origin_dist, pi;
//     int circle_points = 0, square_points = 0;
 
//     // Initializing rand()
//     srand(time(NULL));
 
//     // Total Random numbers generated = possible x
//     // values * possible y values
//     for (i = 0; i < (N * N); i++) {
 
//         // Randomly generated x and y values
//         rand_x = double(rand() %  N + 1) / N;
//         rand_y = double(rand() %  N + 1) / N;
 
//         // Distance between (x, y) from the origin
//         origin_dist = rand_x * rand_x + rand_y * rand_y;
 
//         // Checking if (x, y) lies inside the define
//         // circle with R=1
//         if (origin_dist <= 1)
//             circle_points++;
 
//         // Total number of points generated
//         square_points++;
 
//         // estimated pi after this iteration
//         pi = double(4 * circle_points) / square_points;
 
//         // For visual understanding (Optional)
//         cout << rand_x << " " << rand_y << " "
//              << circle_points << " " << square_points
//              << " - " << pi << endl
//              << endl;
 
//         // Pausing estimation for first 10 values (Optional)
//         if (i < 20)
//             getchar();
//     }
 
//     // Final Estimated Value
//     cout << "\nFinal Estimation of Pi = " << pi;
//     return 0;

// }




  


  

