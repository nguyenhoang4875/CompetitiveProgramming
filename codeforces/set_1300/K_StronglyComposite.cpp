#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/group/AzS2VFYWhz/contest/482326/problem/K
 * Solution: Math
 * 
 * TC: O(n * log n)
 * MC: O(n)
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
const int ms = 1e3 + 5;
int n;
int a[ms];
map<int, int>  mCnt;

void countPrimeDivisor(int n) {
    int cnt = 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                mCnt[i]++;
                n /= i;
            }
        }
    }
    if(n > 1) mCnt[n]++;
}

void solve() {
    cin >> n;

    mCnt.clear();
    For(i, 1, n) {
        int x;
        cin >> x;
        countPrimeDivisor(x);
    } 
    int ans = 0;
    int cntPrime = 0;
    for(auto [f, s] : mCnt) {
        if(s & 1) cntPrime++;
        ans += s / 2;
    }
    ans += cntPrime / 3;
    cout << ans << el;
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