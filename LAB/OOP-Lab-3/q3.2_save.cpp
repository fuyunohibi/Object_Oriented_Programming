#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include <fstream>

using namespace std;

double map(double x, double in_min, double in_max, double out_min, double out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main(){
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_real_distribution<double> dist{-1, 1};

    int N;
    cout << "Enter the N value: ";
    cin >> N;

    std::ofstream out("data.txt");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());

    for (int i = 1; i <= N; i++)
    {
        double x = map(dist(rng), -1, 1, 0, 640);
        
        double y = map(dist(rng), -1, 1, 0, 480);
        
        cout << x << " " << y << endl;
    }
}
