class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        int diff = INT_MAX;
        bool found = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n - 2; i++){
            if(!found){
                int j = i + 1, k = n - 1;
                while(j < k){
                    int val = nums[i] + nums[j] + nums[k] - target;
                    if(val > 0){
                        if(diff > abs(val)){
                            sum = nums[i] + nums[j] + nums[k];
                            diff = abs(val);
                        }
                        k--;
                    }
                    else if(val < 0){
                        if(diff >= abs(val)){
                            sum = nums[i] + nums[j] + nums[k];
                            diff = abs(val);
                        }
                        j++;
                    }
                    else{
                        sum = target;
                        found = 1;
                        break;
                    }
                }
            }
            else break;
        }
        return sum;
    }
};