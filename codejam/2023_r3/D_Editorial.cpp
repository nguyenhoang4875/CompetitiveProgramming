#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codejam.lge.com/contest/problem/1113/4
 * Solution:
 *  - Gen Monotone number
 *  - Using prefixSum to calculate the sum all of monotone numbers < n
 *  - Using binary search to find monotone of n
 *
 */

const int MAX_NUM = 1e18;
const int MOD = 1e9 + 7;

vector<int> cand;
vector<int> prefix;

void preprocess() {
    cand.clear();
    cand.push_back(0);

    queue<int> q;
    for (int i = 1; i < 10; ++i) q.push(i);

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        cand.push_back(t);
        int last_num = t % 10;
        for (int i = last_num; i < 10; ++i) {
            if (t > (MAX_NUM - i) / 10) continue;
            q.push(t * 10 + i);
        }
    }
    cand.push_back(1e18 + 1);

    prefix.clear();
    prefix.resize(cand.size());
    for (int i = 1; i < cand.size(); ++i) {
        prefix[i] = prefix[i - 1];
        prefix[i] +=
            (((cand[i] - cand[i - 1]) % MOD) * (cand[i - 1] % MOD)) % MOD;
        prefix[i] %= MOD;
    }
}

void solve(int tc) {
    int N, M;
    cin >> N >> M;

    int ans = 0;
    int lo = lower_bound(cand.begin(), cand.end(), N) - cand.begin();
    int hi = lower_bound(cand.begin(), cand.end(), M) - cand.begin();

    if (hi == 0) {
        cout << 0 << '\n';
        return;
    }

    if (lo == hi) {
        ans += ((M - N) % MOD) * (cand[hi - 1] % MOD);
        ans %= MOD;
        if (cand[hi] == M) {
            ans += M % MOD;
        } else {
            ans += cand[hi - 1] % MOD;
        }
        ans %= MOD;
    } else {
        ans += (prefix[hi - 1] - prefix[lo] + MOD) % MOD;

        if (cand[lo] > N) {
            ans += ((cand[lo] - N) % MOD) * (cand[lo - 1] % MOD);
            ans %= MOD;
        }

        ans += ((M - cand[hi - 1]) % MOD) * ((cand[hi - 1]) % MOD);
        ans %= MOD;
        if (cand[hi] == M) {
            ans += M % MOD;
        } else {
            ans += cand[hi - 1] % MOD;
        }
        ans %= MOD;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    preprocess();
    int tcs = 1;
    cin >> tcs;
    int tc = 1;
    while (tc <= tcs) solve(tc++);
}