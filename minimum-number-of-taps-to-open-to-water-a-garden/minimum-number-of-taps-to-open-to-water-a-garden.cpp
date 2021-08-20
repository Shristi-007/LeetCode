class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int min=0,max=0,ans=0,i;
        while(max<n)
        {int flag=-1;
         for(i=0;i<=n;i++)
         {
             if((i-ranges[i]<=min)&&(i+ranges[i]>max))
             {   flag++;
                 max=i+ranges[i];
             }
         }
            min=max;
            ans++;
         if(flag==-1)
         {
             ans=-1;
             break;
         }
        }
        return ans;
    }
};