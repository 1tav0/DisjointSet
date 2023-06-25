#include <bits/stdc++.h>

// tabulation solution
int frogJump(int n, vector<int> &heights, int k){
    vector<int> dp(n + 1, -1);
    if(n==0)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    int minSteps = INT_MAX;
    for (int i = 1; i <= k; i++){
        if(n-i>=0){
            int jump = frogJump(n - i) + abs(heights[n] - heights[n - i]);
            minSteps = min(minSteps, jump);
        }
    }
    return dp[n] = minSteps;
}

//tc - O(n)xK
//sc - O(n)+O(n)