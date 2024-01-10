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
int q;
string curs;
stack<string> st;

void solve() {
    curs = "";
    st.push(curs);
    cin >> q;
    For(i, 1, q) {
        int type;
        cin >> type;
        if (type == 3) {
            int k;
            cin >> k;
            cout << curs[k - 1] << el;
            continue;
        }
        if (type == 4) {
            if (!st.empty()) {
                curs = st.top();
                st.pop();
            }
            continue;
        }

        st.push(curs);
        if (type == 1) {
            string s;
            cin >> s;
            curs.append(s);
        } else if (type == 2) {
            int k;
            cin >> k;
            int n = curs.size();
            curs.resize(n - k);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}