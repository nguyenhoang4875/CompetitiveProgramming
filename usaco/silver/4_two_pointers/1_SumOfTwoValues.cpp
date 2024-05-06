#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, x;
int a[ms];

void solve() {
    cin >> n >> x;
    map<int, vi> idx;
    For(i, 1, n) {
        cin >> a[i];
        idx[a[i]].push_back(i);
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    while (l < r) {
        int sum = a[l] + a[r];
        if (sum < x)
            l++;
        else if (sum > x)
            r--;
        else {
            if (a[l] == a[r]) {
                cout << idx[a[l]][0] << " " << idx[a[l]][1] << el;
            } else {
                cout << idx[a[l]][0] << " " << idx[a[r]][0] << el;
            }
            return;
        }
    }
    cout << "IMPOSSIBLE" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}