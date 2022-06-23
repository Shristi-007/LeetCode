class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,j,l,maxlen=0;
        l=s.length();
        i=0,j=0;
        unordered_map<char,int>mp;
        while(j<l)
        {
            char ch=s[j];
            if(mp.find(ch)==mp.end())
            {
                mp[ch]++;
                if(j-i+1>maxlen)
                    maxlen=j-i+1;
                j++;
            }
            else
            {
                while(s[i]!=ch)
                {
                    char c=s[i];
                    mp[c]--;
                    if(mp[c]==0)
                    {mp.erase(c);
                    }
                    i++;
                }
                i++;
                j++;
            }
        }
        return maxlen;
    }
};