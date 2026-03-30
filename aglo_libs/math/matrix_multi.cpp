template <int mod = 1'000'000'007>
struct Mat {
    vector<vector<int>> m;
    int n;
    Mat(int _n) {
        n = _n;
        m.assign(n, vector<int>(n));
    }

    void identity() {
        for (int i = 0; i < n; i++) {
            m[i][i] = 1;
        }
    }

    Mat operator*(const Mat& a) const {
        Mat res(n);
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                if (m[i][k] == 0) continue;
                for (int j = 0; j < n; ++j) {
                    res.m[i][j] = (res.m[i][j] + 1LL * m[i][k] * a.m[k][j]) % mod;
                }
            }
        }
        return res;
    }

    Mat pow(int p) const {
        Mat res(n), base = *this;
        res.identity();
        while (p > 0) {
            if (p & 1) res = res * base;
            base = base * base;
            p >>= 1;
        }
        return res;
    }
};
