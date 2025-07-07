#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int) (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int) (b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

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
const int ms = 100 + 5;
char a[ms][ms];
int n;
bool seen[ms][ms];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0 ,0};

void bfs(int r, int c, char color) {
    queue<pair<int, int>> q;
    q.push({r, c});
    seen[r][c] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.F + dx[i];
            int ny = cur.S + dy[i];
            if(nx < 1 or nx > n or ny < 1 or ny > n) continue;
            if(seen[nx][ny] or a[nx][ny] != color) continue;
            seen[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}


void solve() {
    cin >> n;
    int cr = 0, cg = 0, cb = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'R') cr++;
            else if(a[i][j] == 'G') cg++;
            else cb++;
        }
    }

    map<char, int> cnt;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!seen[i][j]) {
                bfs(i, j, a[i][j]);
                cnt[a[i][j]]++;
            }
        }
    }

    vector<vector<int>> v;
    v.push_back({cnt['R'], cr, 'R'});
    v.push_back({cnt['G'], cg, 'G'});
    v.push_back({cnt['B'], cb, 'B'});

    sort(v.begin(), v.end(), [&](vi p1, vi p2) {
        if(p1[0] == p2[0]) {
            if(p1[1] == p2[1]) {
                return p1[2] > p2[2];
            }
            return p1[1] > p2[1];
        }
        return p1[0] > p2[0];
    });
    cout << char(v[0][2]) << " " << v[0][0] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}