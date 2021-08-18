class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sum=0,i,x,y,d,n;
        double z;
        n=points.size();
        for(i=1;i<n;i++)
        {
           x=abs(points[i][0]-points[i-1][0]);
           y=abs(points[i][1]-points[i-1][1]);
           z=min(x,y)*(int)sqrt(2);
           d=z+max(x,y)-min(x,y);
            
            sum+=d;
        }
        return sum;
    }
};