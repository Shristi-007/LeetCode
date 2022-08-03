class Solution {
public:
    vector<pair<int,int>> isVis;
    
    int dfs(int node,vector<int> &edges,int dfs_no,int t)
    {
        isVis[node].first=t;
        isVis[node].second=dfs_no;
        if(edges[node]==-1) return -1;
        
        if(isVis[edges[node]].first==0)
        {
            return dfs(edges[node],edges,dfs_no,t+1);
        }
        else if(isVis[node].second==isVis[edges[node]].second)
            return (1+isVis[node].first-isVis[edges[node]].first);
        else return -1;
    }
    int longestCycle(vector<int>& edges) {
        int dfs_no=1;
        int nodes=edges.size();
        
        isVis.assign(nodes,{0,0});
        int ans=-1;
        for(int i=0; i<nodes; i++)
        {
            if(isVis[i].first==0)
             ans=max(ans,dfs(i,edges,dfs_no++,1)) ;            
        }
        
        return ans;
    }
};