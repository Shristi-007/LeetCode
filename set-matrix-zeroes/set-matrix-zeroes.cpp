class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>col;
        set<int>row;
        int i,m,n,j;
        m=matrix.size();
        n=matrix[0].size();
        for(i=0;i<m;i++)
        {
          for(j=0;j<n;j++)
          {
            if(matrix[i][j]==0)
            {
             row.insert(i);
             col.insert(j);
            }
          }
        }
        for(i=0;i<m;i++)
        {
         if(row.find(i)!=row.end())
         {
             for(j=0;j<n;j++)
             {
                 matrix[i][j]=0;
              }
         }
        }
        for(j=0;j<n;j++)
        {
          if(col.find(j)!=col.end())
          {
              for(i=0;i<m;i++)
              {
                  matrix[i][j]=0;
              }
          }
        }
    }
};