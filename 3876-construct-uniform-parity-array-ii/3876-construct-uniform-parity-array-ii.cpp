class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size(), miniodd = INT_MAX, minieven = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 != 0){
                miniodd = min(miniodd, nums[i]);
            }
            else{
                minieven = min(minieven, nums[i]);
            }
        }
        if(minieven < miniodd && miniodd != INT_MAX){
            return 0;
        }
        return 1;
    }
};