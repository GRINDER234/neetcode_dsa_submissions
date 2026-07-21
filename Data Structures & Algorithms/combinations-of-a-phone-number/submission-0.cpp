class Solution {
public:
    void letterCombinations_backtrack(int i, string res, vector<string>&ans, vector<string>&digToChar, string digits){
        if(res.size() == digits.size()){ 
            ans.push_back(res);
            return;
        }

        string ourchars = digToChar[digits[i]-'0'];
        for(char ch : ourchars){
            letterCombinations_backtrack(i+1, res+ch, ans, digToChar, digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits == "") return ans;
        vector<string>digToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        letterCombinations_backtrack(0, "", ans, digToChar, digits);
        return ans;
    }
};
