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

const long long oo = 1e18, mod = 1e9 + 7;

struct SegmentTree {
    int n;
    vector<int> t;

    SegmentTree(int _n) {
        n = _n;
        t.resize(4 * n, 0);
    }

    // IMPORTANT:update combine MUST update base case of OUT RANGE (*) (l, r) in query function
    int combine(int v1, int v2) { return (v1 + v2) % mod; }

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl] % mod;
        } else {
            int mid = (tl + tr) / 2;
            build(a, 2 * v, tl, mid);
            build(a, 2 * v + 1, mid + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return 0;  // base case OUT RANGE (*)
        if (l <= tl and tr <= r) return t[v];

        int mid = (tl + tr) / 2;
        return combine(query(2 * v, tl, mid, l, r), query(2 * v + 1, mid + 1, tr, l, r));
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = (t[v] + val) % mod;
        } else {
            int mid = (tl + tr) / 2;
            if (pos <= mid)
                update(2 * v, tl, mid, pos, val);
            else
                update(2 * v + 1, mid + 1, tr, pos, val);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }
    int query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int pos, int val) { update(1, 1, n, pos, val); }
    void set(int pos, int val) { update(pos, (val - query(pos, pos) + mod) % mod); }
};

const int ms = 1e5 + 5;
int a[ms], bruteA[ms];

random_device rd;
mt19937 gen(rd());
int random(int l, int r) {
    uniform_int_distribution<int> dis(l, r);
    return dis(gen);
}

int bruteQuery(int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; i++) {
        sum = (sum + bruteA[i]) % mod;
    }
    return sum;
}

void bruteUpdate(int pos, int val) { bruteA[pos] = (bruteA[pos] + val) % mod; }

void solve() {
    int n = 1e5;
    for (int i = 1; i < n; i++) {
        a[i] = random(0, 1e9);
        bruteA[i] = a[i];
    }

    SegmentTree st(n);
    st.build(a, 1, 1, n);

    int q = 10000;
    while (q--) {
        int type = random(1, 2);
        int l = random(1, n);
        int r = random(1, n);
        if (l > r) swap(l, r);

        if (type == 1) {
            // update
            int val = random(0, 1e9);
            st.update(l, val);
            bruteUpdate(l, val);
        } else {
            int sum1 = st.query(l, r);
            int sum2 = bruteQuery(l, r);
            assert(sum1 == sum2);
        }
    }
    cout << "Stress Test Passed" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}