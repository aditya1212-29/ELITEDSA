class Solution {
public:
    bool check(vector<int>& nums, int op, int mid){
        long long cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            cnt += ceil(double(nums[i]) / mid) - 1;
        }
        if(cnt <= op) return 1;
        return 0;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(nums, maxOperations, mid)){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};