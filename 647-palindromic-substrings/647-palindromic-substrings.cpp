class Solution {
public:
    int countSubstrings(string s) {
        int cnt=0;
        int i,j,k,l=s.length();
        int dp[l][l];
        for(k=0;k<l;k++)
        {
            for(i=0,j=k;j<l;i++,j++)
            {
                if(k==0)
                {dp[i][j]=1;
                 cnt++;
                }
                else if(k==1)
                {
                    if(s[i]==s[j])
                    {dp[i][j]=1;
                     cnt++;
                    }
                    else
                        dp[i][j]=0;
                }
                else
                {
                    if((s[i]==s[j])&&(dp[i+1][j-1]))
                    {
                        dp[i][j]=1;
                        cnt++;
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
            }
        }
        return cnt;
    }
};