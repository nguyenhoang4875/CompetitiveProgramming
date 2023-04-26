#include<bits/stdc++.h>
#define int long long 

using namespace std;

struct node {
	int x,y;
	int d;
};

int n,m;
char a[101][101];
int dist[101][101];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};
vector<node> points;

bool isValid(int x,int y){
	return x >= 0 && x < n && y >= 0 && y < m;	
}

int bfs(node s, node f){
	queue<node> q;

	s.d = 0; // set distance start = 0
	q.push(s); // push to queue
	bool visited[n][m];
	for(int i = 0; i < n; i++){
		for(int j=0; j < m; j++){
			visited[i][j] = false;
		}
	}
	while(!q.empty()){
		node u = q.front();
		q.pop();
		// if get destination: return current distance plus 1: u.d + 1
		if(u.x ==f.x && u.y == f.y) return u.d + 1;

		for(int k=0; k<4; k++) {
			int nx=u.x+dx[k];
			int ny=u.y+dy[k];

			// continue if meet any conditions
			if(!isValid(nx, ny) || visited[nx][ny] || a[nx][ny] == '+') continue;

			visited[nx][ny] = true; // mark visited
			q.push({nx, ny, u.d + 1});  // push to queue
		}
	}
	return 0;
}

int32_t main(){
	cin >> n >> m;
	points.clear();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m;j++){
			cin >> a[i][j];
			if(a[i][j] >= '1' && a[i][j] <= '9') points.push_back({i,j});
		}
	}

    int sum=0;
    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = i + 1; j < points.size(); j++) {
        	sum += bfs(points[i], points[j]);
        }
    }
	cout<<sum<<endl;
	return 0;
}