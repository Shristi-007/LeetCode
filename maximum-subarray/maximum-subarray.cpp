class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN,cursum=0,i,n;
        n=nums.size();
        for(i=0;i<n;i++)
        {
           cursum+=nums[i];
            if(cursum>=maxsum)
            {
              maxsum=cursum;
            }
            if(cursum<0)
            {
                cursum=0;
            }
        }
        return maxsum;
    }
};