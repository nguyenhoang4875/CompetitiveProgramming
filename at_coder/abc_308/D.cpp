#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 5e2 + 5;
int n, m;
char a[ms][ms];
const string cs = "snuke";
bool found = false;
map<char, char> mp;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool inBound(int r, int c) {
    if(r < 1 or r > n or c < 1 or c > m) return false;
    return true;
}

void bfs(int r, int c, vvb& seen) {
    queue<vector<int>> q;
    q.push({r, c});
    while(!q.empty()) {
        vi cur = q.front();
        q.pop();
        int cr = cur[0];
        int cc = cur[1];
        For(i, 0, 3) {
            int nr = cr + dx[i];
            int nc = cc + dy[i];
            if(!inBound(nr, nc) or seen[nr][nc]) continue;
            if(a[nr][nc] == mp[a[cr][cc]]) {
                seen[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    mp['s'] = 'n';
    mp['n'] = 'u';
    mp['u'] = 'k';
    mp['k'] = 'e';
    mp['e'] = 's';

    For(i, 1, n) {
        For(j, 1, m) {
            cin >> a[i][j];
        }
    }

    if(a[1][1] != 's') {
        cout << "No" << el;
        return;
    }
    vvb seen(n + 1, vb(m + 1, false));
    seen[1][1] = true;
    bfs(1, 1, seen);
    if(!seen[n][m]) {
        cout << "No" << el;
        return;
    }
    cout << "Yes" << el;



}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}