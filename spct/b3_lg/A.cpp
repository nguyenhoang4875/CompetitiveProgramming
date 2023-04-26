#include<bits/stdc++.h>
#define int long long 

using namespace std;

int n, m;
bool visited[105][105];
int dt[5] = {1, 0, -1, 0, 1};
char a[105][105];

struct node {
    int r, c, d;
};

bool in_bound(int r,int c){
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

int bfs(int sr, int sc, int dr, int dc) {
    queue<node> q;
    visited[sr][sc] = true;
    q.push({sr, sc, 0});
    while (!q.empty()) {
        node nd = q.front();
        q.pop();
        if(nd.r == dr && nd.c == dc) {
            return nd.d;
        }
        int nr, nc;
        for (int i = 0; i <= 3; i++) {
            nr = nd.r + dt[i];
            nc = nd.c + dt[i+1];

            if(!in_bound(nr, nc) || visited[nr][nc] || a[nr][nc] == '+') continue;
            visited[nr][nc] = true;
            q.push({nr, nc, nd.d + 1});
        }
    }



    return 0;
}

int32_t main(){
	cin >> n >> m;
    int sr, sc, dr, dc;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            
            if(a[i][j] == '+') {
                visited[i][j] == true;
            } 
            else if (a[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            else if (a[i][j] == 'D') {
                dr = i;
                dc = j;
            }
        }
    }
    cout << bfs(sr, sc, dr, dc) << endl;
}