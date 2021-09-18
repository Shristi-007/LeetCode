class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int n=0,i;
        string s=to_string(x);
        int l=s.length();
        for(i=0;i<=l/2;i++)
        {
          if(s[i]!=s[l-1-i])
              return false;
        }
        return true;
    }
};