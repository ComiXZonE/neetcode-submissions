class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const auto& s : strs) {
            array<int, 26> counts{};
            for (char c : s) {
                counts[c - 'a']++;
            }

            std::string key;
            key.reserve(26 * 2);
            for (int i = 0; i < 26; ++i) {
                key += '#';  // delimiter avoids ambiguity (e.g. "1" "11" vs "11" "1")
                key += std::to_string(counts[i]);
            }
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (const auto& [key, value] : groups) {
            result.push_back(value);
        }
        
        return result;
    }
};
