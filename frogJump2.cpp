#include <bits/stdc++.h>

// tabulation solution
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