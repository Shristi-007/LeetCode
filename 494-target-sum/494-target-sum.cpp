class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n,i,sum=0,j,ans=0,p=1;
        n=nums.size();
        vector<int>arr;
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            if(nums[i]!=0)
            {
                arr.push_back(nums[i]);
            }
        }
         if((target>sum)||(target<-sum))
        {
            return 0;
        }
        int s1=(sum+target);
        if(s1%2!=0)
            return 0;
        s1=s1/2;
        n=arr.size();
        if(n>0)
        {int dp[n+1][s1+1];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=s1;j++)
            {   
                if(i==0)
                {
                    dp[i][j]=0;
                }
                if(j==0)
                {
                    dp[i][j]=1;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=s1;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
         ans+=dp[n][s1];
        }
       
        int l=nums.size();
        for(i=1;i<=(l-n);i++)
        {
            p*=2;
        }
        if(n>0)
        {
            ans*=p;
            return ans;
        }
        else
        {
            ans=p;
            return ans;
        }
    }
};