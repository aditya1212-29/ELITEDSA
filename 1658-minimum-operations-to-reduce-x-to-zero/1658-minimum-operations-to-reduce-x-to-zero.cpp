class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        int tar = total - x;
        int i = 0, j = 0, ans = INT_MAX;
        while(j < n){
            sum += nums[j];
            while(sum > tar && i <= j){
                sum -= nums[i];
                i++;
            }
            if(sum == tar){
                ans = min(ans, n - (j - i + 1));
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};