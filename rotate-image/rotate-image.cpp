class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int i,j,n,r,c;
        n=matrix[0].size();
        vector<vector<int>>ans(n);
        for(i=0;i<n;i++)
        {
          ans[i]=vector<int>(n);
        }
        r=0;
        for(j=n-1;j>=0;j--)
        {
           c=0;
           for(i=0;i<n;i++)
           {
            ans[i][j]=matrix[r][c++];
           }
            r++;
        }
        for(i=0;i<n;i++)
        {
          for(j=0;j<n;j++)
          {
              matrix[i][j]=ans[i][j];
          }
        }
    }
};