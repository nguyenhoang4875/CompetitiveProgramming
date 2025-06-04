#include <iostream>
#include <vector>
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
        vector<long long> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
 
        // posPrefix[k] will store the sum of positives among a[0]...a[k-1].
        vector<long long> posPrefix(n+1, 0);
        for (int i = 0; i < n; i++){
            posPrefix[i+1] = posPrefix[i] + (a[i] > 0 ? a[i] : 0);
        }
 
        // negSuffix[k] will store the sum of (-a[i]) for a[i] that are negative,
        // for indices i from k to n-1.
        vector<long long> negSuffix(n+1, 0); // negSuffix[n] = 0.
        for (int i = n-1; i >= 0; i--){
            negSuffix[i] = negSuffix[i+1] + (a[i] < 0 ? -a[i] : 0);
        }
 
        long long ans = 0;
        // Try every split k (0 <= k <= n):
        // The idea is to “take” positives from indices 0..k-1 and negatives (in absolute value)
        // from indices k..n-1.
        for (int k = 0; k <= n; k++){
            long long candidate = posPrefix[k] + negSuffix[k];
            ans = max(ans, candidate);
        }
 
        cout << ans << "\n";
    }
    return 0;
}
