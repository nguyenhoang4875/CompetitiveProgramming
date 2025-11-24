#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

vi a;
int n, k;

int binarySearch() {
    int l = *max_element(all(a)), r = accumulate(all(a), 0LL);
    int ans = r;

    auto check = [&](int val) {
        int cnt = 0;
        int sum = 0;
        for (auto& e : a) {
            sum += e;
            if (sum > val) {
                sum = e;
                ++cnt;
            }
        }
        return cnt <= k;
    };

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

vvi memo;
int f(int pos, int night_left) {
    if (memo[pos][night_left] != -1) return memo[pos][night_left];
    if (pos == n) return oo;
    // base case
    if (night_left == 0) {
        return accumulate(a.begin() + pos, a.end(), 0LL);
    }
    int ans = oo;
    int sum_day = 0;
    for (int i = pos; (i < n) and (i - pos + night_left < n); ++i) {
        sum_day += a[i];
        int sub = f(i + 1, night_left - 1);
        int cur = max(sum_day, sub);
        ans = min(ans, cur);
    }
    return memo[pos][night_left] = ans;
};

int tab() {
    vvi dp(n + 1, vi(k + 1, oo));

    dp[n][0] = 0;

    Rof(pos, n - 1, 0) {
        Rep(night_left, k + 1) {
            if (night_left == 0) {
                int sum = 0;
                For(i, pos, n - 1) sum += a[i];
                dp[pos][night_left] = sum;
                continue;
            }

            int sum_day = 0;
            for (int i = pos; (i < n) and (i - pos + night_left < n); ++i) {
                sum_day += a[i];
                if (dp[i + 1][night_left - 1] != oo) {
                    int cur = max(sum_day, dp[i + 1][night_left - 1]);
                    dp[pos][night_left] = min(dp[pos][night_left], cur);
                }
            }
        }
    }
    return dp[0][k];
}

void solve() {
    while (cin >> n >> k) {
        n += 1;
        a.assign(n, 0);

        Rep(i, n) cin >> a[i];

        // binary search
        cout << binarySearch() << el;

        // dp top down
        // memo.assign(n + 1, vi(k + 1, -1));
        // cout << f(0, k) << el;

        // dp bottom up
        // cout << tab() << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}