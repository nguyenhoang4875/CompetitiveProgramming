#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
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

void solve() {
    int n;
    cin >> n;
    string line;
    getline(cin, line);  // need to get line to read all line of the first line.
    map<string, vector<string>> adj;
    while (n--) {
        getline(cin, line);
        stringstream ss(line);
        string tmp = "";
        ss >> tmp;
        string org = tmp;
        org.pop_back();
        while (ss >> tmp) {
            adj[tmp].pb(org);
        }
    }
    string s;
    cin >> s;

    vector<string> order;
    map<string, bool> seen;
    function<void(string)> dfs = [&](string u) {
        seen[u] = true;
        for (auto& v : adj[u]) {
            if (!seen[v]) dfs(v);
        }
        order.pb(u);
    };
    dfs(s);
    reverse(all(order));
    for (auto e : order) cout << e << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}