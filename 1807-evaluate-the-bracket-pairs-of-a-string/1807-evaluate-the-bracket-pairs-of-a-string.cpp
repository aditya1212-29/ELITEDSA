class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string>mp;
        for(int i = 0; i < knowledge.size(); i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string str = "";
        int i = 0, j = 0, n = s.size();
        while(j < n){
            string key = "";
            if(s[j] == '('){
                j++;
                while(j < n && s[j] != ')'){
                    key += s[j];
                    j++;
                }
                if(mp.find(key) != mp.end()){
                    str += mp[key];
                }
                else
                str += '?';
            j++;
            }
            else{
                str += s[j];
                j++;
            }
        }
        return str;
    }
};