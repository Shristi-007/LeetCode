class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l,i,j,k;
        l=strs.size();
        int ans=0;
        int dp[m+1][n+1];
      
            for(j=0;j<=m;j++)
            {
                for(k=0;k<=n;k++)
                {
                    dp[j][k]=0;
                }
            }
        
        for(i=1;i<=l;i++)
        {
            int len,zeroes=0,ones=0;
            len=strs[i-1].length();
            len--;
            while(len>=0)
            {
                if(strs[i-1][len]=='1')
                {
                    ones++;
                }
                else
                {
                    zeroes++;
                }
                len--;
            }
            for(j=m;j>=zeroes;j--)
            {
                for(k=n;k>=ones;k--)
                {
                   dp[j][k]=max(dp[j][k],1+dp[j-zeroes][k-ones]);
                }
            }
        }
        return dp[m][n];
    }
};