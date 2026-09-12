class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<vector<int>> vec;
        for(int i = 0; i < logs.size(); i++){
            vec.push_back({logs[i][0], 1});
            vec.push_back({logs[i][1], -1});
        }
        sort(vec.begin(), vec.end());
        int cnt = 0, ans = 2051, maxcnt = 0;
        for(int i = 0; i < vec.size(); i++){
            cnt += vec[i][1];
            if(cnt > maxcnt){
                ans = vec[i][0];
                maxcnt = cnt;
            }
        }
        return ans;
    }
};