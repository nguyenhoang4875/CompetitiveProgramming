template <typename T = int>
struct SparseTable {
    /*
    MUST READ: based-index = 1
    query(l, r) check value in range [l, r] can be overlap
    Only apply for value can be duplicate: min, max, gcd, or, and
    NOT Apply for: add, multi, divide
    */
    int n, LG;
    vector<vector<T>> up;  // up[i][j]: combine value: [j, j + 2^i - 1]

    SparseTable(const vector<T>& a, int _n) {
        n = _n;
        LG = __lg(n) + 1;
        up.assign(LG + 1, vector<T>(n + 1));
        build(a);
    }

    void build(const vector<T>& a) {
        for (int i = 1; i <= n; ++i) up[0][i] = a[i];

        for (int j = 1; j <= LG; ++j) {
            int mask = (1 << j);
            for (int i = 1; i <= n - mask + 1; ++i) {
                up[j][i] = combine(up[j - 1][i], up[j - 1][i + mask / 2]);
            }
        }
    }

    // Combine allow overlap only: min, max, gcd, or, and, ...
    T combine(T v1, T v2) { return min(v1, v2); }

    T query(int l, int r) {
        int k = __lg(r - l + 1);
        return combine(up[k][l], up[k][r - (1 << k) + 1]);
    }
};