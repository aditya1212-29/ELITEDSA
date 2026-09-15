class Solution {
public:
    int solve(int i, int j, string &s, vector<vector<int>> &pali){
        if(i > j) return 0;
        int ans = 0;
        for(int index = i; index <= j; index++){
            bool check = pali[i][index];
            if(check){
                ans += 1;
            }
        }
        return ans + solve(i + 1, j, s, pali);
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> pali(n, vector<int>(n, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j - i <= 2 || pali[i + 1][j - 1]))
                pali[i][j] = 1;
            }
        }
        return  solve(0, n - 1, s, pali);
    }
};