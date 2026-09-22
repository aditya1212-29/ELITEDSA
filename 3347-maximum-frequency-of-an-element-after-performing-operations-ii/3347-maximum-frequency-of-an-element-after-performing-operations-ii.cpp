class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = INT_MIN;
        map<int, int>mp1, mp2;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            mp1[x]++;
            mp2[x] += 0;
            mp2[x - k] += 1;
            mp2[x + k + 1] -= 1;
        }
        int sum = 0;
        for(auto it : mp2){
            sum += it.second;
            int occ = mp1[it.first];
            int req = sum - occ;
            ans = max(ans, occ + min(req, numOperations));
        }
        return ans;
    }
};