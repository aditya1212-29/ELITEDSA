class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>left(n, 1), top(m, 1);
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ;j++){
                if(matrix[i][j] == 0){
                    left[i] = 0;
                    top[j] = 0;
                }
            }
        }
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++){
                matrix[i][j] *= (left[i] && top[j]);
            }
        }
        return;
    }
};