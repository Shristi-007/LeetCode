class Solution {
public:
    static void solve(int i,int sum,int n,vector<vector<int>>&ans,vector<int>&temp,vector<int>& candidates)
    {
        if(sum==0)
        {
            ans.push_back(temp);
        }
        if((i<n)&&(sum-candidates[i]>=0))
        {
            temp.push_back(candidates[i]);
            solve(i,sum-candidates[i],n,ans,temp,candidates);
            temp.pop_back();
            solve(i+1,sum,n,ans,temp,candidates);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n,i,j;
        n=candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,target,n,ans,temp,candidates);
        return ans;
    }
};