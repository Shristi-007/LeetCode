class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n,i,l,r,ans=0;
        n=nums.size();
        vector<int>v(n);
        for(i=0;i<n;i++)
        {
           v[i]=nums[i]; 
        }
        sort(v.begin(),v.end());
        l=n,r=-1;
        for(i=0;i<n;i++)
        {
            if(v[i]!=nums[i])
            {
                l=min(l,i);
            }
            if(v[n-1-i]!=nums[n-1-i])
            {
                r=max(r,(n-1-i));
            }
        } 
    
        if(r>l)
        {
            ans=r-l+1;
        }
        return ans;
    }
};