class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        int r = 0;
        int i = 0;
        vector<vector<char>> vec(numRows);
        if(numRows == 1) return s;
        while(i < n){
            while(r < numRows && i < n){
                vec[r].push_back(s[i]);
                r++;
                i++;
            }
            r -= 2;
            while(r > 0 && i < n){
                vec[r].push_back(s[i]);
                r--;
                i++;
            }
        }
        string ans = "";
        for(i = 0 ; i < numRows; i++){
            for(int j = 0; j < vec[i].size(); j++){
                    ans += vec[i][j];
            }
        }
        return ans;
    }
};