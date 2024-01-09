#include <bits/stdc++.h>
#define int long long

using namespace std;

// Dsu for size:
struct Dsu {
    Dsu(){};
    Dsu(int n) : parent(n + 1), size(n + 1){};

    vector<int> parent, size;
    void makeSet(int v) {
        parent[v] = v;
        size[v] = 1;  // init size = 1;
    }

    int findSet(int v) {
        return parent[v] = (parent[v] == v ? v : findSet(parent[v]));
    }

    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);  // set a is root of the bigger size of tree
            parent[b] = a;
            size[a] += size[b];  // update the new size of new the merge tree
        }
    }
};

// Dsu by rank:
struct DsuRank {
    DsuRank(){};
    DsuRank(int n) : parent(n + 1), rank(n + 1){};

    vector<int> parent, rank;
    void makeSet(int v) {
        parent[v] = v;
        rank[v] = 0;  // init rank = 0
    }

    int findSet(int v) {
        return parent[v] = (parent[v] == v ? v : findSet(parent[v]));
    }

    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);  // set a is root of the bigger rank tree
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;  // if same rank increase the merge tree by 1
        }
    }
};

// add more data to the DSU, find min and sum of all element in a set

struct DsuMinSum {
    vector<int> parent, size, mn, sum;
    DsuMinSum(){};
    DsuMinSum(int n) : parent(n + 1), size(n + 1), mn(n + 1), sum(n + 1){};

    void makeSet(int v) {
        parent[v] = v;
        size[v] = 1;
        mn[v] = v;
        sum[v] = v;
    }

    int findSet(int v) {
        return parent[v] = (v == parent[v] ? v : findSet(parent[v]));
    }

    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            sum[a] += sum[b];
            mn[a] = min(mn[a], mn[b]);
        }
    }

    int findMin(int v) {  // return sum of all element of set contains v
        v = findSet(v);
        return mn[v];
    }

    int findSum(int v) {  // return min of all element of set contains v
        v = findSet(v);
        return sum[v];
    };
};

int32_t main() {
    DsuMinSum dsu(10);

    for (int i = 0; i <= 9; i++) {
        dsu.makeSet(i);
    }
    dsu.unionSet(1, 3);
    dsu.unionSet(3, 5);
    dsu.unionSet(5, 7);
    dsu.unionSet(7, 9);

    set<int> parent;
    for (int i = 0; i <= 9; i++) {
        // int x = dsu.findSet(i);
        // cout << "x = " << x << endl;
        parent.insert(dsu.findSet(i));
    }
    for (int e : parent) {
        cout << "parent = " << e << endl;
        cout << "min = " << dsu.findMin(e) << endl;
        cout << "sum = " << dsu.findSum(e) << endl;
        cout << "size = " << dsu.size[e] << endl;
        cout << endl;
    }

    return 0;
}