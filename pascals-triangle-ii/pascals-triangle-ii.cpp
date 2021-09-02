class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>arr(rowIndex+1);
        int i;
        for(i=0;i<=rowIndex;i++)
        {
         arr[i]=vector<int>(i+1);
        }
        i=0;
        while(i<=rowIndex)
        {
            arr[i][0]=1;
            arr[i][i]=1;
            int j=1;
            while(j<i)
            {
                arr[i][j++]=arr[i-1][j-1]+arr[i-1][j];
            }
            i++;
        }
        return arr[rowIndex];
    }
};