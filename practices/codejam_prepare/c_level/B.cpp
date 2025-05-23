#include<bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/gym/605682/problem/B
 */

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
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
const int ms = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < k; i++) {
        int c = '?';
        bool f = false;
        for(int j = i; j < n; j += k) {
            if(s[j] == '?') continue;
            if(!f) {
               f = true; 
               c = s[j];
               continue;
            }
            if(f and s[j] != c) {
                cout << "NO" << el;
                return;
            }
        }
        if(c == '0') c0++;
        if(c == '1') c1++;
    }
    if(max(c0, c1) > k / 2) {
        cout << "NO" << el;
        return;
    }
    cout << "YES" << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}