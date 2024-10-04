#include <bits/stdc++.h>
using namespace std;
#define int long long
#define size(a) (int)(a.size())
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)

const int ms = 100005;
int n;
int l[ms], r[ms];
bool check[ms];
int ans;
int num[ms];
vector<int> listCycle, trace;
int numCycle;

int getNum(int s) {
    if (s == 0) return 0;
    num[s] = 1;
    num[s] += getNum(l[s]) + getNum(r[s]);
    return num[s];
}

// dfs for valid case
void dfs1(int u) {
    if (u == 0) return;
    ans -= num[l[u]] * 2;
    ans -= num[r[u]] * 2;
    //	cout << u << " " << ans << "\n";
    dfs1(l[u]);
    dfs1(r[u]);
}

void dfs2(int u) {
    if (u == 0) return;
    if (check[u] == true) {
        if (!trace.empty() && trace.front() == u) {
            listCycle = trace;
            numCycle++;
        }
        return;
    }
    check[u] = true;
    trace.push_back(u);
    dfs2(l[u]);
    dfs2(r[u]);
    trace.pop_back();
}

bool solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= n; i++) check[i] = false;
    for (int i = 1; i <= n; i++) {
        if (l[i] != 0 && check[l[i]]) return false;
        check[l[i]] = true;
        if (r[i] != 0 && check[r[i]]) return false;
        check[r[i]] = true;
    }
    int cnt = 0;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        if (check[i])
            cnt++;
        else
            s = i;
    }
    if (cnt != n - 1) return false;
    vector<int> listSource;
    listSource.push_back(s);
    for (int i = 0; i < size(listSource); i++) {
        if (l[listSource[i]] != 0) listSource.push_back(l[listSource[i]]);
        if (r[listSource[i]] != 0) listSource.push_back(r[listSource[i]]);
    }
    for (int i = 0; i <= n; i++) num[i] = 0;
    getNum(s);
    //	for (int i = 1; i <= n; i++) cout << num[i] << " ";
    //	cout << "size list source: " << size(listSource) << "\n";
    if (size(listSource) == n) {
        int tmp = n * 2;
        ans = tmp * (tmp - 1) / 2;
        dfs1(s);
        cout << ans << "\n";
    } else {
        numCycle = 0;
        listCycle.clear();
        for (int i = 1; i <= n; i++) check[i] = false;
        for (auto u : listSource) check[u] = true;
        for (int i = 1; i <= n; i++) {
            if (check[i] == false) {
                //				cout <<"start dfs2: " << i << "\n";
                trace.clear();
                dfs2(i);
            }
        }
        //		cout << "numcycle: " << numCycle << "\n";
        if (numCycle > 1) return false;
        ans = size(listCycle) * num[s] * 2;
        cout << ans << "\n";
    }
    return true;
}

int32_t main() {
    //	freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        //		cout << "case: " << T << "\n";
        if (!solve()) cout << 0 << "\n";
    }
    return 0;
}