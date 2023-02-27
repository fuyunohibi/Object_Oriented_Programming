#include <iostream>
#include <vector> 
#include <cmath>

using namespace std;

// =====================START - "Sieve of Eratsthenes Algorithm"========================

void sieve(int n) {
    
    //setting limit of nums 
    int prime[100] = {0};
    vector<int> primeNums;

    for (int i=2; i<=n; i++) {
        if(prime[i] == 0) {
            for(int j=i*i; j<=n; j+=i) {
                prime[j] = 1;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        if(prime[i] == 0) {
            primeNums.push_back(i);
            // cout << i << ", ";
        }
    }

    for (int i = 0; i < primeNums.size(); i++) {
        int n = primeNums.size();
        int lastPrime = primeNums[n-1];

        if(primeNums[i] == primeNums[n-1]) {
            cout << lastPrime ;
        }
        else {
            cout << primeNums[i] << ", ";
        }
    }
    cout << endl;
}

// =====================END========================


// =====================START - "Greatest Common Divisor"========================

void gcd_for_loop(int a,int  b) {
    int gcd;
    for(int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    cout << "GCD: " << gcd << endl;
}

int gcd_recursion(int a, int b) {
    if (b != 0) {
        return gcd_recursion(b, a%b);
    }
    else return a;
}

// =====================END========================

int main() {
    // cout << "Prime Numbers: " << endl;
    // sieve(100); 
    // greatest_common_divsor(pow((987*654), 321), pow((123*456), 789));
    gcd_for_loop(10, 2);
    cout << "GCD: " << gcd_recursion(10, 2);
    return 0;
}

