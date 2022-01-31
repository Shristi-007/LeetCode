class Solution {
public:
    bool isCycle(vector<vector<int>>&adj_list, vector<int>&vis, int cur_node)
    { 
        if(vis[cur_node]==2)
        {
            return true;
        }
        
        vis[cur_node]=2;
        for(int i=0;i<adj_list[cur_node].size();i++)
        {
            if(vis[adj_list[cur_node][i]]!=1)
            {
                if(isCycle(adj_list,vis,adj_list[cur_node][i]))
                    return true;
            }
        }
        vis[cur_node]=1;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj_list(numCourses);
        int i,n;
        n=prerequisites.size();
        for(i=0;i<n;i++)
        {
            int main_course=prerequisites[i][0];
            int pre_course=prerequisites[i][1];
            adj_list[main_course].push_back(pre_course);
        }
        vector<int>vis(numCourses,0);
        
        for(i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                if(isCycle(adj_list,vis,i))
                    return false;
            }
        }
        return true;
    }
};