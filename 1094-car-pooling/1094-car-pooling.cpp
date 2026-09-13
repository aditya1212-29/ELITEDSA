class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int ,int>mp;
        for(int i = 0; i < trips.size(); i++){
            mp[trips[i][1]] += trips[i][0];
            mp[trips[i][2]] -= trips[i][0];
        }
        int cnt = 0;
        for(auto it : mp){
            cnt += it.second;
            if(cnt > capacity)
            return 0;
        }
        return 1;
    }
};