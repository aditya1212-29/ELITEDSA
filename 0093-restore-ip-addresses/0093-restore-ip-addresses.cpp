class Solution {
public:
    void solve(int index, int n, string &s, int cnt, string str, vector<string>& ans){
        if(index == n) return;
        if(cnt == 0){
            if(index < n - 1 && s[index] == '0') return;
            else{
                long long val = stoll(s.substr(index));
                if(val > 255) return;
                str += s.substr(index);
                ans.push_back(str);
                return;
            }
        }
        for(int i = index; i < index + 3 && i < n; i++){
                if(stoll(s.substr(index, i - index + 1)) > 255) return;
                if(i - index + 1 > 1 && s[index] == '0') return;
                str += s[i];
                str += '.';
                solve(i + 1, n, s, cnt - 1, str, ans);
                str.pop_back(); 
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        solve(0, n, s, 3, "", ans);
        return ans;
    }
};