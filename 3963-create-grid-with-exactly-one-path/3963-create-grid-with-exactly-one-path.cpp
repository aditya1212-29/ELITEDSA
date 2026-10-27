class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        string s;
        for(int i = 0; i < n; i++){
            s.push_back('.');
        }
        ans.push_back(s);
        for(int i = 1; i < m; i++){
            string s;
            for(int j = 0; j < n - 1; j++){
                s.push_back('#');
            }
            s.push_back('.');
            ans.push_back(s);
        }
        return ans;
    }
};