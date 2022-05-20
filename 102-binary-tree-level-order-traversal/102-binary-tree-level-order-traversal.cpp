/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(!root)
        {
            return v;
        }
        queue<pair<TreeNode*,int>>que;
        que.push({root,0});
        vector<vector<int>>ans(2001);
        while(!que.empty())
        {
            pair<TreeNode*,int>p;
            p=que.front();
            que.pop();
            ans[p.second].push_back(p.first->val);
            if(p.first->left)
            {
                que.push({p.first->left,p.second+1});
            }
             if(p.first->right)
            {
                que.push({p.first->right,p.second+1});
            }
        }
        //vector<vector<int>>v;
        for(int i=0;i<2001;i++)
        {
            if(ans[i].size()>0)
            {
                v.push_back(ans[i]);
            }
        }
        return v;
    }
};