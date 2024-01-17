#include <bits/stdc++.h>
/**
 * Problem: https://codejam.lge.com/problem/24436
 * TLE need to handle the case K = 1e18
 *
 */

#define int long long
using namespace std;
const int ms = 1e5 + 5;
const int oo = 1e9;
int l, k, x, y;
int d[ms];
int tMax = 0;
vector<string> sp;

int power(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) ans *= a;
        n /= 2;
        a *= a;
    }
    return ans;
}

vector<int> getCanGo(int val) {
    vector<int> ans;
    int tmp = 0, tmp2 = 0;
    for (int i = 0; i < l; i++) {
        tmp = val + pow(10, i);
        tmp2 = val - pow(10, i);
        if (tmp >= 0 and tmp <= tMax) ans.push_back(tmp);
        if (tmp2 >= 0 and tmp2 <= tMax) ans.push_back(tmp2);
    }
    return ans;
}

void bfs(int s) {
    d[s] = 0;
    queue<pair<int, int>> q;
    q.push({s, 0});
    while (!q.empty()) {
        pair<int, int> cp = q.front();
        q.pop();
        int val = cp.first;
        int cnt = cp.second;

        vector<int> canGo = getCanGo(val);
        for (auto i : canGo) {
            if (d[i] != oo) continue;
            d[i] = cnt + 1;
            q.push({i, d[i]});
        }
    }
}

string getAnsNum(int val) {
    string tmp = to_string(val);
    int tz = tmp.size();
    if (tz == l) return tmp;
    int diff = l - tz;
    for (int i = 1; i <= diff; i++) {
        tmp = '0' + tmp;
    }
    return tmp;
}

void getPath(int s, int cnt, vector<bool>& seen, string path) {
    seen[s] = true;
    if (cnt == 0) {
        if (s == y) {
            sp.push_back(path);
        }
        return;
    }

    for (int i : getCanGo(s)) {
        if (seen[i]) continue;
        string tmp = " " + getAnsNum(i);
        getPath(i, cnt - 1, seen, path + tmp);
        seen[i] = false;
    }
}
void clearData() { sp.clear(); }

void solve() {
    clearData();
    cin >> l >> k >> x >> y;
    tMax = power(10, l) - 1;
    for (int i = 0; i <= tMax; i++) d[i] = oo;
    vector<int> cg = getCanGo(x);

    bfs(x);
    int cnt = d[y];
    vector<bool> seen(tMax + 5, false);
    getPath(x, cnt, seen, getAnsNum(x));
    if (k > sp.size()) {
        cout << "NO\n";
        return;
    }
    sort(sp.begin(), sp.end());
    cout << sp[k - 1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) solve();

    return 0;
}