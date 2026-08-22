class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        
        while (i < s.length() && j >= 0) {
            while (!isalnum(s[i])) {
                i++;
            }
            while (!isalnum(s[j])) {
                j--;
            }

            if (i < s.length() && j >= 0 && tolower(s[i++]) != tolower(s[j--])) {
                return false;
            }
        }

        return true;
    }
};
