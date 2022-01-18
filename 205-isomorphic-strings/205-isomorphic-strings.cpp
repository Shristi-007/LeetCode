class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int l,i;
        l=s.length();
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        char a,b;
        for(i=0;i<l;i++)
        {
            a=s[i];
            b=t[i];
            if((mp1.find(a)==mp1.end())&&(mp2.find(b)==mp2.end()))
            {
                mp1[a]=b;
                mp2[b]=a;
            }
            else
            {
                if((mp1[a]!=b)||(mp2[b]!=a))
                    return false;
            }
        }
        return true;
    }
};