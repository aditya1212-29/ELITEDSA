class Solution {
public:
    int solve(string &s, int i, int j, int k, vector<int> &dp, vector<vector<bool>> &pali){
        if(i > j){
            return 0;
        }
        int maxi = INT_MIN;
        if(dp[i] != -1) return dp[i];
        for(int index = i ; index <= j; index++){
            int val = 0;
            bool check = pali[i][index];
            if(check && (index - i + 1 >= k)){
                val = 1 + solve(s, index + 1, j, k, dp, pali);
                maxi = max(maxi, val);
            }
            else{
                if(check){
                    val = solve(s, index + 1, j, k, dp, pali);
                    maxi = max(maxi, val);
                }
            }
        }
        return dp[i] = maxi;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int i = 0, j = s.size() - 1;
        vector<int>dp(n, - 1);
        vector<vector<bool>> pali(n, vector<bool>(n, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j - i <= 2 || pali[i + 1][ j - 1]))
                pali[i][j] = 1;
            }
        }
        return solve(s, i, j, k, dp, pali);
    }
};