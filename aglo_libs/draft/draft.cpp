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

//******************** typedef *********************//

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;

//******************* debug(x) *********************//
//****https://codeforces.com/blog/entry/68920****//

//#define watch(x) cout << "[" << #x << "]" << " : " << (x) << endl
//#define getName(var) #var
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl

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

template<typename T>
void check_here(T x){
    cout << "------------- " << x << " -------------" << endl;
}

//****************** CODING **********************//

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << "hello" << endl;
    /*cout << "map : " << map <int, int> { {10, 2}, {11, -2}, {-6, 4} } << endl;
    cout << "unordered_map : " << unordered_map <int, int> { {10, 2}, {11, -2}, {-6, 4} } << endl;
    cout << "vector : " << vector <string> {"heh", "hah"} << endl;
    cout << "vector : " << vector <vector <int>> {{1, 2}, {5, 6, 8}, {}} << endl;
    cout << "set : " << set <string> {"heh", "hah"} << endl;
    cout << "set : " << set <set <int>> {{1, 2}, {5, 6, 8}, {}} << endl;
    cout << "string : " << string{"heh"} << endl;
    cout << "const char* : " << "hah" << endl;*/

    map <int, int> m{ {10, 2}, {11, -2}, {-6, 4} };
    float i = 10.019;
    string s = "this is a string";
    unordered_map <int, int> um{ {10, 2}, {11, -2}, {-6, 4} };
    vector <string> vs{"heh", "hah"};
    vector <vector <int>> vvi{{1, 2}, {5, 6, 8}, {}};
    vector<int> vi{1, 3, 5, 7, 8};
    vector<char> vc{'a', 'c', 'f'};
    vector<pair<int, string>> vpi{ {10, "muoi"}, {11, "muoi mot"}, {-6, "bon"}, {}, {12, "muoi hai"} };
    set <string> ss{"heh", "hah"};
    set <set <int>> ssi{{1, 2}, {5, 6, 8}, {}};
    const char* cs = "hah";
    char c = 's';

    debug(m);
    debug(i);
    debug(s);
    debug(um);
    debug(vs);
    debug(vvi);
    debug(vi);
    debug(vc);
    debug(vpi);
    debug(ss);
    debug(ssi);
    debug(cs);
    debug(c);
    return 0;
}

//**************** AN EXAMPLE OF GRAPH MODOLING ****************//
struct hash_pair {
	template <class T1, class T2>
	lli operator()(const pair<T1, T2>& p) const
	{
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		// return hash1 ^ hash2; // Not unique if hash1 == hash2 ?
		return (hash1 + hash2) * (hash1 + hash2 + 1) /2 + hash2; // In case of pair<int, int> as a key (use cantor function)
	}
};

unordered_map<pair<int, int>, int, hash_pair> edgeList; // <node1, node2> - weight
vector<unordered_map<pair<lli, lli>, lli, hash_pair>> adjList; // <adjNode, idxOfEdge> - weight

//**************** AN EXAMPLE OF MAX FLOW ****************//

#define noA (n + 1)
#define noB (n + 2)
#define noC (n + 3)
#define noT (n + 4)
#define idxEdge (edgeList.size() - 1)

struct _edge{
	int wei;
	int v1, v2;
	_edge(int _wei, int _v1, int _v2) : wei(_wei), v1(_v1), v2(_v2) {}
};
typedef _edge edge;

//Using: unordered_map<pair<int, int>, bool, hash_pair> um;
struct hash_pair {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const
	{
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		// return hash1 ^ hash2; // Not unique if hash1 == hash2 ?
		return (hash1 + hash2) * (hash1 + hash2 + 1) /2 + hash2; // In case of pair<int, int> as a key (use cantor function)
	}
};

unordered_map<pair<int, int>, int, hash_pair> edgeList;
vector<vii> adjList;
vector<int> p;
int s, t, f, mf;

