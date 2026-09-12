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
    vector<TreeNode*> solve(int i, int j){
        if(i > j) return {nullptr};
        vector<TreeNode*>vec;
        for(int index = i ; index <= j ; index++){
            vector<TreeNode*>left = solve(i, index - 1);
            vector<TreeNode*>right = solve(index + 1, j);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* node = new TreeNode(index);
                    node->left = l;
                    node->right = r;
                    vec.push_back(node);
                }
            }
        }
        return {vec};
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};