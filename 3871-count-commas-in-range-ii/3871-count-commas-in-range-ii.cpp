class Solution {
public:
    long long countCommas(long long number) {
        vector<int>vec;
        string s = to_string(number);
        int n = s.size();
        int i = n;
        while(i > 0){
        int start = max(0, i - 3);
        string num = s.substr(start, i - start);
        vec.push_back(stoi(num));
        i -= 3;
        }
        for(int i = 0; i < vec.size(); i++){
            cout<<vec[i]<<endl;
        }
        long long ans = 0;
        long long mul = 1LL * 1000;
        for(int j = 1; j < vec.size(); j++){
            long long val = number - (mul - 1);
            ans += val;
            mul *= 1000;
        }
        return ans;
    }
};