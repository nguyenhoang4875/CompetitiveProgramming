#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int memo[105];
    int f(int i, vector<int>& dp, vector<int>& a) {
        if(i == 0) return a[0];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(f(i - 1, dp, a), a[i] + f(i - 2, dp, a));
    }
    int rob(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, -1);

        return f(n - 1, dp, a);
      
    }
};