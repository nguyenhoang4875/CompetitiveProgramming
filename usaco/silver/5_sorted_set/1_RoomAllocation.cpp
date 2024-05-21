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

struct node {
    int a, b, id;
    bool operator<(const node& n) const {
        if (a == n.a) return b < n.b;
        return a < n.a;
    }
    friend ostream& operator<<(ostream& os, const node& n) {
        return os << n.a << " " << n.b << " " << n.id;
    }
};

void solve() {
    cin >> n;
    multiset<node> mts;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mts.insert({a, b, i});
    }
    int cnt = 0;
    map<int, int> ans;
    while (!mts.empty()) {
        int curEnd = 0;
        cnt++;
        while (true) {
            auto it = mts.lower_bound({curEnd + 1, curEnd + 1});
            if (it == mts.end()) break;
            ans[it->id] = cnt;
            curEnd = it->b;
            mts.erase(it);
        }
    }
    cout << cnt << el;
    for (auto e : ans) cout << e.S << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}