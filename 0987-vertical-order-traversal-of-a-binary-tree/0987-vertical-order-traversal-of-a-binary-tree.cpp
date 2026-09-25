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
    int solve(TreeNode *root){
        if(root == NULL) return 0;
        return 1 + max(solve(root->left), solve(root->right));
    }
    void find(int& left,int& right,int temp,TreeNode* root){
        if(root==NULL) return;
        left=min(left,temp);
        right=max(right,temp);
        find(left,right,temp-1,root->left);
        find(left,right,temp+1,root->right);
 }
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int left=0,right=0,temp=0;
        find(left,right,temp,root);
        int height = solve(root);
        vector<vector<vector<int>>> positive(right + 1, vector<vector<int>>(height)); 
        vector<vector<vector<int>>> negative(-1 * left + 1, vector<vector<int>>(height)); 
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        queue<int>r, c;
        if(root){
            q.push(root);
            r.push(0);
            c.push(0);
        }
        while(!q.empty()){
            TreeNode* node=q.front();
            int row = r.front();
            int col = c.front();
            q.pop();
            r.pop();
            c.pop();
            if(col >= 0){
                positive[col][row].push_back(node->val);
            }
            else{
                negative[-1*col][row].push_back(node->val);
            }
            if(node->left){
                q.push(node->left);
                c.push(col - 1);
                r.push(row + 1);
            }
            if(node->right){
                q.push(node->right);
                c.push(col + 1);
                r.push(row + 1);
            }
        }
        for(int i=negative.size()-1;i>0;i--){
            vector<int>vec;
            for(int j=0;j<height;j++){
                int s = negative[i][j].size();
                sort(negative[i][j].begin(), negative[i][j].end());
                for(int k = 0; k < s; k++){
                    vec.push_back(negative[i][j][k]);
                }
            }
            ans.push_back(vec);
        }
        for(int i=0; i < positive.size(); i++){
            vector<int>vec;
            for(int j=0;j<height;j++){
                int s = positive[i][j].size();
                sort(positive[i][j].begin(), positive[i][j].end());
                for(int k = 0; k < s; k++){
                    vec.push_back(positive[i][j][k]);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};