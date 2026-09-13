class Solution {
public:
    int solve(vector<vector<int>> &a, vector<vector<int>> &b, int x, int y){
        int cnt = 0;
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < b.size(); j++){
                int nx = i + x;
                int ny = j + y;
                if(nx < 0 || nx >= a.size() || ny < 0 || ny >= a.size()) continue;
                if(a[i][j]){
                    if(b[nx][ny])
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = INT_MIN;
        int n = img1.size();
        for(int i = 1 - n ; i < n ; i++){
            for(int j = 1 - n; j < n; j++){
                ans = max(ans, solve(img1, img2, i, j));
            }
        }
        return ans;
    }
};