class Solution {
public:
    static void solve(int i,int sum,int n,vector<vector<int>>&ans,vector<int>&temp,vector<int>& candidates)
    {
        if(sum==0)
        {
            ans.push_back(temp);
        }
       for(int ind=i;ind<n;ind++)
       {
           if((ind>i)&&(candidates[ind]==candidates[ind-1]))
               continue;
           if(candidates[ind]>sum)
               break;
           temp.push_back(candidates[ind]);
           solve(ind+1,sum-candidates[ind],n,ans,temp,candidates);
           temp.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n,i,j;
        n=candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,target,n,ans,temp,candidates);
        return ans;
    }
};