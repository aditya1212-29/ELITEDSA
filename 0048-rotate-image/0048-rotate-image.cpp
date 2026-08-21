class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
            int x = 0, y = m - 1;
            while(x < y){
                swap(matrix[i][x], matrix[i][y]);
                x++, y--;
            }
        }
        return;
    }
};