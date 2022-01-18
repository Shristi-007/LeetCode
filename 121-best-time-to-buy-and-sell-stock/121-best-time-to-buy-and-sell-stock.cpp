class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n,i,profit=0,min_left=INT_MAX;
        n=prices.size();
        for(i=0;i<n;i++)
        {
            if(prices[i]<min_left)
            {
                min_left=prices[i];
            }
            else
            {
                profit=max(profit,(prices[i]-min_left));
            }
        }
        return profit;
    }
};