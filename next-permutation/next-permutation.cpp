class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,n,j,flag=-1;
        n=nums.size();
        vector<int>arr(n);
        for(i=0;i<n;i++)
        {
            arr[i]=nums[i];
        }
        sort(arr.rbegin(),arr.rend());
        for(i=0;i<n;i++)
        {
          if(arr[i]!=nums[i])
          {flag++;
           break;
          }
        }
        if(flag==-1)
        {
            sort(nums.begin(),nums.end());
        }
        else
        {for(i=n-2;i>=0;i--)
       {
         if(nums[i+1]>nums[i])
         {
          break;
         }
       }
        if(i>=0)
        {j=n-1;
         while(nums[j]<=nums[i])
         {
          j--;
         }
         int temp=nums[j];
         nums[j]=nums[i];
         nums[i]=temp;
         reverse(nums.begin()+i+1,nums.end());
        }
        }
    }
};