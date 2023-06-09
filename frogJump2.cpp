#include <bits/stdc++.h>

// tabulation for frogjump2 solution
int frogJump(int n, vector<int> &heights, int k){
    vector<int> dp(n + 1, -1);
    if(n==0)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    for (int i = 1; i < n; i++){
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++){
            if(i-j>=>=0){
                int jump = frogJump(i-j) + abs(heights[n] - heights[n - j]);
                minSteps = min(minSteps, jump);
            }
            dp[i] = minSteps;
        }
    }
    return dp[n - 1];
}

//tc - O(nxK)
//sc - O(n)
//steps: 
//represent in terms of ind
//do stuff om that index
// return count / min or max
//recursion tree -top down
//memoization - overlappin subproblems
//tabulation - bottom up

bool helper(int ind, vector<int>& num){
    if(ind==0){
        return true;
    }
}