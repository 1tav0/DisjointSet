int longestIncreasingSubsequence(int arr[], int n){
    vector<int> dp(n, 1);
    vector<int> hash(n);

    int maxi = 1;
    int lastIndex = 0;
    //tc - O(n`2)
    for (int ind = 0; ind < n; ind++){
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++){
            if(arr[prev]<arr[ind] && 1 + dp[prev] > dp[ind]){
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if(dp[ind]>maxi){
            maxi = dp[ind];
            lastIndex = ind;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    for(auto it: temp){
        cout << it << " ";
    }
    cout << endl;
    return maxi;
}