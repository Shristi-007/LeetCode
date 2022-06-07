class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(auto ch:num)
        {
           
            while((!st.empty())&&(k>0)&&(st.top()>ch))
            {
                st.pop();
                k--;
               
            }
             if((!st.empty())||(ch!='0'))
            {
                st.push(ch);
            }
        }
        while((!st.empty())&&(k>0))
        {
            st.pop();
            k--;
        }
        if(st.empty())
            return "0";
        int n=num.size();
        while(!st.empty())
        {
            num[--n]=st.top();
            st.pop();    
            
        }
        return num.substr(n);
        
    }
};