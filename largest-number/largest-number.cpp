class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res="",s,r,a,b;
        int i,n,j,pos,z=0;
        n=nums.size();
        for(i=0;i<n;i++)
        {
         if(nums[i]==0)
             z++;
        }
        for(i=0;i<n-1;i++)
        { for(j=i+1;j<n;j++)
        {s=to_string(nums[i]);
         r=to_string(nums[j]);
         a=s+r;
         b=r+s;
         if(b>a)
         {
             int temp=nums[i];
             nums[i]=nums[j];
             nums[j]=temp;
         }
        }
        }
        for(i=0;i<n;i++)
        { //cout<<nums[i]<<" ";
          s=to_string(nums[i]);
          res=res+s;
        }
        
        if(z==n)
        {
            res="0";
        }
        return res;
    }
};