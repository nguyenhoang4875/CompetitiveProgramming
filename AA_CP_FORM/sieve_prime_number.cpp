#include <bits/stdc++.h>
#define int long long

using namespace std;
//**************** Sieve of Eratosthenes ****************//

// print all prime numbers not greater than 'n'
// O(n*log(log(n)))
/* 
void SieveOfEratosthenes(int n) {
    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true) {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p]) cout << p << " ";
} */
//////////////////////////////////////////////

vector<int> primeNumber;
void SieveOfEratosthenes(int n) {
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }
    // primeNumber.push_back(1);
    for (int p = 2; p <= n; p++)
        if (prime[p]) primeNumber.push_back(p);
}

//**************** Find all divisor of a number ****************//
// O(sqrt(n))
vector<int> vdiv;

void printDivisors(int n) {
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            vdiv.push_back(i);
            if (n / i != i) vdiv.push_back(n / i);
        }
    }
}

//**************** Find all prime divisor of a number ****************//
// O(sqrt(n))
vector<int> givePrimeDivisor(int n) {
    vector<int> div;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            div.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) div.push_back(n);
    return div;
}

// Using:
int32_t main() {
    int n = 60;
    cout << "Following are the prime numbers smaller than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    for(auto e: primeNumber) cout << e << " ";

    cout << endl;
    cout << "All prime divisors of " << n << endl;
    vector<int> primeDivisor = givePrimeDivisor(n);
    for(auto e: primeDivisor) cout << e << " ";
    cout << endl;
    cout << '\n';
    return 0;
}
