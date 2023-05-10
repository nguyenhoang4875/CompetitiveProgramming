#include<bits/stdc++.h>
#define int long long 

using namespace std;

struct node {
	int x,y;
	int d;
};

int n, m, k;
char a[105][105];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};
int dist[15][15];
int g[15];
int used[15];
int ans = 1e9;


bool isValid(int r,int c){
	if(r < 1 || r > n || c < 1 || c > m) return false;
	return true;
}

int bfs(node s, node f){
	bool visited[n+5][m+5];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			visited[i][j] = false;
		}
	}
	queue<node> q;
	q.push(s); // push to queue
	visited[s.x][s.y] = true;
	while(!q.empty()){
		node u = q.front();
		q.pop();
		if(u.x ==f.x && u.y == f.y) return u.d;

		for(int k=0; k<4; k++) {
			int nx= u.x + dx[k];
			int ny= u.y + dy[k];

			// continue if meet any conditions
			if(!isValid(nx, ny) || visited[nx][ny] || a[nx][ny] == '#') continue;

			visited[nx][ny] = true; // mark visited
			q.push({nx, ny, u.d + 1});  // push to queue
		}
	}
	return -1;
}

void calculate(int n) {
	int res = 0;
	for(int i = 1; i <= n - 1; i++) {
	    int temp = dist[g[i]][g[i+1]];
	    if(temp == -1) {
	        ans = -1;
	        return;
	    }
		res += temp;
	}
	res = max(res, -1LL);
	ans = min(ans, res);
}

void gen(int s, int n) {
	if(s > n) {
		calculate(n);
		return;
	} else {
		for (int val = 1; val <= n; val++) {
			if(used[val]) continue;
			g[s] = val;
			used[val] = true;
			gen(s + 1, n);
			used[val] = false;
		}
	}
}

int32_t main(){
	cin >> n >> m >> k;
	vector<node> vn(k+1);
	int idx = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			if(a[i][j] >= '1' && a[i][j] <= '9'){
				vn[idx++] = {i, j , 0};
			} 
		}
	}
	
	if(k == 1) {
	    cout << "0" << endl;
	    return 0;
	}

    for (int i = 1; i <= k - 1; i++) {
        for (int j = i + 1; j <= k ; j++) {
        	int val = bfs(vn[i], vn[j]);
			dist[i][j] = val;
			dist[j][i] = val;
        }
    }
	gen(1, k);
	cout << ans << endl;
	return 0;
}