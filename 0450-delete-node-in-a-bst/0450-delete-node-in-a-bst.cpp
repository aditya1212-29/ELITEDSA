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
    TreeNode* solve(TreeNode* root, int key){
        if(!root) return NULL;
        if(root->val == key){
            if(!root->left)
            return root->right;
            else{
               TreeNode* node = root->left;
               TreeNode* parent = NULL;
               while(node->right){
                parent = node;
                node = node->right;
               }
               if(parent){
               parent->right = node->left;
               node->left = root->left;
               node->right = root->right;
               return node;
               }
               else{
                node->right = root->right;
                return node;
               }
            }
        }
        else if(root->val > key){
            root->left = solve(root->left, key);
            return root;
        }
        else{
        root->right = solve(root->right, key);
        return root;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node = root;
        if(!root) return root;
        return solve(root, key);
    }
};