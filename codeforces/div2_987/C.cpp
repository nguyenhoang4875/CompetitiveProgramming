#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int) (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int) (b); i--)
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
int n;

void solve() {
    cin >> n;
    if(!(n & 1)) {
        for(int i = 1; i <= n/2; i++) {
            cout << i << " " << i << " ";
        }
        cout << el;
        return;
    }
    if(n &1 and n < 27) {
        cout << -1 << el;
        return;
    }
    vi a(n + 1);
    a[1] = 1;
    a[10] = 1;
    a[26] = 1;
    a[27] = 2;
    a[23] = 2;
    int id = 3;
    for(int i = 2; i <= 9; i+= 2) {
        a[i] = a[i + 1] = id;
        id++;
    }
    for(int i = 11; i <= 22; i+= 2) {
        a[i] = a[i + 1] = id;
        id++;
    }
    for(int i = 24; i <= 25; i+= 2) {
        a[i] = a[i + 1] = id;
        id++;
    }
    id += 5;
    for(int i = 28; i <= n; i += 2) {
        a[i] = a[i + 1] = id;
        id++;
    }
    For(i, 1, n) cout << a[i] << " ";
    cout << endl;



}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}