class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int small=INT_MAX,i,n,flag=-1;
        n=nums.size();
        set<int>s;
        for(i=0;i<n;i++)
        {
          if(nums[i]>0)
          {
              small=min(small,nums[i]);
              s.insert(nums[i]);
          }
        }
        if(small>1)
            return 1;
        else
        { int c=1;
          for(auto it:s)
          {
              if(c!=it)
              return c;
              else
              c++;
          }
         return c;
        }
    }
};