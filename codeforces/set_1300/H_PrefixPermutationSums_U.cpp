#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/gym/482326/problem/H
 * Solution: Brute force
 * - Check cases:
 *  - missing last number 
 *  - and check missing tow number in permutation
 * 
 * TC: O(n)
 * MC: O(n)
 * 
*/

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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;

bool isPermutation(vi a) {
    set<int> si;
    for(auto x: a) {
        if(x < 1 || x > n) return false;
        si.insert(x);
    }
    return sz(si) == n;
}

vi prefixSumToArray(vi &p) {
    vi res(n);
    res[0] = p[0];
    for(int i = 1; i <= n - 1; i++) {
        res[i] = p[i] - p[i - 1];
    }
    return res;
}

void solve() {
    cin >> n;
    vi a(n - 1);
    for(auto &x: a) cin >> x;

    int eLast = n *(n + 1) / 2;
    if(eLast != a.back()) {
        a.pb(eLast);
        vi b = prefixSumToArray(a);
        if(isPermutation(b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    map<int, int> cnt;
    cnt[a[0]]++;
    For(i, 1, n - 2) {
        cnt[a[i] - a[i-1]]++;
    }

    vi cntGt1;
    for(auto [f, s]: cnt) {
        if(s > 1) {
            cntGt1.pb(f);
        }
    }
    if(cntGt1.size() > 1) {
        cout << "NO\n";
        return;
    }

    if(cntGt1.size() == 1) {
        int x1 = cntGt1[0];
        if(cnt[x1] > 2) {
            cout << "NO\n";
            return;
        }
    }
    vi cnt0;
    For(i, 1, n) {
        if(cnt[i] == 0) {
            cnt0.push_back(i);
        }
    }

    if(cnt0.size() != 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}