void augment(int v, int minEdge){
	if(v == s){
		f = minEdge;
		return;
	}
	else if(p[v] != -1){
		augment(p[v], min(minEdge, edgeList[{p[v], v}]));
		edgeList[{p[v], v}] -= f;
		edgeList[{v, p[v]}] += f;
	}
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	int T; cin >> T;
	while(T--){
		int n, nA, nB, nC;
		cin >> n >> nA >> nB >> nC;
		edgeList.clear();
		edgeList.reserve(10 * noT);
		adjList.assign(noT + 10, vii());

		FOR(i, 1, n + 1){
			edgeList[{0, i}] = 1;
			adjList[0].push_back({i, 1});
			edgeList[{i, 0}] = 0;
			adjList[i].push_back({0, 0});
		}
		int mA, mB, mC, tmp;
		cin >> mA;
		FOR(i, 0, mA){
			cin >> tmp;
			edgeList[{tmp, noA}] = 1;
			adjList[tmp].push_back({noA, 1});
			edgeList[{noA, tmp}] = 0;
			adjList[noA].push_back({tmp, 0});
		}
		cin >> mB;
		FOR(i, 0, mB){
			cin >> tmp;
			edgeList[{tmp, noB}] = 1;
			adjList[tmp].push_back({noB, 1});
			edgeList[{noB, tmp}] = 0;
			adjList[noB].push_back({tmp, 0});
		}
		cin >> mC;
		FOR(i, 0, mC){
			cin >> tmp;
			edgeList[{tmp, noC}] = 1;
			adjList[tmp].push_back({noC, 1});
			edgeList[{noC, tmp}] = 0;
			adjList[noC].push_back({tmp, 0});
		}
		edgeList[{noA, noT}] = nA;
		adjList[noA].push_back({noT, nA});
		edgeList[{noT, noA}] = 0;
		adjList[noT].push_back({noA, 0});

		edgeList[{noB, noT}] = nB;
		adjList[noB].push_back({noT, nB});
		edgeList[{noT, noB}] = 0;
		adjList[noT].push_back({noB, 0});

		edgeList[{noC, noT}] = nC;
		adjList[noC].push_back({noT, nC});
		edgeList[{noT, noC}] = 0;
		adjList[noT].push_back({noC, 0});

		// debug(edgeList); debug(adjList);

		mf = 0;
		s = 0; t = noT;
		vector<int> dist;
		while(1){
			f = 0;
			dist.assign(noT + 10, -1);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(noT + 10, -1);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u == t) break;
				for(int i = 0; i < adjList[u].size(); ++i){
					int v = adjList[u][i].first;
					if(edgeList[{u, v}] > 0 && dist[v] == -1){
						dist[v] = dist[u] + 1;
						q.push(v);
						p[v] = u;
					}
				}
			}
			augment(t, noT); /// augment(t, INF);
			if(f == 0) break;
			mf += f;
		}
		cout << mf << endl;
		FOR(i, 1, n + 1){
			if(edgeList.count({i, noA}) && edgeList[{i, noA}] == 0) printf("%d A\n", i);
			else if(edgeList.count({i, noB}) && edgeList[{i, noB}] == 0) printf("%d B\n", i);
			else if(edgeList.count({i, noC}) && edgeList[{i, noC}] == 0) printf("%d C\n", i);
		}
	}
	return 0;
}

//**************** AN EXAMPLE OF INDEX TREE ****************//

#define LSOne(S) (S & (-S))

class FenwickTree {
 private:
 	vi ft; // recall that vi is: typedef vector<int> vi;
 public:
 	FenwickTree(int n){
		ft.assign(n + 1, 0);
	} // init n + 1 zeroes
	int rsq(int b) { // returns RSQ(1, b)
		int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	} // note: LSOne(S) (S & (-S))
	int rsq(int a, int b) { // returns RSQ(a, b)
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}
	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void adjust(int k, int v) { // note: n = ft.size() - 1
		for (; k < (int)ft.size(); k += LSOne(k))
			ft[k] += v;
	}
};

int main() {
	int f[] = { 2,4,5,5,6,6,6,7,7,8,9 }; // m = 11 scores
	FenwickTree ft(10); // declare a Fenwick Tree for range [1..10]
	// insert these scores manually one by one into an empty Fenwick Tree
	for (int i = 0; i < 11; i++)
		ft.adjust(f[i], 1); // this is O(k log n)
	printf("%d\n", ft.rsq(1, 1)); // 0 => ft[1] = 0
	printf("%d\n", ft.rsq(1, 2)); // 1 => ft[2] = 1
	printf("%d\n", ft.rsq(1, 6)); // 7 => ft[6] + ft[4] = 5 + 2 = 7
	printf("%d\n", ft.rsq(1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
	printf("%d\n", ft.rsq(3, 6)); // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1
	ft.adjust(5, 2); // update demo
	printf("%d\n", ft.rsq(1, 10)); // now 13
} // return 0;

//**************** AN EXAMPLE OF COMBINATION MODULO ****************//

//source: https://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/

unsigned long long power(unsigned long long x, int y, int p){
	if(y == 0) return 1;
	if(y == 1) return x;
	unsigned long long res = 1; // Initialize result 
	x = x % p; // Update x if it is more than or equal to p 
	while (y > 0){
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % p; 
		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p){
	return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n, int r, int p){
	// If n<r, then nCr should return 0
	if (n < r) return 0;
	// Base case
	if (r == 0) return 1;
 
	// Fill factorial array so that we can find all factorial of r, n and n-r
	unsigned long long fac[n + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % p;
 
	return (fac[n] * modInverse(fac[r], p) % p
			* modInverse(fac[n - r], p) % p)
		   % p;
}
 
// Driver program
int main()
{
	// p must be a prime greater than n.
	int n = 10, r = 2, p = 13;
	cout << "Value of nCr % p is "
		 << nCrModPFermat(n, r, p);
	return 0;
}