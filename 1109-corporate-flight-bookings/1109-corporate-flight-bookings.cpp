class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n, 0);
        for(int i = 0; i < bookings.size(); i++){
            int s = bookings[i][0] - 1;
            int e = bookings[i][1];
            ans[s] += bookings[i][2];
            if(e == n) continue;
            ans[e] -= bookings[i][2];
        }
        int pre = 0;
        for(int i = 0; i < n; i++){
            pre += ans[i];
            ans[i] = pre;
        }
        return ans;
    }
};