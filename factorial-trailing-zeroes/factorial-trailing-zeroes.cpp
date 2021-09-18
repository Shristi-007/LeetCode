class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0)
            return 0;
        int ans=0,a,i;
        a=log(n)/log(5);
        for(i=1;i<=a;i++)
        {
            int q=pow(5,i);
            ans+=(n/q);
        }
        return ans;
    }
};