class Solution {
public:
    string multiply(string num1, string num2) {
        vector<vector<char>>pro;
        int n = num1.size();
        int m = num2.size();
        int ext = n + m;
        string n1 = num1, n2 = num2;
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());
        for(int i = 0; i < n; i++){
            vector<char>vec;
            int x = i;
            int carry = 0;
            while(x--){
                vec.push_back('0');
            }
            for(int j = 0; j < m; j++){
                int a = n1[i] - '0', b = n2[j] - '0';  
                int val = a * b + carry;
                vec.push_back(val % 10 + '0');
                carry = val / 10;
            }
            if(carry){
                vec.push_back(carry + '0');
            }
            int y = ext - vec.size();
            while(y--){
                vec.push_back('0');
            }
            pro.push_back(vec);
        }
        string ans = "";
        int c = ext;
        int r = pro.size();
        int carry = 0;
        for(int i = 0; i < c; i++){
            int val = 0;
            for(int j = 0; j < r; j++){
                val += (pro[j][i] - '0');
            }
            val += carry;
            ans.push_back((val % 10) + '0');
            carry = val / 10;
        }
        if(carry){
            ans.push_back(carry + '0');
        }
        while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
