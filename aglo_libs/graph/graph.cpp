#include <iostream>
#include <string>
#include <math.h>

#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>

#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;

int N; //size
vector<int> dr {0, 1, 0, -1};
vector<int> dc {-1, 0, 1, 0};


//******************* BFS *******************//

//O(V +E)
// BFS with adjcent list, check bipartite graph
vector<vector<int>> adjList(N+10, vector<int>());
vector<int> color(N+10, 10);
bool check = true;
void BFS_AdjList(){
    for(int i = 1; i <= N && color[i] == 10; ++i){
        queue<int> s;
        s.push(i);
        color[i] = 0;
        while(!s.empty()){
            int cur = s.front();
            s.pop();
            for(int j = 0; j < adjList[cur].size(); ++j){
                int tmp = adjList[cur][j];
                if(color[tmp] == 10){
                    color[tmp] = 1 - color[cur];
                    s.push(tmp);
                }
                else if(color[tmp] == color[cur]){
                    check = false;
                    break;
                }
            }
            if(check == false) break;
        }
        if(check == false) break;
    }
}

// BFS with grid, find the single-source-shortest-path in a grid map (unweight grid map)
char grid_map[510][510]; //grid map
int H, W; // height and width of grid map
bool way = false;
void BFS_Grid(){
    queue<pair<int, int>> s;
	int step[510][510];
	s.push(make_pair(0, 0));
	step[0][0] = 0;
	grid_map[0][0] = 'X';
	
	while(!s.empty()){
		pair<int, int> cur = s.front();
		s.pop();
		for(int i = 0; i < 4; ++i){
			int cx = cur.first + dr[i];
			int cy = cur.second + dc[i];
			if(cx >= 0 && cy >= 0 && cx < H && cy < W){
				if(grid_map[cx][cy] != 'X'){
					s.push(make_pair(cx, cy));
					step[cx][cy] = step[cur.first][cur.second] + 1;
				}
				grid_map[cx][cy] = 'X';
				if(cx == H-1 && cy == W-1){
					way = true;
					break;
				}
			}
		}
	}
}

// Flood Fill, counting the number of connected components
#define R 100
#define C 100 // size of grid map
int grid[R][C]; // grid map
int floodfill(int r, int c, char c1, char c2) { // returns the size of CC
    if (r < 0 || r >= R || c < 0 || c >= C) return 0; // outside grid
    if (grid[r][c] != c1) return 0; // does not have color c1
    int ans = 1; // adds 1 to ans because vertex (r, c) has c1 as its color
    grid[r][c] = c2; // now recolors vertex (r, c) to c2 to avoid cycling!
    for (int d = 0; d < 8; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans; // the code is neat due to dr[] and dc[]
}

//******************* DFS *******************//

//O(V +E)
#define UNVISITED -1
#define VISITED 0
vector<vii> AdjList;
vi dfs_num; // global variable, initially all values are set to UNVISITED
void DFS(int u){
    dfs_num[u] = VISITED; // important: we mark this vertex as visited
    for (int j = 0; j < (int)AdjList[u].size(); j++) { // default DS: AdjList
        pii v = AdjList[u][j]; // v is a (neighbor, weight) pair
        if (dfs_num[v.first] == UNVISITED) // important check to avoid cycle
            DFS(v.first); // recursively visits unvisited neighbors of vertex u
    }
}

//******************* MST *******************//

//Kruskal, using EdgeList , O(ElogV)
class UnionFind{
public:
    UnionFind(int N){}
    bool isSameSet(int, int){}
    void unionSet(int, int){}
};
vector< pair<int, pii> > EdgeList; // (weight, two vertices) of the edge
int E; //number of edge
int u, v, w; //first vertex - second vertex of edge, weight of edge 
void Kruskal(){
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w); // read the triple: (u, v, w)
        EdgeList.push_back(make_pair(w, pii(u, v)));
    } // (w, u, v)
    sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
    // note: pair object has built-in comparison function
    int mst_cost = 0;
    UnionFind UF(V); // all V are disjoint sets initially
    for (int i = 0; i < E; i++) { // for each edge, O(E)
        pair<int, pii> front = EdgeList[i];
        if (!UF.isSameSet(front.second.first, front.second.second)) { // check
            mst_cost += front.first; // add the weight of e to MST
            UF.unionSet(front.second.first, front.second.second); // link them
        }
    }
}

