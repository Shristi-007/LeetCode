class Solution {
public:
    static bool comp(const vector<int>&a,const vector<int>&b)
    {
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        int total_time=0;
        int n=courses.size();
        priority_queue<int>q;
        for(int i=0;i<n;i++)
        {
            int curr=courses[i][0];
            int end=courses[i][1];
            total_time+=curr;
            q.push(curr);
            if(total_time>end)
            {
                total_time-=q.top();
                q.pop();
            }
        }
        return q.size();
    }
};