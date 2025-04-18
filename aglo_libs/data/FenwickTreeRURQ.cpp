template <typename T = int>
struct FenwickTreeRURQ {
    // MUST: base-index 1
    int n;
    vector<T> bit1, bit2;

    FenwickTreeRURQ(int _n) {
        n = _n;
        bit1.resize(n + 1, 0);
        bit2.resize(n + 1, 0);
    }

    void updatePoint(vector<T>& b, int u, T v) {
        int idx = u;
        while (idx <= n) {
            b[idx] += v;
            idx += (idx & (-idx));
        }
    }

    void updateRange(int l, int r, T v) {
        updatePoint(bit1, l, (n - l + 1) * v);
        updatePoint(bit1, r + 1, -(n - r) * v);
        updatePoint(bit2, l, v);
        updatePoint(bit2, r + 1, -v);
    }

    T getSumOnBit(vector<T>& b, int u) {
        int idx = u;
        T ans = 0;
        while (idx > 0) {
            ans += b[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }

    T prefixSum(int u) { return getSumOnBit(bit1, u) - getSumOnBit(bit2, u) * (n - u); }

    T rangeSum(int l, int r) { return prefixSum(r) - prefixSum(l - 1); }
};