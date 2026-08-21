class Solution {
public:
    int solve(vector<int> &nums, int pre, int index, int target, vector<vector<int>> &dp){
        if(index == 0){
            if((pre ^ nums[index]) == target) return 1;
            if(pre == target) return 0;
            return -1e9;
        }
        if(dp[index][pre] != -1) return dp[index][pre];
        int notTake = solve(nums, pre, index - 1, target, dp);
        int take = 1 + solve(nums, pre ^ nums[index], index - 1, target, dp);
        return dp[index][pre] = max(take, notTake);
    } 
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        int pre = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(total + 1, - 1));
        int val = solve(nums, pre, n - 1, target, dp);
        if(val < 0) return -1;
        return n - val;
    }
};