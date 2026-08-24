class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mini = 1, maxi = 1, ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int newmini = min({nums[i], nums[i] * mini, nums[i] * maxi});
            int newmaxi = max({nums[i], nums[i] * mini, nums[i] * maxi});
            mini = newmini;
            maxi = newmaxi;
            ans = max(ans, maxi);
        }
        return ans;
    }
};