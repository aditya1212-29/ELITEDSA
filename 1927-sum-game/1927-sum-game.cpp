class Solution {
public:
    int cnt(string s){
        int cnt = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '?')
            cnt++;
        }
        return cnt;
    }
    int findSum(string s){
        int digitSum = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '?') continue;
            else{
                int dig = s[i] - '0';
                digitSum += dig;
            }
        }
        return digitSum;
    }
    bool sumGame(string num) {
        int n = num.size();
        int leftSum = 0, rightSum = 0, left = 0, right = 0;
        leftSum = findSum(num.substr(0, n / 2));
        rightSum = findSum(num.substr(n/2));
        left = cnt(num.substr(0, n/2));
        right = cnt(num.substr(n/2));
        cout<<leftSum<<endl;
        cout<<rightSum<<endl;
        cout<<left<<endl;
        cout<<right<<endl;
        if(leftSum == rightSum){
            if(left == right)
            return 0;
            return 1;
        }
        else{
            if(leftSum > rightSum){
                if(right > left){
                    int diff = right - left;
                    if(diff % 2 != 0) 
                    return 1;
                    int val = diff / 2;
                    if(val * 9 == leftSum - rightSum )
                    return 0;
                    return 1;
                }
                return 1;
            }
            else{
                if(left > right){
                    int diff = left - right;
                    if(diff % 2 != 0)
                    return 1;
                    int val = diff / 2;
                    if(val * 9 == rightSum - leftSum)
                    return 0;
                    return 1;
    
                }
                return 1;
            }
        }
    }
};