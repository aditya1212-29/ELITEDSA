class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        int m = shifts.size();
        vector<int>vec(n, 0);
        for(int i = 0; i < m; i++){
            int st = shifts[i][0];
            int end = shifts[i][1] + 1;
            int dir = shifts[i][2];
            if(dir){
                vec[st] += 1;
                if(end == n) continue;
                vec[end] -= 1;
            }
            else{
                vec[st] -= 1;
                if(end == n) continue;
                vec[end] += 1;
            }
        }
        for(int i = 1; i < n; i++){
            vec[i] += vec[i - 1];
        }
        string str = "";
        for(int i = 0; i < n; i++){
            int shift = vec[i] % 26;
            str +=  'a' + (s[i] - 'a' + shift + 26) % 26;
        }
        return str;
    }
};