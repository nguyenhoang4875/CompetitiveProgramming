#include<bits/stdc++.h>
#define int long long 

using namespace std;

int n, m;
bool visited[105][105];
int dt[5] = {1, 0, -1, 0, 1};
int a[105][105];
int dist[105][105];
int oo = 1e18;

struct node {
    int r, c, d;
};


struct compare {
    bool operator()(node &n1, node &n2) {
        return n1.d > n2.d;
    }
};

bool in_bound(int r,int c){
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

int bfs() {
    priority_queue<node, vector<node>, compare> q;
    // queue<node> q;
    visited[1][1] = true;
    dist[1][1] = 0;
    q.push({1, 1, a[1][1]});
    while (!q.empty()) {
        node nd = q.top();
        // node nd = q.front();
        q.pop();
        visited[nd.r][nd.c] = true;
       
        int nr, nc;
        for (int i = 0; i <= 3; i++) {
            nr = nd.r + dt[i];
            nc = nd.c + dt[i+1];

            if(!in_bound(nr, nc) || visited[nr][nc]) continue;
            int newDist = nd.d + a[nr][nc];
            if(newDist < dist[nr][nc]) {
                dist[nr][nc] = newDist;
                q.push({nr, nc, newDist});
            }
        }
    }
    return dist[n][m];
}

int32_t main(){
	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0;j <= m; j++) {
            dist[i][j] = oo;
        }
    }
    cout << bfs() << endl;
}