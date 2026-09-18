class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>vec(n, 0);
        int m = shifts.size();
        for(int i = 0; i < m; i++){
            int l = shifts[i][0];
            int r = shifts[i][1] + 1;
            int d = shifts[i][2];
            if(d == 0){
                vec[l] -= 1;
                if(r == n) continue;
                vec[r] += 1;
            }
            else{
                vec[l] += 1;
                if(r == n) continue;
                vec[r] -= 1;
            }
        }
        for(int i = 1; i < n; i++){
            vec[i] += vec[i - 1];
        }
        string str = "";
        for(int i = 0; i < n; i++){
            if(vec[i] == 0){
                str += s[i];
            }
            else if(vec[i] < 0){
                int val = vec[i] % 26;
                if(s[i] - 'a' + val < 0){
                    str += 'a' + (s[i] - 'a' + val + 26);
                }
                else{
                    str += 'a' + (s[i] - 'a' + val);
                }
            }
            else{
                int val = vec[i] % 26;
                if(s[i] - 'a' + val >= 26){
                    str += 'a' + (s[i] - 'a' + val - 26);
                }
                else{
                    str += 'a' + (s[i] - 'a' + val);
                }
            }
        }
        return str;
    }
};
