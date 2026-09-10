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
    pair<int, int> solve(TreeNode *root, int &ans){
        if(!root){
            return {0,0};
        }
        if(!root->left && !root->right){
            ans++;
            return {root->val, 1};
        }
        pair<int, int> l ,r;
        l = solve(root->left, ans);
        r = solve(root->right, ans);
        int avg = (l.first + r.first + root->val)/ (l.second + r.second + 1);
        if(avg == root->val)
        ans++;
        return {l.first + r.first + root->val, l.second + r.second + 1};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        pair<int, int>p;
        p = solve(root, ans);
        return ans;
    }
};