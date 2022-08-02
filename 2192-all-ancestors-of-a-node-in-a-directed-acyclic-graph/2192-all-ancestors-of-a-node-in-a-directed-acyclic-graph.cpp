class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n+1];
        vector<int>ind(n+1,0);
        int m,a,b,i;
        m=edges.size();
        for(i=0;i<m;i++)
        {
            a=edges[i][0];
            b=edges[i][1];
            adj[a].push_back(b);
            ind[b]++;
        }
        queue<int>q;
        vector<set<int>>anc(n);
        for(i=0;i<n;i++)
        {
            if(ind[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(int child:adj[t])
            {
                anc[child].insert(anc[t].begin(),anc[t].end());
                anc[child].insert(t);
                ind[child]--;
                if(ind[child]==0)
                    q.push(child);
            }
        }
        vector<vector<int>>ans(n);
        for(i=0;i<n;i++)
        {
            ans[i]=vector<int>(anc[i].begin(),anc[i].end());
        }
        return ans;
    }
};