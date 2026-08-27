class Solution {
   public:
    int characterReplacement(string s, int k) {
        std::array<int, 26> frequency = {0};

        int max_char_freq = 0;
        int i = 0;
        int result = 0;

        for (int j = 0; j < s.length(); j++) {
            frequency[s[j] - 'A']++;
            max_char_freq = max(max_char_freq, frequency[s[j] - 'A']);

            if (j - i + 1 - max_char_freq <= k) {
                result = max(result, j - i + 1);
            } else {
                while (j - i + 1 - max_char_freq > k) {
                    frequency[s[i] - 'A']--;
                    i++;
                }
            }
        }

        return result;
    }
};