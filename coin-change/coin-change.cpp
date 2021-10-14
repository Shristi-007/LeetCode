class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1);
        int INF=100000000;
        int i,j,n,ans;
        n=coins.size();
        for(i=0;i<=amount;i++)
        {
         dp[i]=INF;
        }
        dp[0]=0;
        for(i=1;i<=amount;i++)
        {  ans=INF;
           for(j=0;j<n;j++)
           {
             if(coins[j]<=i)
             {
                ans=min(ans,dp[i-coins[j]]);
             }
           }
         if(ans==INF)
         {
           dp[i]=INF;
         }
         else
         {
             dp[i]=ans+1;
         }
        }
        if(dp[amount]==INF)
            dp[amount]=-1;
        return (dp[amount]);
    }
};