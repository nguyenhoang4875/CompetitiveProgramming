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
const int ms = 2e5 + 5;
int n, a, b;

void solve() {
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (int i = 0; i <= 1000; i++) {
        char c = s[i % n];
        if (c == 'N') y++;
        if (c == 'E') x++;
        if (c == 'S') y--;
        if (c == 'W') x--;
        if (x == a and y == b) {
            cout << "YES" << el;
            return;
        }
    }
    cout << "NO" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) solve();
    return 0;
}