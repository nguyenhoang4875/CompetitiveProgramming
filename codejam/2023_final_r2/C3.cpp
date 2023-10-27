#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl

#if 1
template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x)os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")" ;
}
#endif

template<typename T>
void check_here(T x){
    cout << "------------- " << x << " -------------" << endl;
}

//*** define ***//
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = (int)a; i >= (int)b; i--)
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

const int oo = 1e9, mod = 1e9 + 7;
const int ms = 300 + 5;
int r, c, n, sr, sc;
char a[ms][ms];
// int dist[ms][ms];
bool visited[ms][ms];

struct node {
    int x, y, d;
};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool inBound(int x, int y) {
    if(x < 1 || x > r || y < 1 || y > c) return false;
    return true;
}

void bfs(int sr, int sc, vvi &dist) {
    dist.resize(r + 5, vi(c + 5, oo));
   for(int i = 1; i <= r; i++) {
       for(int j = 1; j <= c; j++) {
            dist[i][j] = oo;
            visited[i][j] = false;
        }
    }
    queue<node> q;
    q.push({sr, sc, 0});
    visited[sr][sc] = true;
    dist[sr][sc] = 0;
    while(!q.empty()) {
        node cn = q.front();
        q.pop();

        int nx, ny;
        for(int i = 0; i <= 3; i++) {
            nx = cn.x + dx[i];
            ny = cn.y + dy[i];
            if(!inBound(nx, ny) || visited[nx][ny] || a[nx][ny] == 'W') continue;
            int newDist = cn.d + 1;
            dist[nx][ny] = newDist;
            q.push({nx, ny, newDist});
            visited[nx][ny] = true;
        }
    }

}

int calDistance(vii& points, vvi& dist) {
    int ans = 0;
    for(auto e: points) {
        int tmp = dist[e.F][e.S];
        ans += dist[e.F][e.S];
    }
    return ans;
}

void solve() {
    cin>> r >> c >> n >> sr >> sc;
    vii points;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        points.pb({x, y});
    }
    vii walls;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c;j++) {
            cin >> a[i][j];
            if(a[i][j] == 'W') walls.pb({i, j});
        }
    }

    vvi vDist[n + 5];

    bfs(sr, sc, vDist[0]);

    int originVal = calDistance(points, vDist[0]);
    for(int i = 0; i < n; i++) {
        int x = points[i].F;
        int y = points[i].S;
        bfs(x, y, vDist[i + 1]);
    }
    int vAns = 0;
    for(int k = 1; k <= n; k++) {
        int cnt = 0;
        for(auto wall: walls) {
            int minOfS = oo;
            int minOfPoint = oo;
            int nx, ny;
            for(int i = 0; i <= 3; i++) {
               nx = wall.F + dx[i];
               ny = wall.S + dy[i];
               if(!inBound(nx, ny) || a[nx][ny] == 'W') continue;
            //    debug(nx);
            //    debug(ny);
               minOfS = min(minOfS, vDist[0][nx][ny]);
               minOfPoint = min(minOfPoint, vDist[k][nx][ny]);
            }
            int temp = minOfPoint + minOfS + 2;
            int curVal = vDist[0][points[k- 1].F][points[k - 1].S];
            int diff = 0;
            if(temp < curVal) {
                 diff = curVal - temp;
                //  debug(diff);
            }
            vAns += diff;

        }
    }
    cout << originVal << " " << vAns << "\n";

    // for(auto e: points) {
    //     int tmp = dist[e.F][e.S];
    //     originVal += dist[e.F][e.S];
    // }

    // cout << originVal<<'\n';

    // cout << "------------------------" << endl;
    // for(auto e: walls) cout << e.F << " wall " << e.S << "\n";
    // int vNet = 0;
    // for(auto e: walls) {
    //     // cout << e.F << " wall " << e.S << '\n';
    //     a[e.F][e.S] = '.';
    //     bfs(sr, sc);
    //     int temp = originVal -  calDistance(points);
    //     // cout << "temp = " << temp << "\n";
    //     vNet += temp;
    //     a[e.F][e.S] = 'W';
    // }
    // cout << originVal << " " << vNet << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}