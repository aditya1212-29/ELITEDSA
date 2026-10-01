class Solution {
public:
    bool solve(int i, int j, string &s, string& p){
        if(j == p.size()) return i == s.size();
        bool flag = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        if(j + 1 < p.size() && p[j + 1] == '*'){
            return solve(i, j + 2, s, p) || (flag && solve(i + 1, j, s, p));
        }
        if(flag) return solve(i + 1, j + 1, s, p);
        return 0;
    }
    bool isMatch(string s, string p) {
        return solve(0, 0, s, p);
    }
};