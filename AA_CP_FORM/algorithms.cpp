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

//****************** hash_pair() *******************//

//hash function for unordered_map with pair<int, int> is the key
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

//sort function for sorting vector of pair<int, int>
//Using: sort(vect.begin(), vect.end(), sortbysecond);
bool sortbysecond(const pair<int,int> &a, const pair<int,int> &b){
	   return (a.second > b.second); // sorting by descending order of second elements
	   //return (a.second < b.second); // sorting by ascending order of second elements
}

//priority_queue in increasing order
//Using:
priority_queue<int, vector<int>, greater<int> > gquiz;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


//****************** Customize priority_queue ******************//
struct myComp {
	constexpr bool operator()(pair<int, int> const& a, pair<int, int> const& b) const noexcept
	{
		if(a.first < b.first) return true;
		if(a.first > b.first) return false;
		if(a.second > b.second) return true;
		else return false;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> qcandy;


//****************** Customize set - map ******************//
struct setcomp {
  bool operator() (const pair<lli, lli>& lhs, const pair<lli, lli>& rhs) const{
	  if(lhs.first < rhs.first) return true;
	  else if(lhs.first > rhs.first) return false;
	  else if(lhs.second > rhs.second) return false;
	  else return true;
  }
};
set<pair<lli, lli>, setcomp> setP;


//***************** OTHER FORM *******************//

// UnionFind Disjoint Set
// Using: UnionFind bridge(N);
class UnionFind{
public:
	vector<int> p, rank;
	vector<int> setSize;
	int noSet;
	UnionFind(int N){
		rank.assign(N, 0);
		p.assign(N, 0);
		for(int i = 0; i < N; ++i) p[i] = i;
		setSize.assign(N, 1);
		noSet = N;
	}
	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if(!isSameSet(i, j)){
			int x = findSet(i);
			int y = findSet(j);
			if(rank[x] > rank[y]){
				p[y] = x;
				// setSize[x] += setSize[y];
			}
			else{
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
				// setSize[y] += setSize[x];
			}
			// --noSet;
		}
	}
	int getNoSet(){
		return noSet;
	}
	int getSetSize(int i){
		return setSize[find(i)];
	}
};

// Cantor function
// Using: create a unique number from 2 number, can be use to create keys of map
int cantor(int x, int y){ // create a unique number from 2 number
	return (x + y) * (x + y + 1) /2 + y;
}

int createKey(int x1, int y1, int x2, int y2){ // create a unique number from x1, y1, x2, y2
	return cantor(cantor(x1, y1), cantor(x2, y2));
}

// Find LCM (Least Common Multiple) and GCD (Greatest Common Divisor) of two number
long long gcd(long long int a, long long int b)
{
  if (b == 0)
	return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}

//**************** SEGMENT TREE ****************//

/*Using: 
int main() {
	int arr[] = { 18, 17, 13, 19, 15, 11, 20 }; // the original array
	vi A(arr, arr + 7);
	SegmentTree st(A);
	printf("RMQ(1, 3) = %d\n", st.rmq(1, 3)); // answer = index 2
	printf("RMQ(4, 6) = %d\n", st.rmq(4, 6)); // answer = index 5
}
*/
class SegmentTree { // the segment tree is stored like a heap array
private:
	vi st, A; // recall that vi is: typedef vector<int> vi;
	int n;
	int left (int p) { return p << 1; } // same as binary heap operations
	int right(int p) { return (p << 1) + 1; }
	void build(int p, int L, int R) { // O(n)
		if (L == R) // as L == R, either one is fine
			st[p] = L; // store the index
		else { // recursively compute the values
			build(left(p) , L , (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R );
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2]) ? p1 : p2;
		}
	}
	int rmq(int p, int L, int R, int i, int j) { // O(log n)
		if (i > R || j < L) return -1; // current segment outside query range
		if (L >= i && R <= j) return st[p]; // inside query range
		// compute the min position in the left and right part of the interval
		int p1 = rmq(left(p) , L , (L+R) / 2, i, j);
		int p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);
		if (p1 == -1) return p2; // if we try to access segment outside query
		if (p2 == -1) return p1; // same as above
		return (A[p1] <= A[p2]) ? p1 : p2; // as in build routine
	}
public:
	SegmentTree(const vi &_A) {
		A = _A; n = (int)A.size(); // copy content for local usage
		st.assign(4 * n, 0); // create large enough vector of zeroes
		build(1, 0, n - 1); // recursive build
	}
	int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } // overloading
};

//**************** Sieve of Eratosthenes ****************//

// print all prime numbers not greater than 'n'
// O(n*log(log(n)))
 
/* Using:
int main()
{
	int n = 30;
	cout << "Following are the prime numbers smaller than or equal to " << n << endl;
	SieveOfEratosthenes(n);
	return 0;
}
*/
void SieveOfEratosthenes(int n)
{
	vector<bool> prime(n + 1, true);
 
	for (int p = 2; p * p <= n; p++)
	{
		// If prime[p] is not changed,
		// then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples
			// of p greater than or
			// equal to the square of it
			// numbers which are multiple
			// of p and are less than p^2
			// are already been marked.
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
 
	// Print all prime numbers
	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << " ";
}
//////////////////////////////////////////////

vector<int> primeNumber;
void SieveOfEratosthenes(int n)
{
	vector<bool> prime(n + 1, true); 
	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	// primeNumber.push_back(1);
	for (int p = 2; p <= n; p++)
		if (prime[p])
			primeNumber.push_back(p);
}

//**************** Find all divisor of a number ****************//
// O(sqrt(n))
vector<int> vdiv;

void printDivisors(int n){
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0){
			vdiv.push_back(i); 
            if (n/i != i) vdiv.push_back(n/i);
        }
    }
}

//**************** Find all prime divisor of a number ****************//
// O(sqrt(n))
vector<int> givePrimeDivisor(int n) {
    vi div;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            div.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) div.push_back(n);
    return div;
}

//***************** KMP *******************//

// String matching - find all match of string P (length m) in string T (length n)
// O(n + m)

// Using: call kmpPreprocess() to process string P. Then call 
#define MAX_N 100010
char T[MAX_N], P[MAX_N]; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P kmpSearch() to find matching

void kmpPreprocess() { // call this before calling kmpSearch()
	int i = 0, j = -1; b[0] = -1; // starting values
	while (i < m) { // pre-process the pattern string P
		while (j >= 0 && P[i] != P[j]) j = b[j]; // different, reset j using b
		i++; j++; // if same, advance both pointers
		b[i] = j; // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
	}
} // in the example of P = "SEVENTY SEVEN" above

void kmpSearch() { // this is similar as kmpPreprocess(), but on string T
	int i = 0, j = 0; // starting values
	while (i < n) { // search through string T
		while (j >= 0 && T[i] != P[j]) j = b[j]; // different, reset j using b
		i++; j++; // if same, advance both pointers
		if (j == m) { // a match found when j == m
			printf("P is found at index %d in T\n", i - j);
			j = b[j]; // prepare j for the next possible match
		}
	}
}