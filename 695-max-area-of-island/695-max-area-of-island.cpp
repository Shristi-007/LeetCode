class Solution {
public:
    int vis[51][51];
    bool isvalid(int curx,int cury,int m, int n)
    {
        if((curx<0)||(curx>=m)||(cury<0)||(cury>=n))
        {
            return false;
        }
        return true;
    }
    void bfs(vector<vector<int>>& grid,int curx,int cury,int m,int n,int &cnt)
    {
        vector<pair<int,int>>dir={{0,-1},{0,1},{-1,0},{1,0}};
        queue<pair<int,int>>que;
        vis[curx][cury]=1;
        cnt++;
        que.push({curx,cury});
        pair<int,int>cord;
        while(!que.empty())
        {
            cord=que.front();
            que.pop();
            for(auto dirn:dir)
            {
                int X=cord.first+dirn.first;
                int Y=cord.second+dirn.second;
                if(isvalid(X,Y,m,n))
                   {
                       if((vis[X][Y]==0)&&(grid[X][Y]==1))
                       {
                           que.push({X,Y});
                           vis[X][Y]=1;
                           cnt++;
                       }
                   }
            }
        }
                   return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m,n,i,j;
        m=grid.size();
        n=grid[0].size();
        int maxarea=0;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                vis[i][j]=0;
            }
        }
        
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if((vis[i][j]==0)&&(grid[i][j]==1))
                {   int cnt=0;
                    bfs(grid,i,j,m,n,cnt);
                    maxarea=max(maxarea,cnt);
                }
            }
        }
        return maxarea;
    }
};