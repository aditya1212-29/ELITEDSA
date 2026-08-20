class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>>mp;
        set<int>s1 = {2,3,4,5}; 
        set<int>s2 = {4,5,6,7};
        set<int>s3 = {6,7,8,9};
        int ans = n * 2;
        for(int i = 0 ; i < reservedSeats.size(); i++){
            int r = reservedSeats[i][0];
            int c = reservedSeats[i][1];
            mp[r].push_back(c);
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            bool a = 1, b = 1, c = 1;
            for(auto i : it->second){
                if(s1.count(i))
                a = 0;
                if(s2.count(i))
                b = 0;
                if(s3.count(i))
                c = 0;
            }
            if(a && c)
            ans -= 0;
            else if(a || b || c) 
            ans -= 1;
            else 
            ans -= 2;
        }
        return ans;
    }
};