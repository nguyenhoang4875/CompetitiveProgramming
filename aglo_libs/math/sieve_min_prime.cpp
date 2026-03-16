#include <bits/stdc++.h>
#define int long long
#define el '\n'

using namespace std;

//*** Sieve min prime number of a number ***//
// O(n log log n)
vector<int> min_prime;
void minSieve(int n) {
    min_prime.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) min_prime[i] = i;

    for (int i = 2; i <= n; i++) {
        if (min_prime[i] == i) {
            for (int j = i; j <= n; j += i)
                if (min_prime[j] == j) min_prime[j] = i;
        }
    }
}

// *** Prime Factors Exp by using min_prime"
// O(log n); (n < sieve size)
vector<pair<int, int>> primeFactorsExp(int n) {
    vector<pair<int, int>> f;

    while (n > 1) {
        int p = min_prime[n];
        int cnt = 0;

        while (n % p == 0) {
            n /= p;
            ++cnt;
        }
        f.push_back({p, cnt});
    }
    return f;
}

// *** Prime Factors by using min_prime"
// O(log n);  (n < sieve size)
vector<int> primeFactors(int number) {
    vector<int> f;
    while (number != 1) {
        f.push_back(min_prime[number]);
        number /= min_prime[number];
    }
    return f;
}

// *** Generate Divisors by Prime Factors Exp ***//
// O(d(n)) where d(n) = number of divisors
vector<int> genDiv(const vector<pair<int, int>>& f) {
    vector<int> div = {1};

    for (auto [p, exp] : f) {
        int dn = div.size();
        int mul = 1;

        for (int e = 1; e <= exp; ++e) {
            mul *= p;
            for (int i = 0; i < dn; ++i) {
                div.push_back(div[i] * mul);
            }
        }
    }

    return div;
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
    minSieve(1e7);

    vector<pair<int, int>> m = primeFactorsExp(72);
    for (auto& [f, s] : m) cout << f << " " << s << el;

    cout << "-------------------------------" << el;
    vector<int> div = genDiv(m);
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
