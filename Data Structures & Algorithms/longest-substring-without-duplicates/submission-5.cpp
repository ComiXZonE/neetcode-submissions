class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars_set;
        int result = 0;
        
        int i = 0;
        for (int j = 0; j < s.length(); j++) {
            char c = s[j];
            if (!chars_set.contains(c)) {
                chars_set.insert(c);
                result = max(result, j - i + 1);
            }
            else {
                while (s[i] != c) {
                    chars_set.erase(s[i]);
                    i++;
                }
                i++;
            }
        }

        return result;
    }
};
