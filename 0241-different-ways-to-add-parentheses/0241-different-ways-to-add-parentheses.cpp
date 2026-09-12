class Solution {
public:
    vector<int> solve(string &expression, int i, int j){
        if(i == j){
            return {expression[i] - '0'};
        }
        if(i + 1 == j){
            return {stoi(expression.substr(i, 2))};
        }
        vector<int>vec;
        for(int index = i ; index <= j; index++){
            if(expression[index] == '+' || expression[index] == '-'||
                expression[index] == '*'|| expression[index] == '/'){
                vector<int>left = solve(expression, i, index - 1);
                vector<int>right = solve(expression, index + 1, j);
                if(expression[index] == '+'){
                    for(int k = 0; k < left.size(); k++){
                        for(int l = 0; l < right.size(); l++){
                            vec.push_back(left[k] + right[l]);
                        }
                    }
                }
                if(expression[index] == '-'){
                    for(int k = 0; k < left.size(); k++){
                        for(int l = 0; l < right.size(); l++){
                            vec.push_back(left[k] - right[l]);
                        }
                    }
                }
                if(expression[index] == '*'){
                    for(int k = 0; k < left.size(); k++){
                        for(int l = 0; l < right.size(); l++){
                            vec.push_back(left[k] * right[l]);
                        }
                    }
                }
                if(expression[index] == '/'){
                    for(int k = 0; k < left.size(); k++){
                        for(int l = 0; l < right.size(); l++){
                            vec.push_back(left[k] / right[l]);
                        }
                    }
                }
            }
        }
        return vec;
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size() - 1;
        return solve(expression, 0, n);
    }
};