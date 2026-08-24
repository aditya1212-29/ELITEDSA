class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int n = nums.size(), l = 0, r = 0;
        long long score = 0, len = 0, sum = 0;
        while(r < n){
            sum += nums[r];
            len = r - l + 1;
            score = 1LL * sum * len;
            while(score >= k && l <= r){
                sum -= nums[l];
                l++;
                len = r - l + 1;
                score = 1LL * sum * len;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
};