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
int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

int solve() {
    int n;
    cin >> n;
    int mega_mask = 0;
    Rep(i, n) {
        char x;
        cin >> x;
        mega_mask |= ((x - '0') << i);
    }

    vi a(n);  // can kill if use i-th weapon
    Rep(i, n) {
        int m = 0;
        Rep(j, n) {
            char x;
            cin >> x;
            m |= ((x - '0') << j);
        }
        a[i] = m;
    }

    int max_mask = (1LL << n) - 1;
    vi memo(max_mask + 1, -1);

    function<int(int, int)> f = [&](int mask, int can_kill) {
        if (memo[mask] != -1) return memo[mask];
        if (mask == max_mask) return 1LL;

        int ans = 0;
        Rep(u, n) {
            if (!getBit(mask, u) and getBit(can_kill, u)) {
                ans += f(mask | (1LL << u), can_kill | a[u]);
            }
        }
        return memo[mask] = ans;
    };

    return f(0, mega_mask);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    For(i, 1, tcs) { cout << "Case " << i << ": " << solve() << el; }
    return 0;
}