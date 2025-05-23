#include <bits/stdc++.h>
#define int long long

using namespace std;

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
    int lx = -1;
    int px = -1;
    bool f = false;
    set<int> st;
    for (int i = 0; i < n; i++) {
        if (!f and s[i] == '*') {
            f = true;
            lx = i;
            st.insert(i);
            continue;
        }
        if (i - lx == k) {
            if (s[i] == '*') {
                lx = i;
                st.insert(i);
            } else {
                if (px != -1) {
                    lx = px;
                    st.insert(px);
                }
            }
        }
        if (s[i] == '*') px = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '*') {
            if (!st.count(i)) st.insert(i);
            break;
        }
    }
    cout << st.size() << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}