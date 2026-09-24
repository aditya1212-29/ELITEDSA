class Solution {
public:
    int mod = 1e9 + 7;
    long long power(int b, int p){
        if(p == 0) return 1;
        long long h = power(b, p/2);
        long long res = (h * h) % mod;
        if(p % 2 == 0) return res % mod;
        return 1LL* b * res % mod;

    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int, vector<vector<int>>> mp;
        int bs = ceil(sqrt(nums.size()));
        int n = nums.size(), m = queries.size();
        for(int i = 0; i < m; i++){
            int k = queries[i][2];
            int val = queries[i][3];
            int l = queries[i][0];
            int r = queries[i][1];
            if(k >= bs){
                for(int i = l; i <= r; i += k){
                    nums[i] = (1LL* nums[i] * val) % mod;
                }
            }
            else{
                mp[k].push_back({l, r, val});
            }
        }
        for(auto it = mp.begin(); it != mp.end() ; it++){
            vector<long long>vec(n, 1);
            int k = it->first;
            for(auto x : it->second){
                int left = x[0];
                int right = x[1];
                int val = x[2];
                int steps  = (right - left) / k;
                int next = left + (steps + 1) * k;
                vec[left] = (1LL *vec[left] * val) % mod;
                if(next < n){
                    vec[next] = (vec[next] * power(val, mod - 2)) % mod;
                }
            }
            for(int i = 0; i < n; i++){
                if(i - k >= 0)
                vec[i] = vec[i] * vec[i - k] % mod;
            }
            for(int i = 0; i < n; i++){
                nums[i] = (1LL * nums[i] * vec[i]) % mod;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans ^= nums[i];
        }
        return ans;
    }
};