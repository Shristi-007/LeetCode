class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i,n;
        n=digits.size();
        vector<int>ans;
        i=n-1;
        while(i>=0)
        {
           if(digits[i]==9)
               digits[i]=0;
            else
            {
                digits[i]+=1;
                break;
            }
            i--;
        }
        if(digits[0]==0)
        {
            ans.push_back(1);
         }
        for(i=0;i<n;i++)
        {
            ans.push_back(digits[i]);
            //cout<<digits[i]<<" ";
        }
        return ans;
    }
};