class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i=0, j=n-1;
        while(i < j)
        {
            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j])) j--;
            char c1 = s[i];
            char c2 = s[j];
            if(tolower(c1) != tolower(c2)) return false;
            i = i + 1;
            j = j - 1;
        }

        return true;
    }
};
