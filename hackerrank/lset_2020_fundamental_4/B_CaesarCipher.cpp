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
int n, k;
string s;

void caesarCipher(int i) {
    char c = s[i];
    if (c >= 'a' && c <= 'z') {
        s[i] = (c - 'a' + k) % 26 + 'a';
        return;
    }
    if (c >= 'A' && c <= 'Z') {
        s[i] = (c - 'A' + k) % 26 + 'A';
        return;
    }
}

void solve() {
    cin >> n >> s >> k;
    k %= 26;
    For(i, 0, n - 1) caesarCipher(i);
    cout << s << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}