#include <iostream>
#include <string>
#include <random>

using namespace std;

void calculateMSE() {
    int n, i = 0;
    double sum = 0;
    cout << "Enter the N value: ";
    cin >> n;
    mt19937 rng;
    rng.seed(random_device()());
    uniform_real_distribution<double> dist{0, 1};

    while(i < n) {
        double x = dist(rng);
        double err = x-0.5;
        sum += (err*err);
        i++;
    }

    double mean_squared_error = sum / n;

    cout << "Mean Squared Error (MSE): " << mean_squared_error << endl;
}

int main() {
    calculateMSE();
    return 0;
}
