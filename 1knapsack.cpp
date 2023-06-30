int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1, 0);

	for(int W=weight[0]; W<=maxWeight; W++) prev[W] = value[0];

	for(int i=1; i<n; i++){
		for(int wt=maxWeight; wt>=0; wt--){
			int notPick = prev[wt];
			int pick = -1e8;
			if(weight[i]<=wt) pick = value[i] + prev[wt-weight[i]];

			prev[wt] = max(pick, notPick);
		}
	}

	return prev[maxWeight];
}