
//n is the size of the coin array
int Coin_change(int coin[],int sum,int n){
	int dp[n+1][sum+1];
	dp[0][0]=INT_MAX;
	for(int i=1;i<=n;i++)
	dp[i][0]=0;
	for(int j=1;j<=sum;j++)
	dp[0][j]=INT_MAX;
	for(int j=1;j<=sum;j++){
		if(j%coin[0]==0)
		dp[1][j]=j/coin[0];
		else
		dp[1][j]=INT_MAX;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(coin[i-1]<=j)
			dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	if(dp[n][sum]==INT_MAX)
	return -1;
	
	return dp[n][sum];
}
