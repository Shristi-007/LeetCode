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
    void depth(TreeNode* root, int d,vector<int>&dis, vector<int>&par)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->right)
        {
            dis[root->right->val]=d+1;
            par[root->right->val]=root->val;
            depth(root->right,d+1,dis,par);
        }
        if(root->left)
        {
             dis[root->left->val]=d+1;
            par[root->left->val]=root->val;
            depth(root->left,d+1,dis,par);
        }
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
       
        vector<int>par(101);
        vector<int>dis(101);
         dis[root->val]=0;
        par[root->val]=-1;
        depth(root,0,dis,par);
        if((dis[x]==dis[y])&&(par[x]!=par[y]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};