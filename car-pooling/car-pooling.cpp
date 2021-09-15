class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int arr[1001]={0};
        int i,n,j;
        n=trips.size();
        for(i=0;i<n;i++)
        {
         for(j=trips[i][1];j<trips[i][2];j++)
         {
             arr[j]+=trips[i][0];
         }
        }
        for(i=0;i<=1000;i++)
        {
          if(arr[i]>capacity)
              return false;
        }
        return true;
    }
};