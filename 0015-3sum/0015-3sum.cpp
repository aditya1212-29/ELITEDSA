class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i = 0 ; i < n - 2; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = n - 1;
            while(j < k){
                if(j != i + 1 && nums[j] == nums[j - 1]){
                    j++;
                    continue;
                }
                if(k != n - 1 && nums[k] == nums[k + 1]) {
                    k--;
                    continue;
                }
                if(nums[i] + nums[j] + nums[k] == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                }
                else if(nums[i] + nums[j] + nums[k] > 0)
                k--;
                else
                j++;
            }
        }
        return ans;
    }
};