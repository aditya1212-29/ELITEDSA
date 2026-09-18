class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {  
        if(ops.size() == 0) return m * n;
        int r = ops[0][0], c = ops[0][1];
        int ans = r * c;
        for(int i = 1; i < ops.size(); i++){
            int a = ops[i][0], b = ops[i][1];
            r = min(r, a);
            c = min(c, b);
            ans = r * c;
        }
        return ans;
    }
};