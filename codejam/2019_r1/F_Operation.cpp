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
struct SegmentTree {
    int n;
    vector<int> t;

    SegmentTree(int _n) {
        n = _n;
        t.resize(4 * n, 0);
    }

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int mid = (tl + tr) / 2;
            build(a, 2 * v, tl, mid);
            build(a, 2 * v + 1, mid + 1, tr);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    int combine(int v1, int v2) { return v1 + v2; }

    int query(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return 0;
        if (l <= tl and tr <= r) return t[v];

        int mid = (tl + tr) / 2;
        return combine(query(2 * v, tl, mid, l, r), query(2 * v + 1, mid + 1, tr, l, r));
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] += val;
        } else {
            int mid = (tl + tr) / 2;
            if (pos <= mid)
                update(2 * v, tl, mid, pos, val);
            else
                update(2 * v + 1, mid + 1, tr, pos, val);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }
    int query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int pos, int val) { update(1, 1, n, pos, val); }
    void set(int pos, int val) { update(pos, val - query(pos, pos)); }
};

struct cmpStr {
    bool operator()(const string a, const string b) const {
        if (a.length() == b.length()) {
            return a < b;
        }
        return a.length() < b.length();
    }
};

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;

void solve() {
    cin >> n;
    string query[n + 5][5];
    map<string, int, cmpStr> mp;
    For(i, 1, n) {
        int type;
        cin >> type;
        if (type == 1) {
            query[i][0] = "1";
            cin >> query[i][1];
            cin >> query[i][2];
            mp[query[i][1]] = 0;
        } else if (type == 2) {
            query[i][0] = "2";
            cin >> query[i][1];
            cin >> query[i][2];
            mp[query[i][1]] = 0;
            mp[query[i][2]] = 0;
        } else {
            query[i][0] = "3";
            cin >> query[i][1];
            mp[query[i][1]] = 0;
        }
    }
    int idx = 1;
    for (auto e : mp) {
        mp[e.F] = idx++;
    }
    SegmentTree sgt(ms);
    For(i, 1, n) {
        int type = stoll(query[i][0]);
        if (type == 1) {
            int a = mp[query[i][1]];
            int b = stoll(query[i][2]);
            sgt.update(a, b);
            cout << sgt.query(1, ms) << " ";
        } else if (type == 2) {
            int a = mp[query[i][1]];
            int b = mp[query[i][2]];
            cout << sgt.query(min(a, b), max(a, b)) << " ";
        } else {
            int a = mp[query[i][1]];
            sgt.set(a, 0);
            cout << sgt.query(1, ms) << " ";
        }
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}