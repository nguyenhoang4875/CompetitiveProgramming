// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Dsu {  // OOP style
   private:
    vector<int> p, rank, setSize;
    int numSets;

   public:
    Dsu(int N) {
        p.assign(N + 1, 0);
        for (int i = 0; i <= N; ++i) p[i] = i;
        rank.assign(N + 1, 0);     // optional speedup
        setSize.assign(N + 1, 1);  // optional feature
        numSets = N;               // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }             // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; }  // optional

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;         // i and j are in same set
        int x = findSet(i), y = findSet(j);  // find both rep items
        if (rank[x] > rank[y]) swap(x, y);   // keep x 'shorter' than y
        p[x] = y;                            // set x under y
        if (rank[x] == rank[y]) ++rank[y];   // optional speedup
        setSize[y] += setSize[x];            // combine set sizes at y
        --numSets;                           // a union reduces numSets
    }
};

int main() {
    printf("Assume that there are 5 disjoint sets initially\n");
    Dsu dsu(5);                             // create 5 disjoint sets
    printf("%d\n", dsu.numDisjointSets());  // 5
    dsu.unionSet(0, 1);
    printf("%d\n", dsu.numDisjointSets());  // 4
    dsu.unionSet(2, 3);
    printf("%d\n", dsu.numDisjointSets());  // 3
    dsu.unionSet(4, 3);
    printf("%d\n", dsu.numDisjointSets());                  // 2
    printf("isSameSet(0, 3) = %d\n", dsu.isSameSet(0, 3));  // will return 0 (false)
    printf("isSameSet(4, 3) = %d\n", dsu.isSameSet(4, 3));  // will return 1 (true)
    for (int i = 0; i < 5; i++)                             // findSet will return 1 for {0, 1} and 3 for {2, 3, 4}
        printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, dsu.findSet(i), i, dsu.sizeOfSet(i));
    dsu.unionSet(0, 3);
    printf("%d\n", dsu.numDisjointSets());  // 1
    for (int i = 0; i < 5; i++)             // findSet will return 3 for {0, 1, 2, 3, 4}
        printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, dsu.findSet(i), i, dsu.sizeOfSet(i));
    return 0;
}