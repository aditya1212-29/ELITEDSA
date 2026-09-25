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
    int minimumOperations(TreeNode* root) {
        int cnt = 0;
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>vec;
            int s = q.size();
            for(int i = 0; i < s; i++){
                vec.push_back(q.front()->val);
                TreeNode* node = q.front();
                q.pop();
                if(node ->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }   
            for(int i = vec.size() - 1; i > 0; i--){
                int index = i;
                int maxi = vec[i];
                for(int j = i - 1; j >= 0; j--){
                    if(vec[j] > maxi){
                        maxi = vec[j];
                        index = j;
                    }
                }
                if(index != i){
                    swap(vec[i], vec[index]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};