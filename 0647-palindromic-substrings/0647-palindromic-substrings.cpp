class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> pali(n, vector<int>(n, 0));
        int total = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j - i <= 2 || pali[i + 1][j - 1])){
                pali[i][j] = 1;
                total++;
                }
            }
        }
        return total;
    }
};