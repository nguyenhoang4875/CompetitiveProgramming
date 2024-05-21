#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Argus online judge
 * Solution: Priority Queue
 */

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

struct cmp {
    bool operator()(pii &p1, pii &p2) {
        if (p1.S == p2.S) {
            return p1.F > p2.F;
        } else
            return p1.S > p2.S;
    }
};

void solve() {
    string a;
    int id, pr;
    priority_queue<pii, vii, cmp> q;
    map<int, int> mii;
    while (true) {
        cin >> a;
        if (a == "#") break;
        cin >> id >> pr;
        q.push({id, pr});
        mii[id] = pr;
    }
    int num;
    cin >> num;
    while (num--) {
        pii cur = q.top();
        q.pop();
        cout << cur.F << el;
        int newPr = cur.S + mii[cur.F];
        q.push({cur.F, newPr});
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}