#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://acm.timus.ru/problem.aspx?space=1&num=1152
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int n, m[20], d[(1 << 20)], memo[(1 << 20)];

int solve(int mask) {
    int &ret = memo[mask];

    if (ret == -1) {
        for (int i = 0; i < n; ++i) {
            bool valid = false;

            for (int j = 0; j < 3; ++j)
                if ((mask & (1 << ((i + j) % n))) == 0) valid = true;

            if (!valid) continue;

            int mask2 = mask, x = 0;

            for (int j = 0; j < 3; ++j) mask2 |= (1 << ((i + j) % n));

            int aux = solve(mask2) + d[mask2];
            if (ret == -1 || aux < ret) ret = aux;
        }

        if (ret == -1) ret = 0;
    }

    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> m[i];

    for (int mask = 0; mask < (1 << n); ++mask) {
        d[mask] = 0;

        for (int i = 0; i < n; ++i)
            if ((mask & (1 << i)) == 0) d[mask] += m[i];
    }

    memset(memo, -1, sizeof(memo));
    cout << solve(0) << '\n';

    return 0;
}