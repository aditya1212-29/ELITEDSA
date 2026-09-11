class Solution {
public:
    int solve(vector<int>& digits, int cnt, vector<int> &visited){
        if(cnt == 0) return 1;
        int ans = 0;
        vector<int>fre(10, 0);
        for(int i = 0; i < digits.size(); i++){
            if(visited[i]) continue;
            if(cnt == 3 && digits[i] == 0) continue;
            if(cnt == 1 && digits[i] % 2 != 0) continue;
            if(fre[digits[i]] == 0){
                visited[i] = 1;
                fre[digits[i]]++;
                ans += solve(digits, cnt - 1, visited);
                visited[i] = 0;
            }
        }
        return ans;
    }
    int totalNumbers(vector<int>& digits) {
        vector<int>visited(digits.size(), 0);
        return solve(digits, 3, visited);
    }
};