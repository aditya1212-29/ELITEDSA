class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long, long long>mp;
        vector<vector<long long>> ans;
        for(int i = 0; i < segments.size(); i++){
            mp[segments[i][0]] += segments[i][2];
            mp[segments[i][1]] -= segments[i][2];
        }
        auto it = mp.begin();
        long long sum = it->second;
        it++;
        for(; it != mp.end(); it++){
            if(sum > 0){
                auto itt = prev(it);
                ans.push_back({itt->first, it->first, sum});
            }
            sum += it->second;
        }
        return ans;
    }
};