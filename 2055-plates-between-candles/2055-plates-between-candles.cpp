class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        vector<int>pre(n, 0);
        vector<int>ans;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '|'){
                sum += 1;
            }
            pre[i] = sum;
        }
        for(int i = 0; i < m; i++){
            int low = queries[i][0], high = queries[i][1];
            int left = low;
            int ans1 = -1, ans2 = -1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(pre[mid] != 0 && s[mid] == '|'){
                    high = mid - 1;
                    ans1 = mid;
                }
                else if(left != 0 && pre[mid] > pre[left - 1]){
                    high = mid - 1;
                }
                else if(left == 0 && pre[mid] != 0){
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            if(ans1 == -1){
                ans.push_back(0);
                continue;
            }
            low = ans1 + 1;
            high = queries[i][1];
            int right = high;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(pre[mid] != 0 && s[mid] == '|'){
                    low = mid + 1;
                    ans2 = mid;
                }
                else if(pre[mid] < pre[right]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            if(ans2 == -1){
                ans.push_back(0);
                continue;
            }
            ans.push_back((ans2 - ans1) - (pre[ans2] - pre[ans1]));
        }
        return ans;
    }
};