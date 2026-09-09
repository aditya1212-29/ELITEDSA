class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0, mul = 1LL * 1000;
        while(mul <= n){
            long long val = n -(mul - 1);
            ans += val;
            if(mul > LLONG_MAX / 1000)
            break;
            mul *= 1000;
        }
        return ans;
    }
};