class Solution {
public:
    bool isvalid(int n,int m, int x,int y)
    {
         if((x<0)||(x>=n)||(y<0)||(y>=m))
         {
             return false;
         }
        else
        {
            return true;
        }
    }
    int minCost(vector<vector<int>>& grid) {
        int n,m,i,j;
        n=grid.size();
        m=grid[0].size();
        int dp[102][102];
        for(i=0;i<n;i++)
        {
          for(j=0;j<m;j++)
          {
              dp[i][j]=100000;
          }
        }
        queue<pair<int,int>>que;
        dp[0][0]=0;
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        que.push({0,0});
        while(!que.empty())
        {
            auto curr=que.front();
            que.pop();
            int x=curr.first;
            int y=curr.second;
            for(i=0;i<4;i++)
            {
               int X=x+dir[i].first;
               int Y=y+dir[i].second;
               if(isvalid(n,m,X,Y))
               {
                   if((i+1==grid[x][y])&&(dp[X][Y]>dp[x][y]))
                   {
                       dp[X][Y]=dp[x][y];
                       que.push({X,Y});
                   }
                   else if(dp[x][y]+1<dp[X][Y])
                   {
                       dp[X][Y]=1+dp[x][y];
                       que.push({X,Y});
                   }
               }
            }
        }
        return dp[n-1][m-1];
    }
};