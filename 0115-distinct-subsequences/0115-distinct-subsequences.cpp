class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(i < 0) return dp[i+1][j+1] = 0;
        if(j == 0){
            int cnt = 0;
            while(i >= 0){
                if(s[i] == t[j])
                cnt++;
                i--;
            }
            return dp[i+1][j+1] = cnt;
        }
        if(dp[i+1][j+1] != -1) return dp[i+1][j+1];
        int take = 0, notTake = 0;
        notTake = solve(s, t, i - 1, j, dp);
        if(s[i] == t[j]){
            take = solve(s, t, i - 1, j - 1, dp);
        }
        return dp[i+1][j+1] = take + notTake;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, - 1));
        return solve(s, t, n - 1, m - 1, dp);
    }
};