//Prim, using Adjcent List, O(ElogV)
//take a starting vertex, flags it as "taken", enqueues a pair of information into a priority queue (weight "w" and other end point "v")
vi taken; // global boolean flag to avoid cycle
priority_queue<pii> pq; // priority queue to help choose shorter edges
// note: default setting for C++ STL priority_queue is a max heap
void process(int vtx) { // so, we use -ve sign to reverse the sort order
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        pii v = AdjList[vtx][j];
        if (!taken[v.first]) pq.push(pii(-v.second, -v.first));
    }
} // sort by (inc) weight then by (inc) id
int mst_cost;
void Prim(){
    taken.assign(V, 0); // no vertex is taken at the beginning
    process(0); // take vertex 0 and process all edges incident to vertex 0
    mst_cost = 0;
    while (!pq.empty()) { // repeat until V vertices (E=V-1 edges) are taken
        pii front = pq.top(); pq.pop();
        u = -front.second, w = -front.first; // negate the id and weight again
        if (!taken[u]) // we have not connected this vertex yet
            mst_cost += w, process(u); // take u, process all edges incident to u
    } // each edge is in pq only once!
    printf("MST cost = %d (Prim’s)\n", mst_cost);
}

//******************* SSSP *******************//

// SSSP in unweighted graph using Adjcent List
#define INF INT_MAX
int V; // number of vertex
int s; // source vertex
int t; // destination vertex
vi p; // vector of parent of a vertex
vector<vii> AdjList;
void printPath(int u) { // extract information from ‘vi p’
    if (u == s) {
        printf("%d", s);
        return;
    } // base case, at the source s
    printPath(p[u]); // recursive: to make the output format: s -> ... -> t
    printf(" %d", u);
}
int V; // number of vertex
void SSSP_unw(){
    vi dist(V, INF); //vector of distance from s to vertexs
    dist[s] = 0; // distance from source s to s is 0
    queue<int> q;
    q.push(s);
    vi p; // addition: the predecessor/parent vector
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            pii v = AdjList[u][j];
            if (dist[v.first] == INF) {
                dist[v.first] = dist[u] + 1;
                p[v.first] = u; // addition: the parent of vertex v.first is u
                q.push(v.first);
            }
        }
    }
    printPath(t);
    printf("\n");
}

// ********** DIJKTRA ALGORITHM **********//
// O(E + VlogV)
// SSSP in weighted grapth using Adjcent List
void SSSP_wei(){
    vi dist(V, INF); dist[s] = 0; // INF = 1B to avoid overflow
    priority_queue< pii, vector<pii>, greater<pii> > pq; pq.push(pii(0, s));
    while (!pq.empty()) { // main loop
        pii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
        int d = front.first, u = front.second;
        if (d > dist[u]) continue; // this is a very important check
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            pii v = AdjList[u][j]; // all outgoing edges from u
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second; // relax operation
                pq.push(pii(dist[v.first], v.first));
            }
        }
    }
}

// ********** BELLMAN-FORD ALGORITHM **********//
// O(V^3) using Adjacency Matrix
// O(VE) using Adjacency List
vi dist(V, INF); dist[s] = 0;
for (int i = 0; i < V - 1; i++) // relax all E edges V-1 times
	for (int u = 0; u < V; u++) // these two loops = O(E), overall O(VE)
		for (int j = 0; j < (int)AdjList[u].size(); j++) {
			ii v = AdjList[u][j]; // record SP spanning here if needed
			dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
		}

//******************* FLOW *******************//