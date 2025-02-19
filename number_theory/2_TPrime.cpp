#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 1e6;
int n;

vector<bool> isPrime(ms + 5, true);

void sievePrime() {
    isPrime[1] = false;
    for (int i = 2; i <= ms; i++) {
        if (isPrime[i] == false) continue;
        for (int j = i * i; j <= ms; j += i) {
            isPrime[j] = false;
        }
    }
}

void solve() {
    cin >> n;
    For(i, 1, n) {
        int x;
        cin >> x;
        int sq = (int)sqrtl(x + 5);
        while (sq * sq > x) sq--;
        if (sq * sq == x and isPrime[sq]) {
            cout << "YES" << el;
        } else
            cout << "NO" << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sievePrime();

    solve();
    return 0;
}