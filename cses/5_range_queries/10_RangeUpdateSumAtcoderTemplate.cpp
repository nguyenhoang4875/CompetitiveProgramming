#include <bits/stdc++.h>
#define int long long
using namespace std;

template <class Info, class Tag>
class LazySegtree {
   private:
    const int n;
    vector<Info> tree;
    vector<Tag> lazy;

    /** builds the segtree values in O(N) time */
    void build(int v, int l, int r, const vector<Info> &a) {
        if (l == r) {
            tree[v] = a[l];
        } else {
            int m = (l + r) / 2;
            build(2 * v, l, m, a);
            build(2 * v + 1, m + 1, r, a);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    /** applies update x to lazy[v] and tree[v] */
    void apply(int v, int l, int r, const Tag &x) {
        tree[v].apply(x, l, r);
        lazy[v].apply(x);
    }

    /** pushes lazy updates down to the children of v */
    void push_down(int v, int l, int r) {
        int m = (l + r) / 2;
        apply(2 * v, l, m, lazy[v]);
        apply(2 * v + 1, m + 1, r, lazy[v]);
        lazy[v] = Tag();
    }

    void range_update(int v, int l, int r, int ql, int qr, const Tag &x) {
        if (qr < l || ql > r) {
            return;
        }
        if (ql <= l && r <= qr) {
            apply(v, l, r, x);
        } else {
            push_down(v, l, r);
            int m = (l + r) / 2;
            range_update(2 * v, l, m, ql, qr, x);
            range_update(2 * v + 1, m + 1, r, ql, qr, x);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    Info range_query(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) {
            return Info();
        }
        if (l >= ql && r <= qr) {
            return tree[v];
        }
        push_down(v, l, r);
        int m = (l + r) / 2;
        return range_query(2 * v, l, m, ql, qr) + range_query(2 * v + 1, m + 1, r, ql, qr);
    }

   public:
    LazySegtree() {}

    LazySegtree(int n) : n(n) {
        tree.assign(4 << __lg(n), Info());
        lazy.assign(4 << __lg(n), Tag());
    }

    LazySegtree(const vector<Info> &a) : n(a.size()) {
        tree.assign(4 << __lg(n), Info());
        lazy.assign(4 << __lg(n), Tag());
        build(1, 0, n - 1, a);
    }

    /** updates [ql, qr] with the arbitrary update chosen */
    void range_update(int ql, int qr, const Tag &x) { range_update(1, 0, n - 1, ql, qr, x); }

    /** @return result of range query on [ql, qr] */
    Info range_query(int ql, int qr) { return range_query(1, 0, n - 1, ql, qr); }
};

enum QueryType { ADD, SET, NONE };

struct Tag {
    QueryType type = NONE;
    int val = 0;
    void apply(const Tag &t) {
        if (t.type == ADD) {
            val += t.val;
            if (type != SET) {
                type = ADD;
            }
        } else if (t.type == SET) {
            type = SET;
            val = t.val;
        }
    }
};

struct Info {
    int sum = 0;
    void apply(const Tag &t, int l, int r) {
        if (t.type == SET) {
            sum = t.val * (r - l + 1);
        } else if (t.type == ADD) {
            sum += t.val * (r - l + 1);
        }
    }
};

/** @return result of joining nodes a and b together */
Info operator+(const Info &a, const Info &b) { return {a.sum + b.sum}; }

int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<Info> a(n);
    for (Info &i : a) {
        cin >> i.sum;
    }

    LazySegtree<Info, Tag> st(a);
    for (int t = 0; t < q; t++) {
        int type, a, b;
        cin >> type >> a >> b;
        a--, b--;
        if (type == 1) {
            int x;
            cin >> x;
            st.range_update(a, b, Tag{ADD, x});
        } else if (type == 2) {
            int x;
            cin >> x;
            st.range_update(a, b, Tag{SET, x});
        } else {
            cout << st.range_query(a, b).sum << '\n';
        }
    }
}