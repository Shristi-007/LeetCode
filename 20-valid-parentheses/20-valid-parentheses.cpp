class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i,l;
        l=s.length();
       
        for(i=0;i<l;i++)
        {
            char ch=s[i];
            if((ch=='(')||(ch=='{')||(ch=='['))
            {
                st.push(ch);
            }
               if(st.empty())
                {return false;
                }
            
                switch(ch)
                {
                    case ')':
                        {
                            char t=st.top();
                            st.pop();
                            if((t=='{')||(t=='['))
                                return false;
                            break;
                        }
                         case '}':
                        {
                            char t=st.top();
                            st.pop();
                            if((t=='(')||(t=='['))
                                return false;
                            break;
                        }
                         case ']':
                        {
                            char t=st.top();
                            st.pop();
                            if((t=='{')||(t=='('))
                                return false;
                            break;
                        }
                }
            
           
        }
        
        if(!st.empty())
        {   
            return false;
        }
        return true;
    }
};