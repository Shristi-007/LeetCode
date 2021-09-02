class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int pos=-1,i=1,n;
        int large=arr[0];
        n=arr.size();
        while(i<n&&arr[i]>arr[i-1])
        {
            i++;
        }
        return (i-1);
    }
};