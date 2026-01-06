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
vector<int> phiN(int n) {
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; ++i) ans[i] = i;

    for (int i = 2; i <= n; ++i) {
        if (ans[i] == i) {
            for (int j = i; j <= n; j += i) {
                ans[j] -= ans[j] / i;
            }
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    cout << "phi " << n << " = " << phi(n) << '\n';

    vector<int> ans = phiN(n);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}