class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pos;
        vector<int>ans(n);
        for(int i = 0 ; i < n; i++){
            if(nums[i] > -1)
            pos.push_back(nums[i]);
        }   
        int s = pos.size();
        if(s == 0) return nums;
        k %= s;
        int x = 0, y = 0;
        rotate(pos.begin(), pos.begin() + k, pos.end());
        for(int i = 0 ; i < n; i++){
            if(nums[i] < 0){
                ans[i] = nums[i];
                y++;
            }
            else{
                ans[i] = pos[x];
                x++;
            }
        }
        return ans;
    }
};