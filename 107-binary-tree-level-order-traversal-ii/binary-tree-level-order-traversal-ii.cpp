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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        if(root == NULL)
            return res;

        q.push(root);
        while(!q.empty())
        {
            int level = q.size();
            vector<int>temp;
            for(int i= 0;i<level;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left!=NULL)
                    q.push(t->left);
                if(t->right!=NULL)
                    q.push(t->right);
            }
            res.push_back(temp);
        }
         reverse(res.begin(),res.end());
         return res;
    }
};