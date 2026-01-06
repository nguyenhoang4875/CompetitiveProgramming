#include <bits/stdc++.h>
#define int long long
#define el '\n'

using namespace std;

int s_size;           // size of sieve
vector<int> ps;       // prime number
bitset<10000010> bs;  // bitset is prime number

//*** Sieve ***//
// O(n log log n) (n <= 1e7)
void sieve(int n) {
    s_size = n + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < s_size; ++i) {
        if (bs[i]) {
            for (int j = i * i; j < s_size; j += i) bs[j] = 0;
            ps.push_back(i);
        }
    }
}

//*** Is Prime ***//
// O(sqrt(n) / ln(sqrt(n))); (n < (ps.back() * ps.back()))
bool isPrime(int n) {
    if (n < s_size) return bs[n];
    for (int i = 0; i < (int)ps.size() and ps[i] * ps[i] <= n; ++i) {
        if (n % ps[i] == 0) return false;
    }
    return true;
}

//*** Prime Factors ***//
// O(sqrt(n) / ln(sqrt(n))); (n < (ps.back() * ps.back()))
vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 0; i < (int)ps.size() and (ps[i] * ps[i] <= n); ++i) {
        while (n % ps[i] == 0) {
            n /= ps[i];
            factors.push_back(ps[i]);
        }
    }
    if (n != 1) factors.push_back(n);
    return factors;
}

//*** numPF ***//
// O(sqrt(n) / ln(sqrt(n))); (n < (ps.back() * ps.back()))
int numPF(int n) {
    int ans = 0;
    for (int i = 0; i < (int)ps.size() and (ps[i] * ps[i] <= n); ++i) {
        while (n % ps[i] == 0) {
            n /= ps[i];
            ++ans;
        }
    }
    return ans + (n != 1);
}

//*** numDiv ***//
// O(sqrt(n) / ln(sqrt(n))); (n < (ps.back() * ps.back()))
int numDiv(int n) {
    int ans = 1;
    for (int i = 0; i < (int)ps.size() and (ps[i] * ps[i] <= n); ++i) {
        int power = 0;
        while (n % ps[i] == 0) {
            n /= ps[i];
            ++power;
        }
        ans *= power + 1;
    }
    if (n != 1) ans *= 2;
    return ans;
}

//*** sumDiv ***//
// O(sqrt(n) / ln(sqrt(n))); (n < (ps.back() * ps.back()))
int sumDiv(int n) {
    int ans = 1;
    for (int i = 0; i < (int)ps.size() and (ps[i] * ps[i] <= n); ++i) {
        int multiplier = ps[i], total = 1;
        while (n % ps[i] == 0) {
            n /= ps[i];
            total += multiplier;
            multiplier *= ps[i];
        }
        ans *= total;
    }
    if (n != 1) ans *= (n + 1);
    return ans;
}

//*** eulerPhi ***//
// O(sqrt(n) / ln(sqrt(n))); (n < (ps.back() * ps.back()))
int eulerPhi(int n) {
    int ans = n;
    for (int i = 0; i < (int)ps.size() and (ps[i] * ps[i] <= n); ++i) {
        if (n % ps[i] == 0) ans -= ans / ps[i];
        while (n % ps[i] == 0) n /= ps[i];
    }

    if (n != 1) ans -= ans / n;
    return ans;
}

// Using:
int32_t main() {
    sieve(10000000);  // upto 1e7
    cout << ps.back() << el;
    cout << isPrime((1LL << 31) - 1) << el;
    cout << isPrime(136117223861LL) << el;

    cout << "-------------------------------" << el;
    vector<int> r = primeFactors(142391208960LL);  // 2^10*3^4*5*7^4*11*13
    for (auto e : r) cout << e << " ";
    cout << el;

    cout << "-------------------------------" << el;
    cout << numPF(60) << el;  // 4: 2 2 3 5

    cout << "-------------------------------" << el;
    cout << numDiv(60) << el;  // 12

    cout << "-------------------------------" << el;
    cout << sumDiv(60) << el;  // 168

    cout << "-------------------------------" << el;
    cout << eulerPhi(10) << el;       // 4: 1, 3, 7, 9
    cout << eulerPhi(1e9 + 7) << el;  // 1e9 + 6

    return 0;
}
