#include <bits/stdc++.h>

// tabulation solution
int frogJump(int n, vector<int> &heights, int k){
    if(n==0)
        return 0;

    int minSteps = INT_MAX;
    for (int i = 1; i <= k; i++){
        if(n-i>=0){
            int jump = frogJump(n - i) + abs(heights[n] - heights[n - i]);
            minSteps = min(minSteps, jump);
        }
    }
    return minSteps;
}