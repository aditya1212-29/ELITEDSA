class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(), minidiff = INT_MAX, maxi = INT_MIN;
        int index = -1;
        vector<int>mini(n);
        int val = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            val = min(val, nums[i]);
            mini[i] = val;
        }
        for(int i = 0 ; i < n; i++){
            maxi = max(maxi, nums[i]);
            int diff = maxi - mini[i];
            if(diff <= k){
                return index = i;
            }
        }
        return index;
    }
};