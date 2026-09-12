class Solution {
public:
    bool check(int val, vector<int>& nums, int p){
        int i = 0, j = 1, cnt = 0;
        while(j < nums.size()){
            if(abs(nums[i] - nums[j]) <= val){
                i = j + 1;
                j = i + 1;
                cnt++;
            }
            else i++, j++;
        }
        if(cnt >= p) return 1;
        return 0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n - 1];
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid, nums, p)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};