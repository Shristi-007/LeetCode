class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n,i,x=0,d;
        n=nums.size();
        if(n<2)
            return 0;
        sort(nums.begin(),nums.end());
        for(i=1;i<n;i++)
        {
            d=abs(nums[i]-nums[i-1]);
            x=max(x,d);
        }
        return x;
    }
};