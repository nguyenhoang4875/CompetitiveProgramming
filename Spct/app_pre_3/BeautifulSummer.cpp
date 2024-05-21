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
int n;

vector<int> dailyTemperatures(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        while (!st.empty() and a[st.top()] >= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top() - i;
        }
        st.push(i);
    }
    return ans;
}

void solve() {
    cin >> n;
    vi a(n);
    for (auto& x : a) cin >> x;
    vi ans = dailyTemperatures(a);
    for (auto e : ans) cout << e << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}