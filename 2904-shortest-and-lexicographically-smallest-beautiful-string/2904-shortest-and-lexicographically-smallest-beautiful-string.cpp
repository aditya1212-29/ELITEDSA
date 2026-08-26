class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int pre = 0;  
        int ans = INT_MAX;
        int l = 0, r = 0;
        string ss = "";
        while(r < n){
            pre += (s[r] -'0');
            while(pre > k && l <= r){
                    pre  -= (s[l] -'0');
                    l++;
                }
            if(pre == k){
               while(l <= r && s[l] == '0'){
                l++;
               }
               string str = s.substr(l, r - l + 1);
               if (ss == "" || str.size() < ss.size() ||
                    (str.size() == ss.size() && str < ss)) {
                    ss = str;
                }
            }
            r++;
        }
        return ss;
    }
};