class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n,ans=0;
        n=startTime.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(v.begin(),v.end());
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)
        {
           if(i==0)
           {
               dp[i]+=v[i][2];
               continue;
           }
            dp[i]=v[i][2];
            int x=search(v,i);
            if(x!=-1)
            {
                dp[i]+=dp[x];
            }
            dp[i]=max(dp[i],dp[i-1]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
    int search(vector<vector<int>>&arr, int ind)
    {
        int l=0,r=ind-1,mid;
        int ans=-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(arr[mid][0]<=arr[ind][1])
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};