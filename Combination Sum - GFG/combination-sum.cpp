// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void recur(int sum,vector<vector<int>>&ans,vector<int>&curr,int i,vector<int>&A)
    {
        if(sum==0)
        {
            ans.push_back(curr);
            return;
        }
        if((i<A.size())&&(sum-A[i]>=0))
        {
            curr.push_back(A[i]);
            recur(sum-A[i],ans,curr,i,A);
            curr.pop_back();
            i++;
            recur(sum,ans,curr,i,A); 
        }
        
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        vector<int>curr;
        vector<vector<int>>ans;
        recur(B,ans,curr,0,A);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends