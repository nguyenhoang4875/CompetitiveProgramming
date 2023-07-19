#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
*/

class Solution {
public:
    int dp[1005];

    int minCost(vector<int>& cost, int n) {
        if(n < 0 ) return 0;
        if(n == 0 || n == 1) return cost[n];
        if(dp[n] != 0) return dp[n];
        dp[n] = cost[n] +  min(minCost(cost, n - 1), minCost(cost, n - 2));
        return dp[n];
    }

    // recursion approach: Top Down
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();
       return min(minCost(cost, n - 1), minCost(cost, n- 2));
    }

    // Tabulation: Bottom Up
    int minCostClimbingStairs(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 0);
        dp[0] = a[0];
        dp[1] = a[1];

        for(int i = 2; i < n; i++) {
            dp[i] = a[i] + min(dp[i-1], dp[i-2]);
        } 

        return min(dp[n-1], dp[n-2]);
    }
};