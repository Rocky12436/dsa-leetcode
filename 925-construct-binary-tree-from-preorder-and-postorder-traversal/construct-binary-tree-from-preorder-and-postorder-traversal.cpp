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
    int idx = 0 ;
    unordered_map<int,int>p;
    TreeNode* fun(vector<int>&preorder ,int low , int high)
    {
        if(low>high) return NULL;
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        if(low == high)
            return node;
        int id = p[preorder[idx]];
        node->left=fun(preorder,low,id);
        node->right=fun(preorder,id+1,high-1);
        return node;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0 ; i<postorder.size();i++)
        {
            p[postorder[i]]=i;
        }
        return fun(preorder,0,postorder.size()-1);
    }
};