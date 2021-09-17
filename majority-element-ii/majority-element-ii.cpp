class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n,i,x;
        map<int,int>m;
        n=nums.size();
        vector<int>ans;
        x=n/3;
        for(i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(auto it:m)
        {
           if(it.second>x)
           {
               ans.push_back(it.first);
           }
        }
        return ans;
    }
};