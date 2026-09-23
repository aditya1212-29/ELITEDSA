class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX, sum = 0;
        int l = 0, r = 0;
        while(r < n){
            sum += nums[r];
            while(sum >= target && l <= r){
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};