#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

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
#define For(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define Fore(it,x) for(auto it = x.begin(); it != x.end(); ++it)

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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 30; 
int n;
char a[ms][ms];
int bac[ms][ms];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

string sMin = "";
string sMax = "";

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > n) return false;
    return true;
}

void findMinMax(int r, int c) {

    // find way
    vii ways;
    For(i, 0, 3) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(!inBound(nr, nc)) continue;
        // cout << nr << " " << nc << "\n";
        if(bac[nr][nc] == 0) {
            ways.pb({nr, nc});
        }
    }
    // debug(ways);
    // return;
    for(auto way: ways) {
    // debug(way);
    string sw = "";
    sw += a[r][c];
    sw += a[way.F][way.S];
    queue<pii> q;
    q.push(way);
    vvb visited(n + 2,vb(n + 2, false));
    visited[r][c] = true;
    visited[way.F][way.S] = true;

    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        int minBac = bac[p.F][p.S];
        bool found = false;
        int nr, nc, sr = 0, sc = 0;
        For(i, 0, 3) {
            nr = p.F + dr[i];
            nc = p.S + dc[i];
            if(!inBound(nr, nc) || visited[nr][nc]) continue;
            if(bac[nr][nc] == minBac) {
                // cout << nr << " n " << nc << '\n';
                found = true;
                sw += a[nr][nc];
                q.push({nr, nc});
                visited[nr][nc] = true;
                break;
            } else {
                sr = nr;
                sc = nc;
            }
        }
        if(!found && sr != 0) {
            // cout << sr << " s " << sc << '\n';
            sw += a[sr][sc];
            q.push({sr, sc});
            visited[sr][sc] = true;
        }
     }
     cout << sw << '\n';
    // if(sMin.compare(sw) > 0) {
    //     sMin = sw;
    // }
     sMin = min(sMin, sw);
     sMax = max(sMax, sw);
    }
}

void FindMax(int r, int c) {
}

void solve() {
    sMin = "";
    sMax = "";
    cin >> n;
    For(i, 1, n) {
        For(j, 1, n) {
            cin >> a[i][j];
            sMin += 'Z';
            sMax += 'A';
        }
    }

    For(i, 1, n) {
        For(j, 1, n) {
            int cb = oo;
            cb = min(cb, i - 1);
            cb = min(cb, n - i);
            cb = min(cb, j - 1);
            cb = min(cb, n - j);
            bac[i][j] = cb;
        }
    }
    // For(i, 1, n) {
    //     For(j , 1, n) {
    //         cout << bac[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // int rMin = 1, cMin = 1, rMax = 1, cMax = 1;
    // char chMin = a[1][1], chMax = a[1][1];
    for(auto [x, y]: vii{{1, 1 }, {1, n}, {n , 1}, {n, n}}) {
        // cout << x << " " << y << '\n';
        findMinMax(x, y);
    }
    cout << sMax << " " << sMin << '\n';

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // string a = "abc";
    // string b= "bac";
    // string c = max(a, b);
    // cout << c << endl;

    int tcs;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}