class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string, vector<string>>mp;
        vector<vector<string>>ans;
        for(int i = 0; i < n; i++){
            string org = strs[i];
            string index = strs[i];
            sort(index.begin(), index.end());
            mp[index].push_back(org);
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};