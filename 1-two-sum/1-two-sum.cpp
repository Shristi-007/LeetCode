class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
           vector<int>ans,store;
        int i,j,k,n,a,b;
        n=nums.size();
    	store = nums;
    	sort(store.begin(), store.end());
    	int left=0,right=n-1;
    	int number1,number2;

    	while(left<right){
        	if(store[left]+store[right]==target){

            	number1 = store[left];
            	number2 = store[right];

            	break;

        	}
        	else if(store[left]+store[right]>target)
            	    right--;
        	else
            	    left++;
    	}

    	for(int i=0;i<nums.size();++i){

        	if(nums[i]==number1||nums[i]==number2)
            	    ans.push_back(i);

    	}

    	    
        return ans;
            
    }
};
  