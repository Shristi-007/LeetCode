class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n;
        n=nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
          m[nums[i]]++;
            if(m[nums[i]]>1)
            {
                return nums[i];
            }
        }
        return nums[n-1];
    }
};