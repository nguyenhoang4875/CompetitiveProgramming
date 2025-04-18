template <typename T = int>
struct FenwickTree {
    // MUST: base-index 1
    int n;
    vector<T> t;
    FenwickTree(int _n) {
        n = _n;
        t.resize(n + 1, 0);
    }
    // custom this function if needed (ACCUMULATE ONLY)
    T combine(T x, T y) { return x + y; }

    void update(int i, T val) {
        while (i <= n) {
            t[i] = combine(t[i], val);
            i += i & (-i);
        }
    }
    T prefixSum(int i) {
        T val = 0;
        while (i > 0) {
            val = combine(val, t[i]);
            i -= i & -i;
        }
        return val;
    }
    T query(int l, int r) { return prefixSum(r) - prefixSum(l - 1); }

    void set(int i, T val) { update(i, val - query(i, i)); }
};