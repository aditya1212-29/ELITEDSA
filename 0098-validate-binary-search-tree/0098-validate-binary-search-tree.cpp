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
    bool solve(TreeNode* root, int &val){
        if(!root) return 1;
        if(!solve(root->left, val))
        return 0;
        if(root->val <= val) 
        return 0;
        val = root->val;
        return solve(root->right, val);
    }
    bool isValidBST(TreeNode* root) {
        int val = INT_MIN;
        return solve(root, val);
    }
};