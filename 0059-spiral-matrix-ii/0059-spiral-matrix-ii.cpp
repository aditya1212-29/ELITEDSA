class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>vec(n, vector<int>(n));
        int left = 0, right = n - 1, top= 0, bottom = n - 1;
        int r = 0 , c = 0;
        int cnt = 1;
        while(left <= right && top <= bottom){
            while(c <= right){
                vec[r][c] = cnt;
                cnt++;
                c++;
            }
            top++;
            r = top, c = right;
            while(r <= bottom){
                vec[r][c] = cnt;
                cnt++;
                r++;
            }
            right--;
            r = bottom, c = right;
            while(c >= left){
                vec[r][c] = cnt;
                cnt++;
                c--;
            }
            bottom--;
            r = bottom, c = left;
            while(r >= top){
                vec[r][c] = cnt;
                cnt++;
                r--;
            }
            left++;
            r = top, c = left;
        }
        return vec;
    }
};