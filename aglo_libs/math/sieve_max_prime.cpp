#include <bits/stdc++.h>
#define int long long
#define el '\n'

using namespace std;

//*** Sieve max prime number of a number ***//
// O(n log log n)
vector<int> max_prime;
void maxSieve(int n) {
    max_prime = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) max_prime[i] = i;

    for (int i = 2; i <= n; i++) {
        if (max_prime[i] == i) {
            for (int j = i; j <= n; j += i) max_prime[j] = i;
        }
    }
}

// *** Prime Factors by using max_prime"
// O(log n);  (n < sieve size)
vector<int> primeFactors(int number) {
    vector<int> f;
    while (number != 1) {
        f.push_back(max_prime[number]);
        number /= max_prime[number];
    }
    return f;
}

// *** Prime Map Factor by using max_prime"
// O(log n); (n < sieve size)
map<int, int> primeMapFactors(int n) {
    map<int, int> f;
    while (n != 1) {
        f[max_prime[n]]++;
        n /= max_prime[n];
    }
    return f;
}

// *** Generate Divisors by Prime Map Factors ***//
// O(d(n)) where d(n) = number of divisors
void genDiv(map<int, int>::const_iterator it, map<int, int>::const_iterator end, int cur, vector<int>& div) {
    if (it == end) {
        div.push_back(cur);
        return;
    }

    int p = it->first;
    int exp = it->second;

    auto nextIt = next(it);
    for (int i = 0; i <= exp; i++) {
        genDiv(nextIt, end, cur, div);
        cur *= p;
    }
}

//*** Find All Divisors ***//
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

//*** Find Num Diff Prime Divisors ***//
// O( n log log n)
vector<int> num_diff_pf;  // number of distinct prime factors

void numDiffPF(int n) {
    num_diff_pf = vector<int>(n + 1);
    for (int i = 2; i <= n; ++i) {
        if (num_diff_pf[i] == 0) {
            for (int j = i; j <= n; j += i) ++num_diff_pf[j];
        }
    }
}

// Using:
int32_t main() {
    maxSieve(1e7);

    map<int, int> m = primeMapFactors(72);
    for (auto& [f, s] : m) cout << f << " " << s << el;

    cout << "-------------------------------" << el;
    vector<int> div;
    genDiv(m.begin(), m.end(), 1LL, div);
    sort(div.begin(), div.end());
    for (auto& e : div) cout << e << " ";
    cout << el;
    cout << "-------------------------------" << el;

    vector<int> d2 = getDivisors(72);
    sort(d2.begin(), d2.end());
    for (auto& e : d2) cout << e << " ";
    cout << el;
    cout << "-------------------------------" << el;

    numDiffPF(1e7);
    cout << num_diff_pf[2 * 3 * 5 * 7] << el;  // 4

    return 0;
}
