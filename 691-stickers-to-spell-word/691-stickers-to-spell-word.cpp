class Solution {
public:
    int solve(vector<string>& stickers, string target,int i,int j,vector<vector<int>>&dp)
    {    int n,m,x;
     x=j;
        n=stickers.size();
        m=target.length();
        if(j==((1<<m)-1))
            return 0;
        if(i==n)
            return (1e7);
        if(dp[i][j]!=-1)
            return dp[i][j];
        int notused=solve(stickers,target,i+1,j,dp);
        int used=0;
        for(char ch:stickers[i])
        {
            for(int k=0;k<m;k++)
            {
                if((target[k]==ch)&&(!((1<<k)&j)))
                {
                    used=1;
                    j=j|(1<<k);
                    break;
                }
            }
        }
        int taken=1e7;
        if(used)
        {
            taken=1+solve(stickers,target,i,j,dp);
        }
        return dp[i][x]=min(taken,notused);
    }
    int minStickers(vector<string>& stickers, string target) {
        int n,m,ans;
        n=stickers.size();
        m=target.length();
        vector<vector<int>>dp(n+1,vector<int>((1<<m),-1));
        ans=solve(stickers,target,0,0,dp);
        if(ans>m)
            return -1;
        else
            return ans;
    }
};