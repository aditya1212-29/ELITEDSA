/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(root == NULL) return root;
        q.push(root);
        while(!q.empty()){
            vector<Node*>vec;
            int s = q.size();
            for(int i = 0; i < s; i++){
                Node* node = q.front();
                q.pop();
                vec.push_back(node);
                if(node->left != NULL)
                q.push(node->left);
                if(node->right != NULL)
                q.push(node->right);
            }
            for(int i = 1; i < vec.size(); i++){
                vec[i-1]->next = vec[i];
            }
        } 
        return root;
    }
};