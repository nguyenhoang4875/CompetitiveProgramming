#include <bits/stdc++.h>

#define int long long
using namespace std;
const int ms = 1e5 + 5;
const int oo = 1e9;
int f[ms];
int d[ms];
map<int, vector<int>> mc;
bool visited[ms];

int countDivisors(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n) cnt++;
        }
    }
    return cnt;
}

bool checkDiff(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    int cnt = 0;
    for (int i = 0; i <= 3; i++) {
        if (s1[i] != s2[i]) cnt++;
    }
    return cnt == 1;
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

        int numDiv = f[val];
        vector<int> canGo;
        for (int i = numDiv - 1; i <= numDiv + 1; i++) {
            for (auto e : mc[i]) {
                if (d[e] == oo) canGo.push_back(e);
            }
        }
        for (auto i : canGo) {
            if (d[i] != oo) continue;
            if (checkDiff(i, val)) {
                d[i] = cnt + 1;
                q.push({i, d[i]});
            }
        }
    }
}

void solve() {
    int S, E1, E2;
    cin >> S >> E1 >> E2;

    // pre calculate for divisors of i
    for (int i = 1000; i <= 9999; i++) {
        f[i] = countDivisors(i);
        mc[f[i]].push_back(i);
        d[i] = oo;
    }

    bfs(S);
    cout << d[E1] << "\n";
    cout << d[E2] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << countDivisors(16);

    solve();
    return 0;
}