#include <bits/stdc++.h>
#define int long long

using namespace std;

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
const int ms = 2e5 + 5;
int n;
int k[ms], a[ms];

void preCal() {
    For(i, 1, ms - 1) k[i] = i;
    vb prime(ms, true);
    For(i, 2, ms - 1) {
        if (prime[i]) {
            for (int j = i * i; j < ms; j += i) {
                prime[j] = true;

                int sq = i * i;
                while (k[j] % sq == 0) {
                    k[j] /= sq;
                }
            }
        }
    }
}

int nC2(int n) { return n * (n - 1) / 2; }

void solve() {
    preCal();
    cin >> n;
    For(i, 1, n) { cin >> a[i]; }
    map<int, int> mp;
    For(i, 1, n) { mp[k[a[i]]]++; }

    int sum = 0;
    for (auto [f, s] : mp) {
        // cout << f << " " << s << el;
        if (f == 0) {
            sum += s * n;
            sum -= s * (s + 1) / 2;
        } else
            sum += nC2(s);
    }
    cout << sum << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}