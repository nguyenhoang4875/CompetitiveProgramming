#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> prime;
void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) is_prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (is_prime[p]) prime.push_back(p);
}

//**************** Find all divisor of a number ****************//
// O(sqrt(n))

vector<int> getDivisors(int n) {
    vector<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i * i != n) div.push_back(n / i);
        }
    }
    return div;
}

//**************** Find all prime divisor of a number ****************//
// O(sqrt(n))
vector<int> givePrimeDivisor(int n) {
    vector<int> div;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) div.push_back(n);
    return div;
}

//**************** Find factors primes number of a number ****************//
// O(log n)
vector<int> min_prime(1e6 + 1, 0);  // ms: max size
void minSieve(int n) {
    for (int i = 1; i <= n; i++) {
        min_prime[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (min_prime[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (min_prime[j] == j) {
                    min_prime[j] = i;
                }
            }
        }
    }
}

vector<int> getFactor(int number) {
    vector<int> f;
    while (number != 1) {
        f.push_back(min_prime[number]);
        number /= min_prime[number];
    }
    return f;
}

map<int, int> getFactorMap(int n) {
    map<int, int> f;
    while (n != 1) {
        f[min_prime[n]]++;
        n /= min_prime[n];
    }
    return f;
}

void generateDivisors(map<int, int>::const_iterator it, map<int, int>::const_iterator end, int cur,
                      vector<int>& divisors) {
    if (it == end) {
        divisors.push_back(cur);
        return;
    }

    int prime = it->first;
    int exp = it->second;

    auto nextIt = next(it);
    for (int i = 0; i <= exp; i++) {
        generateDivisors(nextIt, end, cur, divisors);
        cur *= prime;
    }
}


// Using:
int32_t main() {
    int n = 60;
    cout << "The prime numbers smaller than or equal to " << n << endl;
    sieve(n);
    cout << prime.size() << '\n';
    for (auto e : prime) cout << e << " ";

    cout << endl;
    cout << "All prime divisors with O(sqrt n) of " << n << endl;
    vector<int> prime_div = givePrimeDivisor(n);
    for (auto e : prime_div) cout << e << " ";
    cout << endl;

    cout << "All prime factors with O(log n) of " << n << endl;
    minSieve(n);
    vector<int> factors = getFactor(n);
    for (auto e : factors) cout << e << " ";
    cout << endl;

    return 0;
}
