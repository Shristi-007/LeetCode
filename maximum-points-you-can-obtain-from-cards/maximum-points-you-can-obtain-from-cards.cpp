class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i,n,sum=0,x;
        n=cardPoints.size();
        vector<int>prefix(n+1),postfix(n+1);
        prefix[0]=cardPoints[0];
        for(i=1;i<n;i++)
        {
         prefix[i]=cardPoints[i]+prefix[i-1];
        }
        postfix[0]=cardPoints[n-1];
        int a=1;
        for(i=n-2;i>=0;i--)
        {
         postfix[a]=cardPoints[i]+postfix[a-1];
            a++;
        }
    
        for(i=0;i<k-1;i++)
        {
          x=prefix[i]+postfix[k-i-2];
          sum=max(sum,x);
        }
        x=max(prefix[k-1],postfix[k-1]);
        sum=max(sum,x);
    return sum;
    }
};