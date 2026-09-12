class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>vec(101, 0);
        for(int i = 0; i < logs.size(); i++){
            int s = logs[i][0] - 1950;
            int e = logs[i][1] - 1950;
            vec[s] += 1;
            vec[e] -= 1;
        }
        int ans = 2051;
        int sum = 0, maxi = 0;
        for(int i = 0; i <= 100; i++){
           sum += vec[i];
           if(sum > maxi){
                ans = i + 1950;
                maxi = sum;
           }
        }
        return ans;
    }
};