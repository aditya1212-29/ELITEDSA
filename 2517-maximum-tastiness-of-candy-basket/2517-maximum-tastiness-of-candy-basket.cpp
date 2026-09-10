class Solution {
public:
    bool check(int val, vector<int>& prices, int k){
        int cnt = 1;
        int last = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - last >= val){
                last = prices[i];
                cnt++;
            }
        }
        return cnt >= k ? 1 : 0;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size() - 1;
        int ans = 0;
        sort(price.begin(), price.end());
        int low = 0, high = price[n];
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid, price , k)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};