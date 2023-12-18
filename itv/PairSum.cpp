#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Given an array with n elements and sum.
 * Check if any pair that their sum is equal to sum
 * n <= 10 ^5
 *
 * Example:
 * [1, 2, 3, 9] sum = 8 => No
 * [1, 2, 4, 4] sum = 8 => Yes
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
int n, sum;

// using unordered_set
// TC: O(n)
// MC: O(n)
void solve1() {
    cin >> n;
    vi a(n);
    for (auto &x : a) cin >> x;
    cin >> sum;
    unordered_set<int> st;
    for (auto x : a) {
        if (st.find(x) != st.end()) {
            cout << "Yes" << el;
            return;
        }
        st.insert(sum - x);
    }
    cout << "No" << el;
}

// using binary search
// TC: O(n * log n)
// MC: O(n)
void solve2() {
    cin >> n;
    vi a(n);
    for (auto &x : a) cin >> x;
    cin >> sum;

    sort(all(a));
    For(i, 0, n - 1) {
        int val = sum - a[i];
        if (binary_search(a.begin() + i, a.end(), val)) {
            cout << "Yes" << el;
            return;
        }
    }

    cout << "No" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve2();
    return 0;
}