// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	long long int mod=1e9+7;
	long long int solve(int i,int N,vector<long long int>&dp)
	{
	    if(i>=N)
	    return 1;
	    if(dp[i]!=-1)
	    return dp[i];
	    long long int x=0,y=0;
	    x=(x+solve(i+2,N,dp))%mod;
	    y=(y+solve(i+1,N,dp))%mod;
	    return dp[i]=(x+y)%mod;
	}
	long long int TotalWays(int N)
	{
	    vector<long long int>dp(N+3);
	    for(int i=0;i<N+3;i++)
	    {
	        dp[i]=-1;
	    }
	   
	    long long int ans=solve(0,N,dp);
	    ans=(ans*ans)%mod;
	    return ans;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends