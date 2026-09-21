class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi =*max_element(nums.begin(), nums.end()) + k;
        int s = maxi + 2;
        unordered_map<int, int> mp;
        for(auto it : nums) mp[it]++;
        vector<int>vec(s, 0);
        for(int i = 0; i < nums.size(); i++){
            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxi);
            vec[l] += 1;
            vec[r + 1] -= 1;
        }
        for(int i = 1; i < s; i++){
            vec[i] += vec[i - 1];
        }
        int ans = INT_MIN;
        for(int i = 0; i < s; i++){
            int cnt = mp[i];
            int occ = vec[i];
            int req = occ - cnt;
            ans = max(ans, cnt + min(req, numOperations));
        }
        return ans;
    }
};