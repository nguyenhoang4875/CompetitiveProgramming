#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: What should be minimum number of people that should be present in a
 * hall so that there's atleast n% chance of two people having the same birthday
 *
 * Example: n = 50 => 23 people
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
const int num_day_of_year = 365;

void solve() {
    cin >> n;
    if (n == 100) {
        cout << 366 << el;
        return;
    }
    double prob_diff_birthday = 1;
    double np = 1.0 * n / 100;
    int cnt = 1;
    int num_day = 364;
    while (prob_diff_birthday > 1 - np) {
        prob_diff_birthday *= 1.0 * num_day / num_day_of_year;
        num_day--;
        cnt++;
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}