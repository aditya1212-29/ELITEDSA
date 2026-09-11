class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>> &dp){
        if(i > j) return 1;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int index = i ; index <= j ; index++){
            int left = solve(i, index - 1, n, dp);
            int right = solve(index + 1, j, n, dp);
            ans += left * right;
        }
        return dp[i][j] = ans;
    }
    int numTrees(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(1, n, n, dp);
    }
};