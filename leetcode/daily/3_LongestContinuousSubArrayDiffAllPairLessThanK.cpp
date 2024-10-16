#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
 */

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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

int a[100005];

struct SegmentTree {
    int n;
    vector<int> t;

    SegmentTree(int _n) {
        n = _n;
        t.resize(4 * n, 0);
    }

    int combine(int v1, int v2) { return min(v1, v2); }

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int mid = (tl + tr) / 2;
            build(a, 2 * v, tl, mid);
            build(a, 2 * v + 1, mid + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return 2e9;
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
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }
    int query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int pos, int val) { update(1, 1, n, pos, val); }
    void set(int pos, int val) { update(pos, val - query(pos, pos)); }
};

struct SegmentTreeMax {
    int n;
    vector<int> t;

    SegmentTreeMax(int _n) {
        n = _n;
        t.resize(4 * n, 0);
    }

    int combine(int v1, int v2) { return max(v1 , v2); }

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int mid = (tl + tr) / 2;
            build(a, 2 * v, tl, mid);
            build(a, 2 * v + 1, mid + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

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
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }
    int query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int pos, int val) { update(1, 1, n, pos, val); }
    void set(int pos, int val) { update(pos, val - query(pos, pos)); }
};

int longestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        a[i + 1] = nums[i];
    }

    SegmentTree st(n);
    st.build(a, 1, 1, n);
    SegmentTreeMax stm(n);
    stm.build(a, 1, 1, n);

    // For(i, 1, n) cout << a[i] << " ";
    // cout  << el;
    auto check = [&](int len) {
        for(int i = 1; i <= n - len + 1; i++) {
            int minVal = st.query(i, i + len - 1);
            int maxVal = stm.query(i, i + len - 1);
            if(maxVal - minVal <= k)  {
                // cout << i << " " << i + len - 1 << el;
                // cout << minVal << " " << maxVal << el;
                return true;
            }
        }
        return false;
    };

    int l = 1, r = n;
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
    
}
void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(auto &x: a) cin >> x;
    cout << longestSubarray(a, k);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}