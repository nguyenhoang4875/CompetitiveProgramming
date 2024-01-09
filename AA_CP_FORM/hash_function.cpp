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
const int ms = 1e5 + 5;

struct custom_hash {
    static uint64_t splitMix64(uint64_t x) {
        x = 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(const uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitMix64(x + FIXED_RANDOM);
    }
};

struct custom_hash_pair {
    static uint64_t splitMix64(uint64_t x) {
        x = 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(const pair<uint64_t, uint64_t> &p) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitMix64(p.first + FIXED_RANDOM) ^
               (splitMix64(p.second + FIXED_RANDOM) >> 1);
    }
};

void solve() {
    unordered_map<int, int, custom_hash> mii = {{-1, 1}, {0, 1}, {1, 1}};
    unordered_map<pii, int, custom_hash_pair> mpi = {
        {{-1, 1}, 1}, {{0, 1}, 1}, {{1, 1}, 1}};
    for (auto e : mii) {
        cout << e.F << " " << e.S << el;
    }
    for (auto e : mpi) {
        cout << e.F.F << " " << e.F.S << " " << e.S << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}