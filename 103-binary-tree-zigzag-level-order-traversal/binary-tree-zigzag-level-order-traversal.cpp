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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if (!root) return ans;
        q.push(root);
        while(!q.empty())
        {
            int level = q.size();
            vector<int>temp;
            for(int i = 0 ; i<level;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left!=NULL)
                    q.push(t->left);
                if(t->right!=NULL)
                    q.push(t->right);
                
            }
            ans.push_back(temp);
              

        }
        // also we can use the bool fun instead of this for loop 
        // if(!lefttoright)
        // reverse. so the in both case tc is o(N);
         for(int i = 0 ; i<ans.size();i++)
            {
                if(i%2==1)
                {
                    reverse(ans[i].begin(),ans[i].end());
                }
            }
        return ans;
    }
};