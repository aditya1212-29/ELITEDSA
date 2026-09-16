class Solution {
public:
    int mod = 1e9 + 7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int>sum(n, 0);
        for(int i = 0; i < requests.size(); i++){
            int s = requests[i][0];
            int e = requests[i][1] + 1;
            sum[s] += 1;
            if(e == n) continue;
            sum[e] -= 1; 
        }
        int pre = 0;
        for(int i = 0; i < n; i++){
            pre += sum[i];
            sum[i] = pre;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        sort(sum.begin(), sum.end(), greater<int>());
        long long  ans = 0;
        for(int i = 0; i < n; i++){
            long long val = 1LL * nums[i] * sum[i];
            ans = (ans % mod + val % mod) % mod;
        }
        return int(ans);
    }
};