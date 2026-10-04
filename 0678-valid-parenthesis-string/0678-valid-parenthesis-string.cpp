class Solution {
public: 
    bool checkValidString(string s) {
        int min = 0, max = 0, n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                min++, max++;
            }
            if(s[i] == ')'){
                min--, max--;
            }
            if(s[i] == '*'){
                min--, max++;
            }
            if(min < 0) min = 0;
            if(max < 0) return false;
        }
        return min == 0;
    }
};