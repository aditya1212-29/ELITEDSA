class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int index, int n, bool flag, int k, vector<vector<vector<int>>> &dp){
        if(k == 0) return 1;
        if(index == n) return 0;
        if(dp[index][k][flag] != -1) return dp[index][k][flag];
        long long take = 0, notTake = 0;
        if(flag){
            take  = solve(index, n, 0, k - 1, dp);
            notTake = solve(index + 1, n, 1, k, dp);
        }
        else{
            take = solve(index + 1, n, 1, k, dp);
            notTake = solve(index + 1, n, 0, k, dp);
        }
        return dp[index][k][flag] = (take + notTake) % mod;
    }
    int numberOfSets(int n, int k) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, n, 0, k, dp);
    }
};