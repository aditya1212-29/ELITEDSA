class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>vec(n, 0);
        int cnt = 0;
        for(int i = 0; i < queries.size(); i++){
            int s = queries[i][0];
            int e = queries[i][1] + 1;
            vec[s] -= 1;
            if(e < n)
            vec[e] += 1;
        }
        for(int i = 1; i < n; i++){
            vec[i] += vec[i - 1];
        }
        for(int i = 0; i < n; i++){
            if(nums[i] + vec[i] <= 0)
            cnt++;
        }
        return cnt == n;
    }
};