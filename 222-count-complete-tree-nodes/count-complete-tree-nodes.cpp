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
    int fun(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = 0;
        int right = 0;
        TreeNode* temp = root ;
        while(temp != NULL)
        {
            left++;
            temp = temp->left;
        }
        temp = root;
        while(temp != NULL)
        {
            right ++;
            temp = temp->right;
        }
        if(left == right)
        {
            return pow(2,left)-1;
        }
        return 1 + fun(root->left) + fun(root->right);

    }
    int countNodes(TreeNode* root) {
        return fun(root);
    }
};