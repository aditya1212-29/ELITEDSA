class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int index, string &s, vector<int> &dp){
        if(index == s.size()){
            return 1;
        }
        long long  cnt = 0;
        vector<int>vec(26, 0);
        if(dp[index] != -1) return dp[index];
        for(int i = index; i < s.size(); i++){
            if(vec[s[i]-'a']) continue;
            vec[s[i]-'a']++;
            cnt += solve(i + 1, s, dp) % mod;
        }
        return dp[index] = (cnt + 1) % mod;
    }
    int distinctSubseqII(string s) {
        if(s == "") return 0;
        int n = s.size();
        vector<int>dp(n, -1);
        return (solve(0, s, dp) + mod  - 1) % mod;
    }
};