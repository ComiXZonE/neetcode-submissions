class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> char_count;

        for (char c : s1) {
            char_count[c]++;
        }

        int n1 = s1.length();
        int n2 = s2.length();

        for (int i = 0; i <= n2 - n1; i++) {
            unordered_map<char, int> char_count1;
            for (int j = i; j < i + n1; j++) {
                char_count1[s2[j]]++;
            }

            if (char_count == char_count1) {
                return true;
            }
        }

        return false;
    }
};
