#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

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

bool find132pattern2(vector<int>& a) {
    int n = a.size();
    vector<int> preMin(n);
    preMin[0] = a[0];
    for (int i = 1; i < n; i++) {
        preMin[i] = min(preMin[i - 1], a[i]);
    }
    set<int> st;
    st.insert(a[n - 1]);
    for (int i = n - 2; i >= 1; --i) {
        if (a[i] > preMin[i - 1]) {
            auto up = st.upper_bound(preMin[i - 1]);
            if (up != st.end()) {
                if (*up < a[i]) return true;
            }
        }
        st.insert(a[i]);
    }

    return false;
}

bool find132pattern(vector<int>& a) {
    int n = a.size();
    vector<int> preMin(n);
    preMin[0] = a[0];
    for (int i = 1; i < n; i++) {
        preMin[i] = min(preMin[i - 1], a[i]);
    }
    stack<int> st;
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] <= preMin[i - 1]) continue;
        while (st.size() and st.top() <= preMin[i - 1]) st.pop();
        if (st.size() and st.top() < a[i]) return true;
        st.push(a[i]);
    }

    return false;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    Rep(i, n) cin >> a[i];
    cout << find132pattern(a);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}