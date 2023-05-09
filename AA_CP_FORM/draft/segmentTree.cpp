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


//**************** AN EXAMPLE OF SEGMENT TREE ****************//
// 2021 Final round
// Segment tree to store the maximum member in range,
// And find the smallest-id-member that greater than a pre-define number (length)

class SegmentTree { // the segment tree is stored like a heap array
public:
    vector<lli> st, A; // recall that vi is: typedef vector<int> vi;
    lli n;
    lli left (lli p) { return p << 1; } // same as binary heap operations
    lli right(lli p) { return (p << 1) + 1; }
    void build(lli p, lli L, lli R) { // O(n)
        if (L == R) // as L == R, either one is fine
            st[p] = L; // store the index
        else { // recursively compute the values
            build(left(p) , L , (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R );
            lli p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2]) ? p1 : p2;
        }
    }
    lli rmq(lli length, lli p, lli L, lli R, lli i, lli j) { // O(log n)
		if (length > A[st[p]]) return -1;
        if (i > R || j < L) return -1; // current segment outside query range
		if (L == R){
			if(A[st[p]] >= length) return st[p];
			else return -1;
		}
        // if (L >= i && R <= j) return st[p]; // inside query range
        // compute the min position in the left and right part of the llierval
		lli p2 = 0;
        lli p1 = rmq(length, left(p) , L , (L+R) / 2, i, j);
		if (p1 == -1){
			p2 = rmq(length, right(p), (L+R) / 2 + 1, R , i, j);
       		if (p2 == -1) return -1; // same as above
			return p2;
		}
		return p1;
        // return (A[p1] >= A[p2]) ? p1 : p2; // as in build routine
    }
	void update(lli p, lli L, lli R, lli idx, lli newVal){
		if (L == R && L == idx){
			A[idx] = newVal;
		}
		else if(idx <= (L + R) / 2){
			update(left(p) , L , (L + R) / 2, idx, newVal);
			lli p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2]) ? p1 : p2;
		}
		else{
			update(right(p), (L + R) / 2 + 1, R, idx, newVal);
			lli p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2]) ? p1 : p2;
		}
	}
public:
    SegmentTree(const vector<lli> &_A) {
        A = _A; n = (lli)A.size(); // copy content for local usage
        st.assign(4 * n + 10, 0); // create large enough vector of zeroes
        build(1, 1, n); // recursive build
    }
    lli rmq(lli length, lli i, lli j) { return rmq(length, 1, 1, n, i, j); } // overloading
	void update(lli idx) { return update(1, 1, n, idx, -1); }
};



//****************** CODING **********************//
//**************** AN EXAMPLE OF SEGMENT TREE ****************//
// 2019 Online round 1 - problem F
// Segment tree to store the sum of member in range

class SegmentTree { // the segment tree is stored like a heap array
public:
    vector<lli> st, A; // recall that vi is: typedef vector<int> vi;
    lli n;
    lli left (lli p) { return p << 1; } // same as binary heap operations
    lli right(lli p) { return (p << 1) + 1; }
    void build(lli p, lli L, lli R) { // O(n)
        if (L == R) // as L == R, either one is fine
            st[p] = A[L]; // store the index
        else { // recursively compute the values
            build(left(p) , L , (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R );
            lli p1 = st[left(p)], p2 = st[right(p)];
            st[p] = p1 + p2;
        }
    }
    lli rmq(lli p, lli L, lli R, lli i, lli j) { // O(log n)
        if (i > R || j < L) return -1; // current segment outside query range
		if (L >= i && R <= j) return st[p]; // inside query range
        // compute the min position in the left and right part of the llierval
		lli p1 = rmq(left(p) , L , (L+R) / 2, i, j);
		lli p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);
		if (p1 == -1) return p2; // if we try to access segment outside query
		if (p2 == -1) return p1; // same as above
		return (p1 + p2); // as in build routine
    }
	void update(lli p, lli L, lli R, lli idx, lli newVal){
		if (L == R && L == idx){
			A[idx] = newVal;
			st[p] = newVal;
		}
		else if(idx <= (L + R) / 2){
			update(left(p) , L , (L + R) / 2, idx, newVal);
			lli p1 = st[left(p)], p2 = st[right(p)];
            st[p] = p1 + p2;
		}
		else{
			update(right(p), (L + R) / 2 + 1, R, idx, newVal);
			lli p1 = st[left(p)], p2 = st[right(p)];
            st[p] = p1 + p2;
		}
	}
public:
    SegmentTree(const vector<lli> &_A) {
        A = _A; n = (lli)A.size(); // copy content for local usage
        st.assign(4 * n + 10, 0); // create large enough vector of zeroes
        build(1, 0, n - 1); // recursive build
    }
    lli rmq(lli i, lli j) { return rmq(1, 0, n-1, i, j); } // overloading
	void update(lli idx, lli val) { return update(1, 0, n-1, idx, val); }
};