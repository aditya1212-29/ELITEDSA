class Solution {
public:
    bool solve(int i, int j, int cnt, vector<vector<char>> &grid, vector<vector<vector<int>>> &dp){
        if(cnt < 0 || i >= grid.size() || j == grid[0].size() || cnt > 5000) return 0;
        if(i == grid.size() - 1 && j == grid[0].size() -1){
            if(grid[i][j] == '(') cnt++;
            else cnt--;
            return cnt == 0 ? 1 : 0;
        }
        if(dp[i][j][cnt] != -1) return dp[i][j][cnt]; 
        if(i == 0 && j == 0){
            if(grid[i][j] == '(')
            return dp[i][j][cnt] = solve(i + 1, j, cnt + 1, grid, dp) || solve(i, j + 1, cnt + 1, grid, dp);
            return dp[i][j][cnt] = 0;
        }
        if(grid[i][j] == '('){
            return dp[i][j][cnt] = solve(i + 1, j, cnt + 1, grid, dp) || solve(i, j + 1, cnt + 1, grid, dp);
        }
        else{
            return dp[i][j][cnt] = solve(i + 1, j, cnt - 1, grid, dp) || solve(i, j + 1, cnt - 1, grid, dp);
        }
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(5000, -1)));
        return solve(0, 0, cnt, grid, dp);
    }
};