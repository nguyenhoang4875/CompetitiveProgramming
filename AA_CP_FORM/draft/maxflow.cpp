// 2020 Online round1 - problem B

#include <iostream>
#include <string>
#include <math.h>

#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include <algorithm>
#include <utility>
#include <limits>

//******************** typedef *********************//

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;

#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)

//******************* debug(x) *********************//
//****https://codeforces.com/blog/entry/68920****//

//#define watch(x) cout << "[" << #x << "]" << " : " << (x) << endl
//#define getName(var) #var
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl

#if 0
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

//****************** CODING **********************//

#define MF 11000
#define INF 11000

vector<unordered_map<int, int>> adjList(12);
vector<int> vparent;
int f, mf;
int s = 0;
int t = 11;

void augment(int v, int minEdge){  // traverse BFS spanning tree from s.t
	if (v == s){
		f = minEdge;
		return;
	}  // record minEdge in a global var f
	else if(vparent[v] != -1){
		augment(vparent[v], min(minEdge, adjList[vparent[v]][v]));
		adjList[vparent[v]][v] -= f;
		adjList[v][vparent[v]] += f;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while(T--){
		// cout << "hello" << endl;
		f = 0;
		mf = 0;
		adjList.clear();
		adjList.assign(12, unordered_map<int, int>());
		int n, nA, nB, nC;
		cin >> n >> nA >> nB >> nC;
		int mA, mB, mC, tmp;
		unordered_set<int> usA, usB, usC, usAB, usBC, usCA, usABC;
		cin >> mA;
		FOR(i, 0, mA){
			cin >> tmp;
			usA.insert(tmp);
		}
		cin >> mB;
		FOR(i, 0, mB){
			cin >> tmp;
			if(usA.count(tmp)){
				usA.erase(tmp);
				usAB.insert(tmp);
			}
			else{
				usB.insert(tmp);
			}
		}
		cin >> mC;
		FOR(i, 0, mC){
			cin >> tmp;
			if(usA.count(tmp)){
				usA.erase(tmp);
				usCA.insert(tmp);
			}
			else if(usB.count(tmp)){
				usB.erase(tmp);
				usBC.insert(tmp);
			}
			else if(usAB.count(tmp)){
				usAB.erase(tmp);
				usABC.insert(tmp);
			}
			else{
				usC.insert(tmp);
			}
		}
		// debug(usA);
		// debug(usB);
		// debug(usC);
		// debug(usAB);
		int sA = usA.size();
		int sB = usB.size();
		int sC = usC.size();
		int sAB = usAB.size();
		int sBC = usBC.size();
		int sCA = usCA.size();
		int sABC = usABC.size();

		adjList[0].insert({1, sA});
		adjList[0].insert({2, sB});
		adjList[0].insert({3, sC});
		adjList[0].insert({4, sAB});
		adjList[0].insert({5, sBC});
		adjList[0].insert({6, sCA});
		adjList[0].insert({7, sABC});

		adjList[1].insert({0, 0});
		adjList[1].insert({8, INF});
		adjList[2].insert({0, 0});
		adjList[2].insert({9, INF});
		adjList[3].insert({0, 0});
		adjList[3].insert({10, INF});

		adjList[4].insert({0, 0});
		adjList[4].insert({8, INF});
		adjList[4].insert({9, INF});

		adjList[5].insert({0, 0});
		adjList[5].insert({9, INF});
		adjList[5].insert({10, INF});

		adjList[6].insert({0, 0});
		adjList[6].insert({10, INF});
		adjList[6].insert({8, INF});

		adjList[7].insert({0, 0});
		adjList[7].insert({8, INF});
		adjList[7].insert({9, INF});
		adjList[7].insert({10, INF});

		adjList[8].insert({1, 0});
		adjList[8].insert({4, 0});
		adjList[8].insert({6, 0});
		adjList[8].insert({7, 0});
		adjList[8].insert({11, nA});

		adjList[9].insert({2, 0});
		adjList[9].insert({4, 0});
		adjList[9].insert({5, 0});
		adjList[9].insert({7, 0});
		adjList[9].insert({11, nB});

		adjList[10].insert({3, 0});
		adjList[10].insert({5, 0});
		adjList[10].insert({6, 0});
		adjList[10].insert({7, 0});
		adjList[10].insert({11, nC});

		adjList[11].insert({8, 0});
		adjList[11].insert({9, 0});
		adjList[11].insert({10, 0});

		// debug(adjList);

		mf = 0; // mf stands for max_flow
		while(1){ // O(VE^2) (actually O(V^3 E) Edmonds Karp’s algorithm
			f = 0;// run BFS, compare with the original BFS shown in Section 4.2.2
			vi dist(12, INF);
			dist[s] = 0;
			queue<int> q; q.push(s);
			vparent.assign(12, -1);      // record the BFS spanning tree, from s to t!
			while(!q.empty()){
				int u = q.front(); q.pop();
				if (u == t) break; // immediately stop BFS if we already reach sink t
				for (auto itr : adjList[u]){            // note: this part is slow
					int v = itr.first;
					if (adjList[u][v] > 0 && dist[v] == INF){
						dist[v] = dist[u] + 1;
						q.push(v);
						vparent[v] = u;      // 3 lines in 1!
					}
				}
			}
			augment(t, INF);   // find the min edge weight ‘f’ in this path, if any
			if (f == 0) break; // we cannot send any more flow (‘f’ = 0), terminate
			mf += f;            // we can still send a flow, increase the max flow!
		}
		cout << mf << "\n";
		for(auto itr : adjList[8]){
			// cout << itr.first <<", " << itr.second << "\n";
			if(itr.first != 11){
				tmp = (itr.second);
				// debug(tmp);
				FOR(i, 0, tmp){
					if(itr.first == 1 && usA.size() > 0){
						cout << *usA.begin() << " " << "A" << "\n";
						usA.erase(usA.begin());
					}
					else if(itr.first == 4 && usAB.size() > 0){
						cout << *usAB.begin() << " " << "A" << "\n";
						usAB.erase(usAB.begin());
					}
					else if(itr.first == 6 && usCA.size() > 0){
						cout << *usCA.begin() << " " << "A" << "\n";
						usCA.erase(usCA.begin());
					}
					else if(itr.first == 7 && usABC.size() > 0){
						cout << *usABC.begin() << " " << "A" << "\n";
						usABC.erase(usABC.begin());
					}
				}
			}
		}
		for(auto itr : adjList[9]){
			// cout << itr.first <<", " << itr.second << "\n";
			if(itr.first != 11){
				tmp = (itr.second);
				// debug(tmp);
				FOR(i, 0, tmp){
					if(itr.first == 2 && usB.size() > 0){
						cout << *usB.begin() << " " << "B" << "\n";
						usB.erase(usB.begin());
					}
					else if(itr.first == 4 && usAB.size() > 0){
						cout << *usAB.begin() << " " << "B" << "\n";
						usAB.erase(usAB.begin());
					}
					else if(itr.first == 5 && usBC.size() > 0){
						cout << *usBC.begin() << " " << "B" << "\n";
						usBC.erase(usBC.begin());
					}
					else if(itr.first == 7 && usABC.size() > 0){
						cout << *usABC.begin() << " " << "B" << "\n";
						usABC.erase(usABC.begin());
					}
				}
			}
		}
		// debug(tmp);
		// check_here(13);
		for(auto itr : adjList[10]){
			if(itr.first != 11){
				tmp = (itr.second);
				FOR(i, 0, tmp){
					if(itr.first == 3 && usC.size() > 0){
						cout << *usC.begin() << " " << "C" << "\n";
						usC.erase(usC.begin());
					}
					else if(itr.first == 5 && usBC.size() > 0){
						cout << *usBC.begin() << " " << "C" << "\n";
						usBC.erase(usBC.begin());
					}
					else if(itr.first == 6 && usCA.size() > 0){
						cout << *usCA.begin() << " " << "C" << "\n";
						usCA.erase(usCA.begin());
					}
					else if(itr.first == 7 && usABC.size() > 0){
						cout << *usABC.begin() << " " << "C" << "\n";
						usABC.erase(usABC.begin());
					}
				}
			}
		}
	}
	return 0;
}

//**************** AN EXAMPLE OF MAX FLOW ****************//
// 2020 Final - problem E
// Fastest solution ???

#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
using pii = pair<int, int>;
int const INF_FLOW = int(2e9);
 
/*
 * Getting maximum flow: Edmond-Karp based implementation - O(min(fE, VE^2))
 */
struct Maxflow {
    int ne;
    vector<int> par;
    vector<vector<int>> adj;
    vector<vector<int>> cap;
    vector<vector<int>> flow;
    int snd, tnd;
 
    Maxflow(int n) : ne(n) {
        par.resize(n);
        cap.resize(n, vector<int>(n, 0));
        flow.resize(n, vector<int>(n, 0));
        adj.resize(n, vector<int>(n, 0));
        snd = 0;
        tnd = n - 1;
    }
 
    void addEdge(int u, int v, int c) {
        adj[u][v] = 1;
        adj[v][u] = 1;
        cap[u][v] += c;
    }
 
    int bfs() {
        fill(par.begin(), par.end(), -1);
        par[snd] = -2;
        queue<pii> q;
        q.push({snd, INF_FLOW});
        while (!q.empty()) {
            int cur = q.front().first;
            int f = q.front().second;
            q.pop();
 
            for (int nxt = 0; nxt < ne; ++nxt) {
                if (adj[cur][nxt] == 0) continue;
 
                if (par[nxt] == -1 && cap[cur][nxt] - flow[cur][nxt] > 0) {
                    par[nxt] = cur;
                    int new_f = min(f, cap[cur][nxt] - flow[cur][nxt]);
                    if (nxt == tnd) return new_f;
                    q.push({nxt, new_f});
                }
            }
        }
        return 0;
    }
 
    int findMaxflow() {
        int totflow = 0;
        int f = 0;
        while ((f = bfs())) {
            totflow += f;
            int cur = tnd;
            while (cur != snd) {
                int prv = par[cur];
                flow[prv][cur] += f;
                flow[cur][prv] -= f;
                cur = prv;
            }
        }
        return totflow;
    }
 
    void getResidual(int nd, vector<bool>& vis) {
        vis[nd] = true;
        for (int i = 0; i < ne; ++i) {
            if (cap[nd][i] - flow[nd][i] && !vis[i]) getResidual(i, vis);
        }
    }
};
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    // 0: source(attack)
    // [1,n]: employee
    // n+1: sink(defence)
    Maxflow mf(n + 2);
    int tot = 0;
    int atk, def;
    for (int i = 0; i < n; ++i) {
        cin >> atk >> def;
        mf.addEdge(0, i + 1, atk);
        mf.addEdge(i + 1, n + 1, def);
        tot += atk + def;
    }
 
    int num, s;
    for (int i = 0; i < m; ++i) {
        cin >> num >> s;
        vector<int> v(num);
        for (int j = 0; j < num; ++j) cin >> v[j];
        for (int j = 0; j < num; ++j) {
            for (int k = j + 1; k < num; ++k) {
                mf.addEdge(v[j], v[k], s);
                mf.addEdge(v[k], v[j], s);
            }
        }
    }
 
    cout << tot - mf.findMaxflow() << '\n';
 
    vector<bool> attackers(n + 2, false);
    vector<int> ans;
    mf.getResidual(0, attackers);
    for (int i = 1; i <= n; ++i) {
        if (attackers[i]) ans.push_back(i);
    }
    cout << ans.size();
    for (auto& each : ans) cout << " " << each;
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while (tcs-- > 0) solve();
}