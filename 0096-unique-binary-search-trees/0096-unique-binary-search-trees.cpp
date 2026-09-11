class Solution {
public:
    int solve(int i, int j, int n){
        if(i > j) return 1;
        if(i == j) return 1;
        int ans = 0;
        for(int index = i ; index <= j ; index++){
            int left = solve(i, index - 1, n);
            int right = solve(index + 1, j, n);
            ans += left * right;
        }
        return ans;
    }
    int numTrees(int n) {
        return solve(1, n, n);
    }
};