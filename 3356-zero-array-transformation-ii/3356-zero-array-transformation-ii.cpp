class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int low = 0, high = queries.size() - 1;
        int ans = -1;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) count++;
        }
        if(count == n) return 0;
        while(low <= high){
            vector<int>vec(n, 0);
            int mid = low + (high - low) / 2;
            for(int i = 0; i <= mid ; i++){
                int s = queries[i][0];
                int e = queries[i][1] + 1;
                int val = queries[i][2];
                vec[s] -= val;
                if(e < n)
                vec[e] += val;
            }
            int cnt = 0;
            for(int i = 1; i < n; i++){
                vec[i] += vec[i - 1];
            }
            for(int i = 0; i < n; i++){
                if(vec[i] + nums[i] <= 0)
                cnt++;
            }
            if(cnt == n){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans == -1 ? ans : ans + 1;
    }
};