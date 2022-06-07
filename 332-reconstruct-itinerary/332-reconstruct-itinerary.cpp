class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>adj;
        stack<string>st;
        vector<string>ans;
        st.push("JFK");
        int n,i;
        n=tickets.size();
        for(i=0;i<n;i++)
        {
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        while(!st.empty())
        {
           string src=st.top();
           
           if(adj[src].size()==0)
           {
               ans.push_back(src);
               st.pop();
           }
           else
           {
               auto d=adj[src].begin();
               st.push(*d);
               adj[src].erase(d);
           }
           
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};