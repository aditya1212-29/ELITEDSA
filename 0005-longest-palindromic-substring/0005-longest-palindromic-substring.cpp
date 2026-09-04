class Solution {
public:
    bool solve(int i, int j, string &s, vector<vector<int>> &dp,int &start, int &len){
        if(i > j) return 0;
        if(i == j){
            if(len < 0){
                len = 1;
                start = i;
            }
            return dp[i][j] = 1;
        }
        if(i + 1 == j){
            if(s[i] == s[j]){
                if(len < 2){
                    len = 2;
                    start = i;
                }
                return dp[i][j] = 1;
            }
            return dp[i][j] = 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        solve(i + 1, j - 1, s, dp, start, len);
        solve(i, j - 1, s, dp, start, len);
        solve(i + 1, j ,s, dp, start, len);
        if(s[i] == s[j] && dp[i + 1][j - 1]){
            int nlen = j - i + 1;
            if(nlen > len){
                len = nlen;
                start = i;
            }
            return dp[i][j] = 1;
        }
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(s == "") return "";
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int start = 0, len = 1;
        bool ans = solve(0, n - 1, s, dp, start, len);
        return s.substr(start, len);
    }
};