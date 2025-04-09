#include <bits/stdc++.h>
#define int long long

using namespace std;

// O(sqrt(n))
int phi(int n) {
    int ans = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            ans -= ans / p;
        }
    }
    if (n > 1) {
        ans -= ans / n;
    }
    return ans;
}

// O(n * log(log(n)))
vector<int> phi1ToN(int n) {
    vector<int> vPhi(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        vPhi[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        // If i is prime
        if (vPhi[i] == i) {
            for (int j = i; j <= n; j += i) {
                vPhi[j] -= vPhi[j] / i;
            }
        }
    }
    return vPhi;
}

void solve() {
    int n;
    cin >> n;
    cout << "phi " << n << " = " << phi(n) << '\n';

    vector<int> vPhi = phi1ToN(n);
    for (int i = 1; i <= n; i++) {
        cout << vPhi[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}