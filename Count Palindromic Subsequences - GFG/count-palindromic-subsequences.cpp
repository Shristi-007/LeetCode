// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string s)
    {
       long long int i,j,l,k,ans=0,a,b,m;
       m=1e9+7;
       l=s.length();
       long long int dp[l][l];
       for(k=0;k<l;k++)
       {
           for(i=0,j=k;j<l;j++,i++)
           {
               if(k==0)
               {
                   dp[i][j]=1;
               }
               else if(k==1)
               {
                   if(s[i]==s[j])
                   dp[i][j]=3;
                   else
                   dp[i][j]=2;
               }
               else
               {
                   if(s[i]==s[j])
                   {
                      a=(dp[i][j-1]%m+dp[i+1][j]%m)%m;
                      b=(a+1)%m;
                      dp[i][j]=b;
                   }
                   else
                   {
                      a=(dp[i][j-1]%m+dp[i+1][j]%m)%m;
                      b=(a%m-dp[i+1][j-1]%m+m)%m;
                      dp[i][j]=b;
                   }
               }
             
           }
       }
       return (dp[0][l-1]%m);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends