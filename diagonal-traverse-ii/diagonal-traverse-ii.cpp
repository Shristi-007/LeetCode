class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
       map<int,vector<int>>m;
        int i,n=nums.size(),j;
        vector<int>arr;
        for(i=n-1;i>=0;i--)
        {
          for(j=0;j<nums[i].size();j++)
          {
            m[i+j].push_back(nums[i][j]);
          }
        }
        for(auto it:m)
        {
          for(j=0;j<m[it.first].size();j++)
          {
           arr.push_back(m[it.first][j]);
          }
        }
        return arr;
    }
};