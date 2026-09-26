/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *root, int k, vector<int> &ans, TreeNode *res){
        if(!root || root == res) return;
        if(k < 0) return;
        if(k == 0){
            ans.push_back(root->val);
            return ;
        }
        solve(root->left, k - 1, ans, res);
        solve(root->right, k - 1, ans, res);
    }
    void find(TreeNode *root, TreeNode* tar, vector<TreeNode*> vec, vector<TreeNode*> &route){
        if(!root) return;
        if(root == tar){
            vec.push_back(root);
            route = vec;
            return;
        }
        vec.push_back(root);
        find(root->left, tar, vec, route);
        find(root->right, tar, vec, route);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*>vec, route;
        vector<int>ans;
        find(root, target, vec, route);
        TreeNode *res = NULL;
        int cnt = 0;
        for(int i = 0; i < route.size() ; i++){
            cout<<route[i]->val<< " ";
        }
        for(int i = route.size() - 1; i >= 0; i--){
            solve(route[i], k - cnt, ans, res);
            res = route[i];
            cnt++;
        }
        return ans;
    }
};