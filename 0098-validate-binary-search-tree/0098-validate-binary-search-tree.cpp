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
    bool solve(TreeNode* root, long long &val){
        if(!root) return 1;
        if(!solve(root->left, val))
        return 0;
        if(root->val <= val) 
        return 0;
        val = root->val;
        return solve(root->right, val);
    }
    bool isValidBST(TreeNode* root) {
        long long val = LLONG_MIN;
        return solve(root, val);
    }
};