class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         int i,n;
        n=intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        vector<int>newInterval(2);
        newInterval[0]=intervals[0][0];
        newInterval[1]=intervals[0][1];
        for(i=1;i<n;i++)
        {
            if(intervals[i][1]<newInterval[0])
            {
                ans.push_back(intervals[i]);
            }
            else if(newInterval[1]<intervals[i][0])
            {
                ans.push_back(newInterval);
                newInterval[0]=intervals[i][0];
                newInterval[1]=intervals[i][1];
            }
            else
            {
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};