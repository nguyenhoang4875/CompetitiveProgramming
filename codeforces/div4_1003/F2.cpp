#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1);
        vector<int> freq(n+1, 0);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            freq[a[i]]++;
        }
 
        vector<vector<int>> adj(n+1);
        for (int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        string ans(n, '0');
 
        // Global Edge Scan: If an edge connects two vertices with the same value,
        // mark that candidate as valid.
        for (int u = 1; u <= n; u++){
            for (int v : adj[u]){
                if (v > u && a[u] == a[v])
                    ans[a[u]-1] = '1';
            }
        }
 
        // Global Vertex Scan: Check if any vertex has two or more neighbors with the same value.
        for (int v = 1; v <= n; v++){
            if(adj[v].size() < 2)
                continue;
 
            vector<int> neighValues;
            for (int u : adj[v])
                neighValues.push_back(a[u]);
 
            sort(neighValues.begin(), neighValues.end());
 
            int count = 1;
            for (size_t i = 1; i < neighValues.size(); i++){
                if(neighValues[i] == neighValues[i-1])
                    count++;
                else{
                    if(count >= 2)
                        ans[neighValues[i-1]-1] = '1';
                    count = 1;
                }
            }
            if(count >= 2)
                ans[neighValues.back()-1] = '1';
        }
 
        // Final Cleanup:
        // Even if our scans marked candidate i as valid, if it appears fewer than 2 times,
        // it cannot form a non-trivial path.
        for (int i = 1; i <= n; i++){
            if(freq[i] < 2)
                ans[i-1] = '0';
        }
 
        cout << ans << "\n";
    }
    
    return 0;
}
