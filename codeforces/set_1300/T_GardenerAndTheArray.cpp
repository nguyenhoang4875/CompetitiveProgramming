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

void solve() {
    cin >> n;
    vi v[n + 5];
    map<int, int> mp;
    bool found = false;
    int idx = 0;
    int tn = n;
    while(tn--) {
        idx++;
        int m;
        cin >> m;
        bool f= true;
        For(i, 1, m) {
            int x;
            cin >> x;
            v[idx].pb(x);
            if(mp.count(x) == 0) {
                f = false;
            }
            mp[x]++;
        }
        if(f) {
            found = true;
        }
    }
    if(found) {
        cout << "Yes\n";
        return;
    }


    map<int, int> mp2;
    Ford(id, n, 1) {
        bool f = true;
        for(auto x: v[id]) {
            if(mp2.count(x) == 0) {
                f = false;
            } 
            mp2[x]++;
        }
        if(f) found = true;
    }

    if(found) {
        cout << "Yes\n";
        return;
    }

    int cnt = 0;
    for(auto [f, s] : mp) {
        if(s == 1) cnt++;
    }
    if(cnt == 0) {
        cout << "Yes\n";
    } else cout << "No\n";

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