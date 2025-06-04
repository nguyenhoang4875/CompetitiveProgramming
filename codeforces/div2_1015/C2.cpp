#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
 
        // used[i] indicates if index i has been paired/assigned
        vector<bool> used(n+1, false);
        // To store mirror pairs: (i, j) with i < j
        vector<pair<int,int>> mirrors;
        // For self symmetric pair (if exists)
        int selfIndex = -1;
 
        bool possible = true;
        for(int i = 1; i <= n; i++){
            if(used[i]) continue;
            // Check if self–symmetric.
            if(a[i] == b[i]){
                // For even n no self–symmetric pair is allowed;
                // for odd n, there must be exactly one.
                if(n % 2 == 0 || selfIndex != -1){
                    possible = false;
                    break;
                }
                selfIndex = i;
                used[i] = true;
            } else {
                // Look for the mirror of index i: an index j > i such that
                // a[j] == b[i] and b[j] == a[i].
                int jFound = -1;
                for(int j = i+1; j <= n; j++){
                    if(!used[j] && a[j] == b[i] && b[j] == a[i]){
                        jFound = j;
                        break;
                    }
                }
                if(jFound == -1){
                    possible = false;
                    break;
                }
                used[i] = used[jFound] = true;
                // Ensure smaller index is first.
                if(i < jFound)
                    mirrors.push_back({i, jFound});
                else
                    mirrors.push_back({jFound, i});
            }
        }
 
        // Check parity conditions:
        if(n % 2 == 0){
            if(selfIndex != -1) possible = false;
            if((int)mirrors.size() != n/2) possible = false;
        } else {
            if(selfIndex == -1) possible = false;
            if((int)mirrors.size() != (n-1)/2) possible = false;
        }
 
        if(!possible){
            cout << -1 << "\n";
            continue;
        }
 
        // Build the target assignment.
        // target[i] will be the final position where the pair originally from index i should go.
        vector<int> target(n+1, 0);
        int left = 1, right = n;  // available symmetric positions: left and its mirror right.
        for(auto &p : mirrors){
            int i = p.first, j = p.second;
            target[i] = left;
            target[j] = right;
            left++; right--;
        }
        if(selfIndex != -1){
            // Middle position must be (n+1)/2.
            target[selfIndex] = (n+1)/2;
        }
 
        // Now, we need to reorder the array of pairs (currently in positions 1..n in the natural order)
        // so that for each original index i, its pair goes to position target[i].
        // Let Q be an array (of size n+1) where Q[p] is the original index that should go to position p.
        // We have: for each i from 1 to n, Q[ target[i] ] = i.
        vector<int> Q(n+1, 0);
        for (int i = 1; i <= n; i++){
            Q[ target[i] ] = i;
        }
 
        // Our current order R is simply R[p] = p for p = 1..n.
        vector<int> R(n+1);
        for (int i = 1; i <= n; i++){
            R[i] = i;
        }
        // To quickly know where each original index currently is, maintain pos.
        vector<int> pos(n+1);
        for (int i = 1; i <= n; i++){
            pos[i] = i; // initially, pair originally from i is at position i.
        }
 
        // We will record our swaps (each swap swaps the entire pair at positions p and q).
        vector<pair<int,int>> ops;
 
        // For positions 1..n, fix the element if it's not what we want.
        for (int p = 1; p <= n; p++){
            if(R[p] == Q[p]) continue;
            // Let x be the pair that should be at position p.
            int x = Q[p];
            int curPos = pos[x];
            // Swap the pairs currently at positions p and curPos.
            ops.push_back({p, curPos});
            // Swap R[p] and R[curPos]
            int temp = R[p];
            R[p] = R[curPos];
            R[curPos] = temp;
            // Update positions.
            pos[R[p]] = p;
            pos[R[curPos]] = curPos;
        }
 
        // The final configuration now satisfies:
        // For each position p (1 <= p <= n), the pair originally from index i (where i = R[p]) now sits at position p.
        // By our assignment, if p and n+1-p form a symmetric pair (say p holds pair i and n+1-p holds pair j),
        // then by construction target[i] = p and target[j] = n+1-p, and our mirror pair satisfied a[i] = b[j].
        //
        // Thus the final arrays satisfy a[p] = b[n+1-p] for all p.
 
        // Output the number of swaps and the operations.
        cout << ops.size() << "\n";
        for(auto &op : ops){
            cout << op.first << " " << op.second << "\n";
        }
    }
    return 0;
}
