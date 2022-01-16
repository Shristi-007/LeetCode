class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n,i,j,k,ans=0;
        n=nums.size();
        if(n<=2)
        {
            return n;
        }
        vector<unordered_map<int,int>>arr(n);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                k=nums[j]-nums[i];
                if(arr[i].find(k)!=arr[i].end())
                {
                    arr[j][k]=1+arr[i][k];
                }
                else
                {
                    arr[j][k]=2;
                }
                ans=max(ans,arr[j][k]);
            }
        }
        return ans;
    }
};