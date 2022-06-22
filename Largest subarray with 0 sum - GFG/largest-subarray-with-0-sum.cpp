// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        map<int,int>mp;
        int i,maxlen=0,sum=0;
        for(i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)
            {
                if(i+1>maxlen)
                {
                    maxlen=i+1;
                }
            }
            if(mp.find(sum)!=mp.end())
                {
                    int d=i-(mp[sum]+1)+1;
                    if(d>maxlen)
                    maxlen=d;
                }
                else
                {
                    mp[sum]=i;
                }
               
        }
        return maxlen;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends