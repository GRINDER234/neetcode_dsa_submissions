class Solution {
public:
    void backtrack_parenthesis(int open, int close, int n, string &s, vector<string>&ans){
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }

        if(open < n){
            s += '(';
            backtrack_parenthesis(open+1, close, n, s, ans);
            s.pop_back();
        }

        if(open > close){
            s += ')';
            backtrack_parenthesis(open, close+1, n, s, ans);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        //op = n
        //cl = n
        string s = "";
        vector<string>ans;
        backtrack_parenthesis(0, 0, n, s, ans);
        return ans;
    }
};
