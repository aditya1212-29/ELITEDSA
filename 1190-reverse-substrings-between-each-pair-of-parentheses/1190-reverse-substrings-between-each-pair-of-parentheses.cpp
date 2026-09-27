class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char>st;
        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                string str = "";
                while(!st.empty() && st.top() != '('){
                    str += st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                for(int j = 0; j < str.size(); j++){
                    st.push(str[j]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};