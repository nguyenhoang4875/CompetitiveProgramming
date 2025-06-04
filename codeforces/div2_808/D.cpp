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
        long long q; // current IQ
        cin >> n >> q;
        vector<long long> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        // Precompute freeAvailable: freeAvailable[i] is true if there exists some j (i <= j < n) 
        // with a[j] <= 1 (i.e. a contest that is "free" when IQ == 1).
        vector<bool> freeAvailable(n, false);
        freeAvailable[n-1] = (a[n-1] <= 1);
        for (int i = n - 2; i >= 0; i--){
            freeAvailable[i] = freeAvailable[i+1] || (a[i] <= 1);
        }
        
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if(q <= 0) break; // cannot test any more contests
            
            if(a[i] <= q) {
                // "Free" contest: test without changing IQ.
                cnt++;
            }
            else { // a[i] > q, a "hard" contest
                if(q > 1){
                    // We can afford to test it: get +1 to count and decrease IQ by 1.
                    cnt++;
                    q--;
                }
                else { // q == 1
                    // Testing this contest will drop IQ to 0.
                    // It is optimal to do so only if this is the last contest OR
                    // if no future contest is "free" (i.e. none with a[j] <= 1).
                    if(i == n-1 || (i < n-1 && !freeAvailable[i+1])){
                        cnt++;
                        q--; // now becomes 0
                    }
                    // Otherwise, skip to preserve the IQ for a free contest later.
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
