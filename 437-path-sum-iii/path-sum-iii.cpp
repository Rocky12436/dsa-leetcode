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
    int count = 0 ;
    void fun(TreeNode* root , int target)
    {
        if(root == NULL)
        {
            return ;
        }
        TreeNode * t = root;
        fun2(t,0,target);
        fun(root->left,target);
        fun(root->right,target);
        return ;
    }
    void fun2(TreeNode* root , long long sum , int Target)
    {
        if(root == NULL)
            return ;
        sum+=root->val;

        if(sum == Target)
        {
            count++;
        }
        fun2(root->left,sum,Target);
        fun2(root->right,sum,Target);
        return;


    }
    int pathSum(TreeNode* root, int targetSum) {
        fun(root,targetSum);
        return count;
    }
};