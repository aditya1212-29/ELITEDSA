class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        int i = 0, j = 1;
        while(j < n){
            while(j < n && nums[i] == nums[j]){
                 j++;
            }
            if(j == n) return cnt;
            nums[i+1] = nums[j];
            i++, j++;
            cnt++;
        }
        return cnt;
    }
};