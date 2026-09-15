class Solution {
public:
    vector<int>solve(string &exp, int i, int j){
        if(i == j || i + 1 == j) return {stoi(exp.substr(i, j - i + 1))};
        vector<int>ans;
        vector<int>left, right;
        for(int index = i; index <= j; index++){
            if(exp[index] == '+' || exp[index] == '-' || exp[index] == '*' || exp[index] == '/'){
                left = solve(exp, i, index - 1);
                right = solve(exp, index + 1, j);
            }
            for(int k = 0; k < left.size(); k++){
                for(int l = 0; l < right.size(); l++){
                    if(exp[index] == '+'){
                        ans.push_back(left[k] + right[l]);
                    }
                    if(exp[index] == '-'){
                        ans.push_back(left[k] - right[l]);
                    }
                    if(exp[index] == '*'){
                        ans.push_back(left[k] * right[l]);
                    }
                    if(exp[index] == '/'){
                        ans.push_back(left[k] / right[l]);
                    }
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        return solve(expression, 0, n - 1);
    }
};