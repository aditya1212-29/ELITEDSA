class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n , 0));
        for(int i = 0; i < queries.size(); i++){
            int s = queries[i][1];
            int e = queries[i][3] + 1;
            int sr = queries[i][0];
            int er = queries[i][2];
            for(int r = sr; r <= er; r++){
                ans[r][s] += 1;
                if(e < n)
                ans[r][e] -= 1;
            }
        }
        for(int i = 0; i < n; i++){
            int pre = 0;
            for(int j = 0; j < n; j++){
                pre += ans[i][j];
                ans[i][j] = pre;
            }
        }
        return ans;
    }
};