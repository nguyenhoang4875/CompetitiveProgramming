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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;
int a[ms];

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    if(n == 2) {
        cout << "Yes\n";
        return;
    }
    if(n == 3) {
        sort(a + 1, a + n + 1);
        if(a[1] == a[2] || a[2] == a[3]) {
            cout << "Yes\n";
            return;
        }
        cout << "No\n";
        return;
    }
    sort(a + 1, a + n + 1);
    if(a[1] == a[n]) {
        cout << "Yes\n";
        return;
    }
    map<int, int> mii;
    For(i, 1, n) mii[a[i]]++;
    if(mii.size() >= 3) {
        cout << "No\n";
        return;
    }
    if(mii.size() == 2) {
        int t1 = -1;
        int t2 = -1;
        for(auto [f,s ]: mii) {
            if(t1 == -1) {
                t1 = s;
            } else t2 = s;
        }
        if(abs(t1 - t2)  <= 1) {
            cout << "Yes\n";
            return;
        }
        cout << "No\n";
    }



}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}