class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int n = numRows;
        for(int i = 0 ; i < n; i++){
            vector<int>vec;
            int pre = 1;
            for(int j = 0; j <= i; j++){
                vec.push_back(pre);
                pre = pre * (i - j) / (j + 1);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};