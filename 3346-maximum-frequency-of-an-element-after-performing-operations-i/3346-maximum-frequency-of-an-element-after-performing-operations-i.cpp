class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        int s = maxi + k - (mini - k) + 2;
        int offset = mini - k;
        int n = nums.size();
        unordered_map<int, int>mp;
        for(auto it : nums)
        mp[it]++;
        vector<int>vec(s, 0);
        for(int i = 0; i < n; i++){
            int start = nums[i] - k - offset;
            int end = nums[i] + k - offset;
            vec[start] += 1;
            if(end + 1 < s)
            vec[end + 1] -= 1;
        }
        for(int i = 1; i < s; i++){
            vec[i] += vec[i - 1];
        }
        int ans = INT_MIN;
        for(int i = 0; i < s; i++){
            int cnt = vec[i];
            int index = i + offset;
            int occ = mp[index];
            int req = cnt - occ;
            int take = occ + min(req, numOperations);
            ans = max(ans, take);
        }
        return ans;
    }
};