class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int l, r, ans = 0;
        for(int i = 0; i < n; i++){
            l = r = i;
            while(l >= 0 && r < n){
                if(s[l--] == s[r++]) ans++;
                else break;
            }
        }
        for(int i = 0; i < n; i++){
            l = i;
            r = i + 1;
            while(l >= 0 && r < n){
                if(s[l--] == s[r++]) ans++;
                else break;
            }
        }
        return ans;
    }
};