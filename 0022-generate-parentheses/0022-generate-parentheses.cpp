class Solution {
public:
    void sub(int n,vector<string>&arr,string &s1,int l,int r){
        if(l+r==2*n){
            arr.push_back(s1);
            return;
        }
        if(l<n)
        {
            s1.push_back('(');
            sub(n,arr,s1,l+1,r);
            s1.pop_back();
        }
        if(r<l){
             s1.push_back(')');
            sub(n,arr,s1,l,r+1);
            s1.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>vec;
        string s;
        sub(n,vec,s,0,0);
        return vec;
    }
};
