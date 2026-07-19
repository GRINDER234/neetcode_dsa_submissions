class Solution {
private:
    bool isPalindrome(string s, int j, int i){
        if(s.size() == 0) return true;
        while(j <= i){
            if(s[j] != s[i]){
                return false;
            }
            j++;
            i--;
        }
        return true;
    }

    void partition_backtrack(vector<string>&res, vector<vector<string>>&ans, int i, int j, string &s){
        if(i >= s.size()){
            if(i == j){
                ans.push_back(res);
            }
            return;
        }

        if(isPalindrome(s,j,i)){
            res.push_back(s.substr(j, i-j+1));
            partition_backtrack(res,ans,i+1,i+1,s);
            res.pop_back();
        }

        partition_backtrack(res, ans, i+1, j, s);
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        partition_backtrack(res,ans,0,0,s);
        return ans;
    }
};
