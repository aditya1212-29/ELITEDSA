class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>>ans;
        map<long long, long long>mp;
        for(int i = 0; i < segments.size(); i++){
            mp[segments[i][0]] += 1LL * segments[i][2];
            mp[segments[i][1]] -= 1LL * segments[i][2];
        }
        auto it = mp.begin();
        long long cnt = 1LL * it->second;
        int s = it->first;
        it = next(it);
        for(; it != mp.end(); it++){
            ans.push_back({s, it->first, cnt});
            cnt += it->second;
            if(cnt == 0){
                it = next(it);
                if(it == mp.end()) 
                return ans;
                cnt += it->second;
            }
            s = it->first;
        }
        return ans;
    }
};