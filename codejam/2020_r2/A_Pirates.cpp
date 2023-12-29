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
int n;

struct Node {
    int id, val, t;
};

struct cmp {
    bool operator()(Node& n1, Node& n2) { return n1.t > n2.t; }
};

void solve() {
    cin >> n;
    priority_queue<Node, vector<Node>, cmp> qa, qb;
    For(i, 1, n) {
        int x, y;
        cin >> x >> y;
        qa.push({i, x, abs(y - x)});
        qb.push({i, y, abs(x - y)});
    }
    set<int> claimed;
    int sumA = 0, sumB = 0;
    For(i, 1, n) {
        if (i & 1) {
            while (!qa.empty() && claimed.count(qa.top().id)) qa.pop();
            sumA += qa.top().val;
            // cout << "qa = " << qa.top().val << el;
            // cout << "id = " << qa.top().id << el;
            claimed.insert(qa.top().id);
            qa.pop();
        } else {
            while (!qb.empty() && claimed.count(qb.top().id)) qb.pop();
            sumB += qb.top().val;
            // cout << "qb = " << qb.top().val << el;
            // cout << "id = " << qb.top().id << el;
            claimed.insert(qb.top().id);
            qb.pop();
        }
    }
    cout << sumA - sumB << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}